/** 
 * @file xmlccDomHandler.cpp
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

#include "./xmlccDomHandler.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Handler::Handler( TagList* tagList ) {

  if( tagList == 0 )
    throw SYS::Failure( "XMLCC::DOM::Handler - given XML list is null!" );

  _tagList = tagList; /// list is keeping all found XML; SYS::List< Str >*

} // Handler

/// destructor
Handler::~Handler( void ) {
} // ~Handler

/******************************************************************************/

void // called before reading document
Handler::startDoc( void ) {

  // do nothing

} // Handler::startDocument

/******************************************************************************/

void // called for each starting XML tag
Handler::startTag( Str tag ) {

  _tagList->add( tag );

} // Handler::startNode

/******************************************************************************/

void // called for each text value in XML
Handler::characters( Str txt ) {

  _tagList->add( txt );

} // Handler::characters

/******************************************************************************/

void // called for each ending XML tag
Handler::endTag( Str tag ) {

  _tagList->add( tag );

} // Handler::endNode

/******************************************************************************/

void // called after reading document
Handler::endDoc( void ) {

  // do nothing

} // Handler::endDocument

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
