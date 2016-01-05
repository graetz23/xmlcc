/** 
 * @file xmlccTest.cpp
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

#include "./xmlccTest.h" // for throwing XMLCC::Error
#include "./xmlccCfgConfig.h" // CFG::Config

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

void  /// run available unit tests for XMLCC::
run( void ) {

  try {

    SYS::UnitFrame unitFrame; // unit test frame work; register unit tests

    CFG::Config config;

    if( config.getSystemTestSysList( ) )
      unitFrame.add( new TEST::List( "XMLCC::SYS::List" ) );

    if( config.getSystemTestSysStrTool( ) )
      unitFrame.add( new TEST::StrTool( "XMLCC::SYS::StrTool" ) );

    if( config.getSystemTestSysXmlTool( ) )
      unitFrame.add( new TEST::XmlTool( "XMLCC::SYS::XmlTool" ) );

//    if( config.getSystemTestSysXmlParser( ) )
//      unitFrame.add( new TEST::XmlParser( "XMLCC::SYS::XmlParser" ) );

//    if( config.getSystemTestDomTokenizer( ) )
//      unitFrame.add( new TEST::Tokenizer( "XMLCC::DOM::Tokenizer" ) );

    if( config.getSystemTestDomController( ) )
      unitFrame.add( new TEST::Controller( "XMLCC::DOM::Controller" ) );

//    if( config.getSystemTestXmlcc( ) )
//      unitFrame.add( new TEST::Xmlcc( "XMLCC::" ) );

    unitFrame.run( ); // run all unit test that were registered

  } catch( XMLCC::SYS::Failure& f ) { // own exception class
    std::cout << "SYS::Failure caught:" << std::endl << std::flush;
    std::cout << f;
  } catch( XMLCC::SYS::Error& e ) { // own exception class
    std::cout << "SYS::Error caught:" << std::endl << std::flush;
    std::cout << e;
  } catch( XMLCC::SYS::Exception& e ) { // own exception class
    std::cout << "SYS::Exception caught:" << std::endl << std::flush;
    std::cout << e;
  } catch( std::exception& e ) { // standard exception class
    std::cout << "std::exception caught:" << std::endl << std::flush;
    std::cout << e.what( ) << std::endl << std::flush;
  } catch( ... ) { // any other exception thrown
    std::cout << "unknown exception caught:" << std::endl << std::flush;
    XMLCC::SYS::Exception e;
    e.nuke( ); // nuke the screen up
  } // try

} // run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
