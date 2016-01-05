/** 
 * @file xmlccDomTokenizer.h
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

#ifndef __xmlccDomTokenizer_h__
#define __xmlccDomTokenizer_h__

/******************************************************************************/

#include "xmlccSys.h" // SYS::
#include "./xmlccDomController.h" // creating, modifying, and deleting elements

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Tokenizer_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Tokenizer_
#endif

/******************************************************************************/

class /// class converts strings keeping tags into objects of the DOM structure
Tokenizer {
  public:

    Tokenizer( void ); /// constructor
    virtual ~Tokenizer( void ); /// destructor

    Node* buildDomTreeOfTagList( TagList* tagList ); /// DOM tree

    Node* convert( Str tag ); /// convert XML tag or text 2 DOM Node*

  protected:

    Node* convertTag( Str tag ); /// convert a tag 2 node
    Node* convertTagComplete( Str tag ); /// convert a tag 2 node
    Node* convertValue( Str value ); /// convert a value 2 node

    bool check4Ending( Str tag ); /// check if tag is ending
    bool check4StandAlone( Str tag ); /// check if tag is standalone

    Node* convert2Node( Str line ); /// filter string and hand back objects
    Node* convert2NodeComplete( Str tag ); /// convert a tag 2 node

    Node* conv2Header( Str line ); /// convert header string to an node
    Node* conv2Comment( Str line ); /// convert comment string to an node
    Node* conv2Tag( Str line ); /// convert tag string to an node
    Node* conv2CData( Str line ); /// convert CDATA to an node
    Node* conv2Doctype( Str line );  /// convert DOCTYPE to an node

    NodeList* convAttAndValList( Str line ); /// get Strs: att="val"
    Node* conv2AttAndVal( Str line ); /// convert to attrib and value node
    Node* conv2Val( Str line ); /// convert a value string to an node

    Str getTag( Str line ); /// hand the tag back as string

    SYS::StrTool _strTool; /// string manipulation
    SYS::XmlTool _xmlTool; /// XML tags
    DOM::Controller _controller; /// creates Node* objects
};
// class Tokenizer

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomTokenizer_h__
