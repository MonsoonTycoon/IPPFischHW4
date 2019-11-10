#include "matrix.h"

long possiblePathsRecursive(int M, int N) {
    if (M==0 || N==0) {
        return 0;
    }

    if (M+N==2) {
        return 1;
    }

    return possiblePathsRecursive(M-1, N) + possiblePathsRecursive(M, N-1);
}

long possiblePathsIterative(int M, int N) {
    if ( M == 0 || N == 0){
        return 0;
    }
    if ( M == 1 && N == 1){
        return 1;
    }
    Matrix<int> ansMatrix ( M, N ); //populate matrix
    for (int i = 0; i < M; i++) { // first row all 1
        ansMatrix.set(i, 0, 1);
    }
    for (int j = 0; j < N; j++) { // first col all 1
        ansMatrix.set( 0, j, 1);
    }
    for (int k = 1; k < M; k++) { //populate matrix
        for (int l = 1; l < N; l++) {
            ansMatrix.set( k, l , (ansMatrix.get( k-1, l ) + ansMatrix.get( k, l-1 ) ) );
        }
    }
    return ansMatrix.get( M-1, N-1 );
}

