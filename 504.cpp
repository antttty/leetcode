#include <string>
#include <iostream>
using namespace std;

string convertToBase7(int num) {
        string ret;
        while(num != 0){
            int tmp = num % 7;
            ret = to_string(tmp) + ret;
            num = num / 7;
        }
        return ret;
    }

int main(){
    cout << convertToBase7(-7);
    return 0;
}