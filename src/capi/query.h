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
#ifndef ZORBA_QUERY_H
#define ZORBA_QUERY_H

#include <zorba/zorbac.h>

namespace zorbac {

  class Query
  {
    public:
	    static XQUERY_ERROR
      get_dynamic_context(XQC_Query query, XQC_DynamicContext_Ref context);

      static XQUERY_ERROR
      get_static_context(XQC_Query, XQC_StaticContext_Ref context);

	    static XQUERY_ERROR 
      execute(XQC_Query query, FILE*);

	    static XQUERY_ERROR 
      apply_updates(XQC_Query query);

	    static XQUERY_ERROR 
      sequence(XQC_Query query, XQC_Sequence_Ref sequence);

	    static void 
      free(XQC_Query query);

      // private use
      static void
      assign_functions(XQC_Query query);

  };

} /* namespace zorbac */
#endif
