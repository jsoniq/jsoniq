/*
 * Copyright 2011 The FLWOR Foundation.
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
#include "stdafx.h"

#include "functions/func_jsoniq_functions.h"
#include "functions/func_jsoniq_functions_impl.h"

#include "runtime/json/jsoniq_functions.h"
#include "runtime/json/jsoniq_functions_impl.h"
#include "runtime/core/item_iterator.h"

#include "compiler/parser/query_loc.h"
#include "compiler/expression/expr_consts.h"
#include "compiler/expression/fo_expr.h"

#include "types/typeops.h"

namespace zorba
{

#ifdef ZORBA_WITH_JSON


/*******************************************************************************

********************************************************************************/
bool op_zorba_object_insert::mustCopyInputNodes(expr* fo, csize producer) const
{
  if (producer == 0 || (producer % 2))
    return false;

  static_context* sctx = fo->get_sctx();

  if (sctx->preserve_mode() != StaticContextConsts::no_preserve_ns)
  {
    return true;
  }

  return false;
}


PlanIter_t op_zorba_object_insert::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& args,
    expr& ann) const
{
  return new JSONObjectInsertIterator(sctx, loc, args, true);
}


/*******************************************************************************

********************************************************************************/
bool op_zorba_json_array_insert::mustCopyInputNodes(expr* fo, csize producer) const
{
  if (producer == 2 &&
      fo->get_sctx()->preserve_mode() != StaticContextConsts::no_preserve_ns)
  {
    return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool op_zorba_json_replace_value::mustCopyInputNodes(expr* fo, csize producer) const
{
  if (producer == 2 &&
      fo->get_sctx()->preserve_mode() != StaticContextConsts::no_preserve_ns)
  {
    return true;
  }

  return false;
}



/*******************************************************************************

********************************************************************************/
bool op_zorba_json_array_append::mustCopyInputNodes(expr* fo, csize producer) const
{
  if (producer == 2 &&
      fo->get_sctx()->preserve_mode() != StaticContextConsts::no_preserve_ns)
  {
    return true;
  }

  return false;
}



/*******************************************************************************

********************************************************************************/
PlanIter_t op_zorba_json_replace_value::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONReplaceValueIterator(sctx, loc, argv, true);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t fn_jsoniq_parse_json::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  SingletonIterator* lArg = dynamic_cast<SingletonIterator*>(argv[0].getp());
  if (lArg && lArg->getValue()->isAtomic())
  {
    const QueryLoc& lArgLoc = lArg->getLocation();
    return new JSONParseIterator(sctx, loc, argv, lArgLoc);
  }
  else
  {
    QueryLoc lArgLoc = QueryLoc::null;
    return new JSONParseIterator(sctx, loc, argv, lArgLoc);
  }
}


void populate_context_jsoniq_functions_impl(static_context* sctx)
{
  DECL(sctx, op_zorba_object_insert,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops",
                     "",
                     "object-insert"), 
         GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE,
         true,
         GENV_TYPESYSTEM.EMPTY_TYPE));
}


#endif // ZORBA_WITH_JSON

} /* namespace zorba */

/* vim:set et sw=2 ts=2: */