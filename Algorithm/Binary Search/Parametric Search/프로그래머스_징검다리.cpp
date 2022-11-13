/*
Algorithm: Parametric_Search
TC: Nlog(1e9)
SC: N
Explaination:
Parametric Seacrh의 특징은
1) 최소들의 최대를 찾는다.
2) x < y 일 때, f(x) < f(y)를 만족하는 경우를 찾는 문제에서 유용하다 
3) 마지막 답은 ret로 따로 뽑아내서 찾는다 
4) 다음 양식을 고정한다

while(left <= right)


  if( > C) {
    right = mid - 1
  else {
    left = mid + 1
    ret = mid


*/

#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    
    vector<int> dist;
    rocks.push_back(distance);
    dist.push_back(rocks[0]);
    for(int i = 1; i < rocks.size(); i++) {
        dist.push_back(rocks[i] - rocks[i-1]);
    }
    
    int left = 1;
    int right = distance;
    while(left <= right) {
        int mid = (left + right) / 2;
        
        int sum = 0;
        int removed = 0;
        for(int d : dist) {
            sum += d;
            if(sum < mid) removed++;
            else sum = 0;
        }
        
        if(removed > n) {
            right = mid - 1;
        } else {
            answer = mid;
            left = mid + 1;
        }
    }
    return answer;
}
