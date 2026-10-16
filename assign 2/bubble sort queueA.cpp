#include <iostream>
using namespace std;

int main() {
    int q[100], n, temp;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> q[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (q[j] > q[j + 1]) {
                temp = q[j];
                q[j] = q[j + 1];
                q[j + 1] = temp;
            }
        }
    }

    cout << "Sorted queue: ";
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}
