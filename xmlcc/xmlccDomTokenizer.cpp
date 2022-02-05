/** 
 * @file xmlccDomTokenizer.cpp
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

#include "./xmlccDomTokenizer.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// constructor
Tokenizer::Tokenizer( void ) {
} // Tokenizer

/// destructor
Tokenizer::~Tokenizer( void ) {
} // ~Tokenizer

/******************************************************************************/

Node* /// build object model tree
Tokenizer::buildDomTreeOfTagList( TagList* tagList ) {

  if( tagList == 0 )
    throw SYS::Failure(
      "DOM::Tokenizer::buildDomTreeOfTagList - TagList* is null!" );

  Node* root = 0; // the root node; kept in mind
  Node* node = 0; // currently handled node
  Node* hierNode = 0; // remember the last hierarchy for call back
  NodeList* objectHierarchyList = 0; // switch back to the last hierarchies

  Tag xmlTag = ""; // currently handled XML tag

  int level = 0; // level of hierarchy; increased and decreased

  int noOfXmlTags = tagList->size( );
  if( !( noOfXmlTags > 0 ) )
    throw SYS::Failure( "XMLCC::DOM:Mapper - given XML tag list is empty" );

  objectHierarchyList = new NodeList( 12 ); // 12 levels is a lot

  root = (Node*)_controller.createRoot( ); // root node; represents XML file

  objectHierarchyList->add( root ); // at hierarchy 0; or index of smart array
  hierNode = objectHierarchyList->lst( ); // get last in list
//  level = objectHierarchyList->size( ); // 1 for header, comments, and main tag
//
//  if( level != 1 )
//    throw SYS::Error( "DOM::Mapper - something went internally wrong" );

  for( int t = 0; t < noOfXmlTags; t++ ) {

    Tag xmlTag = tagList->get( t ); // string keeping < .. > or > .. <

    bool isHeader = _xmlTool.check4Header( xmlTag );
    bool isComment = _xmlTool.check4Comment( xmlTag );
    bool isCData = _xmlTool.check4CData( xmlTag );
    bool isStandAloneTag = _xmlTool.check4StandAlone( xmlTag );
    bool isStartingTag = _xmlTool.check4Starting( xmlTag );
    bool isEndingTag = _xmlTool.check4Ending( xmlTag );
    bool isTxt = _xmlTool.check4Text( xmlTag );

    if( isHeader ) { // create header node

      Header* header = (Header*)convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // get last in list
      hierNode->addNode( header );

    } // XML tag is header of file

    if( isComment ) { // create comment node

      node = convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // get last in list
      hierNode->addNode( node );

    } // is starting tag

    if( isCData ) { // create CDATA node

      node = convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // get last in list
      hierNode->addNode( node );

    } // is starting tag

    if( isStandAloneTag ) { // create standalone tag

      node = convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // get last in list
      hierNode->addNode( node );

    } // is standalone tag

    if( isStartingTag ) { // create new node an increase hierarchy

      node = convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // getting last
      hierNode->addNode( node ); // build the tree
      hierNode = node; // an XML tag is a possible new hierarchy
      level++; // up one level

      int levelOfObjHierList = objectHierarchyList->size( );
      if( levelOfObjHierList <= level )
        objectHierarchyList->add( hierNode ); // add to list
      else
        objectHierarchyList->set( level, hierNode ); // set to list

    } // is starting tag

    if( isEndingTag ) {

      level--; // one level down in hierarchy

    } // is ending tag

    if( isTxt ) {

      node = convert( xmlTag );
      hierNode = objectHierarchyList->get( level ); // getting last
      hierNode->addNode( node );

    } // is text content

  } // no of XML tags in xmlList

  delete objectHierarchyList;

  return root;

} // Tokenizer::buildDomTreeOfTagList

/******************************************************************************/

Node*  /// convert XML tag or text 2 objects
Tokenizer::convert( Str tag ) {

  Node* node = 0;

  if( _xmlTool.check4Tag( tag ) )
    node = convertTagComplete( tag );
  else
    node = convertValue( tag );

  return node;

} // Tokenizer::convert

/******************************************************************************/

Node*  // convert a tag 2 node
Tokenizer::convertTag( Str tag ) {

  Node* node = 0;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  node = convert2Node( tag );

  return node;

} // Parser::convertTag

Node*  // convert a tag 2 node
Tokenizer::convertTagComplete( Str tag ) {

  Node* node = 0;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  node = convert2NodeComplete( tag );

  return node;

} // Parser::convertTagComplete

Node* // convert a val 2 node
Tokenizer::convertValue( Str value ) {

  Node* node = 0;

  value = _strTool.trimS( value );
  value = _strTool.filterWs( value );

  node = conv2Val( value );

  return node;

} // Parser::convertValue

/******************************************************************************/

bool /// check if tag is ending
Tokenizer::check4Ending( Str tag ) {

  bool isTagEnding = false;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  if( tag.length( ) > 0 ) {

    char m = tag[ 0 ];

    if( m == '/' )
      isTagEnding = true;
    else
      isTagEnding = false;

  } else
    throw SYS::Failure( "Tokenizer::check4TagEnding - no tag given; no chars" );

  return isTagEnding;

} // Tokenizer::check4TagEnding

bool /// check if tag is standalone
Tokenizer::check4StandAlone( Str tag ) {

  bool isTagStandAlone = false;

  tag = _strTool.trimS( tag );
  tag = _strTool.filterWs( tag );

  size_t tagLength = tag.length( );

  if( tagLength > 0 ) {

    char m = tag[ tagLength - 1 ];

    if( m == '/' )
      isTagStandAlone = true;
    else
      isTagStandAlone = false;

  } else
    throw SYS::Failure(
      "Tokenizer::check4TagStandAlone - no tag given; no chars" );

  return isTagStandAlone;

} // Tokenizer::check4TagStandAlone

/******************************************************************************/

Node* /// filter a string and hand back objects
Tokenizer::convert2Node( Str line ) {

  Node* node = 0;

  size_t length = line.size( );

  if( length < 1 )
    throw SYS::Failure( "Tokenizer::convert2Node - line has no char" );

  char m = line[ 0 ];

  if( m == '!' ) {  // check for comment

    if( length > 5 ) { // !---- has minimum of 5

      char s0 = line[ 0 ];
      char s1 = line[ 1 ];
      char s2 = line[ 2 ];

      if( ( s0 == '!' ) && ( s1 == '-' ) && ( s2 == '-' ) ) { // comment

        char e0 = line[ length - 1 ];
        char e1 = line[ length - 2 ];

        if( ( e1 == '-' ) && ( e0 == '-' ) ) { // found comment
          return conv2Comment( line );
        } // if --

      } // if !--

    } // if 5

  } // if !

  if( m == '?' ) { // check for a header

    char s0 = line[ 0 ];

    if( s0 == '?' ) {

      char e0 = line[ length - 1 ];

      if( e0 == '?' ) {
        return conv2Header( line );
      } // if ?

    } // if ?
  } // if ?  

  if( ( m != '!' ) && ( m != '?' ) ) { // check for a ending tag 

    char s0 = line[ 0 ];

    if( s0 == '/' ) {

      char e0 = line[ length - 1 ];

      if( e0 != '/' ) { // have to be

        Str tag = line.substr( 1, ( length - ( 1 ) ) );
        node = conv2Tag( tag );

        return node; // return zero

      } else { // useless else here
        throw SYS::Error(
          "Tokenizer::convert2Node - tag is malformed like </text/>" );
      } // if tag / ... /

    } // if ?
  } // if ?  

  // check for a tag starting
  if( ( m != '/' ) && ( m != '!' ) && ( m != '?' ) )
    return conv2Tag( line );

  return node;

} // Tokenizer::convert2Node

/******************************************************************************/

Node* /// filter a string and hand back objects
Tokenizer::convert2NodeComplete( Str line ) {

  Node* node = 0;

  size_t length = line.size( );

  if( length < 1 )
    throw SYS::Failure( "Tokenizer::convert2NodeComplete - line has no char" );

  char a = line[ 0 ];

  if( a != '<' )
    throw SYS::Failure(
      "Tokenizer::convert2NodeComplete - line has no starting <" );

  char e = line[ length - 1 ];

  if( e != '>' )
    throw SYS::Failure(
      "Tokenizer::convert2NodeComplete - line has no ending >" );

  line = line.substr( 1, ( length - ( 1 + 1 ) ) ); // without < .. >
  length = line.size( );

  char m = line[ 0 ]; // the first after '<'

  if( m == '!' ) {  // check for comment

    if( length > 5 ) { // <!----> has minimum of 7 -> 3 for beginning

      char s0 = line[ 0 ];
      char s1 = line[ 1 ];
      char s2 = line[ 2 ];

      if( ( s0 == '!' ) && ( s1 == '-' ) && ( s2 == '-' ) ) { // comment

        char e0 = line[ length - 1 ]; // -
        char e1 = line[ length - 2 ]; // --

        if( ( e1 == '-' ) && ( e0 == '-' ) ) { // found <!---->
          return conv2Comment( line );
        } // if --

      } // if !--

      if( ( s0 == '!' ) && ( s1 == '[' ) && ( s2 == 'C' ) ) { // ![C -> DATA[

        if( length > 10 ) {

          char s3 = line[ 3 ]; // D
          char s4 = line[ 4 ]; // A
          char s5 = line[ 5 ]; // T
          char s6 = line[ 6 ]; // A
          char s7 = line[ 7 ]; // [

          if( ( s3 == 'D' ) && ( s4 == 'A' ) && ( s5 == 'T' ) && ( s6 == 'A' )
              && ( s7 == '[' ) ) {

            char e0 = line[ length - 1 ]; // ]
            char e1 = line[ length - 2 ]; // ]]

            if( ( e1 == ']' ) && ( e0 == ']' ) ) { // found comment

              return conv2CData( line );

            } // if "]]"

          } // if "DATA["

        } // if length > 10

      } // if "![C"

      if( ( s0 == '!' ) && ( s1 == 'D' || s1 == 'd' )
          && ( s2 == 'O' || s2 == 'o' ) ) { // !DO

        if( length > 10 ) {

          char s3 = line[ 3 ]; // C
          char s4 = line[ 4 ]; // T
          char s5 = line[ 5 ]; // Y
          char s6 = line[ 6 ]; // P
          char s7 = line[ 7 ]; // E

          if( ( s3 == 'C' || s3 == 'c' ) && ( s4 == 'T' || s4 == 't' )
              && ( s5 == 'Y' || s5 == 'y' ) && ( s6 == 'P' || s6 == 'p' )
              && ( s7 == 'E' || s7 == 'e' ) ) {

            return conv2Doctype( line );

          } // if "CTYPE"

        } // if length > 10

      } // if "!DO"

    } // if 5

  } // if !

  if( m == '?' ) { // check for a header

    char s0 = line[ 0 ];

    if( s0 == '?' ) {

      char e0 = line[ length - 1 ];

      if( e0 == '?' ) {
        return conv2Header( line );
      } // if ?

    } // if ?
  } // if ?  

  if( ( m != '!' ) && ( m != '?' ) ) { // check for a ending tag 

    char s0 = line[ 0 ];

    if( s0 == '/' ) {

      char e0 = line[ length - 1 ];

      if( e0 != '/' ) { // have to be

        Str tag = line.substr( 1, ( length - ( 1 + 1 ) ) );
        node = conv2Tag( tag );

        return node; // return zero

      } else { // useless else here
        throw SYS::Error(
          "Tokenizer::convert2NodeComplete - tag is malformed like </text/>" );
      } // if tag / ... /

    } // if ?
  } // if ?  

  // check for a tag starting
  if( ( m != '/' ) && ( m != '!' ) && ( m != '?' ) )
    return conv2Tag( line );

  return node;

} // Tokenizer::convert2NodeComplete

/******************************************************************************/

Node* /// convert a known header string to an node
Tokenizer::conv2Header( Str line ) {

  Node* node = 0;

  line = line.substr( 1, ( line.length( ) - ( 1 + 1 ) ) );
  line = _strTool.trimS( line );

  Str tag = getTag( line ); // search for tag first

  node = new Header( tag );
  NodeList* objList = convAttAndValList( line );

  for( int o = 0; o < objList->size( ); o++ )
    node->addNode( objList->get( o ) );

  delete objList;

  return node;

} // Tokenizer::convert2Tag

/******************************************************************************/

Node* /// convert a known comment string to an node
Tokenizer::conv2Comment( Str line ) {

  Node* node = 0;

  line = line.substr( 3, ( line.length( ) - ( 3 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  node = new Comment( line );

  return node;

} // Tokenizer::convert2Comment;

/******************************************************************************/

Node* /// convert CDATA to an node
Tokenizer::conv2CData( Str line ) {

  Node* node = 0;

  // <![CDATA[ ... ]]>
  line = line.substr( 8, ( line.length( ) - ( 8 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  node = new CData( line );

  return node;

} // Tokenizer::convert2Comment;

/******************************************************************************/

Node* /// convert DOCTYPE to an node
Tokenizer::conv2Doctype( Str line ) {

  Node* node = 0;

  // <!DOCTYPE >
  line = line.substr( 8, ( line.length( ) - ( 8 + 2 ) ) );
  line = _strTool.trimS( line );
  line = _strTool.filterWs( line );

  // TODO: filter DOCTYPE to white spaces and quotes

  node = new Doctype( );

  return node;

} // Tokenizer::convert2Comment;

/******************************************************************************/

Node* /// convert a known starting tag string to an node
Tokenizer::conv2Tag( Str line ) {

  Node* node = 0;

  char e0 = line[ line.length( ) - ( 1 ) ];

  if( e0 == '/' ) // standalone tag
    line = line.substr( 0, line.length( ) - ( 1 ) );
  else if( e0 != '/' ) // normal tag
    line = line.substr( 0, line.length( ) - ( 0 ) );
  else
    // useless else here
    throw SYS::Failure( "Tokenizer::conv2Tag - tag is not of chars" );

  line = _strTool.trimS( line );

  Str tag = getTag( line ); // search for tag first

  node = new Element( tag );

  NodeList* objList = convAttAndValList( line );

  for( int o = 0; o < objList->size( ); o++ )
    node->addNode( objList->get( o ) );

  delete objList;

  return node;

} // Tokenizer::convert2Tag

/******************************************************************************/

NodeList* /// get Str with strings as: att="val"
Tokenizer::convAttAndValList( Str line ) {

  StrList* strList = new StrList( 10 );

  bool firstWhiteSpace = false;
  bool firstExclamationMark = false;

  Str str; // define here for collecting chars in foor loop

  for( Str::iterator i = line.begin( ); i != line.end( ); i++ ) {

    char c = *i; // actual char

    if( firstWhiteSpace ) {

      if( c != ' ' )
        str += c;

      if( firstExclamationMark ) {

        if( c == ' ' )
          str += c; // now add whiteys

        if( ( c == '"' ) || ( i == ( line.end( ) - ( 1 ) ) ) ) {

          strList->add( str );

          str.clear( );

        } // "

      } // if

      if( c == '"' ) {

        if( !firstExclamationMark ) {
          firstExclamationMark = true;
        } else
          firstExclamationMark = false;
        {
        } // first

      } // "
    } // if not first white (after tag)

    if( !firstWhiteSpace && c == ' ' )
      firstWhiteSpace = true;

  } // for i

  NodeList* nodeList = new NodeList( 5 );

  for( int s = 0; s < strList->size( ); s++ ) {

    Str str = strList->get( s );

    Node* attribute = conv2AttAndVal( str );

    if( attribute != 0 )
      nodeList->add( attribute );

  } // for s

  delete strList;

  return nodeList;

} // Tokenizer::getAttAndValList

/******************************************************************************/

Node* /// convert a string to attribute and value node
Tokenizer::conv2AttAndVal( Str line ) {

  Node* node = 0;

  line = _strTool.trimS( line );

  Str str; // define here for collecting chars in foor loop

  StrList* strList = new StrList( 10 );

  for( Str::iterator i = line.begin( ); i != line.end( ); i++ ) {

    char c = *i; // actual char

    if( ( c != '=' ) && ( c != '"' ) )
      str += c;

    if( c == '"' ) {

      str = _strTool.trimS( str );
      str = _strTool.filterWs( str );

      strList->add( str );

      str.clear( );

    } // if

  } // for i

  int strListSize = strList->size( );

  if( strListSize == 2 ) {

    Str attributeStr = strList->get( 0 );
    Str valueStr = strList->get( 1 );

    node = new Attribute( attributeStr, valueStr );

  } else
    throw SYS::Error(
      "Tokenizer::conv2AttAndVal - attribute has no correct XML syntax" );

  delete strList;

  return node;

} // Tokenizer::convert2AttributeAndValue

/******************************************************************************/

Node* /// convert a known value string to an node
Tokenizer::conv2Val( Str line ) {

  Node* node = 0;

  Str str = _strTool.trimS( line );

  if( str.length( ) < 1 )
    return node;

  node = new Value( str );

  return node;

} // Tokenizer::convert2Value

/******************************************************************************/

Str // hand the tag back as string
Tokenizer::getTag( Str line ) {

  // search for tag first
  Str tag;

  size_t posOfFirstWhite = 0;
  size_t lineLength = line.length( );

  bool isFound = false;

  while( !isFound ) {

    char t = line[ posOfFirstWhite ];

    if( t != ' ' )
      tag += t;

    if( t == ' ' )
      isFound = true;

    if( posOfFirstWhite >= ( lineLength - ( 1 ) ) )
      isFound = true;

    posOfFirstWhite++;

  } // while

  return tag;

} // Tokenizer::getTag

/******************************************************************************/

} // namespace DOM 

} // namespace XMLCC

/******************************************************************************/
