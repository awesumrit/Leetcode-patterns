
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string, int> m;
        int cnt = 0, n = values.size();
        for(int i=0; i<n; i++){
            if(m.find(equations[i][0]) == m.end())
                m[equations[i][0]] = cnt++;
            if(m.find(equations[i][1]) == m.end())
                m[equations[i][1]] = cnt++;
        }
        vector<vector<pair<int,double>>> adj(cnt);
        for(int i=0; i<n; i++){
            adj[m[equations[i][0]]].push_back({m[equations[i][1]], values[i]});
            adj[m[equations[i][1]]].push_back({m[equations[i][0]], 1.0/values[i]});
        }
        
        vector<double> ans(queries.size(), -1.0);
        for(int i=0; i<queries.size(); i++){
            if(m.find(queries[i][0]) == m.end() || m.find(queries[i][1]) == m.end())
                continue;
            int u = m[queries[i][0]], v = m[queries[i][1]];
            double val = 1.0;
            queue<pair<int,double>> q;
            q.push({u,val});
            int flag = 0;
            vector<bool> vis(cnt, false);
            while(!q.empty() && flag==0){
                pair<int,double> pq = q.front();
                int u = pq.first;
                vis[u] = true;
                double curr_val = pq.second;
                q.pop();
                for(auto node: adj[u]){
                    if(node.first == v){
                        flag = 1;
                        val = curr_val*node.second;
                        break;
                    }
                    if(vis[node.first])
                        continue;
                    q.push({node.first, curr_val*node.second});
                }
            }
            if(flag)
                ans[i] = val;         
        }
        
        return ans;
    }
};
