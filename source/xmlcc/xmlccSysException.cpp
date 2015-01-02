/** 
 * @file xmlccSysException.cpp
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

#include "./xmlccSysException.h"

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

// constructor
Exception::Exception( void ) {
  mark( );
} // Exception::Exception

// constructor overloaded
Exception::Exception( Str message ) : _message( message ) { 
  mark( );
} // Exception::Exception

// use __LINE__ @ lineNo
Exception::Exception( Str message, int lineNo ) {
  std::ostringstream lineNoStream;
  lineNoStream << lineNo;
  _message = "line: ";
  _message.append( lineNoStream.str( ) );
  _message.append( " " );
  _message.append( message );
  mark( );
} // Exception::Exception

// use __FILE__ @ fileName
Exception::Exception( Str message, char* fileName ) {
  _message = "file: ";
  _message.append( fileName );
  _message.append( " " );
  _message.append( message );
  mark( );
} // Exception::Exception

// use __FILE__ @ fileName and __LINE__ @ lineNo
Exception::Exception( Str message, char* fileName, int lineNo ) {
  std::ostringstream lineNoStream;
  lineNoStream << lineNo;
  _message = "file: ";
  _message.append( fileName );
  _message.append( " in line: " );
  _message.append( lineNoStream.str( ) );
  _message.append( " - " );
  _message.append( message );
  mark( );
} // Exception::Exception

// destructor
Exception::~Exception( void ) {
} // Exception::~Exception

/******************************************************************************/

Str // returns message
Exception::declare( void ) const {
  return _message;
} // Exception::declare

void // message to console
Exception::report( void ) const {
  std::cout << _message << std::endl << std::flush;
} // Exception::report

void // message to console and stop
Exception::stop( void ) const {
  report( );
  std::cin.get( );
} // Exception::stop

/******************************************************************************/

void // do a nuke
Exception::nuke( void ) const {
  std::cout << std::endl << std::flush;
  std::cout << "                  ____             " << std::endl << std::flush;
  std::cout << "          __,-~~/~    `---.        " << std::endl << std::flush;
  std::cout << "        _/_,---(      ,    )       " << std::endl << std::flush;
  std::cout << "    __ /        NUKED     ) \\ __  " << std::endl << std::flush;
  std::cout << "   ====------------------===;;;==  " << std::endl << std::flush;
  std::cout << "      /  ~\"~\"~\"~\"~\"~~\"~)     " << std::endl << std::flush;
  std::cout << "      (_ (      (     >    \\)     " << std::endl << std::flush;
  std::cout << "       \\_( _ <         >_>\'      " << std::endl << std::flush;
  std::cout << "           ~ `-i' ::>|--\"         " << std::endl << std::flush;
  std::cout << "               I;|.|.|             " << std::endl << std::flush;
  std::cout << "              <|i::|i|>            " << std::endl << std::flush;
  std::cout << "               |[::|.|             " << std::endl << std::flush;
  std::cout << "                ||: |              " << std::endl << std::flush;
  std::cout << std::endl << std::flush;
} // Exception::nuke

/******************************************************************************/

std::ostream& // for std::cout
operator << ( std::ostream& s, Exception& e ) {
  s << e._message << std::endl << std::flush;
  return s;
} // Exception::operator << 

std::ostream& // for std::cout
operator << ( std::ostream& s, Exception* e ) {
  s << e->_message << std::endl << std::flush;
  return s;
} // Exception::operator << 

/******************************************************************************/

void // mark exception
Exception::mark( void ) {
  Str tmp = "XMLCC::Exception::";
  tmp.append( _message );
  _message = tmp;
} // Exception::mark

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
