#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cnt = 0;
    int n = truck_weights.size();
    int idx = 0;
    int ontruck = 0;
    queue<pair<int,int> > onroad;
    queue<int> done;
    int curtime = 0;
    while(true){
        curtime++;
        if(curtime == onroad.front().second + bridge_length){
            ontruck -= onroad.front().first;
            done.push(onroad.front().first);
            onroad.pop();
        }
        if(done.size()==n)
            break;
        if(ontruck + truck_weights[idx]<=weight){
            onroad.push({truck_weights[idx],curtime});
            ontruck += truck_weights[idx];
            idx++;
        }
    }
    answer = curtime;
    return answer;
}
