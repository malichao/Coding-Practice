#include <stdlib.h>
#include <stdio.h>
void* aligned_malloc(size_t wanted_size, size_t byte_aligment) {
	void* allocated_addr;
	void* aligned_addr;
	int offset = byte_aligment - 1 + sizeof(void*);
	if ((allocated_addr = (void*) malloc(wanted_size + offset)) == NULL)
		return NULL;

	aligned_addr = (void*) (((size_t) allocated_addr + offset)
			& ~(byte_aligment - 1));
	((void **) aligned_addr)[-1] = allocated_addr;

	printf("allocated_addr = %d,aligned_addr = %d,offset = %d\n",
								allocated_addr, aligned_addr, offset);
	return aligned_addr;
}

void aligned_free(void *aligned_addr) {
	if (aligned_addr == NULL)
		return;
	void *allocated_addr = ((void**) aligned_addr)[-1];
	free(allocated_addr);
	aligned_addr = NULL;
	allocated_addr = NULL;
}

int main() {
	double aligment = 2;
	int* p = (int*) aligned_malloc(100, aligment);
	printf("pointer addr= %d,ratio=%.1f\n", p, (int) (p) / aligment);
	aligned_free(p);
}
