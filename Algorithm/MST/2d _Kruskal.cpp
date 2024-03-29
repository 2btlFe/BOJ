#include <bits/stdc++.h>

using namespace std;
int d4i[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isSamePair(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first == b.first && a.second == b.second;
}

bool isSmallPair(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first == b.first ? (a.second < b.second) : (a.first < b.first);
}

pair<int,int> getParent(pair<int, int> parent[][301], pair<int, int> x) {
    if(isSamePair(x, parent[x.first][x.second])) return x;
    else return parent[x.first][x.second] = getParent(parent, parent[x.first][x.second]);
}

void unionParent(pair<int, int> parent[][301], pair<int, int> x, pair<int, int> y) {
    x = getParent(parent, x);
    y = getParent(parent, y);
    if(isSmallPair(x, y)) {
        parent[y.first][y.second] = x;
    } else {
        parent[x.first][x.second] = y;
    }
}

class Edge {
public:
	pair<int, int> from, to;
    int cost;
	Edge(const pair<int,int>& _from, const pair<int,int>& _to, const int _cost) {
		this -> from = _from;
        this -> to = _to;
        this -> cost = _cost;
	}
	bool operator < (const Edge &edge) const{
		return this-> cost > edge.cost;
	}
};


int solution(vector<vector<int>> land, int height) {
    
    int R = land.size();
    int C = land[0].size();
    
    priority_queue<Edge> pq;
    pair<int, int> parent[301][301];
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            for(int k = 0; k < 4; k++) {
                int ni = i + d4i[k][0];
                int nj = j + d4i[k][1];
                if(ni < 0 || ni >= R || nj < 0 || nj >= C) continue;
                pq.push(Edge({i, j}, {ni, nj}, abs(land[i][j] - land[ni][nj])));
                parent[i][j] = {i, j};
            }
        }
    }
    
    int sum = 0;
    while(!pq.empty()) {
        Edge e = pq.top();
        pq.pop();
        if(!isSamePair(getParent(parent, e.from), getParent(parent, e.to))) {
            //cout << e.from.first << " " << e.from.second << " -> " << e.to.first << " " << e.to.second <<  " : " << e.cost << endl;
            unionParent(parent, e.from, e.to);
            if(e.cost > height) {
                sum += e.cost;
            }
        }
    }
    
    return sum;
}
