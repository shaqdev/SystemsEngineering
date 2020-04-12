#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h> // memset declaration

void *calloc_imp(size_t nmemb, size_t size)
{
	size_t buf_size = nmemb * size;

	// checkign overflow of multiplication	
	if (nmemb == buf_size/size)
	{
		void *ptr_malloc = malloc(buf_size);
		if (ptr_malloc != NULL)
		{
			memset(ptr_malloc, 0, buf_size);
		}
		return ptr_malloc;
	}
	return NULL;
}

int main(int argc, char const *argv[])
{
	size_t nmemb = 10, size = 4;
	void *ptr_calloc;
	int * ptr_calloc_int;

	ptr_calloc_int = (int *)calloc_imp(nmemb, size);
	if (ptr_calloc_int != NULL)
		printf("Value in memory : %d\n", *ptr_calloc_int);
	else
		printf("NULL returned\n");
	free(ptr_calloc_int);

	// More assert tests tests
	ptr_calloc = calloc_imp(SIZE_MAX,2);
	assert(ptr_calloc == NULL);
	free (ptr_calloc);

	ptr_calloc = calloc_imp(50, 6);
	assert(ptr_calloc != NULL);
	free (ptr_calloc);
	return 0;

return 0;
}