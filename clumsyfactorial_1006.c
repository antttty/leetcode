#include <stdio.h>
/*直接在一个循环中计算*/

//仔细观察算式的格式 可以用递归解决该问题
int clumsy(int N){
    int sum = 0, sumpart = 0;
    int tmp = 1;
    int i = 0, ipart1 = (N-1)/4, ipart2 = (N-1)%4;
    while (i < ipart1)
    {
        //计算到当前part的sum值
        sumpart = tmp * N*(N-1)/(N-2);
        N = N - 3;
        sumpart = sumpart +  N;
        if (tmp == 1)
            tmp = -1;
        i++;
        N--;
        sum += sumpart;
    }

    //计算剩余部分的值
    sumpart = 0;
    if (sum == 0) {
        switch (ipart2)
        {
        case 3:
            sumpart = 7;
            break;
        case 2:
            sumpart = 6;
            break;
        case 1:
            sumpart = 2;
            break;
        case 0:
            sumpart = 1;
            break;
        default:
            break;
        }
    } else{
        switch (ipart2)
        {
        case 3:
            sumpart = -5;
            break;
        case 2:
            sumpart = -6;
            break;
        case 1:
            sumpart = -2;
            break;
        case 0:
            sumpart = -1;
            break;
        default:
            break;
        }
    }
    sum += sumpart;
    return sum;
}

int main()
{
    int  N = 14;
    int ret = clumsy(N);
    printf("ret:%d\n", ret);
    return 0;
}
