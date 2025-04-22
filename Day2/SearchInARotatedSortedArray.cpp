#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();
            int start = 0;
            int end = n - 1;
            while(start <= end) {
                int mid = (start + end) / 2;
                if(nums[mid] == target) return mid; // yahan maine mid i target return kr diya tha maine 
                // If the left part is sorted
                if(nums[start] <= nums[mid]) {
                    if(nums[start] <= target && target <= nums[mid]) {
                        //right part ko hata doonga
                        end = mid - 1;
                    }
                    else {
                        start = mid + 1;
                    }
                }
                else {
                    //right part is sorted
                    if(nums[mid] <= target && target <= nums[end]) {
                        //element exists
                        start = mid +  1;
                    }
                    else {
                        // element does not exists
                        end = mid - 1;
                    }
                }
            }
            return -1;
        }
    };