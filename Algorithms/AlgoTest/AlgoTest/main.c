//
//  main.c
//  AlgoTest
//
//  Created by 유진원 on 10/8/24.
//

#include <stdio.h>

int seq(const int S[], int target);
int main(int argc, const char * argv[]) {
    // insert code here...
    
    const int S[] = {1,2,3,4,5,6,7,8,9,10};
    
    printf("%dth\n",seq(S,5));
    return 0;
}

int seq(const int *S, int target){
    int i;
    for (i=0;i<=9;i++){
        if(S[i] == target) return i;
    }
    
    return 0;
}
