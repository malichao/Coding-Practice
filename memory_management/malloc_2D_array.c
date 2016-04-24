#include <stdlib.h>
#include <stdio.h>

void** malloc_2D_array(size_t row,size_t col,size_t size){
	void** addr=(void**) malloc(row*size);
	for(size_t i=0;i<row;i++)
		addr[i]=malloc(col*size);
	return addr;
}

void** malloc_2D_array1(size_t row,size_t col,size_t size){
	void** addr=(void**) malloc(row*sizeof(void*) + row*col*size);
	void* array=&addr[row];
	for(size_t i=0;i<row;i++)
		addr[i]=(void*)(i*(col*size)+(size_t)array);
	return addr;
}

#define TYPE double
#define PRINT_FORMAT "%f \t"
#define VALUE j
int main(){
	size_t row=5,col=5;

	printf("Method 1\n");
	TYPE** a=(TYPE**)malloc_2D_array(row,col,sizeof(TYPE));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			a[i][j]=VALUE;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf(PRINT_FORMAT,a[i][j]);
		printf("\n");
	}
	free(a);


	printf("Method 2\n");
	TYPE** b=(TYPE**)malloc_2D_array1(row,col,sizeof(TYPE));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			b[i][j]=VALUE;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf(PRINT_FORMAT,b[i][j]);
		printf("\n");
	}
	free(b);

}
