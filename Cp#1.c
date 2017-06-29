// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int value;
	struct stack *next;
};
struct stack *top = NULL;

void push(int value);
int pop();
void print_stack();

int main()
{
	int value;
	int menu = 0;

	while (1)
	{
		printf("	0.|EXIT|	1.|POP|		2.|PUSH|	3.|PRINT|	 ");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			if (top == NULL)
			{
				printf("EMPTY\n");
				break;
			}
			printf("POP: %d\n", pop());
			break;
		case 2:
			printf("PUSH: ");
			scanf("%d", &value);
			push(value);
			break;
		case 3:
			if (top == NULL)
			{
				printf("EMPTY\n");
				break;
			}
			printf("PRINT:\n");
			print_stack();
			break;
		case 0:
			return 0;
			break;
		default:
			printf("Invalid number.\n");
			break;
		}
	}
	


	
	
	return 0;
}

void push(int value)
{
	struct stack *push;

	push = (struct stack*)malloc(sizeof(struct stack));
	if (push == NULL) {
		printf("Database is full; can't and more parts.\n"); 
		return;
	}	

	push->value = value;
	push->next = top;
	top = push;
}

int pop()
{
	struct stack *pop;
	int value;

	value = top->value;
	pop = top;
	top = top->next;
	free(pop);
	return value;
}

void print_stack()
{
	struct stack *print;
	for (print = top; print != NULL; print = print->next)
		printf("  %d\n", print->value);
}

