DROP TABLE user;	# 删除可能存在的表，再创建新表，安全！
CREATE TABLE user(
			id			INT				AUTO_INCREMENT PRIMARY KEY,
			name		VARCHAR(50)		NOT NULL,
			sex			VARCHAR(10)		NOT NULL,
			birthday	DATE
);