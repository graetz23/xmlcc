/** 
 * @file xmlccDomAttribute.cpp
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2022 Christian (graetz23@gmail.com)
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

#include "./xmlccDomAttribute.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Attribute::Attribute( Str name ) :
    Node( name ) {
  _value = ""; /// attribute's value; attribute's name is stored in _tag
} // Attribute

/// constructor
Attribute::Attribute( Str name, Str value ) :
    Node( name ) {
  _value = value; /// attribute's value; attribute's name is stored in _tag
} // Attribute

/// destructor
Attribute::~Attribute( void ) {
} // ~Attribute

/******************************************************************************/

Str /// returns the stored name of this attribute
Attribute::getName( void ) {
  return getStr( );
} // Attribute::getName

void /// sets the name of this attribute
Attribute::setName( Str name ) {
  setStr( name );
} // Attribute::setName

/******************************************************************************/

Str /// returns the stored value of this attribute
Attribute::getValue( void ) {
  return _value;
} // Attribute::getValue

void /// sets the value of this attribute
Attribute::setValue( Str value ) {
  _value = value;
} // Attribute::setValue

/******************************************************************************/

std::ostream& // for std::cout
operator <<( std::ostream& s, Attribute* node ) {

  s << node->getName( ) << "=\"" << node->getValue( ) << "\"" << std::flush;

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
