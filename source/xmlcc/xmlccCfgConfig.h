/** 
 * @file xmlccCfgConfig.h
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

    static DOM::Root* generate( void ); /// generate missing configuration file
    static void write( DOM::Root* root ); /// write configuration file to drive
    static DOM::Root* read( void ); /// read configuration file from drive

    Str getConfig( Str type, Str tag, Str attribute );

  private:

    DOM::Controller _controller; /// crawling DOM's tree

};
// class Config

/******************************************************************************/

}// namespace CFG

} // namespace XMLCC

/******************************************************************************/

#endif // __xmlccCfgConfig_h__
