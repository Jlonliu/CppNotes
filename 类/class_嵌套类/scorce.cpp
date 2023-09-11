#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
template<class Item>
class QueueTP {
private:
	enum{ Q_SIZE = 10 };
	class Node {
	public:
		Item item;
		Node* next;
		Node(const Item & i) :item(i), next(0) {}
	};
	Node * front;
	Node * rear;
	int items;//current number of intems in Queue
	const int qsize;//maximum number of items in Queue
	QueueTP(const QueueTP & q):qsize(0) { }
public:
	QueueTP(int qs = Q_SIZE);
	~QueueTP();
	bool isempty()const { return items == 0; }
	bool isfull()const { return  items == qsize; }
	int queuecount()const { return items; }
	bool enqueue(const Item &item);//addd item to end
	bool dequeue(Item &item);//remove item from front
};
template<class Item>
QueueTP<Item>::QueueTP(int qs) :qsize(qs) {
	front = rear = 0;
	items = 0;
}
template<class Item>
QueueTP<Item>::~QueueTP() {
	Node* temp;
	while (front != 0) {
		temp = front;
		front = front->next;
		delete temp;
	}
}
template<class Item>
bool QueueTP<Item>::enqueue(const Item &item) {
	if (isfull()) {
		cout << "Queue is full,can not enter new data.\n";
		return false;
	}
	else {
		Node * add = new Node(item);//create a new node
		items++;
		if (front == 0)
			front = add;
		else
			rear->next = add;//将add放入队尾
		rear = add;//rear指针指向队尾
		return true;
	}
}
template<class Item>
bool QueueTP<Item>::dequeue(Item & item) {
	if (isempty()) {
		cout << "Queue is empty,no data to use.\n";
		return false;
	}
	item = front->item;//获取数据
	items--;
	Node *temp = front;
	front = front->next;//指向下一个节点
	delete temp;//删除节点
	if (items == 0)//如果没有数据了
		rear = 0;//rear指向空
	return true;
}
int main(void) {
	{
		QueueTP<string> cs(5);
		string temp;
		while (!cs.isfull()) {
			cout << "Please enter your name: ";
			getline(cin, temp);
			cs.enqueue(temp);
		}
		cout << "The queue is full.\n";
		while (!cs.isempty()) {
			cs.dequeue(temp);
			cout << temp << endl;
		}
	}
	while (getchar() != '\n')
		continue;
	getchar(); return 0;
}