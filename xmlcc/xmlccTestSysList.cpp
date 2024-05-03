/** 
 * @file xmlccTestSysList.cpp
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2024 Christian (graetz23@gmail.com)
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

#include "xmlccTestSysList.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
List::List( std::string name ) {

  _name = name;

} // List

/// destructor
List::~List( void ) {

} // ~List

/******************************************************************************/

void // inherit method for all unit tests using assert methods
List::run( void ) {

  Str tag = "";

  // /// //// DOUBLE //// /// //
  int ext = 1000;
  SYS::List< double >* list = new SYS::List< double >( ext );

  int size = 10 + 10 * ext;

  for( int d = 0; d < size; d++ ) // test add( )
    list->add( (double)( d + 1 ) );

  list->opt( ); // test opt( )

  double res = 0;

  size = list->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    res = list->get( d );
    if( res != (double)( d + 1 ) )
      throw SYS::Failure( "XMLCC::TEST:: SYS::List<T>::add( ) - failed" );
  } // for d

  double* dArr = list->arr( ); // test arr ( );
  size = list->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test arr[ ]
    res = dArr[ d ];
    if( res != (double)( d + 1 ) )
      throw SYS::Failure( "XMLCC::TEST:: SYS::List<T>::arr( ) - failed" );
  } // for d
  delete[ ] dArr;

  size = list->size( ); // test size( )
  for( int d = 0; d < size; d++ )  // test set( )
    list->set( d, (double)( d + 2 ) );

  size = list->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    res = list->get( d );
    if( res != (double)( d + 2 ) )
      throw SYS::Failure( "XMLCC::TEST:: SYS::List<T>::set( ) - failed" );
  } // for d

  size = list->size( ); // test size( )
  for( int d = 0; d < size; d++ )  // test set( )
    list->set( d, (double)( d + 1 ) );

  list->ins( 100, 23. ); // test ins( )
  int sizeIns = list->size( );
  if( sizeIns != size + 1 )
    throw SYS::Failure(
      "XMLCC::TEST:: SYS::List<T>::ins( ) - failed by size( )" );
  for( int d = 0; d < sizeIns; d++ ) {  // test get( )
    res = list->get( d );
    if( d == 100 )
      if( res != 23. )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - failed by value" );
    if( d < 100 ) {
      if( res != (double)( d + 1 ) ) {
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - failed before value" );
      } else if( d > 100 ) {
        if( res != (double)( d ) ) {
          throw SYS::Failure(
            "XMLCC::TEST:: SYS::List<T>::ins( ) - failed after value" );
        } // wrong result
      } // d > 100
    } // d < 100
  } // for d

  list->opt( 100 ); // test opt( ext )

  delete list;
  // /// //// DOUBLE //// /// //

  /****************************************************************************/

  // /// //// DUMMY //// /// //
  ext = 1000;
  SYS::List< Dummy >* listDummy = new SYS::List< Dummy >( ext );

  size = 10 + 10 * ext;

  for( int d = 0; d < size; d++ ) { // test add( )
    Dummy dummy;
    dummy._val = (double)( d + 1 );
    listDummy->add( dummy );
  } // for d

  listDummy->opt( ); // test opt( )

  Dummy resDummy;

  size = listDummy->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    resDummy = listDummy->get( d );
    if( resDummy._val != (double)( d + 1 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::add( ) - Dummy - failed" );
  } // for d

  Dummy* dummyArr = listDummy->arr( ); // test arr ( );
  size = listDummy->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test arr[ ]
    resDummy = dummyArr[ d ];
    if( resDummy._val != (double)( d + 1 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::arr( ) - Dummy - failed" );
  } // for d
  delete[ ] dummyArr;

  size = listDummy->size( ); // test size( )
  for( int d = 0; d < size; d++ ) { // test set( )
    resDummy = listDummy->get( d );
    resDummy._val = (double)( d + 2 );
    listDummy->set( d, resDummy );
  } // for d

  size = listDummy->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    resDummy = listDummy->get( d );
    if( resDummy._val != (double)( d + 2 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::set( ) - Dummy - failed" );
  } // for d

  size = listDummy->size( ); // test size( )
  for( int d = 0; d < size; d++ ) { // test set( )
    resDummy = listDummy->get( d );
    resDummy._val = (double)( d + 1 );
    listDummy->set( d, resDummy );
  } // for d

  Dummy insDummy;
  insDummy._val = 0.;
  listDummy->ins( 100, insDummy ); // test ins( )
  sizeIns = listDummy->size( );
  if( sizeIns != size + 1 )
    throw SYS::Failure(
      "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy - failed by size( )" );
  for( int d = 0; d < sizeIns; d++ ) {  // test get( )
    resDummy = listDummy->get( d );
    if( d == 100 )
      if( resDummy._val != 0. )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy - failed by value" );
    if( d < 100 ) {
      if( resDummy._val != (double)( d + 1 ) )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy - failed before value" );
    } else if( d > 100 ) {
      if( resDummy._val != (double)( d ) )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy - failed after value" );
    } // if
  } // for d

  listDummy->opt( 100 ); // test opt( ext )

  delete listDummy;
  // /// //// DUMMY //// /// //

  /****************************************************************************/

  // /// //// DUMMY* //// /// //
  ext = 1000;
  SYS::List< Dummy* >* listDummyPtr = new SYS::List< Dummy* >( ext );

  size = 10 + 10 * ext;

  for( int d = 0; d < size; d++ ) { // test add( )
    Dummy* dummy = new Dummy( );
    dummy->_val = (double)( d + 1 );
    listDummyPtr->add( dummy );
  } // for d

  listDummyPtr->opt( ); // test opt( )

  Dummy* resDummyPtr;

  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    resDummyPtr = listDummyPtr->get( d );
    if( resDummyPtr->_val != (double)( d + 1 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::add( ) - Dummy* - failed" );
  } // for d

  Dummy** dummyPtrArr = listDummyPtr->arr( ); // test arr ( );
  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test arr[ ]
    resDummyPtr = dummyPtrArr[ d ];
    if( resDummyPtr->_val != (double)( d + 1 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::arr( ) - Dummy* - failed" );
  } // for d
  delete[ ] dummyPtrArr;

  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) { // test set( )
    resDummyPtr = listDummyPtr->get( d );
    resDummyPtr->_val = (double)( d + 2 );
    listDummyPtr->set( d, resDummyPtr );
  } // for d

  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) {  // test get( )
    resDummyPtr = listDummyPtr->get( d );
    if( resDummyPtr->_val != (double)( d + 2 ) )
      throw SYS::Failure(
        "XMLCC::TEST:: SYS::List<T>::set( ) - Dummy* - failed" );
  } // for d

  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) { // test set( )
    resDummyPtr = listDummyPtr->get( d );
    resDummyPtr->_val = (double)( d + 1 );
    listDummyPtr->set( d, resDummyPtr );
  } // for d

  Dummy* insDummyPtr = new Dummy( );
  insDummyPtr->_val = 0.;
  listDummyPtr->ins( 100, insDummyPtr ); // test ins( )
  sizeIns = listDummyPtr->size( );
  if( sizeIns != size + 1 )
    throw SYS::Failure(
      "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy* - failed by size( )" );
  for( int d = 0; d < sizeIns; d++ ) {  // test get( )
    resDummyPtr = listDummyPtr->get( d );
    if( d == 100 )
      if( resDummyPtr->_val != 0. )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy* - failed by value" );
    if( d < 100 ) {
      if( resDummyPtr->_val != (double)( d + 1 ) )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy* - failed before value" );
    } else if( d > 100 ) {
      if( resDummyPtr->_val != (double)( d ) )
        throw SYS::Failure(
          "XMLCC::TEST:: SYS::List<T>::ins( ) - Dummy* - failed after value" );
    } // if
  } // for d

  listDummyPtr->opt( 100 ); // test opt( ext )

  size = listDummyPtr->size( ); // test size( )
  for( int d = 0; d < size; d++ ) // test get( )
    delete listDummyPtr->get( d ); // do not forget to delete
  delete listDummyPtr;
  // /// //// DUMMY* //// /// //

} // List::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
