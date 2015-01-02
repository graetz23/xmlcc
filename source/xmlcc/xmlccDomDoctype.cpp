/** 
 * @file xmlccDomDoctype.cpp
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

#include "./xmlccDomDoctype.h" // header

/******************************************************************************/

namespace XMLCC {

namespace DOM {

/******************************************************************************/

/// <!DOCTYPE html>
Doctype::Doctype( void ) :
    Node( "DOCTYPE" ) {
  _rootType = "html";
} // Doctype::Doctype

/// <!DOCTYPE rootType>
Doctype::Doctype( Str rootType ) :
    Node( "DOCTYPE" ) {
  _rootType = rootType;
} // Doctype::Doctype

/// sys -> SYSTEM "{file|url}.dtd"
Doctype::Doctype( Str rootType, Str sys, Str pathDtdFile ) :
    Node( "DOCTYPE" ) {
  _rootType = rootType;
  _sysORpub = sys;
  _pathDtdFile = pathDtdFile;
} // Doctype::Doctype

/// pub -> PUBLIC "public identifier" "dtd"
Doctype::Doctype( Str rootType, Str pub, Str pathPubIdent, Str pathDtdFile ) :
    Node( "DOCTYPE" ) {
  _rootType = rootType;
  _sysORpub = pub;
  _pathPubIdent = pathPubIdent;
  _pathDtdFile = pathDtdFile;
} // Doctype::Doctype

/// destructor
Doctype::~Doctype( void ) {
} // ~Doctype

/******************************************************************************/

Str /// returns the stored DOCTYPE
Doctype::getDoctype( void ) {
  return getStr( );
} // Doctype::getDoctype

void /// sets the DOCTYPE
Doctype::setDoctype( Str doctype ) {
  setStr( doctype );
} // Doctype::setDoctype 

Str /// returns the stored root type for document
Doctype::getRootType( void ) {
  return _rootType;
} // Doctype::getRootType

void /// sets the root type for document
Doctype::setRootType( Str rootType ) {
  _rootType = rootType;
} // Doctype::setRootType 

Str /// returns the stored SYSTEM or PUBLIC
Doctype::getSysOrPub( void ) {
  return _sysORpub;
} // Doctype::getSysOrPub

void /// sets the SYSTEM or PUBLIC
Doctype::setSysOrPub( Str sysORpub ) {
  _sysORpub = sysORpub;
} // Doctype::setSysOrPub 

Str /// returns the stored public identifier
Doctype::getPathPublicIdentifier( void ) {
  return _pathPubIdent;
} // Doctype::getPathPublicIdentifier

void /// sets the public identifier
Doctype::setPathPublicIdentifier( Str pubIdent ) {
  _pathPubIdent = pubIdent;
} // Doctype::setPathPublicIdentifier 

Str /// returns the stored path to DTD file
Doctype::getPathDtdFile( void ) {
  return _pathDtdFile;
} // Doctype::getPathDtdFile

void /// sets the path to DTD file
Doctype::setPathDtdFile( Str dtdFile ) {
  _pathDtdFile = dtdFile;
} // Doctype::setPathDtdFile 

/******************************************************************************/

std::ostream& /// std::ostream
operator <<( std::ostream& s, Doctype* node ) {

  s << "<!" << node->getDoctype( ) << " " << node->getRootType( ) << std::flush;

  Str pathPubIdent = node->getPathPublicIdentifier( );
  if( pathPubIdent.compare( "" ) != 0 ) {
    s << " " << "\"" << node->getPathPublicIdentifier( ) << "\"" << std::flush;
  } // if public identifier exists

  Str pathDtdFile = node->getPathDtdFile( );
  if( pathDtdFile.compare( "" ) != 0 ) {
    s << " " << "\"" << node->getPathDtdFile( ) << "\"" << std::flush;
  } // if dtd file exists

  s << ">" << std::flush << std::endl;

  return s;

} // Node::operator <<

/******************************************************************************/

} // namespace DOM

} // namespace XMLCC

/******************************************************************************/
