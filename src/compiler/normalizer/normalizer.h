#ifndef ZORBA_NORMALIZER_H
#define ZORBA_NORMALIZER_H

#include "common/shared_types.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_visitor.h"

namespace zorba {

class normalizer : public expr_visitor {
  public:
    normalizer(CompilerCB* aCompilerCB) : m_sctx(aCompilerCB->m_sctx) { }
    ~normalizer() { }

    bool begin_visit(expr&);
    bool begin_visit(var_expr&);
    bool begin_visit(order_modifier&);
    bool begin_visit(flwor_expr&);
    bool begin_visit(case_clause&);
    bool begin_visit(promote_expr&);
    bool begin_visit(trycatch_expr&);
    bool begin_visit(typeswitch_expr&);
    bool begin_visit(if_expr&);
    bool begin_visit(fo_expr&);
    bool begin_visit(ft_select_expr&);
    bool begin_visit(ft_contains_expr&);
    bool begin_visit(instanceof_expr&);
    bool begin_visit(treat_expr&);
    bool begin_visit(castable_expr&);
    bool begin_visit(cast_expr&);
    bool begin_visit(name_cast_expr&);
    bool begin_visit(validate_expr&);
    bool begin_visit(extension_expr&);
    bool begin_visit(relpath_expr&);
    bool begin_visit(axis_step_expr&);
    bool begin_visit(match_expr&);
    bool begin_visit(const_expr&);
    bool begin_visit(order_expr&);
    bool begin_visit(elem_expr&);
    bool begin_visit(doc_expr&);
    bool begin_visit(attr_expr&);
    bool begin_visit(text_expr&);
    bool begin_visit(pi_expr&);
    bool begin_visit(function_def_expr&);
    bool begin_visit(insert_expr&);
    bool begin_visit(delete_expr&);
    bool begin_visit(replace_expr&);
    bool begin_visit(rename_expr&);
    bool begin_visit(transform_expr&);

    void end_visit(expr&);
    void end_visit(var_expr&);
    void end_visit(order_modifier&);
    void end_visit(flwor_expr&);
    void end_visit(case_clause&);
    void end_visit(promote_expr&);
    void end_visit(trycatch_expr&);
    void end_visit(typeswitch_expr&);
    void end_visit(if_expr&);
    void end_visit(fo_expr&);
    void end_visit(ft_select_expr&);
    void end_visit(ft_contains_expr&);
    void end_visit(instanceof_expr&);
    void end_visit(treat_expr&);
    void end_visit(castable_expr&);
    void end_visit(cast_expr&);
    void end_visit(name_cast_expr&);
    void end_visit(validate_expr&);
    void end_visit(extension_expr&);
    void end_visit(relpath_expr&);
    void end_visit(axis_step_expr&);
    void end_visit(match_expr&);
    void end_visit(const_expr&);
    void end_visit(order_expr&);
    void end_visit(elem_expr&);
    void end_visit(doc_expr&);
    void end_visit(attr_expr&);
    void end_visit(text_expr&);
    void end_visit(pi_expr&);
    void end_visit(function_def_expr&);
    void end_visit(insert_expr&);
    void end_visit(delete_expr&);
    void end_visit(replace_expr&);
    void end_visit(rename_expr&);
    void end_visit(transform_expr&);

  private:
    static_context *m_sctx;
};


void normalize_expr_tree (const char *, CompilerCB*, expr_t root);

} /* namespace zorba */
#endif /* ZORBA_NORMALIZER_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set ts=2 sw=2: */
