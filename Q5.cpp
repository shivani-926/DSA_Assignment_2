#include <iostream>
using namespace std;

void displayMatrix(int n, int mat[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void diagonalMatrix(int n) {
    int diag[n];
    int mat[n][100] = {0};

    for (int i = 0; i < n; i++) {
        cout << "Enter diagonal element " << i << ": ";
        cin >> diag[i];
        mat[i][i] = diag[i];
    }
    displayMatrix(n, mat);
}

void triDiagonalMatrix(int n) {
    int diag[n], lower[n], upper[n];
    int mat[n][100] = {0};

    for (int i = 0; i < n; i++) {
        cout << "Enter main diagonal element " << i << ": ";
        cin >> diag[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << "Enter lower diagonal element " << i << ": ";
        cin >> lower[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cout << "Enter upper diagonal element " << i << ": ";
        cin >> upper[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) mat[i][j] = diag[i];
            else if (i == j + 1) mat[i][j] = lower[j];
            else if (i == j - 1) mat[i][j] = upper[i];
        }
    }
    displayMatrix(n, mat);
}

void lowerTriangularMatrix(int n) {
    int elems[n];
    int mat[n][100] = {0};

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> elems[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) mat[i][j] = elems[i];
        }
    }
    displayMatrix(n, mat);
}

void upperTriangularMatrix(int n) {
    int elems[n];
    int mat[n][100] = {0};

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i << ": ";
        cin >> elems[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) mat[i][j] = elems[i];
        }
    }
    displayMatrix(n, mat);
}

void symmetricMatrix(int n) {
    int mat[n][100] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "Enter element (" << i << "," << j << "): ";
            cin >> mat[i][j];
            mat[j][i] = mat[i][j];
        }
    }
    displayMatrix(n, mat);
}

int main() {
    int n, choice;
    cout << "Enter matrix size: ";
    cin >> n;

    do {
        cout << "\nChoose Matrix Type:\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-Diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: diagonalMatrix(n); break;
            case 2: triDiagonalMatrix(n); break;
            case 3: lowerTriangularMatrix(n); break;
            case 4: upperTriangularMatrix(n); break;
            case 5: symmetricMatrix(n); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n"; break;
        }
    } while (choice != 0);

    return 0;
}
