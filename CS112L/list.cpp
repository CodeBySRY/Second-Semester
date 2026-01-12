#include <iostream>
using namespace std;

class Queue {
public:
    int front;
    int rear;
    int arr[100];

    Queue() : front(-1), rear(-1) {}

    bool isEmpty() { return front == -1 || rear == -1; }

    bool isFull() { return rear == 100 - 1; }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
            front = 0;

        rear++;
        arr[rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        front++;
        if (isEmpty())
            front = rear = -1;
        return ans;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


int main() {

    Queue q1;
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(25);

    q1.display();

    q1.dequeue();

    q1.enqueue(45);

    q1.display();



    return 0;
}