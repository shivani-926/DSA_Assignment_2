#include <iostream>
using namespace std;

void bubblesort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        bool flag = true;

        for (int j = 0; j < n - i; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = false;
            }
        }

        if (flag == true) {
            break;
        }
    }
}

int main() {
    int n;
    int A[100];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    bubblesort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
