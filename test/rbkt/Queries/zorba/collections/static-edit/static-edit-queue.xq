import module namespace ddl = "http://zorba.io/modules/store/static/collections/ddl";
import module namespace dml = "http://zorba.io/modules/store/static/collections/dml";

import module namespace ns = "http://www.example.com/example" at "../collection_001.xqdata";

ddl:create(xs:QName("ns:collection_queue"));

dml:insert-last(xs:QName("ns:collection_queue"), <a/>);

dml:edit(dml:collection(xs:QName("ns:collection_queue")[1]), <b/>);
