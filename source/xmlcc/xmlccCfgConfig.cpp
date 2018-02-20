/** 
 * @file xmlccCfgConfig.cpp
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2018 Christian Scheiblich (cscheiblich@gmail.com)
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
  _root = read( ); // one strategy, take DOM tree to mem
} // Config

/// destructor
Config::~Config( void ) {
  if( _root != 0 )
    delete _root; // delete DOM tree if read; always
} // ~Config

/******************************************************************************/

bool // check if config file is existing
Config::exists( void ) {
  bool isExisting = false;
  Str fileName = "xmlcc.xml"; // static file name
  FileStr file; // standard file stream
  file.open( (char*)fileName.c_str( ), std::ios::in );
  if( !file.fail( ) )
    isExisting = true;
  file.close( );
  return isExisting;
} // Config::isExisting

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
              new DOM::Element( "xmlcc:built",
                new DOM::Attribute( "date", "01.01.2015" ) ),
              new DOM::Element( "xmlcc:version",
                new DOM::Attribute( "number", "1.00" ) ),
              new DOM::Element( "xmlcc:package",
                new DOM::Attribute( "name", "Amara Faith" ) ),
              new DOM::Element( "xmlcc:license",
                new DOM::Attribute( "type", "The MIT License (MIT)" ) ),
              new DOM::Element( "xmlcc:project",
                new DOM::Attribute( "url",
                  "https://github.com/cscheiblich/xmlcc/" ) ),
              new DOM::Element( "xmlcc:user",
                new DOM::Attribute( "name", "Christian Scheiblich" ),
                new DOM::Attribute( "email", "cscheiblich@gmail.com" ) ) ),
            new DOM::Comment( "library system; run unit tests, etc." ),
            new DOM::Element( "xmlcc:system",
              new DOM::Comment( "unit test framework configuration" ),
              new DOM::Element( "xmlcc:test",
                new DOM::Comment( "unit test framework configuration" ),
              new DOM::Element( "xmlcc:sysList",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:sysStrTool",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:sysXmlTool",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:sysXmlParser",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:domTokenizer",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:domController",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Element( "xmlcc:xmlcc",
                new DOM::Attribute( "run", "no" ) ),
              new DOM::Comment(
                "reads chars &compares them; due to use of STL file encoding" ),
              new DOM::CData(
                "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ) ) ) ) );

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
    f.report( );
    std::cout << "generating config file for xmlcc .. " << std::flush;
    write( generate( ) );
    std::cout << "done!" << std::endl << std::flush;
    xml = read( ); // recovery
  } catch( SYS::Error& e ) {
    if( xml != 0 )
      delete xml;
    e.report( );
    std::cout << "generating config file for xmlcc .. " << std::flush;
    write( generate( ) );
    std::cout << "done!" << std::endl << std::flush;
    xml = read( ); // recovery
  } catch( SYS::Exception& e ) {
    if( xml != 0 )
      delete xml;
    e.report( );
    std::cout << "generating config file for xmlcc .. " << std::flush;
    write( generate( ) );
    std::cout << "done!" << std::endl << std::flush;
    xml = read( ); // recovery
  } catch( std::exception& e ) {
    if( xml != 0 )
      delete xml;
    std::cout << "generating config file for xmlcc .. " << std::flush;
    write( generate( ) );
    std::cout << "done!" << std::endl << std::flush;
    xml = read( ); // recovery
  } catch( ... ) {
    if( xml != 0 )
      delete xml;
    std::cout << "generating config file for xmlcc .. " << std::flush;
    write( generate( ) );
    std::cout << "done!" << std::endl << std::flush;
    xml = read( ); // recovery
  } // try

  return xml;

} // Config::read

/******************************************************************************/

/// <config><parser> .. </parser></config>
bool // get config parameter
Config::getConfigParserConsoleTalk( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:parser", "xmlcc:console", "talk" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigParserConsoleTalk

bool // get config parameter
Config::getConfigParserCleanTag( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:parser", "xmlcc:clean", "tags" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigParserCleanTag

bool // get config parameter
Config::getConfigParserCleanAttributes( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:parser", "xmlcc:clean", "attribute" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigParserCleanAttributes

bool // get config parameter
Config::getConfigParserCleanComments( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:parser", "xmlcc:clean", "comments" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigParserCleanComments

int // get config parameter
Config::getConfigParserMemoryPreallocation( void ) {
  int parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:parser", "xmlcc:memory", "preallocation" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2I( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigParserMemoryPreallocation

/******************************************************************************/

/// <config><tokenizer> .. </tokenizer></config>
bool // get config parameter
Config::getConfigTokenizerTalk( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:config", "xmlcc:tokenizer", "xmlcc:console", "talk" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getConfigTokenizerTalk

/******************************************************************************/

/// <config><info> .. </info></config>
Str // get info parameter
Config::getInfoBuiltDate( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:built", "date" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoBuiltDate

Str // get info parameter
Config::getInfoVersionNumber( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:version", "number" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoVersionNumber

Str // get info parameter
Config::getInfoPackageName( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:package", "name" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoPackageName

Str // get info parameter
Config::getInfoLicenseType( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:license", "type" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoLicenseType

Str // get info parameter
Config::getInfoProjectUrl( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:project", "url" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoProjectUrl

Str // get info parameter
Config::getInfoUserName( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:user", "name" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoUserName

Str // get info parameter
Config::getInfoUserEmail( void ) {
  Str parameter = ""; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:info", "xmlcc:user", "email" );
  if( res != 0 )
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getInfoUserEmail

/******************************************************************************/

/// <config><system> .. </system></config>
bool // get system parameter
Config::getSystemTestSysList( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:sysList", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestSysList

bool // get system parameter
Config::getSystemTestSysStrTool( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:sysStrTool", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestStrTool

bool // get system parameter
Config::getSystemTestSysXmlTool( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:sysXmlTool", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestXmlTool

bool // get system parameter
Config::getSystemTestSysXmlParser( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:sysXmlParser", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestXmlParser

bool // get system parameter
Config::getSystemTestDomTokenizer( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:domTokenizer", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestDomTokenizer

bool // get system parameter
Config::getSystemTestDomController( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:domController", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestDomController

bool // get system parameter
Config::getSystemTestXmlcc( void ) {
  bool parameter = true; // default
  DOM::Root* xmlConfigFile = read( ); // load config file from drive
  DOM::Node* res = _controller.search( xmlConfigFile, "xmlcc:xmlcc",
    "xmlcc:system", "xmlcc:test", "xmlcc:xmlcc", "run" );
  if( res != 0 ) {
    Str readParameter = ( (DOM::Attribute*)res )->getValue( );
    parameter = _strTool.doS2B( readParameter ); // conversion
  } // if
  _controller.erase( xmlConfigFile );
  return parameter;
} // Config::getSystemTestXmlcc

Str // get system parameter
Config::getSystemCData( void ) {

  Str parameter = "";

  throw SYS::Error( "CFG::Config::getSystemCData - not implemented yet!" );

  return parameter;

} // Config::getSystemCData

/******************************************************************************/

} // namespace CFG

} // namespace XMLCC

/******************************************************************************/
