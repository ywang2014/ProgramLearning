#include <limits.h>
#include <stddef.h>
#include "mem.h"
#include "assert.h"
#include "table.h"

#define T Table_T

// types
struct T{
	// fields
	int size;
	int (*cmp)(const void *x, const void *y);
	unsigned int (*hash)(const void *key);
	
	struct binding{
		struct binding *link;
		const void *key;
		void *value;
	} **buckets;
};


// static functions
static int cmpatom(const void *x, const void *y){
	return x != y;
}


static unsigned int hashatom(const void *key){
	return (unsigned long) key >> 2;
} 


// functions
T Table_new(int hint, int cmp(const void *x, const void *y), unsigned int hash(const void *key)){
	T table;
	int i;
	static int primes[] = { 509, 509, 1021, 2053, 4093, 8191, 16381, 32771, 65521, INT_MAX };
	
	assert(hint >= 0);
	
	for (i = 1; primes[i] < hint; i++){
		;
	}
	
	table = ALLOC(sizeof(*table) + primes[i - 1] * sizeof(table->buckets[0]));
	table ->size = primes[i-1];
	table->cmp = cmp ? cmp : cmpatom;
	table->hash = hash ? hash : hashatom;
	table->buckets = (struct binding **)(table + 1);
	
	for (i = 0; i < table->size; i++){
		table->buckets[i] = NULL;
	}
	
	table->length = 0;
	table->timestamp = 0;
	
	return table;
}


void *Table_get(T table, const void *key){
	int i;
	struct binding *p;
	
	assert(table);
	assert(key);
	
	// search table for key 
	i = (*table->hash)(key) % table->size;
	for (p = table->buckets[i]; p; p->link){
		if ((*table->cmp)(key, p->key) == 0){	// 相等说明找到了
			break;
		}
	}
	
	return p ? p->value : NULL;
}


void *Table_put(T table, const void *key, void *value){
	int i;
	struct binding *p;
	void *prev;
	
	assert(table);
	assert(key);
	
	// search table for key
	i = (*table->hash)(key) % table->size;
	for (p = table->buckets[i]; p; p = p->link){
		if ((*table->cmp)(key, p->key) == 0){
			break;
		}
	}
	
	if (p == NULL){
		NEW(p);
		p->key = key;
		p->link = table->buckets[i];
		table->buckets[i] = p;
		table->length++;
		prev = NULL;
	}
	else{
		prev = p->value;
	}
		
	p->value = value;
	table->timestamp++;
		
	return prev;
}


int Table_length(T table){
	assert(table);
	
	return table->length;
}


void Table_map(T table, void apply(const void *key, void **value, void *c1), void *c1){
	int i;
	unsigned int stamp;
	struct binding *p;
	
	assert(table);
	assert(apply);
	
	stamp = table->timestamp;
	for (i = 0; i < table->size; i++){
		for (p = table->buckets[i]; p; p = p->link){
			apply(p->key, &p->value, c1);
			
			assert(table->timestamp == stamp);
		}
	}
}


void *Table_remove(T table, const void *key){
	int i;
	struct binding **ptr;
	
	assert(table);
	assert(key);
	
	table->timestamp++;
	i = (*table->hash)(key) % table->size;
	for (ptr = &table->buckets[i]; *ptr; ptr = &((*ptr)->link)){
		if ((*table->cmp)(key, (*ptr)->key) == 0){
			struct binding *p = *ptr;
			void *value = p->value;
			*ptr = p->link;
			FREE(p);
			table->length--;
			
			return value;
		}
	}
	
	return NULL;
}


void **Table_toArray(T table, void *end){
	int i = 0;
	int j = 0;
	void **array;
	struct binding *p;
	
	assert(table);
	
	array = ALLOC((2 * table->length + 1) * sizeof(array *));
	// 哈希表的遍历，双层循环实现
	for (i = 0; i < table->size; i++){
		for (p = table->buckets[i]; p; p = p->link){
			array[j++] = (void *)p->key;
			array[j++] = p->value;
		}
	}
	array[j] = end;
	
	return array;
}


void Table_free(T *table){
	assert(table && *table);
	
	if ((*table)->length > 0){
		int i;
		struct binding *p;
		struct binding *q;
		
		for (i = 0; i < (*table)->size; i++){
			for (p = (*table)->bucktes[i]; p; p = q){
				q = p->link;
				FREE(p);
			}
		}
	}
	
	FREE(*table);
}