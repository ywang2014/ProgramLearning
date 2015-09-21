# -*- coding: utf-8 -*-

# 使用MySql
	# MySQL是Web世界中使用最广泛的数据库服务器
	# SQLite的特点是轻量级、可嵌入，但不能承受高并发访问，适合桌面和移动应用
	# MySQL是为服务器端设计的数据库，能承受高并发访问，同时占用的内存也远远大于SQLite
	# MySQL内部有多种数据库引擎，最常用的引擎是支持数据库事务的InnoDB
	
	
## 安装MySQL

## 安装MySQL驱动
$ pip install mysql-connector-python --allow-external mysql-connector-python

## 演示如何连接到MySQL服务器的test数据库：

# 导入MySQL驱动:
import mysql.connector

# 注意把password设为你的root口令，数据库必须是已经存在的
conn = mysql.connector.connect(user='root', password='root', database='mydb')

cursor = conn.cursor()

# 创建user表:
cursor.execute('create table user (id varchar(20) primary key, name varchar(20))')

# 插入一行记录，注意MySQL的占位符是%s:
cursor.execute('insert into user (id, name) values (%s, %s)', ['1', 'Alice'])
cursor.execute('insert into user (id, name) values (%s, %s)', ['2', 'Bob'])
print(cursor.rowcount)

# 提交事务:
conn.commit()
cursor.close()

# 运行查询:
def func():
	import mysql.connector
	conn = mysql.connector.connect(user='root', password='root', database='mydb')
	cursor = conn.cursor()
	values = []
	cursor.execute('select * from user where id = %s', ['1'])
	values.append(cursor.fetchall())
	'''
	每次查询之后，必须执行cursor.fetchall()，否则报错！错误很奇怪！！！！
	'''
	cursor.execute('select * from user where id = %s', ['2'])
	values.append(cursor.fetchall())
	print(values)

	cursor.close()
	conn.close()
	

	
## 执行INSERT等操作后要调用commit()提交事务；

## MySQL的SQL占位符是%s。SQLite ?
