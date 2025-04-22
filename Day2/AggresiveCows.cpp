#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
class Solution {
  public:
    bool isPossibleSolution(int a[],int N,int M, int sol) {
        int pageSum = 0;
        int c = 1;
        for(int i = 0;i < N;i++) {
            if(a[i] > sol) {
                return false;
            }
            if(pageSum + a[i] > sol) {
                c++;
                pageSum = a[i];
                if(c > M) {
                    return false;
                }
            }
            else {
                pageSum += a[i];
            }
        }
        return true;
    }
    // Function to find minimum number of pages.
    int findPages(int N, int A[], int M) {
        if(M > N) {
            return -1;
        }
        int start = 0;
        int end = accumulate(A,A+N,0);
        int ans = 0;
        while(start <= end) {
            int mid = (start + end)/2;
            if(isPossibleSolution(A,N,M,mid)) {
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};