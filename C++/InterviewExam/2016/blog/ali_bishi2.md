2 问答题
	
	描述
	
	Memcached是一款非常流行的开源缓存软件，请根据下面的网络协议说明，实现解析函数。补充题目中的代码片段和结构体定义。程序代码运行于X86 64bit Linux平台。
	The format of a packet is a fixed size header followed by three optional variable size components (command-specific extras, the key and the value):
	Byte/ 0 | 1 | 2 | 3 |
	/ | | | |
	|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
	+---------------+---------------+---------------+---------------+
	0/ HEADER /
	/ /
	/ /
	/ /
	+---------------+---------------+---------------+---------------+
	24/ Command-specific extras (as needed) /
	+/ (note length in the extras length header field) /
	+---------------+---------------+---------------+---------------+
	m/ Key (as needed) /
	+/ (note length in key length header field) /
	+---------------+---------------+---------------+---------------+
	n/ Value (as needed) /
	+/ (note length is total body length header field, minus /
	+/ sum of the extras and key length body fields) /
	+---------------+---------------+---------------+---------------+
	header:
	Byte/ 0 | 1 | 2 | 3 |
	/ | | | |
	|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
	+---------------+---------------+---------------+---------------+
	0| Magic | Opcode | Key length |
	+---------------+---------------+---------------+---------------+
	4| Extras length | Data type | Reserved |
	+---------------+---------------+---------------+---------------+
	8| Total body length |
	+---------------+---------------+---------------+---------------+
	12| Opaque |
	+---------------+---------------+---------------+---------------+
	16| CAS |
	| |
	+---------------+---------------+---------------+---------------+
	Total 24 bytes
	Magic is a magic byte which distinguishes requests from responses. It must be 0x80 for requests and 0x81 for responses.
	Opcode specifies the type of command, e.g. GET is 0 and SET is 1. 
	Key Length specifies the size in bytes of the Key-part of the packet.
	Extras length specifies the size in bytes of the Command-specific extras-part of the packet.
	Data type is currenly not used and should always be 0.
	Bytes 7-8 is either Reserved in the request or Status in the response. - The status corresponds to an error code or 0 if successful.
	Total body length is the total size of the body in bytes, i.e. Total body length = Key length + Key length + Value length. The value length is not given explicitly in the header, but can be calculated as Total body length - Key length - Extras length.
	Opaque is 4 bytes which are passed along in a request and passed back unmodified in the response.
	CAS is used for data version checking. When storing a value you can optionally set its CAS value. Future modifications will be rejected if a matching CAS value is not provided.
	example:
	Byte/ 0 | 1 | 2 | 3 |
	/ | | | |
	|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|0 1 2 3 4 5 6 7|
	+---------------+---------------+---------------+---------------+
	0| 0x80 | 0x00 | 0x00 | 0x05 |
	+---------------+---------------+---------------+---------------+
	4| 0x00 | 0x00 | 0x00 | 0x00 |
	+---------------+---------------+---------------+---------------+
	8| 0x00 | 0x00 | 0x00 | 0x05 |
	+---------------+---------------+---------------+---------------+
	12| 0x00 | 0x00 | 0x00 | 0x00 |
	+---------------+---------------+---------------+---------------+
	16| 0x00 | 0x00 | 0x00 | 0x00 |
	+---------------+---------------+---------------+---------------+
	20| 0x00 | 0x00 | 0x00 | 0x00 |
	+---------------+---------------+---------------+---------------+
	24| 0x48 ('H') | 0x65 ('e') | 0x6c ('l') | 0x6c ('l') |
	+---------------+---------------+---------------+---------------+
	28| 0x6f ('o') |
	+---------------+
	Total 29 bytes (24 byte header, and 5 bytes key)
	Field (offset) (value)
	Magic (0) : 0x80
	Opcode (1) : 0x00
	Key length (2,3) : 0x0005
	Extra length (4) : 0x00
	Data type (5) : 0x00
	Reserved (6,7) : 0x0000
	Total body (8-11) : 0x00000005
	Opaque (12-15): 0x00000000
	CAS (16-23): 0x0000000000000000
	Extras : None
	Key (24-29): The textual string: "Hello"
	Value : None
	
	问题
	struct Packet 
	{
	};
	
	Packet* DeocdeBuffer(char *buffer, int32_t len) 
	{
	}
