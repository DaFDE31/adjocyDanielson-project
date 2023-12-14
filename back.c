#include <project.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <project.h>

FILE* fp = NULL;


int openFile(char* readFile) {
    fp = fopen(readFile,"rb");
    if(fp == NULL) return 1;
    seek(fp,0,SEEK_CUR);
    long size = ftell(fp);
    rewind(fp);
    char* backing = (char*) malloc(size);
    /*if(backing == NULL){
        fclose(fp);
        return 1;
    }*/
    size_t inBytes = fread(backing,1,size,fp);
    /*
    if(inBytes != size){
        free(backing);
        fclose(fp);
        return 1;
    }*/
    free(backing);
    return 0;
}

int read_page(unsigned char page){
    fseek(fp, (int) page * 256, SEEK_SET);
    char* pm_loc = get_mem_loc();
    fread(pm_loc, 256,1,fp);
}