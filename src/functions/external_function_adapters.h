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
#ifndef ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H
#define ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H

#include <vector>
#include <zorba/external_function.h>

#include "common/shared_types.h"

#include "functions/udf.h"

namespace zorba 
{

class stateless_external_function_adapter : public external_function 
{
private:
  StatelessExternalFunction * m_function;
  expr_script_kind_t          theUpdateType;
  xqp_string                  theNamespace;

public:
  SERIALIZABLE_CLASS(stateless_external_function_adapter)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(stateless_external_function_adapter, external_function)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    zorba::serialization::serialize_baseclass(ar, (external_function*)this);
    if(!ar.is_serializing_out())
      m_function = NULL;//don't serialize this for now
    SERIALIZE_ENUM(expr_script_kind_t, theUpdateType);
    ar & theNamespace;
  }

public:
  stateless_external_function_adapter(
        const signature& sig, 
        StatelessExternalFunction *function,
        expr_script_kind_t aUpdateType,
        const xqp_string& aPrefix);
  
  ~stateless_external_function_adapter();

  virtual expr_script_kind_t getUpdateType() const { return theUpdateType; }

  virtual bool isDeterministic() const { return m_function->isDeterministic(); }

  PlanIter_t codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const;
};


} /* namespace zorba */
#endif  /* ZORBA_EXTERNAL_FUNCTION_ADAPTERS_H */
/* vim:set ts=2 sw=2: */
