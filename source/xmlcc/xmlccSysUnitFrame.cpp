/** 
 * @file xmlccSysUnitFrame.cpp
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

#include <cstdlib> // std::exit( 0 )
#include "./xmlccSysUnitFrame.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
UnitFrame::UnitFrame( void ) {

  _unitTestList = new List< UnitTest* >( 100 );

} // UnitFrame

/// destructor
UnitFrame::~UnitFrame( void ) {

  int noOfUnitTests = _unitTestList->size( );
  for( int u = 0; u < noOfUnitTests; u++ ) {

    UnitTest* unitTest = _unitTestList->get( u );

    if( unitTest != 0 )
      delete unitTest; // delete objects

  } // loop and delete all registered unit tests

  delete _unitTestList;

} // ~UnitFrame

/******************************************************************************/

void // register a unit test object
UnitFrame::add( UnitTest* unitTest ) {

  if( unitTest != 0 )
    _unitTestList->add( unitTest );

} // UnitFrame::add

/******************************************************************************/

void // run all registered unit tests; UnitTest objects
UnitFrame::run( void ) {

  UnitTest* unitTest = 0;

  try { // run all registered unit tests and tell about console

    int noOfUnitTests = _unitTestList->size( );
    for( int u = 0; u < noOfUnitTests; u++ ) {
      std::cout << "SYS::UnitFrame:: testing => " << std::flush;
      unitTest = _unitTestList->get( u );
      std::cout << unitTest->tell( ) << " .. " << std::flush;
      unitTest->run( ); // inherit unit test method
      std::cout << "done!" << std::endl << std::flush;
    } // loop and run all registered unit tests
    std::cout << std::endl << std::flush;

  } catch( Error& e ) {
    std::cout << "not passed - caught Error!" << std::endl << std::flush;
    std::cout << unitTest->tell( ) << std::endl << std::flush;
    std::cout << e.declare( ) << std::endl << std::flush;
    std::exit( 0 ); // break down program
  } catch( Failure& f ) {
    std::cout << "not passed - caught Failure!" << std::endl << std::flush;
    std::cout << unitTest->tell( ) << std::endl << std::flush;
    std::cout << f.declare( ) << std::endl << std::flush;
    std::exit( 0 ); // break down program
  } catch( Exception& e ) {
    std::cout << "not passed - caught Exception!" << std::endl << std::flush;
    std::cout << unitTest->tell( ) << std::endl << std::flush;
    std::cout << e.declare( ) << std::endl << std::flush;
    std::exit( 0 ); // break down program
  } catch( std::exception& e ) { // standard exception class
    std::cout << "not passed - caught std:exception!" << std::endl
      << std::flush;
    std::cout << unitTest->tell( ) << " == " << std::endl << std::flush;
    std::cout << e.what( ) << std::endl << std::flush;
    std::exit( 0 ); // break down program
  } catch( ... ) { // any other exception thrown
    std::cout << "not passed - caught unknown exception!" << std::endl
      << std::flush;
    std::cout << "SYS::UnitFrame - unknown exception caught:" << std::endl
      << std::flush;
    std::exit( 0 ); // break down program
  } // try

} // UnitFrame::run

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
