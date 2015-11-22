-- phpMyAdmin SQL Dump
-- version 3.1.5-rc1
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2010 年 08 月 22 日 01:12
-- 服务器版本: 5.0.18
-- PHP 版本: 5.2.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `test`
--

-- --------------------------------------------------------

--
-- 表的结构 `news`
--

CREATE TABLE IF NOT EXISTS `news` (
	`id` int(11) unsigned NOT NULL auto_increment,
	`title` varchar(256) NOT NULL,
	PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- 导出表中的数据 `news`
--


-- --------------------------------------------------------

--
-- 表的结构 `news2`
--

CREATE TABLE IF NOT EXISTS `news2` (
	`id` int(11) unsigned NOT NULL auto_increment,
	`title` varchar(256) NOT NULL,
	`content` varchar(256) NOT NULL,
	PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

--
-- 导出表中的数据 `news2`
--

