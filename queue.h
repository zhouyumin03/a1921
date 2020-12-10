#ifndef queue_h
#define queue_h
#include <stdio.h>
#include <stdlib.h>
struct Deque {
		int front;
			int rear;
				int size;
					int *arr;
};
int IsFull(struct Deque* newDeque);
int IsEmpty(struct Deque* newDeque);
struct Deque* CreateDeque(int k);
void InsertFront(struct Deque* newDeque, int data);
void InsertRear(struct Deque* newDeque, int data);
void DeleteFront(struct Deque* newDeque);
void DeleteRear(struct Deque* newDeque);
int DequeFront(struct Deque* newDeque);
int DequeRear(struct Deque* newDeque);
int IsEmpty(struct Deque* newDeque);
int IsFull(struct Deque* newDeque);

#endif
