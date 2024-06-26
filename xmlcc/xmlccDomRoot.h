/** 
 * @file xmlccDomRoot.h
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

#ifndef __xmlccDomRoot_h__
#define __xmlccDomRoot_h__

/******************************************************************************/

#include "./xmlccDomNode.h" // base class DOM::Node represents any XML node

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Root_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Root_
#endif

/******************************************************************************/

class Root: public Node {
  public:

    Root( void ); /// constructor
    Root( Str fileName ); /// set a file name

    Root( Str fileName, Node* header ); /// add a header

    Root( Str fileName, Node* header, Element* rootElement ); /// add also the single XML root element

    Root( Str fileName, Node* header, Comment*, Element* rootElement ); /// add one comment

    Root( Str fileName, Node* header, Comment*, Comment*,
        Element* rootElement ); /// add two comments

    Root( Str fileName, Node* header, Comment*, Comment*, Comment*,
        Element* rootElement ); /// add three comments

    Root( Str fileName, Node* header, Comment*, Comment*, Comment*, Comment*,
        Element* rootElement ); /// add four comments

    Root( Str fileName, Node* header, Comment*, Comment*, Comment*, Comment*,
        Comment*, Element* rootElement ); /// add five comments

    virtual ~Root( void ); /// destructor

    Str getFileName( void ); /// returns the stored file name of this root
    void setFileName( Str fileName ); /// sets the file name of this root

    friend std::ostream& operator <<( std::ostream& s, Root* node );

};
// class Root

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomRoot_h__
