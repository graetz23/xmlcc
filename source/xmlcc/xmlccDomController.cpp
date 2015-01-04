/** 
 * @file xmlccController.cpp
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

#include "./xmlccDomController.h" // header file of class DOM::Controller

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Controller::Controller( void ) {
} // Controller

/// destructor
Controller::~Controller( void ) {
} // ~Controller

/******************************************************************************/

Node* // return DOM::Element stored at Node* by name or a null pointer
Controller::getElement( Node* node, Str strElement ) {
  Node* element = 0;
  NodeList* elementList = genListOfElements( node );
  int noOfElements = elementList->size( );
  int n = 0;
  bool isSearching = true;
  while( isSearching && ( n < noOfElements ) ) {
    Element* elementNode = (Element*)( elementList->get( n ) );
    Str nameElementNode = elementNode->getStr( );
    if( nameElementNode.compare( strElement ) == 0 ) {
      isSearching = false;
      element = elementNode;
    } // if found
    n++;
  } // while isSearching
  delete elementList;
  return (Node*)( element ); // if DOM::Element not found return null pointer
} // Controller::getElement

Node* // return DOM::Attribute stored at Node* by name or a null pointer
Controller::getAttribute( Node* node, Str strAttribute ) {
  Node* attribute = 0;
  NodeList* attributeList = genListOfAttributes( node );
  int noOfElements = attributeList->size( );
  int n = 0;
  bool isSearching = true;
  while( isSearching && ( n < noOfElements ) ) {
    Attribute* attributeNode = (Attribute*)( attributeList->get( n ) );
    Str nameAttributeNode = attributeNode->getStr( );
    if( nameAttributeNode.compare( strAttribute ) == 0 ) {
      isSearching = false;
      attribute = attributeNode;
    } // if found
    n++;
  } // while isSearching
  delete attributeList;
  return (Node*)( attribute ); // if DOM::Attribute not found return null ptr
} // Controller::getAttribute

/**************************************************************************/

Root* /// create a XMLCC root
Controller::createRoot( void ) {
  return new Root( "file.xml" );
} // Controller::createRoot

Root* /// create XMLCC root, representing the file
Controller::createRoot( Str fileName ) {
  return new Root( fileName );
} // Controller::createRoot

/**************************************************************************/

Node* /// an XML header with standard attributes
Controller::createHeader( void ) {
  // <? xml version="1.0" encoding="UTF-8" standalone="no" ?>
  Node* header = create( Types::Header, "xml" );
  create( header, Types::Attribute, "version", "1.0" );
  //create( header, Types::Attribute, "standalone", "no" );
  //create( header, Types::Attribute, "encoding", "UTF-8" ); // seems to be ~8>
  return header;
} // Controller::createHeader

Node* /// a HTML DOCTYPE header with most common attributes
Controller::createDoctype( void ) {
  // <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  //      "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
  Node* doctype = create( Types::Doctype, "DOCTYPE html PUBLIC" );
  //create( doctype, Types::Attribute, "type", "-//W3C//DTD XHTML 1.0 Strict//EN" );
  //create( doctype, Types::Attribute, "dtd", "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd" );
  return doctype;
} // Controller::createDoctype

/******************************************************************************/

Node* // new node of any type
Controller::create( Types::Type type, Str tag ) {
  Node* node = 0;
  switch( type ) {
    case Types::Root:
      node = new Root( tag );
      break;
    case Types::Header:
      node = new Header( tag );
      break;
    case Types::Doctype:
      node = new Doctype( tag );
      break;
    case Types::Element:
      node = new Element( tag );
      break;
    case Types::Attribute:
      node = new Attribute( tag );
      break;
    case Types::Value:
      node = new Value( tag );
      break;
    case Types::CData:
      node = new CData( tag );
      break;
    case Types::Comment:
      node = new Comment( tag );
      break;
    default:
      throw SYS::Failure( "DOM::Controller - unknown type of Node* requested" );
  } // switch
  return node;
} // Controller::create

Node* // new node of type 'Element with Value' or 'Attribute with value'
Controller::create( Types::Type type, Str tag, Str value ) {
  Node* node = 0;
  switch( type ) {
    case Types::Element:
      node = new Element( tag, value );
      break;
    case Types::Attribute:
      node = new Attribute( tag, value );
      break;
    default:
      throw SYS::Failure(
        "DOM::Controller::create - type is neither DOM::Element nor DOM::Attribute!" );
  } // switch
  return node;
} // Controller::create

/******************************************************************************/

Node* // create a new node and add the passed
Controller::create( Types::Type type, Str tag, Node* leaf ) {
  Node* node = 0;
  switch( type ) {
    case Types::Element:
      node = new Element( tag );
      break;
    default:
      throw SYS::Failure(
        "DOM::Controller::create - must be of type DOM::Element" );
  } // switch
  node->addNode( leaf ); // add passed Node* as leaf of new Node*
  return node;
} // Controller::create

Node* // create a new node with value and add the passed
Controller::create( Types::Type type, Str tag, Str value, Node* leaf ) {
  Node* node = 0;
  switch( type ) {
    case Types::Element:
      node = new Element( tag, value );
      break;
    default:
      throw SYS::Failure(
        "DOM::Controller::create - must be of type DOM::Element" );
  } // switch
  node->addNode( leaf ); // add passed Node* as leaf of new Node*
  return node;
} // Controller::create

void // create a new node and add it to node
Controller::create( Node* root, Types::Type type, Str tag ) {
  Node* node = 0;
  switch( type ) {
    case Types::Header:
      node = new Header( tag );
      break;
    case Types::Doctype:
      node = new Doctype( tag );
      break;
    case Types::Element:
      node = new Element( tag );
      break;
    case Types::Attribute:
      node = new Attribute( tag );
      break;
    case Types::Value:
      node = new Value( tag );
      break;
    case Types::CData:
      node = new CData( tag );
      break;
    case Types::Comment:
      node = new Comment( tag );
      break;
    default:
      throw SYS::Failure( "DOM::Controller - unknown type of Node* requested" );
  } // switch
  root->addNode( node ); // add new Node* to passed Node* root
} // Controller::create

void // create a new node with value and add it to node
Controller::create( Node* root, Types::Type type, Str tag, Str value ) {
  Node* node = 0;
  switch( type ) {
    case Types::Element:
      node = new Element( tag, value );
      break;
    case Types::Attribute:
      node = new Attribute( tag, value );
      break;
    default:
      throw SYS::Failure(
        "DOM::Controller::create - type is neither DOM::Element nor DOM::Attribute!" );
  } // switch
  root->addNode( node ); // add new Node* to passed Node* root
} // Controller::create

/******************************************************************************/

int /// get number of DOM::Header stored at handed node; is not recursive!
Controller::getNoOfHeaders( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfHeaders - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isHeader( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfHeaders

int /// get number of DOM::Doctype stored at handed node; is not recursive!
Controller::getNoOfDoctypes( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfHeaders - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isDoctype( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfDoctypes

int /// get number of DOM::Comment stored at handed node; is not recursive!
Controller::getNoOfComments( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfComments - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isComment( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfComments

int /// get number of DOM::Element stored at handed node; is not recursive!
Controller::getNoOfElements( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfElements - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isElement( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getnoOfElements

int /// get number of DOM::Attribute stored at handed node; is not recursive!
Controller::getNoOfAttributes( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfAttributes - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isAttribute( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfAttributes

int /// get number of DOM::Value stored at handed node; is not recursive!
Controller::getNoOfValues( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfValues - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isValue( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfValues

int /// get number of DOM::CData stored at handed node; is not recursive!
Controller::getNoOfCData( Node* node ) {
  int noOfHits = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getNoOfCData - Node* is null!" );
  for( int n = 0; n < node->getNoOfNodes( ); n++ )
    if( isCData( node->getNode( n ) ) )
      noOfHits++;
  return noOfHits;
} // Controller::getNoOfCData

/******************************************************************************/

void  /// generate array with all DOM::Headers of Node* - not recursive!
Controller::genArrOfHeaders( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfHeaders - Node* is null!" );
  NodeList* nodeList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isHeader( unknown ) )
      nodeList->add( unknown );
  } // n
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::genArrOfHeaders

void  /// generate array with all DOM::Headers of Node* - not recursive!
Controller::genArrOfDoctypes( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfDoctypes - Node* is null!" );
  NodeList* nodeList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isDoctype( unknown ) )
      nodeList->add( unknown );
  } // n
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::genArrOfDoctypes

void // generate array with all DOM::Comment of Node* - not recursive!
Controller::genArrOfComments( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfComments - Node* is null!" );
  NodeList* nodeList = genListOfComments( node );
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::genArrOfComments

void // generate array with all DOM::Element of Node* - not recursive!
Controller::genArrOfElements( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfElements - Node* is null!" );
  NodeList* nodeList = genListOfElements( node );
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::getArrOfElements

void // generate array with all DOM::Attribute of Node* - not recursive!
Controller::genArrOfAttributes( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure(
      "DOM::Controller::genArrOfAttributes - Node* is null!" );
  NodeList* nodeList = genListOfAttributes( node );
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::getArrOfAttributes

void // generate array with all DOM::Value of Node* - not recursive!
Controller::genArrOfValues( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfValues - Node* is null!" );
  NodeList* nodeList = genListOfValues( node );
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::getArrOfValues

void  /// generate array with all DOM::CData of Node* - not recursive!
Controller::genArrOfCData( int& size, Node**& arr, Node* node ) {
  size = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genArrOfCData - Node* is null!" );
  NodeList* nodeList = genListOfCData( node );
  size = nodeList->size( );
  arr = nodeList->arr( );
  delete nodeList;
} // Controller::genArrOfCData

/******************************************************************************/

NodeList* /// all DOM::Comment of Node* in NodeList* or empty nodeList; no = 0
Controller::genListOfComments( Node* node ) {
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genListOfComments - Node* is null!" );
  NodeList* commentList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isComment( unknown ) )
      commentList->add( unknown );
  } // n
  commentList->opt( ); // optimize memory
  return commentList;
} // Controller::genListOfComments

NodeList* /// all DOM::Element of Node* in NodeList* or empty nodeList; no = 0
Controller::genListOfElements( Node* node ) {
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genListOfElements - Node* is null!" );
  NodeList* elementList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isElement( unknown ) )
      elementList->add( unknown );
  } // n
  elementList->opt( ); // optimize memory
  return elementList;
} // Controller::genListOfElements

NodeList* /// all DOM::Attribute of Node* in NodeList* or empty nodeList; no = 0
Controller::genListOfAttributes( Node* node ) {
  if( node == 0 )
    throw SYS::Failure(
      "DOM::Controller::genListOfAttributes - Node* is null!" );
  NodeList* attributeList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isAttribute( unknown ) )
      attributeList->add( unknown );
  } // n
  attributeList->opt( ); // optimize memory
  return attributeList;
} // Controller::genListOfAttributes

NodeList* /// all DOM::Value of Node* in NodeList* or empty nodeList; no = 0
Controller::genListOfValues( Node* node ) {
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genListOfValues - Node* is null!" );
  NodeList* valueList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isValue( unknown ) )
      valueList->add( unknown );
  } // n
  valueList->opt( ); // optimize memory
  return valueList;
} // Controller::genListOfValues

NodeList* /// all DOM::CData of Node* in NodeList* or empty nodeList; no = 0
Controller::genListOfCData( Node* node ) {
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::genListOfCData - Node* is null!" );
  NodeList* cDataList = new NodeList( 10 );
  int noOfNodes = node->getNoOfNodes( );
  for( int n = 0; n < noOfNodes; n++ ) {
    Node* unknown = node->getNode( n );
    if( isCData( unknown ) )
      cDataList->add( unknown );
  } // n
  cDataList->opt( ); // optimize memory
  return cDataList;
} // Controller::genListOfCData

/******************************************************************************/

StrList* // returns a StrList* all strings of DOM::Comment stored at Node*
Controller::genStrListOfComments( Node* node ) {
  StrList* strList = new StrList( 10 );
  NodeList* commentList = genListOfComments( node );
  int noOfComments = commentList->size( );
  for( int n = 0; n < noOfComments; n++ ) {
    Node* commentNode = commentList->get( n );
    strList->add( commentNode->getStr( ) );
  } // n
  delete commentList;
  strList->opt( );
  return strList;
} // Controller::genStrListOfComments

StrList* // returns a StrList* all strings of DOM::Element stored at Node*
Controller::genStrListOfElements( Node* node ) {
  StrList* strList = new StrList( 10 );
  NodeList* elementList = genListOfElements( node );
  int noOfElements = elementList->size( );
  for( int n = 0; n < noOfElements; n++ ) {
    Node* elementNode = elementList->get( n );
    strList->add( elementNode->getStr( ) );
  } // n
  delete elementList;
  strList->opt( );
  return strList;
} // Controller::genStrListOfElements

StrList* /// returns a list keeping values 4 for all set attributes
Controller::genStrListOfAttributes( Node* node ) {
  StrList* strList = new StrList( 10 );
  NodeList* attributeList = genListOfAttributes( node );
  int noOfValues = attributeList->size( );
  for( int n = 0; n < noOfValues; n++ ) {
    Node* attributeNode = attributeList->get( n );
    strList->add( attributeNode->getStr( ) );
  } // n
  delete attributeList;
  strList->opt( );
  return strList;
} // Controller::genStrListOfAttributes

StrList* // returns a StrList* all strings of DOM::Value stored at Node*
Controller::genStrListOfValues( Node* node ) {
  StrList* strList = new StrList( 10 );
  NodeList* valueList = genListOfValues( node );
  int noOfValues = valueList->size( );
  for( int n = 0; n < noOfValues; n++ ) {
    Node* valueNode = valueList->get( n );
    strList->add( valueNode->getStr( ) );
  } // n
  delete valueList;
  strList->opt( );
  return strList;
} // Controller::genStrListOfValues

StrList* // returns a StrList* all strings of DOM::CData stored at Node*
Controller::genStrListOfCData( Node* node ) {
  StrList* strList = new StrList( 10 );
  NodeList* cDataList = genListOfCData( node );
  int noOfCData = cDataList->size( );
  for( int n = 0; n < noOfCData; n++ ) {
    Node* cDataNode = cDataList->get( n );
    strList->add( cDataNode->getStr( ) );
  } // n
  delete cDataList;
  strList->opt( );
  return strList;
} // Controller::genStrListOfCData

/******************************************************************************/

Node* /// return first DOM::Header stored at Node* or a null pointer
Controller::getFirstHeader( Node* node ) {
  Node* header = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstHeader - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isHeader( unknown ) ) {
      isSearching = false;
      header = unknown;
    } // found
    n++;
  } // while searching
  return header;
} // Controller::getFirstHeader

Node* /// return first DOM::Doctype stored at Node* or a null pointer
Controller::getFirstDoctype( Node* node ) {
  Node* doctype = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstDoctype - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isDoctype( unknown ) ) {
      isSearching = false;
      doctype = unknown;
    } // found
    n++;
  } // while searching
  return doctype;
} // Controller::getFirstDoctype

Node* /// return first DOM::Comment stored at Node* or a null pointer
Controller::getFirstComment( Node* node ) {
  Node* comment = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstComment - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isComment( unknown ) ) {
      isSearching = false;
      comment = unknown;
    } // found
    n++;
  } // while searching
  return comment;
} // Controller::getFirstComment

Node* /// return first DOM::Element stored at Node* or a null pointer
Controller::getFirstElement( Node* node ) {
  Node* element = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstElement - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isElement( unknown ) ) {
      isSearching = false;
      element = unknown;
    } // found
    n++;
  } // while searching
  return element;
} // Controller::getFirstElement

Node* /// return first DOM::Attribute stored at Node* or a null pointer
Controller::getFirstAttribute( Node* node ) {
  Node* attribute = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstAttribute - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isAttribute( unknown ) ) {
      isSearching = false;
      attribute = unknown;
    } // found
    n++;
  } // while searching
  return attribute;
} // Controller::getFirstAttribute

Node* /// return first DOM::Value stored at Node* or a null pointer
Controller::getFirstValue( Node* node ) {
  Node* value = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstValue - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isValue( unknown ) ) {
      isSearching = false;
      value = unknown;
    } // found
    n++;
  } // while searching
  return value;
} // Controller::getFirstValue

Node* /// return first DOM::CData stored at Node* or a null pointer
Controller::getFirstCData( Node* node ) {
  Node* cData = 0;
  if( node == 0 )
    throw SYS::Failure( "DOM::Controller::getFirstCData - Node* is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfNodes = node->getNoOfNodes( );
  while( isSearching && ( n < noOfNodes ) ) {
    Node* unknown = node->getNode( n );
    if( isCData( unknown ) ) {
      isSearching = false;
      cData = unknown;
    } // found
    n++;
  } // while searching
  return cData;
} // Controller::getFirstCData

/**************************************************************************/

Str // returns string of FIRST DOM::Attribute stored at Node*
Controller::getStrOfFirstComment( Node* node ) {
  Str strComment = "";
  Node* comment = getFirstComment( node );
  if( comment == 0 )
    throw new SYS::Failure(
      "Controller::getStrOfFirstComment - no DOM::Comment stored" );
  strComment = comment->getStr( );
  return strComment;
} // Controller::getStrOfFirstComment

Str // returns string of FIRST DOM::Element stored at Node*
Controller::getStrOfFirstElement( Node* node ) {
  Str strElement = "";
  Node* element = getFirstElement( node );
  if( element == 0 )
    throw new SYS::Failure(
      "Controller::getStrOfFirstElement - no DOM::Element stored" );
  strElement = element->getStr( );
  return strElement;
} // Controller::getStrOfFirstElement

Str // returns string of FIRST DOM::Attribute stored at Node*
Controller::getStrOfFirstAttribute( Node* node ) {
  Str strAttribute = "";
  Node* attribute = getFirstAttribute( node );
  if( attribute == 0 )
    throw new SYS::Failure(
      "Controller::getStrOfFirstAttribute - no DOM::Attribute stored" );
  strAttribute = attribute->getStr( );
  return strAttribute;
} // Controller::getStrOfFirstAttribute

Str // returns string of FIRST DOM::Value stored at Node*
Controller::getStrOfFirstValue( Node* node ) {
  Str strValue = "";
  Node* valueNode = getFirstValue( node );
  if( valueNode == 0 )
    throw SYS::Failure(
      "Controller::getStrOfFirstValue - no DOM::Value stored" );
  strValue = valueNode->getStr( );
  return strValue;
} // Controller::getStrOfFirstValue

Str // returns string of FIRST DOM::CData stored at Node*
Controller::getStrOfFirstCData( Node* node ) {
  Str strCData = "";
  Node* cDataNode = getFirstCData( node );
  if( cDataNode == 0 )
    throw SYS::Failure(
      "Controller::getStrOfFirstCData - no DOM::Value stored" );
  strCData = cDataNode->getStr( );
  return strCData;
} // Controller::getStrOfFirstCData

/******************************************************************************/

Str // string of DOM::Value of first DOM::Attribute stored to Node*
Controller::getStrOfValueOfFirstAttribute( Node* node ) {
  Str strValue = "";
  Attribute* attributeNode = (Attribute*)( getFirstAttribute( node ) );
  strValue = attributeNode->getValue( );
  return strValue;
} // Controller::getStrOfValueAtFirstAttribute

Str // string of DOM::Value of selected DOM::Attribute stored to Node*
Controller::getStrOfValueOfAttribute( Node* node, Str strAttribute ) {
  Str strValue = "";
  NodeList* attributeList = genListOfAttributes( node );
  int noOfAttributes = attributeList->size( );
  int n = 0;
  bool isSearching = true;
  while( isSearching && ( n < noOfAttributes ) ) {
    Attribute* attributeNode = (Attribute*)( attributeList->get( n ) );
    Str nameAttributeNode = attributeNode->getName( );
    if( nameAttributeNode.compare( strAttribute ) == 0 ) {
      isSearching = false;
      strValue = attributeNode->getValue( );
    } // if found
    n++;
  } // while isSearching
  delete attributeList;
  if( isSearching == true ) // not found
    throw SYS::Failure(
      "Controller::getStrOfValueOfAttribute - DOM::Attribute not found!" );
  return strValue;
} // Controller::getStrOfValueOfAttribute

/******************************************************************************/

Node* // search CURRENT hierarchy; return Node* or null
Controller::search( Node* xml, Str tagName ) {
  Node* son = 0;
  if( xml == 0 )
    throw SYS::Failure( "DOM::Controller::search - given node is null!" );
  int n = 0;
  bool isSearching = true;
  int noOfSons = xml->getNoOfNodes( );
  while( isSearching && ( n < noOfSons ) ) {
    Node* current = xml->getNode( n );
    Str nameCurrent = _xmlTool.getTagName( current->getStr( ) );
    if( nameCurrent.compare( tagName ) == 0 ) {
      isSearching = false;
      son = current;
    } // if found
    n++;
  } // while isSearching
  return son;
} // Controller::search

Node* // TWO hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2 ) {
  return search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 );
} // Controller::search

Node* // THREE hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2,
    Str tagNameHierarchy3 ) {
  return search( search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 ),
    tagNameHierarchy3 );
}

Node* // FOUR hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2,
    Str tagNameHierarchy3, Str tagNameHierarchy4 ) {
  return search(
    search( search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 ),
      tagNameHierarchy3 ), tagNameHierarchy4 );
} // Controller::search

Node*  // FIVE hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2,
    Str tagNameHierarchy3, Str tagNameHierarchy4, Str tagNameHierarchy5 ) {
  return search(
    search(
      search( search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 ),
        tagNameHierarchy3 ), tagNameHierarchy4 ), tagNameHierarchy5 );
} // Controller::search

Node* // SIX hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2,
    Str tagNameHierarchy3, Str tagNameHierarchy4, Str tagNameHierarchy5,
    Str tagNameHierarchy6 ) {
  return search(
    search(
      search(
        search( search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 ),
          tagNameHierarchy3 ), tagNameHierarchy4 ), tagNameHierarchy5 ),
    tagNameHierarchy6 );
} // Controller::search

Node* // SEVEN hierarchies; not null
Controller::search( Node* xml, Str tagNameHierarchy1, Str tagNameHierarchy2,
    Str tagNameHierarchy3, Str tagNameHierarchy4, Str tagNameHierarchy5,
    Str tagNameHierarchy6, Str tagNameHierarchy7 ) {
  return search(
    search(
      search(
        search(
          search( search( search( xml, tagNameHierarchy1 ), tagNameHierarchy2 ),
            tagNameHierarchy3 ), tagNameHierarchy4 ), tagNameHierarchy5 ),
      tagNameHierarchy6 ), tagNameHierarchy7 );
} // Controller::search

/******************************************************************************/

void // print DOM tree to std::cout; without '\n'@end
Controller::view( Node* node ) {
  if( node == 0 )
    throw SYS::Error( "DOM::Controller::write - Node* is null!" );
  std::cout << node->getTag( ) << std::flush;
} // Controller::view

/******************************************************************************/

void // write XML file using file name in DOM::Root*
Controller::write( Root* root ) {
  if( root == 0 )
    throw SYS::Error( "DOM::Controller::write - Root* (Node*) is null!" );
  std::fstream file;
  file.open( (char*)root->getFileName( ).c_str( ), std::ios::out );
  // TODO throw SYS::Failure if file not open here
  file << root << std::endl << std::flush;
  file.close( );
} // Controller::write

void // write any XML structure to drive
Controller::write( Str fileName, Node* node ) {
  if( node == 0 )
    throw SYS::Error( "DOM::Controller::write - Node* is null!" );
  std::fstream file;
  file.open( (char*)fileName.c_str( ), std::ios::out );
  // TODO throw SYS::Failure if file not open here
  file << node << std::endl << std::flush;
  file.close( );
} // Controller::write

/******************************************************************************/

void // delete a given XML tag or DOM:: tree safely
Controller::erase( Node* node ) {
  if( node != 0 )
    delete node;
} // Controller::erase

/******************************************************************************/

bool // true if node is of type DOM::Root
Controller::isRoot( Node* node ) {
  if( dynamic_cast< Root* >( node ) != 0 )
    return true;
  return false;
} // Controller::isRoot

bool // true if node is of type Header
Controller::isHeader( Node* node ) {
  if( dynamic_cast< Header* >( node ) != 0 )
    return true;
  return false;
} // Controller::isHeader

bool // true if node is of type DOM::Doctype
Controller::isDoctype( Node* node ) {
  if( dynamic_cast< Doctype* >( node ) != 0 )
    return true;
  return false;
} // Controller::isDoctype

bool // return true if node is of type DOM::Comment
Controller::isComment( Node* node ) {
  if( dynamic_cast< Comment* >( node ) != 0 )
    return true;
  return false;
} // Controller::isComment

bool // true if node is of type DOM::Element
Controller::isElement( Node* node ) {
  if( dynamic_cast< Element* >( node ) != 0 )
    return true;
  return false;
} // Controller::isElement

bool // true if node is of type DOM::Attribute
Controller::isAttribute( Node* node ) {
  if( dynamic_cast< Attribute* >( node ) != 0 )
    return true;
  return false;
} // Controller::isAttribute

bool // return true if node is of type DOM::Value
Controller::isValue( Node* node ) {
  if( dynamic_cast< Value* >( node ) != 0 )
    return true;
  return false;
} // Controller::isValue

bool // true if node is of type DOM::CData
Controller::isCData( Node* node ) {
  if( dynamic_cast< CData* >( node ) != 0 )
    return true;
  return false;
} // Controller::isCData

/******************************************************************************/

} // namespace OBJ

} // namespace XMLCC

/******************************************************************************/
