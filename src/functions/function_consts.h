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
#ifndef ZORBA_FUNCTIONS_FUNCTION_CONSTS
#define ZORBA_FUNCTIONS_FUNCTION_CONSTS

namespace zorba
{

class FunctionConsts
{

public:

typedef enum
{
  FN_UNKNOWN,

  FN_UNORDERED_1,

  FN_ZORBA_DDL_PROBE_INDEX_POINT_VALUE_N,
  FN_ZORBA_DDL_PROBE_INDEX_POINT_GENERAL_N,
  FN_ZORBA_DDL_PROBE_INDEX_RANGE_VALUE_N,
  FN_ZORBA_DDL_PROBE_INDEX_RANGE_GENERAL_N,
  OP_CREATE_INTERNAL_INDEX_2,
  FN_ZORBA_DDL_CREATE_INDEX_1,
  FN_ZORBA_DDL_DELETE_INDEX_1,
  FN_ZORBA_DDL_REFRESH_INDEX_1,
  OP_VALUE_INDEX_ENTRY_BUILDER_N,
  OP_GENERAL_INDEX_ENTRY_BUILDER_N,

  FN_EXACTLY_ONE_1,
  FN_MAX_1,
  FN_MAX_2,
  FN_MIN_1,
  FN_MIN_2,

  FN_BOOLEAN_1,
  FN_NOT_1,
  FN_FALSE_0,
  FN_TRUE_0,

  FN_NAME_1,

  OP_EXACTLY_ONE_NORAISE_1,

  OP_UNION_2,
  OP_INTERSECT_2,
  OP_EXCEPT_2,

  OP_EQUAL_2,
  OP_NOT_EQUAL_2,
  OP_LESS_EQUAL_2,
  OP_GREATER_EQUAL_2,
  OP_LESS_2,
  OP_GREATER_2,

  OP_ATOMIC_VALUES_EQUIVALENT_2,

  OP_VALUE_EQUAL_2,
  OP_VALUE_EQUAL_DOUBLE_2,
  OP_VALUE_EQUAL_FLOAT_2,
  OP_VALUE_EQUAL_DECIMAL_2,
  OP_VALUE_EQUAL_INTEGER_2,
  OP_VALUE_EQUAL_STRING_2,
  OP_VALUE_NOT_EQUAL_2,
  OP_VALUE_NOT_EQUAL_DOUBLE_2,
  OP_VALUE_NOT_EQUAL_FLOAT_2,
  OP_VALUE_NOT_EQUAL_DECIMAL_2,
  OP_VALUE_NOT_EQUAL_INTEGER_2,
  OP_VALUE_NOT_EQUAL_STRING_2,
  OP_VALUE_LESS_EQUAL_2,
  OP_VALUE_LESS_EQUAL_DOUBLE_2,
  OP_VALUE_LESS_EQUAL_FLOAT_2,
  OP_VALUE_LESS_EQUAL_DECIMAL_2,
  OP_VALUE_LESS_EQUAL_INTEGER_2,
  OP_VALUE_LESS_EQUAL_STRING_2,
  OP_VALUE_LESS_2,
  OP_VALUE_LESS_DOUBLE_2,
  OP_VALUE_LESS_FLOAT_2,
  OP_VALUE_LESS_DECIMAL_2,
  OP_VALUE_LESS_INTEGER_2,
  OP_VALUE_LESS_STRING_2,
  OP_VALUE_GREATER_EQUAL_2,
  OP_VALUE_GREATER_EQUAL_DOUBLE_2,
  OP_VALUE_GREATER_EQUAL_FLOAT_2,
  OP_VALUE_GREATER_EQUAL_DECIMAL_2,
  OP_VALUE_GREATER_EQUAL_INTEGER_2,
  OP_VALUE_GREATER_EQUAL_STRING_2,
  OP_VALUE_GREATER_2,
  OP_VALUE_GREATER_DOUBLE_2,
  OP_VALUE_GREATER_FLOAT_2,
  OP_VALUE_GREATER_DECIMAL_2,
  OP_VALUE_GREATER_INTEGER_2,
  OP_VALUE_GREATER_STRING_2,

  OP_ADD_2,
  OP_SUBTRACT_2,
  OP_MULTIPLY_2,
  OP_DIVIDE_2,
  OP_INTEGER_DIVIDE_2,
  OP_MOD_2,

  OP_NUMERIC_ADD_2,
  OP_NUMERIC_ADD_DOUBLE_2,
  OP_NUMERIC_ADD_FLOAT_2,
  OP_NUMERIC_ADD_DECIMAL_2,
  OP_NUMERIC_ADD_INTEGER_2,
  OP_NUMERIC_SUBTRACT_2,
  OP_NUMERIC_SUBTRACT_DOUBLE_2,
  OP_NUMERIC_SUBTRACT_FLOAT_2,
  OP_NUMERIC_SUBTRACT_DECIMAL_2,
  OP_NUMERIC_SUBTRACT_INTEGER_2,
  OP_NUMERIC_MULTIPLY_2,
  OP_NUMERIC_MULTIPLY_DOUBLE_2,
  OP_NUMERIC_MULTIPLY_FLOAT_2,
  OP_NUMERIC_MULTIPLY_DECIMAL_2,
  OP_NUMERIC_MULTIPLY_INTEGER_2,
  OP_NUMERIC_DIVIDE_2,
  OP_NUMERIC_DIVIDE_DOUBLE_2,
  OP_NUMERIC_DIVIDE_FLOAT_2,
  OP_NUMERIC_DIVIDE_DECIMAL_2,
  OP_NUMERIC_DIVIDE_INTEGER_2,
  OP_NUMERIC_INTEGER_DIVIDE_2,
  OP_NUMERIC_MOD_2,

  OP_NOTATION_EQUAL_2,

  OP_UNARY_PLUS_1,
  OP_UNARY_MINUS_1,
  OP_DOUBLE_UNARY_PLUS_1,
  OP_DOUBLE_UNARY_MINUS_1,

  OP_AND_2,
  OP_OR_2,

  OP_VAR_ASSIGN_1,
  OP_VAR_DECLARE_1,
  OP_VAR_EXISTS_1,
  OP_VAR_REF_1,

  OP_EITHER_NODES_OR_ATOMICS_1,
  OP_DISTINCT_NODES_1,
  OP_CHECK_DISTINCT_NODES_1,
  OP_DISTINCT_NODES_OR_ATOMICS_1,
  OP_SORT_NODES_ASC_1,
  OP_SORT_NODES_ASC_OR_ATOMICS_1,
  OP_SORT_NODES_DESC_1,
  OP_SORT_NODES_DESC_OR_ATOMICS_1,
  OP_SORT_DISTINCT_NODES_ASC_1,
  OP_SORT_DISTINCT_NODES_ASC_OR_ATOMICS_1,
  OP_SORT_DISTINCT_NODES_DESC_1,
  OP_SORT_DISTINCT_NODES_DESC_OR_ATOMICS_1,

  OP_ENCLOSED_1,

  OP_HOIST_1,
  OP_UNHOIST_1,

  FN_FOP_1,

#include "functions/function_enum.h"

  FN_MAX_FUNC

} FunctionKind;


typedef enum
{
  NO = 0,
  YES,
  PRESERVE
} AnnotationValue;


typedef enum
{
  DoDistinct    = 1,   // Used by fn:zore-or-one and fn:exaclty-one
  SkipCodeGen   = 2,
  hasFnNamespace = 4,
  isDeterministic = 8,
  isPrivate = 16
} AnnotationFlags;

};

}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set ts=2 sw=2: */

