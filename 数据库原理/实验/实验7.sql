/* 创建表时定义由一个属性组成的主键（给约束命名）*/
CREATE TABLE a 
(
  akey INTEGER,
  aname char(10),
  acom  char(10), 
  CONSTRAINT ac PRIMARY key (akey)
) 

/* 创建表时定义由两个或两个以上属性组成的主键（给约束命名） */
CREATE TABLE b
(
 bkey INTEGER,
 bcount INTEGER,
 bname  char(10),

 CONSTRAINT bc PRIMARY key (bkey,bcount)
)

/* 删除以上两个主键约束。*/
ALTER TABLE a 
    DROP CONSTRAINT ac
ALTER TABLE b
    DROP CONSTRAINT bc

/* 利用ALTER TABLE语句定义上述两个主键*/
ALTER TABLE a
ADD CONSTRAINT ac PRIMARY key (akey)

ALTER TABLE b
ADD CONSTRAINT bc PRIMARY key (bkey,bcount)

/* 创建表时定义一个列级参照完整性约束（给约束命名）*/
drop TABLE c

CREATE TABLE c 
(
    akey INTEGER PRIMARY key CONSTRAINT c1 REFERENCES a(akey),
    cname CHAR(10),
    count INTEGER 
)

/* 创建表时定义一个表级的由两个属性组成的参照完整性约束（给约束命名）*/
CREATE TABLE e 
(
    ekey INTEGER PRIMARY key
)

CREATE TABLE d
(
    akey INTEGER,
    ekey INTEGER,
    dname char(10),
    dcom  CHAR(10),
    CONSTRAINT dc PRIMARY key (akey,ekey),
    CONSTRAINT d1 FOREIGN key (akey) REFERENCES a(akey),
    CONSTRAINT d2 FOREIGN key (ekey) REFERENCES e(ekey)
)

/* 设计数据更新语句检查参照完整性约束是否起作用。*/
INSERT into c (akey,cname,count)
VALUES(1,'a',13)

INSERT into d 
VALUES(2,3,'1','1')

/* 删除上述完整性约束。*/
ALTER TABLE c
DROP CONSTRAINT c1

ALTER TABLE d
DROP CONSTRAINT dc,d1,d2

/* 利用ALTER TABLE 建立上述参照完整性约束，并且规定UPDATE/DELETE时的动作*/
ALTER TABLE c
ADD CONSTRAINT c1 FOREIGN key (akey) REFERENCES a(akey)
   ON UPDATE NO ACTION
   ON DELETE NO ACTION;

ALTER TABLE d
ADD CONSTRAINT dc  PRIMARY key (akey,ekey)

ALTER TABLE d
ADD CONSTRAINT d1 FOREIGN key (akey) REFERENCES a(akey)
    ON UPDATE NO ACTION
    ON DELETE NO ACTION;

ALTER TABLE d
ADD CONSTRAINT d2 FOREIGN key (ekey) REFERENCES e(ekey)
    ON UPDATE NO ACTION
    ON DELETE NO ACTION;

/* 设计数据更新语句检查参照完整性约束及其相应的动作是否起作用。*/
INSERT into d
VALUES(1,1,'1','1')
SELECT * from d

update c
set akey = 2
WHERE akey = 1

UPDATE d
SET akey = 2
WHERE akey = 1;




/*定义一个检查约束，检查其值在某个取值范围内，并设计相应的更新语句检查该约束是否起作用 */

ALTER TABLE b
add CONSTRAINT b2 CHECK(bcount between 20 and 30)

insert into b
VALUES(2,1,'3')

/*定义一个检查其值符合某个匹配模式的检查约束（使用LIKE），并设计相应的更新语句检查该约束是否起作用？*/
ALTER TABLE b
add CONSTRAINT b3 CHECK(bname LIKE 'l_' )

INSERT into b
VALUES(3,21,'kl')

/* 定义一个检查其值符合某个正则表达式的检查约束（使用SIMILAR TO），并设计相应的更新语句检查该约束是否起作用？*/



/* 定义一个UNIQUE约束，并设计相应的更新语句检查该约束是否起作用？*/
ALTER TABLE b
ADD  CONSTRAINT b5  UNIQUE (bcount)

INSERT into b
VALUES(1,21,'ll')
INSERT into b
VALUES(2,21,'lo')

/* 定义一个DEFAULT约束，设计一个INSERT语句检查该约束是否起作用*/
ALTER TABLE b
ADD  CONSTRAINT b6  DEFAULT  25 for bcount 

INSERT into b(bkey,bname)
VALUES(3,'lp')

SELECT * 
from b
WHERE bkey = 3