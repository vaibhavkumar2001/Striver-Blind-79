// ISKA MAINE PURA ALGO MAIN APNI COPY MEIN LIKHA H WAHAN JAAKE MAIN PADH LOONGA    



#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
    public:
      long subarrayXor(vector<int> &arr, int k) {
          int n = arr.size(); //size of the given array.
          int xr = 0;
          map<int, int> mpp; //declaring the map.
          mpp[xr]++; //setting the value of 0.
          int cnt = 0;
      
          for (int i = 0; i < n; i++) {
              // prefix XOR till index i:
              xr = xr ^ arr[i];
      
              //By formula: x = xr^k:
              int x = xr ^ k;
      
              // add the occurrence of xr^k
              // to the count:
              cnt += mpp[x];
      
              // Insert the prefix xor till index i
              // into the map:
              mpp[xr]++;
        }
        return cnt;
    }
};