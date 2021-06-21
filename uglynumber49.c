#include <stdio.h>
#include <stdlib.h> //atoi

int nthUglyNumber(int n){
    int pint[1690] = {1, 2, 3, 4, 5};
    int ret = 1;
    if (n <= 5)
        return pint[n-1];

    int i = 2, j = 1, k = 1, cur = 5; //表示在pint中的下标
    int prei = i, prej = j, prek = k;
    int tmp;
    while (cur < n){
        if (2 * pint[prei] <= 3 * pint[prej] && 2 * pint[prei] <= 5 * pint[prek]){
            tmp = 2 * pint[i];
            i++;
        } 
        if (3 * pint[prej] <= 2 * pint[prei] && 3 * pint[prej] <= 5 * pint[prek]){
            tmp = 3 * pint[prej];
            j++;
        }

        if (5 * pint[prek] <= 3 * pint[prej] && 5 * pint[prek] <= 2 * pint[prei]){
            tmp = 5 * pint[prek];
            k++;
        }

        prei = i;
        prej = j;
        prek = k;
        pint[cur++] = tmp;
    }
    return pint[--cur];
}

int main(int argc, char **argv){
    /*if (argc != 2){
        printf("usage : ./49 #number\n");
        return 0;
    }*/

    int ret = nthUglyNumber(109);
    printf("--------------ret : %d\n", ret);
    return 0;
}