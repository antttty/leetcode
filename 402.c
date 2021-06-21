#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

char* removeKdigits(char* num, int k) {
    int n = strlen(num), top = 0;
    char* stk = (char*)malloc(sizeof(char) * (n + 1));
    memset(stk, 0, n+1);
    stk[top] = num[0];
    for (int i = 1; i < n; i++) {
        while (top >= 0 && stk[top] > num[i] && k) {
            top--;
            k--;
        }
        stk[++top] = num[i];
    }
    top -= k;

    char* ans = (char*)malloc(sizeof(char) * (n + 1));
    memset(ans, 0, n+1);
    int ansSize = 0;
    bool isLeadingZero = true;
    for (int i = 0; i <= top; i++) {
        if (isLeadingZero && stk[i] == '0') {
            continue;
        }else{
            isLeadingZero = false;
        }
        ans[ansSize++] = stk[i];
    }
    return ans;
}

int main(){
    char nums[] = {"10"};
    int k = 2;
    char *ret = removeKdigits(nums, k);
    printf("%s\n", ret);
    free(ret);
    return 0;
}