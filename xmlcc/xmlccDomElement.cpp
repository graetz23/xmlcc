/** 
 * @file xmlccDomElement.cpp
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

#include <stdarg.h>
#include "./xmlccDomElement.h" // Element
#include "./xmlccDomAttribute.h" // Attribute
#include "./xmlccDomComment.h" // Comment
#include "./xmlccDomCData.h" // CData
#include "./xmlccDomValue.h" // Value

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Element::Element( Str tag ) :
    Node( tag ) {
} // Element

/******************************************************************************/

/// constructor
Element::Element( Str tag, Str value ) :
    Node( tag ) {
  addNode( new Value( value ) );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0 ) :
    Node( tag ) {
  addNode( node0 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9 ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE, Node* nodeF ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
  addNode( nodeF );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE, Node* nodeF, Node* nodeG ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
  addNode( nodeF );
  addNode( nodeG );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE, Node* nodeF, Node* nodeG, Node* nodeH ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
  addNode( nodeF );
  addNode( nodeG );
  addNode( nodeH );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE, Node* nodeF, Node* nodeG, Node* nodeH,
    Node* nodeI ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
  addNode( nodeF );
  addNode( nodeG );
  addNode( nodeH );
  addNode( nodeI );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN
Element::Element( Str tag, Node* node0, Node* node1, Node* node2,
    Node* node3, Node* node4, Node* node5, Node* node6, Node* node7,
    Node* node8, Node* node9, Node* nodeA, Node* nodeB, Node* nodeC,
    Node* nodeD, Node* nodeE, Node* nodeF, Node* nodeG, Node* nodeH,
    Node* nodeI, Node* nodeJ ) :
    Node( tag ) {
  addNode( node0 );
  addNode( node1 );
  addNode( node2 );
  addNode( node3 );
  addNode( node4 );
  addNode( node5 );
  addNode( node6 );
  addNode( node7 );
  addNode( node8 );
  addNode( node9 );
  addNode( nodeA );
  addNode( nodeB );
  addNode( nodeC );
  addNode( nodeD );
  addNode( nodeE );
  addNode( nodeF );
  addNode( nodeG );
  addNode( nodeH );
  addNode( nodeI );
  addNode( nodeJ );
} // Element::Element

/******************************************************************************/

/// COMPOSITE PATTERN for more than 20
Element::Element( Str tag, int noOfNodes, Node* node, ... ) :
    Node( tag ) {

  addNode( node );

  noOfNodes--; // due to that the first node is stored already

  // va_list params = 0; // g++ reports this as an error, due to init by int
  va_list params; // g++ reports this as an error, due to init by int
  va_start( params, node );

  Node* nodeNext = 0;
  for( int o = 0; o < noOfNodes; o++ ) {

    nodeNext = va_arg( params, Node* );

    if( nodeNext != 0 )
      addNode( nodeNext );

  } // o

  va_end( params );

} // Element

/******************************************************************************/

/// COMPOSITE PATTERN for more than 20
Element::Element( Str tag, Str value, int noOfNodes, Node* node, ... ) :
    Node( tag ) {

  addNode( new Value( value ) );

  addNode( node );

  noOfNodes--; // due to that the first node is stored already

  // va_list params = 0; // g++ reports this as an error, due to init by int
  va_list params; // g++ reports this as an error, due to init by int

  va_start( params, node );

  Node* nodeNext = 0;
  for( int o = 0; o < noOfNodes; o++ ) {

    nodeNext = va_arg( params, Node* );

    if( nodeNext != 0 )
      addNode( nodeNext );

  } // o

  va_end( params );

} // Element

/******************************************************************************/

/// destructor
Element::~Element( void ) {
} // ~Element

/******************************************************************************/

Str /// returns the stored tag of this element
Element::getTag( void ) {
  return getStr( );
} // Element::getTag

void /// sets the tag of this element
Element::setTag( Str tag ) {
  setStr( tag );
} // Element::setTag

/******************************************************************************/

Str /// returns the FIRST stored value of this element
Element::getValue( void ) {

  Value* valueNode = 0;
  int noOfNodes = getNoOfNodes( );

  if( noOfNodes > 0 ) {

    int pos = 0;
    bool search = true;
    while( search ) {

      Node* leaf = getNode( pos );

      if( dynamic_cast< Value* >( leaf ) != 0 ) {
        valueNode = (Value*)leaf;
        search = false;
      }

      if( pos + 1 == noOfNodes )
        search = false;

      pos++;
    } // search

  } // if is not standalone

  Str value = "";

  if( valueNode != 0 )
    value = valueNode->getValue( );

  return value;

} // Element::getValue

/******************************************************************************/

Str /// returns the FIRST stored value of this element
Element::getValue( int indx ) {

  Value* valueNode = 0;
  int noOfNodes = getNoOfNodes( );

  if( noOfNodes > 0 ) {

    int pos = 0;
    int all = 0;
    bool search = true;
    while( search ) {

      Node* leaf = getNode( indx );

      if( dynamic_cast< Value* >( leaf ) != 0 ) {
        valueNode = (Value*)leaf;
        pos++;
      }

      if( pos == indx )
        search = false;

      if( all + 1 == noOfNodes )
        search = false;

      all++;
    } // search

  } // if is not standalone

  Str value = "";

  if( valueNode != 0 )
    value = valueNode->getValue( );

  return value;

} // Element::getValue

/******************************************************************************/

int /// sets the value of this element
Element::getNoOfValues( void ) {

  int noOfValues = 0;

  int noOfNodes = getNoOfNodes( );

  if( noOfNodes > 0 ) {

    int pos = 0;
    bool search = true;
    while( search ) {

      Node* leaf = getNode( pos );

      if( dynamic_cast< Value* >( leaf ) != 0 )
        noOfValues++;

      if( pos + 1 == noOfNodes )
        search = false;

      pos++;
    } // search

  } // if is not standalone

  return noOfValues;

} // Element::getNoOfValues

/******************************************************************************/

void /// sets the value of this element
Element::addValue( Str value ) {
  addNode( new Value( value ) );
} // Element::addValue

/******************************************************************************/

std::ostream& /// std::ostream
operator <<( std::ostream& s, Element* node ) {

  node->doIndentation( s );

  s << "<" << node->getTag( ) << std::flush;

  int noOfNodes = node->getNoOfNodes( );

  int countCData = 0;
  int countValues = 0;
  int countComments = 0;
  int countElements = 0;
  for( int o = 0; o < noOfNodes; o++ ) {

    Node* leaf = node->getNode( o );

    if( dynamic_cast< Attribute* >( leaf ) != 0 ) {

      Attribute* attribute = (Attribute*)leaf;

      s << " " << attribute << std::flush;

    } // if attribute

    if( dynamic_cast< CData* >( leaf ) != 0 )
      countCData++;

    if( dynamic_cast< Value* >( leaf ) != 0 )
      countValues++;

    if( dynamic_cast< Comment* >( leaf ) != 0 )
      countComments++;

    if( dynamic_cast< Element* >( leaf ) != 0 )
      countElements++;

  } // o

  Str value = node->getValue( );

  if( countElements == 0 && countComments == 0 && countCData == 0 ) {

    if( countValues == 0 ) {

      s << "/>" << std::endl << std::flush;

    } else if( countValues == 1 ) {

      s << ">" << std::flush;

      for( int o = 0; o < noOfNodes; o++ ) {

        Node* leaf = node->getNode( o );

        if( dynamic_cast< Value* >( leaf ) != 0 ) {

          Value* value = (Value*)leaf;

          value->incIndentation( node );

          s << value << std::flush;

          value->decIndentation( node );

        } // if value

      } // for

      s << "</" << node->getTag( ) << ">" << std::endl << std::flush;

    } else {

      s << ">" << std::endl << std::flush;

      for( int o = 0; o < noOfNodes; o++ ) {

        Node* leaf = node->getNode( o );

        if( dynamic_cast< Value* >( leaf ) != 0 ) {

          Value* value = (Value*)leaf;

          value->incIndentation( node );

          value->doIndentation( s );

          s << value << std::endl << std::flush;

          value->decIndentation( node );

        } // if value

      } // for

      node->doIndentation( s );

      s << "</" << node->getTag( ) << ">" << std::endl << std::flush;

    } // if

  } else {

    s << ">" << std::endl << std::flush;

    for( int o = 0; o < noOfNodes; o++ ) {

      Node* leaf = node->getNode( o );

      if( dynamic_cast< Element* >( leaf ) != 0 ) {

        Element* element = (Element*)leaf;

        element->incIndentation( node );

        s << element << std::flush;

        element->decIndentation( node );

      } // if element

      if( dynamic_cast< Value* >( leaf ) != 0 ) {

        Value* value = (Value*)leaf;

        value->incIndentation( node );

        value->doIndentation( s );

        s << value << std::endl << std::flush;

        value->decIndentation( node );

      } // if value

      if( dynamic_cast< Comment* >( leaf ) != 0 ) {

        Comment* comment = (Comment*)leaf;

        comment->incIndentation( node );

        s << comment << std::flush;

        comment->decIndentation( node );

      } // if comment

      if( dynamic_cast< CData* >( leaf ) != 0 ) {

        CData* cdata = (CData*)leaf;

        cdata->incIndentation( node );

        s << cdata << std::flush;

        cdata->decIndentation( node );

      } // if cdata

    } // o

    node->doIndentation( s );

    s << "</" << node->getTag( ) << ">" << std::endl << std::flush;

  } // if has sub elements

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
