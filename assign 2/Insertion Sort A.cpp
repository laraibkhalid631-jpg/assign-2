#include <iostream>
using namespace std;

int main() {
    int s[100], n, key, j;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 1; i < n; i++) {
        key = s[i];
        j = i - 1;

        while (j >= 0 && s[j] > key) {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = key;
    }

    cout << "Sorted stack: ";
    for (int i = n - 1; i >= 0; i--)
        cout << s[i] << " ";

    return 0;
}
