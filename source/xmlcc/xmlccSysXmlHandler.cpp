/** 
 * @file xmlccSysXmlHandler.cpp
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

#include "./xmlccSysXmlHandler.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
XmlHandler::XmlHandler( void ) {

  _isTalking = true; // std::cout or throw an exception if this is used

} // XmlHandler

/// constructor
XmlHandler::XmlHandler( bool isTalking ) {

  _isTalking = isTalking; // std::cout or throw an exception if this is used

} // XmlHandler

/// destructor
XmlHandler::~XmlHandler( void ) {
} // ~XmlHandler

/******************************************************************************/

void // called before reading document
XmlHandler::startDoc( void ) {

  if( _isTalking ) {
    std::cout << std::endl << std::endl << std::flush;
    std::cout << "XMLCC::SYS::XmlParser starts reading document" << std::endl
      << std::flush;
  } else {
    throw Failure( "SYS::XmlHandler - do not use base handler class" );
  } // if _istalking

} // XmlHandler::startDocument

/******************************************************************************/

void // called for each starting XML tag
XmlHandler::startTag( Str tag ) {

  if( _isTalking )
    std::cout << tag << std::endl << std::flush;
  else
    throw Failure( "SYS::XmlHandler - do not use base handler class" );

} // XmlHandler::startNode

/******************************************************************************/

void // called for each text value in XML
XmlHandler::characters( Str txt ) {

  if( _isTalking )
    std::cout << txt << std::endl << std::flush;
  else
    throw Failure( "SYS::XmlHandler - do not use base handler class" );

} // XmlHandler::characters

/******************************************************************************/

void // called for each ending XML tag
XmlHandler::endTag( Str tag ) {

  if( _isTalking )
    std::cout << tag << std::endl << std::flush;
  else
    throw Failure( "SYS::XmlHandler - do not use base handler class" );

} // XmlHandler::endNode

/******************************************************************************/

void // called after reading document
XmlHandler::endDoc( void ) {

  if( _isTalking ) {
    std::cout << "XMLCC::SYS::XmlParser ends reading document" << std::flush;
    std::cout << std::endl << std::endl << std::flush;
  } else {
    throw Failure( "SYS::XmlHandler - do not use base handler class" );
  } // if _istalking

} // XmlHandler::endDocument

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
