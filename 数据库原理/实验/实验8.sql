CREATE DATABASE stma
USE stma

create table Student
(
Sno char(9) primary key,
Sname char(20) not null,
Ssex char(2) check(Ssex in('男','女')),
Sage smallint  check(Sage between 5 and 99),
Sdept char(20) unique
);

create table Course
(
Cno char(4) primary key,
Cname char(40) not null,
Cpno char(4),
Ccredit smallint check(Ccredit between 1 and 8),
);

create table SC
(
Sno char(9),
Cno char(4),
Grade smallint check(Grade between 0 and 100),
primary key(Sno,Cno),
foreign key(Sno) references Student(Sno),
foreign key(Cno) references Course(Cno)
);

INSERT into Student 
VALUES('1','a','男',6,'csa')
INSERT into Student 
VALUES('2','b','女',7,'csb')
INSERT into Student 
VALUES('3','c','男',8,'csc')
INSERT into Student 
VALUES('4','d','女',9,'csd')
INSERT into Student 
VALUES('5','e','男',10,'cse')
INSERT into Student 
VALUES('6','f','女',11,'csf')

INSERT into Course
VALUES('1','a','1',1)
INSERT into Course
VALUES('2','b','2',2)
INSERT into Course
VALUES('3','c','3',3)
INSERT into Course
VALUES('4','d','4',4)
INSERT into Course
VALUES('5','e','5',5)

INSERT into SC
VALUES('1','1',30)
INSERT into SC
VALUES('2','2',50)
INSERT into SC
VALUES('3','3',40)
INSERT into SC
VALUES('4','4',60)
INSERT into SC
VALUES('5','5',20)

SELECT * 
FROM SC,Student

SELECT *
FROM sc,Student
WHERE sc.Sno = Student.Sno AND Student.Sage > 8

SELECT *
FROM sc,Course
WHERE sc.Cno IN
(
    select Cno
    FROM Course
    WHERE Cno > 3
)
