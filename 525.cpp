    #include <vector>
    #include <map>
    #include <iostream>
    using namespace std;

    int findMaxLength(vector<int>& nums) {
        int ret = 0;
        int presum = nums[0];
        map<int, int> mmap;
        if (presum == 0)
            presum = -1;
        mmap[presum] = 0;
        mmap[0] = -1;
        int tmp = 0;
        for (int i=1; i<nums.size(); i++){
            tmp = nums[i];
            if (tmp == 0)
                tmp = -1;
            presum = presum + tmp;
            if (mmap.find(presum) != mmap.end()){
                if (i+1-mmap[presum] > ret)
                    ret = i -mmap[presum];
            }else
                mmap[presum] = i;
        }
        return ret;
    }

    int main(){
        vector<int>     nums = {0,1,0};
        int ret = findMaxLength(nums);
        cout << ret << '\n';
        return 0;
    }