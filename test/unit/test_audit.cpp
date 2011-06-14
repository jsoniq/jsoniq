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

#include <vector>
#include <iostream>
#include <cassert>

#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/audit.h>

int
test_audit(int argc, char* argv[])
{
  void* store = zorba::StoreManager::getStore();
  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance(store);

  zorba::audit::Provider* lAuditProvider = lZorbaInstance->getAuditProvider();
  zorba::audit::Configuration* config = lAuditProvider->createConfiguration();
  std::vector<zorba::String> property_names;
  zorba::audit::Configuration::getPropertyNames(property_names);

  bool lIsStatic;
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/filename");
  assert(lIsStatic);
  lIsStatic = zorba::audit::Configuration::enableProperty(config, property_names,
                                                          "xquery/compilation/duration");
  assert(lIsStatic);

  zorba::audit::Event* event = lAuditProvider->createEvent(config);

  zorba::XQuery_t query = lZorbaInstance->createQuery();
  zorba::StaticContext_t lStaticContext = lZorbaInstance->createStaticContext();

  lStaticContext->setAuditEvent(event);

  Zorba_CompilerHints lHints;
  query->setFileName("test_audit");
  query->compile("1+1", lStaticContext, lHints);
  Zorba_SerializerOptions lSerOptions;
  query->execute(std::cout, &lSerOptions);

  if (event->size() != 1) { //one record
    return 1;
  } else {
    const zorba::audit::Record* lRecord = event->at(0);
    if (lRecord->size() != 2) {
      return 2;
    } else {
      std::cerr << *event << std::endl;
    }
  }


  lZorbaInstance->getAuditProvider()->submitEvent(event);
  lZorbaInstance->getAuditProvider()->destroyConfiguration(config);

  return 0;
}