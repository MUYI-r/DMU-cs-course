/* 创建一个“海大汽配”供应商供应的零件视图V_DLMU_PartSupp1，要求列出供应零件的编号、零件名称、可用数量、零售价格、供应价格和备注等信息。 */


CREATE VIEW V_DLMU_PartSupp1 
AS 
SELECT p.partkey,p.name,ps.availqty,p.retailprice,ps.supplycost,p.comment
from supplier s,partsupp ps,part p
WHERE s.name = '海大汽修' AND s.suppkey = ps.suppkey AND p.partkey = ps.partkey

INSERT into V_DLMU_PartSupp1
VALUES(15,'fsa',111,1211,14,'ff')

UPDATE V_DLMU_PartSupp1
SET supplycost = 222
WHERE partkey = 14

DELETE
from V_DLMU_PartSupp1
WHERE partkey = 14 

/* 创建一个视图V_CustAvgOrder，按顾客统计平均每个订单的购买金额和零件种类数量，要求输出顾客编号，姓名，平均购买金额和平均购买零件种类数量。 */
CREATE VIEW V_CustAvgOrder(custkey,name,avgorder,avgnum)
AS 
SELECT c.custkey,c.name,AVG(o.totalprice),avg(l.quantity) 
FROM customer c,orders o,lineitem l
WHERE c.custkey = o.custkey AND l.orderkey = o.orderkey
GROUP BY c.custkey,c.name

INSERT into V_CustAvgOrder
VALUES(19,'ff',1312,31)

UPDATE V_CustAvgOrder
SET avgorder = 222
WHERE custkey = 1

DELETE
from V_CustAvgOrder
WHERE custkey = 5 

/* 创建顾客订购零件明细视图V_CustOrdDetails，要求列出顾客编号、姓名、购买零件数、金额；然后在该视图的基础上，实现（2）中的视图V_CustAvgOrder；
然后删除利用RESTRICT选项删除视图V_CustOrdDetails，观察现象，并解释原因。
利用CASCADE选项删除视图V_CustOrdDetails，观察现象，并检查V_CustAvgOrder是否存在？解释原因？ */
CREATE VIEW V_CustOrdDetails(custkey,name,partnum,totalprice)
AS
SELECT c.custkey,c.name,l.quantity,o.totalprice
from customer c,orders o,lineitem l
WHERE c.custkey = o.custkey AND l.orderkey = o.orderkey

DROP VIEW V_DLMU_PartSupp3

CREATE VIEW V_CustAvgOrder(custkey,name,avgorder,avgnum)
AS
SELECT V.custkey,V.name,AVG(V.totalprice),AVG(V.partnum)
from   V_CustOrdDetails V
GROUP BY V.custkey,V.name

DROP VIEW V_CustOrdDetails ;

DROP VIEW V_CustOrdDetails CASCADE
/* （4）
创建一个“海大汽配”供应商供应的零件视图V_DLMU_PartSupp2，要求列出供应零件的编号、可用数量和供应价格等信息。
然后通过该视图分别增加、删除和修改一条“海大汽配”零件供应记录，验证该视图是否是可更新的？*/

CREATE VIEW V_DLMU_PartSupp2(suppkey,sum,supplycost)
AS
SELECT ps.partkey,ps.availqty,ps.supplycost
From  partsupp ps
WHERE  ps.suppkey IN
(
    select s.suppkey
    from supplier s
    WHERE s.name = '海大汽修'
)

INSERT into V_DLMU_PartSupp2
VALUES(4,4,4)

UPDATE V_DLMU_PartSupp2
SET sum = 16
WHERE suppkey = 13

DELETE
from V_DLMU_PartSupp2
WHERE suppkey = 15


/* 利用WITH CHECK OPTION 选项，创建一个“海大汽配”供应商供应的零件视图V_DLMU_PartSupp3，要求列出供应零件的编号、可用数量和供应价格等信息。
然后通过该视图分别增加、删除和修改一条“海大汽配”零件供应记录，验证WITH CHECK OPTION是否起作用？并比较第（4）题与本题结果有何异同？*/

CREATE VIEW V_DLMU_PartSupp3(suppkey,sum,supplycost)
AS
SELECT ps.partkey,ps.availqty,ps.supplycost
From  partsupp ps
WHERE  ps.suppkey IN
(
    select s.suppkey
    from supplier s
    WHERE s.name = '海大汽配'
)
WITH CHECK OPTION

INSERT into V_DLMU_PartSupp3
VALUES(15,111,12)

UPDATE V_DLMU_PartSupp3
SET sum = 188
WHERE suppkey = 14

DELETE
from V_DLMU_PartSupp3
WHERE suppkey = 13

/* 第（1）题中创建的视图是可更新的吗？第（2）创建的视图是可更新的吗？分别通过SQL更新语句加以验证，并说明原因。 */
CREATE VIEW V3(custkey,avgorder)
AS 
SELECT c.custkey,AVG(o.totalprice) 
FROM customer c,orders o,lineitem l
WHERE c.custkey = o.custkey AND l.orderkey = o.orderkey
GROUP BY c.custkey,c.name

INSERT into V_DLMU_PartSupp1
VALUES(15,123)

UPDATE V3
SET avgorder = 124
WHERE custkey = 1

DELETE
from V3
WHERE custkey = 3




UPDATE supplier
SET name = '海大汽修'
WHERE name = '海大汽配'
SELECT *
FROM V_CustAvgOrder
SELECT *
FROM customer
SELECT *
FROM lineitem
SELECT *
FROM orders




INSERT into partsupp(partkey,suppkey,availqty,supplycost,comment)
values(13,5,11,15,'good')

SELECT *
from  supplier

