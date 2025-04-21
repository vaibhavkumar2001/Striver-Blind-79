#include<iostream>
#include<vector>
#include<map>
using namespace std;


class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n = nums.size(); // size of the given array.
            map<int, int> mpp;
            int preSum = 0, cnt = 0;
    
            mpp[0] = 1; // Setting 0 in the map.
            for (int i = 0; i < n; i++) {
                // Add current element to prefix Sum:
                preSum += nums[i];
    
                // Calculate x-k: Yahan pe remove krne ka mtlb h ki main index ki baat kr rha hoon jo current index aur peeche ka index minus kr rha tha
                int remove = preSum - k;
    
                // Add the number of subarrays to be removed:
                if (mpp.find(remove) != mpp.end()) {
                    cnt += mpp[remove];
                }
    
                // Update the count of prefix sum in the map.
                mpp[preSum] += 1;
            }
            return cnt;
        }
    };
