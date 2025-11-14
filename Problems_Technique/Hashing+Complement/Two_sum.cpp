#include<bits/stdc++.h>
using namespace std;
vector<int> twosum(vector<int>&nums,int target)
{
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++)
    {
        int comp=target-nums[i];
        if(hash.find(comp)!=hash.end())
        {
            return {hash[comp],i};
        }
        hash[nums[i]]=i;
    }
    return {-1,-1};
}
int main()
{
    vector<int> nums={1,2,3,4,5};
    int target=9;
    vector<int>res =twosum(nums,target);
    for(int x: res)
        cout<<x<<" ";
    cout<<endl;
}