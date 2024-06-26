/** 
 * @file xmlccTestSysStrTool.h
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

#ifndef __xmlccTestSysStrTool_h__
#define __xmlccTestSysStrTool_h__

/******************************************************************************/

#include "./xmlccTestDefines.h" // defines, includes & typdefs for TEST::
#include "./xmlccSys.h" // use SYS:: for implementation of unit tests

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

#define _XMLCC_VERSION_TEST_SYS_StrTool_ _XMLCC_VERSION_SYS_StrTool_
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_TEST_SYS_StrTool_
#endif

/******************************************************************************/

class /// implementing run method and the unit tests for class SYS::StrTool
StrTool: public SYS::UnitTest {
  public:

    StrTool( std::string name ); /// constructor
    virtual ~StrTool( void ); /// destructor

    void run( void ); /// inherit method for all unit tests using assert methods

};
// class TEST::StrTool

/******************************************************************************/

}// namespace TEST

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccTestSysStrTool_h__

/******************************************************************************/
