import module namespace
math="http://www.zorba-xquery.com/modules/math";

math:floor(-2.5, 2)

(:
Output: Error [XQP0021] Floor function: both arguments must have the same sign
:)