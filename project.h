typedef struct Key
{
    int key;
};

typedef struct Value
{
    int value;
};

//Struct for an entry in the page table
typedef struct 
{
    unsigned char frame;
    int valid;
}entry;
///////////////////////////////////////

typedef struct{
    unsigned char page_number;
    unsigned char frame_number;
}TLBEntry;

void establish();// invalidate all entries

void* update(int page); //grabs a value from the backing store and puts it in the page table

unsigned char search(int page);//Should be changed to return a value to the TLB


// NOTE: COMMENTED OUT DUE TO ERRORS, FIX AND THEN UNCOMMENT
/* 
typedef struct Map
{
    Key key;
    Value value;
    Value get(Key key){
    }
    
};
*/

/**
 * findAddress - Takes an argument of the line number to get the integer from, Outputs the integer held 
 * within the target line number.
*/
int findAddress(int targetLineNum);

/**
* readFromBackingStore - Updates the page number and offset based on the inputted logical address
*/
void readFromBackingStore(int logical_address);