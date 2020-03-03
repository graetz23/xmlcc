/** 
 * @file xmlccDomNode.h
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2020 Christian (graetz23@gmail.com)
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

#ifndef __xmlccDomNode_h__
#define __xmlccDomNode_h__

/******************************************************************************/

#include "./xmlccSys.h"      // SYS::
#include "./xmlccDomTypes.h" // all XMLCC TYPES

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Node_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Node_
#endif

/******************************************************************************/

typedef Str Tag; // template & namespace typedef
typedef StrList TagList; // template & namespace typedef

/******************************************************************************/

// define derived class here
class Root;
class Header;
class Doctype;
class Comment;
class CData;
class Element;
class Attribute;
class Value;

/******************************************************************************/

class /// Composite Pattern Base class
Node {

    /**************************************************************************/

  protected:
    Node( Str tag ); /// constructor

    /**************************************************************************/

  public:
    virtual ~Node( void ); /// destructor

    /**************************************************************************/

    void setStr( Str string ); /// set string for an node
    Str getStr( void ); /// get string of an node

    /**************************************************************************/

    Tag getTag( void ); /// get XML tag as std::string; running recursively

    /**************************************************************************/

    void addNode( Node* leaf ); /// add leaf to this Node*

    /**************************************************************************/

    int getNoOfNodes( void ); /// get no of objects
    Node* getNode( int no ); /// get node of internal no
    Node** getNodes( void ); /// get all objects as an array; delete the array

    /**************************************************************************/

    int getIndentation( void ); /// get indentation for std::ostream
    void setIndentation( Node* node ); /// set indentation for std::ostream
    void incIndentation( Node* node ); /// increase indentation
    void decIndentation( Node* node ); /// decrease indentation
    void doIndentation( std::ostream& s ); /// add indentation to ostream

    /**************************************************************************/

    friend std::ostream& operator <<( std::ostream& s, Node* node ); /// stream

    /**************************************************************************/

  protected:

    Str _name; /// name of the current XMLCC node
    SYS::List< Node* >* _nodeList; /// list of current added objects
    int _indentation; /// indentation for ostream; number of leading whitespaces
    int _indentationSize; /// set the number of whitespaces for each indentation

    /**************************************************************************/

};
// class Node

/******************************************************************************/

typedef SYS::List< Node* > NodeList; // template & namespace typedef

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomNode_h__

/******************************************************************************/
