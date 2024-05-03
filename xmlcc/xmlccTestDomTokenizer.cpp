/** 
 * @file xmlccTestDomTokenizer.cpp
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

#include "xmlccTestDomTokenizer.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
Tokenizer::Tokenizer( std::string name ) {

  _name = name;

} // Tokenizer

/// destructor
Tokenizer::~Tokenizer( void ) {

} // ~Tokenizer

/******************************************************************************/

void // inherit method for all unit tests using assert methods
Tokenizer::run( void ) {

  DOM::Tokenizer tokenizer; // object of class to be tested

  Str tag = "";
  Str tagStarting = "<file version=\"1.2\" date=\"19.12.2014\">";
  Str tagEnding = "</file>";
  Str tagStandAlone = "<file name=\"xmlcc.xml\"/>";
  Str tagHeader = "<?xml version=\"1.0\"?>";
  Str tagComment = "<!--xmlcc powered by C++-->";
  Str tagCData = "<![CDATA[0123456789ABCDEF]]";
  Str tagText = "xmlcc powered by c++";

//  // testing method addSpikes
//  _actualStr = "unitTest";
//  _expectedStr = "<unitTest>";
//  _actualStr = xmlTool.addSpikes( _actualStr );
//  assertEquals( _expectedStr, _actualStr );
//
//  // testing method check4Text
//  assertFalse( xmlTool.check4Text( tagText ) );
//  assertTrue( xmlTool.check4Text( tagStarting ) );
//  assertTrue( xmlTool.check4Text( tagStarting ) );
//  assertTrue( xmlTool.check4Text( tagEnding ) );
//  assertTrue( xmlTool.check4Text( tagStandAlone ) );
//  assertTrue( xmlTool.check4Text( tagHeader ) );
//  assertTrue( xmlTool.check4Text( tagComment ) );
//
//  // testing method cleanTag
//  _expectedStr = "<file version = \" 1.2 \" date = \" 19.12.2014 \">";
//  tag = "  \t< \n file   version  = \"  1.2 \" date  =  \" 19.12.2014   \" >  ";
//  _actualStr = xmlTool.cleanTag( tag );
//  assertEquals( _expectedStr, _actualStr );

} // Tokenizer::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
