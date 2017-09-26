#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int strStr(string haystack, string needle){
        for(int i = 0; i < haystack.size(); ++i){
            string p = haystack.substr(i);
            for(int j = 0; j < needle.size(); ++j){
                if(p[j] != needle[j]) {break;}
                if(j == needle.size()-1) {return i;}
            }
        }
        return -1;
    }

};

int main(){
    Solution s;
    string haystack("dhkabakdndajkan");
    string needle("kan");

    int result = s.strStr(haystack, needle);
    cout << result << endl;

    return 0;
}