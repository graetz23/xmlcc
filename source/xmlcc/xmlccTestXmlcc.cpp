/** 
 * @file xmlccTestXmlcc.cpp
 * @author Christian (graetz23@gmail.com)
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2020 Christian (graetz23@gmail.com)
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

#include "xmlccTestXmlcc.h" // header

/******************************************************************************/

namespace XMLCC {

namespace TEST {

/******************************************************************************/

/// constructor
Xmlcc::Xmlcc( std::string name ) {

  _name = name;

} // Xmlcc

/// destructor
Xmlcc::~Xmlcc( void ) {

} // ~Xmlcc

/******************************************************************************/

void // inherit method for all unit tests using assert methods
Xmlcc::run( void ) {

  Str fileName = "xmlccMalformed.xml";

//  Str tag = "";
//  Str tagStarting = "<file version=\"1.2\" date=\"19.12.2014\">";
//  Str tagEnding = "</file>";
//  Str tagStandAlone = "<file name=\"xmlcc.xml\"/>";
//  Str tagHeader = "<?xml version=\"1.0\"?>";
//  Str tagComment = "<!--xmlcc powered by C++-->";
//  Str tagCData = "<![CDATA[0123456789ABCDEF]]";
//  Str tagText = "xmlcc powered by c++";

  /****************************************************************************/

  DOM::Controller controller;
  DOM::Parser domParser;
  SAX::Parser saxParser( new SAX::HandlerExample( ) );

  /****************************************************************************/

  DOM::Root* root = 0;

  /****************************************************************************/

  if( false ) {

    root = controller.createRoot( "xmlccTest.xml" ); // set file name to Root*
    root->setStr( "xmlccTest.xml" ); // overwrite file name again

    root->addNode( controller.createHeader( ) );
    controller.create( root, DOM::Types::Comment,
      "some generated example data" );

    DOM::Node* people = controller.create( DOM::Types::Element, "people" );
    controller.create( people, DOM::Types::Comment,
      "several persons are following" );
    controller.create( people, DOM::Types::Comment,
      "this file is written as xmlcc.xml" );
    controller.create( people, DOM::Types::Comment,
      "you can see it in XMLCC directory" );
    root->addNode( people ); // Root* is single and not written; keeps file name

    DOM::Node* person = controller.create( DOM::Types::Element, "person" );
    controller.create( person, DOM::Types::Comment,
      "first person added 2 xml" );
    controller.create( person, DOM::Types::Attribute, "gender", "female" );
    controller.create( person, DOM::Types::Element, "family", "Gable" );
    controller.create( person, DOM::Types::Element, "fore", "Ginger" );
    controller.create( person, DOM::Types::Comment, "check this again" );
    controller.create( person, DOM::Types::Element, "age", "24" );
    people->addNode( person );

    person = controller.create( DOM::Types::Element, "person" );
    controller.create( person, DOM::Types::Attribute, "gender", "male" );
    controller.create( person, DOM::Types::Element, "family", "Hudden" );
    DOM::Node* fore = controller.create( DOM::Types::Element, "fore", "Paul" );
    controller.create( fore, DOM::Types::Attribute, "nick", "The_Bull" );
    person->addNode( fore );
    controller.create( person, DOM::Types::Element, "age", "empty" );
    DOM::Node* address = controller.create( DOM::Types::Element, "address" );
    controller.create( address, DOM::Types::Element, "street", "Main Street" );
    controller.create( address, DOM::Types::Element, "number", "5643" );
    controller.create( address, DOM::Types::Element, "zipcode", "70569" );
    controller.create( address, DOM::Types::Element, "city", "Stuttgart" );
    person->addNode( address );
    people->addNode( person );

    person = controller.create( DOM::Types::Element, "person" );
    people->addNode( person );
    controller.create( person, DOM::Types::Attribute, "gender", "male" );
    controller.create( person, DOM::Types::Element, "fore", "Tom Fred" );
    controller.create( person, DOM::Types::Element, "family", "Bauer" );
    controller.create( person, DOM::Types::Element, "age", "empty" );

    address = controller.create( DOM::Types::Element, "address" );
    controller.create( address, DOM::Types::Element, "street", "Bergweg" );
    controller.create( address, DOM::Types::Element, "number", "19" );
    controller.create( address, DOM::Types::Element, "zip code", "69155" );
    controller.create( address, DOM::Types::Element, "city", "Heidelberg" );

    DOM::Node* tmp = 0;
    DOM::Node* contact = controller.create( DOM::Types::Element, "contact" );
    controller.create( address, DOM::Types::Comment, "check address again" );

    tmp = controller.create( DOM::Types::Element, "work", "1 44 55" );
    controller.create( tmp, DOM::Types::Attribute, "time", "work_days" );
    contact->addNode( tmp );
    tmp = controller.create( DOM::Types::Element, "private" );
    controller.create( tmp, DOM::Types::Attribute, "time", "weekends" );
    contact->addNode( tmp );
    tmp = controller.create( DOM::Types::Element, "mobil", "+49 7" );
    controller.create( tmp, DOM::Types::Attribute, "time", "evenings" );
    contact->addNode( tmp );
    tmp = controller.create( DOM::Types::Element, "email" );
    controller.create( tmp, DOM::Types::Attribute, "private",
      "tom@nodomain.country" );
    contact->addNode( tmp );
    tmp = controller.create( DOM::Types::Element, "email" );
    controller.create( tmp, DOM::Types::Attribute, "work",
      "tom.bauer@nocompany.country" );
    controller.create( tmp, DOM::Types::Attribute, "mark", "weekdays" );
    controller.create( tmp, DOM::Types::Attribute, "empty" );
    contact->addNode( tmp );

    person->addNode( address );
    person->addNode( contact );

    std::cout << root << std::flush << std::endl; // might of DOM tree

    std::fstream file;
    std::string strFileName = root->getFileName( );
    char* charFileName = (char*)( strFileName.c_str( ) );
    file.open( charFileName, std::ios::out );
    if( file.fail( ) )
      throw SYS::Failure( "main - can not open file" );
    file << root << std::endl << std::flush; // might of DOM tree
    file.close( );

    std::cout << std::endl << std::endl << std::flush;

    delete root; // free XML DOM tree
    root = 0; // set to null pointer

  } // if

  /****************************************************************************/

  controller.erase( root );

} // Xmlcc::run

/******************************************************************************/

} // namespace TEST

} // namespace XMLCC

/******************************************************************************/
