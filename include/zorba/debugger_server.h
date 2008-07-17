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
#ifndef ZORBA_DEBUGGER_H
#define ZORBA_DEBUGGER_H

#include <istream>


namespace zorba{

/**
 * @
 */

class ZORBA_EXTERN_DECL ZorbaDebugger
{

  public:

    virtual ~ZorbaDebugger(){}
    
    virtual void
    start(  void * aStore, 
            std::istream * aQuery,
            const String & aFileName,
            unsigned short aRequestPort = 8000,
            unsigned short aEventPort = 9000 ) = 0;

    virtual bool
    isEnabled() const = 0;
};
}//end of namespace xqp

#endif
