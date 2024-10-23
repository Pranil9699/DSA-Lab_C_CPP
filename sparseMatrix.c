#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


int main(){
	// create the matrix
	int sparse_matrix[4][5]=
	{{0,0,6,0,9},{0,0,4,6,0},{0,0,0,0,0},{0,1,2,0,0}};
//	size of matrix

int size=0,i,j;

system("cls");
for( i =0 ; i<4;i++){
	for( j=0;j<5;j++){
		if(sparse_matrix[i][j]!=0)
		size++;
	}
}

//printf("Size will be %d\n",size);
// defining final martrix
	int matrix[3][size];
	int k=0;
	
//	computing final matrix

for( i=0;i<4;i++){
	for( j=0;j<5;j++){
		if(sparse_matrix[i][j]!=0){
		
		matrix[0][k]=i;
		matrix[1][k]=j;
		matrix[2][k]=sparse_matrix[i][j];
		k++;
	}
}
}

// Displaying the final matrix



for( i =0 ; i<3;i++){
	for( j=0;j<size;j++){
	printf("%d \t",matrix[i][j]);
	
	}
	printf("\n");
}

return 0;

}
