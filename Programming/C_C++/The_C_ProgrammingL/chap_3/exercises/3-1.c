#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <limits.h>

#define MAX_ARRAY_SIZE 10000

int binsearch_1(int, int[], int);
int binsearch_2(int, int[], int);
int binsearch_3(int, int[], int);

int main()
{
	int arr[MAX_ARRAY_SIZE];
	int index = -1;
	int x = 10; // element to be searched

	// Initialize array
	for (int i = 0; i < MAX_ARRAY_SIZE; ++i)
		arr[i] = i;

	// find time taken for INT_MAX iterations for each binary search function
	clock_t time_taken;
	int i;

	// caluclating time taken for binsearch_1 
	for (i = 0, time_taken = clock(); i < INT_MAX; ++i)
		index = binsearch_1(x, arr, MAX_ARRAY_SIZE);

	time_taken = clock() - time_taken;

	if (index < 0)
		printf("binsearch_1 : Element not found\n");
	else
		printf("binsearch_1 : Element found at index, %d\n", index);

	printf("Time taken by binsearch_1 in seconds : %lu\n", time_taken/CLOCKS_PER_SEC);

	// caluclating time taken for binsearch_2
	for (i = 0, time_taken = clock(); i < INT_MAX; ++i)
		index = binsearch_2(x, arr, MAX_ARRAY_SIZE);

	time_taken = clock() - time_taken;

	if (index < 0)
		printf("binsearch_2 : Element not found\n");
	else
		printf("binsearch_2 : Element found at index, %d\n", index);

	printf("Time taken by binsearch_2 in seconds : %lu\n", time_taken/CLOCKS_PER_SEC);

	// caluclating time taken for binsearch_3
	for (i = 0, time_taken = clock(); i < INT_MAX; ++i)
		index = binsearch_3(x, arr, MAX_ARRAY_SIZE);

	time_taken = clock() - time_taken;

	if (index < 0)
		printf("binsearch_3 : Element not found\n");
	else
		printf("binsearch_3 : Element found at index, %d\n", index);

	printf("Time taken by binsearch_3 in seconds : %lu\n", time_taken/CLOCKS_PER_SEC);

return 0;
}

/*	x 	: element to search
	arr : sorted array
	n	: size of arr
*/
int binsearch_1(int x, int arr[], int n)
{
	int low = 0, high = n-1, mid;
	while (low <= high){
		mid = (low+high)/2;
		if (x < arr[mid])
			high = mid-1;
		else if (x > arr[mid])
			low = mid+1;
		else
			return mid;
	}
	return -1;
}

int binsearch_2(int x, int arr[], int n)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	while (low < high)
	{
		mid = (high+low)/2;
		if (x <= arr[mid])
			high = mid;
		else
			low = mid+1;
	}
	if (x == arr[low])
		return low;
	else
		return -1;
}

int binsearch_3(int x, int arr[], int n)
{
	int low,mid,high;
	low = 0;
	high = n-1;
	mid = (low + high)/2;
	while (low <= high && x != arr[mid])
	{
		if (x < arr[mid])
			high = mid -1;
		else
			low = mid + 1;
		mid = (low+high)/2;
	}
	if (x == arr[mid])
		return mid;
	else
		return -1;
}