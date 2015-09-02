# -*- coding: utf-8 -*-

# 把变量从内存中变成可存储或传输的过程称之为序列化
	# 在Python中叫pickling，在其他语言中也被称之为serialization，marshalling，flattening等等
# 序列化之后，就可以把序列化后的内容写入磁盘，或者通过网络传输到别的机器上

# 把变量内容从序列化的对象重新读到内存里称之为反序列化，即unpickling

# pickle模块可实现序列化:
	# 把一个对象序列化并写入文件：
import pickle
d = dict(name = 'Bob', age = 20, score = 88)
pickle.dumps(d)
# pickle.dumps()方法把任意对象序列化成一个bytes，然后，就可以把这个bytes写入文件
# pickle.dump()直接把对象序列化后写入一个file-like Object：

f = open('dump.txt', 'wb')
pickle.dump(d, f)
f.close()
# dump.txt文件，一堆乱七八糟的内容，这些都是Python保存的对象内部信息

# 可以先把内容读到一个bytes，然后用pickle.loads()方法反序列化出对象
# 也可以直接用pickle.load()方法从一个file-like Object中直接反序列化出对象
f = open('dump.txt', 'rb')
d = pickle.load(f)
f.close()
d	# {'age':20, 'score':88, 'name':Bob}
# 这个变量和原来的变量是完全不相干的对象，它们只是内容相同而已

## 只能用Pickle保存那些不重要的数据，不能成功地反序列化也没关系: pickle只能用于python，不同版本可能都不兼容

# 要在不同的编程语言之间传递对象，就必须把对象序列化为标准格式，比如XML
# 更好的方法是序列化为JSON：JSON表示出来就是一个字符串，可以被所有语言读取，也可以方便地存储到磁盘或者通过网络传输
	# JSON不仅是标准格式，并且比XML更快，而且可以直接在Web页面中读取，非常方便
	
# JSON表示的对象就是标准的JavaScript语言的对象，JSON和Python内置的数据类型对应如下：
# JSON类型：  {} [] "string" 123.45 true/false null
# Python类型：dict list str int/float True/False None

# Python内置的json模块提供了非常完善的Python对象到JSON格式的转换
	# 把Python对象变成一个JSON：
import json
d = dict(name = 'Bob', age = 20, score = 88)
json.dumps(d)	# '{"age":20, "score":88, "name":"Bob"}'
# dumps()方法返回一个str，内容就是标准的JSON。dump(): 可以直接把JSON写入一个file-like Object

# loads(): 把JSON的字符串反序列化 load(): 从file-like Object中读取字符串并反序列化
json_str = '{"age":20, "score":88, "name":"Bob"}'
json.loads(json_str)	# {'age':20, 'score':88, 'name':'Bob'}

import json
class Student(object):
	def __init__(self, name, age, score):
		self.name = name
		self.age = age
		self.score = score
		
	def student2dict(std):
		return {
			'name': std.name,
			'age': std.age,
			'score': std.score
		}
		
	def dict2student(d):
		return Student(d['name'], d['age'], d['score'])
		
		
# 有了转换函数，对象就可以顺利序列化为JSON，否则不可以！
s = Student('Bob', 20, 88)
print(json.dumps(s, default = student2dict))
# 输出: {"age":20, "name":"Bob", "score":88}

# 简单方法，把任意class的实例变为dict:
print(json.dumps(s, default = lambda obj: obj.__dict__))
# 因为通常class的实例都有一个__dict__属性，它就是一个dict，用来存储实例变量
	# 少数例外，比如定义了__slots__的class
	# slots的作用是阻止在实例化类时为实例分配dict，默认情况下每个类都会有一个dict,通过__dict__访问
	
# 把JSON反序列化为一个Student对象实例，需要dict2student()函数，转换出dict
# object_hook函数负责把dict转换为Student实例：
json_str = '{"age":20, "score":88, "name":"Bob"}'
print(json.loads(json_str, object_hook = dict2student))
#输出: <__main__.Student object at 0x10cd3c190>

## Python语言特定的序列化模块是pickle
	# 使序列化更通用、更符合Web标准，用json模块
	# json模块的dumps()和loads()函数是定义得非常好的接口的典范