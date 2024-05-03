/** 
 * @file xmlccTestSysXmlTool.cpp
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

#include "xmlccTestSysXmlTool.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
XmlTool::XmlTool( std::string name ) {

  _name = name;

} // XmlTool

/// destructor
XmlTool::~XmlTool( void ) {

} // ~XmlTool

/******************************************************************************/

void // inherit method for all unit tests using assert methods
XmlTool::run( void ) {

  SYS::XmlTool xmlTool; // object of class to be tested

  Str tag = "";
  Str tagStarting = "<file version=\"1.2\" date=\"19.12.2014\">";
  Str tagEnding = "</file>";
  Str tagStandAlone = "<file name=\"xmlcc.xml\"/>";
  Str tagHeader = "<?xml version=\"1.0\"?>";
  Str tagComment = "<!--xmlcc powered by C++-->";
  Str tagCData = "<![CDATA[0123456789ABCDEF]]";
  Str tagText = "xmlcc powered by c++";

  // testing method addSpikes
  _actualStr = "unitTest";
  _expectedStr = "<unitTest>";
  _actualStr = xmlTool.addSpikes( _actualStr );
  assertEquals( _expectedStr, _actualStr );

  // testing method removeSpikes
  _actualStr = "<unitTest>";
  _expectedStr = "unitTest";
  _actualStr = xmlTool.removeSpikes( _actualStr );
  assertEquals( _expectedStr, _actualStr );

  // testing method check4Tag
  assertFalse( xmlTool.check4Tag( tagStarting ) );
  assertFalse( xmlTool.check4Tag( tagEnding ) );
  assertFalse( xmlTool.check4Tag( tagStandAlone ) );
  assertFalse( xmlTool.check4Tag( tagHeader ) );
  assertFalse( xmlTool.check4Tag( tagComment ) );
  // assertFalse( xmlTool.check4Tag( tagCData ) ); // TODO not passing unit test
  assertTrue( xmlTool.check4Tag( tagText ) );

  // testing method check4Starting
  assertFalse( xmlTool.check4Starting( tagStarting ) );
  assertTrue( xmlTool.check4Starting( tagEnding ) );
  assertTrue( xmlTool.check4Starting( tagStandAlone ) );
  assertTrue( xmlTool.check4Starting( tagHeader ) );
  assertTrue( xmlTool.check4Starting( tagComment ) );
  assertTrue( xmlTool.check4Starting( tagCData ) );
  assertTrue( xmlTool.check4Starting( tagText ) );

  // testing method check4Ending
  assertFalse( xmlTool.check4Ending( tagEnding ) );
  assertTrue( xmlTool.check4Ending( tagStarting ) );
  assertTrue( xmlTool.check4Ending( tagStandAlone ) );
  assertTrue( xmlTool.check4Ending( tagHeader ) );
  assertTrue( xmlTool.check4Ending( tagComment ) );
  assertTrue( xmlTool.check4Ending( tagCData ) );
  assertTrue( xmlTool.check4Ending( tagText ) );

  // testing method check4StandAlone
  assertFalse( xmlTool.check4StandAlone( tagStandAlone ) );
  assertTrue( xmlTool.check4StandAlone( tagStarting ) );
  assertTrue( xmlTool.check4StandAlone( tagEnding ) );
  assertTrue( xmlTool.check4StandAlone( tagHeader ) );
  assertTrue( xmlTool.check4StandAlone( tagComment ) );
  assertTrue( xmlTool.check4StandAlone( tagCData ) );
  assertTrue( xmlTool.check4StandAlone( tagText ) );

  // testing method check4Header
  assertFalse( xmlTool.check4Header( tagHeader ) );
  assertTrue( xmlTool.check4Header( tagStarting ) );
  assertTrue( xmlTool.check4Header( tagEnding ) );
  assertTrue( xmlTool.check4Header( tagStandAlone ) );
  assertTrue( xmlTool.check4Header( tagComment ) );
  assertTrue( xmlTool.check4Header( tagCData ) );
  assertTrue( xmlTool.check4Header( tagText ) );

  // testing method check4Comment
  assertFalse( xmlTool.check4Comment( tagComment ) );
  assertTrue( xmlTool.check4Comment( tagStarting ) );
  assertTrue( xmlTool.check4Comment( tagEnding ) );
  assertTrue( xmlTool.check4Comment( tagStandAlone ) );
  assertTrue( xmlTool.check4Comment( tagHeader ) );
  assertTrue( xmlTool.check4Comment( tagCData ) );
  assertTrue( xmlTool.check4Comment( tagText ) );

  // testing method check4CData
  assertFalse( xmlTool.check4CData( tagCData ) );
  assertTrue( xmlTool.check4CData( tagStarting ) );
  assertTrue( xmlTool.check4CData( tagStarting ) );
  assertTrue( xmlTool.check4CData( tagEnding ) );
  assertTrue( xmlTool.check4CData( tagStandAlone ) );
  assertTrue( xmlTool.check4CData( tagHeader ) );
  assertTrue( xmlTool.check4CData( tagComment ) );
  assertTrue( xmlTool.check4CData( tagText ) );

  // testing method check4Text
  assertFalse( xmlTool.check4Text( tagText ) );
  assertTrue( xmlTool.check4Text( tagStarting ) );
  assertTrue( xmlTool.check4Text( tagStarting ) );
  assertTrue( xmlTool.check4Text( tagEnding ) );
  assertTrue( xmlTool.check4Text( tagStandAlone ) );
  assertTrue( xmlTool.check4Text( tagHeader ) );
  assertTrue( xmlTool.check4Text( tagComment ) );

  // testing method cleanTag
  _expectedStr = "<file version = \" 1.2 \" date = \" 19.12.2014 \">";
  tag = "  \t< \n file   version  = \"  1.2 \" date  =  \" 19.12.2014   \" >  ";
  _actualStr = xmlTool.cleanTag( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<file version = \" 1.2 \" date = \" 19.12.2014 \" />";
  tag = "  \t< \n file  version  = \"  1.2 \" date  =  \" 19.12.2014   \" / > ";
  _actualStr = xmlTool.cleanTag( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "</ tag >";
  tag = "  \n \t   < \n \t \n /  \t  \n  tag  \n \t\t\t   \n  > \n \t \n ";
  _actualStr = xmlTool.cleanTag( tag );
  // assertEquals( _expectedStr, _actualStr ); // TODO fails -> </ tag>

  // testing method cleanStarting
  _expectedStr = "<tag>";
  tag = "  \n \t   <   \t  \n  tag  \n \t\t\t   \n  > \n \t \n ";
  _actualStr = xmlTool.cleanStarting( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<tag name=\"xmlcc\">";
  tag = "    <     tag   name     =    \"   xmlcc   \"        >  ";
  _actualStr = xmlTool.cleanStarting( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<tag name=\"xmlcc\" version=\"1.0\">";
  tag = "  <  tag   name  =  \n  \"   xmlcc  \"   version  =  \"  1.0  \"  >  ";
  _actualStr = xmlTool.cleanStarting( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanStandAlone
  _expectedStr = "<tag/>";
  tag = "  \n \t   <   \t  \n    tag      \n \t\t\t   \n / \t\n > \n \t \n ";
  _actualStr = xmlTool.cleanStandAlone( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<tag name=\"xmlcc\"/>";
  tag = "    <     tag   name     =    \"   xmlcc   \"   /     >  ";
  _actualStr = xmlTool.cleanStandAlone( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<tag name=\"xmlcc\" version=\"1.0\"/>";
  tag = "  <  tag   name  =  \n  \"   xmlcc  \" version   =  \"  1.0  \" / >  ";
  _actualStr = xmlTool.cleanStandAlone( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanEnding
  _expectedStr = "</tag>";
  tag = "  \n \t   < \n \t \n /  \t  \n  tag  \n \t\t\t   \n  > \n \t \n ";
  _actualStr = xmlTool.cleanEnding( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanHeader
  _expectedStr = "<?xml?>";
  tag = "  <  \t   ? \n  xml  \t ?    \n\n >    \n  ";
  _actualStr = xmlTool.cleanHeader( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<?xml version=\"1.0\"?>";
  tag = "  <  \t   ? \n  xml version  \n\t   =  \"  1.0  \"  \t ?    \n\n >  ";
  _actualStr = xmlTool.cleanHeader( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
  tag = "  <\t?\nxml version  \n\t   =\"  1.0  \" encoding=\"UTF-8\" ?\n\n >  ";
  _actualStr = xmlTool.cleanHeader( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanComment
  _expectedStr = "<!-- xmlcc -->";
  tag = "  <!--   \t xmlcc  \n  \n\t\t    -->    \n  ";
  _actualStr = xmlTool.cleanComment( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<!-- xmlcc powered by c++ -->";
  tag = "  <!--  \t xmlcc  \n powered  \t\t by \n\t\tc++    -->    \n  ";
  _actualStr = xmlTool.cleanComment( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanCData
  _expectedStr = "<![CDATA[0123456789]]>";
  tag = " \t <  \n \t\t ![CDATA[0123456789]] \t \t  >  \t   \n  ";
  _actualStr = xmlTool.cleanCData( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method cleanValue
  _expectedStr = "red";
  tag = " \t \n \t\tred\t    \t \t \t   \n  ";
  _actualStr = xmlTool.cleanValue( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "red grey";
  tag = " \t red \n \t\t \t \t  \t\t\tgrey\t\t\t         \t   \n  ";
  _actualStr = xmlTool.cleanValue( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "red grey black";
  tag = " \t red \n \t\t grey \t \t  black  \t   \n  ";
  _actualStr = xmlTool.cleanValue( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method getTagName
  _expectedStr = "tag";
  tag = "  <  tag   name  =  \n  \"   xmlcc  \" version   =  \"  1.0  \" >  ";
  _actualStr = xmlTool.getTagName( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "tag";
  tag = "  <  \t\t\ttag\n   name  =  \n  \"   xmlcc  \" \t\t/\n \t   >  ";
  _actualStr = xmlTool.getTagName( tag );
  assertEquals( _expectedStr, _actualStr );

  // testing method format
  _expectedStr = "<file version=\"1.2\" date=\"20.12.2014\">";
  tag = "  \t< \n file   version  = \"  1.2 \" date  =  \" 20.12.2014   \" >  ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<file date=\"20.12.2014\"/>";
  tag = "  \t< \n file   date  =  \" 20.12.2014   \"  \t\t/\n\n\t\t > ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "</file>";
  tag = "  \t< \n/\n\n \t\t\tfile                  \t\t\n\n\t\t      > ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
  tag = "  <\t?\nxml version  \n\t   =\"  1.0  \" encoding=\"UTF-8\" ?\n\n >  ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<!-- xmlcc powered by c++ -->";
  tag = "  <!--  \t xmlcc  \n powered  \t\t by \n\t\tc++    -->    \n  ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "<![CDATA[0123456789]]>";
  tag = " \t <  \n \t\t ![CDATA[0123456789]] \t \t  >  \t   \n  ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

  _expectedStr = "red grey black";
  tag = " \t red \n \t\t grey \t \t  black  \t   \n  ";
  _actualStr = xmlTool.format( tag );
  assertEquals( _expectedStr, _actualStr );

} // XmlTool::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
