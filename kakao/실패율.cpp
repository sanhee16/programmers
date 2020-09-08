#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
bool cmp(pair< double, int> a, pair< double, int> b) {
    if (a.first > b.first)
        return true;
    else if (a.first == b.first) {
        if (a.second > b.second)
            return false;
        else if (a.second <= b.second)
            return true;
    }
    else if (a.first < b.first)
        return false;
    return true;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> reach;
    vector<double> not_clear;
    int fin = 0;
    vector<pair< double , int> > rate;
    for (int i = 0; i <= N; i++) {
        reach.push_back(0);
        not_clear.push_back(0); 
    }
    for (int i = 1; i <= N; i++) {
        rate.push_back({ 0.0, i});
    }
    for (int i = 0; i < stages.size(); i++) {
        if (stages[i] == N + 1) {
            fin++;
            continue;
        }
        reach[stages[i]]++;
    }
    int add = fin;
    for (int i = N; i > 0; i--) {
        add += reach[i];
        not_clear[i] = add;
    }

    
    for (int i = 0; i < N; i++) {
        if (not_clear[i + 1]==0) {
            continue;
        }
        else {
            rate[i] = { reach[i + 1] / not_clear[i + 1] , i + 1 };
        }

    }
    sort(rate.begin(), rate.end(), cmp);


    for (int i = 0; i < N; i++)
        answer.push_back(rate[i].second);
    for (int i = 0; i < N; i++)
        cout << rate[i].second << "(" << rate[i].first << ")" << " ";

    cout << endl;
    return answer;
}
int main() {
    solution(5, { 2, 1, 2, 1, 2, 4, 3, 3 });
    solution(4, { 4,4,4,4,4 });

    return 0;
}
