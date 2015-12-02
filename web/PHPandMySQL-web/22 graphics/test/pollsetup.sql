/*
	pollsetup.sql
	
	mysql -uroot -p < pollsetup.sql
*/

create database poll;
use poll;

create table poll_results(
				candidate varchar(30),
				num_votes int
				);
				
insert into poll_results values
	('John Smith', 0),
	('Mary Jones', 0),
	('Fred Blogs', 0);

grant all privileges
	on poll.poll_results
	to poll@localhost
	identified by 'poll';
