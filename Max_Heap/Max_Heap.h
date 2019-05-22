#include <math.h>
#define MAX_ELEMENTS (10^6)


typedef struct
{
	int key;
}element;
element HEAP[MAX_ELEMENTS];
int parent, child;

typedef struct
{
	int key;
	int arr_index;
}cop_ar;

void bubble_sort(cop_ar arr[], int count);

/*I-th Big Value Finder*/
int search(int I_th)
{
	cop_ar cop_arr[MAX_ELEMENTS / 2] = { 0 };
	int temp, i, arr_temp;
	for (i = 1; 2 * i < I_th;i *= i);
	i += 1;
	printf("%d\n", i);
	arr_temp = I_th - i;
	temp = 0;
	
	for (int j = i;i <= (2*j-1);i++)
	{
		cop_arr[temp].key = HEAP[i].key;
		cop_arr[temp].arr_index = i;
		temp++;
	}
	
	bubble_sort(cop_arr, temp);
	return (cop_arr[arr_temp].arr_index);
}

/*Delete I-th max value from heap*/

int pop(int* index, int I_th)
{
	int item, temp;
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
	printf("Done\n");
	return 0;
}

/* Insert x into Max heap*/

int push(int* index, int item)
{
	int i;
	if(item<0)	return 0;
	i = ++(*index);
	while ((i != 1) && (item > HEAP[i / 2].key))
	{
		HEAP[i] = HEAP[i / 2];
		i /= 2;
	}
	HEAP[i].key = item;
	printf("Done\n");
	return 0;
}


/*Print I-th max value from heap, But DON't Remove*/

void Print_Ith(int index)
{
	printf("%d ", HEAP[index].key);
}

void bubble_sort(cop_ar arr[], int count)    // 매개변수로 정렬할 배열과 요소의 개수를 받음
{
	cop_ar temp;

	for (int i = 0; i < count; i++)    // 요소의 개수만큼 반복
	{
		for (int j = 0; j < count - 1; j++)   // 요소의 개수 - 1만큼 반복
		{
			if (arr[j].key < arr[j + 1].key)          // 현재 요소의 값과 다음 요소의 값을 비교하여
			{                                 // 큰 값을
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // 다음 요소로 보냄
			}
		}
	}
}
