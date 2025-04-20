 // Yahan maine Most optimal Solution likha h maine 



 // yahan mera AGLORITHM yeh h ki main 2 pointer ka use karoonga 
//Step1 -> pehle main ek i aur j leta h dono ko ek hi jagah pe rakhta hoon 
// Step 2-> phir main j ko aage badaoonga aur sum mein current element ko add krta jaaoonga 
// Step 3-> sum mein add krte krte agr sum mera k se bada hojaayga toh main i ko minus kardonga
// Step 4-> Mera seedha seedha yahan pe yeh kr rha hoon ki main j ko bhi aage badha rha hoon aur i ko tbhi aage badha rha hoon jb mera sum  k se bada hojaayega tb 
#include <bits/stdc++.h>
using namespace std;

int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.

    int left = 0, right = 0; // 2 pointers
    long long sum = a[0];
    int maxLen = 0;
    while (right < n) {
        // if sum > k, reduce the subarray from left
        // until sum becomes less or equal to k:
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }

        // if sum = k, update the maxLen i.e. answer:
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }

        // Move forward thw right pointer:
        right++;
        if (right < n) sum += a[right];
    }

    return maxLen;
}

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    long long k = 10;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}



