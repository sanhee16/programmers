#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int answer = 0;

void dfs(vector<int> v, vector<int> numbers, int start, int res, int target){
    if(start == numbers.size()){
        if(res==target){
            answer++;
        }
        return ;
    }
        
    for(int i=start; i<numbers.size();i++){
        if(v[i]==0){
            v[i]=1;
            dfs(v,numbers,i+1,res+numbers[i],target);
            dfs(v,numbers,i+1,res-numbers[i],target);
            return ;
        }
    }
    return ;
}
int solution(vector<int> numbers, int target) {
   
    vector<int> v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(0);
    }
    dfs(v,numbers,0,0,target);
    
    
    return answer;
}
