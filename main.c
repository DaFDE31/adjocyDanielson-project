// START - Imports
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"
#include "page_table.c"
#include "TLB.c"
//#include "project.c"
// STOP - Imports

// START - Init. Vars
extern unsigned char page_number; 
extern unsigned char offset;
int lengthOfAddressestxt = 1000;
char* addresses = "addresses.txt";
int logicalAddress;
// STOP - Init. Vars

//side methods

FILE* fp = NULL;


int openFile(char* readFile) {
    fp = fopen(readFile,"r");
    if(fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char* bin = malloc(256 * 256);
    for(int i = 0; i < (256 * 256); i++)
        fread(&bin[i],(256 * 256) +1, 1, fp);
    
    
}



int read_page(char* readFile){
    fp = fopen(readFile, "r");
    if(fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    
}

// START - Main Function


void addressTranslator(int logical_address) {
    page_number = (logical_address >> 8) & 0x00FF; // Extracts Page Number using Bit Shifting and Bit Masking
    offset = logical_address & 0x00FF; // Extracts Offset using Bit Masking
}

int main(int argc, char * argv[]) {

 if(argc < 2) return 1;
    for (int i = 0; i < lengthOfAddressestxt; i++){
        page_establish(); // Creates the page table
        logicalAddress = findAddress(i); // Sets the logical address
        addressTranslator(logicalAddress); // Updates the GLOBAL page_num and offset var


        unsigned char frame_number;// Hopfully we can use this to look up a spefic frame in physical memory


        int temp_tlbFrame = TLB_lookup(page_number);// holds the value so we don't have to call the method twice
        if ( temp_tlbFrame == -1){// TLB miss
            int temp_frame = page_search(page_number);// holds the value so we don't have to call the method twice
            if(temp_frame == -1){// Page fault
                // Use physical memory and backing store to get the frame
                frame_number = 0;// 0 is to be replaced with that method discussed above
                page_update(page_number, frame_number);
                printf("Page fault!");
            }
            else{
                frame_number = (unsigned char) temp_frame;
            }
            TLB_insert(page_number, frame_number);
            PMget(frame_number, offset);
        }
        else{
            frame_number = (unsigned char)temp_tlbFrame;
            PMget(frame_number, offset);
        }
    }

    // Print the results <TESTING ONLY>
    printf("Address Number: %d\n", logicalAddress);
    printf("Page Number: %d\n", page_number);
    printf("Offset: %d\n", offset);

    return 0;
}
// STOP - Main Function