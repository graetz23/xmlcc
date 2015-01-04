/** 
 * @file xmlccTest.h
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

#ifndef __xmlccTest_h__
#define __xmlccTest_h__

/******************************************************************************/

#include "./xmlcc.h" // building objects
#include "./xmlccSys.h" // using SYS:: for unit test framework
#include "./xmlccTestSysList.h" // unit test cases for SYS::List
#include "./xmlccTestSysStrTool.h" // unit test cases for SYS::StrTool
#include "./xmlccTestSysXmlTool.h" // unit test cases for SYS::XmlTool
#include "./xmlccTestSysXmlParser.h" // unit test cases for SYS::XmlParser
#include "./xmlccTestDomTokenizer.h" // unit test cases for DOM::Tokenizer
#include "./xmlccTestDomController.h" // unit test cases for DOM::Controller
#include "./xmlccTestXmlcc.h" // unit test cases for parse & write

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

#define _XMLCC_VERSION_TEST_ 1.00 // 20150101

/****************************************************************************/

void run( void ); /// run all available tests for XMLCC::

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/

#endif // _XMLCC_TEST_

/******************************************************************************/
