#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"Max_Heap.h"

#define HEAP_FULL(index) (index==MAX_ELEMENTS-1)
#define HEAP_EMPTY(index) (!index)

extern element HEAP[MAX_ELEMENTS];
int index = 0;

int main()
{
	char command[5] = { 0 };
	int I_th;
	printf("I(insert)\nD(delete)\nT(print)\nQ(quit)\n");
	while (1)
	{
		scanf("%s", &command);

		printf("\n");
		switch (command[0])
		{
		case'I':
			scanf("%d", &I_th);
			printf("%d", I_th);
			if (HEAP_FULL(index))
			{
				printf("FULLLL\n");	break;
			}
			push(&index, I_th);
			break;

		case'T':
			scanf("%d", &I_th);
			if(I_th<=0)	break;

			I_th=search(I_th);
			if (!(I_th) == 0) Print_Ith(I_th);
			else printf("0 ¾Ë¾ÒÀ½ \n");
			break;

		case'D':
			scanf("%d", &I_th);
			I_th=search(I_th);

			if (HEAP_EMPTY(index)||(I_th<=0))
			{
				printf("Error\n");	break;
			}
			if (I_th == 0)	pop(&index, 1);
			else pop(&index, I_th);
			break;

		case'P':
			if (HEAP_FULL(index)||HEAP_EMPTY(index))
			{
				printf("Error\n");
				break;
			}
			for (int j = 1;j <= index;j++)
				printf("%d ", HEAP[j].key);
			printf("\n");
			break;
		case'Q':
			return 0;

		default:
			printf("Wrong Input\n");
			break;
		}
		printf("\n");
	}
}
