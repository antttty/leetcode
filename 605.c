#include <stdbool.h>
#include <stdlib.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    bool    ret = false;
    int     sum = 0;
    int     tmp = 0;
    int     start = 0, end = -1;
    for(int i = 0; i <= flowerbedSize; i++){
        if (i == flowerbedSize)
            tmp = 1;
        else
            tmp = flowerbed[i];

        if (tmp == 1){
            end = i+1;
            if (end - start - 1 > 2){
                if ((end - start - 1)%2 == 0){//偶数
                    sum += ((end-start-1-2)/2);
                }else{//奇数
                    sum += ((end-start-1-1)/2);
                }
                if (sum >= n)
                    return true;
            }
            start = end;
        }
    }
    return ret;
}

int main(){
    int flowerbed[] = {1,0,0,0,1};
    bool ret = canPlaceFlowers(flowerbed, 5, 1);
    return 0;
}