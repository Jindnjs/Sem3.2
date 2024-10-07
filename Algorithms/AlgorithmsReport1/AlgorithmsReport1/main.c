//
//  main.c
//  AlgorithmsReport1
//
//  Created by 유진원 on 10/7/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int P[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    printf("4번 방법 *(&P[0][0] + 4 * 2 + 2) = %d\n",*(&P[0][0] + 4 * 2 + 2));
    return 0;
    
}
//
//    printf("1번 방법 P[2][2] = %d\n",P[2][2]);

//printf("2번 방법 *( *(P+2) + 2) = %d\n",*(*(P+2)+ 2));
//printf("3번 방법 (*(P+2))[2] = %d\n",(*(P+2))[2]);
//printf("4번 방법 *(&P[0][0] + 4 * 2 + 2) = %d\n",*(&P[0][0] + 4 * 2 + 2));
    
