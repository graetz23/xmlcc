/** 
 * @file xmlccSysUnitTest.h
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

#ifndef __xmlccSysUnitTest_h__
#define __xmlccSysUnitTest_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs
#include "./xmlccSysError.h" /// XMLCC's exception class for capital errors
#include "./xmlccSysFailure.h" /// XMLCC's exception class for failures
#include "./xmlccSysStrTool.h" /// XMLCC's exception class for failures

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_UnitTest_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_UnitTest_
#endif

/******************************************************************************/

class /// class for unit tests like JUnit and cppUnit but way more easy
UnitTest {
  public:

    UnitTest( void ); /// constructor
    UnitTest( Str name ); /// constructor storing unit test name
    virtual ~UnitTest( void ); /// destructor

    virtual void run( void ); /// inherit and implement by using assert methods

    Str tell( void ); /// returns the set name of the unit test

  protected:

    void fail( void ); /// fails a test witho now message

    void assertNull( void* pointer ); /// throws UnitException if null

    void assertTrue( bool condition ); /// throws UnitException if true
    void assertFalse( bool condition ); /// throws UnitException if false

    void assertEquals( int expected, int actual ); /// throws UnitException if not
    void assertEquals( long expected, long actual ); /// throws UnitException if not
    void assertEquals( double expected, double actual ); /// throws UnitException if not
    void assertEquals( double expected, double actual, double delta ); /// throws UnitException if not
    void assertEquals( Str expected, Str actual ); /// throws UnitException if not

    // TODO implement assert equal array methods - think about the double size ..
    // void assertArrayEquals( int* expected, int* actual, int size ); // throws UnitException

    bool _actualBool; /// member for easy usage in objects
    bool _expectedBool; /// member for easy usage in objects
    int _actualInt; /// member for easy usage in objects
    int _expectedInt; /// member for easy usage in objects
    long _actualLong; /// member for easy usage in objects
    long _expectedLong; /// member for easy usage in objects
    double _actualDouble; /// member for easy usage in objects
    double _expectedDouble; /// member for easy usage in objects
    Str _actualStr; /// member for easy usage in objects
    Str _expectedStr; /// member for easy usage in objects

    Str _name; /// name of unit test, set by constructor

    StrTool* _strTool; // string tool for conversion of std::string

};
// class UnitTest

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysUnitTest_h__

/******************************************************************************/
