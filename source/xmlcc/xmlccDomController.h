/** 
 * @file xmlccController.h
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

#ifndef __xmlccController_h__
#define __xmlccController_h__

/******************************************************************************/

#include "./xmlccDomTypes.h"     // an DOM::Types
#include "./xmlccDomRoot.h"      // an DOM::Root node
#include "./xmlccDomHeader.h"    // an DOM::Header node
#include "./xmlccDomElement.h"   // an DOM::Element node
#include "./xmlccDomAttribute.h" // an DOM::Attribute node
#include "./xmlccDomValue.h"     // an DOM::Value node
#include "./xmlccDomComment.h"   // an DOM::Comment node
#include "./xmlccDomCData.h"     // an DOM::CDATA node
#include "./xmlccDomDoctype.h"   // an DOM::DOCTYPE node

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Controller_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Controller_
#endif

/******************************************************************************/

class /// class for building objects
Controller {
  public:

    Controller( void ); /// constructor
    virtual ~Controller( void ); /// destructor

    /**************************************************************************/

    Node* getElement( Node* node, Str strElement ); /// return DOM::Element stored at Node* by name or a null pointer
    Node* getAttribute( Node* node, Str strAttribute ); /// return DOM::Attribute stored at Node* by name or a null pointer

    /**************************************************************************/

    Root* createRoot( void ); /// XMLCC root, representing the file
    Root* createRoot( Str fileName ); /// XMLCC root, representing the file

    /**************************************************************************/

    Node* createHeader( void ); /// an XML header with standard attributes
    Node* createDoctype( void ); /// a HTML DOCTYPE header with std attributes

    /**************************************************************************/

    Node* create( Types::Type type, Str tag ); /// new node of any type
    Node* create( Types::Type type, Str tag, Str value ); /// new node of type 'Element with Value' or 'Attribute with value'

    /**************************************************************************/

    Node* create( Types::Type type, Str tag, Node* leaf ); /// create a new node and add the passed Node* to new Node*
    Node* create( Types::Type type, Str tag, Str value, Node* leaf ); /// create a new node with value and add the passed Node* to the new Node*
    void create( Node* root, Types::Type type, Str tag ); /// create a new node and add it to the passed Node*
    void create( Node* root, Types::Type type, Str tag, Str value ); /// create a new node with value and add it to the passed Node*

    /**************************************************************************/

    int getNoOfHeaders( Node* node ); /// get number of DOM::Header stored at handed node; is not recursive!
    int getNoOfDoctypes( Node* node ); /// get number of DOM::Doctype stored at handed node; is not recursive!
    int getNoOfComments( Node* node ); /// get number of DOM::Comment stored at handed node; is not recursive!
    int getNoOfElements( Node* node ); /// get number of DOM::Element stored at handed node; is not recursive!
    int getNoOfAttributes( Node* node ); /// get number of DOM::Attribute stored at handed node; is not recursive!
    int getNoOfValues( Node* node ); /// get number of DOM::Value stored at handed node; is not recursive!
    int getNoOfCData( Node* node ); /// get number of DOM::CData stored at handed node; is not recursive!

    /**************************************************************************/

    void genArrOfHeaders( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Header of Node* - not recursive!
    void genArrOfDoctypes( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Doctype of Node* - not recursive!
    void genArrOfComments( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Comment of Node* - not recursive!
    void genArrOfElements( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Element of Node* - not recursive!
    void genArrOfAttributes( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Attribute of Node* - not recursive!
    void genArrOfValues( int& size, Node**& arr, Node* node ); /// generate array with all DOM::Value of Node* - not recursive!
    void genArrOfCData( int& size, Node**& arr, Node* node ); /// generate array with all DOM::CData of Node* - not recursive!

    /**************************************************************************/

    NodeList* genListOfComments( Node* node ); /// all DOM::Comment of Node* in NodeList* or empty nodeList; no = 0
    NodeList* genListOfElements( Node* node ); /// all DOM::Element of Node* in NodeList* or empty nodeList; no = 0
    NodeList* genListOfAttributes( Node* node ); /// all DOM::Attribute of Node* in NodeList* or empty nodeList; no = 0
    NodeList* genListOfValues( Node* node ); /// all DOM::Value of Node* in NodeList* or empty nodeList; no = 0
    NodeList* genListOfCData( Node* node ); /// all DOM::CData of Node* in NodeList* or empty nodeList; no = 0

    /**************************************************************************/

    StrList* genStrListOfComments( Node* node ); /// generates a StrList* all strings of DOM::Comment stored at Node*
    StrList* genStrListOfElements( Node* node ); /// generates a StrList* all strings of DOM::Element stored at Node*
    StrList* genStrListOfAttributes( Node* node ); /// generates a StrList* all strings of DOM::Attribute stored at Node*
    StrList* genStrListOfValues( Node* node ); /// generates a StrList* all strings of DOM::Value stored at Node*
    StrList* genStrListOfCData( Node* node ); /// generates a StrList* all strings of DOM::CData stored at Node*

    /**************************************************************************/

    Node* getFirstHeader( Node* node ); /// return first DOM::Header stored at Node* or a null pointer
    Node* getFirstDoctype( Node* node ); /// return first DOM::Doctype stored at Node* or a null pointer
    Node* getFirstComment( Node* node ); /// return first DOM::Comment stored at Node* or a null pointer
    Node* getFirstElement( Node* node ); /// return first DOM::Element stored at Node* or a null pointer
    Node* getFirstAttribute( Node* node ); /// return first DOM::Attribute stored at Node* or a null pointer
    Node* getFirstValue( Node* node ); /// return first DOM::Value stored at Node* or a null pointer
    Node* getFirstCData( Node* node ); /// return first DOM::CData stored at Node* or a null pointer

    /**************************************************************************/

    Str getStrOfFirstComment( Node* node ); /// returns string of FIRST DOM::Comment stored at Node*
    Str getStrOfFirstElement( Node* node ); /// returns string of FIRST DOM::Element stored at Node*
    Str getStrOfFirstAttribute( Node* node ); /// returns string of FIRST DOM::Attribute stored at Node*
    Str getStrOfFirstValue( Node* node ); /// returns string of FIRST DOM::Value stored at Node*
    Str getStrOfFirstCData( Node* node ); /// returns string of FIRST DOM::CData stored at Node*

    /**************************************************************************/

    Str getStrOfValueOfFirstAttribute( Node* node ); /// string of DOM::Value of first DOM::Attribute stored to Node*
    Str getStrOfValueOfAttribute( Node* node, Str strAttribute ); /// string of DOM::Value of selected DOM::Attribute stored to Node*

    /**************************************************************************/

    void view( Node* node ); /// print DOM tree to std::cout; without '\n'@end

    /**************************************************************************/

    void write( Root* root ); /// write XML file using file name in DOM::Root*
    void write( Str fileName, Node* node ); /// write any XML structure to drive

    /**************************************************************************/

    void erase( Node* node ); /// delete a given XML tag or DOM:: tree safely

    /**************************************************************************/

    bool isRoot( Node* obect ); /// true if is of type DOM::Root
    bool isHeader( Node* obect ); /// true if is of type DOM::Header
    bool isDoctype( Node* obect ); /// true if is of type DOM::Doctype
    bool isComment( Node* obect ); /// true if is of type DOM::Comment
    bool isElement( Node* obect ); /// true if is of type DOM::Element
    bool isAttribute( Node* obect ); /// true if is of type DOM::Attribute
    bool isValue( Node* obect ); /// true if is of type DOM::Value
    bool isCData( Node* obect ); /// true if is of type DOM::CData

    /**************************************************************************/

    SYS::StrTool _strTool; /// std::string manipulation
};
// class Controller

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomController_h__
