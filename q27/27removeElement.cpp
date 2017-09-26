#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int removeElement(vector<int> &nums, int val){
        int j = 0;
        for (int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main(){
    Solution s;
    int arr[] = {1,3,2,2,3,4,4,3};
    int cnt = sizeof(arr)/sizeof(int);
    vector<int> nums(arr, arr+cnt);

    int val = 3;

    int result = s.removeElement(nums, val);
    for(int i = 0; i < result; ++i){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}