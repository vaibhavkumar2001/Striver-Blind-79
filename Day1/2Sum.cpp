// Yahan mera logic yeh ki pehle main do loop le rha toh mera TC O(N^2) aarhi thi toh maine approach change kr diya tha 
//Two pointer ka use kr rha tha pr yahan sort krne pr orginial array change ho rha toh maine uske indices store kr diya tha
// aur then main two pointer laga deta hoon

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            // Pehle main saara elements ka original index store kr leta hoon
            vector<pair<int,int>>arr;
            for(int i = 0;i < nums.size();i++) {
                arr.push_back({nums[i],i});
            } // Yahan tk mera arr ready h 
            //ab main nums ko sort kr deta hoon
            sort(arr.begin(),arr.end());
            //Ab main two pointer laga deta hoon
            int left = 0,right = nums.size() - 1;
            while(left < right) {
                int sum = arr[left].first + arr[right].first;
                if(sum == target) {
                    return {arr[left].second,arr[right].second};
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
            return {};
        }
    };

   int main() {
       vector<int>nums = {2,7,11,15};
       int target = 9;
       Solution obj;
       vector<int>ans = obj.twoSum(nums,target);
       for(auto it : ans) {
           cout << it << " ";
       }
   } 