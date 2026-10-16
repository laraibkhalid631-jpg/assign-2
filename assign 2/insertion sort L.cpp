#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* top = NULL;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* p = new Node{x, top};
        top = p;
    }

    Node* sorted = NULL;

    while (top != NULL) {
        Node* current = top;
        top = top->next;

        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* p = sorted;

            while (p->next != NULL &&
                   p->next->data <= current->data)
                p = p->next;

            current->next = p->next;
            p->next = current;
        }
    }

    top = sorted;

    cout << "Sorted stack (top to bottom): ";
    while (top != NULL) {
        cout << top->data << " ";
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    return 0;
}
