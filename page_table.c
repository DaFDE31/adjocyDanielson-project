#include <project.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <project.h>

entry* table[256];


void establish(){
    for (int v = 0; v<256; v++){
        table[v]->valid = 0;
    }
}

void* update(int page){
    //table[page]->frame = 
    //Consult the Backing store, this will be for Sameer
    table[page]->valid = 1;

    //hi
}


unsigned char search(int page){
    if (table[page]->valid == 0){
        update(page);
    }
    return table[page]->frame; 

}