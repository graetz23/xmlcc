/** 
 * @file xmlccDomHeader.cpp
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

#include "./xmlccDomHeader.h" // DOM::Header
#include "./xmlccDomAttribute.h" // DOM::Attribute

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// set tag to "xml"
Header::Header( void ) :
    Node( "xml" ) {
  // addNode( new Attribute( "version", "1.0" ) );
  // addNode( new Attribute( "encoding", "UTF-8" ) );
  // addNode( new Attribute( "standalone", "yes" ) );
} // Header::Header

/// set e.g. version="1.0"
Header::Header( Attribute* egVersion ) :
    Node( "xml" ) {
  addNode( egVersion );
} // Header::Header

/// set e.g. version and encoding="UTF-8"
Header::Header( Attribute* egVersion, Attribute* egEncoding ) :
    Node( "xml" ) {
  addNode( egVersion );
  addNode( egEncoding );
} // Header::Header

///  set v., enc., and standalone="yes"
Header::Header( Attribute* egVersion, Attribute* egEncoding,
    Attribute* egStandalone ) :
    Node( "xml" ) {
  addNode( egVersion );
  addNode( egEncoding );
  addNode( egStandalone );
} // Header::Header

/// set data type of node, should be always "xml"
Header::Header( Str tag ) :
    Node( tag ) {
  // addNode( new Attribute( "version", "1.0" ) );
  // addNode( new Attribute( "encoding", "UTF-8" ) );
  // addNode( new Attribute( "standalone", "yes" ) );
} // Header

/// set e.g. version="1.0"
Header::Header( Str tag, Attribute* a0 ) :
    Node( "xml" ) {
  addNode( a0 );
} // Header::Header

/// set e.g. version and encoding="UTF-8"
Header::Header( Str tag, Attribute* a0, Attribute* a1 ) :
    Node( "xml" ) {
  addNode( a0 );
  addNode( a1 );
} // Header::Header

/// set v., enc., and standalone="yes"
Header::Header( Str tag, Attribute* a0, Attribute* a1, Attribute* a2 ) :
    Node( "xml" ) {
  addNode( a0 );
  addNode( a1 );
  addNode( a2 );
} // Header::Header

/// destructor
Header::~Header( void ) {
} // ~Header

/******************************************************************************/

Str /// returns the stored tag of this header 
Header::getTag( void ) {
  return getStr( );
} // Header::getTag

void /// sets the tag of this header
Header::setTag( Str tag ) {
  setStr( tag );
} // Header::setTag

/******************************************************************************/

std::ostream& /// std::ostream
operator <<( std::ostream& s, Header* node ) {

  int noOfAttributes = node->getNoOfNodes( );

  s << "<?" << node->getTag( ) << std::flush;

  for( int o = 0; o < noOfAttributes; o++ ) {

    Node* attribute = node->getNode( o );

    s << " " << attribute << std::flush;

  } // o

  s << "?>" << std::endl << std::flush;

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
