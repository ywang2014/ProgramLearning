# -*- coding: utf-8 -*-

# 使用SQLite
	# SQLite是一种嵌入式数据库，它的数据库就是一个文件
	# SQLite本身是C写的，而且体积很小
	# 经常被集成到各种应用程序中，甚至在iOS和Android的App中都可以集成
	
# Python就内置了SQLite3，所以，在Python中使用SQLite，不需要安装任何东西，直接使用

# 概念：
	# 表是数据库中存放关系数据的集合，一个数据库里面通常都包含多个表
	# 表和表之间通过外键关联
	# 要操作关系数据库，首先需要连接到数据库，一个数据库连接称为Connection
	# 连接到数据库后，需要打开游标，称之为Cursor，通过Cursor执行SQL语句，然后，获得执行结果
	# Python定义了一套操作数据库的API接口，任何数据库要连接到Python，只需要提供符合Python标准的数据库驱动即可
	# 由于SQLite的驱动内置在Python标准库中，所以我们可以直接来操作SQLite数据库
	
# 导入SQLite驱动
import sqlite3
# 连接到SQLite数据库
# 数据库文件是mytest.db
# 如果文件不存在，则自动在当前目录创建
conn = sqlite3.connect('mytest.db')

# 创建一个Cursor
cursor = conn.cursor()

# 执行一条SQL语句，创建user表
cursor.execute('create table user (id varchar(20) primarykey, name varchar(20))')

# 插入一条记录
cursor.execute('insert into user (id, name) values (\'1\', \'Alice\')')

# 通过rowcount获得插入的行数
print(cursor.rowcount)

# 关闭Cursor
cursor.close()

# 提交事物
conn.commit()

# 关闭connection
conn.close()

## 查询记录
conn = sqlite3.connect('mytest.db')
cursor = conn.cursor()

# 执行查询语句
cursor.execute('select * from user where id = ?', '1')

# 获得查询结果
value = cursor.fetchall()
print(value)
cursor.close()
conn.close()

input('pause!')

## 使用Python的DB-API时，Connection和Cursor对象，打开后一定记得关闭
# 使用Cursor对象执行insert，update，delete语句时，执行结果由rowcount返回影响的行数，就可以拿到执行结果
# 使用Cursor对象执行select语句时，通过featchall()可以拿到结果集。结果集是一个list，每个元素都是一个tuple，对应一行记录。

# 如果SQL语句带有参数，那么需要把参数按照位置传递给execute()方法，有几个?占位符就必须对应几个参数
	# cursor.execute('select * from user where id=?', '1')
	
	
## 在Python中操作数据库时，要先导入数据库对应的驱动，然后，通过Connection对象和Cursor对象操作数据
# 要确保打开的Connection对象和Cursor对象都正确地被关闭，否则，资源就会泄露


## 练习
	# 请编写函数，在Sqlite中根据分数段查找指定的名字：

	# -*- coding: utf-8 -*-
def func():
	import os, sqlite3
	
	db_file = os.path.join(os.path.dirname("E:\\Users\\ZKY\\ProgramLearning\\python\\python-Michael\\DataBase"), 'mytest.db')
	if os.path.isfile(db_file):
		os.remove(db_file)
	
	// 初始化数据
	conn = sqlite3.connect(db_file)
	cursor = conn.cursor()
	cursor.execute('create table user (id varchar(20) primary key, name varchar(20), score int )')
	cursor.execute(r"insert into user values ('001', 'Admin', 95)")
	cursor.execute(r"insert into user values ('002', 'Bob', 60)")
	cursor.execute(r"insert into user values ('003', 'Celo', 80)")
	
	cursor.close()
	conn.commit()
	conn.close()
	
def get_score_in(low, high):
	'''
	返回指定分数区间的名字，按分数从低到高排序
	'''
	
	import sqlite3
	conn = sqlite3.connect('mytest.db')
	cursor = conn.cursor()
	
	cursor.execute('select name from user where score between %s and %s order by score', (low,high))
	'''
	cursor.execute('select name from user where score > ? and score < ? order by score asc', (low, high))
	'''
	value = cursor.fetchall()
	
	print(value)
	
	cursor.close()
	conn.close()

input('pause!')


########################################################
def get_score_in(low, high):
	import sqlite3
    try:
        conn = sqlite3.connect(db_file)
        cursor = conn.cursor()
        cursor.execute('select name from user where score between ? and ? order by score',(low,high))
        values=cursor.fetchall()
    finally:
        cursor.close()
        conn.commit()
        conn.close()
    l=[]
    for data in values:
        l.append(data[0])
    return l
	
	
##############################################


# -*- coding: utf-8 -*-

import os, sqlite3

db_file = os.path.join(os.path.dirname(__file__), 'test.db')
if os.path.isfile(db_file):
    os.remove(db_file)

# 初始数据:
conn = sqlite3.connect(db_file)
cursor = conn.cursor()
cursor.execute('create table user(id varchar(20) primary key, name varchar(20), score int)')
cursor.execute(r"insert into user values ('A-001', 'Adam', 95)")
cursor.execute(r"insert into user values ('A-002', 'Bart', 62)")
cursor.execute(r"insert into user values ('A-003', 'Lisa', 78)")
cursor.close()
conn.commit()
conn.close()

def get_score_in(low, high):
    conn = sqlite3.connect(db_file)
    cursor = conn.cursor()
    try:
        cursor.execute('select name from user where score between ? and ? order by score asc', (low, high))
        values = cursor.fetchall()
    except:
        raise
    finally:
        cursor.close()
        conn.close()
    return [v[0] for v in values]
try:
    assert get_score_in(80, 95) == ['Adam'], get_score_in(80, 95)
except AssertionError:
    print('result is not right: get_score_in(80, 95) is not equal to ["Adam"]')
    raise
finally:
    print('get_score_in(80, 95) = ' + str(get_score_in(80, 95)))

try:
    assert get_score_in(60, 80) == ['Bart', 'Lisa'], get_score_in(60, 80)
except AssertionError:
    print('result is not right: get_score_in(60, 80) is not equal to ["Bart", "Lisa"]')
    raise
finally:
    print('get_score_in(60, 80) = ' + str(get_score_in(60, 80)))

try:
    assert get_score_in(60, 100) == ['Bart', 'Lisa', 'Adam'], get_score_in(60, 100)
except AssertionError:
    print('result is not right: get_score_in(60, 100) is not equal to ["Bart", "Lisa", "Adam"]')
    raise
finally:
    print('get_score_in(60, 100) = ' + str(get_score_in(60, 100)))

运行结果：

get_score_in(80, 95) = ['Adam']
get_score_in(60, 80) = ['Bart', 'Lisa']
get_score_in(60, 100) = ['Bart', 'Lisa', 'Adam']


