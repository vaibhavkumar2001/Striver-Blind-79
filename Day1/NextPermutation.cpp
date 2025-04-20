// Algorithm / Intuition
// The steps are the following:

// Find the break-point,
//  i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
// For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
// To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
// If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
// So, in this case, we will reverse the whole array and will return it as our answer.
// If a break-point exists:
// Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
// Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.


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

    // Agr break point nhi toh array sorted h decreasing order mein toh main loop ki help se main right to left jayunga aur check krloonga 
    // toh maine array ko reverse kr diya 
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