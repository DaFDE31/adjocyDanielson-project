

typedef struct 
{
    unsigned char* frame;
    int valid;
}entry;

void establish();// invalidate all entries

void* update(int page); //grabs a value from the backing store and puts it in the page table

unsigned char* search(int page);//Should be changed to return a value to the TLB