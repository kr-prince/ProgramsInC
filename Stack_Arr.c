#include <stdio.h>

int stack[10];
int top = -1;

void popFromStack() {
	if (top == -1) {
		printf(" Stack is empty..! \n");	
	}
	else {
		printf(" Deleted element is %d\n", stack[top]);
		top -= 1;
	}
}

void pushToStack(int n) {
	if (top == 10) {
		printf(" Stack is full..!\n");
	}
	else {
		stack[++top] = n;
		printf(" Element %d is inserted.\n", n); 
	}
}

void displayStack() {
	for (int i =0 ; i<=top; ++i) {
		printf(" %d ->", stack[i]);
	}
	printf("|\n");
}

int main() {
	int ch = 0, d;
	do {
		printf(" Enter choice : 1. Push  2. Pop  3. Display  4. Exit  ->  ");
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf(" Enter an element: ");
					scanf("%d", &d);
					pushToStack(d);
					break;

			case 2: popFromStack();
					break;		

			case 3: displayStack();
					break;		

			case 4: break;

			default: printf(" Invalid choice. Try again.\n");				
		}

	}while (ch != 4);
	return 0;
}