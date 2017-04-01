/** 
 * @file xmlccDomHeader.h
 * @author Christian Scheiblich
 * @contact cscheiblich@gmail.com
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2017 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __xmlccDomHeader_h__
#define __xmlccDomHeader_h__

/******************************************************************************/

#include "./xmlccDomNode.h" // base class DOM::Node represents any XML node

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Header_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Header_
#endif

/******************************************************************************/

class Header: public Node {
  public:

    Header( void ); /// set tag to "xml"
    Header( Attribute* egVersion ); /// set e.g. version="1.0"
    Header( Attribute* egVersion, Attribute* egEncoding ); /// set e.g. version and encoding="UTF-8"
    Header( Attribute* egVersion, Attribute* egEncoding,
        Attribute* egStandalone ); ///  set v., enc., and standalone="yes"

    Header( Str tag ); /// set tag, should be always "xml"
    Header( Str tag, Attribute* a0 ); /// set e.g. version="1.0"
    Header( Str tag, Attribute* a0, Attribute* a1 ); /// set e.g. version and encoding="UTF-8"
    Header( Str tag, Attribute* a0, Attribute* a1, Attribute* a2 ); /// set v., enc., and standalone="yes"

    virtual ~Header( void ); /// destructor

    Str getTag( void ); /// returns the stored tag of this header
    void setTag( Str tag ); /// sets the tag of this header

    friend std::ostream& operator <<( std::ostream& s, Header* node );

};
// class Header

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomHeader_h__
