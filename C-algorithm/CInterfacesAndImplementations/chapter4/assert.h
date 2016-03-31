/**
	assert.h 
*/

#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
	extern void assert(int e);
#define assert(e) ((void)((e) || \
	(fprintf(stderr, "%s:%d: Assertion failed: %s\n", \
	__FILE__, (int)__LINE__, #e), abort(), 0)))
#endif


/***********************************************************************/
#undef assert
#ifdef NDEBUG
#define assert(e) ((void)0)
#else
	#include "except.h"
extern void assert(int e);
#define assert(e) ((void)((e) || (RAISE(Assert_Failed), 0)))
#endif 