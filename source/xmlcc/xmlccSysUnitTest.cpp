/** 
 * @file xmlccSysUnitTest.cpp
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

#include <stdlib.h> // atoi(), atof(), ...
#include "./xmlccSysUnitTest.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
UnitTest::UnitTest( void ) {

  _strTool = new StrTool( );

  _name = "UnitTest";

  _actualBool = true; /// member for easy usage in objects
  _expectedBool = false; /// member for easy usage in objects
  _actualInt = 1; /// member for easy usage in objects
  _expectedInt = 0; /// member for easy usage in objects
  _actualLong = 1; /// member for easy usage in objects
  _expectedLong = 0; /// member for easy usage in objects
  _actualDouble = 1.; /// member for easy usage in objects
  _expectedDouble = 0.; /// member for easy usage in objects
  _actualStr = "foo"; /// member for easy usage in objects
  _expectedStr = "bar"; /// member for easy usage in objects

} // UnitTest

/******************************************************************************/

/// name of unit test, set by constructor
UnitTest::UnitTest( Str name ) {

  _strTool = new StrTool( );

  _name = name; // name of unit test
  _actualBool = true; /// member for easy using in objects
  _expectedBool = false; /// member for easy using in objects
  _actualInt = 1; /// member for easy using in objects
  _expectedInt = 0; /// member for easy using in objects
  _actualLong = 1; /// member for easy using in objects
  _expectedLong = 0; /// member for easy using in objects
  _actualDouble = 1.; /// member for easy using in objects
  _expectedDouble = 0.; /// member for easy using in objects
  _actualStr = "foo"; /// member for easy using in objects
  _expectedStr = "bar"; /// member for easy using in objects

} // UnitTest

/******************************************************************************/

/// destructor
UnitTest::~UnitTest( void ) {

  delete _strTool;

} // ~UnitTest

/******************************************************************************/
void /// method should be over written by inheriting class
UnitTest::run( void ) {

  int expected = 1;
  int actual = 1;
  assertEquals( expected, actual ); // throws UnitExceptions

  fail( ); // fail test at the end to mark the unit test run of base UnitTest

} // UnitTest::run

/******************************************************************************/

Str /// returns the set name of the unit test
UnitTest::tell( void ) {

  return _name;

} // UnitTest::tell

/******************************************************************************/

void // assert (always) with no message
UnitTest::fail( void ) {

  throw Error( "SYS::UnitTest::fail() ~8>" ); // throw an exception that's all

} // UnitTest::fail

/******************************************************************************/

void // assert if pointer or object is null
UnitTest::assertNull( void* pointer ) {

  if( pointer == 0 )
    throw Failure( "SYS::UnitTest::assertNull() - pointer is null" );

} // UnitTest::assertNull

/******************************************************************************/

void // assert if condition is true
UnitTest::assertTrue( bool condition ) {

  if( condition )
    throw Failure( "SYS::UnitTest::assertTrue() - condition is false" );

} // UnitTest::assertTrue

/******************************************************************************/

void // assert if condition is false
UnitTest::assertFalse( bool condition ) {

  if( !condition )
    throw Failure( "SYS::UnitTest::assertFalse() - condition is true" );

} // UnitTest::assertFalse

/******************************************************************************/

void // assert if integers are not equal
UnitTest::assertEquals( int expected, int actual ) {

  if( expected != actual ) {

    Str msg;
    msg.append( "SYS::UnitTest::assertEquals() - " );
    msg.append( "expected: " );
    msg.append( _strTool->doI2S( expected ) );
    msg.append( " " );
    msg.append( "actual: " );
    msg.append( _strTool->doI2S( actual ) );
    throw Failure( msg );

  } // if

} // UnitTest::assertEquals

/******************************************************************************/

void // assert if longs are not equal
UnitTest::assertEquals( long expected, long actual ) {

  if( expected != actual ) {

    Str msg;
    msg.append( "SYS::UnitTest::assertEquals() - " );
    msg.append( "expected: " );
    msg.append( _strTool->doL2S( expected ) );
    msg.append( " " );
    msg.append( "actual: " );
    msg.append( _strTool->doL2S( actual ) );
    throw Failure( msg );

  } // if

} // UnitTest::assertEquals

/******************************************************************************/

void // assert if doubles are not equal
UnitTest::assertEquals( double expected, double actual ) {

  if( expected != actual ) {

    Str msg;
    msg.append( "SYS::UnitTest::assertEquals() - " );
    msg.append( "expected: " );
    msg.append( _strTool->doD2S( expected ) );
    msg.append( " " );
    msg.append( "actual: " );
    msg.append( _strTool->doD2S( actual ) );
    throw Failure( msg );

  } // if

} // UnitTest::assertEquals

/******************************************************************************/

void // assert if doubles are not of equal precision
UnitTest::assertEquals( double expected, double actual, double delta ) {

  double diff = 0.; // difference of expected and actual

  diff = expected - actual;

  if( diff < 0. ) // go for the magnitude
    diff *= -1.;

  if( delta < 0. ) // go for the magnitude
    delta *= -1;

  if( diff > delta ) { // throw if difference is stiller taller than delta

    Str msg;
    msg.append( "SYS::UnitTest::assertEquals() - " );
    msg.append( "expected: " );
    msg.append( _strTool->doD2S( expected ) );
    msg.append( " " );
    msg.append( "actual: " );
    msg.append( _strTool->doD2S( actual ) );
    msg.append( " " );
    msg.append( "delta: " );
    msg.append( _strTool->doD2S( delta ) );
    msg.append( " " );
    msg.append( "difference: " );
    msg.append( _strTool->doD2S( diff ) );
    throw Failure( msg );

  } // if

} // UnitTest::assertEquals

/******************************************************************************/

void UnitTest::assertEquals( Str expected, Str actual ) {

  int s = expected.compare( actual );

  if( s != 0 ) {

    Str msg;
    msg.append( "SYS::UnitTest::assertEquals()" );
    msg.append( "\n" );
    msg.append( "expected:'" );
    msg.append( expected );
    msg.append( "' " );
    msg.append( "actual:'" );
    msg.append( actual );
    msg.append( "'!" );
    throw Failure( msg );

  } // if

} // UnitTest::assertEquals

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
