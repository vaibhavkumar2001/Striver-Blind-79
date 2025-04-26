//Mera intuition yeh h ki main stack mein unn elements ko rakhoonga jo mera ans banane mein help karenge

//EK logic yeh ki pehle main stack mein current ast ko push krdoonga agr woh positve h toh 

//agr stack ka top positive h toh aur jo curr ast h woh negative h toh dono destroy honge


#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int>st;
            for(auto ast : asteroids) {
                bool destroy = false; //YEh maine flag banaya h jo batayega ki curr ast destroy hua h ki nhi 
                // asteriods mein se maine ast nikal liya
                //ast postive h toh maine stack mein push kr diya
                if(ast > 0) {
                    st.push(ast);
                }
                else {
                    // ab jo mera curr ast aarha h woh negative h toh 
                    while(!st.empty() && st.top() > 0) {
                        if(st.top() == abs(ast)) {
                            // agr st ke top ki value aur curr ast ki value same h toh destroy krdo
                            destroy = true;
                            //aur stack se pop krdo
                            st.pop();
                            break;
                        }
                        else if (st.top() > abs(ast)) {
                            destroy = true;
                            break;
                        }
                        else {
                            // mtlb st.top() less h ast se toh stack ka top destroy hojaayega
                            st.pop();
                        }
                    }
                    if(!destroy) {
                        st.push(ast); // Agr destroy true h toh st mein push krdo curr ast ko
                    }
                }
            }
            //Collect the remaining asteroids from the stack
            vector<int>ans(st.size());
            for(int i = st.size() - 1;i >= 0;i--) {
                ans[i] = st.top();
                st.pop();
            }
            return ans;
        }
    };