/** 
 * @file xmlccTestDomController.cpp
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

#include "xmlccTestDomController.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
Controller::Controller( std::string name ) {

  _name = name;

} // Controller

/// destructor
Controller::~Controller( void ) {

} // ~Controller

/******************************************************************************/

void // inherit method for all unit tests using assert methods
Controller::run( void ) {

  DOM::Controller controller; // object of class to be tested

  SYS::XmlTool xmlTool; // tested in another unit case
  SYS::StrTool strTool; // tested in another unit case

  // generating XML unit test structure
  DOM::Root* xml = new DOM::Root( "xmlccTest.xml",
    new DOM::Header( new DOM::Attribute( "version", "1.0" ) ),
    new DOM::Comment( "XMLCC 1.00 20150101 Amara Faith" ),
    new DOM::Element( "main",
      new DOM::Comment( "unit test cases for class DOM::Controller" ),
      new DOM::Element( "sub1", new DOM::Comment( "sub element no 1" ),
        new DOM::Element( "element11", new DOM::Value( "true" ) ),
        new DOM::Element( "element12", new DOM::Value( "false" ) ) ),
      new DOM::Element( "sub2", new DOM::Comment( "sub element no 2" ),
        new DOM::Element( "standalone21",
          new DOM::Attribute( "switch", "true" ) ),
        new DOM::Element( "standalone22",
          new DOM::Attribute( "switch", "false" ) ) ),
      new DOM::Element( "sub3", new DOM::Comment( "sub element no 3" ),
        new DOM::Element( "standalone31",
          new DOM::Attribute( "switch311", "true" ),
          new DOM::Attribute( "switch312", "true" ),
          new DOM::Attribute( "switch313", "true" ) ),
        new DOM::Element( "standalone32",
          new DOM::Attribute( "switch321", "false" ),
          new DOM::Attribute( "switch322", "false" ),
          new DOM::Attribute( "switch323", "false" ) ) ),
      new DOM::Element( "sub4", new DOM::Comment( "sub element no 4" ),
        new DOM::Element( "element41", "true" ),
        new DOM::Element( "standalone42",
          new DOM::Attribute( "switch", "false" ) ),
        new DOM::Element( "element43", "true" ),
        new DOM::Element( "standalone44",
          new DOM::Attribute( "switch", "false" ) ),
        new DOM::Element( "element45", new DOM::Attribute( "switch", "true" ),
          new DOM::Value( "true" ) ),
        new DOM::Element( "element46", new DOM::Attribute( "switch", "false" ),
          new DOM::Value( "false" ) ) ),
      new DOM::CData( "abcdefghijklmnopqrstuvwxyz" ) ) );

  std::fstream file; // open file
  file.open( ( (char*)( xml->getStr( ).c_str( ) ) ), std::ios::out );
  file << xml; // DOM:: 2 std::fstream - writing to drive
  file.close( );

  // generated structure looks like ..
  //  <?xml version="1.0"?>
  //  <!--XMLCC 1.00 20150101 Amara Faith-->
  //  <main>
  //    <!--unit test cases for class DOM::Controller-->
  //    <sub1>
  //      <!--sub element no 1-->
  //      <element11>true</element11>
  //      <element12>false</element12>
  //    </sub1>
  //    <sub2>
  //      <!--sub element no 2-->
  //      <standalone21 switch="true"/>
  //      <standalone22 switch="false"/>
  //    </sub2>
  //    <sub3>
  //      <!--sub element no 3-->
  //      <standalone31 switch311="true" switch312="true" switch313="true"/>
  //      <standalone32 switch321="false" switch322="false" switch323="false"/>
  //    </sub3>
  //    <sub4>
  //      <!--sub element no 4-->
  //      <element41>true</element41>
  //      <standalone42 switch="false"/>
  //      <element43>true</element43>
  //      <standalone44 switch="false"/>
  //      <element45 switch="true">true</element45>
  //      <element46 switch="false">false</element46>
  //    </sub4>
  //    <![CDATA[abcdefghijklmnopqrstuvwxyz]]>
  //  </main>

  // test isRoot() method
  DOM::Root* root = xml;
  assertFalse( controller.isRoot( root ) );
  assertTrue( controller.isHeader( root ) );
  assertTrue( controller.isDoctype( root ) );
  assertTrue( controller.isComment( root ) );
  assertTrue( controller.isElement( root ) );
  assertTrue( controller.isAttribute( root ) );
  assertTrue( controller.isValue( root ) );
  assertTrue( controller.isCData( root ) );

  // test getFirstHeader() & isHeader() methods
  DOM::Node* header = controller.getFirstHeader( root ); // throws itself
  assertTrue( controller.isRoot( header ) );
  assertFalse( controller.isHeader( header ) );
  assertTrue( controller.isDoctype( header ) );
  assertTrue( controller.isComment( header ) );
  assertTrue( controller.isElement( header ) );
  assertTrue( controller.isAttribute( header ) );
  assertTrue( controller.isValue( header ) );
  assertTrue( controller.isCData( header ) );

  // test getFirstComment() & isComment() methods
  DOM::Node* commentXMLCC = controller.getFirstComment( root ); // throws itself
  assertTrue( controller.isRoot( commentXMLCC ) );
  assertTrue( controller.isHeader( commentXMLCC ) );
  assertTrue( controller.isDoctype( commentXMLCC ) );
  assertFalse( controller.isComment( commentXMLCC ) );
  assertTrue( controller.isElement( commentXMLCC ) );
  assertTrue( controller.isAttribute( commentXMLCC ) );
  assertTrue( controller.isValue( commentXMLCC ) );
  assertTrue( controller.isCData( commentXMLCC ) );

  // test getFirstElement( ) & isElement() methods
  DOM::Node* main = controller.getFirstElement( root ); // throws itself
  assertTrue( controller.isRoot( main ) );
  assertTrue( controller.isHeader( main ) );
  assertTrue( controller.isDoctype( main ) );
  assertTrue( controller.isComment( main ) );
  assertFalse( controller.isElement( main ) );
  assertTrue( controller.isAttribute( main ) );
  assertTrue( controller.isValue( main ) );
  assertTrue( controller.isCData( main ) );

  // test getFirstCData( ) & isCData() methods
  DOM::Node* cData = controller.getFirstCData( main ); // throws itself
  assertTrue( controller.isRoot( cData ) );
  assertTrue( controller.isHeader( cData ) );
  assertTrue( controller.isDoctype( cData ) );
  assertTrue( controller.isComment( cData ) );
  assertTrue( controller.isElement( cData ) );
  assertTrue( controller.isAttribute( cData ) );
  assertTrue( controller.isValue( cData ) );
  assertFalse( controller.isCData( cData ) );

  // test genListOfElements & getElement methods
  //  <main>
  //    <!--unit test cases for class DOM::Controller-->
  //    <sub1>
  //      ..
  //    </sub1>
  //    <sub2>
  //      ..
  //    </sub2>
  //    <sub3>
  //      ..
  //    </sub3>
  //    <sub4>
  //      ..
  //    </sub4>
  //    <![CDATA[abcdefghijklmnopqrstuvwxyz]]>
  //  </main>

  DOM::NodeList* subOfMainList = controller.genListOfElements( main );
  int noOfSubOfMain = subOfMainList->size( );
  _actualInt = noOfSubOfMain; // sub1, sub2, sub3, and sub4 => 4
  _expectedInt = 4;
  assertEquals( _expectedInt, _actualInt );
  for( int n = 0; n < noOfSubOfMain; n++ ) {
    DOM::Node* sub = subOfMainList->get( n );
    assertNull( sub );
    _expectedStr = "sub";
    _expectedStr.append( strTool.doI2S( n + 1 ) ); // sub1, sub2, ..
    _actualStr = sub->getStr( );
    assertEquals( _expectedStr, _actualStr );
  } // n

  _expectedStr = "sub1"; // <sub1>
  DOM::Node* sub1 = controller.getElement( main, _expectedStr );
  _actualStr = sub1->getStr( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "sub2"; // <sub2>
  DOM::Node* sub2 = controller.getElement( main, _expectedStr );
  _actualStr = sub2->getStr( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "sub3"; // <sub3>
  DOM::Node* sub3 = controller.getElement( main, _expectedStr );
  _actualStr = sub3->getStr( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "sub4"; // <sub4>
  DOM::Node* sub4 = controller.getElement( main, _expectedStr );
  _actualStr = sub4->getStr( );
  assertEquals( _expectedStr, _actualStr );

  // test getElement( ) & getFirstValue( ) methods
  //    <sub1>
  //      <!--sub element no 1-->
  //      <element11>true</element11>
  //      <element12>false</element12>
  //    </sub1>

  _expectedStr = "element11"; // <element11>true</element11>
  DOM::Node* element11 = controller.getElement( sub1, _expectedStr );
  _actualStr = element11->getStr( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* value11 = controller.getFirstValue( element11 );
  _expectedStr = "true";
  _actualStr = value11->getStr( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "element12"; // <element12>false</element12>
  DOM::Node* element12 = controller.getElement( sub1, _expectedStr );
  _actualStr = element12->getStr( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* value12 = controller.getFirstValue( element12 );
  _expectedStr = "false";
  _actualStr = value12->getStr( );
  assertEquals( _expectedStr, _actualStr );

  // test getElement & getFirstAttribute( ) methods
  //    <sub2>
  //      <!--sub element no 2-->
  //      <standalone21 switch="true"/>
  //      <standalone22 switch="false"/>
  //    </sub2>

  _expectedStr = "standalone21"; // <standalone21 switch="true"/>
  DOM::Node* standalone21 = controller.getElement( sub2, _expectedStr );
  _actualStr = standalone21->getStr( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute21 = controller.getFirstAttribute( standalone21 );
  _expectedStr = "switch";
  _actualStr = ( (DOM::Attribute*)( attribute21 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "true";
  _actualStr = ( (DOM::Attribute*)( attribute21 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "standalone22"; // <standalone22 switch="false"/>
  DOM::Node* standalone22 = controller.getElement( sub2, _expectedStr );
  _actualStr = standalone22->getStr( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute22 = controller.getFirstAttribute( standalone22 );
  _expectedStr = "switch";
  _actualStr = ( (DOM::Attribute*)( attribute22 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "false";
  _actualStr = ( (DOM::Attribute*)( attribute22 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );

  // test genListOfAttributes & genStrListOfAttributes & getFirstAttribute &
  // getAttribute & getStrOfValueOfFirstAttribute & getStrOfValueOfAttribute
  // methods
  //    <sub3>
  //      <!--sub element no 3-->
  //      <standalone31 switch311="true" switch312="true" switch313="true"/>
  //      <standalone32 switch321="false" switch322="false" switch323="false"/>
  //    </sub3>

  // <standalone31 switch311="true" switch312="true" switch313="true"/>
  _expectedStr = "standalone31";
  DOM::Node* standalone31 = controller.getElement( sub3, _expectedStr );
  _actualStr = standalone31->getStr( );
  assertEquals( _expectedStr, _actualStr );

  // <standalone31 switch311="true" switch312="true" switch313="true"/>
  DOM::Node* attribute311 = controller.getFirstAttribute( standalone31 );
  _expectedStr = "switch311";
  _actualStr = ( (DOM::Attribute*)( attribute311 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "true";
  _actualStr = ( (DOM::Attribute*)( attribute311 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute312 = controller.getAttribute( standalone31,
    "switch312" );
  _expectedStr = "switch312";
  _actualStr = ( (DOM::Attribute*)( attribute312 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "true";
  _actualStr = ( (DOM::Attribute*)( attribute312 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute313 = controller.getAttribute( standalone31,
    "switch313" );
  _expectedStr = "switch313";
  _actualStr = ( (DOM::Attribute*)( attribute313 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "true";
  _actualStr = ( (DOM::Attribute*)( attribute313 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );

  // <standalone31 switch311="true" switch312="true" switch313="true"/>
  DOM::NodeList* attribute31List = controller.genListOfAttributes(
    standalone31 );
  int noOfAttributesOfStandalone31 = attribute31List->size( );
  _actualInt = noOfAttributesOfStandalone31; // switch311, switch312, switch313
  _expectedInt = 3;
  assertEquals( _expectedInt, _actualInt );
  for( int n = 0; n < noOfAttributesOfStandalone31; n++ ) {
    DOM::Node* attribute = attribute31List->get( n );
    assertNull( attribute );
    _expectedStr = "switch31";
    _expectedStr.append( strTool.doI2S( n + 1 ) ); // switch311, switch312, ..
    _actualStr = ( (DOM::Attribute*)( attribute ) )->getName( );
    assertEquals( _expectedStr, _actualStr ); // attribute names
  } // n
  for( int n = 0; n < noOfAttributesOfStandalone31; n++ ) {
    DOM::Node* attribute = attribute31List->get( n );
    assertNull( attribute );
    _expectedStr = "true"; // three times ..
    _actualStr = ( (DOM::Attribute*)( attribute ) )->getValue( );
    assertEquals( _expectedStr, _actualStr ); // attribute values
  } // n
  StrList* attribute31StrList = controller.genStrListOfAttributes(
    standalone31 );
  int noOfStrAttributesOfStandalone31 = attribute31StrList->size( );
  _actualInt = noOfStrAttributesOfStandalone31; // switch311, switch312, switch313
  _expectedInt = 3;
  assertEquals( _expectedInt, _actualInt );
  for( int s = 0; s < noOfStrAttributesOfStandalone31; s++ ) {
    _expectedStr = "switch31";
    _expectedStr.append( strTool.doI2S( s + 1 ) ); // switch311, switch312, ..
    _actualStr = attribute31StrList->get( s );
    assertEquals( _expectedStr, _actualStr ); // attribute names
  } // s

  // <standalone32 switch321="false" switch322="false" switch323="false"/>
  _expectedStr = "standalone32";
  DOM::Node* standalone32 = controller.getElement( sub3, _expectedStr );
  _actualStr = standalone32->getStr( );
  assertEquals( _expectedStr, _actualStr );

  // <standalone32 switch321="false" switch322="false" switch323="false"/>
  DOM::Node* attribute321 = controller.getFirstAttribute( standalone32 );
  _expectedStr = "switch321";
  _actualStr = ( (DOM::Attribute*)( attribute321 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "false";
  _actualStr = ( (DOM::Attribute*)( attribute321 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute322 = controller.getAttribute( standalone32,
    "switch322" );
  _expectedStr = "switch322";
  _actualStr = ( (DOM::Attribute*)( attribute322 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "false";
  _actualStr = ( (DOM::Attribute*)( attribute322 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );
  DOM::Node* attribute323 = controller.getAttribute( standalone32,
    "switch323" );
  _expectedStr = "switch323";
  _actualStr = ( (DOM::Attribute*)( attribute323 ) )->getName( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "false";
  _actualStr = ( (DOM::Attribute*)( attribute323 ) )->getValue( );
  assertEquals( _expectedStr, _actualStr );

  // <standalone32 switch321="false" switch322="false" switch323="false"/>
  DOM::NodeList* attribute32List = controller.genListOfAttributes(
    standalone32 );
  int noOfAttributesOfStandalone32 = attribute32List->size( );
  _actualInt = noOfAttributesOfStandalone32; // switch321, switch322, switch323
  _expectedInt = 3;
  assertEquals( _expectedInt, _actualInt );
  for( int n = 0; n < noOfAttributesOfStandalone32; n++ ) {
    DOM::Node* attribute = attribute32List->get( n );
    assertNull( attribute );
    _expectedStr = "switch32";
    _expectedStr.append( strTool.doI2S( n + 1 ) ); // switch321, switch322, ..
    _actualStr = ( (DOM::Attribute*)( attribute ) )->getName( );
    assertEquals( _expectedStr, _actualStr ); // attribute names
  } // n
  for( int n = 0; n < noOfAttributesOfStandalone32; n++ ) {
    DOM::Node* attribute = attribute32List->get( n );
    assertNull( attribute );
    _expectedStr = "false"; // three times ..
    _actualStr = ( (DOM::Attribute*)( attribute ) )->getValue( );
    assertEquals( _expectedStr, _actualStr ); // attribute values
  } // n
  StrList* attribute32StrList = controller.genStrListOfAttributes(
    standalone32 );
  int noOfStrAttributesOfStandalone32 = attribute32StrList->size( );
  _actualInt = noOfStrAttributesOfStandalone32; // switch321, switch322, switch323
  _expectedInt = 3;
  assertEquals( _expectedInt, _actualInt );
  for( int s = 0; s < noOfStrAttributesOfStandalone32; s++ ) {
    _expectedStr = "switch32";
    _expectedStr.append( strTool.doI2S( s + 1 ) ); // switch321, switch322, ..
    _actualStr = attribute32StrList->get( s );
    assertEquals( _expectedStr, _actualStr ); // attribute names
  } // s

  // <standalone31 switch311="true" switch312="true" switch313="true"/>
  _expectedStr = "true";
  _actualStr = controller.getStrOfValueOfFirstAttribute( standalone31 );
  assertEquals( _expectedStr, _actualStr ); // attribute values
  _expectedStr = "true";
  _actualStr = controller.getStrOfValueOfAttribute( standalone31, "switch312" );
  assertEquals( _expectedStr, _actualStr ); // attribute values
  _expectedStr = "true";
  _actualStr = controller.getStrOfValueOfAttribute( standalone31, "switch313" );
  assertEquals( _expectedStr, _actualStr ); // attribute values

  // <standalone32 switch321="false" switch322="false" switch323="false"/>
  _expectedStr = "false";
  _actualStr = controller.getStrOfValueOfFirstAttribute( standalone32 );
  assertEquals( _expectedStr, _actualStr ); // attribute values
  _expectedStr = "false";
  _actualStr = controller.getStrOfValueOfAttribute( standalone32, "switch322" );
  assertEquals( _expectedStr, _actualStr ); // attribute values
  _expectedStr = "false";
  _actualStr = controller.getStrOfValueOfAttribute( standalone32, "switch323" );
  assertEquals( _expectedStr, _actualStr ); // attribute values

  // test genListOfElements() & getElement() & genStrListOfElements( ) methods
  //    <sub4>
  //      <!--sub element no 4-->
  //      <element41>true</element41>
  //      <standalone42 switch="false"/>
  //      <element43>true</element43>
  //      <standalone44 switch="false"/>
  //      <element45 switch="true">true</element45>
  //      <element46 switch="false">false</element46>
  //    </sub4>

  DOM::NodeList* elementsOfSub4List = controller.genListOfElements( sub4 );
  int noOfElementsOfSub4 = elementsOfSub4List->size( );
  _actualInt = noOfElementsOfSub4;
  _expectedInt = 6; // element41, standalone42, element43, .. => 6
  assertEquals( _expectedInt, _actualInt );
  for( int n = 0; n < noOfElementsOfSub4; n++ ) {
    DOM::Node* sub = elementsOfSub4List->get( n );
    assertNull( sub );
    _actualStr = sub->getStr( );
    if( n == 0 )
      _expectedStr = "element41";
    if( n == 1 )
      _expectedStr = "standalone42";
    if( n == 2 )
      _expectedStr = "element43";
    if( n == 3 )
      _expectedStr = "standalone44";
    if( n == 4 )
      _expectedStr = "element45";
    if( n == 5 )
      _expectedStr = "element46";
    assertEquals( _expectedStr, _actualStr );
  } // n

  _expectedStr = "element41"; // <element41>true</element41>
  DOM::Node* element41 = controller.getElement( sub4, _expectedStr );
  _actualStr = element41->getStr( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "standalone42"; // <standalone42 switch="false"/>
  DOM::Node* standalone42 = controller.getElement( sub4, _expectedStr );
  _actualStr = standalone42->getStr( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "element43"; // <element43>true</element43>
  DOM::Node* element43 = controller.getElement( sub4, _expectedStr );
  _actualStr = element43->getStr( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "standalone44"; // <standalone44 switch="false"/>
  DOM::Node* standalone44 = controller.getElement( sub4, _expectedStr );
  _actualStr = standalone44->getStr( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "element45"; // <element41>true</element41>
  DOM::Node* element45 = controller.getElement( sub4, _expectedStr );
  _actualStr = element45->getStr( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "element46"; // <element41>true</element41>
  DOM::Node* element46 = controller.getElement( sub4, _expectedStr );
  _actualStr = element46->getStr( );
  assertEquals( _expectedStr, _actualStr );

  StrList* elementsOfSub4StrList = controller.genStrListOfElements( sub4 );
  int noOfStrOfElementsOfSub4 = elementsOfSub4StrList->size( );
  _actualInt = noOfStrOfElementsOfSub4;
  _expectedInt = 6; // element41, standalone42, element43, .. => 6
  assertEquals( _expectedInt, _actualInt );
  for( int s = 0; s < noOfStrOfElementsOfSub4; s++ ) {
    Str strElement = elementsOfSub4StrList->get( s );
    _actualStr = strElement;
    if( s == 0 )
      _expectedStr = "element41";
    if( s == 1 )
      _expectedStr = "standalone42";
    if( s == 2 )
      _expectedStr = "element43";
    if( s == 3 )
      _expectedStr = "standalone44";
    if( s == 4 )
      _expectedStr = "element45";
    if( s == 5 )
      _expectedStr = "element46";
    assertEquals( _expectedStr, _actualStr );
  } // s

  // testing XML tags; hardcore version
  _expectedStr = "<element11>true</element11>";
  _actualStr =  element11->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "<element12>false</element12>";
  _actualStr =  element12->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<standalone21 switch=\"true\"/>";
  _actualStr =  standalone21->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "<standalone22 switch=\"false\"/>";
  _actualStr =  standalone22->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr =
      "<standalone31 switch311=\"true\" switch312=\"true\" switch313=\"true\"/>";
  _actualStr =  standalone31->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr =
      "<standalone32 switch321=\"false\" switch322=\"false\" switch323=\"false\"/>";
  _actualStr =  standalone32->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<element41>true</element41>";
  _actualStr =  element41->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "<standalone42 switch=\"false\"/>";
  _actualStr =  standalone42->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "<element43>true</element43>";
  _actualStr =  element43->getTag( );
  assertEquals( _expectedStr, _actualStr );
  _expectedStr = "<standalone44 switch=\"false\"/>";
  _actualStr =  standalone44->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<![CDATA[abcdefghijklmnopqrstuvwxyz]]>";
  _actualStr =  cData->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr =
      "<!--unit test cases for class DOM::Controller-->";
  DOM::Node* commentOfMain = controller.getFirstComment( main );
  _actualStr =  commentOfMain->getTag( );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr =
      "<sub1>\n<!--sub element no 1-->\n<element11>true</element11>\n<element12>false</element12>\n</sub1>";
  _actualStr =  sub1->getTag( );
  assertEquals( _expectedStr, _actualStr );

  // TODO no idea to hack, add some more unit test packs .. !#§%

  delete attribute32StrList; // does not delete any stored Node*
  delete attribute31StrList; // does not delete any stored Node*
  delete elementsOfSub4StrList; // does not delete any stored Node*
  delete elementsOfSub4List; // does not delete any stored Node*
  delete attribute32List; // does not delete any stored Node*
  delete attribute31List; // does not delete any stored Node*
  delete subOfMainList; // does not delete any stored Node*
  delete xml; // delete all DOM::Node* objects recursively

} // Controller::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
