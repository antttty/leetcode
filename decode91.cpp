#include <string.h>
#include <iostream>

int numDecodings(char * s){
    if (s[0] == '0')
        return 0;

    int len = strlen(s);
    int dp[len+1];
    dp[0] = 1;
    dp[1] = 1;

    int i = 0;
    for (i = 1; i < len; i++){
        if (s[i] == '0'){
            if (s[i-1] == '0' || s[i-1]>'2')
                return 0;
            else   
                dp[i+1] = dp[i-1];
        }else{
            if (s[i-1] == '1')
                dp[i+1] = dp[i] + dp[i-1];               
            else if (s[i-1] == '2'){
                if (s[i] < '7')
                    dp[i+1] = dp[i] + dp[i-1]; 
                else
                    dp[i+1] = dp[i]; 
            }
            else   
                dp[i+1] = dp[i];
        }
    }
    return dp[len];
}

int main()
{
    char s[] = "1111";
    int ret = numDecodings(s);
    std::cout << "-----ret:" << ret << '\n';
    return 0;
}
