nclude"duilie.h"

int IsFull(struct Deque* newDeque);
int IsEmpty(struct Deque* newDeque);
struct Deque* CreateDeque(int k)
{
	struct Deque* newDeque = (struct Deque *)malloc(sizeof(struct Deque));
	newDeque->front = newDeque->rear = 0;
	newDeque->size = ++k;
	int* Arr = (int *)malloc(sizeof(int) * newDeque->size);
	newDeque->arr = Arr;
	return newDeque;
}
void InsertFront(struct Deque* newDeque, int data)
{
	if(IsFull(newDeque))
	{
		return;
	}
	else
	{
		int index = (newDeque->front + newDeque->size - 1) % newDeque->size;
		newDeque->front = index;
		newDeque->arr[newDeque->front] = data;
	}
}
void InsertRear(struct Deque* newDeque, int data)
{
	if(IsFull(newDeque))
	{
		return;
	}
	else
	{
		int index = (newDeque->rear + 1) % newDeque->size;
		newDeque->arr[newDeque->rear] = data;
		newDeque->rear = index;
	}
}
void DeleteFront(struct Deque* newDeque)
{
	if(IsEmpty(newDeque))
	{
		return;
	}
	else
	{
		newDeque->front = (newDeque->front + 1) % newDeque->size;
	}
}
void DeleteRear(struct Deque* newDeque)
{
	if(IsEmpty(newDeque))
	{
		return;
	}
	else
	{
		newDeque->rear = (newDeque->rear + newDeque->size - 1) % newDeque->size;
	}
}
int DequeFront(struct Deque* newDeque)
{
	if(IsEmpty(newDeque))
	{
		return -1;
	}
	else
	{
		return newDeque->arr[newDeque->front];
	}
}
int DequeRear(struct Deque* newDeque)
{
	if(IsEmpty(newDeque))
	{
		return -1;
	}
	else
	{
		return newDeque->arr[(newDeque->rear + newDeque->size - 1) % newDeque->size]; 
	}
}
int IsEmpty(struct Deque* newDeque)
{
	if(newDeque->front == newDeque->rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsFull(struct Deque* newDeque)
{
	if(newDeque->front == (newDeque->rear + 1) % newDeque->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


