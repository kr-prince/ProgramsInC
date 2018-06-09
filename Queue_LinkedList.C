#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *ptr;
} *front, *rear, *temp, *front1;

int count = 0;

void create() { front = rear = NULL; }

void queuSize() { printf(" Queue Size: %d\n", count);}

void enQueue(int data) {
	if (rear == NULL) {
		rear = (struct node*)malloc(1*sizeof(struct node));
		rear->ptr = NULL;
		rear->info = data;
		front = rear;
	} else {
		temp = (struct node *)malloc(1*sizeof(struct node));
		temp->info = data;
		temp->ptr = NULL;
		rear->ptr = temp;
		rear = temp;
	}
	count++;
}

void deQueue() {
	if (front == NULL) {
		printf(" Error: Queue is empty.\n");
		return;
	} else {
		front1 = front;
		printf(" Element %d is deleted.\n", front->info);
		if (front->ptr != NULL) {
			front1 = front1->ptr;
			free(front);
			front = front1;
		}
		else {
			free(front);
			front = NULL;
			rear = NULL;
		}
		count--;
	}
}

void displayQ() {
	if (front == NULL && rear == NULL) { 
		printf(" Queue is empty. \n");
	} else {
		front1 = front;
		while (front1 != rear) {
			printf(" %d ->", front1->info);
			front1 = front1->ptr;
		}
		if (front1 == rear) {
			printf(" %d \n", front1->info);
		}
	}
}

void empty() {
	if ((front == NULL) && (rear == NULL)) {
		printf(" Queue is empty. \n");
	} else {
		printf(" Queue not empty. \n");
	}
}

int frontElement() {
	if ((front != NULL) && (rear != NULL)) {
		return (front->info);
	} else {
		return -1;
	}
}

void reverse(struct node **head) {
	struct node *p, *q, *r;
	p = q = r = *head;
	p = p->ptr->ptr;
	q = q->ptr;
	r->ptr = NULL;
	q->ptr = r;

	while (p != NULL) {
		r = q;
		q = p;
		p = p->ptr;
		q->ptr = r;
	}
	*head = q;
}


int main() {
	int ch = 0, el;
	create();
	do {
		printf(" 1. EnQueue  2. DeQueue  3. Display  4. FirstElement  5. Empty?  6. Reverse  7. Exit\n "); 
		scanf("%d", &ch);

		switch(ch) {
			case 1: printf(" Enter element to be added : ");
					scanf("%d", &el);
					enQueue(el);
					queuSize();
					break;

			case 2: deQueue();
					queuSize();
					break;

			case 3: displayQ();
					break;

			case 4: printf(" First element is : %d \n",frontElement());
					break;

			case 5: empty();
					break;

			case 6: front1 = front;
					reverse(&front);
					rear = front1;
					//rear->ptr = NULL;
					
					displayQ();
					break;

			case 7: break;

			default: printf(" Invalid choice. Try again.");
		}
	} while (ch != 7);
	return 0;
}