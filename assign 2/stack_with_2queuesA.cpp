#include <iostream>
using namespace std;

const int SIZE = 100;

class Queue {
    int a[SIZE], front, rear;

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    bool empty() {
        return front > rear;
    }

    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue full\n";
            return;
        }
        a[++rear] = x;
    }

    int dequeue() {
        if (empty()) return -1;
        return a[front++];
    }

    int size() {
        return rear - front + 1;
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        q2.enqueue(x);

        while (!q1.empty())
            q2.enqueue(q1.dequeue());

        Queue temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        if (q1.empty()) {
            cout << "Stack empty\n";
            return -1;
        }
        return q1.dequeue();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    return 0;
}
