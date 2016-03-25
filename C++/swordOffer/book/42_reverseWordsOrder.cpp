/**
	翻转单词顺序 VS 左旋转字符串
	
	输入一个英文句子，翻转句子中单词的顺序，但单词内容字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
	
	例如：输入字符串"I am a student.", 则输出"student. a am I".
*/
inline void swap(char& ch1, char& ch2)
{
	char oldCh1 = ch1;
	ch1 = ch2;
	ch2 = oldCh1;
}


void reverseString(char* begin, char* end)
{
	if (begin == NULL || end == NULL)
	{
		return;
	}
	
	while (begin < end)
	{
		swap(*begin, *end);
		begin++;
		end--;
	}
}


char* reverseSentence(char* data)
{
	if (data == NULL)
	{
		return NULL;
	}
	
	char* begin = data;
	
	char* end = data;
	while (*end != '\0')
	{
		end++;
	}
	end--;
	
	// 第一步，翻转整个句子
	reverseString(begin, end);
	
	// 翻转单词
	begin = end = data;
	while (begin != '\0')
	{
		if (*begin == ' ')
		{
			begin++;
			end++;
		}
		else if (*end == ' ' || *end == '\0')
		{
			reverseString(begin, end);
			
			begin = ++end;
		}
		else
		{
			end++;
		}
	}
	
	return data;
}


/*********************************************/
// 借助vector容器实现的方法
void reverseSentence(char* data)
{
	char* begin = data;
	char* end = data;
	char* word = NULL;
	
	std::list<string> strs;
	
	while (*end != '\0')
	{
		if (*end == ' ' && *begin != ' ')
		{
			word = charToWord(begin, end, word);
			strs.push_front(word);
			
			begin = ++end;
		}
		else if (*begin == ' ')
		{
			strs.push_front(' ');
			
			begin++;
			end++;
		}
		else
		{
			end++;
		}
	}
	
	word = charToWord(begin, end, word);
	
	strs.push_front(word);
	
	for (list<string>::iterator it = strs.begin(); it != strs.end(); it++)
	{
		printf("%s", *it);
		
	}
}


char* charToWord(char* begin, char* end, char* word)
{
	char* pWord = word;
	
	while (begin != end)
	{
		*pWord++ = *begin++;
	}
	
	*pWord = '\0';
	
	return word;
}
