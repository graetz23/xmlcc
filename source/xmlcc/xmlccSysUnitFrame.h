/** 
 * @file xmlccSysUnitFrame.h
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

#ifndef __xmlccSysUnitFrame_h__
#define __xmlccSysUnitFrame_h__

/******************************************************************************/

#include "./xmlccSysList.h" /// template based smart array for unit test objects
#include "./xmlccSysUnitTest.h" /// base class for each unit test implementation

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_UnitFrame_ _XMLCC_VERSION_SYS_UnitTest_
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_UnitFrame_
#endif

/******************************************************************************/

class // class for manipulating std::string and char*
UnitFrame {
  public:

    UnitFrame( void ); /// constructor
    virtual ~UnitFrame( void ); /// destructor

    void add( UnitTest* unitTest ); // register a unit test object

    void run( void ); /// run all registered unit tests; UnitTest objects

  private:

    List< UnitTest* >* _unitTestList; /// list of available unit Tests

};
// class UnitFrame

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysUnitFrame_h__
