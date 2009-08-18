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
#include "compiler/parsetree/parsenode_print_xqdoc_visitor.h"

#include <ostream>
#include <stack>

#include "compiler/parsetree/parsenode_print_xquery_visitor.h"
#include "compiler/parsetree/parsenode_visitor.h"

#include "compiler/parser/xqdoc_comment.h"
#include "types/typemanager.h"

using namespace std;

namespace zorba {

#ifndef NDEBUG
#define INDENT(os)  os << std::string(theIndent, ' ')
#define INDENT_INC  theIndent += 2
#define INDENT_DEC  theIndent -= 2
#define NL(os) os << std::endl
#else
#define INDENT(os)
#define INDENT_INC
#define INDENT_DEC
#define NL(os)
#endif

class ParseNodePrintXQDocVisitor : public parsenode_visitor {

private:
  string getLocalName(const string& aQName)
  {
    string::size_type lIndex = aQName.find(':');
    if(lIndex == string::npos)
    {
      return aQName;
    } else {
      return aQName.substr(lIndex+1);
    }
  }

  string getFileName(const string& aFileName)
  {
    string::size_type lIndex = aFileName.find_last_of("/\\");
    if(lIndex == string::npos)
    {
      return aFileName;
    } else {
      return aFileName.substr(lIndex+1);
    }
  }

  void print_comment(ostream& os, const XQDocComment* aComment)
  {
    if(aComment == 0) return;
    list<XQDocAnnotation> lAnnotations = aComment->getAnnotations();
    list<XQDocAnnotation>::const_iterator lIt;

    if(!aComment->getDescription().empty() || lAnnotations.begin()!=lAnnotations.end() ||
        aComment->hasVersion() || aComment->hasReturn() || aComment->isDeprecated())
    {
      os << "<xqdoc:comment>" << endl;
      INDENT_INC; INDENT(os);
      if(!aComment->getDescription().empty())
      {
        os << "<xqdoc:description><![CDATA[" << aComment->getDescription();
        os << "]]></xqdoc:description>" << endl;
      }
      for(lIt = lAnnotations.begin(); lIt != lAnnotations.end(); ++lIt)
      {
        const XQDocAnnotation lAnnotation = *lIt;
        string lNamespace = "xqdoc";
        if(lAnnotation.getType() == TYPE_UNKNOWN)
        {
          lNamespace = "zorbadoc";
        }
        INDENT(os);
        os << "<" << lNamespace << ":" << lAnnotation.getName() << "><![CDATA[" << lAnnotation.getValue();
        os << "]]></" << lNamespace << ":" << lAnnotation.getName() << '>';  NL(os);

      }
      
      if(aComment->hasVersion())
      {
        INDENT(os);
        os << "<xqdoc:version>" << aComment->getVersion() << "</xqdoc:version>";
        NL(os);
      }
    
      if(aComment->hasReturn())
      {
        INDENT(os);
        os << "<xqdoc:return>" << aComment->getReturn() << "</xqdoc:return>";
        NL(os);
      }
    
      if(aComment->isDeprecated())
      {
        INDENT(os);
        os << "<xqdoc:deprecated";
        if(aComment->getDeprecatedComment().empty())
        {
          os << " />"; NL(os);
        } else {
          os << ">" << aComment->getDeprecatedComment() << "</xqdoc:deprecated>"; NL(os);
        }
      }
      INDENT_DEC;
      INDENT(os);
      os << "</xqdoc:comment>"; NL(os);
   }
  }

protected:
    int theIndent;
    ostream& os;
    const string  theFileName;
    stringstream  theImports;
    stringstream  theVariables;
    stringstream  theFunctions;
    string        theQuery;

public:

ParseNodePrintXQDocVisitor(ostream &aStream, const string& aFileName)
  : theIndent(0),
    os(aStream),
    theFileName(getFileName(aFileName))
{
}

void print(const parsenode* p, const store::Item_t& aDateTime)
{
    string lContent;
    os << "<?xml version='1.0' ?>" << endl;
    os << "<xqdoc:xqdoc xmlns:xqdoc='http://www.xqdoc.org/1.0' xmlns:zorbadoc='http://www.zorba-xquery.com/zorba/doc'>" << endl;
    INDENT_INC; INDENT(os);
    os << "<xqdoc:control>" << endl;
    INDENT_INC;
    INDENT(os); os << "<xqdoc:date>" << aDateTime->getStringValue() << "</xqdoc:date>" << endl;
    INDENT(os); os << "<xqdoc:version>1.0</xqdoc:version>" << endl;
    INDENT_DEC; INDENT(os);
    os << "</xqdoc:control>" << endl;
    p->accept(*this);
    lContent = theImports.str();
    if(!lContent.empty())
    { 
      INDENT(os);
      os << "<xqdoc:imports>" << std::endl;
      os << lContent;
      INDENT(os);
      os << "</xqdoc:imports>" << std::endl;
    }
    lContent = theVariables.str();
    if(!lContent.empty())
    {
      INDENT(os);
      os << "<xqdoc:variables>" << std::endl;
      INDENT(os);
      os << lContent;
      INDENT(os);
      os << "</xqdoc:variables>" << std::endl;
    }
    lContent = theFunctions.str();
    if(!lContent.empty())
    {
      INDENT(os);
      os << "<xqdoc:functions>" << std::endl;
      INDENT(os);
      os << lContent;
      INDENT(os);
      os << "</xqdoc:functions>" << std::endl;
    }
    os << "</xqdoc:xqdoc>" << std::endl;
}

#define IDS \
  " pos='" << n.get_location() << "' ptr='" << &n << "'"


#define XQDOC_NO_BEGIN_TAG( cls )       \
  void *begin_visit(const cls& /*n*/) { \
    return no_state;                    \
  }

#define XQDOC_NO_END_TAG( cls )                                     \
  void end_visit(const cls& /*n*/, void* /*visit_state*/) {}

#define XQDOC_NO_BEGIN_END_TAG( cls ) \
  XQDOC_NO_BEGIN_TAG (cls)            \
  XQDOC_NO_END_TAG (cls)

XQDOC_NO_BEGIN_END_TAG (AbbrevForwardStep)
XQDOC_NO_BEGIN_END_TAG (CaseClause)
XQDOC_NO_BEGIN_END_TAG (DefaultNamespaceDecl)
XQDOC_NO_BEGIN_END_TAG (DirAttr)
XQDOC_NO_BEGIN_END_TAG (ForwardAxis)
XQDOC_NO_BEGIN_END_TAG (GeneralComp)
XQDOC_NO_BEGIN_END_TAG (MainModule)

void* begin_visit(const ModuleDecl& /*n*/) {
  INDENT(os);
  INDENT_INC;
  os << "<xqdoc:module type='library'>";
  INDENT_INC; NL(os);
  return no_state;
}

void end_visit(const ModuleDecl& n, void* /*visit_state*/) {
  INDENT(os);
  os << "<xqdoc:uri>" << n.get_target_namespace() << "</xqdoc:uri>" << endl;
  INDENT(os);
  os << "<xqdoc:name>" << theFileName << "</xqdoc:name>" << endl;
  INDENT(os);
  print_comment(os, n.getComment());
  INDENT_DEC;
  INDENT_DEC;
  INDENT(os);
  os << "</xqdoc:module>" << endl;
}

void* begin_visit(const FunctionDecl& /*n*/) {
  INDENT_INC;
  INDENT(theFunctions);
  INDENT_INC;
  theFunctions << "<xqdoc:function>";
  NL(theFunctions);
  return no_state;
}

void end_visit(const FunctionDecl& n, void* /*visit_state*/) {
  INDENT(theFunctions);
  print_comment(theFunctions, n.getComment());
  INDENT(theFunctions);
  theFunctions << "<xqdoc:name>" << n.get_name()->get_localname() << "</xqdoc:name>" << endl;
  INDENT(theFunctions);
  switch(n.get_type())
  {
    case ParseConstants::fn_read:
      theFunctions << "<zorbadoc:read />";
      break;
    case ParseConstants::fn_update:
      theFunctions << "<zorbadoc:updating />";
      break;
    case ParseConstants::fn_extern:
      theFunctions << "<zorbadoc:external />";
      break;
    case ParseConstants::fn_extern_update:
      theFunctions << "<zorbadoc:updating />";
      theFunctions << "<zorbadoc:external />";
      break;
    case ParseConstants::fn_sequential:
      theFunctions << "<zorbadoc:sequential />";
      break;
    case ParseConstants::fn_extern_sequential:
      theFunctions << "<zorbadoc:sequential />";
      theFunctions << "<zorbadoc:external />";
  }
  theFunctions << endl; 
  INDENT(theFunctions); 
  theFunctions << "<xqdoc:signature><![CDATA["; 
  FunctionDecl lFunctionDeclClone(n.get_location(), n.get_name(), n.get_paramlist(), n.get_return_type(), 0, n.get_type());
  FunctionIndex lIndex = print_parsetree_xquery(theFunctions, &lFunctionDeclClone);
  theFunctions << "]]></xqdoc:signature>" << endl;
  
  INDENT(theFunctions);
  if(n.get_paramlist())
  {
    theFunctions << "<zorbadoc:parameters>" << endl;
    INDENT_INC;
    const rchandle<ParamList> lParamList = n.get_paramlist();
    for (vector<rchandle<Param> >::const_iterator it = lParamList->begin();
            it != lParamList->end(); ++it)
    {
      //const Param* lParam = &**it;
      const string lFnName = lIndex[n.get_name()->get_qname()].top();
      lIndex[n.get_name()->get_qname()].pop();
      size_t lStart = lFnName.find(' ');
      if(lStart != string::npos)
      {
        INDENT(theFunctions);
        const char lOccurence = lFnName.at(lFnName.length()-1);
        string lType = lFnName.substr(lStart+4);
        theFunctions << "<zorbadoc:parameter name='" << lFnName.substr(0, lStart) << "' ";//type='"<< lFnName.substr(lStart+4) << "' />" << endl;
        if(lOccurence == '*' || lOccurence == '?' || lOccurence == '+')
        {
          theFunctions << "type='" << lType.substr(0, lType.length()-1) << "' occurrence='" << lOccurence << "' "; 
        } else {
          theFunctions << "type='" << lType << "' "; 
        }
        theFunctions << "/>" << endl;;
      } else {
        INDENT(theFunctions);
        theFunctions << "<zorbadoc:parameter name='" << lFnName << "' />";
      }
    }
    INDENT_DEC;
    INDENT(theFunctions);
    theFunctions << "</zorbadoc:parameters>" << endl;;
  } else {
    theFunctions << "<zorbadoc:parameters />" << endl;
  }

  INDENT_DEC;
  INDENT_DEC;
  INDENT(theFunctions);
  theFunctions << "</xqdoc:function>" << endl;
}

void* begin_visit(const VarDecl&) {
  INDENT_INC;
  INDENT(theVariables);
  INDENT_INC;
  theVariables << "<xqdoc:variable>";
  NL(theVariables);
  return no_state;
}

void end_visit(const VarDecl& n, void*) {
  INDENT(theVariables);
  theVariables << "<xqdoc:uri>" << getLocalName(n.get_varname()) << "</xqdoc:uri>" << endl;
  INDENT(theVariables);
  print_comment(theVariables, n.getComment());
  INDENT_DEC;
  INDENT_DEC;
  INDENT(theVariables);
  theVariables << "</xqdoc:variable>" << endl;
}


void* begin_visit(const ModuleImport&) {
  INDENT_INC;
  INDENT(theImports);
  INDENT_INC;
  theImports << "<xqdoc:import>";
  NL(theImports);
  return no_state;
}

void end_visit(const ModuleImport& n, void*) {
  INDENT(theImports);
  theImports << "<xqdoc:uri>" << n.get_uri() << "</xqdoc:uri>" << endl;
  INDENT(theImports);
  print_comment(theImports, n.getComment());
  INDENT_DEC;
  INDENT_DEC;
  INDENT(theImports);
  theImports << "</xqdoc:import>" << endl;
}

XQDOC_NO_BEGIN_END_TAG (SequenceType)
XQDOC_NO_BEGIN_END_TAG (NameTest)
XQDOC_NO_BEGIN_END_TAG (NamespaceDecl)
XQDOC_NO_BEGIN_END_TAG (NodeComp)
XQDOC_NO_BEGIN_END_TAG (GroupByClause)
XQDOC_NO_BEGIN_END_TAG (GroupSpecList)
XQDOC_NO_BEGIN_END_TAG (GroupSpec)
XQDOC_NO_BEGIN_END_TAG (GroupCollationSpec)
XQDOC_NO_BEGIN_END_TAG (Param)
XQDOC_NO_BEGIN_END_TAG (SchemaImport)
XQDOC_NO_BEGIN_END_TAG (URILiteralList)
XQDOC_NO_BEGIN_END_TAG (ValueComp)
XQDOC_NO_BEGIN_END_TAG (VarGetsDecl)
XQDOC_NO_BEGIN_END_TAG (VarInDecl)
XQDOC_NO_BEGIN_END_TAG (VersionDecl)
XQDOC_NO_BEGIN_END_TAG (QName)
XQDOC_NO_BEGIN_END_TAG (CommonContent)
XQDOC_NO_BEGIN_END_TAG (ComparisonExpr)
XQDOC_NO_BEGIN_END_TAG (NumericLiteral)
XQDOC_NO_BEGIN_END_TAG (PathExpr)
XQDOC_NO_BEGIN_END_TAG (RelativePathExpr)
XQDOC_NO_BEGIN_END_TAG (TypeswitchExpr)
XQDOC_NO_BEGIN_END_TAG (VarRef)
XQDOC_NO_BEGIN_END_TAG (VarBinding)
XQDOC_NO_BEGIN_END_TAG (AdditiveExpr)
XQDOC_NO_BEGIN_END_TAG (AndExpr)
XQDOC_NO_BEGIN_END_TAG (AnyKindTest)
XQDOC_NO_BEGIN_END_TAG (AposAttrContentList)
XQDOC_NO_BEGIN_END_TAG (AposAttrValueContent)
XQDOC_NO_BEGIN_END_TAG (ArgList)
XQDOC_NO_BEGIN_END_TAG (AtomicType)
XQDOC_NO_BEGIN_END_TAG (AttributeTest)
XQDOC_NO_BEGIN_END_TAG (AxisStep)
XQDOC_NO_BEGIN_END_TAG (BaseURIDecl)
XQDOC_NO_BEGIN_END_TAG (BlockBody)
XQDOC_NO_BEGIN_END_TAG (BoundarySpaceDecl)
XQDOC_NO_BEGIN_END_TAG (CaseClauseList)
XQDOC_NO_BEGIN_END_TAG (CastableExpr)
XQDOC_NO_BEGIN_END_TAG (CastExpr)
XQDOC_NO_BEGIN_END_TAG (CatchExpr)
XQDOC_NO_BEGIN_END_TAG (CatchListExpr)
XQDOC_NO_BEGIN_END_TAG (CDataSection)
XQDOC_NO_BEGIN_END_TAG (CommentTest)
XQDOC_NO_BEGIN_END_TAG (CompAttrConstructor)
XQDOC_NO_BEGIN_END_TAG (CompCommentConstructor)
XQDOC_NO_BEGIN_END_TAG (CompDocConstructor)
XQDOC_NO_BEGIN_END_TAG (CompElemConstructor)
XQDOC_NO_BEGIN_END_TAG (CompPIConstructor)
XQDOC_NO_BEGIN_END_TAG (CompTextConstructor)
XQDOC_NO_BEGIN_END_TAG (ConstructionDecl)
XQDOC_NO_BEGIN_END_TAG (ContextItemExpr)
XQDOC_NO_BEGIN_END_TAG (CopyNamespacesDecl)
XQDOC_NO_BEGIN_END_TAG (CountClause)
XQDOC_NO_BEGIN_END_TAG (DefaultCollationDecl)
XQDOC_NO_BEGIN_END_TAG (DeleteExpr)
XQDOC_NO_BEGIN_END_TAG (DirAttributeList)
XQDOC_NO_BEGIN_END_TAG (DirAttributeValue)
XQDOC_NO_BEGIN_END_TAG (DirCommentConstructor)
XQDOC_NO_BEGIN_END_TAG (DirElemConstructor)
XQDOC_NO_BEGIN_END_TAG (DirElemContent)
XQDOC_NO_BEGIN_END_TAG (DirElemContentList)
XQDOC_NO_BEGIN_END_TAG (DirPIConstructor)
XQDOC_NO_BEGIN_END_TAG (DocumentTest)
XQDOC_NO_BEGIN_END_TAG (ElementTest)
XQDOC_NO_BEGIN_END_TAG (EmptyOrderDecl)
XQDOC_NO_BEGIN_END_TAG (EnclosedExpr)
XQDOC_NO_BEGIN_END_TAG (EvalExpr)
XQDOC_NO_BEGIN_END_TAG (AssignExpr)
XQDOC_NO_BEGIN_END_TAG (ExitExpr)
XQDOC_NO_BEGIN_END_TAG (Expr)
XQDOC_NO_BEGIN_END_TAG (exprnode)
XQDOC_NO_BEGIN_END_TAG (ExtensionExpr)
XQDOC_NO_BEGIN_END_TAG (FilterExpr)
XQDOC_NO_BEGIN_END_TAG (FlowCtlStatement)
XQDOC_NO_BEGIN_END_TAG (FLWORClauseList)
XQDOC_NO_BEGIN_END_TAG (FLWORExpr)
XQDOC_NO_BEGIN_END_TAG (FLWORWinCond)
XQDOC_NO_BEGIN_END_TAG (ForClause)
XQDOC_NO_BEGIN_END_TAG (ForwardStep)
XQDOC_NO_BEGIN_END_TAG (FTAnd)
XQDOC_NO_BEGIN_END_TAG (FTAnyallOption)
XQDOC_NO_BEGIN_END_TAG (FTBigUnit)
XQDOC_NO_BEGIN_END_TAG (FTCaseOption)
XQDOC_NO_BEGIN_END_TAG (FTContainsExpr)
XQDOC_NO_BEGIN_END_TAG (FTContent)
XQDOC_NO_BEGIN_END_TAG (FTDiacriticsOption)
XQDOC_NO_BEGIN_END_TAG (FTDistance)
XQDOC_NO_BEGIN_END_TAG (FTIgnoreOption)
XQDOC_NO_BEGIN_END_TAG (FTInclExclStringLiteral)
XQDOC_NO_BEGIN_END_TAG (FTInclExclStringLiteralList)
XQDOC_NO_BEGIN_END_TAG (FTLanguageOption)
XQDOC_NO_BEGIN_END_TAG (FTMatchOption)
XQDOC_NO_BEGIN_END_TAG (FTMatchOptionProximity)
XQDOC_NO_BEGIN_END_TAG (FTMatchOptionProximityList)
XQDOC_NO_BEGIN_END_TAG (FTMildnot)
XQDOC_NO_BEGIN_END_TAG (FTOptionDecl)
XQDOC_NO_BEGIN_END_TAG (FTOr)
XQDOC_NO_BEGIN_END_TAG (FTOrderedIndicator)
XQDOC_NO_BEGIN_END_TAG (FTProximity)
XQDOC_NO_BEGIN_END_TAG (FTRange)
XQDOC_NO_BEGIN_END_TAG (FTRefOrList)
XQDOC_NO_BEGIN_END_TAG (FTScope)
XQDOC_NO_BEGIN_END_TAG (FTScoreVar)
XQDOC_NO_BEGIN_END_TAG (FTSelection)
XQDOC_NO_BEGIN_END_TAG (FTStemOption)
XQDOC_NO_BEGIN_END_TAG (FTStopwordOption)
XQDOC_NO_BEGIN_END_TAG (FTStringLiteralList)
XQDOC_NO_BEGIN_END_TAG (FTThesaurusID)
XQDOC_NO_BEGIN_END_TAG (FTThesaurusList)
XQDOC_NO_BEGIN_END_TAG (FTThesaurusOption)
XQDOC_NO_BEGIN_END_TAG (FTTimes)
XQDOC_NO_BEGIN_END_TAG (FTUnaryNot)
XQDOC_NO_BEGIN_END_TAG (FTUnit)
XQDOC_NO_BEGIN_END_TAG (FTWildcardOption)
XQDOC_NO_BEGIN_END_TAG (FTWindow)
XQDOC_NO_BEGIN_END_TAG (FTWords)
XQDOC_NO_BEGIN_END_TAG (FTWordsSelection)
XQDOC_NO_BEGIN_END_TAG (FTWordsValue)
XQDOC_NO_BEGIN_END_TAG (FunctionCall)
XQDOC_NO_BEGIN_END_TAG (IfExpr)
XQDOC_NO_BEGIN_END_TAG (InsertExpr)
XQDOC_NO_BEGIN_END_TAG (InstanceofExpr)
XQDOC_NO_BEGIN_END_TAG (IntersectExceptExpr)
XQDOC_NO_BEGIN_END_TAG (ItemType)
XQDOC_NO_BEGIN_END_TAG (LetClause)
XQDOC_NO_BEGIN_END_TAG (LibraryModule)
XQDOC_NO_BEGIN_END_TAG (Module)
XQDOC_NO_BEGIN_END_TAG (MultiplicativeExpr)
XQDOC_NO_BEGIN_END_TAG (OccurrenceIndicator)
XQDOC_NO_BEGIN_END_TAG (OptionDecl)
XQDOC_NO_BEGIN_END_TAG (OrderByClause)
XQDOC_NO_BEGIN_END_TAG (OrderCollationSpec)
XQDOC_NO_BEGIN_END_TAG (OrderDirSpec)
XQDOC_NO_BEGIN_END_TAG (OrderedExpr)
XQDOC_NO_BEGIN_END_TAG (OrderEmptySpec)
XQDOC_NO_BEGIN_END_TAG (OrderingModeDecl)
XQDOC_NO_BEGIN_END_TAG (OrderModifier)
XQDOC_NO_BEGIN_END_TAG (OrderSpec)
XQDOC_NO_BEGIN_END_TAG (OrderSpecList)
XQDOC_NO_BEGIN_END_TAG (OrExpr)
XQDOC_NO_BEGIN_END_TAG (ParamList)
XQDOC_NO_BEGIN_END_TAG (ParenthesizedExpr)
XQDOC_NO_BEGIN_END_TAG (ParseErrorNode)
XQDOC_NO_BEGIN_END_TAG (parsenode)
XQDOC_NO_BEGIN_END_TAG (PITest)
XQDOC_NO_BEGIN_END_TAG (PositionalVar)
XQDOC_NO_BEGIN_END_TAG (Pragma)
XQDOC_NO_BEGIN_END_TAG (PragmaList)
XQDOC_NO_BEGIN_END_TAG (PredicateList)
XQDOC_NO_BEGIN_END_TAG (Prolog)
XQDOC_NO_BEGIN_END_TAG (QuantifiedExpr)
XQDOC_NO_BEGIN_END_TAG (QueryBody)
XQDOC_NO_BEGIN_END_TAG (QuoteAttrContentList)
XQDOC_NO_BEGIN_END_TAG (QuoteAttrValueContent)
XQDOC_NO_BEGIN_END_TAG (QVarInDecl)
XQDOC_NO_BEGIN_END_TAG (QVarInDeclList)
XQDOC_NO_BEGIN_END_TAG (RangeExpr)
XQDOC_NO_BEGIN_END_TAG (RenameExpr)
XQDOC_NO_BEGIN_END_TAG (ReplaceExpr)
XQDOC_NO_BEGIN_END_TAG (RevalidationDecl)
XQDOC_NO_BEGIN_END_TAG (ReverseAxis)
XQDOC_NO_BEGIN_END_TAG (ReverseStep)
XQDOC_NO_BEGIN_END_TAG (SchemaAttributeTest)
XQDOC_NO_BEGIN_END_TAG (SchemaElementTest)
XQDOC_NO_BEGIN_END_TAG (SchemaPrefix)
//XQDOC_NO_BEGIN_END_TAG (SequenceType)
XQDOC_NO_BEGIN_END_TAG (SignList)
XQDOC_NO_BEGIN_END_TAG (SIND_DeclList)
XQDOC_NO_BEGIN_END_TAG (DecimalFormatNode)
XQDOC_NO_BEGIN_END_TAG (SingleType)
XQDOC_NO_BEGIN_END_TAG (StringLiteral)
XQDOC_NO_BEGIN_END_TAG (TextTest)
XQDOC_NO_BEGIN_END_TAG (TransformExpr)
XQDOC_NO_BEGIN_END_TAG (TreatExpr)
XQDOC_NO_BEGIN_END_TAG (TryExpr)
XQDOC_NO_BEGIN_END_TAG (TypeName)
XQDOC_NO_BEGIN_END_TAG (UnaryExpr)
XQDOC_NO_BEGIN_END_TAG (UnionExpr)
XQDOC_NO_BEGIN_END_TAG (UnorderedExpr)
XQDOC_NO_BEGIN_END_TAG (ValidateExpr)
XQDOC_NO_BEGIN_END_TAG (CtxItemDecl)
XQDOC_NO_BEGIN_END_TAG (IndexDecl)
XQDOC_NO_BEGIN_END_TAG (IndexField)
XQDOC_NO_BEGIN_END_TAG (IndexFieldList)
XQDOC_NO_BEGIN_END_TAG (IndexStatement)
XQDOC_NO_BEGIN_END_TAG (VarGetsDeclList)
XQDOC_NO_BEGIN_END_TAG (VarInDeclList)
XQDOC_NO_BEGIN_END_TAG (CopyVarList)
XQDOC_NO_BEGIN_END_TAG (VFO_DeclList)
XQDOC_NO_BEGIN_END_TAG (WhereClause)
XQDOC_NO_BEGIN_END_TAG (WhileExpr)
XQDOC_NO_BEGIN_END_TAG (Wildcard)
XQDOC_NO_BEGIN_END_TAG (WindowClause)
XQDOC_NO_BEGIN_END_TAG (WindowVarDecl)
XQDOC_NO_BEGIN_END_TAG (WindowVars)

};

void print_parsetree_xqdoc (ostream &os, const parsenode *p, const string& aFileName, const store::Item_t& aDateTime) {
  ParseNodePrintXQDocVisitor v (os, aFileName);
  v.print (p, aDateTime);
}

} // end namespace
