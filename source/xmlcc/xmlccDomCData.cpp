/** 
 * @file xmlccDomCData.cpp
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

#include "./xmlccDomCData.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
CData::CData( Str content ) :
    Node( content ) {
} // CData

/// destructor
CData::~CData( void ) {
} // ~CData

/******************************************************************************/

Str /// returns the stored content of this CData
CData::getContent( void ) {
  return getStr( );
} // CData::getContent

void /// sets the content of this CData
CData::setContent( Str content ) {
  setStr( content );
} // CData::setContent

/******************************************************************************/

std::ostream& /// std::ostream
operator <<( std::ostream& s, CData* node ) {

  node->doIndentation( s );

  s << "<![CDATA[" << node->getContent( ) << "]]>" << std::endl << std::flush;

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/