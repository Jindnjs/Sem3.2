//
//  main.cpp
//  OopWeek4Train
//
//  Created by 유진원 on 9/25/24.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int N;
    std::cin >> N;
    
    int **A = new int *[N];
    int **B = new int *[N];
    int **C = new int *[N];
    int **D = new int *[N];

    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
        B[i] = new int[N];
        C[i] = new int[N];
        D[i] = new int[N];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(!(std::cin >> A[i][j])) {
                std::cout << "ERR" << std::endl;
                for (int i = 0; i < N; i++) {
                    delete[] A[i];delete[] B[i];
                    delete[] C[i];delete[] D[i];
                }
                delete[] A;delete[] B;
                delete[] C;delete[] D;
                return 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!(std::cin >> B[i][j])) {
                std::cout << "ERR" << std::endl;
                for (int i = 0; i < N; i++) {
                    delete[] A[i];delete[] B[i];
                    delete[] C[i];delete[] D[i];
                }
                delete[] A;delete[] B;
                delete[] C;delete[] D;
                return 0;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            D[i][j] = 0;
            for (int a = 0; a < N; a++) {
                D[i][j] += A[i][a] * B[a][j];
            }
        }
    }
    
    for (int i = 0; i< N; i++){
        for (int j = 0; j<N; j++)
            std::cout << C[i][j] << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i< N; i++){
        for (int j = 0; j<N; j++)
            std::cout << D[i][j] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < N; i++) {
        delete[] A[i];delete[] B[i];
        delete[] C[i];delete[] D[i];
    }
    delete[] A;delete[] B;
    delete[] C;delete[] D;

    return 0;
}
