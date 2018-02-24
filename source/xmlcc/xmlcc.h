/** 
 * @file xmlcc.h
 * @author Christian Scheiblich
 *
 * XMLCC is a C++ library for the extensible markup language (XML). It is
 * strongly object-oriented and based on software design patterns for
 * generating, searching, and parsing even malformed XML files. Two parsers are
 * available: a simple API for XML (SAX) parser for an event based parsing and
 * a document object model (DOM) parser generating an object model tree. XMLCC
 * is yet a non validating, not speed optimized, and explicit not dealing with
 * file encodings; those are overcome by C++'s local standard template libraries
 * (STL). It provides an easy access to XML files.
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

#ifndef __xmlcc_h__
#define __xmlcc_h__

/******************************************************************************/

#include "./xmlccDom.h" // XMLCC::DOM:: document object model (DOM)
#include "./xmlccSax.h" // XMLCC::SAX:: simple API for XML (SAX)
#include "./xmlccCfg.h" // XMLCC::CFG:: configuration of xmlcc lib

/******************************************************************************/

#ifdef _XMLCC_USE_TEST_

#include "./xmlccTest.h" // XMLCC::TEST::

#endif

/******************************************************************************/

namespace XMLCC {

/******************************************************************************/

#define _XMLCC_LICENSE_ MIT /// use and share by the MIT License (MIT)
#define _XMLCC_VERSION_ 1.00 /// version number of the current implementation
#define _XMLCC_DATE_ 20150101 /// date of the current implementation
#define _XMLCC_PACKAGE_ "Amara Faith" /// name of the current package
#define _XMLCC_BUILD_DATE_ __DATE__ /// the actual date for compiling
#define _XMLCC_BUILD_TIME_ __TIME__ /// the actual time for compiling

/******************************************************************************/

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlcc_h__

/******************************************************************************/
