/** 
 * @file xmlccSysXmlTool.h
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2018 Christian Scheiblich (cscheiblich@gmail.com)
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

#ifndef __xmlccSysXmlTool_h__
#define __xmlccSysXmlTool_h__

/******************************************************************************/

#include "./xmlccSysDefines.h" /// common include file for headers and typedefs
#include "./xmlccSysStrTool.h" // uses SYS::StrTool class; of course

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

#define _XMLCC_VERSION_SYS_XmlTool_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_SYS_XmlTool_
#endif

/******************************************************************************/

class /// class cleans malformed XML tags; uses class SYS::StrTool
XmlTool {
  public:

    XmlTool( void ); /// constructor
    virtual ~XmlTool( void ); /// destructor

    Str format( Str tag ); /// reformatting of any kind of tag

    Str cleanTag( Str tag ); /// remove doubled white spaces and tabulators
    Str cleanStarting( Str tag ); // if starting tag '< .. >'
    Str cleanEnding( Str tag ); // if ending tag '< / .. >'
    Str cleanStandAlone( Str tag ); // if stand alone tag '< .. / >'
    Str cleanHeader( Str tag ); // if tag is a header '<? .. ?>'
    Str cleanComment( Str tag ); // if tag is a comment '<!-- .. -->'
    Str cleanCData( Str tag ); // if tag is CDATA '<![CDATA[ .. ]]>'
    Str cleanValue( Str value ); /// ' black   grey   ' to 'black grey'

    Str addSpikes( Str tag ); /// check and add spikes ' .. '  => '<..>'
    Str removeSpikes( Str tag ); /// check and removes - even multiple - leading and ending spikes ' < < .. >> ' => ' .. '

    bool check4Tag( Str tag ); /// if XML tag; going for '< .. >'
    bool check4Starting( Str tag ); /// if starting tag '< .. >'
    bool check4Ending( Str tag ); /// if ending tag '< / .. >'
    bool check4StandAlone( Str tag ); /// if standalone tag '< .. / >'

    bool check4Header( Str tag ); /// if tag is a header '<? .. ?>'
    bool check4Comment( Str tag ); /// if tag is a comment '<!-- .. -->'
    bool check4CData( Str tag ); /// if tag is CDATA '<![CDATA[ .. ]]>'

    bool check4Text( Str tag ); /// check for having text ' .. '

    Str getTagName( Str line ); /// hand the beginning tag '<tag' back as string

  protected:

    StrTool* _strTool; /// string manipulation

};
// class XmlTool

/******************************************************************************/

}// namespace SYS

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccSysXmlTool_h__
