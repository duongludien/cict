//Duong Lu Dien
//B1401133

#define MAX_ELEMENTS 200

typedef int ElementType;

typedef struct {
	ElementType data[MAX_ELEMENTS];
	int front, rear;
} Queue;

void make_null_queue(Queue *Q) {
	Q->front = 0;
	Q->rear = -1;
}

void push(Queue *Q, int x) {
	Q->rear++;
	Q->data[Q->rear] = x;
}

ElementType top(Queue Q) {
	return Q.data[Q.front];
}

void pop(Queue *Q) {
	Q->front++;
}

int empty_queue(Queue Q) {
	return Q.front > Q.rear;
}
