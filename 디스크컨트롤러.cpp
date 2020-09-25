#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cstring>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int n = jobs.size();
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i = 0; i < jobs.size(); i++) {
        answer -= jobs[i][0];
    }

    int cur_time = 0, idx = 0;
    sort(jobs.begin(), jobs.end());
    while (true) {
        for (int i = idx; i < jobs.size(); i++) {
            if(jobs[i][0] <= cur_time) {
                pq.push(jobs[i][1]);
                idx++;
            }else {
                break;
            }
        }
        if (pq.empty() == true){
            if (idx == n) {
                break;
            }else{
                cur_time = jobs[idx][0];
                continue;
            }
            
        }
        int work = pq.top();
        cur_time += work;
        answer += cur_time;

        pq.pop();
        
        
    }

    answer = answer / n;
    cout << answer << endl;
    return answer;
}

int main() {
    solution({ {0,3}, {1,9}, {2,6} });
    return 0;
}
