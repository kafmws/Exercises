typedef struct {
	int *queue;
	int front;
	int rear;
	int maxSize;
	bool empty;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *q = malloc(sizeof(MyCircularQueue));
	if(!q)return NULL;
	q->queue = malloc(sizeof(int)*k);
	q->maxSize = k;
	q->front = q->rear = 0;
	q->empty = true;
	return q;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if(obj==NULL||myCircularQueueIsFull(obj)) {
		return false;
	}
	(obj->queue)[obj->rear] = value;
	obj->rear = (obj->rear+1)%obj->maxSize;
	if(obj->front==obj->rear)obj->empty = false;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if(obj==NULL||myCircularQueueIsEmpty(obj)) {
		return false;
	}
	obj->front = (obj->front+1)%obj->maxSize;
	if(obj->front==obj->rear)obj->empty = true;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	int re = -1;
	if(obj&&!myCircularQueueIsEmpty(obj)) {
		re = (obj->queue)[obj->front];
	}
	return re;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	int re = -1;
	if(obj&&!myCircularQueueIsEmpty(obj)) {
		re = (obj->queue)[obj->rear];
	}
	return re;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if(obj==NULL)return false;
	return (obj->front==obj->rear&&obj->empty)?true:false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if(obj==NULL)true;
	return 	(obj->front==obj->rear&&(!obj->empty))?true:false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	if(obj) {
		if(obj->queue) {
			free(obj->queue);
		}
		free(obj);
	}
}