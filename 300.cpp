#include <vector>
#include <iostream>
using namespace std;

//如何改进该算法 降低其复杂度为n * log n
int lengthOfLIS(vector<int>& nums) {
    vector<int> ret(nums.size(), 1);
    int len = 1;
    for (int i = 1; i < nums.size(); i++){
        for(int j = 0; j < i ; j++){
            if (nums[i] > nums[j]){
                ret[i] = max(ret[j]+1, ret[i]);
                if (ret[i] > len)
                    len = ret[i];
            }
        }
    }
    return len;
}

int main()
{
    int nums[] = {1,3,6,7,9,4,10,5,6};
    INT32_MAX;
    vector<int> ve(nums, nums+sizeof(nums)/sizeof(int));
    int ret = lengthOfLIS(ve);
    std::cout << "ret : " << ret;
    return 0;
}