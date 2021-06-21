#include <stdio.h>
#include <string.h>

int max(int x, int y){
    return (x>y)?x:y;
}

int lengthOfLongestSubstring(char * s){
    int     len = strlen(s);
    if (len <= 1)
        return len;

    int     l = 0, r = 1;
    int     ret = 1;
    for(; r < len; r++){
        int k = l;
        for(; k < r; k++){
            if (s[k] == s[r]){
                int tmp = r - l;
                l = k + 1;
                ret = max(ret, tmp);
                break;
            }
        }
    }
    ret = max(ret, r - l);
    return  ret;
}

int main(){
    char s[32] = "pwdegrgp";
    printf("ret:%d\n", lengthOfLongestSubstring(s));
    return 0;
}