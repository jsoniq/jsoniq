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

#include "runtime/full_text/ft_single_token_iterator.h"
#include "util/stl_util.h"
#include "zorbaerrors/Assert.h"

namespace zorba {

////////// Constructor(s), cloning ////////////////////////////////////////////

FTSingleTokenIterator::FTSingleTokenIterator( FTToken const &token,
                                              index_t begin ) :
  token_( token ), begin_( begin )
{
  reset();
}

FTTokenIterator_t FTSingleTokenIterator::clone() const {
  return FTTokenIterator_t( new FTSingleTokenIterator( token_, begin_ ) );
}

///////////////////////////////////////////////////////////////////////////////

FTSingleTokenIterator::index_t FTSingleTokenIterator::begin() const {
  return begin_;
}

FTSingleTokenIterator::index_t FTSingleTokenIterator::end() const {
  return begin_ + 1;
}

bool FTSingleTokenIterator::hasNext() const {
  return pos_ == begin_;
}

FTTokenIterator::Mark_t FTSingleTokenIterator::pos() const {
  return Mark_t( new LocalMark( pos_ ) );
}

void FTSingleTokenIterator::pos( Mark_t const &mark ) {
  pos_ = dynamic_cast<LocalMark const&>( *mark ).pos_;
}

bool FTSingleTokenIterator::next( FTToken const **ppToken ) {
  if ( pos_ == begin_ ) {
    if ( ppToken )
      *ppToken = &token_;
    ++pos_;
    return true;
  }
  return false;
}

void FTSingleTokenIterator::reset() {
  pos_ = begin_;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */