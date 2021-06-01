/*  统计每个顾客订购金额 */

SELECT c.name ,SUM(o.totalprice)
From  customer c,orders o
WHERE c.custkey = o.custkey
GROUP by c.name;

/* 查询平均每个订单金额超过1000元的顾客编号及其姓名。 */

SELECT c.custkey,c.name
FROM orders o, customer c 
WHERE c.custkey = o.custkey
GROUP by c.custkey,c.name
HAVING AVG(o.totalprice) > 1000;

/* 查询订购了“海大”制造的“船舶模拟驾驶舱”的顾客。*/


SELECT c.custkey,c.name
from customer c
WHERE c.custkey IN
(
 select o.custkey
 from orders o,lineitem l,part p
 WHERE o.orderkey = l.orderkey AND 
       l.partkey = p.partkey       
       AND p.name = '船舶模拟驾驶仓' AND p.mfgr = '海大'
)
/* 查询没有购买过“海大”制造的“船舶模拟驾驶舱”的顾客。 */
SELECT c.custkey,c.name
from customer c
WHERE  NOT exists
(
 select *
 from  orders o,lineitem l,part p
 WHERE o.orderkey = l.orderkey AND 
       l.partkey = p.partkey       
       AND p.name = '船舶模拟驾驶仓' AND p.mfgr = '海大'
       AND c.custkey = o.custkey
)

/* 查询至少购买过顾客“张三”购买过的全部零件的顾客姓名。*/
SELECT distinct   c1.name
from              customer c1 ,orders o2,lineitem l2
WHERE             c1.custkey = o2.custkey AND o2.orderkey = l2.orderkey 
AND  not exists
(
  select *
  from  customer c2,orders o1,lineitem l1
  WHERE c2.name = '张三' AND c2.custkey = o1.custkey AND
        l1.orderkey = o1.orderkey AND not exists 
        (
         SELECT *
         from  lineitem l3,orders o3
         WHERE l3.orderkey = o3.orderkey and l3.partkey  = l1.partkey 
         AND   o3.custkey  = o2.custkey

        ) 
  
)


/* 查询顾客“张三”和“李四”都订购过的全部零件的信息。
   查询顾客“张三”和“李四”订购的全部零件的信息。
   顾客“张三”订购过，而“李四”没订购过的零件的信息。 */
SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '张三' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey   
INTERSECT
SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '李四' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey 


SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '张三' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey   
UNION
SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '李四' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey   

SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '张三' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey   
EXCEPT
SELECT p.*
from  part p,customer c,orders o, lineitem l
WHERE c.name = '李四' AND c.custkey = o.custkey 
AND   o.orderkey = l.orderkey AND p.partkey = l.partkey 

/* 查询平均每个订单金额超过1万元的顾客中属于中国的顾客信息。 */
SELECT ct.nationkey ,ct.custkey,ct.name
from 
    (
    SELECT c.nationkey , c.custkey , c.name
    FROM orders o, customer c 
    WHERE c.custkey = o.custkey
    GROUP by c.custkey,c.name,c.nationkey
    HAVING AVG(o.totalprice) > 10000
    ) as ct, nation n
WHERE n.name = 'china' AND n.nationkey = ct.nationkey  


SELECT * 
from customer c
WHERE exists
(
 select *
 FROM lineitem l,orders o
 WHERE c.custkey = o.custkey AND o.orderkey = l.orderkey
       AND exists 
       (
             select *
             FROM part p
             WHERE p.partkey = l.partkey 
                   AND p.mfgr = '海大'
       )
 

)

SELECT c.custkey ,c.name
from customer c
WHERE c.custkey IN 
(
 select o.custkey
 from orders o,lineitem l,part p
 WHERE o.orderkey = l.orderkey AND l.partkey = p.partkey      
       AND p.mfgr = '海大' 
)


USE TPCH



SELECT *
from lineitem
SELECT *
FROM orders
SELECT *
FROM customer
SELECT *
FROM part
select *
FROM supplier
SELECT *
FROM nation
SELECT *
From partsupp


INSERT into orders(orderkey,custkey,totalprice)
VALUES(10,5,89800)
INSERT into part(partkey,name)
VALUES(3,'船舶模拟驾驶仓')
INSERT into supplier(suppkey,name)
VALUES(4,'海大')
INSERT into partsupp(partkey,suppkey)
VALUES(3,4)
Insert into lineitem(orderkey,partkey,suppkey)
VALUES(3,2,4)
INSERT into customer(custkey,name)
VALUES (5,'李四')
UPDATE part
set mfgr = '海大'
WHERE partkey = '3'
