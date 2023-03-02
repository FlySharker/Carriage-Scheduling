#pragma once
#include"Assistance.h"

template<class T>
class SeqQueue
{
protected:
	double tag;
	int front, rear;
	int maxsize;
	T* elems;
public:
	SeqQueue(int size = 100);
	virtual ~SeqQueue();
	SeqQueue(const SeqQueue<T>& sa);
	SeqQueue<T>& operator=(const SeqQueue<T>& sa);
	int GetLength() const;
	bool IsEmpty() const;
	double QueueFull() const;
	double QueueEmpty() const;
	void Clear();
	void Traverse(void (*Visit)(const T&)) const;
	Status EnQueue(T e);
	Status GetHead(T& e);
	Status DelQueue(T& e);
};

template<class T>
SeqQueue<T>::SeqQueue(int size) :maxsize(size), front(0), rear(0), tag(0)
{
	if (elems != NULL) delete[] elems;
	elems = new T[maxsize];
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
	delete[] elems;
}

template<class T>
void SeqQueue<T>::Traverse(void (*Visit)(const T&)) const
{
	int k = 0;
	if (front == rear && tag == 0) {
		cout << "队列已空" << endl;
		return;
	}
	if (front == rear && tag == 1) {
		cout << "队列已满" << endl;
		for (int i = front; k < maxsize; i = (i + 1) % maxsize) {
			(*Visit)(elems[i]);
			k++;
		}
	}
	else {
		for (int i = front; i != rear; i = (i + 1) % maxsize) {
			(*Visit)(elems[i]);
		}
	}

}

template<class T>
Status SeqQueue<T>::EnQueue(T e)
{
	if (front == rear && tag == 1) return OVER_FLOW;
	else {
		elems[rear] = e;
		rear = (rear + 1) % maxsize;
		tag = QueueFull();
		return SUCCESS;
	}

}

template<class T>
bool SeqQueue<T>::IsEmpty() const
{
	return front == rear && tag == 0;
}

template<class T>
double SeqQueue<T>::QueueFull() const
{
	if (front != rear) return 0.5;
	else if (front == rear) return 1;
}

template<class T>
double SeqQueue<T>::QueueEmpty() const
{
	if (front != rear) return 0.5;
	else if (front == rear) return 0;
}

template<class T>
Status SeqQueue<T>::GetHead(T& e)
{
	if (IsEmpty()) {
		return UNDER_FLOW;
	}
	else {
		e = elems[front];
		return SUCCESS;
	}
}

template<class T>
Status SeqQueue<T>::DelQueue(T& e)
{
	if (IsEmpty()) {
		return UNDER_FLOW;
	}
	else {
		e = elems[front];
		front = (front + 1) % maxsize;
		tag = QueueEmpty();
		return SUCCESS;
	}
}

template<class T>
void SeqQueue<T>::Clear()
{
	front = 0;
	rear = 0;
	tag = 0;
}

template<class T>
int SeqQueue<T>::GetLength() const
{
	if (front == rear && tag == 1) return 5;
	else return (rear - front + maxsize) % maxsize;
}

template<class T>
SeqQueue<T>::SeqQueue(const SeqQueue<T>& sa)
{
	*this = sa;
}

template<class T>
SeqQueue<T>& SeqQueue<T>::operator=(const SeqQueue<T>& sa)
{
	if (this != &sa) {
		delete[] elems;
		elems = new T[sa.maxsize];
		tag = sa.tag;
		front = sa.front;
		rear = sa.rear;
		maxsize = sa.maxsize;
		for (int i = front; i != rear; i = (i + 1) % maxsize) {
			elems[i] = sa.elems[i];
		}
	}
	return *this;
}

