/** 
 * @file xmlccDomNode.cpp
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

#include "./xmlccDomNode.h" // DOM::Node
#include "./xmlccDomRoot.h" // DOM::Root
#include "./xmlccDomHeader.h" // DOM::Header
#include "./xmlccDomDoctype.h" // DOM::Doctype
#include "./xmlccDomComment.h" // DOM::Comment
#include "./xmlccDomCData.h" // DOM::CData
#include "./xmlccDomElement.h" // DOM::Element
#include "./xmlccDomAttribute.h" // DOM::Attribute
#include "./xmlccDomValue.h" // DOM::Value

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

// constructor
Node::Node( Str string ) {
  _name = string;
  _indentation = 0;
  _indentationSize = _XMLCC_INDENTATION_SIZE_; /// set in xmlccDefines.h
  _nodeList = new NodeList( ); /// THIS DOES NOT ALLOCATE MEMORY IN ADVANCE
} // Node

// destructor with recursive powers kills the node tree; should be virtual in .h
Node::~Node( void ) {
  for( int n = 0; n < _nodeList->size( ); n++ )
    delete _nodeList->get( n );
  delete _nodeList;
} // ~Node

/******************************************************************************/

void // set tag for an node
Node::setStr( Str string ) {
  _name = string;
} // Node::setTag

Str // get string of an node
Node::getStr( void ) {
  return _name;
} // Node::getStr

/******************************************************************************/

Tag // get XML tag as std::string; running recursively
Node::getTag( void ) {
  StrStream stream;
  stream << this;
  Tag tag = stream.str( ); // std::string
  return tag.substr( 0, tag.length( ) - 1 ); // skip last symbol; '\n'
} // Node::getTag

/******************************************************************************/

void /// push node back 2 list
Node::addNode( Node* node ) {
  _nodeList->add( node );
} // Node::addNode

/******************************************************************************/

int /// get no of objects
Node::getNoOfNodes( void ) {
  return _nodeList->size( );
} // Node::getNoOfNodes

Node* /// get node of internal no
Node::getNode( int no ) {
  return _nodeList->get( no );
} // Node::getNode

Node**  /// get all objects as arrays
Node::getNodes( void ) {
  return _nodeList->arr( );
} // Node::getNodes

/******************************************************************************/

void // set indentation for std::ostream
Node::setIndentation( Node* node ) {
  _indentation = node->getIndentation( );
} // Node::setIndentation

int // get indentation for std::ostream
Node::getIndentation( void ) {
  return _indentation;
} // Node::getIndentation

void // increase indentation
Node::incIndentation( Node* node ) {
  _indentation = node->getIndentation( ) + _indentationSize;
} // Node::incIndentation

void // decrease indentation
Node::decIndentation( Node* node ) {
  _indentation = node->getIndentation( ) - _indentationSize;
} // Node::decIndentation

/******************************************************************************/

std::ostream& // for std::cout
operator <<( std::ostream& s, Node* node ) {
  if( dynamic_cast< Root* >( node ) != 0 ) {
    Root* root = (Root*)node;
    s << root << std::flush;
  } else if( dynamic_cast< Header* >( node ) != 0 ) {
    Header* header = (Header*)node;
    s << header << std::flush;
  } else if( dynamic_cast< Doctype* >( node ) != 0 ) {
    Doctype* doctype = (Doctype*)node;
    s << doctype << std::flush;
  } else if( dynamic_cast< Comment* >( node ) != 0 ) {
    Comment* comment = (Comment*)node;
    s << comment << std::flush;
  } else if( dynamic_cast< CData* >( node ) != 0 ) {
    CData* cdata = (CData*)node;
    s << cdata << std::flush;
  } else if( dynamic_cast< Element* >( node ) != 0 ) {
    Element* element = (Element*)node;
    s << element << std::flush;
  } else if( dynamic_cast< Attribute* >( node ) != 0 ) {
    Attribute* attribute = (Attribute*)node;
    s << attribute << std::flush;
  } else if( dynamic_cast< Value* >( node ) != 0 ) {
    Value* value = (Value*)node;
    s << value << std::flush;
  } else {
    throw SYS::Error( "DOM::Node::<< - unknown type of Node*!" );
  } // if
  return s;
} // Node::operator << 

/******************************************************************************/

void /// add indentation to ostream
Node::doIndentation( std::ostream& s ) {
  for( int w = 0; w < _indentation; w++ )
    s << " " << std::flush;
} // Node::doIndentation

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
