#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> arr;

bool possible(int x, int y, int diff, int con, int n) {
    
    // 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
    
    if (diff == 1) {
        //보
        // 한쪽 끝 부분이 기둥 위에 있거나
        if (y < n && x < n && arr[x + 1][y + 1] >= 2) {
            return true;
        }
        if (x < n && arr[x + 1][y] >= 2) {
            return true;
        }
        // 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야
        if (y > 0 && y < n) {
            if (arr[x][y - 1] >= 1 && arr[x][y + 1] >= 1) {
                if (arr[x][y - 1] == 2 || arr[x][y + 1] == 2) {
                    return false;
                }
                else {
                    return true;
                }
            }
        }
        return false;
    }
    else if (diff == 2) {
        //기둥 : 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
        //보의 한쪽 끝 부분 위에 있거나
        if (arr[x][y] == 1 || arr[x][y] == 3) {
            return true;
        }
        if (y > 0 && (arr[x][y-1] == 1 || arr[x][y-1] == 3)) {
            return true;
        }

        // 바닥 위에 있거나
        if (x == n)
            return true;

        //다른 기둥 위에 있어야
        if (x < n && arr[x+1][y] >= 2)
            return true;
        return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    vector<int> con_x = {0,1,-1,0,0,1,1,-1,-1};
    vector<int> con_y = {0,0,0,1,-1,1,-1,1,-1};
    vector<int> tmp;
    for (int i = 0; i < n+1; i++)
        tmp.push_back(0);
    for (int i = 0; i < n+1; i++)
        arr.push_back(tmp);
    /*
    기둥 : 0 -> 2
    보 : 1
    */
    vector<int> b;
    int x = 0, y = 0, diff = 0, con = 0;
    int tmp_x=0, tmp_y=0;
    for (int i = 0; i < build_frame.size(); i++) {
        b = build_frame[i];
        tmp_x = b[0]; tmp_y = b[1]; diff = b[2]; con = b[3];
        if (diff == 0)
            diff = 2;
        x = n - tmp_y;
        y = tmp_x;
        if (con == 1) {
            // build
            bool ret = possible(x, y, diff, con, n);
            if (ret == true) {
                arr[x][y] += diff;
            }
        }
        else if (con == 0) {
            // delete
            arr[x][y] -= diff;
            for (int j = 0; j < 9; j++) {
                int t_x = con_x[j] + x;
                int t_y = con_y[j] + y;
                if (t_x > -1 && t_y > -1 && t_x < n + 1 && t_y < n + 1) {
                    if (arr[t_x][t_y] == 1 || arr[t_x][t_y] == 2) {
                        int save = arr[t_x][t_y];
                        arr[t_x][t_y] = 0;
                        bool ret = possible(t_x, t_y, save, 1, n);
                        arr[t_x][t_y] = save;

                        if (ret == false) {
                            arr[x][y] += diff;
                            break;
                        }
                    }
                    else if (arr[t_x][t_y] == 3){
                        arr[t_x][t_y] = 2;
                        bool ret1 = possible(t_x, t_y, 1, 1, n);

                        arr[t_x][t_y] = 1;
                        bool ret2 = possible(t_x, t_y, 2, 1, n);
                        arr[t_x][t_y] = 3;
                        if (ret1 == false || ret2 == false) {
                            arr[x][y] += diff;
                            break;
                        }
                    }
                }
            }
        }
        b.clear();
    }
    /*
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int j = 0; j < n + 1; j++) {
        for (int i = n; i > -1 ; i--) {
            x = 0, y = 0;
            x = j;
            y = n - i;
            
            if (arr[i][j] == 0) {

            }else if (arr[i][j] == 1) {
                answer.push_back({ x,y,1});
            }else if (arr[i][j] == 2) {
                answer.push_back({ x,y,0});

            }else if (arr[i][j] == 3) {
                answer.push_back({ x,y,0 });
                answer.push_back({ x,y,1 });
            }
        }
    }

    return answer;
}
