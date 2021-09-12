class Solution {
public:
    
// // Naive implementation of find
// int find(int parent[], int i)
// {
//     if (parent[i] == -1)
//         return i;
//     return find(parent, parent[i]);
// }
  
// // Naive implementation of union()
// void Union(int parent[], int x, int y)
// {
//     int xset = find(parent, x);
//     int yset = find(parent, y);
//     parent[xset] = yset;
// }

    struct subset {
        int parent;
        int rank;
    };
    
    // A utility function to find set of an element i
    // (uses path compression technique)
    int find(vector<subset> &subsets, int i)
    {
        // find root and make root as parent of i (path
        // compression)
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);

        return subsets[i].parent;
    }

    // A function that does union of two sets of x and y
    // (uses union by rank)
    void Union(vector<subset> &subsets, int xroot, int yroot)
    {

        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;

        // If ranks are same, then make one as root and
        // increment its rank by one
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<subset> subsets(n+1);
        for (int v = 0; v < n; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        for (int e = 0; e < n; ++e) {
            int x = find(subsets, edges[e][0]);
            int y = find(subsets, edges[e][1]);

            if (x == y)
                return {edges[e][0], edges[e][1]};

            Union(subsets, x, y);
        }   
        
        return {};
    }
};
