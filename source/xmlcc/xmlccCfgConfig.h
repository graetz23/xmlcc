/** 
 * @file xmlccCfgConfig.h
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

#ifndef __xmlccCfgConfig_h__
#define __xmlccCfgConfig_h__

/******************************************************************************/

#include "./xmlccDom.h" // DOM::

/******************************************************************************/

namespace XMLCC {

namespace CFG {

/******************************************************************************/

#define _XMLCC_VERSION_CFG_Config_ 1.00 // 20150101
#ifdef _XMLCC_DEBUG_
#define _XMLCC_DEBUG_CFG_Config_
#endif

/******************************************************************************/

class /// class parses from file or string buffer and returns a string list
Config {
  public:

    Config( void ); /// constructor sets to xmlcc.xml
    // Config( Str fileName ); /// constructor
    virtual ~Config( void ); /// destructor

    static bool exists( void ); /// check if config file is existing

    static DOM::Root* generate( void ); /// generate missing configuration file
    static void write( DOM::Root* xml ); /// write configuration file to drive
    static DOM::Root* read( void ); /// read configuration file from drive

    /// <config><parser> .. </parser></config>
    bool getConfigParserConsoleTalk( void ); /// get config parameter
    bool getConfigParserCleanTag( void ); /// get config parameter
    bool getConfigParserCleanAttributes( void ); /// get config parameter
    bool getConfigParserCleanComments( void ); /// get config parameter
    int getConfigParserMemoryPreallocation( void ); /// get config parameter

    /// <config><tokenizer> .. </tokenizer></config>
    bool getConfigTokenizerTalk( void ); /// get config parameter

    /// <config><info> .. </info></config>
    Str getInfoBuiltDate( void ); /// get info parameter
    Str getInfoVersionNumber( void ); /// get info parameter
    Str getInfoPackageName( void ); /// get info parameter
    Str getInfoLicenseType( void ); /// get info parameter
    Str getInfoProjectUrl( void ); /// get info parameter
    Str getInfoUserName( void ); /// get info parameter
    Str getInfoUserEmail( void ); /// get info parameter

    /// <config><system> .. </system></config>
    bool getSystemTestSysList( void ); /// get system parameter
    bool getSystemTestSysStrTool( void ); /// get system parameter
    bool getSystemTestSysXmlTool( void ); /// get system parameter
    bool getSystemTestSysXmlParser( void ); /// get system parameter
    bool getSystemTestDomTokenizer( void ); /// get system parameter
    bool getSystemTestDomController( void ); /// get system parameter
    bool getSystemTestXmlcc( void ); /// get system parameter
    Str getSystemCData( void ); /// get system parameter

  private:

    DOM::Root* _root; /// root node of read config file xmlcc.xml

    DOM::Controller _controller; /// crawling DOM's tree
    SYS::XmlTool _xmlTool; /// convert std::string to bool, int, double, ..
    SYS::StrTool _strTool; /// convert std::string to bool, int, double, ..

};
// class Config

/******************************************************************************/

}// namespace CFG

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccCfgConfig_h__
