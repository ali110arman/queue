#include "iostream"
using namespace std;
//......................................................kelas saf ba araye
class Queue {
public:
	Queue(int c);
	void Enqueue(int);
	void Dequeue();
	void Print();
	void queueFront();
	bool IsFull();
	bool IsEmpty();
private:
	int queue[100];
	int front, rear, capacity;
};

Queue::Queue(int c){	//dorost kardan saf
	front = rear = 0;
	capacity = c;
}

void Queue::Enqueue(int data){	//ezafe kardan be saf
	if (IsFull())				//agar por bood
		return;
	else {
		queue[rear] = data;
		rear++;
	}
}

void Queue::Dequeue(){		//hasf kardan az saf
	if (IsEmpty())			//agar khally bood
		return;
	else
		front++;
}

void Queue ::Print(){	//chap kardan saf
	if (IsEmpty())		//agar khally bood
		return;
	for (int i = front; i < rear; i++) 
		cout << queue[i]<<"\t";
}

void Queue::queueFront(){	//chap megdar aval list
	if (IsEmpty())			//agar khally bood
		return;
	cout<< queue[front];
}

bool Queue::IsFull() {		//baresy por boodan saf
	if (capacity == rear)	
		return false;
	else
		return true;
}

bool Queue::IsEmpty() {		//baresy khaly boodan saf
	if (front == rear)
		return false;
	else
		return true;
}








//......................................................kelas saf charkheshi ba araye
class cirQueue
{
	int rear, front;
	int size;
	int arr[100];
	cirQueue(int);
	void enQueue(int value);
	int deQueue();
	void displayQueue();
};

cirQueue::cirQueue(int s)
{
	front = rear = -1;
	size = s;
}
void cirQueue::enQueue(int value) {	//ezafe kardan be saf
	if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))	//baresy khaly boodan saf
		return;

	else if (front == -1) //ezafe kardan be ebteda
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size - 1 && front != 0)	//baressy khaly boodan
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}


int cirQueue::deQueue() {	//hazf kardan be saf
	if (front == -1)	//baresy khaly boodan saf
		return 0;
	int data = arr[front];
	arr[front] = -1;
	if (front == rear)	//agar por bood
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
		front = 0;
	else
		front++;

	return data;
}

void cirQueue::displayQueue()	//namyash saf
{
	if (front == -1)//baresy khaly boodan saf
		return;

	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout << arr[i] << " ";
	}
	else
	{
		for (int i = front; i < size; i++)
			cout << arr[i] << " ";

		for (int i = 0; i <= rear; i++)
			cout << arr[i] << " ";
	}
}








//......................................................kelas saf ba linklist
class QNode {
public:
	int value;
	QNode* next;
	QNode(int d)
	{
		value = d;
		next = NULL;
	}
};

class QueueByLinkList {
public:
	QueueByLinkList();
	void enQueue(int);
	void deQueue();
	bool IsFull();
	bool IsEmpty();
	int PrintFront();
	int PrintRear();
	QNode* front, * rear;
private:	
	QNode* NewNode(int);
};
QNode* QueueByLinkList::NewNode(int value) {	//dorost kardan node jadid
	QNode* node = new QNode(value);	//dorost kardan node jadid
	node->value = value;
	node->next = NULL;
	return node;
}

QueueByLinkList::QueueByLinkList(){
	front = rear = NULL;	//avalin bar magadir null ast
}

void QueueByLinkList::enQueue(int value){	//ezafe kardan be saf
	QNode* temp = new QNode(value);	//dorost kardan node jadid
	if (IsEmpty()) {
		front = rear = temp;	//node avalie han rear ast ham front
		return;
	}
	rear->next = temp;	//ezafe kardan node be enteha
	rear = temp;
}

void QueueByLinkList::deQueue(){	//hazf kardan az saf
	if (front == NULL)	//agar khally bood
		return;
	QNode * temp = front;
	front = front->next;
	if (front == NULL)	//agar front khally bood rear ham avaz mishavad
		rear = NULL;
	delete (temp);
}
bool QueueByLinkList::IsEmpty() {	//baresy por boodan saf
	if (rear == NULL)
		return true;
	else
		return false;
}
bool QueueByLinkList::IsFull() {	//baresy khally boodan saf
	if (front == NULL) 
		return true;
	else
		return false;
}

int QueueByLinkList::PrintFront() {		//chap front dar list
	QNode* temp = front;
	return temp->value;
}
int QueueByLinkList::PrintRear() {		//chap rear dar list
	QNode* temp = rear;
	return temp->value;
}









//......................................................kelas saf charckheshi ba link list
class cqlNode {
public:
	int data;
	cqlNode* link;
};

class cqlQueue {
public:
	cqlNode* front, * rear;
	void enQueue( int );
	int deQueue();
	void displayQueue();

};
cqlQueue* q = new cqlQueue;

void cqlQueue::enQueue( int value)	//ezafe kardan be saf
{
	cqlNode* temp = new cqlNode;
	temp->data = value;
	if (q->front == NULL)	//agar khally bood
		q->front = temp;
	else
		q->rear->link = temp;
	q->rear = temp;
	q->rear->link = q->front;
}

int cqlQueue::deQueue()	//hazf kardan be saf
{
	if (q->front == NULL) {	//agar khally bood
		return 0;
	}

	int value;
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else // There are more than one nodes 
	{
		cqlNode* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}

	return value;
}

void cqlQueue::displayQueue()
{
	cqlNode* temp = q->front;
	while (temp->link != q->front) {
		cout<< temp->data<<"	";
		temp = temp->link;
	}
	cout<< temp->data<<"	";
}





int main() {

	//saf sade

	//Queue q(10);
	//q.Enqueue(20);
	//q.Enqueue(30);
	//q.Enqueue(40);
	//q.Enqueue(50);
	//q.Dequeue();
	//q.Print();
	//cout << endl;





	//saf charkheshi

	//cirQueue q(5);
	//q.enQueue(14);
	//q.enQueue(22);
	//q.enQueue(13);
	//q.deQueue();
	//q.displayQueue();
	//return 0;



	
	//saf ba link list

	//QueueByLinkList q;
	//q.enQueue(1);
	//q.enQueue(2);
	//q.enQueue(3);
	//q.deQueue();
	//q.deQueue();
	//q.enQueue(4);
	//q.deQueue();
	//q.enQueue(5);
	//cout << "Queue Front : " << q.PrintFront() << endl;
	//cout << "Queue Rear : " << q.PrintRear() << endl;





	//saf charckeshi ba link list

	cqlQueue qw;
	q->front = q->rear = NULL;
	qw.enQueue(1);
	qw.enQueue(2);
	qw.enQueue(3);
	qw.displayQueue();
	cout<<qw.deQueue();
	qw.enQueue(4);
	qw.enQueue(5);
	qw.displayQueue();


	return 0;
}