class Solution {
public:
    
    void bfs(int src,int n,vector<vector<int>>& isConnected,vector<bool> &vis){
        vis[src] = 1;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int nbr=0;nbr<n;nbr++){
                if(isConnected[temp][nbr] and !vis[nbr]){
                    vis[nbr] = 1;
                    q.push(nbr);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,n,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};