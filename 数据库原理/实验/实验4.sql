/* 插入一个新顾客的记录，要求每列都给一个合理的值
插入一条订单明细记录，要求每列都给一个合理的值*/
INSERT into customer
VALUES(6,'chi','china',1,'198',1.2,'a','good');
INSERT into lineitem
VALUES(5,1,1,22,1.2,1.3,0.6,1.4,'g','1','2020-01-01','2020-03-03','2020-01-02','22','22','22');

/*插入一条订单记录，可以只出要的几个字段的值，其中数值字段可以用RANDOM函数随机生成数值*/
INSERT into orders(orderkey,custkey,comment)
VALUES(RAND(100),2,'good');

/* 修改所有零件的零售价，使其价格上浮10%*/
UPDATE part
set retailprice *= 1.1;

/* 修改顾客张三的国籍 */
UPDATE customer
set nationkey = 1
WHERE name = '张三';


/* 删除所有订单记录*/
DELETE 
from orders;

/* 删除2011年1月1日之前订单记录*/
DELETE 
from orders
WHERE orderDATE < '2011-01-01';

/* 创建一个顾客购物统计表，记录每个顾客及其购物总数和总价等信息*/
CREATE TABLE customerall
(
   custkey  INTEGER PRIMARY key,
   name     char(10),
   odersnum INTEGER,
   costall  INTEGER,

);

INSERT into customerall
SELECT c.custkey,c.name,COUNT(c.name),SUM(o.totalprice)
From  customer c,orders o
WHERE c.custkey = o.custkey
GROUP by c.custkey,c.name;



/* 把零件表的数据插入零件表中，多次重复执行，知道总记录数达到50万为止，
记录下你执行了多少次？执行过程中你是如何保证实体完整性约束的？*/
INSERT INTO part(partkey,name)
SELECT partkey + (select COUNT(*) FROM part),name from part;


SELECT *
FROM part

/* 修改顾客张三的订单明细记录中111号零件的折扣*/
UPDATE lineitem
set    discount = 0.4
WHERE  orderkey IN 
(
  select o.orderkey
  from customer c,orders o
  WHERE c.name = '张三' AND c.custkey = o.custkey 
    
)  and partkey = 111;

/* 利用LINEITEM表中的详细信息修改对应订单中的totalprice
利用PARTSUPP 表中的供应价格来修改LINEITEM中的EXTENDEDPRICE，
假设：EXTENDEPRICE = SUPPLYCOST * QUANTITY * DISCOUNT*/
UPDATE lineitem
SET extendedprice = p.supplycost * quantity * discount 
FROM partsupp p 
WHERE p.partkey =lineitem.partkey AND p.suppkey = lineitem.suppkey;

UPDATE orders
SET totalprice = p.supplycost * quantity
from partsupp p,lineitem l
WHERE l.orderkey IN
(
    select l1.orderkey
    from   orders o,lineitem l1
    WHERE  o.orderkey = l1.orderkey AND l1.partkey = p.partkey 
           AND p.suppkey = l1.suppkey 
)

/* 删除顾客张三的订单记录*/
DELETE 
from lineitem
WHERE orderkey = 7 or orderkey = 8

DELETE 
From orders
WHERE custkey = 
(
 SELECT c.custkey
 from customer c
 WHERE c.name = '张三'
);

SELECT l.orderkey ,  o.orderkey,o.custkey ,c.name,c.custkey
from lineitem l,orders o,customer c
