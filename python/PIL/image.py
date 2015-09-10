# -*- coding: utf-8 -*-

# PIL(Python Imaging Library)
	# PIL仅支持到Python 2.7, Pillow，支持最新Python 3.x，又加入了许多新特性，可以直接安装使用Pillow
	# 命令行下直接通过pip安装：$ pip install pillow
	# pip 不是在python解释器中运行。而是在windows的命令行下运行，pip在Python\Scripts目录下
	# cmd 中 cd 进入该目录下，输入：pip install pillow
	
# 图像操作
from PIL import Image

# 打开一个jpg文件，注意是当前路径
im = Image.open('test.jpg')
# 获得图像尺寸
w, h = im.size
print('Original image size: %sx%s' % (w, h))
# 缩放到50%
im.thumbnail((w//2, h//2))
w, h = im.size
print('Resize image to: %sx%s' % (w, h))
# 把缩放后的图像用jpeg格式保存
im.save('thumbnail.jpg', 'jpeg')

# 其他功能如切片、旋转、滤镜、输出文字、调色板等一应俱全
# 比如，模糊效果也只需几行代码：
from PIL import Image, ImageFilter
im = Image.open('meinv.jpg')
# 应用模糊滤镜
im2 = im.filter(ImageFilter.BLUR)
im2.save('blur.jpg', 'jpeg')

# PIL的ImageDraw提供了一系列绘图方法，让我们可以直接绘图。比如要生成字母验证码图片：
from PIL import Image, ImageDraw, ImageFont, ImageFilter

import random

# 随机字母
def ranChar():
	return chr(random.randint(65, 90))
	
# 随机颜色
def ranColor():
	return (random.randint(64, 255), random.randint(64, 255), random.randint(64, 255))
	
def ranColor2():
	return (random.randint(32, 127), random.randint(32, 127), random.randint(32, 127))
	
# 240*60
width = 60 * 4
height = 60
image = Image.new('RGB', (width, height), (255, 255, 255))
# 创建Font对象
font = ImageFont.truetype('C:/WINDOWS/Fonts/arial.ttf', 36)	# 绝对地址
# 创建Draw对象
draw = ImageDraw.Draw(image)
# 填充每个像素
for x in range(width):
	for y in range(height):
		draw.point((x, y), fill = ranColor())
# 输出文字 
for t in range(4):
	draw.text((60 * t + 10, 10), ranChar(), font = font, fill = ranColor2())
image.save('draw1.jpg', 'jpeg')
# 模糊 
image = image.filter(ImageFilter.BLUR)
image.save('drawblur.jpg', 'jpeg')
input('pause!')
# 上面代码，即就是生成验证码程序


## 双击file.py时，必须保证程序没有错误，才能得到结果：如果没有结果，则很有可能程序中有错误






