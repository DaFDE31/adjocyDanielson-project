#include <project.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"

int index = 0;
TLBEntry* tlb[16];
int TLBsize = 0;

void* TLB_insert(unsigned char page, unsigned char frame) {
  // Check if the TLB is full
  if (index >= 16) {
    index = 0;
  }
  tlb[index]->frame_number = frame;
  tlb[index]->page_number = page;
  if (TLBsize <16){
    TLBsize++;
  }
  index++;
}

unsigned char TLB_lookup(unsigned char page){
    int enter = 0;
    while (enter < TLBsize){
        if (tlb[enter]->page_number = page){
            return tlb[enter]->frame_number;
        }
        enter++;
    }
    TLB_insert(page, search(page));
    return tlb[index-1]->frame_number;
}