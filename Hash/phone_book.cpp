#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<int,string> d;
    int a=0;
    for(auto& i : phone_book){
        d[a] = i;
        a++;
    }
    a=0;
    int b=0;
    for(auto& i : phone_book){
        for(b=0;b<phone_book.size();b++){
            string cmp_str = d[a];
            if(d[b].substr(0,d[a].length()).compare(d[a])==0 && a!=b){
                answer = false;
                return answer;
            }
        }
        a++;
    }
    return answer;
}
