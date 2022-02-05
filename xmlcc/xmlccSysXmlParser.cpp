/** 
 * @file xmlccSysXmlParser.cpp
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2020 Christian (graetz23@gmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "./xmlccSysXmlParser.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
XmlParser::XmlParser( void ) {
  _strTool = new SYS::StrTool( ); // create object for string tool
  _xmlTool = new SYS::XmlTool( ); // create object for xml tool
  if( _xmlHandler == 0 )
    _xmlHandler = new XmlHandler( true ); // if this is used write to console
  _init( ); // initialize all members
} // XmlParser

/// constructor
XmlParser::XmlParser( XmlHandler* xmlHandler ) {
  _strTool = new SYS::StrTool( ); // create object for string tool
  _xmlTool = new SYS::XmlTool( ); // create object for xml tool
  _xmlHandler = 0; // set member pointers for sure to zero
  if( xmlHandler == 0 )
    throw Failure(
      "SYS::XmlParser::XmlParser - given XML handler is null ~8>" );
  _xmlHandler = xmlHandler; // base class for handling found XML tags & texts
  _init( ); // initialize all members; sets _xmlHandler to null; code shadow ~8>
} // XmlParser

/// destructor
XmlParser::~XmlParser( void ) {
  if( _xmlHandler != 0 )
    delete _xmlHandler;
  if( _xmlTool != 0 )
    delete _xmlTool;
  if( _strTool != 0 )
    delete _strTool;
} // ~XmlParser

/******************************************************************************/

void // size of preallocation; .. 100k
XmlParser::setSizeMemAlloc( int sizeMemAlloc ) {
  if( sizeMemAlloc < 10 ) // min 10
    sizeMemAlloc = 10;
  if( sizeMemAlloc > 100000 ) // max 100k
    sizeMemAlloc = 100000;
  _sizeMemAlloc = sizeMemAlloc;
} // XmlParser::setSizeMemAlloc

void // clean malformed XML tags
XmlParser::setDoFormatTags( bool doFormatTags ) {
  _doFormatTags = doFormatTags;
} // XmlParser::setDoFormatTags

/******************************************************************************/

void /// reads XML file and returns root object
XmlParser::parse( Str fileName ) {

  FileStr file; // standard file stream

  try { // try anything ~8>

    file.open( (char*)fileName.c_str( ), std::ios::in );

    if( file.fail( ) ) {
      Str msg = "XmlParser::parseFile - can not open file: ";
      throw Failure( msg.append( fileName ) );
    } // no file or locked up by another process

    _parse( file ); // parse file using set XmlHandler

    file.close( ); // close read file

  } catch( Failure& f ) { // SYS::Failure
    if( !file.fail( ) )
      file.close( );
    throw f;
  } catch( Error& e ) { // SYS::Error
    if( !file.fail( ) )
      file.close( );
    throw e;
  } catch( Exception& e ) { // SYS::Exception
    if( !file.fail( ) )
      file.close( );
    throw e;
  } catch( std::exception& e ) { // case not possible by _parse( .. ) method
    if( !file.fail( ) )
      file.close( );
    throw Exception( "SYS::XmlParser::parseFile - std::exception caught" );
  } catch( ... ) { // case not possible by _parse( .. ) method
    if( !file.fail( ) )
      file.close( );
    throw Exception( "SYS::XmlParser::parseFile - unkown exception caught" );
  } // try

} // XmlParser::parseFile

/******************************************************************************/

void // this function parses a line char by char
XmlParser::_parse( FileStr& file ) {

  try { // try everything .. like chicken's road rash ~8>

    file.unsetf( std::ios_base::skipws ); // include white spaces

    _lineNo = 0; // count lines for telling XML file errors
    _charNo = 0; // count characters for telling XML file errors
    // Defining a state machine for parsing '< .. >', '..', and '> .. <'
    _switchState = false; // signal when to switch a state
    _isReadingTxt = true;  // 1 .. condition 0 = c0 .. state machine
    _isReadingTag = false; // 0 .. condition 1 = c1 .. state machine
    _isReadingAlt = false; // 0 .. condition 2 = c2 .. state machine
    _state = idle;         // set state machine of parser to be idle
    _inSpike = 0; // checks a tag to be consistent .. 0 .. 1 .. 0 .. 1
    _spikeOpened = 0; // count up on opening spike .. 0 .. 1 .. 2 .. 3
    _spikeClosed = 0; // count up on closing spike .. 0 .. 1 .. 2 .. 3
    char c = '\0'; // actual character
    bool storeChar = true;
    Str str; // current string for collecting characters
    str.clear( ); // not necessary .. anyway

    _xmlHandler->startDoc( ); // calls this before reading document

    while( file >> c ) { // read character by character

      storeChar = true;

      if( c == '\t' ) // replace tab stops by white spaces
        c = ' ';

      if( c == '\n' || c == '\r' ) { // replace break lines by white spaces
        c = ' ';
        _lineNo++;
      } // if \n \r

      // conditions of the state machine - starting tag
      if( c == '<' && _isReadingTxt && !_isReadingTag && !_isReadingAlt ) {
        _isReadingTxt = false; // c0 == 0
        _isReadingTag = true;  // c1 == 1
        _isReadingAlt = false; // c2 == 0
        _switchState = true;
        // TODO exceptions are not working - parser works on <tag < alt="1"> ..
        if( ( _inSpike != 0 ) || ( _spikeOpened != _spikeClosed ) )
          throw Failure(
            "SYS::XmlParser::parseFile - XML file has bug in structure" );
        _inSpike++;  // in correct XML structures; 0 => 1
        _spikeOpened++; // count up; .. 2 => 3 ..
      } // c == '<'

      // conditions of the state machine - ending tag
      if( c == '>' && !_isReadingTxt && _isReadingTag && !_isReadingAlt ) {
        _isReadingTxt = true;  // c0 == 1
        _isReadingTag = false; // c1 == 0
        _isReadingAlt = false; // c2 == 0
        _switchState = true;
        _inSpike--; // in correct XML structures; 1 => 0
        _spikeClosed++; // count up; .. 2 => 3 ..
        // TODO exceptions are not working - parser works on <tag alt="1"> > ..
        if( ( _inSpike != 0 ) || ( _spikeOpened != _spikeClosed ) )
          throw Failure(
            "SYS::XmlParser::parseFile - XML file has bug in structure" );
      } // c == '>'

      // conditions of the state machine - switching attributes of tag
      if( c == '"' && !_isReadingTxt && _isReadingTag ) {
        // < " .. " >  =>  < .. " " .. >  =>  < " .. " >  => ..
        _isReadingTxt = false;          // c0 == 0
        _isReadingTag = true;           // c1 == 1
        _isReadingAlt = !_isReadingAlt; // c2 == !c2
      } // c == '"'

      // state machine - determine the state
      if( _isReadingTxt && !_isReadingTag && !_isReadingAlt ) {
        _state = readingTag; // reading text inside of an XML tag
      } else if( !_isReadingTxt && _isReadingTag && !_isReadingAlt ) {
        _state = readingTxt; // reading text outside an XML tag
      } else if( !_isReadingTxt && _isReadingTag && _isReadingAlt ) {
        _state = readingAlt; // reading attribute inside an XML tag
      } else {
        throw Error(
          "SYS::XmlParser::parseFile - unknown state of state machine!" );
      } // if

      // state machine - performing operations for each state
      switch( _state ) {

        case idle: // could never happen in case of implementation
          throw Failure( "SYS::XmlParser::parseFile - state machine is idle!" );
          break;

        case readingTag: // reading TAG < .. > </ .. > < .. />
          if( _switchState ) {
            str = _strTool->trimS( str ); // cut left and right garbage
            if( !str.empty( ) ) {
              str += c;
              _charNo++;
              storeChar = false; // do not store char again
              if( _doFormatTags ) // else they have white spaces
                str = _xmlTool->format( str );
              if( _xmlTool->check4Ending( str ) ) // pass found TAG to handler
                _xmlHandler->endTag( str ); // case for </ .. >
              else
                _xmlHandler->startTag( str ); // all < >, < />, <? ?>, <!-- -->
              str.clear( );
            } // if
            _switchState = false;
          } // if changed state
          break;

        case readingTxt: // reading TEXT .. < > .. </ > .. < /> ..
          if( _switchState ) {
            str = _strTool->trimS( str ); // do not read blank strings!
            if( !str.empty( ) ) {
              if( _doFormatTags ) // else they have white spaces
                str = _xmlTool->format( str );
              _xmlHandler->characters( str ); // pass found TEXT to handler
              str.clear( );
            } // if
            _switchState = false;
          } // if changed state
          break;

        case readingAlt: // reading attribute < " .. " > < ".." />
          // still nothing to do yet ~8>
          break;

        default:
          throw Error(
            "SYS::XmlParser::parseFile - state machine in unknown state:",
            (int)_state );
          break;

      }; // switch

      if( storeChar ) { // add current char to string and keep it in mind
        str += c; // add character to current string
        _charNo++; // add number of processed characters
      } // if storeChar

    } // c - each character

    _state = idle; // set state machine of parser to be idle
    _xmlHandler->endDoc( ); // calls this at end of document

  } catch( Failure& f ) {
    throw Failure(
      f.declare( ).append( " @ line no: " ).append( _strTool->doI2S( _lineNo ) )
          .append( " @ char pos: " ).append( _strTool->doI2S( _charNo ) ) );
  } catch( Error& e ) {
    throw Error(
      e.declare( ).append( " @ line no: " ).append( _strTool->doI2S( _lineNo ) )
          .append( " @ char pos: " ).append( _strTool->doI2S( _charNo ) ) );
  } catch( Exception& e ) {
    throw Exception(
      e.declare( ).append( " @ line no: " ).append( _strTool->doI2S( _lineNo ) )
          .append( " @ char pos: " ).append( _strTool->doI2S( _charNo ) ) );
  } catch( std::exception& e ) {
    Str msg = "SYS::XmlParser::parse - std::exception caught - ";
    msg.append( " @ line no: " ).append( _strTool->doI2S( _lineNo ) ).append(
      " @ char pos: " ).append( _strTool->doI2S( _charNo ) );
    throw SYS::Exception( msg );
  } catch( ... ) {
    Str msg = "SYS::XmlParser::parse - unknown exception caught - ";
    msg.append( " @ line no: " ).append( _strTool->doI2S( _lineNo ) ).append(
      " @ char pos: " ).append( _strTool->doI2S( _charNo ) );
    throw SYS::Exception( msg );
  } // try

} // XmlParser::_parse

/******************************************************************************/

void // called by constructor for initializing members
XmlParser::_init( void ) {
  // read this from xmlcc.xml later ..
  _sizeMemAlloc = 1000; // memory allocation for 1 to 999, 1000 to 1999, ..
  _doFormatTags = true; // clean up XML tags before storing
  // initialize values of state machine
  _state = idle; // set state machine to be idle
  _switchState = false; // switches state if set true in cycle
  _isReadingTxt = false; // is reading text between XML tag
  _isReadingAlt = false; // is reading attribute in XML tag
  _isReadingTag = false; // is reading XML tag
  // initialize values for information on exceptions
  _lineNo = 0; // count lines for telling XML file errors
  _charNo = 0; // count characters for telling XML file errors
  _inSpike = 0; // checks a tag to be consistent
  _spikeOpened = 0; // count opening spikes
  _spikeClosed = 0; // count closing spikes
} // XmlParser::_init

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
