#include <iostream>
using namespace std;

const int SIZE = 100;

class Queue {
    int s1[SIZE], s2[SIZE];
    int top1, top2;

public:
    Queue() {
        top1 = top2 = -1;
    }

    void enqueue(int x) {
        if (top1 == SIZE - 1) {
            cout << "Queue is full\n";
            return;
        }
        s1[++top1] = x;
    }

    int dequeue() {
        if (top2 == -1) {
            while (top1 != -1)
                s2[++top2] = s1[top1--];
        }

        if (top2 == -1) {
            cout << "Queue is empty\n";
            return -1;
        }

        return s2[top2--];
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}
