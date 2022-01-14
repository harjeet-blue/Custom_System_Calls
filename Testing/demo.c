// Name - Harjeet Singh Yadav
// Roll Number - 2020561
// CSAI

#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SYS_matrix_copy 550  // 550 is my syscall id, change 
//this no according to your sycall id ( number which you gave it in the table )


int main(int argc, char **argv)
{
  
    float matrix1[2][3] = { {1.23, 2.56, 4.89 }, {3.123, 4.568, 8.235 } };
    float matrix2[2][3];
 
    printf("Making system call with matrix1 and matrix 2\n");

    long res = syscall(SYS_matrix_copy, matrix1, matrix2, 2, 3);

    printf("System call returned %ld.\n", res);
    perror("Console Output");

    printf("Matrix 2 : - After system call\n");

    for(int i = 0 ; i< 2 ; i++){

        for(int j =0 ; j<3 ; j++){

            printf("%d ",matrix2[i][j]);
        }

        printf("\n");
    }

    return res;
}
