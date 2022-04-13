//boj7682 Tic Tac Toe.cpp
//Algorithm: implementation
//Time Complexity: O(n)
//Explaination:
//그냥 쉬운 구현 문제

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define endl "\n"
using namespace std;

bool check(string s, char c) {
	bool ret = false;
	
	//가로선   
	for(int i = 0; i < 3; i++) {
		ret |= (s[3*i] == c) && (s[3*i] == s[3*i+1]) && (s[3*i+1] == s[3*i+2]);
	}
	
	//세로선 
	for(int i = 0; i < 3; i++) {
		ret |= (s[i] == c) && (s[i] == s[i+3]) && (s[i+3] == s[i+6]);
	}
	
	//대각선 
	ret |= (s[0] == c) && (s[0] == s[4]) && (s[4] == s[8]); 
	ret |= (s[2] == c) && (s[2] == s[4]) && (s[4] == s[6]);
	
	return ret;	
}

int main() {
	while(1) {
		string s; cin >> s;
		if(s == "end") break;
			
		//1) x와 O의 개수 확인 
		
		int numX = count(all(s), 'X');
		int numO = count(all(s), 'O'); 
		
		//2) 상태 확인  
		bool state;
		if(numX - numO == 1) {
			state = ((numX == 5) && !check(s, 'X') && !check(s, 'O')) || ((check(s, 'X') && !check(s,'O'))); //O의 패배 
		} else if(numX - numO == 0) {
			state = !check(s, 'X') && check(s, 'O'); //~x의 승리 && o의 승리 
		} else {
			state = false;
		} 
			
		if(state) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
}
