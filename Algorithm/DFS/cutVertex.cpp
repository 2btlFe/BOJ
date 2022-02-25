const int maxN = 100001;
bool isCutVertex[maxN];
vector<int> v[maxN];
int discovered[maxN];
int counter;

int findCutVertex(int here, bool isRoot) {
    discovered[here] = ++counter;
    int ret = discovered[here];
    
  //fine children
    int children = 0;
    for(int there : v[here]) {
        if(discovered[there] == -1) {
            children++;
            int subtree = findCutVertex(there, 0); 
            if(!isRoot && subtree >= discovered[here]) isCutVertex[here] = true;
            ret = min(ret, subtree);
        }
        else ret = min(ret, discovered[there]);
    }
    
    //in case, root
    if(isRoot) isCutVertex[here] = (children >= 2); 
    return ret;
}
