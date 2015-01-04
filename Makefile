# @file Makefile
# @author Christian Scheiblich
#
# XMLCC is distributed under the MIT License (MIT); this file is part of.
#
# Copyright (c) 2008-2015 Christian Scheiblich (cscheiblich@gmail.com)
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
# type to your console: 
#   make && cd XMLCC && ./xmlcc
#
# last change 1.00 20150101 Amara Faith
#

CC=g++

# CFLAGS=-c -Wall
CFLAGS=-O3 -c -Wall
# CFLAGS=-O3 -g3 -c -Wall

LDFLAGS=

SRCDIR=source

SRCCNTRL=git

# like to have that stuff static while developing ~8>
SOURCES= \
	$(SRCDIR)/xmlcc/xmlccSysException.cpp \
	$(SRCDIR)/xmlcc/xmlccSysFailure.cpp \
	$(SRCDIR)/xmlcc/xmlccSysError.cpp \
	$(SRCDIR)/xmlcc/xmlccSysStrTool.cpp \
	$(SRCDIR)/xmlcc/xmlccSysXmlTool.cpp \
	$(SRCDIR)/xmlcc/xmlccSysXmlHandler.cpp \
	$(SRCDIR)/xmlcc/xmlccSysXmlParser.cpp \
	$(SRCDIR)/xmlcc/xmlccSysUnitTest.cpp \
	$(SRCDIR)/xmlcc/xmlccSysUnitFrame.cpp \
	$(SRCDIR)/xmlcc/xmlccDomNode.cpp \
	$(SRCDIR)/xmlcc/xmlccDomRoot.cpp \
	$(SRCDIR)/xmlcc/xmlccDomHeader.cpp \
	$(SRCDIR)/xmlcc/xmlccDomElement.cpp \
	$(SRCDIR)/xmlcc/xmlccDomAttribute.cpp \
	$(SRCDIR)/xmlcc/xmlccDomValue.cpp \
	$(SRCDIR)/xmlcc/xmlccDomComment.cpp \
	$(SRCDIR)/xmlcc/xmlccDomCData.cpp \
	$(SRCDIR)/xmlcc/xmlccDomDoctype.cpp \
	$(SRCDIR)/xmlcc/xmlccDomController.cpp \
	$(SRCDIR)/xmlcc/xmlccDomHandler.cpp \
	$(SRCDIR)/xmlcc/xmlccDomParser.cpp \
	$(SRCDIR)/xmlcc/xmlccDomTokenizer.cpp \
	$(SRCDIR)/xmlcc/xmlccDomCore.cpp \
	$(SRCDIR)/xmlcc/xmlccSaxHandler.cpp \
	$(SRCDIR)/xmlcc/xmlccSaxHandlerExample.cpp \
	$(SRCDIR)/xmlcc/xmlccSaxParser.cpp \
	$(SRCDIR)/xmlcc/xmlccCfgConfig.cpp \
	$(SRCDIR)/xmlcc/xmlccTestSysList.cpp \
	$(SRCDIR)/xmlcc/xmlccTestSysStrTool.cpp \
	$(SRCDIR)/xmlcc/xmlccTestSysXmlTool.cpp \
	$(SRCDIR)/xmlcc/xmlccTestSysXmlParser.cpp \
	$(SRCDIR)/xmlcc/xmlccTestDomTokenizer.cpp \
	$(SRCDIR)/xmlcc/xmlccTestDomController.cpp \
	$(SRCDIR)/xmlcc/xmlccTestXmlcc.cpp \
	$(SRCDIR)/xmlcc/xmlccTest.cpp \
	$(SRCDIR)/main.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=xmlcc

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	mv $(EXECUTABLE) ./XMLCC/
	
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ./XMLCC/$(EXECUTABLE) 
	rm -f $(OBJECTS)
	
update:
	$(SRCCNTRL) pull
  
commit:
	$(SRCCNTRL) commit
	$(SRCCNTRL) push

# clean out, make an update, and then build
refresh:
	make clean
	make update
	date
	make all
	date
