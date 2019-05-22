#define MAX_ELEMENTS (10^6)


typedef struct
{
	int key;
}element;
element HEAP[MAX_ELEMENTS];
int parent, child;

/*Delete I-th max value from heap*/

void pop(int* index, int I_th)
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
}

/* Insert x into Max heap*/

void push(int* index, int item)
{
	int i;
	printf("Move to Push\n");
	printf("%d Inputed \n", item);
	i = ++(*index);
	while ((i != 1) && (item > HEAP[i / 2].key))
	{
		HEAP[i] = HEAP[i / 2];
		i /= 2;
	}
	HEAP[i].key = item;
}


/*Print I-th max value from heap, But DON't Remove*/

void Print_Ith(int index)
{
	printf("%d ", HEAP[index].key);
}
