xquery version "1.0";
(:
 : Copyright 2006-2011 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
 :)

(:~
 : This module provides a function (np:node-position) that, given a node, 
 : returns positional information about the node in the form of an xs:anyURI
 : item. The module also defines functions that use such positional information
 : to determine: (1) positional relationships between two nodes (e.g. if one 
 : is the ancestor of another) and (2) positional properties of a single node
 : (e.g. its level in the tree).
 :
 : Within this module, the term "node position" will be used to refer to an
 : xs:anyURI item that is returned by the np:node-position function.
 :
 : @author Federico Cavalieri, Markos Zaharioudakis 
 :)
module namespace np = "http://www.zorba-xquery.com/modules/node-position";

declare namespace ver = "http://www.zorba-xquery.com/options/versioning";
declare option ver:module-version "2.0";

(:~
 : Compute a stable and opaque positional information representation 
 : (with type xs:anyURI) for a given node.
 : 
 : <p>Each node in a snapshot has a different URI. Note however that
 : different nodes in different snapshots might have the same URI.</p>  
 :
 : @param $arg the node for which the positional information URI
 :  should be computed
 :
 : @return the opaque positional information URI of the node.
 :)
declare function np:node-position(
  $arg as node()
) as xs:anyURI external;

(:~
 : Determines whether the node position given as second argument is
 : an ancestor of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is an ancestor of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential descendant node position
 : @param $n-pos2 the potential ancestor node position
 :
 : @return true if the node position $n-pos2 is an ancestor of the node position
 : $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function. 
 :)
declare function np:ancestor-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument belongs
 : to the subtree rooted at the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node belongs to the subtree rooted at the 
 : first. Otherwise, the result of the function does not imply anything about 
 : the positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential subtree root node position
 : @param $n-pos2 the potential node in the subtree node position
 :
 : @return true if the node position $n-pos2 belongs to the subtree rooted at 
 : the node position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:in-subtree-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : a descendant of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is a descendant of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential ancestor node position
 : @param $n-pos2 the potential descendant node position
 :
 : @return true if the node position $n-pos2 is a descendant of the node 
 : position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:descendant-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : the parent of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is the parent of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential child node position
 : @param $n-pos2 the potential parent node position
 :
 : @return true if the node position $n-pos2 is the parent of the node position 
 : $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:parent-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : a child of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is a child of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential parent node position
 : @param $n-pos2 the potential child node position
 :
 : @return true if the node position $n-pos2 is a child of the node position 
 : $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:child-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : an attribute of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is an attribute of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential parent node position
 : @param $n-pos2 the potential attribute node position
 :
 : @return true if the node position $n-pos2 is an attribute of the node 
 : position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:attribute-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : a following-sibling of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is a following-sibling of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential preceding-sibling node position
 : @param $n-pos2 the potential following-sibling node position
 :
 : @return true if the node position $n-pos2 is a following-sibling of the node 
 : position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : a preceding-sibling of the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is a preceding-sibling of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential following-sibling node position
 : @param $n-pos2 the potential preceding-sibling node position
 :
 : @return true if the node position $n-pos2 is a preceding-sibling of the node 
 : position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two node positions are siblings.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is a sibling of the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two node positions $n-pos1 and $n-pos2 are siblings; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:sibling-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether the node position given as second argument is
 : following the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is following the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential preceding node position
 : @param $n-pos2 the potential following node position
 :
 : @return true if the node position $n-pos2 is following the node position 
 : $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether the node position given as second argument is
 : following in document order the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is following in document order the 
 : first. Otherwise, the result of the function does not imply anything about 
 : the positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential preceding node position
 : @param $n-pos2 the potential following node position
 :
 : @return true if the node position $n-pos2 is following in document order the
 : node position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:following-in-document-order-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : preceding the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is preceding the first.
 : Otherwise, the result of the function does not imply anything about the
 : positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential following node position
 : @param $n-pos2 the potential preceding node position
 :
 : @return true if the node position $n-pos2 is preceding the node position 
 : $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether the node position given as second argument is
 : preceding in document order the node position given as first argument.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the second node is preceding in document order the 
 : first. Otherwise, the result of the function does not imply anything about 
 : the positional relationship of the two nodes.
 :
 : @param $n-pos1 the potential following node position
 : @param $n-pos2 the potential preceding node position
 :
 : @return true if the node position $n-pos2 is preceding in document order the 
 : node position $n-pos1; false otherwise.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:preceding-in-document-order-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Computes the level of a node position in its tree.
 :
 : Note: The first level has the number one.
 :
 : The result of the function applies to the corresponding node as well, 
 : that is, within the snapshot in which the position was computed, the node 
 : level is the returned one.
 : The result of the function does not imply anything about the
 : node level in other snapshots.
 :
 : @param $n-pos the node position of the node whose level should be 
 : determined.
 :
 : @return the level in the tree of the node position $n-pos as xs:integer.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:level(
  $n-pos as xs:anyURI) as xs:integer external;  

(:~
 : Determines whether a node position corresponds to an attribute node.
 :
 : @param $n-pos the potential attribute node position
 :
 : @return true if the node position $n-pos corresponds to an attribute; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-attribute(
  $n-pos1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node position corresponds to a comment node.
 :
 : @param $n-pos the potential comment node position
 :
 : @return true if the node position $n-pos corresponds to an comment; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-comment(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node position corresponds to a document node.
 :
 : @param $n-pos the potential document node position
 :
 : @return true if the node position $n-pos corresponds to a document; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-document(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node position corresponds to an element node.
 :
 : @param $n-pos the potential element node position
 :
 : @return true if the node position $n-pos corresponds to an element; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-element(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node position corresponds to an processing-instruction
 : node.
 :
 : @param $n-pos the potential processing-instruction node position
 :
 : @return true if the node position $n-pos corresponds to a processing 
 : instruction; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-processing-instruction(
  $n-pos1 as xs:anyURI) as xs:boolean external;
  
(:~
 : Determines whether a node position corresponds to a text node.
 :
 : @param $n-pos the potential text node position
 :
 : @return true if the node position $n-pos corresponds to a text; 
 : false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:is-text(
  $n-pos1 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two node positions belong to the same tree.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the two nodes belong to the same tree. 
 : Otherwise, the result of the function does not imply anything about 
 : the positional relationship of the two nodes.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two nodes whose node positions are $n-pos1
 : and $n-pos2 belong to the same tree.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-tree-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether a node position belongs to a collection.
 :
 : @param $n-pos the node position
 :
 : @return true if the node position $n-pos 
 : belongs to a collection; false otherwise.
 :
 : @error zerr:ZAPI0028 if the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)
declare function np:in-collection(
  $n-pos as xs:anyURI) as xs:boolean external;

(:~
 : Determines whether two node positions belong to the same collection.
 :
 : If the two positions were obtained within the same snapshot S, then the
 : result of the function applies to the corresponding nodes as well, that
 : is, within snapshot S, the two nodes belong to the same collection. 
 : Otherwise, the result of the function does not imply anything about 
 : the positional relationship of the two nodes.
 :
 : @param $n-pos1 a node position
 : @param $n-pos2 a node position
 :
 : @return true if the two nodes whose node positions are $n-pos1
 : and $n-pos2 belong to the same collection.
 :
 : @error zerr:ZAPI0028 if one of the given URI is not a valid node
 : position computed by the <tt>np:node-position</tt> function.
 :)  
declare function np:in-same-collection-of(
  $n-pos1 as xs:anyURI,
  $n-pos2 as xs:anyURI) as xs:boolean external;
