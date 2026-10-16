#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool empty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* n = new Node{x, NULL};

        if (rear == NULL)
            front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }
    }

    int dequeue() {
        if (empty()) return -1;

        Node* temp = front;
        int x = temp->data;
        front = front->next;

        if (front == NULL) rear = NULL;

        delete temp;
        return x;
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
