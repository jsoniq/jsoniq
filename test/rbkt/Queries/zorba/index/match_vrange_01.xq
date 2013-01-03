import module namespace d="www.data.com" at "match_vrange_01.xqlib";

import module namespace ddl = 
"http://www.zorba-xquery.com/modules/store/static/collections/ddl";

import module namespace dml = 
"http://www.zorba-xquery.com/modules/store/static/collections/dml";

import module namespace iddl = 
"http://www.zorba-xquery.com/modules/store/static/indexes/ddl";

declare construction strip;


declare variable $doc := 
<parents>
<parent uri="" child="/zorba" date-time="2013-01-01"/>
<parent uri="/zorba" child="/zorba/repo" date-time="2013-01-01"/>
<parent uri="/zorba/repo" child="/zorba/repo/index1" date-time="2012-01-01"/>
<parent uri="/zorba/repo" child="/zorba/repo/index2" date-time="2013-01-01"/>
<parent uri="/zorba/repo" child="/zorba/repo/index3" date-time="2012-10-31"/>
</parents>;


ddl:create($d:parents);

iddl:create($d:idx);


for $p in $doc/parent
return dml:insert($d:parents, $p);


d:page-count("/zorba/repo")
,
"
"
