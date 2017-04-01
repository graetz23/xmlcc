/** 
 * @file xmlccSys.h
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2017 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __xmlccSys_h__
#define __xmlccSys_h__

/******************************************************************************/

#define _XMLCC_VERSION_SYS_ 1.00 // 20150101

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs
#include "./xmlccSysException.h" /// exception base class for errors & failures
#include "./xmlccSysFailure.h" /// exception class for failures
#include "./xmlccSysError.h" /// exception class for capital errors
#include "./xmlccSysList.h" /// template based smart array for unit test objects
#include "./xmlccSysStrTool.h" /// tool for manipulating std::string & char*
#include "./xmlccSysXmlTool.h" /// tool for cleaning malformed XML tags
#include "./xmlccSysXmlHandler.h" /// class for handling read XML tags & texts
#include "./xmlccSysXmlParser.h" /// class for parsing XML files
#include "./xmlccSysUnitTest.h" /// base class for each unit test implementation
#include "./xmlccSysUnitFrame.h" /// class for unit test framework

/******************************************************************************/

// SYS:: base configuration of #defines and #templates - on top of all source!
namespace XMLCC {

namespace SYS {

/******************************************************************************/

/******************************************************************************/

} // namespace SYS

typedef SYS::StrList StrList;       // namespace & template typedef
typedef SYS::Str Tag;            // namespace & template typedef
typedef SYS::StrList TagList;    // namespace & template typedef

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSys_h__

/******************************************************************************/
