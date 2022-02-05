/** 
 * @file xmlccSaxParser.cpp
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

#include "./xmlccSaxParser.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SAX {

/******************************************************************************/

/// constructor
Parser::Parser( Handler* handler ) {

  _handler = 0;

  if( handler == 0 )
    throw SYS::Failure( "XMLCC::SAX::Parser - given handler object in null!" );

  _handler = handler;

} // Parser

/// destructor
Parser::~Parser( void ) {

  // destructor SYS::~XmlParser( ) is deleting object behind _handler pointer

} // ~Parser

/******************************************************************************/

void /// reads buffer of type char*
Parser::parseBuffer( char* buffer ) {

  parseBuffer( Str( buffer ) ); // convert char* array to std::string

} // Parser::parseBuffer

/******************************************************************************/

void /// reads buffer of type std::string
Parser::parseBuffer( Str buffer ) {

  if( buffer.length( ) <= 0 )
    throw SYS::Failure( "SAX::Parser::parseBuffer - buffer is empty" );

} // Parser::parseBuffer

/******************************************************************************/

void /// parses XML from file and calls handler's virtual functions
Parser::parseFile( Str fileName ) {

  try { // try everything .. like chicken's road rash ~8>

    SYS::XmlParser* xmlParser = new SYS::XmlParser( _handler );

    xmlParser->parse( fileName );

    delete xmlParser; // deletes XML handler too

  } catch( SYS::Failure& f ) {

    Str msg = "XMLCC::SAX::Parser::parseFile - ";
    throw SYS::Failure( msg.append( f.declare( ) ) );

  } catch( SYS::Error& e ) {

    Str msg = "XMLCC::SAX::Parser::parseFile - ";
    throw SYS::Error( msg.append( e.declare( ) ) );

  } catch( SYS::Exception& e ) {

    Str msg = "XMLCC::SAX::Parser::parseFile - ";
    throw SYS::Exception( msg.append( e.declare( ) ) );

  } catch( std::exception& e ) {

    throw SYS::Exception(
      "XMLCC::SAX::Parser::parseFile - std::exception caught!" );

  } catch( ... ) {

    throw SYS::Exception( "XMLCC::SAX::Parser::parseFile - unknown caught!" );

  } // try

} // Parser::parseFile

/******************************************************************************/

} // namespace SAX

} // namespace XMLCC

/******************************************************************************/
