#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include<stdlib.h>

using namespace std;

struct Trie {
	bool fin;
	Trie* next[26];
	int cnt;

	Trie() {
		fin = false;
		cnt = 0;
		memset(next, 0, sizeof(next));
	}
	~Trie(){
		for (int i = 0; i < 26; i++) {
			if (next[i]) {
				delete next[i];
			}
		}
	}

	void insert(const char* key) {
		if (*key == '\0') {
			fin = true;
			return;
		}
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL) {
				next[curr] = new Trie();
			}
			cnt++;
			next[curr]->insert(key + 1);
			return;
		}
	}

	int find_str(const char* key) {
		
		if (*key == '?') {
			return cnt;
		}
		else{
			int curr = *key - 'a';
			if (next[curr] == NULL) {
				return 0;
			}
			
			return next[curr]->find_str(key + 1);
		}
	}
};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	for (int i = 0; i < queries.size(); i++) {
		answer.push_back(0);
	}

	Trie* tr[10001];
	Trie* tr_re[10001];
	int cnt[10001] = { 0, };
	memset(tr, 0, sizeof(tr));
	memset(tr_re, 0, sizeof(tr_re));

	for (int i = 0; i < words.size(); i++) {
		string tmp = words[i];
		int size = tmp.length();
		const char* str = tmp.c_str();
		if (!tr[size]) 
			tr[size] = new Trie();
		tr[size]->insert(str);

		reverse(tmp.begin(), tmp.end());
		str = tmp.c_str();
		if (tr_re[size] == NULL)
			tr_re[size] = new Trie();
		tr_re[size]->insert(str);
	
		cnt[size]++;
	}
	
	for (int i = 0; i < queries.size(); i++) {
		int len = queries[i].length();
		if (queries[i][0] == '?' && queries[i][len-1] != '?') {
			// ???o -> reverse
			string tmp = queries[i];
			reverse(tmp.begin(), tmp.end());
			const char* str = tmp.c_str();
			if (tr_re[len] == NULL) {
				answer[i] = 0;
				continue;
			}

			answer[i] = tr_re[len]->find_str(str);
		}
		else if (queries[i][0] != '?' && queries[i][len-1] == '?') {
			//abc??
			string tmp = queries[i];
			const char* str = tmp.c_str();
			if (tr[len] == NULL) {
				answer[i] = 0;
				continue;
			}
			answer[i] = tr[len]->find_str(str);
		}
		else if (queries[i][0] == '?' && queries[i][len - 1] == '?') {
			//??????
			string tmp = queries[i];
			answer[i] = cnt[len];
		}
	}
	

	for (int i = 0; i < 10001; i++) {
		if (tr[i]) {
			delete tr_re[i];
			delete tr[i];
		}
	}
	return answer;
}

int main() {

	vector<int> answer_vec;
	vector<string> words = { "aa","a","frodo", "front", "frost", "frozen", "frame", "kakao","abc" };
	vector<string> queries = { "?", "fro??", "??", "????o", "fr???", "fro???", "pro?","???"};

	answer_vec = solution(words, queries);

	for (int i = 0; i < answer_vec.size(); i++) {
		cout << answer_vec[i] << ", ";
	}
	cout << endl;
	
	return 0;
}
