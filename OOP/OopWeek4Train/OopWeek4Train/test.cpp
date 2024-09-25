#include <iostream>
using namespace std;

int main(void) {
    // 왼쪽행 오른쪽열 선형결합 2차원 행렬 곱

    // input data
    int n;
    cin >> n;

    int **A = new int *[n];
    int **B = new int *[n];
    int **C = new int *[n];
    int **D = new int *[n];

    for (int i = 0; i < n; i++) {
        A[i] = new int [n];
        B[i] = new int [n];
        C[i] = new int [n];
        D[i] = new int [n];
    }


    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cin >> A[i][j]) {
                count++;
            }
        }
    }

    // ArrB
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((cin >> B[i][j])) {
                count++;
            }
        }
    }

    if(count != (n*n*2)) {
        cout << "ERR" << endl;
        // 메모리 해제
        for (int i = 0; i < n; i++) {
            delete[] A[i];  // 각 행에 대해 delete[]
            delete[] B[i];
            delete[] C[i];
            delete[] D[i];
        }

        delete[] A;  // 전체 배열에 대해 delete[]
        delete[] B;
        delete[] C;

        delete[] D;
        return 0;
    }


    // C 배열에 A + B 저장
    for (int column = 0; column < n; column++) {
        for (int row = 0; row < n; row++) {
            C[column][row] = A[column][row] + B[column][row];
        }
    }

    // D 배열에 A * B 저장 (행렬 곱셈)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = 0; // 초기화
            for (int k = 0; k < n; k++) {
                D[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << D[i][j] << " ";
        }
    }

    cout << endl;
    // memory delete


    // 메모리 해제
    for (int i = 0; i < n; i++) {
        delete[] A[i];  // 각 행에 대해 delete[]
        delete[] B[i];
        delete[] C[i];
        delete[] D[i];
    }

    delete[] A;  // 전체 배열에 대해 delete[]
    delete[] B;
    delete[] C;
    delete[] D;


    return 0;
}

/**
 * input line 4 , 32개
 * while (cin >> v) : 몇개가 들어왔는지 카운트
 */
