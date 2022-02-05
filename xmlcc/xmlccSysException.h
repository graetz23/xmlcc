/** 
 * @file xmlccSysException.h
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2022 Christian (graetz23@gmail.com)
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

#ifndef __xmlccSysException_h__
#define __xmlccSysException_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_Exception_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_Exception_
#endif

/******************************************************************************/

#ifndef _SYS_DEFINES_ // if the sysDefines.h is not used and strTool is

typedef std::string Str; /// use STL typedef in SYS namespace
typedef std::fstream FileStr;/// use STL typedef in SYS namespace
typedef std::ifstream FileStrIn;/// use STL typedef in SYS namespace
typedef std::ofstream FileStrOut;/// use STL typedef in SYS namespace

#endif

/******************************************************************************/

class /// base class for errors
Exception {
  public:

    Exception( void ); /// constructor
    Exception( Str message ); /// constructor overloaded
    Exception( Str message, int lineNo ); /// use __LINE__ @ lineNo
    Exception( Str message, char* fileName ); /// use __FILE__ @ fileName
    Exception( Str message, char* fileName, int lineNo ); /// use __FILE__ @ fileName and __LINE__ @ lineNo
    virtual ~Exception( void ); /// destructor

    Str declare( void ) const; /// returns message as std::string
    void report( void ) const; /// message to console
    void stop( void ) const; /// message to console and wait for enter
    void nuke( void ) const; /// do a nuke and melt down afterwards

    friend std::ostream& operator <<( std::ostream& s, Exception& e ); /// cout
    friend std::ostream& operator <<( std::ostream& s, Exception* e ); /// cout

  protected:

    Str _message; /// the generated exception message

  private:

    virtual void mark( void ); /// mark exception

};
// class Exception

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysException_h__
