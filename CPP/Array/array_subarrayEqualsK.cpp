#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        int cnt = 0;
        unordered_map<int,int> mapp;

        mapp[0] = 1;

        for (int i=0; i < nums.size();i++){
            total = total + nums[i];
            if (mapp.find(total-k) != mapp.end()){
                cnt = cnt + mapp[total-k];
            }
            mapp[total]++;
        }

        return cnt;
    }
};

int main(){
    Solution s;
    s.subarraySum({1,2,3,1,2,1},3);

    return 0;
    
}