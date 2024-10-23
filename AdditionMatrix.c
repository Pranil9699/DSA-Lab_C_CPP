#include<stdio.h>

void getElement(int obj[2][3]){
	int i,j,count=1;
	for(i=0;i<2;i++){
	    for(j=0;j<3;j++){
        	printf("Enter the %d element\t:",count);
        	scanf("%d",&obj[i][j]);
        	count++;
    	}       
    }
}

void addition(int obj1[2][3],int obj2[2][3],int result[2][3]){
	int i,j;
	for(i=0;i<2;i++){
    	for(j=0;j<3;j++){
	        result[i][j]=obj1[i][j]+obj2[i][j];
    	}       
    }
}
void display(int obj[2][3]){
	int i,j,count=1;
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("%d ",obj[i][j]);
			}    printf("\n");   
		}
}
int main(){
	
	int A[2][3],B[2][3],C[2][3];
	
	printf("Enter the A matrix values:\n");
	getElement(A);
	printf("Enter the C matrix values:\n");
	getElement(B);
	printf("The Addition matrix values:\n");
	addition(A,B,C);
	display(C);
	return 0;
	
	
}
