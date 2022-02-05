/** 
 * @file xmlccSysStrTool.h
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

#ifndef __xmlccSysStrTool_h__
#define __xmlccSysStrTool_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs
#include "./xmlccSysFailure.h" /// SYS::Failure exception

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_StrTool_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_StrTool_
#endif

/******************************************************************************/

#ifndef _SYS_DEFINES_ // if the sysDefines.h is not used and strTool is

typedef std::string Str; /// use STL typedef in SYS namespace
typedef std::fstream FileStr;/// use STL typedef in SYS namespace
typedef std::ifstream FileStrIn;/// use STL typedef in SYS namespace
typedef std::ofstream FileStrOut;/// use STL typedef in SYS namespace

#endif

/******************************************************************************/

class /// class for manipulating std::string and char* data types
StrTool {
  public:

    StrTool( void ); /// constructor
    virtual ~StrTool( void ); /// destructor

    Str trimS( Str str ); /// remove \ \n\t\r from left and right to first letter or number in string
    Str trimS2L( Str str ); /// remove \ \n\t\r from left to first letter or number in string
    Str trimS2R( Str str ); /// remove \ \n\t\r from right to first letter or number in string

    Str filterWs( Str str ); /// remove more white spaces followed by white spaces
    Str filterTs( Str str ); /// remove more tabulators and replace with white space
    Str filterBs( Str str ); /// remove break lines and replace by white spaces

    std::vector< Str > splitS2Ws( Str str ); // split by white spaces to std::vector

    Str doS2low( Str str ); /// lower all letters in string
    Str doS2up( Str str ); /// upper all letters in string

    Str doI2S( int value ); // convert integer to string
    Str doL2S( long svalue ); // convert long to string
    Str doB2S( bool value ); // convert boolean to string
    Str doF2S( float value ); // convert float to string
    Str doD2S( double value ); // convert double to string
    int doS2I( Str str ); // convert string to integer
    long doS2L( Str str ); // convert string to long
    bool doS2B( Str str ); // convert string to boolean
    float doS2F( Str str ); // convert string to float
    double doS2D( Str str ); // convert string to double

    bool checkS2Std( Str str ); /// check string for containing only standard characters
    bool checkS2Ws( Str str ); /// check string for containing white spaces

    bool checkS2WsOnly( Str str ); /// check string for containing only white spaces

    bool compareS2S( Str str1, Str str2 ); // if both are the same ->; case sensitive

    // some stuff for XML tags: '< >' '</ >' '< />' '<? ?>' '<!-- -->'

};
// class StrTool

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysStrTool_h__
