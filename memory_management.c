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

//Example of realloc
//void* realloc (void* ptr, size_t size);
void test2(){
	int size=10;
	int* numbers = NULL;
	int* more_numbers = NULL;

	more_numbers = (int*) realloc (numbers, size * sizeof(int));

	if (more_numbers!=NULL) {
		numbers=more_numbers;
	}
	else {
		free (numbers);
		puts ("Error (re)allocating memory");
		exit (1);
	}

	for (int n=0;n<size;n++) 
		printf ("%d ",numbers[n]);
	printf("\n");

	free (numbers);
}

//Example of calloc
//void* calloc (size_t num, size_t size);
void test3(){
	int size=10;
	int * pData;
	pData = (int*) calloc (size,sizeof(int));
	if (pData==NULL) exit (1);

	for (int n=0;n<size;n++) 
		printf ("%d ",pData[n]);
	printf("\n");

	free (pData);
}

int main(int argc, char const *argv[])
{
	test1();
	test1_2();
	test2();
	test3();
	return 0;
}