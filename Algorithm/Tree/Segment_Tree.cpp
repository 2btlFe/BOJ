#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

struct RMQ {
    //배열의 길이
    int n;
    //각 구간의 최소치
    vector<int> rangeMin;
    
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n*4);   //4n정도면 됨
        init(array, 0, n-1, 1);        
    }
    
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right) return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid + 1, right, node*2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    //O(lgn)
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        //겹치지 않는다면, 최솟값을 구하지 못하게 INF 반환
        if(right < nodeLeft || nodeRight < left) return INF;
        //포함된다면, node의 최솟값을 반환 
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        //교집합이 생성됐다면, 
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2 + 1, mid+1, nodeRight));
    }
    
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};    
