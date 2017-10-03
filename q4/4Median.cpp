#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    //THE FIRST METHOD: this method is complicate and not correct; this is my first try.
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int length1 = nums1.size();
    //     int length2 = nums2.size();
    //     int odd = (length1+length2)%2;
    //     int index = ceil((length1 + length2 + 1)/2.);

    //     int pre = 0;

    //     int curr1 = 0;
    //     int count = 0;
    //     int curr2 = 0;
    //     for (; curr1 < length1; curr1++){
    //         int j = curr2;
    //         if(j != length2){
    //             for (j; j < length2; j++){
    //                 count += 1;
    //                 if (nums1[curr1] < nums2[j]){
    //                     if (count >= index) {
    //                         if(odd) {return nums1[curr1];}
    //                         else {return (pre+nums1[curr1])/2.;}
    //                     }
    //                     pre = nums1[curr1];
    //                     break;
    //                 }
    //                 else{
    //                     curr2 += 1;
    //                     if(count >= index) {
    //                         if (odd) {return nums2[j];}
    //                         else {return (pre+nums2[j])/2.;}
    //                     }
    //                     pre = nums2[j];
    //                 }
    //             }
    //         }
    //         else{return (nums1[index-length2-1] + pre)/2.;}
    //     }
    //     if (count < index) {
    //         if (odd) {return nums2[index-length1-1];}
    //         else {return (nums2[index-length1-1]+nums2[index-length1-2])/2.;}
    //     }
    // }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp = merge(nums1, nums2);
        printVector(temp);
        int l = temp.size()/2;
        if(temp.size()%2) { return double(temp[l]);}
        else {return double(temp[l-1]+temp[l])/2.;}
    }

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> temp;
        int i = 0;
        int j = 0;

        while(i<nums1.size() and j<nums2.size()){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                temp.push_back(nums2[j]);
                j++;
            }
            else{
                temp.push_back(nums1[i]);
                temp.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        while(i < nums1.size()){
            temp.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()){
            temp.push_back(nums2[j]);
            j++;
        }

        return temp;
    }

    void printVector(vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int>::iterator int_iter;
    int iarr1[] = {1,2};
    int iarr2[] = {3};

    int count1 = sizeof(iarr1)/sizeof(int);
    int count2 = sizeof(iarr2)/sizeof(int);

    vector<int> nums1(iarr1, iarr1+count1);
    vector<int> nums2(iarr2, iarr2+count2);

    double median = s.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;

    return 0;
}