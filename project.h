typedef struct Key
{
    int key;
};

typedef struct Value
{
    int value;
};

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