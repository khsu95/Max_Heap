/*Delete I-th max value from heap*/

void pop(int* index, int I_th)
{
	element item, temp;
	item = HEAP[I_th];
	temp = HEAP[(*index)--];
	parent = I_th;	child = 2;//�����ʿ�, ������ �����Ͽ� �ۼ��� ��
	while (child <= *index)
	{
		if ((child < *index) && HEAP[child].key < HEAP[child + 1].key)
			child++;
		if (temp.key >= HEAP[child].key)	break;
		HEAP[parent] = HEAP[child];
		parent = child;
		child *= 2;
	}
	HEAP[parent] = temp;
}