#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string,int> d;
    unordered_map<string,int> d_cnt;
    int cnt=0;
    for(int a=0;a<clothes.size();a++){
        cnt=0;
        for(auto& i:clothes[a]){
            cnt++;
            if(cnt==2){
                d[i]++;
            }
        }
    }
    vector<int> v;
    
    for(int a=0;a<clothes.size();a++){
        cnt=0;
        for(auto& i:clothes[a]){
            cnt++;
            if(cnt==2 && d_cnt[i]==0){
                d_cnt[i]=1;
                v.push_back(d[i]+1);
            }
        }
    }
    int res=1;
    for(int a=0;a<d.size();a++){
        res = v[a]*res;
        cout << v[a] << endl;
    }
    answer = res - 1;
    
    return answer;
}
