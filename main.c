// START - Imports
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"
#include "page.h"
// STOP - Imports

// START - Init. Vars
unsigned char page_number; 
unsigned char offset;
int lengthOfAddressestxt = 1000;
char* addresses = "addresses.txt";
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
int main(int argc, char* argv[]) {

    if(argc < 2)
        return 1;
    

    for (int i = 0; i < lengthOfAddressestxt; i++){
        page_establish(); // Creates the page table
        int logicalAddress = findAddress(i); // Sets the logical address
        addressTranslator(logicalAddress); // Updates the GLOBAL page_num and offset var


        unsigned char frame_number;// Hopfully we can use this to look up a spefic frame in physical memory
        if (TLB_lookup(page_number) == -1){// TLB miss
            if(page_search(page_number)== -1){// Page fault
            printf("page fault!");
            }
                

        }
        else{
            frame_number = (unsigned char)TLB_lookup(page_number);
            putInPhysicalMemory(frame_number, offset);
        }
        




        //putInPhysicalMemory
        // if ( inTLB(page_number, offset) == 0 ) { // If it == 0 then it means that it IS IN the TLB
        //    putInPhysicalMemory(frameNum, offset);
        // }
        // else {
        //    if ( inPageTable(page_number, offset) == 0 ) { // If it == 0 then it means that it IS IN the page table
        //       putInTLB(page_number, offset);   
        //       putInPhysicalMemory(frameNum, offset);
        //    }
        //    else {
        //       pageFault(page_number, offset);
        //       putInTLB(page_number, offset);
        //       putInPhysicalMemory(frameNum, offset);
        //    }
        // }
    }

    // Print the results <TESTING ONLY>
    printf("Page Number: %d\n", page_number);
    printf("Offset: %d\n", offset);

    return 0;
}
// STOP - Main Function