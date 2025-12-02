#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> data;
    int head;             
    int tail;              
    int capacity;          

public:
    Queue(int k) {
        capacity = k + 1;
        data.resize(k + 1); 
        head = 0;
        tail = 0;
    }
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    int Rear() {
        if (isEmpty()) return -1;
        
        return data[(tail - 1 + capacity) % capacity];
    }
    int enQueue(int value) {
        if (isFull()) return 0; 
        data[tail] = value;
        tail = (tail + 1) % capacity; 
        return 1;
    }
    int deQueue() {
        if (isEmpty()) return 0;
        head = (head + 1) % capacity; 
        return 1;
    }
    int isEmpty() {
        return head == tail;
    }
    int isFull() {
        return (tail + 1) % capacity == head;
    }
};

int main(){
    int n, m, opt, num, ret;
    cin >> n >> m;
    Queue q(n);
    while (m--){
	cin >> opt;
	switch(opt){
	    case 0:
		cout << q.Front() << endl;
		break;
	    case 1:
		cout << q.Rear() << endl;
		break;
	    case 2:
		cin >> num;
		cout << q.enQueue(num) << endl;
		break;
	    case 3:
		cout << q.deQueue() << endl;
		break;
	    case 4:
		cout << q.isEmpty() << endl;
		break;
	    case 5:
		cout << q.isFull() << endl;
		break;
	    default:
		break;
	}
    }
    return 0;
}
