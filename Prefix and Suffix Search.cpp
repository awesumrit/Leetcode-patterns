class WordFilter {
public:
    
    struct Trie{
        Trie* child[27]; //ascii of '{' will be used
        bool isWord;
        int ind;
        
        Trie(){
            for(int i=0; i<27; i++){
                child[i] = NULL;
            }
                isWord = false;
                ind = -1;
        }  
    };
    Trie* root = new Trie();
    
    void addWord(string temp, int ind){
        Trie* curr = root;
        for(int i=0; i<temp.size(); i++){
            if(!curr->child[temp[i]-'a']){
                curr->child[temp[i]-'a'] = new Trie();
            }
            curr = curr->child[temp[i]-'a'];
        }
        curr->isWord = true;
        curr->ind = ind;
    }
    
    int search(string s){
        Trie* curr = root;
        for(int i =0; i<s.size(); i++){
            if(!curr->child[s[i]-'a']){
                return -1;
            }
            curr = curr->child[s[i]-'a'];
        }
        return curr->ind;
    }
    
    WordFilter(vector<string>& words) {
        for(int ind =0; ind<words.size(); ind++){
            string key = words[ind];
            for(int i=0; i<key.size(); i++){
                for(int j=0; j<key.size(); j++){
                    string temp = key.substr(0,i+1) + '{' + key.substr(j);
                    addWord(temp, ind);
                }  
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + '{' + suffix;
        return search(s);
    }
};
