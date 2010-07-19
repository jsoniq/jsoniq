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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#ifndef ZORBA_FUNCTIONS_MATHS_H
#define ZORBA_FUNCTIONS_MATHS_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba {


void populate_context_maths(static_context* sctx);




//fn-zorba-math:sqrt
class fn_zorba_math_sqrt : public function
{
public:
  fn_zorba_math_sqrt(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_SQRT_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:exp
class fn_zorba_math_exp : public function
{
public:
  fn_zorba_math_exp(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_EXP_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:log
class fn_zorba_math_log : public function
{
public:
  fn_zorba_math_log(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_LOG_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:sin
class fn_zorba_math_sin : public function
{
public:
  fn_zorba_math_sin(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_SIN_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:cos
class fn_zorba_math_cos : public function
{
public:
  fn_zorba_math_cos(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_COS_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:tan
class fn_zorba_math_tan : public function
{
public:
  fn_zorba_math_tan(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_TAN_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:asin
class fn_zorba_math_asin : public function
{
public:
  fn_zorba_math_asin(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ASIN_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:acos
class fn_zorba_math_acos : public function
{
public:
  fn_zorba_math_acos(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ACOS_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:atan
class fn_zorba_math_atan : public function
{
public:
  fn_zorba_math_atan(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ATAN_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:atan2
class fn_zorba_math_atan2 : public function
{
public:
  fn_zorba_math_atan2(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ATAN2_2)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:cosh
class fn_zorba_math_cosh : public function
{
public:
  fn_zorba_math_cosh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_COSH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:acosh
class fn_zorba_math_acosh : public function
{
public:
  fn_zorba_math_acosh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ACOSH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:fmod
class fn_zorba_math_fmod : public function
{
public:
  fn_zorba_math_fmod(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_FMOD_2)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:ldexp
class fn_zorba_math_ldexp : public function
{
public:
  fn_zorba_math_ldexp(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_LDEXP_2)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:log10
class fn_zorba_math_log10 : public function
{
public:
  fn_zorba_math_log10(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_LOG10_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:pow
class fn_zorba_math_pow : public function
{
public:
  fn_zorba_math_pow(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_POW_2)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:sinh
class fn_zorba_math_sinh : public function
{
public:
  fn_zorba_math_sinh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_SINH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:asinh
class fn_zorba_math_asinh : public function
{
public:
  fn_zorba_math_asinh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ASINH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:tanh
class fn_zorba_math_tanh : public function
{
public:
  fn_zorba_math_tanh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_TANH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:atanh
class fn_zorba_math_atanh : public function
{
public:
  fn_zorba_math_atanh(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ATANH_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:pi
class fn_zorba_math_pi : public function
{
public:
  fn_zorba_math_pi(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_PI_0)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:isInf
class fn_zorba_math_isInf : public function
{
public:
  fn_zorba_math_isInf(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ISINF_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:isNaN
class fn_zorba_math_isNaN : public function
{
public:
  fn_zorba_math_isNaN(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_ISNAN_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:modf
class fn_zorba_math_modf : public function
{
public:
  fn_zorba_math_modf(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_MODF_1)
  {
  }

  CODEGEN_DECL();
};


//fn-zorba-math:frexp
class fn_zorba_math_frexp : public function
{
public:
  fn_zorba_math_frexp(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_MATH_FREXP_1)
  {
  }

  CODEGEN_DECL();
};


} //namespace zorba


#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 