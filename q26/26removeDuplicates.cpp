/*
use two index, i is used to loop the whole vector, and j is used to indicate the
loaction of the valid number.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int l = nums.size();

        if(nums.empty()){
            return 0;
        }
        if(l == 1){
            return 1;
        }

        int j = 0;
        for(int i=1; i < l; ++i){
            if(nums[i]!=nums[j]){
                nums[j+1] = nums[i];
                ++j;
            }
        }
        return j+1;
    }
};

int main(){
    Solution s;
    int arr[] = {1,2,3,4,4,4,5,6,7,8,8,9};
    int cnt = sizeof(arr)/sizeof(int);
    vector<int> nums(arr, arr+cnt);

    int length = s.removeDuplicates(nums);
    for(int i = 0; i < length; ++i){
        cout << nums[i] << endl;
    }

    return 0;
}