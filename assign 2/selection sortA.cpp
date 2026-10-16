#include <iostream>
using namespace std;

int main() {
    int q[100], n, minIndex, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> q[i];

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (q[j] < q[minIndex])
                minIndex = j;
        }

        temp = q[i];
        q[i] = q[minIndex];
        q[minIndex] = temp;
    }

    cout << "Sorted queue: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}
