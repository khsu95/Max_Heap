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

		printf("I(insert)\nD(delete)\nT(print)\n");
		scanf("%c", &command);

		printf("커맨드 입력 \n");

		switch (command)
		{
		case'I':
			scanf("%d", &item);
			printf("아이템 입력 \n");
			if (HEAP_FULL(index))
			{
				printf("FULLLL\n");	break;
			}
			push(&index, item);
			break;

		case'T':
			scanf("%d", &I_th);
			if (I_th == NULL)	Print_Ith(index, 1);
			else Print_Ith(index, I_th);
			break;

		case'D':
			scanf("%d", &I_th);
			if (HEAP_EMPTY(index))
			{
				printf("EMPTY\n");	break;
			}
			if (I_th == NULL)	pop(&index, 1);
			else pop(&index, I_th);
			break;

		default:
			printf("Wrong Input\n");
			break;
		}
		printf("지금은 %d \n index=%d\n", HEAP[index].key, index);
		command = 0;
	}
}