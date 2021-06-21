/*数组时严格升序的*/
    #include <vector>
    #include <iostream>
    using namespace std;

    //长度为1000 可以遍历
    int findKthPositive(vector<int>& arr, int k) {
        if (arr[0] != 1 && k == 1)
            return 1;
        if (arr[0] == 1 && arr.back() == arr.size()) 
            return arr.back() + k;

        arr.push_back(__INT_MAX__);
        int ret = 1, preret = 1;
        int i = 0;
        for(i = 0; i < arr.size(); i++){
            ret = arr[i] - i - 1;//到i时 缺失了几个数
            if (ret > k)//
            {
                break;
            }
            preret = ret;
        }
        ret = arr[i-1] + (k - preret);
        return ret;
    }

    int main(){
        vector<int> arr = {1,2,3,4};
        cout << findKthPositive(arr, 2) << '\n';
        return 0;
    }
