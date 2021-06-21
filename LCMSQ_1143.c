#include <string.h> //bzero
#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b)) 

int longestCommonSubsequence(char * text1, char * text2){
    int len1 = strlen(text1), len2 = strlen(text2);
    int pint[len2+1][len1+1];//c语言中二维数组的使用
    bzero(pint, ((len1+1)*(len2+1)) * sizeof(int));//初始化位0

    int ret;
    int i = 0, j = 0;
    for (i = 1; i <= len2 ; i++)
    {
        for (j = 0; j <= len1 ; j++)
        {
            if (j == 0)
                continue;
                
            if (text2[i-1] == text1[j-1])
            {
                pint[i][j] = pint[i-1][j-1] + 1;
            }else
                pint[i][j] = max(pint[i-1][j], pint[i][j-1]);
        }
    }

    return pint[len2][len1];
}

int main()
{
    char *text1 = "abcdef";
    char *text2 = "ace";
    int ret = longestCommonSubsequence(text1, text2);
    printf("ret:%d\n", ret);
    return 0;
}