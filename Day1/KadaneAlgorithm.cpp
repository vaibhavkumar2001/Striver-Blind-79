// 


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            int maxi = INT_MIN;
            int sum = 0; // sum isliye le rhe h ki check kr paayoon ki jo ab tk ka sum h woh kahin negative toh nhi 
            for(int i = 0;i < n;i++) {
                sum += nums[i];
                maxi = max(maxi,sum); // Dono mein se max leliya maine
                if(sum < 0) {
                    sum = 0;
                }
            }
            return maxi;
        }
    };