# -*- coding: utf-8 -*-

# datetime python 处理日期和时间的标准库

# 获取当前日期和时间：
from datetime import datetime
now = datetime.now()	# 获取当前时间
print(now)	# 2015-09-02 20:12:45.471541
print(ytpe(now))

# 注意到datetime是模块，datetime模块还包含一个datetime类，通过from datetime import datetime导入的才是datetime这个类
# 如果仅导入import datetime，则必须引用全名datetime.datetime
# datetime.now()返回当前日期和时间，其类型是datetime

# 获取指定日期和时间
from datetime import datatime
dt = datetime(2015, 9, 2, 20, 30)	# 用指定日期时间创建datetime
print(dt)	# 2015-9-2 20:30:00

# datetime 转换为 timestamp
# 在计算机中，时间实际上是用数字表示的。我们把1970年1月1日 00:00:00 UTC+00:00时区的时刻称为epoch time，记为0
# （1970年以前的时间timestamp为负数），当前时间就是相对于epoch time的秒数，称为timestamp

# timestamp = 0 = 1970-1-1 00:00:00 UTC+0:00
# timestamp = 0 = 1970-1-1 08:00:00 UTC+8:00 # 对应的北京时间
# timestamp的值与时区毫无关系，因为timestamp一旦确定，其UTC时间就确定了

# 把一个datetime类型转换为timestamp只需要简单调用timestamp()方法：
from datetime import datetime
dt = datetime(2015, 9, 2, 20, 37)
dt.timestamp()	# 把datetime转换为timestamp
datetime.now().timestamp() # 1441197515.384598
# 注意Python的timestamp是一个浮点数。如果有小数位，小数位表示毫秒数。

# timestamp转换为datetime
# 要把timestamp转换为datetime，使用datetime提供的fromtimestamp()方法：
from datetime import datetime
t = 1441197515.384598
print(datetime.fromtimestamp(t))

# 注意到timestamp是一个浮点数，它没有时区的概念，而datetime是有时区的
# 上述转换是在timestamp和本地时间做转换。本地时间是指当前操作系统设定的时区。
print(datetime.utcfromtimestamp(t))	# 直接被转换到UTC标准时区的时间


# str转换为Datetime	:	datetime.strptime()
from datetime import datetime
cday = datetime.strptime('2015-09-02 20:46:02', '%Y-%m-%d %H:%M:%S')
print(cday)
# 字符串'%Y-%m-%d %H:%M:%S'规定了日期和时间部分的格式。详细的说明请参考Python文档
# 注意转换后的datetime是没有时区信息的


# datetime 转换为str :	strftime()
from datetime import datetime
now = datetime.now()
print(now.strftime('%a, %b %d %H:%M'))	# Wed, Sep 02 20:58


# datetime 加减
# 对日期和时间进行加减实际上就是把datetime往后或往前计算，得到新的datetime。加减可以直接用+和-运算符，不过需要导入timedelta这个类：

from datetime import datetime, timedelta
now = datetime.now()
now # datetime.datetime(2015, 9, 2, 21, 5, 35, 892882)
now + timedelta(hours = 10)	# datetime.datetime(2015, 9, 3, 7, 5, 35, 892882)
now - timedelta(days = 1)	# datetime.datetime(2015, 9, 1, 21, 5, 35, 892882)
# 使用timedelta你可以很容易地算出前几天和后几天的时刻


# 本地时间转换为UTC时间
# 本地时间是指系统设定时区的时间，例如北京时间是UTC+8:00时区的时间，而UTC时间指UTC+0:00时区的时间

# datetime类型有一个时区属性tzinfo，但是默认为None，所以无法区分这个datetime到底是哪个时区，除非强行给datetime设置一个时区：
from datetime import datetime, timedelta, timezone
tz_utc_8 = timezone(timedelta(hours = 8))	# 创建时区 UTC+8:00
now = datetime.now()
dt = now.replace(tzinfo = tz_utc_8) # 强制设置为 UTC+8:00

# 如果系统时区恰好是UTC+8:00，那么上述代码就是正确的，否则，不能强制设置为UTC+8:00时区


# 时区转换
# 通过utcnow()拿到当前的UTC时间，再转换为任意时区的时间：
utc_dt = datetime.utcnow().replace(tzinfo = timezone.utc)
print(utc_dt)
# astimezone()将转换时区为北京时间
bj_dt = utc_dt.astimezone(timezone(timedelta(hours = 8)))
print(bj_dt)
tokyo_dt = utc_dt.astimezone(timezone(timedelta(hours = 9)))
print(tokyo_dt)
tokyo_dt2 = bj_dt.astimezone(timezone(timedelta(hours = 9)))
print(tokyo_dt2)

# 时区转换的关键在于，拿到一个datetime时，要获知其正确的时区，然后强制设置时区，作为基准时间
# 利用带时区的datetime，通过astimezone()方法，可以转换到任意时区
# 不是必须从UTC+0:00时区转换到其他时区，任何带时区的datetime都可以正确转换，例如上述bj_dt到tokyo_dt的转换

## datetime表示的时间需要时区信息才能确定一个特定的时间，否则只能视为本地时间
# 如果要存储datetime，最佳方法是将其转换为timestamp再存储，因为timestamp的值与时区完全无关


# 练习
	# 假设你获取了用户输入的日期和时间如2015-1-21 9:01:30，以及一个时区信息如UTC+5:00，均是str，请编写一个函数将其转换为timestamp：
import re
from datetime import datetime, timezone, timedelta

def to_timestamp(dt_str, tz_str):
	if (isinstance(dt_str, str) and isinstance(tz_str, str)):
		tz_re = re.match(r'^UTC[+-](\d+)\:(\d+)$', tz_str)
		tz_int = int(tz_re.group(1))
		tz_utc_5 = timezone(timedelta(hours = tz_int))
		ctime = datetime.strptime(dt_str, '%Y-%m-%d %H:%M:%S')
		dt = ctime.replace(tzinfo = tz_utc_5)
	else:
		raise TypeError
	return dt.timestamp()
	
t1 = to_timestamp('2015-6-1 08:10:30', 'UTC+7:00')
assert t1 == 1433121030.0, t1

t2 = to_timestamp('2015-5-31 16:10:30', 'UTC-09:00')
assert t2 == 1433121030.0, t2

print('Pass')

## 问题：
# AFT +04:30 阿富汗时间这样的情况也不少 
# 虽然一天24小时，时间最多24个，但是国际日期变更线不是直的。存在KLT +14:00 基里巴斯线岛时间，这样的个案

####### 自己写的py文件不要和系统模块重名，否则容易导入模块时错误！！
