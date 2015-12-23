/*
	项目数据库：
*/
drop database if exists project;
create database project;

use project;
set names utf8;

grant select, insert, update, delete
on project.*
to project@localhost identified by 'project';