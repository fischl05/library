#include "KMS.h"
#include <stdio.h>
#include <stdlib.h>

// linked list start
void ListInit(LIST* plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numofData = 0;
}

void LInsertFront(LIST* plist, DATA data) {
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
	}

	(plist->numofData)++;
}

void LInsert(LIST* plist, DATA data) {
	NODE* newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = data;

	if (plist->tail == NULL) {
		plist->tail = newnode;
		newnode->next = newnode;
	}
	else {
		newnode->next = plist->tail->next;
		plist->tail->next = newnode;
		plist->tail = newnode;
	}

	(plist->numofData)++;
}

int LFirst(LIST* plist, DATA* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(LIST* plist, DATA* pdata) {
	if (plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur - plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

DATA LRemove(LIST* plist) {
	NODE* rpos = plist->cur;
	DATA rdata = rpos->data;

	if (rpos == plist->tail) {
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numofData)--;
	return rdata;
}

int LCount(LIST* plist) {
	return plist->numofData;
}
// linked list end

// data swap
void swap(DATA* a, DATA* b) {
	DATA temp = *a;
	*a = *b;
	*b = temp;
}

// merge sort start
static sorted[1000];

void merge_sort(DATA* arr, int start, int last, int (*compare)(DATA a, DATA b)) {
	if (start < last) {
		int middle = (start + last) / 2;
		merge_sort(arr, start, middle, compare);
		merge_sort(arr, middle + 1, last, compare);
		merge(arr, start, middle, last, compare);
	}
}

void merge(DATA* arr, int start, int middle, int last, int (*compare)(DATA a, DATA b)) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= last) {
		if (compare(arr[i], arr[j]))
			sorted[k++] = arr[i++];
		else
			sorted[k++] = arr[j++];
	}
	if (i > middle)
		for (int t = j; t <= last; t++)
			sorted[k++] = arr[t];
	else
		for (int t = i; t <= middle; t++)
			sorted[k++] = arr[t];
	for (int t = start; t <= last; t++)
		arr[t] = sorted[t];
}
// merge sort end

// bubble sort start
void bubble_sort(DATA* arr, int last, int (*compare)(DATA a, DATA b)) {
	for (int i = 0; i < last; i++)
		for (int j = 0; j < last - i; j++)
			if (compare(arr[j], arr[j + 1]))
				swap(&arr[j], &arr[j + 1]);
}
// bubble sort end

// sequential search start
int seq_search(int* arr, int max, int goal) {
	int i = 0;
	while (arr[i] != goal && i < max) i++;

	if (i >= max) return -1;
	else return i;
}
// sequential search end

// binary search start
int bin_search(int* arr, int start, int last, int goal) {
	int middle = (start + last) / 2;
	if (start > last) return -1;
	if (arr[middle] == goal) return middle;
	else {
		if (goal > arr[middle]) return bin_search(arr, middle + 1, last, goal);
		else return bin_search(arr, start, middle - 1, last, goal);
	}
}
// binary search end