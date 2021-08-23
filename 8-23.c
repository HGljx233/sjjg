#include"Common.h"
//消失的数字
    int missingNumber(int* nums, int numsSize) {
        int sum = (1 + numsSize) * numsSize / 2;
        for (int i = 0; i < numsSize; i++) {
            sum -= nums[i];
        }
        return sum;
    }
//C++代码:计算数组中没重复的整数
//class Solution {
//public:
//    vector<int> singleNumbers(vector<int>& nums) {
//        int res = 0;
//        for (int num : nums) {
//            res = res ^ num;
//        }
//        int tmp = 1;
//        while (!(res & tmp)) {
//            tmp = tmp << 1;
//        }
//        int group1 = 0, group2 = 0;
//        for (int num : nums) {
//            if (num & tmp) {
//                group1 = group1 ^ num;
//            }
//            else {
//                group2 = group2 ^ num;
//            }
//        }
//
//        return vector<int>{group1, group2};
//    }
//};