// START - Imports
#include <project.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include "project.h"
// STOP - Imports

// START - Init. Vars
unsigned char page_number; 
unsigned char offset;
int lengthOfAddressestxt = 1000;
char* addresses = "addresses.txt";
// STOP - Init. Vars

// START - Main Function
int main() {
    for (int i = 0; i < lengthOfAddressestxt; i++){
        page_establish(); // Creates the page table
        int logicalAddress = findAddress(i); // Sets the logical address
        readFromBackingStore(logicalAddress); // Updates the GLOBAL page_num and offset var


        unsigned char frame_number;// Hopfully we can use this to look up a spefic frame in physical memory
        if (TLB_lookup(page_number) == -1){// TLB miss
            if(page_search(page_number)== -1){// Page fault
            
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
