#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int left_idx =0;
    // 10 20 30 40 50 -> 3 (50)
    if(people.size()==1)
        return 1;
    for(int i=people.size()-1; i>0; i--){
        if(limit - people[0] >= people[i]){
            left_idx = i;
            break;
        }
        answer++;
    }
    
    for(int i=0; i<people.size(); i++){
        int left = limit - people[i];
        if(i==left_idx){
            answer++;
            break;
        }else if(i>left_idx)
            break;
        for(int j=left_idx; ; j--){
            if(j<i)
                break;
            answer++;
            left_idx--;
            if(left >= people[j]){
                break;
            }
        }
    }
    return answer;
}
