/**
	mutex 互斥信号量，经常嵌套在ADT中，保证ADT的访问是线程安全的
*/
typedef struct{
	Sem_T mutex;
	Table_T table;
} Protected_Table_T;


// test example
// create a table
Protected_Table_T tab;
tab.table = Table_new(...);
Sem_init(&tab.mutex, 1);

// get the value of key by atom way
LOCK(tab.mutex)
	value = Table_get(tab.table, key);
END_LOCK;

// put会引发异常，故不能使用LOCK， 使用TRY
TRY
	Sem_wait(&tab.mutex);
	Table_put(tab.table, key, value);
FINALLY
	Sem_signal(&tab.mutex);
END_TRY;