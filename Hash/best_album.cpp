#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    unordered_map<string,int> gen;
    // genres order
    
    for(int i=0;i<size; i++){
        gen[genres[i]] += plays[i];
    }

    
    for(int a=0;a<gen.size();a++){
        int big_sing = 0; 
        string big_gen = "";
        for(auto &i : gen){
            if(big_sing < i.second){
                big_gen = i.first;
                big_sing = i.second;
            }
        }
        
        gen[big_gen]=0;
        // plays order
        vector<int> t = {0,0,0};
        vector<vector<int> > order_sing;
        order_sing.push_back(t);
        order_sing.push_back(t);

        // [700,100,500,700,750]
        //[][1] = plays , [][2] = index
        for(int i=0;i<size; i++){
            if(genres[i].compare(big_gen)==0){
                if(order_sing[0][1] < plays[i]){
                    order_sing[1][1] = order_sing[0][1];
                    order_sing[1][2] = order_sing[0][2];
                    
                    order_sing[0][1] = plays[i];
                    order_sing[0][2] = i;
                }else if(order_sing[1][1] < plays[i] && plays[i] <= order_sing[0][1]){
                    order_sing[1][1] = plays[i];
                    order_sing[1][2] = i;
                }else{

                }
            }
        }

        answer.push_back(order_sing[0][2]);
        if(order_sing[1][1]!=0)
            answer.push_back( order_sing[1][2]);

    }
    // if plays in genres is same 
    
    
    return answer;
}
