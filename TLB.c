#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"
#include "page_table.c"

int ind = 0; //ind stands for index
TLBEntry* tlb[16];
int TLBsize = 0; // Amount of entries in the TLB

void* TLB_insert(unsigned char page, unsigned char frame) {
  // Check if the TLB is full
  if (ind >= 16) {
    ind = 0;
  }
  tlb[ind]->frame_number = frame;
  tlb[ind]->page_number = page;
  if (TLBsize <16){
    TLBsize++;
  }
  ind++;
  //return tlb[ind-1]->frame_number; This line shouldn't be necessary
  
}

int TLB_lookup(unsigned char page){
    int enter = 0;
    while (enter < TLBsize){
        if (tlb[enter]->page_number = page){
            return (int) tlb[enter]->frame_number;
        }
        enter++;
    }
    //TLB_insert(page, search(page));
    return -1;
}