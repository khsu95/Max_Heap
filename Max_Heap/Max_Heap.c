#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"Max_Heap.h"

#define HEAP_FULL(index) (index==MAX_ELEMENTS-1)
#define HEAP_EMPTY(index) (!index)

extern element HEAP[MAX_ELEMENTS];
int index = 0;

int main()
{
	char command = 0;
	while (1)
	{
		int I_th, item;

		printf("I(insert)\nD(delete)\nT(print)\nQ(quit)");
	
		command=0;
		scanf("%c", &command);

		printf("Command Inputed \n");

		switch (command)
		{
		case'I':
			scanf("%d", &item);
			printf("Item Inputed\n");
			if (HEAP_FULL(index))
			{
				printf("FULLLL\n");	break;
			}
			push(&index, item);
			break;

		case'T':
			scanf("%d", &I_th);
			if(I_th<=0)	break;

			I_th=search(I_th);
			if (I_th == 0)	Print_Ith(1);
			else Print_Ith(I_th);
			break;

		case'D':
			scanf("%d", &I_th);
			I_th=search(I_th);

			if (HEAP_EMPTY(index)||(I_th<=0))
			{
				printf("Error\n");	break;
			}
			if (I_th == NULL)	pop(&index, 1);
			else pop(&index, I_th);
			break;
		case'Q':
			return 0;

		default:
			printf("Wrong Input\n");
			break;
		}
		printf("Now Key Value=%d \n index=%d\n", HEAP[index].key, index);
	}
}
