void itoa(int n, char *buf, int size){
	char *p = (char *)malloc(43);
	
	sprintf(p, "%d", n);
	if (strlen(p) >= size - 1){
		while (--size > 0){
			*buf++ = '*';
		}
		*buf = '\0';
	}
	else {
		strcpy(buf, p);
	}
}

/************************************************/
void itoa(int n, char *buf, unsigned int size){
	char *p = (char *)malloc(43);	// 43足够存储所有整形数字的字符串
	
	assert(p);
	assert(buf);
	assert(size > 1);
	
	sprintf(p, "%d", n);
	if (strlen(p) < size){
		strcpy(buf, p);
	}
	else
	{
		strncpy(buf, p, size - 1);
		buf[size - 1] = '\0';
	}
	
	free(p);
	p = NULL;
}