/** 
 * @file xmlccDomDefines.h
 * @author Christian Scheiblich
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

#ifndef __xmlccDomDefines_h__
#define __xmlccDomDefines_h__

/******************************************************************************/

#define _XMLCC_VERSION_DOM_DEFINES_ 1.00 // 20150101

/******************************************************************************/

#include <exception> // std::exception
#include <typeinfo>  // dynmaic_cast<T>
#include <iostream>  // std::cout
#include <sstream>   // std::strstream
#include <fstream>   // std::fsteam
#include <stdio.h>   // c std io lib
#include <cstring>   // std::cstring
#include <string>    // std::string
#include <vector>    // std::vector
#include <math.h>    // floor()

/******************************************************************************/

// XMLCC:: base configuration of #defines and #templates - on top of all source!
namespace XMLCC {

namespace DOM {

#ifndef _DOM_DEFINES_
#define _DOM_DEFINES_ /// use this for SYS:: to exclude for example
#endif

typedef std::string Str; /// use STL typedef in SYS namespace
typedef std::string Str; /// use STL typedef in SYS namespace
typedef std::fstream FileStr; /// use STL typedef in SYS namespace
typedef std::ifstream FileStrIn; /// use STL typedef in SYS namespace
typedef std::ofstream FileStrOut; /// use STL typedef in SYS namespace

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomDefines_h__

/******************************************************************************/
