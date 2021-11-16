#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool isSubseq(string s, string t){
	int n = s.size(), m = t.size();
	int j=0;
	for(int i=0; i<n && j<m; i++){
		if(s[i] == t[j])
			j++;
	}
	return j == m;
}

int main() {
	string s,t;	cin>>s>>t;
	int minLen = INT_MAX;;
	int n = s.size(), m = t.size();

	string ans="";
	vector<int> ind_beg, ind_end;
	for(int i=0; i<n; i++){
		if(s[i] == t[0]){
			ind_beg.push_back(i);
		}
		if(s[i] == t[m-1]){
			ind_end.push_back(i);
		}
	}
	for(int i=0; i<ind_beg.size(); i++){
		for(int j=0; j<ind_end.size(); j++){
			if(ind_end[j] < ind_beg[i])
				continue;
			string str = s.substr(ind_beg[i], ind_end[j]-ind_beg[i]+1);
			if(isSubseq(str, t)){
				if(ind_end[j]-ind_beg[i]+1 < minLen){
					minLen = ind_end[j]-ind_beg[i]+1;
					ans = str;
				}
			}
		}
	}
	// for(int len=m; len<=n; len++){
	// 	for(int i=0; i<n-len+1; i++){
	// 		ans = s.substr(i, len);
	// 		if(isSubseq(ans, t)){
	// 			minLen = len;
	// 			break;
	// 		}
	// 	}
	// 	if(minLen != -1)
	// 		break;
	// }
	cout<<ans;


}
