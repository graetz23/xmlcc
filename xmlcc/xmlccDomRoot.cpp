/** 
 * @file xmlccDomRoot.cpp
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

#include "./xmlccDomRoot.h" // DOM::Root
#include "./xmlccDomHeader.h" // DOM::Header
#include "./xmlccDomComment.h" // DOM::Comment
#include "./xmlccDomElement.h" // DOM::Element

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Root::Root( void ) :
    Node( "XMLCC_ROOT" ) {
} // Root::Root

/// constructor
Root::Root( Str fileName ) :
    Node( fileName ) {
} // Root::Root

/// add a header
Root::Root( Str fileName, Node* header ) :
    Node( fileName ) {
  addNode( header );
} // Root::Root 

/// add also the single XML root element
Root::Root( Str fileName, Node* header, Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( rootElement );
} // Root::Root 

/// add one comment
Root::Root( Str fileName, Node* header, Comment* c0, Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( c0 );
  addNode( rootElement );
} // Root::Root 

/// add two comments
Root::Root( Str fileName, Node* header, Comment* c0, Comment* c1,
    Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( c0 );
  addNode( c1 );
  addNode( rootElement );
} // Root::Root 

/// add three comments
Root::Root( Str fileName, Node* header, Comment* c0, Comment* c1, Comment* c2,
    Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( c0 );
  addNode( c1 );
  addNode( c2 );
  addNode( rootElement );
} // Root::Root 

/// add four comments
Root::Root( Str fileName, Node* header, Comment* c0, Comment* c1, Comment* c2,
    Comment* c3, Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( c0 );
  addNode( c1 );
  addNode( c2 );
  addNode( c3 );
  addNode( rootElement );
} // Root::Root 

/// add five comments
Root::Root( Str fileName, Node* header, Comment* c0, Comment* c1, Comment* c2,
    Comment* c3, Comment* c4, Element* rootElement ) :
    Node( fileName ) {
  addNode( header );
  addNode( c0 );
  addNode( c1 );
  addNode( c2 );
  addNode( c3 );
  addNode( c4 );
  addNode( rootElement );
} // Root::Root 

/// destructor
Root::~Root( void ) {
} // ~Root

/******************************************************************************/

Str /// returns the stored file name of this root
Root::getFileName( void ) {
  return getStr( );
} // Root::getFileName

void /// sets the file name of this root
Root::setFileName( Str fileName ) {
  setStr( fileName );
} // Root::setFileName

/******************************************************************************/

std::ostream& /// std::ostream
operator <<( std::ostream& s, Root* node ) {

  int noOfNodes = node->getNoOfNodes( );

  for( int o = 0; o < noOfNodes; o++ ) {

    DOM::Node* leaf = node->getNode( o );

    leaf->setIndentation( node );

    s << leaf << std::flush;

  } // o

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
