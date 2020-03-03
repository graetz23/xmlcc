/** 
 * @file xmlccTestSysStrTool.cpp
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

#include "xmlccTestSysStrTool.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
StrTool::StrTool( std::string name ) {

  _name = name;

} // StrTool

/// destructor
StrTool::~StrTool( void ) {

} // ~StrTool

/******************************************************************************/

void // inherit method for all unit tests using assert methods
StrTool::run( void ) {

  SYS::StrTool strTool; // object of class to be tested

  Str text = "There was a young lady of Riga, who smiled as she rode on a tiger";
  Str textLower =
    "there was a young lady of riga, who smiled as she rode on a tiger";
  Str textUpper =
    "THERE WAS A YOUNG LADY OF RIGA, WHO SMILED AS SHE RODE ON A TIGER";
  Str limerick = "";
  limerick.append( "There was a young lady of Riga, " );
  limerick.append( "who smiled as she rode on a tiger, " );
  limerick.append( "they returned from the ride, with the lady inside, " );
  limerick.append( "and the smile on the face of the tiger." );

  // testing method compare
  assertTrue( strTool.compareS2S( text, textLower ) );
  assertTrue( strTool.compareS2S( text, textUpper ) );
  assertTrue( strTool.compareS2S( textLower, textUpper ) );
  assertFalse( strTool.compareS2S( limerick, limerick ) );

  // testing method convert text to lower characters
  _expectedStr = textLower;
  _actualStr = strTool.doS2low( textUpper );
  assertEquals( _expectedStr, _actualStr );

  // testing method convert text to upper characters
  _expectedStr = textUpper;
  _actualStr = strTool.doS2up( textLower );
  assertEquals( _expectedStr, _actualStr );

  //TODO implemented unit test cases if bored of other code ..

// // testing method addSpikes
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

} // StrTool::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
