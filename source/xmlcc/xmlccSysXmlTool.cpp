/** 
 * @file xmlccSysXmlTool.cpp
 * @author Christian Scheiblich
 *
 * XMLCC is distributed under the MIT License (MIT); this file is part of.
 *
 * Copyright (c) 2008-2017 Christian Scheiblich (cscheiblich@gmail.com)
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

#include "xmlccSysXmlTool.h" // header

/******************************************************************************/

namespace XMLCC {

namespace SYS {

/******************************************************************************/

/// constructor
XmlTool::XmlTool( void ) {

  _strTool = new SYS::StrTool( );

} // XmlTool

/// destructor
XmlTool::~XmlTool( void ) {

  delete _strTool;

} // ~XmlTool

/******************************************************************************/

Str // clean a tag
XmlTool::format( Str tag ) {

  if( check4Tag( tag ) )
    tag = cleanTag( tag ); // ' <  tag a = "  2  "  / > ' => '<tag a = " 2 " />'

  if( check4Header( tag ) )
    return cleanHeader( tag ); // if is a header '<? .. ?>'

  if( check4Comment( tag ) )
    return cleanComment( tag ); // if is a comment '<!-- .. -->' 

  if( check4CData( tag ) )
    return cleanCData( tag ); // if is CDATA '<![CDATA[ .. ]]>'

  if( check4Starting( tag ) )
    return cleanStarting( tag ); // if is starting tag '< .. >'

  if( check4Ending( tag ) )
    return cleanEnding( tag ); // if is ending tag '< / .. >'

  if( check4StandAlone( tag ) )
    return cleanStandAlone( tag ); // if is standalone tag '< .. / >'

  // if not returned yet it is a value
  return cleanValue( tag ); // not an XML tag, clean it anyway ~8>

} // XmlTool::format

/******************************************************************************/

Str /// clean XML tags '   <  tag alt =  "gold  " >  ' to '<tag alt="gold">'
XmlTool::cleanTag( Str tag ) {

  tag = _strTool->filterBs( tag ); // replace breaklines by whitespaces

  tag = _strTool->filterTs( tag ); // replace tabulators by two whitespaces

  tag = _strTool->filterWs( tag ); // remove doubled whitspaces

  tag = _strTool->trimS( tag ); // ' <tag alt = " gold "> ' to '<tag alt = " gold ">' 
  tag = removeSpikes( tag ); // '< tag alt = " gold " >' to ' tag alt = " gold " '
  tag = _strTool->trimS( tag ); // ' tag alt = " gold " ' to 'tag alt = " gold "'
  tag = addSpikes( tag ); // 'tag alt = " gold "' to '<tag alt = " gold ">'

  return tag;

} // XmlTool::cleanTag

/******************************************************************************/

Str // if starting tag '< .. >'
XmlTool::cleanStarting( Str tag ) {

  // TODO could be done much more faster using methods of <cstring>

  bool isTag = check4Tag( tag ); // remember if it was a real tag

  Str cleanTag = ""; // the cleaned tag 

  if( isTag ) {

    // '< tag alt = " gold " >' to ' tag alt = " gold " '
    tag = removeSpikes( tag );

    // ' tag alt = " gold " ' to 'tag alt = " gold "' 
    tag = _strTool->trimS( tag );

    // search for tag first by looking for first whitespace
    Str tagName = "";

    size_t posOfFirstWhite = 0;
    size_t tagLength = tag.length( );

    bool isTagNameFound = false;

    while( !isTagNameFound ) {

      char c = tag[ posOfFirstWhite ];

      if( c != ' ' )
        tagName += c;

      if( c == ' ' || posOfFirstWhite == ( tagLength - ( 1 ) ) ) {

        isTagNameFound = true;

        cleanTag.append( tagName );

      } // done

      posOfFirstWhite++;

    } // while

    // TODO method below is not working ..
    tag = tag.substr( posOfFirstWhite, tagLength );

    size_t pos = 0;
    tagLength = tag.length( );

    Str attributeName = "";
    Str attributeValue = "";

    bool isReadingName = true;
    bool isReadingValue = false;

    bool isFinished = false;

    while( !isFinished && tagLength > 0 ) {

      char c = tag[ pos ];

      if( c == '=' )
        isReadingName = false; // toggle

      if( isReadingName )
        attributeName += c;

      if( c != '"' && isReadingValue )
        attributeValue += c;

      if( c == '"' ) {

        if( c == '"' && isReadingValue ) {

          isReadingName = !isReadingName; // toggle

          attributeName = _strTool->trimS( attributeName ); // ' name  ' => 'name'
          attributeValue = _strTool->trimS( attributeValue ); // 'value is 9 ' => 'value is 9'

          cleanTag.append( " " );
          cleanTag.append( attributeName );
          cleanTag.append( "=\"" );
          cleanTag.append( attributeValue );
          cleanTag.append( "\"" );

          attributeName.clear( );
          attributeValue.clear( );

        } // one set done!

        isReadingValue = !isReadingValue; // toggle

      } // if " .. " 

      if( pos == ( tagLength - ( 1 ) ) )
        isFinished = true;

      pos++;

    } // while

    tag = cleanTag; // copy to original

    tag = addSpikes( tag );

  } // if tag

  return tag;

} // XmlTool::cleanStarting

/******************************************************************************/

Str // if ending tag '< / .. >'
XmlTool::cleanEnding( Str tag ) {

  // TODO could be done much more faster by using methods of <cstring>

  tag = _strTool->trimS( tag ); // ' < / tag  > ' => '< / tag / >'

  tag = removeSpikes( tag ); // '< / tag >' => ' / tag '

  tag = _strTool->trimS( tag ); // ' / tag ' => '/ tag'

  size_t tagLength = tag.length( );

  size_t pos = 1;

  Str cleanTag;

  while( pos < tagLength && tagLength > 0 ) { // skip first, cause is /

    char c = tag[ pos ];

    cleanTag += c;

    pos++;

  } // while

  tag.clear( );

  tag += '/';

  cleanTag = _strTool->trimS( cleanTag );

  tag.append( cleanTag );

  tag = addSpikes( tag );

  return tag;

} // XmlTool::cleanEnding

/******************************************************************************/

Str // if standalone tag '< .. / >'
XmlTool::cleanStandAlone( Str tag ) {

  // TODO could be done much more faster by using methods of <cstring>

  tag = _strTool->trimS( tag ); // ' <tag a="2" / > ' => '<tag a="2" / >'

  tag = removeSpikes( tag ); // '<tag a="2" / >' => 'tag a="2" / '

  tag = _strTool->trimS( tag ); // 'tag a="2" / ' => 'tag a="2" /'

  size_t tagLength = tag.length( );

  size_t pos = 0;

  Str cleanTag;

  while( pos < ( tagLength - 1 ) ) { // skip last, cause is /

    char c = tag[ pos ];

    cleanTag += c;

    pos++;

  } // while

  tag = cleanTag;

  tag = _strTool->trimS( tag );

  tag = addSpikes( tag );

  tag = cleanStarting( tag ); // handle as starting tag

  tag = removeSpikes( tag );

  tag += '/';

  tag = addSpikes( tag );

  return tag;

} // XmlTool::cleanStandAlone

/******************************************************************************/

Str // if tag is a header '<? .. ?>'
XmlTool::cleanHeader( Str tag ) {

  // TODO could be done much more faster by using methods of <cstring>

  tag = _strTool->trimS( tag ); // ' < ? xml .. ?  > ' => '< ? xml .. ?  >'

  tag = removeSpikes( tag ); // '< ? xml .. ?  >' => ' ? xml .. ?  '

  tag = _strTool->trimS( tag ); // ' ? xml .. ?  ' => '? xml .. ?'

  Str cleanTag;

  size_t tagLength = tag.length( );

  char firstChar = tag[ 0 ];
  char lastChar = tag[ tagLength - 1 ];

  size_t pos = 1;

  if( firstChar == '?' && lastChar == '?' ) {

    while( pos < ( tagLength - 1 ) && tagLength > 0 ) { // skip first, cause is /

      char c = tag[ pos ];

      cleanTag += c;

      pos++;

    } // while

    tag = _strTool->trimS( cleanTag );

    tag = addSpikes( tag );

    tag = cleanStarting( tag ); // <xml version = " 1.0 " .. >

    cleanTag = removeSpikes( tag );

    tag.clear( );

    tag += '?';

    tag.append( cleanTag );

    tag += '?';

    tag = addSpikes( tag );

  } // if

  return tag;

} // XmlTool::cleanHeader

/******************************************************************************/

Str // if tag is a comment '<!-- .. -->'
XmlTool::cleanComment( Str tag ) {

  tag = _strTool->filterBs( tag ); // replace break lines by white spaces

  tag = _strTool->filterTs( tag ); // replace tabulators by two white spaces

  tag = _strTool->filterWs( tag ); // remove doubled white spaces

  tag = _strTool->trimS( tag ); // ' <tag alt = " gold "> ' to '<tag alt = " gold ">'
  tag = removeSpikes( tag ); // '< tag alt = " gold " >' to ' tag alt = " gold " '
  tag = _strTool->trimS( tag ); // ' tag alt = " gold " ' to 'tag alt = " gold "'
  tag = addSpikes( tag ); // 'tag alt = " gold "' to '<tag alt = " gold ">'

  // TODO clean comment tag: '<!-- .. -->'

  return tag;

} // XmlTool::cleanComment

/******************************************************************************/

Str // if tag is CDATA '<![CDATA[ .. ]]>'
XmlTool::cleanCData( Str tag ) {

  tag = _strTool->filterBs( tag ); // replace break lines by white spaces

  tag = _strTool->filterTs( tag ); // replace tabulators by two white spaces

  tag = _strTool->filterWs( tag ); // remove doubled white spaces

  tag = _strTool->trimS( tag ); // ' <tag alt = " gold "> ' to '<tag alt = " gold ">'
  tag = removeSpikes( tag ); // '< tag alt = " gold " >' to ' tag alt = " gold " '
  tag = _strTool->trimS( tag ); // ' tag alt = " gold " ' to 'tag alt = " gold "'
  tag = addSpikes( tag ); // 'tag alt = " gold "' to '<tag alt = " gold ">'

  // TODO clean CDATA tag: '<![CDATA[ .. ]]>'

  return tag;

} // XmlTool::cleanCData

/******************************************************************************/

Str /// clean values ' black   grey  red   ' to 'black grey red'
XmlTool::cleanValue( Str value ) {

  value = _strTool->filterBs( value ); // replace break lines by white spaces

  value = _strTool->filterTs( value ); // replace tabulators by two white spaces

  value = _strTool->filterWs( value ); // remove doubled white spaces

  value = _strTool->trimS( value ); // ' black grey ' to 'black grey'

  return value;

} // XmlTool::cleanValue

/******************************************************************************/

Str /// check and add leading spikes
XmlTool::addSpikes( Str tag ) {

  tag = _strTool->trimS( tag ); // trim whitespaces left and right

  tag = removeSpikes( tag ); /// remove all spikes first to clean it

  Str spikedTag = ""; // empty

  char openSpike = '<';
  if( tag[ 0 ] != openSpike ) // append < if not there
    spikedTag.append( "<" );

  spikedTag.append( tag ); // append the tag completely

  char closingSpike = '>';
  if( tag[ tag.size( ) - 1 ] != closingSpike ) // append > if not there
    spikedTag.append( ">" );

  return spikedTag;

} // XmlTool::addSpikes

/******************************************************************************/

Str /// check and removes leading and ending - even multiple - spikes
XmlTool::removeSpikes( Str tag ) {

  // TODO could be done much more faster by using methods of <cstring>

  tag = _strTool->trimS( tag ); // trim whitespaces left and right

  size_t lengthOfTag = tag.size( );

  bool foundFirstNonOpenedSpike = false;
  size_t posOfFirstNonOpenedSpike = 0; // from head
  while( !foundFirstNonOpenedSpike ) {

    char c = tag[ posOfFirstNonOpenedSpike ];

    if( c != '<' )
      foundFirstNonOpenedSpike = true;

    if( posOfFirstNonOpenedSpike == ( lengthOfTag - 1 ) )
      foundFirstNonOpenedSpike = true;

    if( !foundFirstNonOpenedSpike )
      posOfFirstNonOpenedSpike++;

  } // while

  bool foundFirstNonClosedSpike = false;
  size_t posOfFirstNonClosedSpike = lengthOfTag - 1; // from tail
  while( !foundFirstNonClosedSpike ) {

    char c = tag[ posOfFirstNonClosedSpike ];

    if( c != '>' )
      foundFirstNonClosedSpike = true;

    if( posOfFirstNonClosedSpike == 0 )
      foundFirstNonClosedSpike = true;

    if( !foundFirstNonClosedSpike )
      posOfFirstNonClosedSpike--;

  } // while

  Str nonSpikedTag = "";
  // get tag without spikes

  size_t lengthOfSubstr = 0;

  if( posOfFirstNonOpenedSpike <= posOfFirstNonClosedSpike ) {

    lengthOfSubstr = posOfFirstNonClosedSpike - posOfFirstNonOpenedSpike;

    nonSpikedTag = tag.substr( posOfFirstNonOpenedSpike, lengthOfSubstr + 1 );

  } else {

    size_t head = 0;
    size_t tail = lengthOfTag;

    if( posOfFirstNonOpenedSpike < ( lengthOfTag - 1 ) )
      head = posOfFirstNonOpenedSpike;

    if( posOfFirstNonClosedSpike > 0 )
      tail = posOfFirstNonClosedSpike;

    lengthOfSubstr = tail - head;

    nonSpikedTag = tag.substr( head, lengthOfSubstr + 1 );

  } // if wired tag like '<<<<< a' or 'b >>>>' recover it

  return nonSpikedTag;

} // XmlTool::removeSpikes

/******************************************************************************/

bool /// check if content is a tag; going for '< .. >'
XmlTool::check4Tag( Str tag ) {

  bool isTag = false;

  tag = _strTool->trimS( tag ); // remove leading and ending whitespaces

  size_t lengthOfTag = tag.size( );

  if( lengthOfTag > 2 ) { // min is '<a>'

    char firstChar = tag[ 0 ];

    char lastChar = tag[ lengthOfTag - 1 ];

    if( firstChar == '<' && lastChar == '>' )
      isTag = true;

  } // if 

  return isTag;

} // XmlTool::check4Tag

/******************************************************************************/

bool /// check if content is a tag; going for '< .. >'
XmlTool::check4Starting( Str tag ) {

  bool isTag = true;

  if( check4Tag( tag ) ) {

    tag = _strTool->trimS( tag ); // remove leading and ending whitespaces

    tag = removeSpikes( tag ); // remove < .. >

    tag = _strTool->trimS( tag ); // remove leading and ending whitespaces

    size_t lengthOfTag = tag.size( );

    if( lengthOfTag >= 1 ) { // min is 'a'

      char firstChar = tag[ 0 ];

      char lastChar = tag[ lengthOfTag - 1 ];

      if( firstChar == '/' || firstChar == '!' || firstChar == '?' )
        isTag = false;

      if( lastChar == '/' || lastChar == '!' || lastChar == '?' )
        isTag = false;

    } else {

      isTag = false;

    } // if smaller than 'a' 

  } else {

    isTag = false;

  } // check4Tag( tag ) 

  return isTag;

} // XmlTool::check4Tag

/******************************************************************************/

bool /// check if tag is ending
XmlTool::check4Ending( Str tag ) {

  bool isTagEnding = false;

  if( check4Tag( tag ) ) {

    tag = removeSpikes( tag ); // ' <  / .. >  ' to '  / .. ' 

    tag = _strTool->trimS2L( tag ); // '  / .. ' to '/ .. '

    char firstChar = tag[ 0 ];

    if( firstChar == '/' )
      isTagEnding = true;

  } // if

  return isTagEnding;

} // XmlTool::check4TagEnding

/******************************************************************************/

bool /// check if tag is standalone
XmlTool::check4StandAlone( Str tag ) {

  bool isTagStandAlone = false;

  if( check4Tag( tag ) ) {

    tag = removeSpikes( tag ); // ' < .. /  >  ' to ' .. /  ' 

    tag = _strTool->trimS2R( tag ); // ' .. /  ' to ' .. /'

    char lastChar = tag[ tag.size( ) - 1 ];

    if( lastChar == '/' )
      isTagStandAlone = true;

  } // if

  return isTagStandAlone;

} // XmlTool::check4TagStandAlone

/******************************************************************************/

bool /// if tag is a header '<? .. ?>'
XmlTool::check4Header( Str tag ) {

  bool isHeader = false;

  tag = removeSpikes( tag );

  size_t length = tag.size( );

  if( length < 2 )
    return false;
  // throw SYS::Failure( "XmlTool::check4Header - tag has no char" );

  char m = tag[ 0 ];

  if( m == '?' ) { // check for a header

    char s0 = tag[ 0 ];

    if( s0 == '?' ) {

      char e0 = tag[ length - 1 ];

      if( e0 == '?' ) {

        isHeader = true;

      } // if ?

    } // if ?

  } // if ?

  return isHeader;

} // check4Header

/******************************************************************************/

bool // /// if tag is a comment '<!-- .. -->'
XmlTool::check4Comment( Str tag ) {

  // TODO rehack this to allow for ' <  !  -  -  .. -    - >'

  bool isComment = false;

  tag = removeSpikes( tag );

  size_t length = tag.size( );

  if( length < 5 ) // '!----'
    return false;

  char m = tag[ 0 ];

  if( m == '!' ) {  // check for comment

    if( length > 5 ) { // !---- has minimum of 5

      char s0 = tag[ 0 ];
      char s1 = tag[ 1 ];
      char s2 = tag[ 2 ];

      if( ( s0 == '!' ) && ( s1 == '-' ) && ( s2 == '-' ) ) { // comment

        char e0 = tag[ length - 1 ];
        char e1 = tag[ length - 2 ];

        if( ( e1 == '-' ) && ( e0 == '-' ) ) { // found comment

          isComment = true;

        } // if --

      } // if !--

    } // if 5

  } // if !

  return isComment;

} // check4Comment

/******************************************************************************/

bool // if tag is CDATA '<![CDATA[ .. ]]>'
XmlTool::check4CData( Str tag ) {

  // TODO rechack this to allow for ' <  ! [  C DA  T   A  [ ..    ]   ]  > '

  bool isCDATA = false;

  // <![CDATA[ .. ]]>

  tag = removeSpikes( tag );

  size_t length = tag.size( );

  if( length < 10 ) // '![CDATA[]]'
    return false;

  // ![CDATA[ .. ]]

  char m = tag[ 0 ];

  if( m == '!' ) {  // check for comment

    if( length >= 10 ) { // !CDATA[]] has minimum of 9

      char s0 = tag[ 0 ]; // !
      char s1 = tag[ 1 ]; // [
      char s2 = tag[ 2 ]; // C
      char s3 = tag[ 3 ]; // D
      char s4 = tag[ 4 ]; // A
      char s5 = tag[ 5 ]; // T
      char s6 = tag[ 6 ]; // A
      char s7 = tag[ 7 ]; // [

      if( ( s0 == '!' ) && ( s1 == '[' ) && ( s2 == 'C' ) && ( s3 == 'D' )
          && ( s4 == 'A' ) && ( s5 == 'T' ) && ( s6 == 'A' )
          && ( s7 == '[' ) ) { // ![CDATA[ ..

        char e0 = tag[ length - 1 ];
        char e1 = tag[ length - 2 ];

        if( ( e1 == ']' ) && ( e0 == ']' ) ) { // .. ]]

          isCDATA = true;

        } // if ]]

      } // if ![CDATA[

    } // if 10

  } // if !

  return isCDATA;

} // XmlTool::check4CDATA

/******************************************************************************/

bool /// check for having text ' .. '
XmlTool::check4Text( Str tag ) {

  bool isTxt = false;

  isTxt = !check4Tag( tag ); // if tag has ' < .. > ' invert to false

  return isTxt;

} // XmlTool::check4Text

/******************************************************************************/

Str // hand the beginning tag '<tag' back as string
XmlTool::getTagName( Str tag ) {

  // TODO method can be much more faster using methods of <cstring>

  Str tagName = "";

  tag = cleanTag( tag ); // remove doubled white spaces, break lines, etc. ..

  // line has to be '<a>' at minimum and starting with
  if( !check4Tag( tag ) )
    return tagName; // empty string while it has not tag

  tag = removeSpikes( tag );

  tag = _strTool->trimS2L( tag ); // '  tagName .. ' to 'tagName .. '

  // search for tag first by looking for first whitespace

  size_t posOfFirstWhite = 0;
  size_t lineLength = tag.length( );

  bool isTagNameFound = false;

  while( !isTagNameFound ) {

    char c = tag[ posOfFirstWhite ];

    if( c != ' ' )
      tagName += c;

    if( c == ' ' )
      isTagNameFound = true;

    if( posOfFirstWhite == ( lineLength - ( 1 ) ) )
      isTagNameFound = true;

    posOfFirstWhite++;

  } // while

  return tagName;

} // XmlTool::getTagName

/******************************************************************************/

} // namespace SYS

} // namespace XMLCC

/******************************************************************************/
