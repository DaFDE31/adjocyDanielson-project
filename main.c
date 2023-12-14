// START - Imports
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
        int temp_tlbFrame = TLB_lookup(page_number);// holds the value so we don't have to call the method twice
        if ( temp_tlbFrame == -1){// TLB miss
            int temp_frame = page_search(page_number);// holds the value so we don't have to call the method twice
            if(temp_frame == -1){// Page fault
                // Use physical memory and backing store to get the frame
                frame_number = 0;// 0 is to be replaced with that method discussed above
                page_update(page_number, frame_number);
            }
            else{
                frame_number = (unsigned char) temp_frame;
            }
            TLB_insert(page_number, frame_number);
            putInPhysicalMemory(frame_number, offset);
        }
        else{
            frame_number = (unsigned char)temp_tlbFrame;
            putInPhysicalMemory(frame_number, offset);
        }
        
    }

    // Print the results <TESTING ONLY>
    printf("Page Number: %d\n", page_number);
    printf("Offset: %d\n", offset);

    return 0;
}
// STOP - Main Function
