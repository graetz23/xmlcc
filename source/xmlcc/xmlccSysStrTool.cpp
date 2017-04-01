/** 
 * @file xmlccSysStrTool.cpp
 * @author Christian Scheiblich
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

#include <stdlib.h> // atoi(), atof(), ...
#include "./xmlccSysStrTool.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
StrTool::StrTool( void ) {
} // StrTool

/// destructor
StrTool::~StrTool( void ) {
} // ~StrTool

/******************************************************************************/

Str // remove \ \n\t\r from left and right to first letter or number in string
StrTool::trimS( Str str ) {
  str = trimS2L( str );
  str = trimS2R( str );
  return str;
} // StrTool::trimS

Str // remove \ \n\t\r from left to first letter or number in string
StrTool::trimS2L( Str str ) {
  size_t i = 0;
  while( ( ( str[ i ] == ' ' ) || ( str[ i ] == '\t' ) || ( str[ i ] == '\r' )
           || ( str[ i ] == '\n' ) )
         && ( i < str.length( ) ) ) {
    i++;
  } // while
  return str.substr( i, str.length( ) );
} // StrTool::trimS2L

Str // remove \ \n\t\r from right to first letter or number in string
StrTool::trimS2R( Str str ) {
  if( str.length( ) > 0 ) {
    size_t i = str.length( ) - 1;
    while( ( ( str[ i ] == ' ' ) || ( str[ i ] == '\t' ) || ( str[ i ] == '\r' )
             || ( str[ i ] == '\n' ) )
           && ( ( (int)i ) >= 0 ) ) {
      i--;
    } // while
    return str.substr( 0, i + 1 );
  } else
    return str;
} // StrTool::trimS2R

/******************************************************************************/

Str // remove more white spaces followed by white spaces
StrTool::filterWs( Str str ) {
  bool foundW = false;
  Str s = "";
  for( Str::iterator i = str.begin( ); i != str.end( ); i++ ) {
    char c = *i; // actual char
    if( c == ' ' && !foundW ) {
      s += c;
      foundW = true;
    }
    if( !foundW )
      s += c;
    if( c != ' ' && foundW ) {
      s += c;
      foundW = false;
    }
  } // for
  return s;
} // StrTool::filterWs

/******************************************************************************/

Str // remove more tabulators and replace with whitespace
StrTool::filterTs( Str str ) {
  Str s = "";
  for( Str::iterator i = str.begin( ); i != str.end( ); i++ ) {
    char c = *i; // actual char
    if( c == '\t' ) {
      s += ' ';
      s += ' ';
    } else {
      s += c;
    } // if tab
  } // for i
  return s;
} // StrTool::filterTs

/******************************************************************************/

Str // filter break lines to white spaces
StrTool::filterBs( Str str ) {
  Str s = "";
  for( Str::iterator i = str.begin( ); i != str.end( ); i++ ) {
    char c = *i; // actual char
    if( c == '\n' || c == '\r' ) {
      s += ' ';
    } else {
      s += c;
    } // if break lines
  } // for i
  return s;
} // StrTool::filterBs

/******************************************************************************/

std::vector< Str > // split by white spaces to std::vector
StrTool::splitS2Ws( Str str ) {

  std::vector< Str > strList;

  bool found = false;
  char lC = ' '; // set to whitespace at last
  Str s = ""; // empty string
  for( Str::iterator i = str.begin( ); i != str.end( ); i++ ) {

    char c = *i; // actual char

    if( c != ' ' )
      s += c;

    if( c == ' ' && lC != ' ' ) // initial: '  '
      found = true;

    if( i == str.end( ) - 1 )
      found = true;

    if( found ) {
      strList.push_back( s ); // worse case: '< tag alt1 = " 1 " / >'
      s.clear( ); // empty temp string
      found = false;
    } // found true

    lC = c; // last char for detecting multiple white spaces

  } // for i

  return strList;

} // StrTool::splitS2Ws

/******************************************************************************/

Str // lower all letters in string
StrTool::doS2low( Str str ) {
  for( size_t s = 0; s < str.length( ); s++ )
    str[ s ] = (char)tolower( str[ s ] );
  return str;
} // StrTool::doS2low

Str // upper all letters in string
StrTool::doS2up( Str str ) {
  for( size_t s = 0; s < str.length( ); s++ )
    str[ s ] = (char)toupper( str[ s ] );
  return str;
} // StrTool::doS2up

/******************************************************************************/

Str // convert integer to string
StrTool::doI2S( int value ) {
  std::ostringstream stream;
  stream << value;
  return stream.str( );
} // StrTool::doI2S

Str // convert long to string
StrTool::doL2S( long value ) {
  std::ostringstream stream;
  stream << value;
  return stream.str( );
} // StrTool::doL2S

Str // convert bool to string
StrTool::doB2S( bool value ) {
  std::ostringstream stream;
  if( value )
    stream << "TRUE";
  else
    stream << "FALSE";
  return stream.str( );
} // StrTool::doB2S

Str // convert float to string
StrTool::doF2S( float value ) {
  std::ostringstream stream;
  stream << value;
  return stream.str( );
} // StrTool::doF2S

Str // convert double to string
StrTool::doD2S( double value ) {
  std::ostringstream stream;
  stream << value;
  return stream.str( );
} // StrTool::doD2S

/******************************************************************************/

int // convert string to integer
StrTool::doS2I( Str str ) {
  return (int)( atoi( (char*)str.c_str( ) ) );
} // StrTool::doS2I

long // convert string to long
StrTool::doS2L( Str str ) {
  return (long)( atoi( (char*)str.c_str( ) ) );
} // StrTool::doS2L

bool // convert char to bool; positive pattern oriented
StrTool::doS2B( Str str ) {
  str = doS2low( str );
  if( str.compare( "true" ) == 0 )
    return true;
  else if( str.compare( "false" ) == 0 )
    return false;
  else if( str.compare( "1" ) == 0 )
    return true;
  else if( str.compare( "0" ) == 0 )
    return false;
  else if( str.compare( "y" ) == 0 )
    return true;
  else if( str.compare( "j" ) == 0 )
    return true;
  else if( str.compare( "n" ) == 0 )
    return false;
  else if( str.compare( "yes" ) == 0 )
    return true;
  else if( str.compare( "no" ) == 0 )
    return false;
  else if( str.compare( "ok" ) == 0 )
    return true;
  else if( str.compare( "ja" ) == 0 )
    return true;
  else if( str.compare( "okay" ) == 0 )
    return true;
  else if( str.compare( "nope" ) == 0 )
    return false;
  else if( str.compare( "done" ) == 0 )
    return true;
  else if( str.compare( "good" ) == 0 )
    return true;
  else if( str.compare( "fine" ) == 0 )
    return true;
  else if( str.compare( "bad" ) == 0 )
    return false;
  else if( str.compare( "ready" ) == 0 )
    return true;
  else
    throw Failure( "SYS::StrTool::doS2B - given string is not verifiable!" );
} // StrTool::doS2B

float // convert string to float
StrTool::doS2F( Str str ) {
  return (float)( atof( (char*)str.c_str( ) ) );
} // StrTool::doS2F

double // convert string to double
StrTool::doS2D( Str str ) {
  return (double)( atof( (char*)str.c_str( ) ) );
} // StrTool::doS2D

/******************************************************************************/

bool // check string for containing only standard characters
StrTool::checkS2Std( Str str ) {
  for( size_t i = 0; i < str.length( ); i++ )
    if( str[ i ] < 0x20 || str[ i ] > 0x7E )
      return false;
  return true;
} // StrTool::checkS2Std

/******************************************************************************/

bool // check string for containing white spaces
StrTool::checkS2Ws( Str str ) {
  for( size_t i = 0; i < str.length( ); i++ )
    if( str[ i ] == ' ' )
      return true;
  return false;
} // StrTool::checkS2W

/******************************************************************************/

bool /// check string for containing only white spaces
StrTool::checkS2WsOnly( Str str ) {
  for( size_t i = 0; i < str.length( ); i++ )
    if( str[ i ] != ' ' )
      return false;
  return true;
} // StrTool::checkS2WsOnly

/******************************************************************************/

bool // if both are the same ->; case sensitive
StrTool::compareS2S( Str str1, Str str2 ) {

  bool areSame = false;

  int i = str1.compare( str2 );

  if( i == 0 )
    areSame = true;

  return areSame;

} // StrTool::compareS2S

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
