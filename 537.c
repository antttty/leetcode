#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decode(char *num, int *real, int *img){
    char reals[5], imgs[5];
    bzero(reals, sizeof(reals));
    bzero(imgs, sizeof(imgs));

    char *span = strchr(num, '+');
    strncpy(reals, num, span-num);
    strncpy(imgs, span+1, strlen(num)-(span-num)-1);

    *real = atoi(reals);
    *img = atoi(imgs);
}

char * complexNumberMultiply(char * num1, char * num2){
    /*解析出4个数 然后利用乘法的规则进行计算*/
    int real1 = 0, img1 = 0, real2 = 0, img2 = 0;
    decode(num1, &real1, &img1);
    decode(num2, &real2, &img2);
    printf("%d %d %d %d", real1, img1, real2, img2);
    int proreal = 0, proimg = 0;
    proreal = real1 *real2 - img1 * img2;
    proimg = real1*img2 + real2 * img1;
    char *ret = malloc(16 * sizeof(char));
    bzero(ret, 16);
    sprintf(ret, "%d+%di", proreal, proimg);
    return ret;
}

int main(){
    char num[] = "1+1i";
    int real = 0, img = 0;
    char *p = complexNumberMultiply("1+-1i", "1+-1i");
    printf("%s\n", p);
    return 0;
}