CREATE DATABASE TPCH;
USE TPCH;

CREATE TABLE supplier (
	suppkey  INTEGER PRIMARY KEY,
	name CHAR(25),
	address VARCHAR(40),
	nationkey INTEGER,
	phone CHAR(15),
	acctbal REAL,
	comment VARCHAR(101)
    FOREIGN KEY(nationkey) REFERENCES nation (nationkey)
    );

CREATE TABLE part (
	partkey INTEGER PRIMARY KEY,
	name VARCHAR(55),
	mfgr CHAR(25),
	brand CHAR(10),
	type VARCHAR(25),
	size INTEGER,
	container CHAR(10),
	retailprice REAL,
	comment VARCHAR(23)
    );

CREATE TABLE partsupp (
	partkey INTEGER,
	suppkey INTEGER,
	availqty INTEGER,
	supplycost REAL,
	comment VARCHAR(199)
    PRIMARY  KEY(PARTKEY,SUPPKEY),
  
    FOREIGN  KEY(PARTKEY) REFERENCES part(PARTKEY),
    FOREIGN  KEY(SUPPKEY) REFERENCES SUPPLIER(SUPPKEY)
   
    );


CREATE TABLE customer (
	custkey INTEGER PRIMARY KEY,
	name VARCHAR(25),
	address VARCHAR(40),
	nationkey INTEGER,
	phone CHAR(15),
	acctbal REAL,
	mktsegment CHAR(10),
	comment VARCHAR(117)
     FOREIGN   KEY(NATIONKEY) REFERENCES  NATION (NATIONKEY)
    );
	
CREATE TABLE orders (
	orderkey INTEGER PRIMARY KEY,
	custkey INTEGER,
	orderstatus CHAR(1),
	totalprice REAL,
	orderDATE DATE,
	orderpriority CHAR(15),
	clerk CHAR(15),
	shippriority INTEGER,
	comment VARCHAR(79)
    FOREIGN KEY (CUSTKEY) REFERENCES customer (CUSTKEY)
    );

CREATE TABLE lineitem (
	orderkey INTEGER,
	partkey INTEGER,
	suppkey INTEGER,
	linenumber INTEGER,
	quantity REAL,
	extendedprice REAL,
	discount REAL,
	tax REAL,
	returnflag CHAR(1),
	linestatus CHAR(1),
	shipDATE DATE,
	commitDATE DATE,
	receiptDATE DATE,
	shipinstruct CHAR(25),
	shipmode CHAR(10),
	comment VARCHAR(44)
    
    PRIMARY KEY(ORDERKEY,PARTKEY,SUPPKEY),
    FOREIGN KEY(ORDERKEY) REFERENCES  orders(ORDERKEY),
    FOREIGN KEY(PARTKEY) REFERENCES  part(PARTKEY),
    FOREIGN KEY(SUPPKEY) REFERENCES SUPPLIER(SUPPKEY)
    );

CREATE TABLE nation (
	nationkey INTEGER PRIMARY KEY,
	name CHAR(25),
	regionkey INTEGER,
	comment VARCHAR(152)
    
    );

CREATE TABLE region (
	regionkey INTEGER PRIMARY KEY,
	name CHAR(25),
	comment VARCHAR(152)
    
    );

