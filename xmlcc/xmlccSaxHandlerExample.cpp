/** 
 * @file xmlccSaxHandlerExample.cpp
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2024 Christian (graetz23@gmail.com)
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

#include "./xmlccSaxHandlerExample.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SAX {

/******************************************************************************/

/// constructor
HandlerExample::HandlerExample( void ) {

  _level = 0;

} // HandlerExample

/// destructor
HandlerExample::~HandlerExample( void ) {
} // ~HandlerExample

/******************************************************************************/

void // called before reading document
HandlerExample::startDoc( void ) {

  std::cout << "XMLCC::SAX::HandlerExample starts reading document" << std::endl
    << std::flush;

} // HandlerExample::startDocument

/******************************************************************************/

void // called for each starting XML tag
HandlerExample::startTag( Str tag ) {

  for( int t = 0; t < _level; t++ ) // print some white spaces
    std::cout << " " << std::flush;

  if( _xmlTool.check4Starting( tag ) ) // check for being '< .. >'
    _level++;  // increase indentation

  std::cout << tag << std::endl << std::flush;

} // HandlerExample::startNode

/******************************************************************************/

void // called for each text value in XML
HandlerExample::characters( Str txt ) {

  for( int t = 0; t < _level; t++ ) // print some white spaces
    std::cout << " " << std::flush;

  std::cout << txt << std::endl << std::flush;

} // HandlerExample::characters

/******************************************************************************/

void // called for each ending XML tag
HandlerExample::endTag( Str tag ) {

  _level--; // reduce indentation

  for( int t = 0; t < _level; t++ ) // print some white spaces
    std::cout << " " << std::flush;

  std::cout << tag << std::endl << std::flush;

} // HandlerExample::endNode

/******************************************************************************/

void // called after reading document
HandlerExample::endDoc( void ) {

  std::cout << "XMLCC::SAX::HandlerExample ends reading document" << std::endl
    << std::flush;

} // HandlerExample::endDocument

/******************************************************************************/

} // namespace SAX

} // namespace XMLCC

/******************************************************************************/
