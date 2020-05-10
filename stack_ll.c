#include <stdio.h> 
#include <stdlib.h> 


struct Node { 
	int data; 
	struct Node* link; 
}; 
struct Node* top; 

void push(int data) 
{ 
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));

	if (!temp) { 
		printf("\nHeap Overflow"); 
		exit(1); 
	} 

	temp->data = data; 
	temp->link = top; 
	top = temp; 
} 

int isEmpty() 
{ 
	return top == NULL; 
} 

int peek() 
{ 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 


void pop() 
{ 
	struct Node* temp; 

	if (top == NULL) { 
		printf("\nStack Underflow\n"); 
		exit(1); 
	} 
	else { 
		temp = top; 
		top = top->link; 
		temp->link = NULL; 
		free(temp); 
	} 
} 

void display() 
{ 
	struct Node* temp; 

	if (top == NULL) { 
		printf("\nStack Underflow"); 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL) { 

			printf("%d ",temp->data); 

			temp = temp->link; 
		} 
	} 
} 

int main() 
{ 
	push(11); 
	push(22); 
	push(33); 
	push(44); 

	display(); 
	printf("\nTop element is %d\n",peek()); 

	pop(); 
	pop(); 

	display(); 
	printf("\nTop element is %d\n",peek()); 
	return 0; 

} 