#include <math.h>
#define MAX_ELEMENTS (10^6)


typedef struct
{
	int key;
}element;
element HEAP[MAX_ELEMENTS];
int parent, child;

/*I-th Big Value Finder*/
int search(int I_th)
{
	double index=(2^I_th)-1;
	for(index=((log(index))/(log(2)))+1; index<=I_th;index++);
	return HEAP[(int)index-1].key;
}

/*Delete I-th max value from heap*/

int pop(int* index, int I_th)
{
	int item, temp;
	printf("Move to Pop\n");
	printf("%d inputed\n", I_th);
	if (*index < I_th)
	{
		printf("Input Error too Big\n");
		return 0;
	}
	item = HEAP[I_th].key;
	temp = HEAP[(*index)--].key;
	parent = I_th;	child = 2*parent;
	while (child <= *index)
	{
		if ((child < *index) && HEAP[child].key < HEAP[child + 1].key)
			child++;
		if (temp >= HEAP[child].key)	break;
		HEAP[parent] = HEAP[child];
		parent = child;
		child *= 2;
	}
	HEAP[parent].key = temp;
	return 0;
}

/* Insert x into Max heap*/

int push(int* index, int item)
{
	int i;
	printf("Move to Push\n");
	printf("%d Inputed \n", item);
	if(item<0)	return 0;
	i = ++(*index);
	while ((i != 1) && (item > HEAP[i / 2].key))
	{
		HEAP[i] = HEAP[i / 2];
		i /= 2;
	}
	HEAP[i].key = item;
	return 0;
}


/*Print I-th max value from heap, But DON't Remove*/

void Print_Ith(int index)
{
	printf("%d ", HEAP[index].key);
}
