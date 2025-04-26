//ALGO mera yeh h ki -> Jb tk mere queue mein se chota element nhi milta toh jb tk pop krta jaayunga


#include<iostream>
#include<deque>
#include<vector>
using namespace std;


class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> ans;
            deque<int> dq;
            
            for(int i = 0; i < k; i++) {
                int element = nums[i];
                while(!dq.empty() && element > nums[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            
            for(int i = k; i < nums.size(); i++) {
                ans.push_back(nums[dq.front()]);
                
                // Remove elements not within the sliding window
                if(!dq.empty() && dq.front() <= i - k) {
                    dq.pop_front();
                }
                
                int element = nums[i];
                while(!dq.empty() && element > nums[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            
            ans.push_back(nums[dq.front()]);
            return ans;
        }
    };