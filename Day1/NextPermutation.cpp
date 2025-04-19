#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int>nextGreaterPermutation(vector<int>&nums) {
    ///I am finding the break point
    int index = -1;
    int n = nums.size() - 1;
    for(int i = n - 2;i >= 0;i--) {
        if(nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        reverse(nums.begin(),nums.end());
        return nums;
    }

    for(int i = n - 1;i > index;i--) {
        if(nums[i] > nums[index]) {
            swap(nums[i],nums[index]);
            break;
        }
    }

    //Reverse the right whole array
    reverse(nums.begin() + index + 1,nums.end()); 
    return nums;
}

int main()
{
    vector<int> nums = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nextGreaterPermutation(nums);

    cout << "The next permutation is: [";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}