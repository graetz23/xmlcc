/** 
 * @file xmlccDomDoctype.h
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

#ifndef __xmlccDomDoctype_h__
#define __xmlccDomDoctype_h__

/******************************************************************************/

#include "./xmlccDomNode.h" // base class DOM::Node represents any XML node

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

#define _XMLCC_VERSION_DOM_Doctype_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_DOM_Doctype_
#endif

/******************************************************************************/

class Doctype: public Node {
  public:

    Doctype( void ); /// <!DOCTYPE html>

    Doctype( Str rootType ); /// <!DOCTYPE rootType>

    Doctype( Str rootType, Str sys, Str pathDtdFile ); /// sys -> SYSTEM "{file|url}.dtd"

    Doctype( Str rootType, Str pub, Str pathPubIdent, Str pathDtdFile ); /// pub -> PUBLIC "public identifier" "dtd"

    virtual ~Doctype( void ); /// destructor

    Str getDoctype( void ); /// returns the stored DOCTYPE
    void setDoctype( Str doctype ); /// sets the DOCTYPE

    Str getRootType( void ); /// returns the stored root type for document
    void setRootType( Str rootType ); /// sets the root type for document

    Str getSysOrPub( void ); /// returns the stored SYSTEM or PUBLIC
    void setSysOrPub( Str sysORpub ); /// sets the SYSTEM or PUBLIC

    Str getPathPublicIdentifier( void ); /// returns the stored public identifier
    void setPathPublicIdentifier( Str pubIdent ); /// sets the public identifier

    Str getPathDtdFile( void ); /// returns the stored path to DTD file
    void setPathDtdFile( Str dtdFile ); /// sets the path to DTD file

    friend std::ostream& operator <<( std::ostream& s, Doctype* node );

  protected:

    Str _rootType; /// "html" for example
    Str _sysORpub; /// "SYSTEM" or "PUBLIC" for example
    Str _pathPubIdent; /// "-//W3C//DTD XHTML 1.0 Strict//EN" for example
    Str _pathDtdFile; /// "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd"

};
// class Doctype

/******************************************************************************/

}// namespace DOM

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccDomDoctype_h__
