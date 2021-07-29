class Trienode{
public:
	bool end;
	Trienode* child[26];
	Trienode(){
		end = false;
		for(int i=0;i<26;i++) child[i] = NULL;
	}
};

class Solution {
public:

	Trienode *root = new Trienode();
	vector<string> res;

	void insert(string &word) {
		Trienode* node = root;
		for(char c : word){
			if(!node -> child[c - 'a']){
				node -> child[c - 'a'] = new Trienode();
			}
			node = node -> child[c - 'a'];
		}
		node -> end = true;
	}

	void dfs(int i, int j, vector<vector<char>> &board, string &word, Trienode *node){

		if(!(i>=0&&j>=0&&i<board.size()&&j<board[0].size()&&board[i][j]!=' ')) return;

		char c = board[i][j];
		if(!node->child[c-'a']) return;

		node = node->child[c-'a'];
		word.push_back(c);
		if(node->end){
			res.push_back(word), node->end = false;
		}

		board[i][j] = ' ';
		dfs(i+1, j, board, word, node);
		dfs(i-1, j, board, word, node);
		dfs(i, j+1, board, word, node);
		dfs(i, j-1, board, word, node);
		board[i][j] = c;

		word.pop_back();

	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words){

		for(string &w: words) insert(w);
		string s;
		for(int i=0;i<board.size();i++)
			for(int j=0;j<board[0].size();j++)
				dfs(i, j, board, s, root);

		return res;

	}

};
