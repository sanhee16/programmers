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
vector<int> dx = { 1,-1,0,0 };
vector<int> dy = { 0,0,1,-1 };

class Car {
public :
    int x, y, cost, dir;
    Car(){}
    Car(int a, int b, int c, int d) {
        x = a;
        y = b;
        cost = c;
        dir = d;
    }
};
int solution(vector<vector<int>> board) {
    int answer = 1e9;
    vector<int > t;
    vector<vector<int>> vis;
    int n = board.size();
    for (int i = 0; i < board.size(); i++)
        t.push_back(0);
    for (int i = 0; i < board.size(); i++)
        vis.push_back(t);
    board[0][0] = 1;
    queue<Car> q;
    Car tmp(0, 0, 0, 10);
    q.push(tmp);
    while (!q.empty()) {
        Car c = q.front();
        q.pop();
        if (c.x == n - 1 && c.y == n - 1) {
            if (answer > c.cost)
                answer = c.cost;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            int ncost = c.cost;
            int ndir = c.dir;
            if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size())
                continue;
            if (board[nx][ny] == 1)
                continue;
            if (ndir == i || ndir == 10) {
                ncost += 100;
            }else {
                ncost += 600;
            }
            if (vis[nx][ny]==0 || vis[nx][ny] >= ncost) {
                vis[nx][ny] = ncost;
                Car tmpQ(nx, ny, ncost, i);
                q.push(tmpQ);
            }
        }
    }
    cout << answer << endl;

    return answer;
}

int main() {
    solution({ {0, 0, 1, 0},{0, 0, 0, 0},{0,1,0,1},{1,0,0,0} });
    return 0;
}
