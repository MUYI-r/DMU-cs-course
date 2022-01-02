

/*
插入数据
部分语句且不是按序执行
*/
INSERT into customer(custkey,name)
VALUES(193816,'赤凯')

INSERT into region
VALUES(1,'am','good');
INSERT into nation
VALUES(1,'USA',1,'good');
INSERT into supplier
VALUES(1,'google','a1',1,'110',1,'good');
INSERT into part
VALUES(1,'a','a1','a2','a',1,'a',100,'good');

INSERT into part
VALUES(2,'b','b1','b2','b',1,'a',100,'good');
INSERT into customer
VALUES(1,'苏举库','a',2,110,1,'1','good');
INSERT into orders(orderkey,custkey,totalprice,orderDATE)
VALUES(3,1,3000,'2021-03-01');/* ??? */
INSERT into supplier(suppkey,name,nationkey)
VALUES(2,'冰山集团',2);
INSERT into supplier(suppkey,name,nationkey)
VALUES(3,'黑水集团',2);
INSERT into nation
VALUES(2,'china',2,'good');
INSERT into partsupp(partkey,suppkey,supplycost)
VALUES(2,1,400);
INSERT into partsupp(partkey,suppkey,supplycost)
VALUES(1,2,4000);
INSERT into orders(orderkey,custkey,totalprice)
VALUES(2,1,200);
INSERT into lineitem(orderkey,partkey,suppkey,extendedprice)
VALUES(1,1,1,100);
UPDATE lineitem set linenumber = 200 WHERE orderkey = 1; 
INSERT into region
VALUES(2,'asia','good');


/* 1 单表查询*/
SELECT NAME,ADDRESS,PHONE
FROM supplier;

/*2 单表单条件查询*/
SELECT  PARTKEY,NAME,RETAILPRICE
FROM part
WHERE retailprice <= 500;

/*3 单表多条件查询*/
SELECT orderkey,custkey,orderdate,totalprice
FROM orders
WHERE totalprice > 1000 AND orderdate  < '2021-04-23'      ; 

/*4 两表链接查询 笛卡儿积操作  */
SELECT s.name,n.name
FROM supplier s,nation n

/*5 两表链接查询 普通链接*/
SELECT p.*,ps.*
FROM part p,partsupp ps
WHERE p.retailprice < ps.supplycost;

/*6 两表链接查询  等值连接*/
SELECT s.name supplier,n.name nation
From supplier s, nation n
WHERE s.nationkey = n.nationkey;

SELECT p.*,ps.*
FROM part p,partsupp ps
WHERE p.retailprice < ps.supplycost; /* ? */

/*7 两表链接  自然链接*/
SELECT s.name supplier,n.name nation
From supplier s join nation n
on s.nationkey = n.nationkey;

SELECT p.*,ps.*
FROM part  p join partsupp ps
on p.retailprice < ps.supplycost; 




/*8 单表自身链接 */
SELECT s1.suppkey,s1.name,s1.address
from supplier s1,supplier s2
WHERE s2.name = '冰山集团' and s1.nationkey = s2.nationkey;


/*9 三表查询*/
SELECT o.orderkey orderkey,o.totalprice totalprice,l.partkey partkey,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l
WHERE c.name = '苏举库' and c.custkey = o.custkey AND o.orderkey=l.orderkey;

/*10 四表链接*/
SELECT o.orderkey orderkey,o.totalprice totalprice,s.supplycost supplycost,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l,partsupp s
WHERE c.name = '苏举库' and c.custkey = o.custkey and o.orderkey = l.orderkey and l.partkey = s.partkey;

/*11 五表查询*/
SELECT o.orderkey orderkey,o.totalprice totalprice,p.name name,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l,part p,partsupp s
WHERE c.name = '苏举库' and c.custkey = o.custkey and o.orderkey = l.orderkey and l.partkey = s.partkey and p.partkey = l.partkey;

/*六表查询*/
SELECT o.orderkey orderkey,o.totalprice totalprice,sp.name suppliername,p.name name,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l,part p,partsupp s,supplier sp
WHERE c.name = '苏举库' and c.custkey = o.custkey and o.orderkey = l.orderkey and l.partkey = s.partkey and p.partkey = l.partkey and sp.suppkey = l.suppkey;

/*七表查询*/
SELECT o.orderkey orderkey,o.totalprice totalprice,sp.name suppliername,p.name name,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l,part p,partsupp s,supplier sp,nation n
WHERE n.name = 'china' and n.nationkey = c.nationkey and c.custkey = o.custkey and o.orderkey = l.orderkey and l.partkey = s.partkey and p.partkey = l.partkey and sp.suppkey = l.suppkey;

/*八表查询*/
SELECT o.orderkey orderkey,o.totalprice totalprice,sp.name suppliername,p.name name,l.linenumber number,totalprice - l.extendedprice trueprice
from customer c,orders o,lineitem l,part p,partsupp s,supplier sp,nation n,region r
WHERE r.name = 'asia' and n.regionkey = r.regionkey and n.nationkey = c.nationkey and c.custkey = o.custkey and o.orderkey = l.orderkey and l.partkey = s.partkey and p.partkey = l.partkey and sp.suppkey = l.suppkey; 