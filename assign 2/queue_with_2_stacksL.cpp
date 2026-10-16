#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* n = new Node;
        n->data = x;
        n->next = top;
        top = n;
    }

    int pop() {
        if (top == NULL) {
            cout << "Queue is empty\n";
            return -1;
        }

        Node* temp = top;
        int x = top->data;
        top = top->next;
        delete temp;
        return x;
    }

    bool empty() {
        return top == NULL;
    }
};

class Queue {
    Stack s1, s2;

public:
    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty())
                s2.push(s1.pop());
        }
        return s2.pop();
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
