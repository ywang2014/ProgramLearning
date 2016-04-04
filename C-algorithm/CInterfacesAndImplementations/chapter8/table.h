/**
	Table接口 使用隐式指针类型，表示一个关联表格
*/

#ifndef TABLE_INCLUDED
#define TABLE_INCLUDED

#define T Table_T
typedef struct T *T;

// exported functions
extern T Table_new(int hint, int cmp(const void *x, const void *y), unsigned hash(const void *key));

extern void Table_free(T *table);

extern int Table_length(T table);
extern void *Table_put(T table, const void *key, void *value);
extern void *Table_get(T table, const void *key);
extern void *Table_remove(T table, const void *key);

extern void Table_map(T table, void apply(const void *key, void **value, void *c1), void *c1);
extern void **Table_toArray(T table, void *end);


#undef T
#endif