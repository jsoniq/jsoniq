/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_QUERY_LOC_H
#define ZORBA_QUERY_LOC_H

#include <string>

#include "zorbatypes/xqpstring.h"
#ifdef ZORBA_DEBUGGER
#include "json/value.h"
#endif

namespace zorba {

/**
 * Class to save the query location of zorba elements that correspond to a code
 * snipped in the query.
 * This class is a replacement of yy::location which is generated by the bison 
 * parser generator. yy::location is used as few as possible in zorba to reduced
 * dependencies to the parser.
 */
class QueryLoc {

public:
  static QueryLoc null;

private:
  xqpString    theFilenameBegin;
  unsigned int theLineBegin;
  unsigned int theColumnBegin;
  xqpString    theFilenameEnd;
  unsigned int theLineEnd;
  unsigned int theColumnEnd;

public:
  QueryLoc();
  QueryLoc(const QueryLoc& aQueryLoc);
  ~QueryLoc(){}
public:
  xqpString    getFilenameBegin() const { return theFilenameBegin; } 
  unsigned int getLineBegin() const     { return theLineBegin; }     
  unsigned int getColumnBegin() const   { return theColumnBegin; }   
  xqpString    getFilenameEnd() const   { return theFilenameEnd; }   
  unsigned int getLineEnd() const       { return theLineEnd; }       
  unsigned int getColumnEnd() const     { return theColumnEnd; }     

  void setFilenameBegin ( std::string* aFilenameBegin ) { theFilenameBegin = *aFilenameBegin; }
  void setLineBegin     ( unsigned int aLineBegin )     { theLineBegin = aLineBegin; }
  void setColumnBegin   ( unsigned int aColumnBegin )   { theColumnBegin = aColumnBegin; }
  void setFilenameEnd   ( std::string* aFilenameEnd )   { theFilenameEnd = *aFilenameEnd; }
  void setLineEnd       ( unsigned int aLineEnd )       { theLineEnd = aLineEnd; }
  void setColumnEnd     ( unsigned int aColumnEnd )     { theColumnEnd = aColumnEnd; }
#ifdef ZORBA_DEBUGGER
  xqpString getFilename() const { return getFilenameBegin(); }
  
  unsigned int getLineno() const { return getLineBegin(); }
  
  xqpString toJSON() const;
  
  void fromJSON( json::value *obj );
 
  bool equals(const QueryLoc& loc) const
  {
    return theFilenameBegin==loc.getFilenameBegin() && theFilenameEnd==loc.getFilenameEnd() &&
           theColumnBegin==loc.getColumnBegin() && theColumnEnd==loc.getColumnEnd() &&
           theLineBegin==loc.getLineBegin() && theLineEnd==loc.getLineEnd();
  }

  bool operator==(const QueryLoc& loc) const
  {
    return equals(loc);    
  }
  
  bool operator<(const QueryLoc& loc) const
  {
    return theLineBegin < loc.getLineBegin();
  }
#endif
};

std::ostream& operator<< (std::ostream& aOstr, const QueryLoc& aQueryLoc);

} // namespace zorba

#endif
