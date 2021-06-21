#include <string.h>
#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *ret = malloc(201);
    bzero(ret, 201);

    int i = 0, j = 0;
    int len = 0;
    for (i = 0; i < strlen(strs[0]); i++)
    {
        char ch = strs[0][i];
        for(j = 1 ;j < strsSize; j++){
            if (strs[j][i] == '\0')//碰到
                break;
            if (strs[j][i] != ch)
                break;
        }

        if (j == strsSize)//遍历到了最后一个字符串
            ret[len++] = ch;
        else
            break;
    }

    ret[len] = '\0';//加上结束符
    return ret;
}

int main(){
    char *str[3] = {"dog","racecar","car"};
    char *ret = longestCommonPrefix(str, 3);
    printf("ret : %s!\n", ret);
    return 0;
}