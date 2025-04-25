//Iss Question mera algo yeh h ki sbse pehle main nums2 pe ulta traverse karenge aur dhekhenge ki st ke top pe agr chota element mila toh main st se pop kr doonga

//step 2 -> phir agr stack ka top agr chota element mila toh main map ka bhi use kar rha hoon toh main uss number pe -1 rakh doonga aur uss number se bada milne pr uss number pe main uss st ke top wala number rakh doonga 

//step3-> Phir baad mein main vector bana ke uss nums1 ki us value pr uss st k top ko rakh doonga


#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            unordered_map<int, int> storeElement;
            stack<int> st;
            for(int i = nums2.size() - 1; i >= 0; i--) {
                while(!st.empty() && st.top() <= nums2[i]) {
                    st.pop();
                }
                if(st.empty()) {
                    storeElement[nums2[i]] = -1;
                } else {
                    storeElement[nums2[i]] = st.top();
                }
                st.push(nums2[i]);
            }
    
            vector<int> solution;
            for(int num : nums1) {
                solution.push_back(storeElement[num]);
            }
            return solution;
        }
    };
    