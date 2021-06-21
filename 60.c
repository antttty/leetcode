#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*二分法 有序 查找*/
int search(int* nums, int numsSize, int target){
    int     ret = -1;
    int     l = 0, r = numsSize-1;
    int     mid = 0;
    while(l<=r){
        mid = l + (r - l)/2;
        if (nums[mid] == target){
            ret = mid;
            break;
        }

        if (nums[l] > nums[r]){//逆序
            if (nums[mid] < target){
                if (nums[r] < nums[mid]){
                    l = mid +1;
                }else{
                    if (nums[r] < target){
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
            }else{
                if (nums[l] > nums[mid]){
                    r = mid - 1;
                }else{
                    if (nums[l] > target){
                        l = mid + 1;
                    }else{
                        r = mid - 1;
                    }
                }
            }
        }else{//升序
            if (nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
    return ret;
}

int main(){
    char *pret = getPermutation(5, 68);
    printf("%s!\n", pret);
    free(pret);
    return 0;
}