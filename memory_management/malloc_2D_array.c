/******************************************************************************
Author		: Lichao Ma
Date  		: Apr 24,2016
Version		: v0.1
Built		: Sublime GCC, -std=c++11
Description :
	A example of how to allocate a 2D array.
	The layout of a 4x4 2D array:
	______      __________________________
	row_0 | -> |col_0  col_1  col_2  col_3
	row_1 | -> |col_0  col_1  col_2  col_3
	row_2 | -> |col_0  col_1  col_2  col_3
	row_3 | -> |col_0  col_1  col_2  col_3

	So the basic ideal is first mollac a chunk of row pointers and then mollac
	each row respectively.However this require a lot of function call to malloc.
	So a better idea is to malloc all the memory at once and then record the
	start address of each row in the row pointers:

	|row_0 row_1 row_2 row_3|col_0 ...col_3| ..... |col_0 ... col_3|

	And then record the start address of of each row:

	|row_0      row_1       row_2       row_3|
	  |          |           |           |
	  |          ------      ----------  --------------
	  V               V               V               V
	|col_0 ... col_3|col_0 ... col_3|col_0 ... col_3|col_0 ... col_3|

*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>

//Basic example,not a good choice
void** malloc_2D_array(size_t row,size_t col,size_t size){
	void** addr=(void**) malloc(row*size);
	if(addr==NULL)
		return NULL;
	for(size_t i=0;i<row;i++){
		addr[i]=malloc(col*size);
		if(addr[i]==NULL){		//If failed,clean up all previous memory
			for(size_t j=0;j<i;j++)
				free(addr[j]);
		}
		
	}
	return addr;
}

void** malloc_2D_array1(size_t row,size_t col,size_t size){
	//Memory layout:
	//|row_0 row_1 ... row_n|col_0 ...col_m| ..... |col_0 ... col_m|
	void** addr=(void**) malloc(row*sizeof(void*) + row*col*size);
	if(addr==NULL)
		return NULL;

	//Skip the row pointers we get to the start address of the array
	void* array=&addr[row];
	for(size_t i=0;i<row;i++)	//Record the start of each row
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
