/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 24,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	A example of how to allocate a block of memory with the address divisible
	by a power of two.Trying to achieve same purpose of the aligned_alloc
	function in C11.
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
void* aligned_malloc(size_t aligment, size_t size) {
	void* allocated_addr;
	void* aligned_addr;
	int offset = aligment - 1 + sizeof(void*);
	if ((allocated_addr = (void*) malloc(size + offset)) == NULL)
		return NULL;

	aligned_addr = (void*) (((size_t) allocated_addr + offset)& ~(aligment - 1));
	((void **) aligned_addr)[-1] = allocated_addr;

	printf("aligment = %d\noffset = %d\nallocated_addr =\t%p\naligned_addr =\t\t%p\n",
								aligment,offset,allocated_addr, aligned_addr);
	return aligned_addr;
}

void aligned_free(void *aligned_addr) {
	if (aligned_addr == NULL)
		return;
	void *allocated_addr = ((void**) aligned_addr)[-1];
	free(allocated_addr);
}

int main() {
	size_t aligment = 256;
	int* p = (int*) aligned_malloc(256, aligment);
	aligned_free(p);

	int *p1 =(int*) malloc(10*sizeof *p1);
    printf("default-aligned addr:\t%p\n", (void*)p1);
    free(p1);
 
    int *p2 =(int*) aligned_alloc(aligment, 10*sizeof *p2);
    printf("%u-byte aligned addr: \t%p\n",aligment,(void*)p2);
    free(p2);
}
