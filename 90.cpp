    #include <vector>
    #include <set>
    using namespace std;
        set<vector<int>>        hashset;
        void dfs(int i, vector<int>& nums, vector<int> &tmp, vector<vector<int>> &ret){
        if (i == nums.size())
            return ;

        for (int index = i+1; index < nums.size(); index++){
            for (int j = index; j < nums.size(); j++){
                tmp.push_back(nums[j]);
                if (hashset.find(tmp) != hashset.end())
                    ;
                else{
                    hashset.insert(tmp);
                    ret.push_back(tmp);
                }
                    
            }
            tmp.clear();
            tmp.push_back(nums[i]);
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>     ret;
        vector<int>             tmp;
        tmp.clear();
        ret.push_back(tmp);

        for (int i=0; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            if (hashset.find(tmp) != hashset.end())
                ;
            else{
                hashset.insert(tmp);
                ret.push_back(tmp);
            }
                
            dfs(i, nums, tmp, ret);
            tmp.clear();
        }
        return ret;
    }

    int main(){
        vector<int> nums = {1,2,2,3};
        subsetsWithDup(nums);
        return 0;
    }