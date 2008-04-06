#ifndef ZORBA_PRINTERVISITOR_H
#define ZORBA_PRINTERVISITOR_H

#include "runtime/visitors/planitervisitor.h"

namespace zorba {

class PlanIterator;
class IterPrinter;

#define PRINTER_VISITOR(class)  \
  virtual void beginVisit ( const class& ) ;  \
  virtual void endVisit ( const class& ) ;


/**
 * Visitor implementation to print a tree.
 */
class PrinterVisitor : public PlanIterVisitor 
{
private:
  IterPrinter& thePrinter;
  PlanIterator* theIterator;
      
public:
  PrinterVisitor(IterPrinter& aPrinter, PlanIterator* aIter) 
    : thePrinter(aPrinter),
      theIterator(aIter) {}

  void print();
      
private:
  void printCommons(const PlanIterator* aIter);
      
public:
  virtual ~PrinterVisitor() {}
      
  virtual void beginVisit ( const FnDataIterator& ) ;
  virtual void endVisit ( const FnDataIterator& ) ;
       
  virtual void beginVisit ( const FnRootIterator& ) ;
  virtual void endVisit ( const FnRootIterator& ) ;
       
  virtual void beginVisit ( const FnNodeNameIterator& ) ;
  virtual void endVisit ( const FnNodeNameIterator& ) ;

  virtual void beginVisit ( const FnNilledIterator& ) ;
  virtual void endVisit ( const FnNilledIterator& ) ;

  virtual void beginVisit ( const FnBaseUriIterator& ) ;
  virtual void endVisit ( const FnBaseUriIterator& ) ;

  virtual void beginVisit ( const FnDocumentUriIterator& ) ;
  virtual void endVisit ( const FnDocumentUriIterator& ) ;

  virtual void beginVisit ( const FnResolveUriIterator& ) ;
  virtual void endVisit ( const FnResolveUriIterator& ) ;
  
  virtual void beginVisit ( const FnStringIterator& ) ;
  virtual void endVisit ( const FnStringIterator& ) ;

  virtual void beginVisit ( const FnLocalNameIterator& ) ;
  virtual void endVisit ( const FnLocalNameIterator& ) ;

  virtual void beginVisit ( const FnNamespaceUriIterator& ) ;
  virtual void endVisit ( const FnNamespaceUriIterator& ) ;

  virtual void beginVisit ( const FnLangIterator& ) ;
  virtual void endVisit ( const FnLangIterator& ) ;

  virtual void beginVisit ( const FnCollectionIterator& ) ;
  virtual void endVisit ( const FnCollectionIterator& ) ;

  virtual void beginVisit ( const FnErrorIterator& ) ;
  virtual void endVisit ( const FnErrorIterator& ) ;

  virtual void beginVisit ( const FnBooleanIterator& ) ;
  virtual void endVisit ( const FnBooleanIterator& ) ;

  virtual void beginVisit ( const LogicIterator& ) ;
  virtual void endVisit ( const LogicIterator& ) ;

  virtual void beginVisit ( const CompareIterator& ) ;
  virtual void endVisit ( const CompareIterator& ) ;

  virtual void beginVisit ( const ElementIterator& ) ;
  virtual void endVisit ( const ElementIterator& ) ;

  virtual void beginVisit ( const ElementContentIterator& ) ;
  virtual void endVisit ( const ElementContentIterator& ) ;

  virtual void beginVisit ( const UDFunctionCallIterator& ) ;
  virtual void endVisit ( const UDFunctionCallIterator& ) ;

  virtual void beginVisit ( const StatelessExtFunctionCallIterator& ) ;
  virtual void endVisit ( const StatelessExtFunctionCallIterator& ) ;

  virtual void beginVisit ( const AttributeIterator & ) ;
  virtual void endVisit ( const AttributeIterator& ) ;

  virtual void beginVisit ( const DocumentIterator& ) ;
  virtual void endVisit ( const DocumentIterator& ) ;

  virtual void beginVisit ( const DocumentContentIterator& ) ;
  virtual void endVisit ( const DocumentContentIterator& ) ;

  virtual void beginVisit ( const CommentIterator& ) ;
  virtual void endVisit ( const CommentIterator& ) ;

  virtual void beginVisit ( const PiIterator& ) ;
  virtual void endVisit ( const PiIterator& ) ;

  virtual void beginVisit ( const SingletonIterator& ) ;
  virtual void endVisit ( const SingletonIterator& ) ;

  virtual void beginVisit ( const EmptyIterator& ) ;
  virtual void endVisit ( const EmptyIterator& ) ;

  virtual void beginVisit ( const ForVarIterator& ) ;
  virtual void endVisit ( const ForVarIterator& ) ;

  virtual void beginVisit ( const LetVarIterator& ) ;
  virtual void endVisit ( const LetVarIterator& ) ;

  virtual void beginVisit ( const EnclosedIterator& ) ;
  virtual void endVisit ( const EnclosedIterator& ) ;

  virtual void beginVisit ( const DocFilterIterator& ) ;
  virtual void endVisit ( const DocFilterIterator& ) ;

  virtual void beginVisit ( const IfThenElseIterator& ) ;
  virtual void endVisit ( const IfThenElseIterator& ) ;

  virtual void beginVisit ( const NodeDistinctIterator& a );
  virtual void endVisit ( const NodeDistinctIterator& a );

  virtual void beginVisit ( const NodeSortIterator& a );
  virtual void endVisit ( const NodeSortIterator& a );
  
  virtual void beginVisit ( const KindTestIterator& ) ;
  virtual void endVisit ( const KindTestIterator& ) ;
  
  virtual void beginVisit ( const NameTestIterator& ) ;
  virtual void endVisit ( const NameTestIterator& ) ;

  virtual void beginVisit ( const SelfAxisIterator& ) ;
  virtual void endVisit ( const SelfAxisIterator& ) ;

  virtual void beginVisit ( const AttributeAxisIterator& ) ;
  virtual void endVisit ( const AttributeAxisIterator& ) ;

  virtual void beginVisit ( const ParentAxisIterator& ) ;
  virtual void endVisit ( const ParentAxisIterator& ) ;

  virtual void beginVisit ( const AncestorAxisIterator& ) ;
  virtual void endVisit ( const AncestorAxisIterator& ) ;
  
  virtual void beginVisit ( const AncestorSelfAxisIterator& ) ;
  virtual void endVisit ( const AncestorSelfAxisIterator& ) ;
  
  virtual void beginVisit ( const RSiblingAxisIterator& ) ;
  virtual void endVisit ( const RSiblingAxisIterator& ) ;
  
  virtual void beginVisit ( const LSiblingAxisIterator& ) ;
  virtual void endVisit ( const LSiblingAxisIterator& ) ;
  
  virtual void beginVisit ( const ChildAxisIterator& ) ;
  virtual void endVisit ( const ChildAxisIterator& ) ;
  
  virtual void beginVisit ( const DescendantAxisIterator& ) ;
  virtual void endVisit ( const DescendantAxisIterator& ) ;
  
  virtual void beginVisit ( const DescendantSelfAxisIterator& ) ;
  virtual void endVisit ( const DescendantSelfAxisIterator& ) ;
  
  virtual void beginVisit ( const PrecedingAxisIterator& ) ;
  virtual void endVisit ( const PrecedingAxisIterator& ) ;
  
  virtual void beginVisit ( const FollowingAxisIterator& ) ;
  virtual void endVisit ( const FollowingAxisIterator& ) ;
  
  virtual void beginVisit ( const InstanceOfIterator& ) ;
  virtual void endVisit ( const InstanceOfIterator& ) ;       
  
  virtual void beginVisit ( const TreatIterator& ) ;
  virtual void endVisit ( const TreatIterator& ) ;
  virtual void beginVisit ( const EitherNodesOrAtomicsIterator& ) ;
  virtual void endVisit ( const EitherNodesOrAtomicsIterator& ) ;
  
  virtual void beginVisit ( const NumArithIterator<AddOperation>& ) ;
  virtual void beginVisit ( const NumArithIterator<SubtractOperation>& ) ;
  virtual void beginVisit ( const NumArithIterator<MultiplyOperation>& ) ;
  virtual void beginVisit ( const NumArithIterator<DivideOperation>& ) ;
  virtual void beginVisit ( const NumArithIterator<IntegerDivideOperation>& ) ;
  virtual void beginVisit ( const NumArithIterator<ModOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<AddOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<SubtractOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<MultiplyOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<DivideOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<IntegerDivideOperation>& ) ;
  virtual void endVisit ( const NumArithIterator<ModOperation>& ) ;

  virtual void beginVisit ( const GenericArithIterator<AddOperation>& ) ;
  virtual void beginVisit ( const GenericArithIterator<SubtractOperation>& ) ;
  virtual void beginVisit ( const GenericArithIterator<MultiplyOperation>& ) ;
  virtual void beginVisit ( const GenericArithIterator<DivideOperation>& ) ;
  virtual void beginVisit ( const GenericArithIterator<IntegerDivideOperation>& ) ;
  virtual void beginVisit ( const GenericArithIterator<ModOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<AddOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<SubtractOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<MultiplyOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<DivideOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<IntegerDivideOperation>& ) ;
  virtual void endVisit ( const GenericArithIterator<ModOperation>& ) ;

  virtual void beginVisit ( const OpNumericUnaryIterator& ) ;
  virtual void endVisit ( const OpNumericUnaryIterator& ) ;
  
  virtual void beginVisit ( const FnAbsIterator& ) ;
  virtual void endVisit ( const FnAbsIterator& ) ;
  
  virtual void beginVisit( const FnCeilingIterator& );
  virtual void endVisit( const FnCeilingIterator& );
  
  virtual void beginVisit( const FnFloorIterator& );
  virtual void endVisit( const FnFloorIterator& );
  
  virtual void beginVisit( const FnRoundIterator& );
  virtual void endVisit( const FnRoundIterator& );
  
  virtual void beginVisit( const FnRoundHalfToEvenIterator& );
  virtual void endVisit( const FnRoundHalfToEvenIterator& );
  
  virtual void beginVisit ( const FnConcatIterator& ) ;
  virtual void endVisit ( const FnConcatIterator& ) ;
  
  virtual void beginVisit ( const FnEmptyIterator& ) ;
  virtual void endVisit ( const FnEmptyIterator& ) ;
  
  virtual void beginVisit ( const FnExistsIterator& ) ;
  virtual void endVisit ( const FnExistsIterator& ) ;
  
  virtual void beginVisit ( const FnIndexOfIterator& ) ;
  virtual void endVisit ( const FnIndexOfIterator& ) ;
  
  virtual void beginVisit ( const FnRemoveIterator& ) ;
  virtual void endVisit ( const FnRemoveIterator& ) ;
  
  virtual void beginVisit ( const FnReverseIterator& ) ;
  virtual void endVisit ( const FnReverseIterator& ) ;
  
  virtual void beginVisit ( const OpToIterator& ) ;
  virtual void endVisit ( const OpToIterator& ) ;

  virtual void beginVisit ( const FnIdIterator& ) ;
  virtual void endVisit ( const FnIdIterator& ) ;

  virtual void beginVisit ( const FnIdRefIterator& ) ;
  virtual void endVisit ( const FnIdRefIterator& ) ;
  
  virtual void beginVisit ( const FnDistinctValuesIterator& ) ;
  virtual void endVisit   ( const FnDistinctValuesIterator& ) ;
  
  virtual void beginVisit ( const FnInsertBeforeIterator& ) ;
  virtual void endVisit   ( const FnInsertBeforeIterator& ) ;

  virtual void beginVisit ( const FnSubsequenceIterator& ) ;
  virtual void endVisit   ( const FnSubsequenceIterator& ) ;
  
  virtual void beginVisit ( const FnZeroOrOneIterator& ) ;
  virtual void endVisit   ( const FnZeroOrOneIterator& ) ;
  
  virtual void beginVisit ( const FnOneOrMoreIterator& ) ;
  virtual void endVisit   ( const FnOneOrMoreIterator& ) ;
  
  virtual void beginVisit ( const FnExactlyOneIterator& ) ;
  virtual void endVisit   ( const FnExactlyOneIterator& ) ;
  
  virtual void beginVisit ( const FnCountIterator& );
  virtual void endVisit ( const FnCountIterator& );
  
  virtual void beginVisit ( const FnAvgIterator& );
  virtual void endVisit ( const FnAvgIterator& );
  
  virtual void beginVisit ( const FnMinMaxIterator& );
  virtual void endVisit ( const FnMinMaxIterator& );
  
  virtual void beginVisit ( const FnSumIterator& );
  virtual void endVisit ( const FnSumIterator& );
  
  virtual void beginVisit ( const FnDocIterator& ) ;
  virtual void endVisit ( const FnDocIterator& ) ;

  virtual void beginVisit ( const FnDocAvailableIterator& ) ;
  virtual void endVisit ( const FnDocAvailableIterator& ) ;

  virtual void beginVisit ( const HashSemiJoinIterator& ) ;
  virtual void endVisit ( const HashSemiJoinIterator& ) ;

  virtual void beginVisit ( const SortSemiJoinIterator& ) ;
  virtual void endVisit ( const SortSemiJoinIterator& ) ;

  virtual void beginVisit ( const FnTraceIterator& ) ;
  virtual void endVisit ( const FnTraceIterator& ) ;

  virtual void beginVisit( const ResolveQNameIterator& );
  virtual void endVisit( const ResolveQNameIterator& );

  virtual void beginVisit( const QNameIterator& );
  virtual void endVisit( const QNameIterator& );
  
  virtual void beginVisit( const QNameEqualIterator& );
  virtual void endVisit( const QNameEqualIterator& );

  virtual void beginVisit( const PrefixFromQNameIterator& );
  virtual void endVisit( const PrefixFromQNameIterator& );

  virtual void beginVisit( const LocalNameFromQNameIterator& );
  virtual void endVisit( const LocalNameFromQNameIterator& );

  virtual void beginVisit( const NamespaceUriFromQNameIterator& );
  virtual void endVisit( const NamespaceUriFromQNameIterator& );

  virtual void beginVisit( const NamespaceUriForPrefixlIterator& );
  virtual void endVisit( const NamespaceUriForPrefixlIterator& );

  virtual void beginVisit( const InScopePrefixesIterator& );
  virtual void endVisit( const InScopePrefixesIterator& );
  
  virtual void beginVisit ( const CodepointsToStringIterator& ) ;
  virtual void endVisit ( const CodepointsToStringIterator& ) ;
  
  virtual void beginVisit ( const StringToCodepointsIterator& ) ;
  virtual void endVisit ( const StringToCodepointsIterator& ) ;
  
  virtual void beginVisit ( const CompareStrIterator& ) ;
  virtual void endVisit ( const CompareStrIterator& ) ;
  
  virtual void beginVisit ( const CodepointEqualIterator& ) ;
  virtual void endVisit ( const CodepointEqualIterator& ) ;
  
  virtual void beginVisit ( const ConcatStrIterator& ) ;
  virtual void endVisit ( const ConcatStrIterator& ) ;
  
  virtual void beginVisit ( const StringJoinIterator& ) ;
  virtual void endVisit ( const StringJoinIterator& ) ;
  
  virtual void beginVisit ( const SubstringIterator& ) ;
  virtual void endVisit ( const SubstringIterator& ) ;
  
  virtual void beginVisit ( const StringLengthIterator& ) ;
  virtual void endVisit ( const StringLengthIterator& ) ;
  
  virtual void beginVisit ( const NormalizeSpaceIterator& ) ;
  virtual void endVisit ( const NormalizeSpaceIterator& ) ;
  
  virtual void beginVisit ( const NormalizeUnicodeIterator& ) ;
  virtual void endVisit ( const NormalizeUnicodeIterator& ) ;
  
  virtual void beginVisit ( const UpperCaseIterator& ) ;
  virtual void endVisit ( const UpperCaseIterator& ) ;
  
  virtual void beginVisit ( const LowerCaseIterator& ) ;
  virtual void endVisit ( const LowerCaseIterator& ) ;
  
  virtual void beginVisit ( const TranslateIterator& ) ;
  virtual void endVisit ( const TranslateIterator& ) ;
  
  virtual void beginVisit ( const EncodeForUriIterator& ) ;
  virtual void endVisit ( const EncodeForUriIterator& ) ;
  
  virtual void beginVisit ( const IriToUriIterator& ) ;
  virtual void endVisit ( const IriToUriIterator& ) ;
  
  virtual void beginVisit ( const EscapeHtmlUriIterator& ) ;
  virtual void endVisit ( const EscapeHtmlUriIterator& ) ;
  
  virtual void beginVisit ( const ContainsIterator& ) ;
  virtual void endVisit ( const ContainsIterator& ) ;
  
  virtual void beginVisit ( const StartsWithIterator& ) ;
  virtual void endVisit ( const StartsWithIterator& ) ;
  
  virtual void beginVisit ( const EndsWithIterator& ) ;
  virtual void endVisit ( const EndsWithIterator& ) ;
  
  virtual void beginVisit ( const SubstringBeforeIterator& ) ;
  virtual void endVisit ( const SubstringBeforeIterator& ) ;
  
  virtual void beginVisit ( const SubstringAfterIterator& ) ;
  virtual void endVisit ( const SubstringAfterIterator& ) ;

  virtual void beginVisit ( const FnMatchesIterator& );
  virtual void endVisit ( const FnMatchesIterator& );

  virtual void beginVisit ( const FnReplaceIterator& );
  virtual void endVisit ( const FnReplaceIterator& );

  virtual void beginVisit ( const FnTokenizeIterator& );
  virtual void endVisit ( const FnTokenizeIterator& );
  
  virtual void beginVisit ( const ZorNumGen& ) ;
  virtual void endVisit ( const ZorNumGen& ) ;
  
  virtual void beginVisit ( const TextIterator& ) ;
  virtual void endVisit ( const TextIterator& ) ;
  
  virtual void beginVisit(const FnDateTimeConstructorIterator&) ;
  virtual void endVisit(const FnDateTimeConstructorIterator&);

  virtual void beginVisit(const FnYearsFromDurationIterator&) ;
  virtual void endVisit(const FnYearsFromDurationIterator&);

  virtual void beginVisit(const FnMonthsFromDurationIterator&) ;
  virtual void endVisit(const FnMonthsFromDurationIterator&);

  virtual void beginVisit(const FnDaysFromDurationIterator&) ;
  virtual void endVisit(const FnDaysFromDurationIterator&);

  virtual void beginVisit(const FnHoursFromDurationIterator&) ;
  virtual void endVisit(const FnHoursFromDurationIterator&);

  virtual void beginVisit(const FnMinutesFromDurationIterator&) ;
  virtual void endVisit(const FnMinutesFromDurationIterator&);

  virtual void beginVisit(const FnSecondsFromDurationIterator&) ;
  virtual void endVisit(const FnSecondsFromDurationIterator&);

  virtual void beginVisit(const FnYearFromDatetimeIterator&) ;
  virtual void endVisit(const FnYearFromDatetimeIterator&);

  virtual void beginVisit(const FnMonthFromDatetimeIterator&) ;
  virtual void endVisit(const FnMonthFromDatetimeIterator&);

  virtual void beginVisit(const FnDayFromDatetimeIterator&) ;
  virtual void endVisit(const FnDayFromDatetimeIterator&);

  virtual void beginVisit(const FnHoursFromDatetimeIterator&) ;
  virtual void endVisit(const FnHoursFromDatetimeIterator&);

  virtual void beginVisit(const FnMinutesFromDatetimeIterator&) ;
  virtual void endVisit(const FnMinutesFromDatetimeIterator&);

  virtual void beginVisit(const FnSecondsFromDatetimeIterator&) ;
  virtual void endVisit(const FnSecondsFromDatetimeIterator&);

  virtual void beginVisit(const FnTimezoneFromDatetimeIterator&) ;
  virtual void endVisit(const FnTimezoneFromDatetimeIterator&);

  virtual void beginVisit(const FnYearFromDateIterator&) ;
  virtual void endVisit(const FnYearFromDateIterator&);

  virtual void beginVisit(const FnMonthFromDateIterator&) ;
  virtual void endVisit(const FnMonthFromDateIterator&);

  virtual void beginVisit(const FnDayFromDateIterator&) ;
  virtual void endVisit(const FnDayFromDateIterator&);

  virtual void beginVisit(const FnTimezoneFromDateIterator&) ;
  virtual void endVisit(const FnTimezoneFromDateIterator&);

  virtual void beginVisit(const FnHoursFromTimeIterator&) ;
  virtual void endVisit(const FnHoursFromTimeIterator&);

  virtual void beginVisit(const FnMinutesFromTimeIterator&) ;
  virtual void endVisit(const FnMinutesFromTimeIterator&);

  virtual void beginVisit(const FnSecondsFromTimeIterator&) ;
  virtual void endVisit(const FnSecondsFromTimeIterator&);

  virtual void beginVisit(const FnTimezoneFromTimeIterator&) ;
  virtual void endVisit(const FnTimezoneFromTimeIterator&);

  virtual void beginVisit ( const FLWORIterator& ) ;
  virtual void endVisit ( const FLWORIterator& ) ;
  
  virtual void beginVisit ( const TryCatchIterator& ) ;
  virtual void endVisit ( const TryCatchIterator& ) ;

  virtual void beginVisitFlworWhereClause(const  PlanIterator&);
  virtual void endVisitFlworWhereClause(const PlanIterator&);
  
//virtual void beginVisitFlworVariables();
//virtual void endVisitFlworVariables();
  
  virtual void beginVisitFlworLetVariable(const PlanIterator&, bool, const xqpStringStore&);
  virtual void endVisitFlworLetVariable(const PlanIterator&);
  
  virtual void beginVisitFlworForVariable(const PlanIterator&, const xqpStringStore&);
  virtual void endVisitFlworForVariable(const PlanIterator&);

  virtual void beginVisitFlworOrderBy(const PlanIterator&);
  virtual void endVisitFlworOrderBy(const PlanIterator&);

  virtual void beginVisitFlworReturn(const PlanIterator&);
  virtual void endVisitFlworReturn(const PlanIterator&);
  
  virtual void beginVisit(const CastIterator&);
  virtual void endVisit(const CastIterator&);
  
  virtual void beginVisit(const NameCastIterator&);
  virtual void endVisit(const NameCastIterator&);
  
  virtual void beginVisit(const CastableIterator&);
  virtual void endVisit(const CastableIterator&);
  
  virtual void beginVisit(const PromoteIterator&);
  virtual void endVisit(const PromoteIterator&);
  
  virtual void beginVisit(const CtxVariableIterator&);
  virtual void endVisit(const CtxVariableIterator&);
  
  virtual void beginVisit(const OpIsSameNodeIterator&);
  virtual void endVisit(const OpIsSameNodeIterator&);
  
  virtual void beginVisit(const OpNodeBeforeIterator&);
  virtual void endVisit(const OpNodeBeforeIterator&);
  
  virtual void beginVisit(const OpNodeAfterIterator&);
  virtual void endVisit(const OpNodeAfterIterator&);

  virtual void beginVisit(const FnCurrentDateTimeIterator&);
  virtual void endVisit(const FnCurrentDateTimeIterator&);
  
  virtual void beginVisit(const FnCurrentDateIterator&);
  virtual void endVisit(const FnCurrentDateIterator&);
  
  virtual void beginVisit(const FnCurrentTimeIterator&);
  virtual void endVisit(const FnCurrentTimeIterator&);
  
  virtual void beginVisit(const FnImplicitTimezoneIterator&);
  virtual void endVisit(const FnImplicitTimezoneIterator&);
  
  virtual void beginVisit(const FnDefaultCollationIterator&);
  virtual void endVisit(const FnDefaultCollationIterator&);
  
  PRINTER_VISITOR(FnAdjustToTimeZoneIterator_1);
  PRINTER_VISITOR(FnAdjustToTimeZoneIterator_2);
  PRINTER_VISITOR(InsertIterator);
  PRINTER_VISITOR(DeleteIterator);
  PRINTER_VISITOR(ReplaceIterator);
  PRINTER_VISITOR(RenameIterator);
  PRINTER_VISITOR(TransformIterator);
  PRINTER_VISITOR(FnDeepEqualIterator_3);
};

} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

