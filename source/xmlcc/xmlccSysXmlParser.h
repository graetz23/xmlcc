/** 
 * @file xmlccSysXmlParser.h
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

#ifndef __xmlccSysXmlParser_h__
#define __xmlccSysXmlParser_h__

/******************************************************************************/

#include "./xmlccDefines.h" // XMLCC::
#include "./xmlccSys.h" // SYS::
#include "./xmlccSysXmlHandler.h" // SYS::XmlHandler

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_XmlParser_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_XmlParser_
#endif

/******************************************************************************/

class /// class parses from file or string buffer and returns a string list
XmlParser {
  public:

    XmlParser( void ); /// constructor
    XmlParser( XmlHandler* xmlHandler ); /// constructor
    virtual ~XmlParser( void ); /// destructor

    void setSizeMemAlloc( int sizeMemAlloc ); // size of preallocation; .. 100k
    void setDoFormatTags( bool doFormatTags ); // clean malformed XML tags

    void parse( Str fileName ); /// reads file and returns root object

  private:

    void _parse( FileStr& fileStr ); /// do all stuff here

    enum State {
      idle = 0, // parser is in idle state; start and end
      readingTxt = 1, // parser is reading text between an XML tag
      readingTag = 2, // parser is reading an XML tag
      readingAlt = 3  // parser is reading an attribute in an XML tag
    }; // states of parsers's state machine

    State _state; /// current state of parser's state machine
    bool _switchState; /// switches state if set true in cycle
    bool _isReadingTxt; /// is reading text between XML tag
    bool _isReadingAlt; /// is reading attribute in XML tag
    bool _isReadingTag; /// is reading XML tag

    int _lineNo; /// count lines for telling XML file errors
    int _charNo; /// count characters for telling XML file errors

    int _inSpike; /// checks a tag to be consistent
    long _spikeOpened; /// count opening spikes
    long _spikeClosed; /// count closing spikes

    int _sizeMemAlloc; /// cfg of XMLCC; pre size of smart pointer list
    bool _doFormatTags; /// cfg of XMLCC; do format malformed tags or not

    StrTool* _strTool; /// tool class for std::string manipulations
    XmlTool* _xmlTool; /// tool class for XML tag & text manipulations

    XmlHandler* _xmlHandler; /// base class for handling found XML tags & texts

    void _init( void ); /// called by constructor for initializing members

};
// class XmlParser

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysXmlParser_h__
