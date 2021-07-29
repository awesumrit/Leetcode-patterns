class Solution {
public:
	static bool comp(vector<int>&a, vector<int>&b) {return (a[1] < b[1]);}

	int scheduleCourse(vector<vector<int>>& c) 
	{
		sort(c.begin(),c.end(), comp);
		int tot = 0, n = 0;
		priority_queue<int> pq;
		for(int i = 0; i < c.size(); ++i)
		{
			if(c[i][0] > c[i][1]) continue;
			if(tot + c[i][0] <= c[i][1]) { ++n; pq.push(c[i][0]); tot += c[i][0]; }
			else {
                if(pq.top() > c[i][0]) { tot -= pq.top(); pq.pop(); pq.push(c[i][0]); tot += c[i][0]; }
            }
		}
		return n;
	}
};
