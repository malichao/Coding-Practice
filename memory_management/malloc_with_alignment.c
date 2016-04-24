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

//Allocate a block of memory from heap whose address is multiple of power of two.
//The algigment must be power of two,e.g.,2,4,8,16..
void* aligned_malloc(size_t aligment, size_t size) {
	//Since we can't be sure if the allocated address is multiple of aligment or
	//not,so we apply for extra offset space.Then within the extra space we can
	//surely find the address which is multiple of aligment.
	//Also we need an extra space to store the original address,that's why we
	//add sizeof(void*) to the offset.
	int offset = aligment - 1 + sizeof(void*);
	void* allocated_addr= malloc(size + offset);
	if (allocated_addr == NULL)
		return NULL;

	//Add the offset and clear the lower bits
	void* aligned_addr = (void*) (((size_t) allocated_addr + offset)& ~(aligment - 1));

	//Store the original address prior to the aligment address
	((void **) aligned_addr)[-1] = allocated_addr;

	printf("aligment = %d\noffset = %d\nallocated_addr =\t%p\naligned_addr =\t\t%p\n",
								aligment,offset,allocated_addr, aligned_addr);
	return aligned_addr;
}

void aligned_free(void *aligned_addr) {
	if (aligned_addr == NULL)
		return;

	//Read the original address
	void *allocated_addr = ((void**) aligned_addr)[-1];
	free(allocated_addr);
}

int main() {
	size_t aligment = 256;

	printf("My aligned_malloc result:\n");
	int* p = (int*) aligned_malloc(256, aligment);
	aligned_free(p);

	printf("\nC11 aligned_malloc retult:\n");
	int *p1 =(int*) malloc(10*sizeof *p1);
    printf("default-aligned addr:\t%p\n", (void*)p1);
    free(p1);
 	
    int *p2 =(int*) aligned_alloc(aligment, 10*sizeof *p2);
    printf("%u-byte aligned addr: \t%p\n",aligment,(void*)p2);
    free(p2);
}
