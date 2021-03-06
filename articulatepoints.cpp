class Solution {
public:
    int id=0;
    void dfs(int at, int parent, vector<int>& bridge,vector<bool>& visited,vector<int>& ids,vector<int>& low,vector<vector<int> >& adj){
        visited[at]=true;
        low[at]=ids[at]=id++;
        for(int to: adj[at]){
            if(to==parent)  continue;
            if(!visited[to]){
                dfs(to,at,bridge,visited,ids,low,adj);
                low[at]=min(low[at],low[to]);           //if not visited then traverse all paths and find what is the min lowkey value current and to the pointing edge
                if(ids[at]<low[to]){
                    bridge.push_back(at);
                    bridge.push_back(to);
                }
                    
            }
            else    low[at]=min(low[at],ids[to]);       //if visited then update 
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& A) {//nodes, edges
        vector<vector<int> > adj(n,vector<int>());
        for(vector<int> i: A){
            adj[i[0]].push_back(i[1]);  //list matrix
            adj[i[1]].push_back(i[0]);
        }
        vector<int> bridge;
        vector<bool> visited(n,false);
        vector<int> ids(n,0);
        vector<int> low(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i])                
                dfs(i,-1,bridge,visited,ids,low,adj);
        }
        adj.clear();
        for(int i=0;i<bridge.size();i+=2){
            vector<int> t({bridge[i],bridge[i+1]});
            adj.push_back(t);
        }cout<<id<<endl;
        return adj;
    }
}