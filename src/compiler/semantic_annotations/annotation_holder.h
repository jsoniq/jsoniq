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
#ifndef ZORBA_ANNOTATION_HOLDER_H
#define ZORBA_ANNOTATION_HOLDER_H

#include <map>
#include "compiler/semantic_annotations/annotations.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/expression/expr_consts.h"

namespace zorba {

class AnnotationHolder : public SimpleRCObject
{
protected:
  typedef std::map<Annotations::Key, Annotation::value_ref_t> annotations_t;

  annotations_t m_annotations;

public:
  SERIALIZABLE_ABSTRACT_CLASS(AnnotationHolder)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnnotationHolder, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar)
  {
	  //ar & m_annotations;
  }

public:
  AnnotationHolder() {}

  virtual ~AnnotationHolder() {}

  void put_annotation(Annotations::Key key, Annotation::value_ref_t annot);

  const Annotation::value_ref_t get_annotation(Annotations::Key key) const;

  void remove_annotation(Annotations::Key key);

  virtual bool is_updating() const = 0;
};

}

#endif /* ZORBA_ANNOTATION_HOLDER_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
