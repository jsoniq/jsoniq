import module namespace ft = "http://www.zorba-xquery.com/modules/full-text";
import module namespace ref = "http://www.zorba-xquery.com/modules/node-reference";

let $x := <p xml:lang="en">Houston, we have a <em>problem</em>!</p>
let $tokens := ft:tokenize( $x )
let $node-ref := $tokens[5]/@node-ref
let $node := ref:node-by-reference( $node-ref )
return $node instance of text()

(: vim:set et sw=2 ts=2: :)