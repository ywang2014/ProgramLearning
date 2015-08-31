# -*- coding: utf-8 -*-

# 单元测试：用来对一个模块、一个函数或者一个类来进行正确性检验的测试工作
	# “测试驱动开发”（TDD：Test-Driven Development）
# 对于函数abs(),可编写几个测试用例：
	# 1.输入整数：1, 1.2, 0.99			期待返回原值
	# 2.输入负数：-1, -2, -0.5			期待返回值相反值
	# 3.输入0,							期待返回0
	# 4.输入非数值类型：None, [], {}	期待返回TypeError
# 把上面的测试用例放到一个测试模块里，就是一个完整的单元测试

# 编写一个Dict类，这个类的行为和dict一致，但是可以通过属性来访问，用起来就像下面这样：
d = Dict(a = 1, b = 2)
d['a']	# 1
d.a		# 1
# mydict.py
class Dict(dict):
	def __init__(self, **kw):
		supper().__init__(**kw)
		
	def __getattr__(self, key):
		try:
			return self[key]
		except KeyError:
			raise AttributeError(r"'Dict' object has no attribute '%s'" % key)
			
	def __setattr__(self, key, value):
		self[key] = value
		
# 编写单元测试，我们需要引入Python自带的unittest模块，编写mydict_test.py如下：
import unittest

from mydict import Dict

class TestDict(unittest.TestCase):
	def test_init(self):
		d = Dict(a = 1, b = 'test')
		self.assertEqual(d.a, 1)
		self.assertEqual(d.b, 'test')
		self.assertTrue(isinstance(d, dict))
		
	def test_key(self):
		d = Dict()
		d['key'] = 'value'
		self.assertEqual(d.key, 'value')
		
	def test_attr(self):
		d = Dict()
		d.key = 'value'
		self.assertTrue('key' in d)
		self.assertEqual(d['key'], 'value')
		
	def test_keyerror(self):
		d = Dict()
		with self.assertRaises(KeyError):
			value = d['empty']
			
	def test_attrerror(self):
		d = Dict()
		with self.assertRaises(AttributeError):
			value = d.empty
			
# 编写单元测试时，我们需要编写一个测试类，从unittest.TestCase继承
# 对每一类测试都需要编写一个test_xxx()方法
# 由于unittest.TestCase提供了很多内置的条件判断，我们只需要调用这些方法就可以断言输出是否是我们所期望的
# 最常用的断言就是assertEqual()：

self.assertEqual(abs(-1), 1) # 断言函数返回的结果与1相等

# 另一种重要的断言就是期待抛出指定类型的Error，比如通过d['empty']访问不存在的key时，断言会抛出KeyError：
with.self.assertRaises(KeyError):
	value = d['empty']
# 通过d.empty访问不存在的key时，我们期待抛出AttributeError：
with self.assertRaises(AttributeError):
	value = d.empty
	
# 运行单元测试。最简单的运行方式是在mydict_test.py的最后加上两行代码：
if __name__ == '__main__':
	unittest.main()
# 这样就可以把mydict_test.py当做正常的python脚本运行：

$ python3 mydict_test.py

# 另一种方法是在命令行通过参数-m unittest直接运行单元测试：
$python3 -m unittest mydict_test

# setUp tearDown	这两个方法会分别在每调用一个测试方法的前后分别被执行
	# 设想你的测试需要启动一个数据库，这时，就可以在setUp()方法中连接数据库，在tearDown()方法中关闭数据库
class TestDict(unittest.TestCase):
	def setUp(self):
		print('setUp...')
		
	def tearDown(self):
		print('tearDown...')
		
# 可以再次运行测试看看每个测试方法调用前后是否会打印出setUp...和tearDown...


## 单元测试可以有效地测试某个程序模块的行为，是未来重构代码的信心保证
## 单元测试的测试用例要覆盖常用的输入组合、边界条件和异常
## 单元测试代码要非常简单，如果测试代码太复杂，那么测试代码本身就可能有bug
## 单元测试通过了并不意味着程序就没有bug了，但是不通过程序肯定有bug

