# include<iostream>
# include<vector>
# include<utility>
# include<queue>
using namespace std;

void calculatePower(vector<vector<int>> &adj,vector<int> &nodeValue) {
    queue<pair<int,int>> q;
    for(int i=0;i<nodeValue.size();++i) {
        if(nodeValue[i]==16) {
            q.push(make_pair(i,nodeValue[i]));
        }
    }

    while(!q.empty()) {
        int u=q.front().first;
        int uPower=q.front().second;
        q.pop();
        for(int v:adj[u]) {
            if(nodeValue[v]!=16 && nodeValue[v]<(uPower-1)) {
                nodeValue[v]=uPower-1;
                q.push(make_pair(v,uPower-1));
            }
        }
    }

    return ;

}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {

    int V=18;
    vector<vector<int>> adj(V);
    vector<int> nodeValue(V,0);

    nodeValue[0]=16;
    nodeValue[4]=16;
    nodeValue[6]=16;
    nodeValue[7]=16;
    nodeValue[11]=16;
    nodeValue[13]=16;
    nodeValue[16]=16;

    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,4,5);
    addEdge(adj,4,7);
    addEdge(adj,5,6);
    addEdge(adj,7,8);
    addEdge(adj,8,9);
    addEdge(adj,9,10);
    addEdge(adj,10,11);
    addEdge(adj,10,12);
    addEdge(adj,12,13);
    addEdge(adj,12,14);
    addEdge(adj,14,15);
    addEdge(adj,15,16);
    addEdge(adj,14,17);

    calculatePower(adj,nodeValue);

    for(int i=0;i<nodeValue.size();++i) {
        cout<<i<<" -> "<<nodeValue[i]<<'\n';
    }

    return 0;

}