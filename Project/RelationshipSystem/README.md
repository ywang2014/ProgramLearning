# Relationship System

## Project Description
这是我的第一个独立项目，自己构思，设想的人际关系系统，第一步开发，只是一个雏形。
## function
提供人际关系查询

显示查询结果的基本信息，比如生日、爱好等，帮助你了解你的朋友，帮助你给你的朋友选择礼物，帮助你找到志同道合的朋友

界面简单友好！

## Construction
#### 三个基本框：
	左边：基本链接，比如：新浪、百度、体育、娱乐etc
	中间：你的朋友信息
	右边：好友最新动态(推荐系统)
	
#### 搜索实现：
	姓名匹配：张三，显示所有张三的信息
	学校匹配：小学同学，显示所有的小学同学，主页显示前三位，排名算法！
	模糊匹配：在备注中查询结果
	
#### 基本功能实现：
	动态网页显示
	数据库操作：
		访问数据库连接
		插入
		删除
		修改

#### 开发语言：
	PHP
	
## Security
	权限验证：只能看见自己朋友圈的信息
		比如小同学可以看见所有小学同学的信息etc
	
	主人可以设置自己的个人信息权限，对哪些朋友开放
		public protected private

## Problem
	数据库管理，几张表？
	
	如何实现以个人为中心的显示？以学校为中心的，以兴趣爱好为中心的 and so forth.
	
	如何实现关注度的排名算法？打分机制
	
	如何实现推荐功能等？
	
## LICENCE
	It is only for study and free without any commercial purpose!
	All infomation should be used for peaceful purposes without invading anyone's privacy.
	Everyone has obligation to protect your friends' personal details.
	
	***All rights reserved!***

## Idea
	Date: 2015-10-04 Late night