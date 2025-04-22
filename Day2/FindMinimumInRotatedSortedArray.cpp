// Yahan mera logic yeh h ki main pehle ek ans bana loonga usko INT_MAX se initialze krwa loonga
// aab isme identify krna h ki kyon sa left ya right part sorted h 
//agr left part sorted h toh ans mein min store kr lenge min(ans,nums[start]) krke
//agr right part sorted h toh ans mein min store kr lenge min(ans,nums[mid]) krke


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int start = 0;
            int end = nums.size() - 1;
            int ans = INT_MAX;
            while(start <= end) {
                int mid = (start + end) / 2;
                if(nums[start] <= nums[mid]) {
                    ans = min(ans,nums[start]);
                    start = mid + 1;
                }
                else {
                    //mtlb right part h yeh
                    ans = min(ans,nums[mid]); // Yahan maine glt kiya tha yeh yaad rakhna h mujhe
                    end = mid - 1;
                }
            }
            return ans;
        }
    };