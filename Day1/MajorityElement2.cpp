#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int n = nums.size();
            int count1 = 0,count2 = 0;
            int element1 = INT_MIN,element2 = INT_MIN;
            for(int i = 0;i < n;i++) {
                if(count1 == 0 && nums[i] != element2) {// Yahan maine nums[i] != element2 yeh kyon kiya h ? Yeh maine isliye kiya h kyonki jb main yeh use karoonga toh jo maine pehle 1 ko le chuka tha aur uske help se maine calculation karliya tha aur fir count1 aaya toh usne phir doobara se 1 ko lekar calculation krna start krdiya toh yeh galat h toh isse bachne ke liye yeh algo use hua h 
                    count1++;
                    element1 = nums[i];
                }
                else if(count2 == 0 && nums[i] != element1) {
                    count2++;
                    element2 = nums[i];
                }
                else if(nums[i] == element1) count1++;
                else if(nums[i] == element2) count2++;
                else {
                    count1--;
                    count2--;
                }
            }
            // ab main majority check karoonga
            vector<int>ls;
            int cnt1 = 0,cnt2 = 0;
            for(int i = 0;i < n;i++) {
                if(nums[i] == element1) cnt1++;
                if(nums[i] == element2) cnt2++;
            }
            int mini = int(n / 3) + 1;
            if(cnt1 >= mini) ls.push_back(element1);
            if(cnt2 >= mini) ls.push_back(element2);
            return ls;
        }
    };