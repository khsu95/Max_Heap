/* Insert x into Max heap*/

void push(element* HEAP, int item)
{
	int index;
	index = ++(*HEAP);
	while ((index != 1) && (item > HEAP[index / 2]))
	{
	HEAP[index] = HEAP[index / 2];
	index /= 2;
	}
	HEAP[index] = item;
}