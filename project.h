

//Struct for an entry in the page table

typedef struct {
    unsigned char frame;
    int valid;
} page_entry;


typedef struct{
    unsigned char page_number;
    unsigned char frame_number;
} TLBEntry;



void* page_establish();// invalidate all entries

void* page_update(unsigned char page); //grabs a value from the backing store and puts it in the page table

int page_search(unsigned char page);//Should be changed to return a value to the TLB


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

void *PMget(unsigned char frame, unsigned char offset);

int findAddress(int targetLineNum);

int TLB_lookup(unsigned char page);

void* TLB_insert(unsigned char page, unsigned char frame);

/**
* addressTranslator - Updates the page number and offset based on the inputted logical address
*/
void addressTranslator(int logical_address);