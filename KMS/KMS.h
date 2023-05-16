#ifndef __KMS_LIB__
#define __KMS_LIB__

#define TRUE 1
#define FALSE 0

// plz change 'int' to used data type
typedef int DATA;

// linked list start
typedef struct _node {
	DATA data;
	struct _node* next;
}NODE;

typedef struct _list {
	NODE* tail;
	NODE* cur;
	NODE* before;
	int numofData;
}LIST;

void ListInit(LIST* plist);
void LInsert(LIST* plist, DATA data);
void LInsertFront(LIST* plist, DATA data);

int LFirst(LIST* plist, DATA* pdata);
int LNext(LIST* plist, DATA* pdata);
DATA LRemove(LIST* plist);
int LCount(LIST* plist);
// linked list end

// data swap
void swap(DATA* a, DATA* b);

// merge sort
void merge_sort(DATA* arr, int start, int last, int (*compare)(DATA a, DATA b));
void merge(DATA* arr, int start, int middle, int last, int (*compare)(DATA a, DATA b));

// bubble sort
void bubble_sort(DATA* arr, int last, int (*compare)(DATA a, DATA b));

// meaning of return value of search function
// return value is idx value of array
// meaning of return value -1 is find failed

// sequential search 
int seq_search(int* arr, int max, int goal);

// binary search
int bin_search(int* arr, int start, int last, int goal);

#endif