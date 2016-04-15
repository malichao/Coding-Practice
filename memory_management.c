#include <stdlib.h>
#include <stdio.h>

// Example of using malloc and free
// void* malloc (size_t size);
void test1(){
	int *p=(int*) malloc(sizeof(int)*10);
	if(p==NULL) {
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<10;i++)
		printf("%d,",p[i]);
	printf("\n");
	free(p);

}

// Example of using malloc and free,failure 
void test1_1(){
	// The following allocation will failed,and there's no sanity check
	int *p=(int*) malloc(sizeof(int)*100000000000);
	if(p==NULL) {
		printf("Memory allocation failed\n");
		//exit(EXIT_FAILURE);
	}

	// Accessing out of bound memory,Segmentation fault  
	for(int i=0;i<10;i++)
		printf("%d,",p[i]);

	// This will failed too
	free(p);
}

// Example of using malloc and free,applying for array of pointers
void test1_2(){
	int size=100;
	// array of length SIZE, consisting of float pointers
	float** arr =(float**) malloc(sizeof(float*) * size);
	printf("Allocated array of pointers\n");

	// allocate the array of 3 floats at each index
	for (int i = 0; i < size; i++) 
	    arr[i] =(float*) malloc(sizeof(float) * 5);

	// free the individual arrays
	for (int i = 0; i < size; i++)
	    free(arr[i]);
	// free the array of arrays
	free(arr);
	printf("Array of pointers freed\n");
}

int main(int argc, char const *argv[])
{
	test1();
	test1_2();
	return 0;
}