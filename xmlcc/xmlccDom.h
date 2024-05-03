/** 
 * @file xmlccDom.h
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

#ifndef __xmlccDom_h__
#define __xmlccDom_h__

/******************************************************************************/

#define _XMLCC_VERSION_DOM_ 1.00 // 20150101

/******************************************************************************/

#include "./xmlccDomTypes.h"      // DOM:: defines, types, and enums
#include "./xmlccDomParser.h"     // DOM::Parser; parses files to TagList*
#include "./xmlccDomController.h" // DOM::Controller; processes Node* & DOM tree
#include "./xmlccDomTokenizer.h"  // DOM::Tokenizer;  maps TagList 2 DOM tree
#include "./xmlccDomCore.h"       // DOM::Core; methods for parsing 2 DOM tree

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/******************************************************************************/

} // namespace DOM

/******************************************************************************/

typedef DOM::Tag Tag; // template & namespace typedef
typedef DOM::TagList TagList; // template & namespace typedef

/******************************************************************************/

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDom_h__

/******************************************************************************/
