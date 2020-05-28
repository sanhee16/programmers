#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr_back;
vector<vector<int>> back_ground;
int n,m;
int back_ground_len;

void p_vec(vector<vector<int>> v) {
    cout << "------" << endl;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------" << endl;
    return;
}

vector<vector<int>> turn(vector<vector<int>> v) {
    vector<vector<int>> final_v;
    vector<int> vec;
    for (int j = 0; j < v.size(); j++) {
        vec.push_back(0);
    }
    for (int j = 0; j < v.size(); j++) {
        final_v.push_back(vec); // make new vec2D
    }  
    //v is not change
    for (int a = 0; a < v.size(); a++) {
        for (int i = 0; i < v.size(); i++) {
            vec[i] = v[i][a];
        } 
        for (int j = 0; j < v.size(); j++) {
            final_v[a][v.size() - j - 1] = vec[j];
        }  
    } 
    return final_v;
}

vector<vector<int>> add_background_and_key(vector<vector<int>> add_vec) {
    vector<vector<int>> tmp;
    for (int j = 0; j < back_ground_len; j++) {
        tmp.push_back(arr_back); 
    }

    for (int i = 0; i < back_ground_len - 2; i++) {
        for (int j = 0; j < back_ground_len - 2; j++) {
            tmp[i][j] = back_ground[i][j];
        }
    }

    for (int i = 0; i < back_ground_len; i++) {
        for (int j = 0; j < back_ground_len; j++) {
            tmp[i][j] += add_vec[i][j];
        }
    }
    return tmp;
}

vector<vector<int>> move(vector<vector<int>> key,int x, int y) {
    vector<vector<int>> tmp;
    for (int j = 0; j < back_ground_len; j++) {
        tmp.push_back(arr_back); // make new vec2D
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            tmp[i+x][j+y] = key[i][j];
        }
    }
    return tmp;
}

bool test(vector<vector<int>> tmp){
    for (int i = m - 1; i < n + m - 1; i++) {
        for (int j = m - 1; j < n + m - 1; j++) {
            if (tmp[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool mod_key(vector<vector<int>> key){
    bool res = false;
    vector<vector<int>> tmp;
    for (int j = 0; j < back_ground_len; j++) {
        tmp.push_back(arr_back);
    }
    for(int a=0; a<4; a++){
        key = turn(key);
        for (int i = 0; i < back_ground_len - m +1; i++) {
            for (int j = 0; j < back_ground_len - m +1; j++) {
                //move
                tmp = move(key, i, j);
                //add
                tmp = add_background_and_key(tmp);
                //test
                res = test(tmp); 
                if (res == true)
                    return true;
            }
        }
    }
    return false;
    
}
void make_background(vector<vector<int>> lock) {
    back_ground_len = n + (m - 1) * 2;

    for (int i = 0; i < back_ground_len; i++) {
        arr_back.push_back(0);
    }
    for (int j = 0; j < back_ground_len; j++) {
        back_ground.push_back(arr_back); // make new vec2D
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            back_ground[i+m-1][j+m-1] = lock[i][j];
        }
    } 
    return ;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    n = lock.size();
    m = key.size();
    int nk=0, nl=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lock[i][j] == 0)
                nl++;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (key[i][j] == 1)
                nk++;
        }
    }
    if (nk < nl) {
        answer = false;
        return answer;
    }
        

    make_background(lock);

    answer = mod_key(key);
    return answer;
}

int main(){
    bool ans;
    //key , lock
    ans = solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 0},{1, 1, 1},{1, 1, 1} });
    if(ans==0)
        cout << "answer : false "  << endl;
    else
        cout << "answer : true " << endl;
    return 0;
}
