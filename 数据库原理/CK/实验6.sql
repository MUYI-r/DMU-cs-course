/* 创建供应部和销售部四位雇员用户 */
CREATE login GE  WITH PASSWORD = '66666Ck.',default_database=tpch
CREATE USER  GE for login GE 
CREATE login zhou   WITH PASSWORD = '66667Ck.',default_database=tpch
CREATE USER  zhou for login zhou 
CREATE login fan  WITH PASSWORD = '66668Ck.',default_database=tpch
CREATE USER  fan for login fan 
CREATE login shu  WITH PASSWORD = '66669Ck.',default_database=tpch
CREATE USER  shu for login shu 

/*创建供应部和销售部两位经理用户，其权限为超级用户权限*/
CREATE login jiang  WITH PASSWORD = '66669Ck.',default_database=tpch
CREATE USER  jiang for login jiang 
EXEC sp_addrolemember'db_owner','jiang'

CREATE login si  WITH PASSWORD = '66669Ck.',default_database=tpch
CREATE USER  si for login si 
EXEC sp_addrolemember'db_owner','si'

/*以供应部为例，以姜文经理用户登录数据库，按照上述应用情况，给葛优授予相应的权限。 */
GRANT SELECT,INSERT on  supplier TO GE
GRANT SELECT,INSERT on  part TO GE
GRANT SELECT,INSERT on  partsupp TO GE

/*以供应部为例，以姜文经理用户登录数据库，按照上述应用情况，给周润发授予相应的可转授的权限；然后以周润发用户登录数据库，把授给周润发的权限转授给范冰冰。
 */
GRANT SELECT,INSERT on  supplier TO zhou WITH GRANT OPTION
GRANT SELECT,INSERT on  part TO zhou WITH GRANT OPTION
GRANT SELECT,INSERT on  partsupp TO zhou WITH GRANT OPTION

GRANT SELECT,INSERT on  supplier TO fan 
GRANT SELECT,INSERT on  part TO fan 
GRANT SELECT,INSERT on  partsupp TO fan 

/* 回收葛优的权限 */

REVOKE SELECT,INSERT on  supplier FROM GE
REVOKE SELECT,INSERT on  part FROM GE
REVOKE SELECT,INSERT on  partsupp FROM GE

/* 回收周润发的权限，以范冰冰用户登录数据库，设计一个SQL语句验证其是否还具有周润发授予的权限。*/

REVOKE SELECT,INSERT on  supplier FROM zhou CASCADE
REVOKE SELECT,INSERT on  part FROM zhou CASCADE
REVOKE SELECT,INSERT on  partsupp FROM zhou CASCADE

INSERT into part(partkey)
VALUES(111)

/* 创建一个供应部角色和销售部角色 */

CREATE role GYB
CREATE role XSB

/* 按照上述应用情况，给供应部角色和销售部角色授予相应表的所有权限*/
GRANT ALL PRIVILEGES ON supplier TO GYB
GRANT ALL PRIVILEGES ON part TO GYB
GRANT ALL PRIVILEGES ON partsupp TO GYB

GRANT ALL PRIVILEGES ON customer TO XSB
GRANT ALL PRIVILEGES ON orders TO GYB

/* 回收供应部角色对各个表的删除数据和修改数据的权限。 */
REVOKE DELETE,UPDATE ON supplier from GYB
REVOKE DELETE,UPDATE ON part from GYB
REVOKE DELETE,UPDATE ON partsupp from GYB

/* 把供应部角色授予葛优和周润发。*/
GRANT GYB TO GE
GRANT GYB TO zhou

exec sp_addrolemember 'GYB','GE';
exec sp_addrolemember 'GYB','zhou';
/* 撤销授予葛优和周润发的角色。*/
REVOKE GYB from GE,zhou
EXEC sp_droprolemember 'GYB','GE'
EXEC sp_droprolemember 'GYB','zhou'

/* 把创建表和视图的权限授予葛优和周润发。*/
GRANT CREATE TABLE,CREATE VIEW to GE,zhou

/* 把零件表、供应商表和供应情况表的选择、插入权限授予葛优和周润发*/
GRANT SELECT,INSERT ON part to GE,zhou
GRANT SELECT,INSERT ON partsupp to GE,zhou
GRANT SELECT,INSERT ON supplier to GE,zhou

/*把供应情况表的供应价格和数量的修改权限授予葛优。 */
GRANT UPDATE(supplycost,availqty) on partsupp to GE