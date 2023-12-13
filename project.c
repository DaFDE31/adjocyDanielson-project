// TO DO: Make the main function that calls the child functions.
// TO DO: Make the function that translates the integer from addresses.txt to the applicable logical address 
// (as in the page number and offset for the given integer in addresses.txt

// START - IMPORTS
#include <project.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
// STOP - IMPORTS

// START - Init. Vars
unsigned char page_number; 
unsigned char offset;
int lengthOfAddressestxt = 1000;
char* addresses = "addresses.txt";
// STOP - Init. Vars

// START - Functions
int findAddress(int targetLineNum){
    uint16_t targetValue = 0; // Statically allocates memory for the integer whose max value is 65536
    FILE *fp = NULL; // File pointer = null to start

    if (fp == NULL) { // ERROR HANDLING: File Not Found 
        perror("Error opening file");
        return targetValue; // Returns 0 if the file couldn't be opened
    }

    fp = fopen(addresses,"r"); // Opens the file in read mode
    fseek(addresses, targetLineNum - 1, SEEK_SET); // Brings the file pointer to the target line number

    if (fscanf(addresses, "%d", &targetValue) != 1) { // Read the content of the line and convert it to an integer
        // Error reading the integer
        perror("Error reading integer");
        targetValue = 0;  // Return 0 if there's an error reading the integer
    }    

    fclose(fp); // closes file
    return targetValue; // returns the target integer 
}

void *putInPhysicalMemory(unsigned char frame, int offset){
    int location = frame*256+offset;
    //Use this to get the correct value
}

void readFromBackingStore(int logical_address) {
    page_number = (logical_address >> 8) & 0x00FF; // Extracts Page Number using Bit Shifting and Bit Masking
    offset = logical_address & 0x00FF; // Extracts Offset using Bit Masking
}
// STOP - Functions
