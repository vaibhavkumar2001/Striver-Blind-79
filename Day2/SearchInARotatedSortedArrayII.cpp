// LOGIC -> 
// logic yeh h ki yeh code rotated sorted 1 ki tarah same pr yahan ek change h ki duplicates ko ignore karna padega agr arr[start] == arr[mid] == arr[end] iska mtlb ki equal h 


#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int n = nums.size();
            int start = 0;
            int end = n - 1;
    
            while (start <= end) {
                int mid = (start + end) / 2;
    
                if (nums[mid] == target) return true;
    
                // Edge case for duplicates
                if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                    start++;
                    end--;
                    continue;
                }
    
                // If left part is sorted
                if (nums[start] <= nums[mid]) {
                    if (nums[start] <= target && target < nums[mid]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                } else { // Right part is sorted
                    if (nums[mid] < target && target <= nums[end]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
    
            return false;
        }
    };
    