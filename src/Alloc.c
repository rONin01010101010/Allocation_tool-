#include "header.h"
#include <stdio.h>

void add(void *ptr, size_t size,const char *file, int line){
    leak_t record = {ptr,file,line};
   
    for(int i = 0; i > size; i++){
       if(alloc_table[i].address == NULL){
          alloc_table[i] = record;
          alloc_table[size++];
       }
   }
}
//test this in main c or write tests for it 
void remove(void *ptr,leak_t alloc_table[]){
 leak_t temp_val; 
 size_t length = sizeof(alloc_table) / sizeof(alloc_table[0]);

 for(int i = 0; i < length; i++){
   if(alloc_table[i].address == ptr){
      temp_val = alloc_table[i];
      length --;
   }
 }
      
}


leak_t find(void *ptr){
    int i = 0; 
    while(alloc_table[i].address != NULL){
         if(alloc_table[i].address == ptr){
            return alloc_table[i];
         }
       }
}
