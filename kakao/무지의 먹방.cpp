#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;
bool cmp1(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    }
    else if (a.second > b.second) {
        return false;
    }
    else if (a.second == b.second) {
        if (a.first < b.first) {
            return true;
        }
        else if (a.first >= b.first) {
            return false;
        }
    }
    return true;
}
bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    }
    else if (a.first > b.first) {
        return false;
    }
    else if (a.first == b.first) {
        return false;
    }

    return true;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    long long left_time = k;
    long long left_food = n;
    long long sum = 0;
    
    vector<pair<int, int> > food;
    for (int i = 0; i < n; i++) {
        sum += food_times[i];
        food.push_back({ i + 1, food_times[i] });
    }

    if (sum <= k) {
        answer = -1;
        cout << answer;
        return answer;
    }
    int cnt = 0;
    sort(food.begin(), food.end(), cmp1);
    for (int i = 0; i < n; ) { 
        int tmp = food[i].second;
        if (k > ((tmp-cnt) * left_food)){
            k -= ((tmp - cnt) * left_food);
            cnt = tmp;
            for (int j = i; j < n; j++) {
                if (food[j].second == tmp) {
                    food[j].first = 1e9;
                    left_food--;
                    i++;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }

    sort(food.begin(), food.end(), cmp2);
    if (left_food > 0) {
        int idx = k % left_food;
        answer = food[idx].first;
    }else {

    }
    
    cout << answer;
    return answer;
}

int main() {

    solution({ 1, 3, 1, 2 }, 3); //4
    solution({ 1, 3, 1, 2 }, 4); //2
    solution({ 1, 3, 1, 2 }, 5); //4
    solution({ 1, 3, 1, 2 }, 6); //2
    solution({ 1, 3, 1, 2 }, 7); //4
    solution({ 1, 3, 1, 2 }, 8); //-1

    return 0;
}
