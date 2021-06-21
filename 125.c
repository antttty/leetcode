#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
bool isCh(char x){
    return x>=65 && x<=90 ||
        x>=97 && x<=122;
}
bool isMatch(char x, char y){
    if (!(isCh(x) && isCh(y)))
        return false;
        
    int off = abs(x-y);
    return  off == 0 || off == 32;
}

bool isSpace(char x){
    return x==' ';
}

bool isPalindrome(char * s){
    int     l = 0, r = strlen(s) - 1;
    bool    ret = true;
    while( l <= r){
        while (l < strlen(s) && isSpace(s[l]))
            l++;

        while (r>=0 && isSpace(s[r]))
            r--;
        
        if (l>r)
            break;

        if (!isMatch(s[l], s[r])){
            ret = false;
            break;
        }else{
            l++;
            r--;
        }
    }

    return  ret;
}

int main(){
    char s[] = "0P";
    bool ret = isPalindrome(s);

    return 0;
}