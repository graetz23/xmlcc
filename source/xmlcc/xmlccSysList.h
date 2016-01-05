/** 
 * @file xmlccSysList.h
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2016 Christian Scheiblich (cscheiblich@gmail.com)
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

/*******************************************************************************
 * XMLCC::List<T> - template list for all kind of data types
 * remarks:
 * You can use this list for any kind of data; numbers, objects, pointers ...
 * It is not allocating memory until the first data is added using the
 * add( T data ) method. The allocated memory depends on the given
 * extension size, manifested by the member _ext. You can use the overloaded
 * constructor to manipulated this member from the start on. To get data, use
 * get( pos ) method for a single date or the arr( void ) method for all data;
 * the arr( void ) method is handing back a pointer array of the added data.
 * The List<T> is not deleting any data, e.g. stored objects. It is only
 * deleting itself when ~List<T>( void ) is called by delete myList.
 *******************************************************************************
 * CHANGE LOG
 * 2006 created and verified until 0.80
 * 20141218 0.80 added fst and lst methods for getting first and last data item
 * 20141224 1.00 cleaned out SYS:List<T> and implemented unit tests SYS::TEST::
 * 20150913 1.01 added and updated comments, changed in par() floor() 2 ceil().
 *
 ******************************************************************************/

#ifndef __xmlccSysList_h__
#define __xmlccSysList_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs
#include "./xmlccSysError.h" /// XMLCC's exception class for capital errors
#include "./xmlccSysFailure.h" /// XMLCC's exception class for failures

/******************************************************************************/

namespace XMLCC {

namespace SYS {

#define _XMLCC_VERSION_SYS_List_ 1.01 // 20150913
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_List_
#endif

/******************************************************************************/

template< class T >
class List { // use this to add any data in an array
  public:

    List( void ); /// constructor
    List( int ext ); /// give the allocate memory size
    List( int ext, int div ); /// allocated memory size and divisor for speed up
    virtual ~List( void ); /// destructor; virtual 2 be called when heritating

    int size( void ); /// return the size of the list
    void add( T data ); /// add a new data in the first free position
    void set( int pos, T data ); /// set data to position pos
    void ins( int pos, T data ); /// insert data to position pos
    T get( int pos ); /// return a copy of the data at position pos
    T fst( void ); /// return a copy of the data at first position
    T lst( void ); /// return a copy of the data at last position
    T* arr( void ); /// copies the list to an array and returns a pointer
    void par( void ); /// optimizes the memory extension parameters
    void opt( void ); /// optimizes the memory for added data
    void opt( int ext ); /// optimizes mem for added data by given extension

    // T     operator  [ ]   ( int n ) const; /// operator overloading

  private:

    void ext( int ext ); /// extend the allocated memory
    void shr( int pos ); /// shrink the memory to a new size

    T* _data; /// array for data 2 be added, will be extended automatically
    int _pos;  /// next position in allocated memory 4 sotring data 2 _data arr
    int _ext;  /// extension size for next memory allocation to extend _data arr
    int _div;  /// divisor for calculating self allocating memory size
    int _size; /// current size of allocated memory for array _data

};
// List<T>

/****************************************************************************/

template< class T > // constructor setting initial memory to 12 fields
List< T >::List( ) {

  _ext = 12; // memory optimized; reserve 12 places while first one is stored.
  _div = 4; // divider for the memory extension while 13th is stored => 14 total
  _pos = 0; // start position of the internal array; DO NOT CHANGE(!)
  _size = 0; // the current size of the array: 0, 12, 24, 36, 48, 60, 75, 94, ..
  _data = 0; // the pointer to (or array of) the stored data

} // List<T>::List

/****************************************************************************/

template< class T > // constructor setting initial memory to given integer ext
List< T >::List( int ext ) {

  if( ext < 1 )
    ext = 1; // 20081206 fix user failure instead of throwing an exception

  if( ext > 100000 )
    ext = 100000; // 20150913 fix user failure instead of throwing an exception

  _ext = ext; // set the size of the extension, between 1 and 100000
  _pos = 0; // start position of the internal array; DO NOT CHANGE(!)
  _div = 4; // divider for the memory extension while 13th is stored => 14 total
  _size = 0; // the current size of the array: 0, ceil( size / div ) > ext, ..
  _data = 0; // the pointer to (or array of) the stored data

} // List<T>::List

/****************************************************************************/

template< class T > // constructor setting initial memory and divisor
List< T >::List( int ext, int div ) {

  if( ext < 1 )
    ext = 1; // 20081206 fix user failure instead of throwing an exception

  if( ext > 100000 )
    ext = 100000; // 20150913 fix user failure instead of throwing an exception

  if( div < 1 )
    div = 1; // 20100803 only use a qualified divisor instead of throwing excep.

  if( div > 12 ) // 20100803 do not allow a divisor > 12; does not make sense
    div = 12; // the smaller the divisor the fast and more memory hungry it gets

  _ext = ext; // set the size of the extension, between 1 and 100000
  _pos = 0; // start position of the internal array; DO NOT CHANGE(!)
  _div = div; // set an own divisor between 1 and 12; some code magic here.
  _size = 0; // the current size of the array: 0, ext, ceil( size / div ).
  _data = 0; // the pointer to (or array of) the stored data

} // List<T>::List

/****************************************************************************/

template< class T > // destructor
List< T >::~List( void ) {

  delete[ ] _data; // stored objects are never deleted; delete those separately

} // List<T>::~List

/****************************************************************************/

template< class T > // return current size of smart list
int List< T >::size( void ) {

  return _pos; // current size of List by returning the position of last date

} // List<T>::size

/****************************************************************************/

template< class T > // add an element to the end of smart list
void List< T >::add( T data ) {

  if( _pos == _size )
    ext( _ext ); // extend the member array if end is reached

  _data[ _pos ] = data; // store the data at current position
  _pos++; // prepare for next data by getting to next position

} // List<T>::add

/****************************************************************************/

template< class T > // set an element to a given position
void List< T >::set( int pos, T data ) {

  if( pos < 0 )
    throw Error( "List<T>::set - pos is smaller than zero" );

  if( pos >= _pos ) {

    ext( pos - _pos + 1 ); // extend 2 requested set position
    _pos = _size;

  } // hard copy it

  _data[ pos ] = data;

} // List<T>::set

/****************************************************************************/

template< class T > // insert an element at a given position
void List< T >::ins( int pos, T data ) {

  if( pos >= _pos )
    throw Error( "List<T>::ins - pos is equal or greater than size of list" );

  if( pos < 0 )
    throw Error( "List<T>::ins - pos is smaller than zero" );

  if( _pos == _size )
    ext( _ext );

  for( int i = _pos; i > pos; i-- )
    _data[ i ] = _data[ i - 1 ];

  _data[ pos ] = data;
  _pos++;

} // List<T>::ins

/****************************************************************************/

template< class T > // return an element from a given position
T List< T >::get( int pos ) {

  if( _pos == 0 )
    throw Error( "List<T>::get - no data set yet; internal array is empty" );

  if( pos >= _pos )
    throw Error( "List<T>::get - pos is equal or greater than size of list" );

  if( pos < 0 )
    throw Error( "List<T>::get - pos is smaller than zero" );

  T data = _data[ pos ];

  return data;

} // List<T>::get

/****************************************************************************/

template< class T > // return first element in list
T List< T >::fst( void ) {

  return get( 0 );

} // List<T>::fst

/****************************************************************************/

template< class T > // return last element in list
T List< T >::lst( void ) {

  return get( _pos - 1 ); // if list is empty throws this first

} // List<T>::lst

/****************************************************************************/

template< class T > T* // return all elements as array of element type
List< T >::arr( void ) {

  if( _pos <= 0 )
    return 0; // do not throw an error here

  T* arr = new T[ _pos ];

  for( int i = 0; i < _pos; i++ )
    arr[ i ] = _data[ i ];

  return arr;  // do not forget to do: delete [ ] arr

} // List<T>::arr

/****************************************************************************/

template< class T > // optimize the parameters of the smart list
void List< T >::par( void ) {

//int ext = (int)( floor( (double)( _size ) / (double)( _div ) ) ); // extension
  int ext = (int)( ceil( (double)( _size ) / (double)( _div ) ) ); // extension

  if( ext > _ext ) // as long as ext is greater than internal _ext
    _ext = ext; // speed up faster by using ext

} // List<T>::par

/****************************************************************************/

template< class T > // optimize allocated memory of smart list
void List< T >::opt( void ) {

  if( _size > _pos ) {

    shr( _pos ); // shrink array to actual size
    par( );

  } // if

} // List<T>::opt

/****************************************************************************/

template< class T > // optimize allocated memory of smart list and set extension
void List< T >::opt( int ext ) {

  if( _size > _pos )
    shr( _pos ); // shrink array to actual size

  if( ext < 1 )
    ext = 1;

  _ext = ext; // take user's extensions size

} // List<T>::opt

/****************************************************************************/

template< class T > // extended the allocated memory by copying automatically
void List< T >::ext( int ext ) {

  T* tmp = 0;

  if( _size != 0 ) { // data 2 tmp

    tmp = new T[ _size ];

    for( int i = 0; i < _size; i++ )
      tmp[ i ] = _data[ i ];

    delete[ ] _data;

  } // if

  int newSize = _size + ext;

  _data = new T[ newSize ];

  if( _size != 0 ) { // tmp 2 data

    for( int i = 0; i < _size; i++ )
      _data[ i ] = tmp[ i ];

    delete[ ] tmp;

  } // if

  _size = newSize; // set new size

  par( ); // calculate next extension size

} // List<T>::ext

/****************************************************************************/

template< class T > // shrink smart list to the size of pos; last element
void List< T >::shr( int pos ) {

  if( pos > _size )
    throw Error( "List<T>::shr - pos is greater than size of list" );

  if( pos < 0 )
    throw Error( "List<T>::shr - pos is smaller than zero" );

  if( pos > 0 ) {

    T* tmp = new T[ pos ];

    for( int i = 0; i < pos; i++ )
      tmp[ i ] = _data[ i ]; // data 2 tmp

    delete[ ] _data;

    _data = new T[ pos ];

    for( int i = 0; i < pos; i++ )
      _data[ i ] = tmp[ i ]; // tmp 2 data

    delete[ ] tmp;

    _size = pos;

  } // if

} // List<T>::shr

/****************************************************************************/

// template<class T> T  /// operator overloading
// List<T>::operator [ ] ( int n ) const {
//   return this->get( n );
// } // List<T>::operator [ ]

/****************************************************************************/

typedef List< int > IntList;       // namespace & template typedef
typedef List< long > LongList;     // namespace & template typedef
typedef List< bool > BoolList;     // namespace & template typedef
typedef List< double > DoubleList; // namespace & template typedef
typedef List< char > CharList;     // namespace & template typedef
typedef List< Str > StrList;       // namespace & template typedef

/******************************************************************************/

} // namespace SYS

/****************************************************************************/

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysList_h__

/******************************************************************************/
