//Hmne yahan Morres Algorithm use kiya h 
// Morres algo yeh h ki 
// step 1: -> pehle hm count lete h aur element lete h 
// step2-> agr count 0 hota h toh element mein currenet element daal dete h aur count ko +++ kr dete h 
// step 3 -> aur agr current element mere element mein pada hue element ke equal h toh main count ko ++ krta hoon 
// step 4 -> Aur agr eqaual nhi h toh count -- krta hoon  


#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            int count  = 0;
            int element;
            for(int i = 0;i < n;i++) {
                if(count == 0) {
                    count++;
                    element = nums[i];
                }
                else if(nums[i] == element) {
                    count++;
                }
                else {
                    // na hi count 0 h naa hi nums[i] equal h element toh mtlb mujhe count ko -- krna h 
                    count--;
                }
            }
            // AB hm yahan pachuch gye h toh mujhe check element mein jo element pada hua woh n/2 se zyada h ki nhi mtlb ki yahan occurences check karenge
            int count1 = 0;
            for(int i = 0;i < n;i++) {
                // ab jo element maine find kiya tha moore; algo se usko yahan serach krarenge aur occurences check karenge
                if(nums[i] == element) {
                    count1++;
                }
            }
            if(count1 > (n/2)) {
                return element;
            }
            return -1;
        }
    };