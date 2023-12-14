#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"

page_entry* table[256];


void* page_establish(){
    for (int v = 0; v<256; v++){
        table[v]->valid = 0;
    }
}

void* page_update(unsigned char page, unsigned char frame_number){
    table[page]->frame = frame_number;
    table[page]->valid = 1;

    //hi
}


int page_search(unsigned char page){
    if (table[page]->valid == 0){
        return -1;
    }
    return (int)table[page]->frame; 

}