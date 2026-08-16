#include <stdbool.h>
#define header
//leak struct defines what is needed when looking for a leak
typedef struct {
unsigned bytes;
char source_file;
int line;
bool free;
int* address;
} leak_t;

//allocation table that will hold allocation records
leak_t alloc_table[1024];
static int counter;

//functions to use
void add(void *ptr, size_t size,const char *file, int line);
void remove(void *ptr);
leak_t find(void *ptr);

