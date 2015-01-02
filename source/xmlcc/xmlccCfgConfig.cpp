/** 
 * @file xmlccCfgConfig.cpp
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2015 Christian Scheiblich (cscheiblich@gmail.com)
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

#include "./xmlccCfgConfig.h" // header

/******************************************************************************/

namespace XMLCC {

namespace CFG {

/******************************************************************************/

/// constructor
Config::Config( void ) {
} // Config

/// destructor
Config::~Config( void ) {
} // ~Config

/******************************************************************************/

DOM::Root* // use this method in static way; Config::parseFile( "file.xml" );
Config::generate( void ) {

  DOM::Root* xml = 0;

  try { // try everything .. like chicken's road rash ~8>

    xml =
        new DOM::Root( "xmlcc.xml",
          new DOM::Header( new DOM::Attribute( "version", "1.0" ) ),
          new DOM::Comment( "XMLCC 1.00 20150101 Amara Faith" ),
          new DOM::Comment( "config file of the xmlcc library" ),
          new DOM::Element( "xmlcc:xmlcc",
            new DOM::Comment( "library configuration; set by user" ),
            new DOM::Element( "xmlcc:config",
              new DOM::Comment( "parser configuration" ),
              new DOM::Element( "xmlcc:parser",
                new DOM::Element( "xmlcc:console",
                  new DOM::Attribute( "talk", "no" ) ),
                new DOM::Element( "xmlcc:clean",
                  new DOM::Attribute( "tags", "yes" ),
                  new DOM::Attribute( "attributes", "yes" ),
                  new DOM::Attribute( "comments", "yes" ) ),
                new DOM::Element( "xmlcc:memory",
                  new DOM::Attribute( "preallocation", "999" ) ) ),
              new DOM::Comment( "tokenizer configuration" ),
              new DOM::Element( "xmlcc:tokenizer",
                new DOM::Element( "xmlcc:console",
                  new DOM::Attribute( "talk", "no" ) ) ) ),
            new DOM::Comment( "library information; refreshed by each call" ),
            new DOM::Element( "xmlcc:info",
              new DOM::Element( "xmlcc:date",
                new DOM::Attribute( "date", "29.12.2014" ) ),
              new DOM::Element( "xmlcc:built",
                new DOM::Attribute( "date", "29.12.2014" ) ),
              new DOM::Element( "xmlcc:version",
                new DOM::Attribute( "number", "0.93" ) ),
              new DOM::Element( "xmlcc:package",
                new DOM::Attribute( "name", "Amara Faith" ) ),
              new DOM::Element( "xmlcc:license",
                new DOM::Attribute( "type", "The MIT License (MIT)" ) ),
              new DOM::Element( "xmlcc:project",
                new DOM::Attribute( "url",
                  "http://code.google.com/p/xmlcc/" ) ),
              new DOM::Element( "xmlcc:author",
                new DOM::Attribute( "name", "Christian Scheiblich" ),
                new DOM::Attribute( "email", "cscheiblich@gmail.com" ) ) ),
            new DOM::Comment( "library system; run unit tests, etc." ),
            new DOM::Element( "xmlcc:system",
              new DOM::Comment( "unit test framework configuration" ),
              new DOM::Element( "xmlcc:tests",
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "sysList", "yes" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "strTool", "yes" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "xmlTool", "yes" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "xmlParser", "no" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "domTokenizer", "yes" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "domController", "yes" ) ),
                new DOM::Element( "xmlcc:test",
                  new DOM::Attribute( "xmlcc", "yes" ) ) ),
              new DOM::Comment(
                "reads chars &compares them; due to use of STL file encoding" ),
              new DOM::CData(
                "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ) ) ) );

  } catch( SYS::Failure& f ) {
    Str msg = "XMLCC::CFG::Config::generate - ";
    throw SYS::Failure( msg.append( f.declare( ) ) );
  } catch( SYS::Error& e ) {
    Str msg = "XMLCC::CFG::Config::generate - ";
    throw SYS::Error( msg.append( e.declare( ) ) );
  } catch( SYS::Exception& e ) {
    Str msg = "XMLCC::CFG::Config::generate - ";
    throw SYS::Error( msg.append( e.declare( ) ) );
  } catch( std::exception& e ) {
    throw SYS::Exception(
      "XMLCC::CFG::Config::generate - std::exception caught!" );
  } catch( ... ) {
    throw SYS::Exception( "XMLCC::CFG::Config::generate - unknown caught!" );
  } // try

  return xml;

} // Config::generate

/******************************************************************************/

void // use this method in static way; Config::parseFile( "file.xml" );
Config::write( DOM::Root* xml ) {

  try { // try everything .. like chicken's road rash ~8>
    std::fstream file; // open file
    file.open( "xmlcc.xml", std::ios::out );
    file << xml; // DOM::Node* 2 std::fstream or write XML file to drive
    file.close( );
    delete xml;
  } catch( SYS::Failure& f ) {
    Str msg = "XMLCC::CFG::Config::write - ";
    throw SYS::Failure( msg.append( f.declare( ) ) );
  } catch( SYS::Error& e ) {
    Str msg = "XMLCC::CFG::Config::write - ";
    throw SYS::Error( msg.append( e.declare( ) ) );
  } catch( SYS::Exception& e ) {
    Str msg = "XMLCC::CFG::Config::write - ";
    throw SYS::Error( msg.append( e.declare( ) ) );
  } catch( std::exception& e ) {
    throw SYS::Exception(
      "XMLCC::CFG::Config::write - std::exception caught!" );
  } catch( ... ) {
    throw SYS::Exception( "XMLCC::CFG::Config::write - unknown caught!" );
  } // try

} // Config::write

/******************************************************************************/

DOM::Root* // use this method in static way; Config::parseFile( "file.xml" );
Config::read( void ) {

  DOM::Root* xml = 0;

  try { // try everything .. like chicken's road rash ~8>

    DOM::Core core; // parsing, cleaning, tokenizing, and model building
    xml = core.parseFile2DomTree( "xmlcc.xml" ); // parse 2 model tree

  } catch( SYS::Failure& f ) { // recovery might be a dead lock ;-)
    if( xml != 0 )
      delete xml;
    write( generate( ) );
    xml = read( ); // recovery
  } catch( SYS::Error& e ) {
    if( xml != 0 )
      delete xml;
    write( generate( ) );
    xml = read( ); // recovery
  } catch( SYS::Exception& e ) {
    if( xml != 0 )
      delete xml;
    write( generate( ) );
    xml = read( ); // recovery
  } catch( std::exception& e ) {
    if( xml != 0 )
      delete xml;
    write( generate( ) );
    xml = read( ); // recovery
  } catch( ... ) {
    if( xml != 0 )
      delete xml;
    write( generate( ) );
    xml = read( ); // recovery
  } // try

  return xml;

} // Config::read

/******************************************************************************/

Str // return the value for the requested configuration
Config::getConfig( Str type, Str tag, Str attribute ) {

  Str value = "";

  DOM::Root* xml = read( );

  // TODO: hack use of config values in version 1.0X

  delete xml;

  return value;

} // Config::getConfig

} // namespace CFG

} // namespace XMLCC

/******************************************************************************/
