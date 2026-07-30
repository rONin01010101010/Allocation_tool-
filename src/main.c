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

void remove(void *ptr){

       leak_t *emp = NULL;   
       int i = 0;
       while(alloc_table[i].address != NULL){
         if(alloc_table[i].address == ptr){
            alloc_table[i] = emp         
        }
       }
}

void* find(void *ptr){
    int i = 0; 
    while(alloc_table[i].address != NULL){
         if(alloc_table[i].address == ptr){
            print(alloc_table[i]);
         }
       }
}
