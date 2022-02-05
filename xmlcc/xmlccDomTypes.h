/** 
 * @file xmlccDomTypes.h
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

#ifndef __xmlccDomTypes_h__
#define __xmlccDomTypes_h__

/******************************************************************************/

#include "./xmlccDefines.h" /// common include file for headers and typedefs

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Types_ 1.00 // 20150101

/******************************************************************************/

namespace Types { /// namespace for types

enum /// types for building XML elements (XMLCC objects)
Type {
  Root = 0,
  Header = 1,
  Element = 2,
  Attribute = 3,
  Value = 4,
  Comment = 5,
  CData = 6,
  Doctype = 7
};
// enum Type

/******************************************************************************/

}// namespace Types

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomTypes_h__

/******************************************************************************/
