/**
	sequence interface
*/
#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

#define T Sequence_T

typedef struct T *T;

// exported functions
extern T Sequence_new(int hint);
extern T Sequence_seq(void *x, ...);

extern void Sequence_free(T *seq);

extern int Sequence_length(T seq);

extern void *Sequence_get(T seq, int i);
extern void *Sequence_put(T seq, int i, void *x);

extern void *Sequence_addlo(T seq, void *x);
extern void *Sequence_addhi(T seq, void *x);

extern void *Sequence_removelo(T seq);
extern void *Sequence_removehi(T seq);


#undef T
#endif