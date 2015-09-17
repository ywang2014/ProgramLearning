# -*- coding: utf-8 -*-

# 使用枚举类
	# 当我们需要定义常量时，一个办法是用大写变量通过整数来定义，例如月份：
JAN = 1
FEB = 2
MAR = 3
# 好处是简单，缺点是类型是int，并且仍然是变量
# Enum类
from enum import Enum 
Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 
'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))
# 枚举所有的成员
for name, member in Month.__members__.items():
	print(name, '=>', member, ',', member.value)
# value属性则是自动赋给成员的int常量，默认从1开始计数
form enum import Enum, unique
@unique
class Student(Enum):
	Freshman = 1	# Freshman,大一新生设置value为1
	Sophomore = 2
	Junior = 3
	Senior = 4
# @unique装饰器可以帮助我们检查保证没有重复值
print(Student.Freshman)
print(Student.Sophomore.value)
print(Student(1))

# 既可以用成员名称引用枚举常量，又可以直接根据value的值获得枚举常量
## Enum可以把一组相关常量定义在一个class中，且class不可变，而且成员可以直接比较