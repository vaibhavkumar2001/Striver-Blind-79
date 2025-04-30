#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n = intervals.size();
            //Pehle main sort kardoonga kyonki sort krne se saare intervals pass paas aayage
            sort(intervals.begin(),intervals.end());
            vector<vector<int>>ans;
            //ab main loop lgayunga
            for(int i = 0;i < n;i++) {
                //ab yahan pe do case banenge agr intervals ko merge krskte h ya fir merge nhi kr skte
                //Yeh woh wala case h jis mein main interval ko merge nhi kr skta
                if(ans.empty() || ans.back()[1] < intervals[i][0]) {
                    ans.push_back(intervals[i]);
                }
                else {
                    //Yahan woh wala case aayega jahan interval range mein h 
                    ans.back()[1] = max(ans.back()[1],intervals[i][1]);
                }
            }
            return ans;
        }
    };

    int main() {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i = 0;i < n;i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        vector<vector<int>> ans = obj.merge(intervals);
        for(int i = 0;i < ans.size();i++) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
        return 0;
    }