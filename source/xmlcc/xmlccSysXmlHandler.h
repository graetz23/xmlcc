/** 
 * @file xmlccSysXmlHandler.h
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

#ifndef __xmlccSysXmlHandler_h__
#define __xmlccSysXmlHandler_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" // SYS:: and all other
#include "./xmlccSysException.h" // base class for exceptions in SYS::
#include "./xmlccSysFailure.h" // exception class for marking failures
#include "./xmlccSysError.h" // exception class for marking errors

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_XmlHandler_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_XmlHandler_
#endif

/******************************************************************************/

class /// base class for all handlers 2 be implemented
XmlHandler {
  public:

    XmlHandler( void ); /// constructor
    XmlHandler( bool isTalking ); /// constructor
    virtual ~XmlHandler( void ); /// destructor

    virtual void startDoc( void ); /// called before reading document

    virtual void startTag( Str tag ); /// called for each starting XML tag

    virtual void characters( Str txt ); /// called for each text value in XML

    virtual void endTag( Str tag ); /// called for each ending XML tag

    virtual void endDoc( void ); /// called after reading document

  private:

    bool _isTalking; /// std::cout or throw an exception if this handler is used

};
// class XmlHandler

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysXmlHandler_h__
