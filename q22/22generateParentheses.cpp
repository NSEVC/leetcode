#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        string meta = "()";
        for(int i = 0; i < n; ++i){
            result = combine(result, meta);
        }

        return result;
    }

    vector<string> combine(vector<string> result, string meta){
        if(result.empty()) {
            result.push_back(meta);
            return result;
        }
        else{
            set<string> tmp;

            int l1 = result.size();
            for(int i = 0; i < l1; ++i){
                int l2 = result[i].size();
                for(int j = 0; j < l2; ++j){
                    string str = result[i];
                    tmp.insert(str.insert(j, meta));
                }
            }
            return vector<string> (tmp.begin(), tmp.end());
        }
    }
};

int main(){
    Solution s;
    int n = 4;

    vector<string> reslut = s.generateParenthesis(n);

    for(int i = 0; i < reslut.size(); ++i){
        cout << reslut[i] << endl;
    }


    return 0;
}