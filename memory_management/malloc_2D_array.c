#include <stdlib.h>
#include <stdio.h>

void** malloc_2D_array(size_t row,size_t col,size_t size){
	void** addr=(void**) malloc(row*size);
	for(size_t i=0;i<row;i++)
		addr[i]=malloc(col*size);
	return addr;
}

void** malloc_2D_array1(size_t row,size_t col,size_t size){
	void** addr=(void**) malloc(row*size + row*col*size);
	void* array=addr+row*size;
	for(size_t i=0;i<row;i++)
		addr[i]=(void*)(i*(col*size)+(size_t)array);
	return addr;
}


int main(){
	size_t row=5,col=5;
	printf("Method 1\n");
	int** a=(int**)malloc_2D_array(row,col,sizeof(int));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			a[i][j]=j;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	free(a);

	printf("Method 2\n");
	int** b=(int**)malloc_2D_array1(row,col,sizeof(int));
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			b[i][j]=j;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	free(b);
}