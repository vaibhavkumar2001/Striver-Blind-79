//Yahan pe mera yeh logic h ki pichle appraoch mein maine set aur hashset ka use kiya tha aur wahan pe do loop ka use kiya thaa toh isse bachne ke liya main pehle array ko sort krdiya set se bachne ke liye

// aur main use kr rha tha hashet duplicate ko ignore krne ke liye toh is liye main loop ka use krke duplicate ko ignore krliye




#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // Yeh hm pehla i chalayenge duplicates ko remove krne ke liye
            int n = nums.size();
            vector<vector<int>>ans;
            sort(nums.begin(),nums.end()); // sort hm isliye use kr rhe h kyonki hm pichli approach mein set ka use krke sort kr rhe toh hmne yahan direct sort kr diya
            for(int i = 0;i < n;i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue;
                // Now ab hm do pointers ko aage badayanenge
                int j = i + 1;
                int k = n - 1;
                while(j < k) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum < 0) {
                        //mtlb ki sum negative aagaya h 
                        j++;
                    }
                    else if(sum > 0){
                        //negative nhi h toh 
                        k--;
                    }
                    else {
                        vector<int>temp = {nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        //ab hm yahan duplicates ko ignore krna h 
                        while(j < k && nums[j] == nums[j - 1]) j++;
                        while(j < k && nums[k] == nums[k + 1]) k--;
                    }
                }
            }
            return ans;
        }
    };