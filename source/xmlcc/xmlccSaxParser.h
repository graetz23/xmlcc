/** 
 * @file xmlccSaxParser.h
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

#ifndef __xmlccSaxParser_h__
#define __xmlccSaxParser_h__

/******************************************************************************/

#include "./xmlccSaxHandler.h" // for handling data
#include "./xmlccSaxHandlerExample.h" // for handling data

/******************************************************************************/

namespace XMLCC {

namespace SAX {

/******************************************************************************/

#define _XMLCC_VERSION_SAX_Parser_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SAX_Parser_
#endif

/******************************************************************************/

class  /// SAX parser calling handler function with read data
Parser {
  public:

    Parser( Handler* handler ); /// constructor
    virtual ~Parser( void ); /// destructor

    void parseBuffer( char* buffer ); /// parses XML from buffer and calls handler's virtual functions
    void parseBuffer( Str buffer ); /// parses XML from buffer and calls handler's virtual functions
    void parseFile( Str fileName ); /// parses XML from file and calls handler's virtual functions

  protected:

    Handler* _handler; /// a handler for parsed data

};
// class Parser

/******************************************************************************/

}// namespace SAX

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSaxParser_h__

/******************************************************************************/
