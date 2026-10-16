#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node *front = NULL, *rear = NULL;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* p = new Node{x, NULL};

        if (front == NULL)
            front = rear = p;
        else {
            rear->next = p;
            rear = p;
        }
    }

    for (Node* i = front; i != NULL; i = i->next) {
        Node* smallest = i;

        for (Node* j = i->next; j != NULL; j = j->next) {
            if (j->data < smallest->data)
                smallest = j;
        }

        int t = i->data;
        i->data = smallest->data;
        smallest->data = t;
    }

    cout << "Sorted queue: ";
    while (front != NULL) {
        cout << front->data << " ";
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}
