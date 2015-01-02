/** 
 * @file xmlccCfg.h
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

#ifndef __xmlccCfg_h__
#define __xmlccCfg_h__

/******************************************************************************/

#define _XMLCC_VERSION_CFG_ 1.00 // 20150101

/******************************************************************************/

#include "./xmlccCfgConfig.h" // configuration handler for XMLCC library

/******************************************************************************/

namespace XMLCC {

namespace CFG {

/******************************************************************************/

#ifndef _CFG_DEFINES_
#define _CFG_DEFINES_ /// use this for SYS:: to exclude for example
#endif

/******************************************************************************/

} // namespace CFG

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccCfg_h__

/******************************************************************************/
