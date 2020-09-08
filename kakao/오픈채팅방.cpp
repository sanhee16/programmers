#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string, string> > q;
    map<string,string> m;
    for (int i = 0; i < record.size(); i++) {
        string tmp = "",command, uid, name;
        int idx1 = 0, idx2 = 0, j = 0;
        string str = record[i];
        idx2 = str.find(" ", idx1);
        command = str.substr(idx1, idx2 - idx1);
        idx1 = idx2+1;
        idx2 = str.find(" ", idx1);
        uid = str.substr(idx1, idx2 - idx1);
        if (command.compare("Leave") == 0) {
            q.push({ command , uid});
            continue;
        }
        idx1 = idx2+1;
        idx2 = str.find(" ", idx1);
        name = str.substr(idx1);
        if(command.compare("Change") != 0)
            q.push({ command , uid });
        m[uid] = name;

    }
    while (true) {
        if (q.empty() == true)
            break;
        string command = q.front().first, uid = q.front().second, str = "";
        string name = m[uid];
        if (command.compare("Enter") == 0) {
            str = name + "님이 들어왔습니다.";
            answer.push_back(str);
        }else if (command.compare("Leave") == 0) {
            str = name + "님이 나갔습니다.";
            answer.push_back(str);
        }
        q.pop();
    }


    return answer;
}
int main() {
    solution({  "Enter uid1234 Muzi", 
                "Enter uid4567 Prodo",
                "Leave uid1234",
                "Enter uid1234 Prodo",
                "Change uid4567 Ryan" });

    return 0;
}
