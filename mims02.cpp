#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int ret = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());

        int j = drinks.size() - 1;
        for (int i= 0; i < staple.size(); i++){
            int tmp = x - staple[i];
            if (tmp <= 0)
                break;
            while (j >= 0 && drinks[j] > tmp){
                j--;
            }
            ret =  (ret + j + 1) % 1000000007;
        }
        return ret;
    }

    int main(){
        vector<int> staple = {7,3,4,3,9,9,10,8,8,3};
        vector<int> drinks = {7,10,6,7,5,2,8,4,5,8};
        cout << breakfastNumber(staple, drinks, 5) << '\n';
        return 0;
    }