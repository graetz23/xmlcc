/** 
 * @file xmlccDefines.h
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2016 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __xmlccDefines_h__
#define __xmlccDefines_h__

/******************************************************************************/

#define _XMLCC_VERSION_DEFINES_ 1.00 // 20150101

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

#ifndef _XMLCC_USE_TEST_
#define _XMLCC_USE_TEST_ /// enables build of unit tests of XMLCC::TEST::
#endif

#ifndef _XMLCC_DEBUG_
// #define _XMLCC_DEBUG_ /// enables build of debug code & running
#endif

#ifndef _XMLCC_INDENTATION_SIZE_
#define _XMLCC_INDENTATION_SIZE_ 2; /// indentation of the number of white spaces
#endif

typedef std::string Str; /// for STL std:string
typedef std::fstream FileStr; /// for STL std::fstream
typedef std::ifstream FileStrIn; /// for STL std::ifstream
typedef std::ofstream FileStrOut; /// for STL std::ofstream
typedef std::stringstream StrStream; /// for STL std:stringstream

/******************************************************************************/

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDefines_h__
