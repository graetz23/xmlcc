/** 
 * @file xmlccSaxHandlerExample.h
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

#ifndef __xmlccSaxHandlerExample_h__
#define __xmlccSaxHandlerExample_h__

/******************************************************************************/

#include "./xmlccSaxHandler.h" // for converting strings 2 objects

namespace XMLCC {

namespace SAX {

/******************************************************************************/

#define _XMLCC_VERSION_SAX_HandlerExample_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SAX_HandlerExample_
#endif

/******************************************************************************/

class /// example for an handler pushing writing data 2 console
HandlerExample: public Handler {
  public:

    HandlerExample( void ); /// constructor
    virtual ~HandlerExample( void ); /// destructor

    void startDoc( void ); /// called before reading document

    void startTag( Str tag ); /// called for each starting XML tag

    void characters( Str txt ); /// called for each text value in XML

    void endTag( Str tag ); /// called for each ending XML tag

    void endDoc( void ); /// called after reading document

  private:

    int _level; // count level in XML structure and print tabulators for it

    SYS::XmlTool _xmlTool; // recognizing starting < .. > and ending </ .. > tags

};
// class HandlerExample

/******************************************************************************/

}// namespace SAX

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSaxHandlerExample_h__
