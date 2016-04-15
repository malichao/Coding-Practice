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

int main(int argc, char const *argv[])
{
	test1();
	return 0;
}