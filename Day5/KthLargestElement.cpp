//ALgo -> Iss questions mein main min heap ka use karoonga kyonki min heap use krne se mujhe k largest elements mujhe queue ke top pe mil jayega aur baaki bache hue chote elements queue se bahar hojaayege

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            //Pehle main min Heap Banayunga
            priority_queue<int,vector<int>,greater<int>>pq;
            //Ab mian first k elements ko push karoonga queue mein
            for(int i = 0;i < k;i++) {
                int elements = nums[i];
                pq.push(elements);
            }
            //Ab main baaki bache hue ko queue mein push karoonga main tbhi push jb current element queue ke top se bada hoga
            for(int i = k;i < nums.size();i++) {
                int elements = nums[i];
                if(elements > pq.top()) {
                    //Jo pehle se hi top pe pada hua ukso queue se pop krdoonga
                    pq.pop();
                    pq.push(elements);
                }
            }
            int ans = pq.top();
            return ans;
        }
    };