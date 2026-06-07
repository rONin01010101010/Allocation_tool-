#include <stdbool.h>
#define header
#ifndef header
//leak struct defines what is needed when looking for a leak
typedef struct {
unsigned bytes;
char source_file;
int line;
bool free;
int* address;
} leak_t;

//allocation table that will hold allocation records
leak_t alloc_table[50];

//functions to use
void add(leak_t record);
void remove(leak_t record);
void* find(int* ptr);

#endif