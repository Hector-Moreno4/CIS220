#include <stdio.h>
#include <stdlib.h>
//Hector Moreno
//Chapter 5 PA

typedef struct {//Stack structure
int* items;
int top;
int maxSize;
} Stack;

void initializeStack(Stack *stack, int maxSize) {//Initialize the stack 
	stack -> items = malloc(maxSize * sizeof(int));
	stack -> top = -1;
	stack -> maxSize = maxSize;
}

void stackResize(Stack *stack, int *currentSize) {//doubles allocation size of array
    int newSize = *currentSize * 2;
    stack->items = realloc(stack->items, newSize * sizeof(int));
}

int push(Stack *stack, int item) {//pushes item to stack and determines if successful or not 
    if (stack -> top < stack -> maxSize - 1) {
        stack -> items[++stack -> top] = item;
        return 1;
    }
    else {
        stackResize(stack, &(stack -> maxSize));
        stack -> items[++stack -> top] = item;
        return 1;
    }
}

int pop(Stack *stack) {//pops item from stack and returns item popped
	if (stack -> top >= 0) {
		return stack -> items[stack -> top --];
	}
}

int isEmpty(Stack *stack) {//returns 1 if stack is empty or 0 if not empty
	return (stack -> top == -1) ? 1:0;
}

int peek(Stack *stack) {//returns value of item at top of stack 
	if (stack -> top >= 0) {
		return stack -> items[stack -> top];
	}
}

void printStack(Stack *stack) {//prints stack values
	if (stack -> top >= 0) {
	printf("The Stack contents are the following:\n");
	for (int i = stack -> top; i >= 0; --i) {
	printf("%d\n", stack -> items[i]);
	}
	}
	}
	
int main() {
int allocationSize;//Declare allocationSize and maxSize
int maxLength;

printf("Enter the allocation size of the stack: ");// Prompt user for allocation size and length
scanf("%d", &allocationSize);
printf("Enter the maximum length of the stack: ");
scanf("%d", &maxLength);

Stack stack;
initializeStack(&stack, allocationSize);

printf("Item 1 was pushed %s", push(&stack, 1) ? "successfully\n" : "unsuccessfully\n");//Push items 1 and 2 and determine if successful or unsuccessful
printf("Item 2 was pushed %s", push(&stack, 2) ? "successfully\n" : "unsuccessfully\n");

printf("The top item on the stack is: %d\n", peek(&stack));//Display top item on stack

printf("Item 3 was pushed %s", push(&stack, 3) ? "successfully\n" : "unsuccessfully\n");//Push item 3 and determine if successful or not

printf("The length of the stack is: %d\n", stack.top + 1);//Display stacks length

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("The top item on the stack is: %d\n", peek(&stack));//Display top item on stack

printf("Item 4 was pushed %s", push(&stack, 4) ? "successfully\n" : "unsuccessfully\n");//Push item 4 and determine if successful or not

printStack(&stack);//Print stack

printf("Item 5 was pushed %s", push(&stack, 5) ? "successfully\n" : "unsuccessfully\n");//Push item 5 and determine if successful or not

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("Item 6 was pushed %s", push(&stack, 6) ? "successfully\n" : "unsuccessfully\n");//Push item 6 and determine if successful or not

printStack(&stack);//Print stack

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("The stack is empty: %s\n", isEmpty(&stack) ? "true" : "false");//Determine if stack is empty

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("The item popped from the stack was %d\n", pop(&stack));//Pop item from stack and display its value

printf("The stack is empty: %s\n", isEmpty(&stack) ? "true" : "false");//Determine if stack is empty

return 0;
}











		

	
