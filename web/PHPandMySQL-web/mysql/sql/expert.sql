/*
	顾问信息表：
	
	职业分类，
		单独建表，一个分类一张，记录顾问id，即可知道顾问行业
		
		放在这里，行业可以模糊查询，知道分类，不知道实际效果怎么样。varchar
	
		或者自己定义规则，推算用户分类：
			1-8八个单类
			12则代表1/2两类
			148则代表三类：1/4/8
*/
use wuliu;
set names utf8;

create table if not exists experts(
	eid int unsigned not null auto_increment primary key,
	uid int unsigned not null comment '用户id',
	vip char(1) default 0 comment '用户等级',
	career int default 0 comment '职业分类',
	image varchar(50) not null comment '头像url',
	points int default 0 comment '积分',
	introduce text comment '个人简介'
)engine=MyISAM default charset=utf8;

/* drop table experts; */