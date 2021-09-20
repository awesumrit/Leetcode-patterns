class Solution {
public:
   
    void addEdge(list<int>* adj, int u, int v) 
    { 
        adj[u].push_back(v); 
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        list<int>* adj;
        adj = new list<int>[numCourses];
        for(int i=0; i<prerequisites.size(); i++)
            addEdge(adj, prerequisites[i][1], prerequisites[i][0]);
        
        int V = numCourses;
        vector<int> in_degree(V, 0);

        for (int u = 0; u < V; u++) {
            for (auto v : adj[u])
                in_degree[v]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (in_degree[i] == 0)
                q.push(i);

        int cnt = 0;
        vector<int> top_order;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            top_order.push_back(u);
            list<int>::iterator itr;
            for (itr = adj[u].begin(); itr != adj[u].end(); itr++)
                if (--in_degree[*itr] == 0)
                    q.push(*itr);

            cnt++;
        }
        
        if(cnt != V)
            return vector<int> ();
        else
            return top_order;
        
    }
};
