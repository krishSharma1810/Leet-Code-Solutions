#include<iostream>
#include<vector>
using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they 
// add up to target.You may assume that each input would have exactly one solution, and you may not use the 
// same element twice.You can return the answer in any order.



// solution for leetcode
class solution {
    public:
    vector<int> twosum(vector<int> &nums,int target){
        int n=nums.size();
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                if(nums[i]+nums[i+1] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

// Main function to run on device..
int main(){
    vector<int> nums;
    vector<int> ans;
    int target;

    // write test case here.
    nums={2,7,11,15};
    target=9;


    solution sol;
    ans=sol.twosum(nums,target);
    for (int i=0;i<ans.size();i++){
        cout << ans[i]<<endl;
    }
}