/** 
 * @file xmlccSaxHandler.cpp
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

#include "./xmlccSaxHandler.h" // header

/******************************************************************************/

#ifdef _MSC_VER
#pragma warning( disable:4100 ) // for unused objects
#endif // _MSC_VER // _WIN32

/******************************************************************************/

namespace XMLCC {

namespace SAX {

/******************************************************************************/

/// constructor
Handler::Handler( void ) {
} // Handler

/// destructor
Handler::~Handler( void ) {
} // ~Handler

/******************************************************************************/

void // called before reading document
Handler::startDoc( void ) {

  throw SYS::Failure( "SAX::Handler - do not use base handler class" );

} // Handler::startDocument

/******************************************************************************/

void // called for each starting XML tag
Handler::startTag( Str tag ) {

  throw SYS::Failure( "SAX::Handler - do not use base handler class" );

} // Handler::startNode

/******************************************************************************/

void // called for each text value in XML
Handler::characters( Str txt ) {

  throw SYS::Failure( "SAX::Handler - do not use base handler class" );

} // Handler::characters

/******************************************************************************/

void // called for each ending XML tag
Handler::endTag( Str tag ) {

  throw SYS::Failure( "SAX::Handler - do not use base handler class" );

} // Handler::endNode

/******************************************************************************/

void // called after reading document
Handler::endDoc( void ) {

  throw SYS::Failure( "SAX::Handler - do not use base handler class" );

} // Handler::endDocument

/******************************************************************************/

} // namespace SAX

} // namespace XMLCC

/******************************************************************************/
