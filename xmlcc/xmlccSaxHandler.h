/** 
 * @file xmlccSaxHandler.h
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

#ifndef __xmlccSaxHandler_h__
#define __xmlccSaxHandler_h__

/******************************************************************************/

#include "./xmlccDefines.h" // XMLCC::
#include "./xmlccSys.h" // SYS::
#include "./xmlccSysXmlHandler.h" // base class

/******************************************************************************/

namespace XMLCC {

namespace SAX {

/******************************************************************************/

#define _XMLCC_VERSION_SAX_Handler_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SAX_Handler_
#endif

/******************************************************************************/

class /// base class for all handlers 2 be implemented
Handler: public SYS::XmlHandler {
  public:

    Handler( void ); /// constructor
    virtual ~Handler( void ); /// destructor

    virtual void startDoc( void ); /// called before reading document

    virtual void startTag( Str tag ); /// called for each starting XML tag

    virtual void characters( Str txt ); /// called for each text value in XML

    virtual void endTag( Str tag ); /// called for each ending XML tag

    virtual void endDoc( void ); /// called after reading document

};
// class Handler

/******************************************************************************/

}// namespace SAX

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSaxHandler_h__

/******************************************************************************/
