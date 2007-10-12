/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: library.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 */

#include <iostream>

#include "functions/library.h"
#include "functions/function.h"
#include "functions/signature.h"

#include "functions/Accessors.h"
#include "functions/Numerics.h"
#include "functions/Sequences.h"
#include "functions/Strings.h"
#include "functions/Boolean.h"

#include "context/common.h"
#include "util/zorba.h"
#include "types/sequence_type.h"
#include "util/tracer.h"
#include "util/list.h"
#include "store/api/item.h"
#include "store/naive/atomic_items.h"

using namespace std;
namespace xqp {

// clear static initializer state
bool library::static_init = false;


  class initializer;
  static list<const initializer *> initializers;

  class initializer {
    const function &f;
    qnamekey_t &k;

  public:
    initializer (const function &f_, qnamekey_t &k_) : f (f_), k (k_)
    { initializers.push_front (this); }
    const function &run () const {
      k = f.get_fname()->getQNameKey();
      return f;
    }
  };

#define DECL( key, type, sig )                                          \
  qnamekey_t library::key##_key;                                        \
  type key##_tmp_obj (signature sig);                                   \
  initializer key##_tmp_init (key##_tmp_obj, library::key##_key)
  
  
  // Accessors
  DECL (fn_data, fn_data_func,
  			(new QNameItem (XQUERY_FN_NS, "fn", "data"),
  			 xs_anyTypeSeq, xs_anyTypeSeq/*, xs_anySimpleTypeSeq*/));

  DECL (fn_root, fn_root_func,
  			(new QNameItem(XQUERY_FN_NS, "fn", "root"), anyNodeOpt, anyNodeOpt));
  // end Accessors
  
  // Numerics
 	// TODO The parameter and return types of the numeric functions are not correct.
 	// e.g. it is possible to add two untyped atomics or the parameters can be element nodes
 	// which contain a number.
  DECL (op_add, op_numeric_add,
        (new QNameItem (XQUERY_OP_NS,"op","add"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_subtract, op_numeric_subtract,
        (new QNameItem (XQUERY_OP_NS,"op","subtract"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_mul, op_numeric_multiply,
        (new QNameItem (XQUERY_OP_NS,"op","multiply"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_div, op_numeric_divide,
        (new QNameItem (XQUERY_OP_NS,"op","divide"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_idiv, op_numeric_integer_divide,
        (new QNameItem (XQUERY_OP_NS,"op","integer-divide"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_mod, op_numeric_mod,
        (new QNameItem (XQUERY_OP_NS,"op","mod"),
         xs_decimal, xs_decimal, xs_decimal));
  DECL (op_unary_minus, op_numeric_unary_minus, 
  			(new QNameItem (XQUERY_OP_NS,"op","unary-minus"),
  			xs_decimal, xs_decimal));
  DECL (op_unary_plus, op_numeric_unary_plus, 
  			(new QNameItem (XQUERY_OP_NS,"op","unary-plus"),
  			xs_decimal, xs_decimal));

  DECL (fn_abs, fn_abs,
        (new QNameItem(XQUERY_FN_NS, "fn", "abs"),
         xs_decimal,
         xs_decimal));
  // end Numerics

  // Sequences
  DECL (fn_doc, fn_doc_func,
        (new QNameItem(XQUERY_FN_NS,"fn","doc"),
         xs_string,
         documentNode));
  // end Sequences

  // Generic Comparison;
  DECL (op_eq, op_equal,
        (new QNameItem(XQUERY_OP_NS,"op","equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
  DECL (op_ne, op_not_equal,
        (new QNameItem(XQUERY_OP_NS,"op","not-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
  
  DECL (op_gt, op_greater,
        (new QNameItem(XQUERY_OP_NS,"op","greater"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
  DECL (op_ge, op_greater_equal,
        (new QNameItem(XQUERY_OP_NS,"op","greater-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));

   DECL (op_lt, op_less,
        (new QNameItem(XQUERY_OP_NS,"op","less"),
         xs_anyType, xs_anyType,
         xs_boolean));
         
   DECL (op_le, op_less_equal,
        (new QNameItem(XQUERY_OP_NS,"op","less-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
   // end Generic Comparison
   
  // Value Comparison
	DECL (op_val_eq, op_value_equal,
        (new QNameItem(XQUERY_FN_NS,"op","value-equal"),
         xs_anyType, xs_anyType,
         xs_boolean));
      
	DECL (op_val_ne, op_value_not_equal,
				(new QNameItem(XQUERY_FN_NS,"op","value-not-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_val_gt, op_value_greater,
				(new QNameItem(XQUERY_FN_NS,"op","value-greater"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_val_ge, op_value_greater_equal,
				(new QNameItem(XQUERY_FN_NS,"op","value-greater-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_val_lt, op_value_less,
				(new QNameItem(XQUERY_FN_NS,"op","value-less"),
				xs_anyType, xs_anyType,
				xs_boolean));
				
	DECL (op_val_le, op_value_less_equal,
				(new QNameItem(XQUERY_FN_NS,"op","value-less-equal"),
				xs_anyType, xs_anyType,
				xs_boolean));
  // end Value Comparison

  // Strings
  DECL (fn_codepoints_to_string, fn_codepoints_to_string,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoints-to-string"),
         xs_integer,
         xs_string));

  DECL (fn_string_to_codepoints, fn_string_to_codepoints,
        (new QNameItem(XQUERY_FN_NS,"fn","string-to-codepoints"),
         xs_string,
         xs_integer));

  DECL (fn_codepoint_equal, fn_codepoint_equal,
        (new QNameItem(XQUERY_FN_NS,"fn","codepoint-equal"),
         xs_string, xs_string,
         xs_boolean));

  DECL (fn_concat, fn_concat,
        (new QNameItem(XQUERY_FN_NS,"fn","concat"),
         xs_anyType,
         xs_boolean));

  DECL (fn_string_join, fn_string_join,
        (new QNameItem(XQUERY_FN_NS,"fn","string-join"),
         xs_string, xs_string,
         xs_string));

  DECL (fn_string_compare, fn_string_compare,
        (new QNameItem(XQUERY_FN_NS,"fn","compare"),
         xs_string, xs_string, xs_string,
         xs_integer));

  // end Strings

	// start Boolean
	DECL (fn_true, fn_true,
        (new QNameItem(XQUERY_FN_NS,"fn","true"),
         xs_boolean));
  
  DECL (fn_false, fn_false,
        (new QNameItem(XQUERY_FN_NS,"fn","false"),
         xs_boolean));
  
  DECL (fn_boolean, fn_boolean,
        (new QNameItem(XQUERY_FN_NS,"fn","boolean"),
         xs_anyType,
         xs_boolean));
  
  DECL (fn_not, fn_not,
  			(new QNameItem(XQUERY_FN_NS,"fn","not"),
  			xs_anyType,
  			xs_boolean));
	// end Boolean
	
	// start Logic
	DECL (op_and, op_and,
			(new QNameItem(XQUERY_OP_NS,"op","and"),
			xs_anyType,
			xs_boolean));
			
	DECL (op_or, op_or,
			(new QNameItem(XQUERY_OP_NS,"op","or"),
			xs_anyType,
			xs_boolean));
	// end Logic
	
	// begin zorba functions
	DECL (zor_numgen, zor_numgen,
			(new QNameItem(ZORBA_NS,ZORBA_PRE, "numgen"),
			xs_decimal));
	// end zorba functions
	
// TODO


// Comparison operators
qnamekey_t library::op_is_key;
qnamekey_t library::op_precedes_key;
qnamekey_t library::op_follows_key;


// Sequences
qnamekey_t library::op_concatenate_key;
qnamekey_t library::op_union_key;
qnamekey_t library::op_intersect_key;
qnamekey_t library::op_except_key;

// initializer

void library::init(
	ItemFactory* vf_p)
{
  
	if (!library::static_init) {
    while (initializers.size () > 0) {
      const function &f = initializers.pop_front ()->run ();
      put (& f);
    }
    static_init = true; //don't initialize again
	}
}


// ctor, dtor

library::library()
:
	funtab((float)0.6, 1024)
{
	init(&*zorba::getZorbaForCurrentThread()->getItemFactory());
}

library::~library()
{
}


// map interface

void library::put(const function* funp)
{
	qnamekey_t fun_key = funp->get_fname()->getQNameKey();
	funtab.put(fun_key, funp);
}

const function* library::get(qnamekey_t fun_key)
{
//#ifdef DEBUG
//	cout << TRACE << " : fun_key = " << fun_key->qnamekey() << endl;
//#endif

	const function* fun_p = NULL;
	uint64_t key = fun_key;
	if (!funtab.get(key, fun_p)) {
		cout << TRACE << "function not found!\n";
		return NULL;
	}
	return fun_p;
}

} /* namespace xqp */
