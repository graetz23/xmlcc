/** 
 * @file xmlccDomCore.cpp
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

#include "./xmlccDomCore.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Core::Core( void ) {
} // Core

/// destructor
Core::~Core( void ) {
} // ~Core

/******************************************************************************/

TagList* // reads 2 TagList* (StrList*)
Core::parseFile2TagList( Str fileName ) {
  TagList* tagList = 0;
  try { // parse & store 2 List< std::string >*
    tagList = Parser::parseFile( fileName );
    if( tagList == 0 ) {
      Str strFailure = "DOM::Core::parseFile2TagList - ";
      strFailure.append( "parsed but TagList* is null - " );
      strFailure.append( "file not found, is empty, or not XML!" );
      throw SYS::Failure( strFailure );
    } // if
  } catch( SYS::Failure& f ) {
    if( tagList != 0 )
      delete tagList;
    throw f; // file not found, file empty, etc ..
  } catch( SYS::Error& e ) {
    throw e; // throw again
  } catch( SYS::Exception& e ) {
    throw SYS::Error( e.declare( ) ); // convert
  } catch( std::exception& e ) {
    Str strError =
        "DOM::Core::parseFile2TagList - standard exception caught - ";
    strError.append( e.what( ) );
    throw SYS::Error( strError );
  } catch( ... ) {
    Str strError =
        "DOM::Core::parseFile2TagList - unknown exception caught!";
    throw SYS::Error( strError );
  } // try
  return tagList;
} // Core::parseFile2TagList

/******************************************************************************/

Root* /// reads XML file and returns root object
Core::parseFile2DomTree( Str fileName ) {
  Root* root = 0;
  TagList* tagList = 0;
  try {
    // parse file and store it to a list of strings
    tagList = parseFile2TagList( fileName );
    // map any XML tag structure to DOM tree; always Root* returned
    root = (Root*)buildDomTreeOfTagList( tagList );
    if( tagList != 0 )
      delete tagList;
  } catch( SYS::Failure& f ) {
    if( tagList != 0 )
      delete tagList;
    if( root != 0 )
      delete root;
    throw f; // file not found, file empty, etc ..
  } catch( SYS::Error& e ) {
    throw e; // throw again
  } catch( SYS::Exception& e ) {
    throw SYS::Error( e.declare( ) ); // convert
  } catch( std::exception& e ) {
    Str strError =
        "DOM::Core::parseFile2DomTree - standard exception caught - ";
    strError.append( e.what( ) );
    throw SYS::Error( strError );
  } catch( ... ) {
    Str strError =
        "DOM::Core::parseFile2DomTree - unknown exception caught!";
    throw SYS::Error( strError );
  } // try
  return root; // go for 'delete root' ~8>
} // Core::parseFile2DomTree

/******************************************************************************/

Node* // map any XML tag structure to DOM tree; always Root* returned
Core::buildDomTreeOfTagList( TagList* tagList ) {
  Node* node = 0;
  try {
    // map any XML tag structure to DOM tree; always Root* returned
    node = _tokenizer.buildDomTreeOfTagList( tagList );
  } catch( SYS::Failure& f ) {
    if( node != 0 )
      delete node;
    throw f; // file not found, file empty, etc ..
  } catch( SYS::Error& e ) {
    throw e; // throw again
  } catch( SYS::Exception& e ) {
    throw SYS::Error( e.declare( ) ); // convert
  } catch( std::exception& e ) {
    Str strError =
        "DOM::Core::buildDomTreeOfTagList - standard exception caught - ";
    strError.append( e.what( ) );
    throw SYS::Error( strError );
  } catch( ... ) {
    Str strError =
        "DOM::Core::buildDomTreeOfTagList - unknown exception caught!";
    throw SYS::Error( strError );
  } // try
  return node;
} // Core::buildDomTreeOfTagList

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
