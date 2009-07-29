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
#ifndef ZORBA_CONSTRUCTOR_H
#define ZORBA_CONSTRUCTOR_H

#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {
 
class op_enclosed_expr : public function 
{
public:
  op_enclosed_expr(const signature& sig) : function (sig) {}

  xqtref_t return_type(const std::vector<xqtref_t> &arg_types) const;

  PlanIter_t codegen(CompilerCB* cb,
        short sctx, 
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder &ann) const;
};
  
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
