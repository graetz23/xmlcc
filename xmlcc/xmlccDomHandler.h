/** 
 * @file xmlccDomHandler.h
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

#ifndef __xmlccDomHandler_h__
#define __xmlccDomHandler_h__

/******************************************************************************/

#include "./xmlccDefines.h" // XMLCC::
#include "./xmlccSys.h" // SYS::
#include "./xmlccSysXmlHandler.h" // base class

/******************************************************************************/

namespace XMLCC {

typedef Str Tag; /// namespace typedef
typedef StrList TagList; // namespace typedef

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Handler_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Handler_
#endif

/******************************************************************************/

class /// base class for all handlers 2 be implemented
Handler: public SYS::XmlHandler {
  public:

    Handler( TagList* xmlList ); /// pass an XmlList object
    virtual ~Handler( void ); /// destructor

    void startDoc( void ); /// called before reading document

    void startTag( Str tag ); /// called for each starting XML tag

    void characters( Str txt ); /// called for each text value in XML

    void endTag( Str tag ); /// called for each ending XML tag

    void endDoc( void ); /// called after reading document

  private:

    TagList* _tagList; /// list keeping all found XML; SYS::List< Str >*

};
// class Handler

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomHandler_h__
