#include <string.h>
#include <stdio.h>

#define min(a, b) ((a)<(b)?(a):(b))

/*这个计算的是全部围起来的面积*/
int maxArea2(int* height, int heightSize){
    int span = 1;
    int dp[heightSize][heightSize]; //dp[i][j]表示i--j范围内能解的雨水
    for (span = 1; span < heightSize; span++){
        int j = 0;
        for (j = 0; j < heightSize - span; j++){
            int rightj = j + span;
            if (span == 1){
                dp[j][j+span] = min(height[j], height[rightj]);
            }else{
                int k = 0;
                int tmpmax = 0x7fffffff;//int的最小值
                tmpmax = span * min(height[j], height[rightj]);
                for(k = j + 1; k < rightj; k++){
                    if (dp[j][k] + dp[k][rightj] > tmpmax)
                        tmpmax = dp[j][k] + dp[k][rightj];
                }
                dp[j][j+span] = tmpmax;
            }
        }
    }
    return dp[0][heightSize-1];
}

//当新来一条边时  向前找大于等于它的最远的那条边
//然后计算面积 如果计算的面积小于前面的 则不是最大的
int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int heightSize = 9;
    int ret = maxArea(height, heightSize);
    printf("--------------maxArea: %d\n", ret);
    return 0;
}