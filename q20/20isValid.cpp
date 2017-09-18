#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    bool isValid(string str){
        int i = 0;
        bool result = true;
        while(i < str.size()){
            result = isMatch(str[i], str[i+1]);
            if(result == false) {return result;}
            i = i+2;
        }

        return result;
    }

    bool isMatch(char s1, char s2){
        bool result = false;
        if(s1 == '(' and s2 == ')') {result = true;}
        if(s1 == '[' and s2 == ']') {result = true;}
        if(s1 == '{' and s2 == '}') {result = true;}

        return result;
    }
};

int  main(){
    Solution s;
    string str("(){}[]");

    bool result = s.isValid(str);
    cout << result << endl;

    return 0;
}