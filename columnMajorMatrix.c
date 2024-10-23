#include<stdio.h>

#define COL 3
#define ROW 3


int main(){
int matrix[ROW][COL],i,j;
int count=1;
// enter the values in the matrix
for(i=0;i<COL;i++){
	for(j=0;j<ROW;j++){
	printf("Enter the %d element\t:",count);
	scanf("%d",&matrix[i][j]);
	count++;
	}
}	
	
	// column major matrix
	printf("\nColumn major matrix is :\n");
	for(i=0;i<ROW;i++){
	for(j=0;j<COL;j++){
	
	printf("%d\t",matrix[i][j]);
	}printf("\n");
	
}	
return 0;

}
