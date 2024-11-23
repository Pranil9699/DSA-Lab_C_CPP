#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

typedef  struct {
	int data[MAX_SIZE];
	int size;
}MinHeap;

void initHeap(MinHeap* heap){
	heap->size = 0;
}

void swap(int *a ,int *b){
	int temp = *a;
	*a= *b;
	*b = temp;
}

void insert(MinHeap* heap,int value ){
	if(heap->size == MAX_SIZE){
		printf("Heap is Full.cannot insert \n");
		return;
		
	}
	heap->data[heap->size]= value;
	int current = heap->size;
	heap->size++;
	
	while(current > 0){
		int parent = (current-1)/2;
		if(heap->data[current] < heap->data[parent]){
			swap(&heap->data[current],&heap->data[parent]);
			current = parent;
		}else
		break;
	}
}
deleteMin(MinHeap* heap){
	if(heap->size == 0){
		printf("Heap is Empty.cannot delete.\n");
		return;
	}
	
	heap->data[0] = heap->data[heap->size - 1];
	heap->size--;
	
	
	int current =0;
	while(1){
		int leftChild = 2 * current+1;
		int rightChild = 2 * current +2;
		int smallest = current;
		
		if(leftChild < heap->size && heap->data[leftChild] < heap->data[smallest]){
			smallest = leftChild;
		}
		if(rightChild < heap->size && heap->data[rightChild] < heap->data[smallest]){
			smallest = rightChild;
		}
		if(smallest == current)
		break;
		
		swap(&heap->data[current],&heap->data[smallest]);
		current= smallest;
	}
}

void displayHeap(MinHeap* heap){
	int i;
	for(i = 0 ; i < heap->size; i++){
		printf("%d ",heap->data[i]);
	}
	printf("\n");
}

int main(){
	MinHeap heap;
	initHeap(&heap);
	
	insert(&heap,10);
	insert(&heap,20);
	insert(&heap,5);
	insert(&heap,30);
	insert(&heap,15);
	
	printf("Heap After insertions:\n");
	displayHeap(&heap);
	
	printf("Deleting the minimum element...\n");
	deleteMin(&heap);
	
	printf("Heap after deletion \n");
	displayHeap(&heap);
	return 0;
}
