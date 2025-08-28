#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            count++;
        }
    }

    cout << "Total number of distinct elements: " << count << endl;
    return 0;
}
