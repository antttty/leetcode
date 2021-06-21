#include <vector>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ret;
        int left1 = 0, left2 = 0;
        while(left1 < nums1.size() && left2 < nums2.size()){
            if (nums1[left1] == nums2[left2]){
                ret.push_back(left2);
                left2++;
                left1++;
            }else if (nums1[left1] < nums2[left2]){
                left1++;
            }else
                left2++;
        }
        return ret;
    }