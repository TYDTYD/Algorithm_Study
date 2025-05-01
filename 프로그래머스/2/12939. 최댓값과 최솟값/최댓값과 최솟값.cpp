#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int mn=1e9;
    int mx=-1e9;
    string str="";
    for(const auto& c:s){
        if(c==' '){
            int idx=stoi(str);
            mn=min(mn,idx);
            mx=max(mx,idx);
            str="";
            continue;
        }
        str+=c;
    }
    int idx=stoi(str);
    mn=min(mn,idx);
    mx=max(mx,idx);
    answer+=to_string(mn);
    answer+=" ";
    answer+=to_string(mx);
    return answer;
}