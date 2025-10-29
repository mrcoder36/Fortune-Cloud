#include <stdio.h>

int main() {


    // 1 D array
    // int arr[5];
    // arr[0] = 11;
    // arr[1] = 22;
    // arr[2] = 33;
    // arr[3] = 44;
    // arr[4] = 55;

    // printf("%d", arr[0]);
    // printf("%d", arr[1]);
    // printf("%d", arr[2]);
    // printf("%d", arr[3]);
    // printf("%d", arr[4]);

    // for (int i = 0; i <= 4; i++) {
    //     printf("%d\n", arr[i]);
    // }


    // 2D array ------------

    // int num[3][2] ={{1,2},
    //                 {2,3},
    //                 {3,4}};
    // int r, c;

    // for (int r = 0; r < 3; r++) {      // 0<3true 1<3true 2<3true 3<3false
    //     for (int c = 0; c < 2; c++) {  // 0<2true 1<2true 2<2 false
    //         printf("%d ", num[r][c]);  // 1 2
    //     }                              // 2 3
    //     printf("\n");                  // 3 4
    // }


    // 3D ARRAY ---------------------

    int myarr[2][3][2] = {{{1,2},{3,4},{2,4}},
                            {{5,6},{7,8},{6,8}}};
    int d, r, c;

    for (int d = 0; d < 2; d++) {
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 2; c++){
                printf("%d ", myarr[d][r][c]);
            }
            printf("\n");
        }
        printf("\n");
        
    }
    
    


}