/** 
 * @file xmlccDomParser.cpp
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2016 Christian Scheiblich (cscheiblich@gmail.com)
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

#include "./xmlccDomParser.h" // header
#include "./xmlccCfgConfig.h" // CFG::config

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Parser::Parser( void ) {
} // Parser

/// destructor
Parser::~Parser( void ) {

  // destructor SYS::~XmlParser( ) is deleting object behind _handler pointer

} // ~Parser

/******************************************************************************/

TagList* // use this method in static way; Parser::parseFile( "file.xml" );
Parser::parseFile( Str fileName ) {
  TagList* tagList = new TagList( 999 );
// TODO read and set by xmlcc.xml - commented lines are recursive :'-(
//  CFG::Config config;
//  int memoryPreallocation = config.getConfigParserMemoryPreallocation( );
//  TagList* tagList = new TagList( memoryPreallocation );
  try { // try everything .. or recover
    SYS::XmlParser* xmlParser = new SYS::XmlParser( new Handler( tagList ) );
    xmlParser->parse( fileName );
    delete xmlParser; // deletes in SYS::XmlParser the set DOM::Handler* too
    tagList->opt( ); // optimize memory
  } catch( SYS::Failure& f ) {
    Str msg = "XMLCC::DOM::Parser::parseFile - ";
    throw SYS::Failure( msg.append( f.declare( ) ) );
  } catch( SYS::Error& e ) {
    Str msg = "XMLCC::DOM::Parser::parseFile - ";
    throw SYS::Error( msg.append( e.declare( ) ) );
  } catch( SYS::Exception& e ) {
    Str msg = "XMLCC::DOM::Parser::parseFile - ";
    throw SYS::Exception( msg.append( e.declare( ) ) );
  } catch( std::exception& e ) {
    throw SYS::Exception(
      "XMLCC::DOM::Parser::parseFile - std::exception caught!" );
  } catch( ... ) {
    throw SYS::Exception( "XMLCC::DOM::Parser::parseFile - unknown caught!" );
  } // try
  return tagList;
} // Parser::parse

/******************************************************************************/

} // namespace DOM 

} // namespace XMLCC

/******************************************************************************/
