#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            int prefix = 1, sufix = 1;
            int ans = INT_MIN;
            for(int i = 0;i < n;i++) {
                // Ab main yahan 0 wala case solve karoonga
                if(prefix == 0) prefix = 1;
                if(sufix == 0) sufix = 1;
                prefix *= nums[i];
                sufix *= nums[n - i - 1]; 
                ans = max(ans, max(prefix,sufix));
            }
            return ans;
        }
    };