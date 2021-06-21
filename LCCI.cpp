/*两个数组得最小差值*/
#include <stdlib.h> //qsort
int compare(const void *a, const void *b);
int smallestDifference(int* a, int aSize, int* b, int bSize){
    qsort(a, aSize, sizeof(int), compare);
    qsort(b, bSize, sizeof(int), compare);
}

int main(){
    int numsa[] = {};
}

int compare(const void *a, const void *b){
    int *arg1 = (int *)a;
    int *arg2 = (int *)b;
    if (arg1 < arg2)
        return 1;
    if (arg1 > arg2)
        return -1;
    if (arg1 == arg2)
        return 0;
}