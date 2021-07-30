class Trie {
public:

    struct TrieNode{
        TrieNode* child[26]; //ascii of '{' will be used
        bool isEnd;
        
        TrieNode(){
            for(int i=0; i<26; i++){
                child[i] = NULL;
            }
                isEnd = false;
        }  
    };
    TrieNode* root = new TrieNode();
    
    Trie() {
        
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(!tmp->child[word[i]-'a'])
                tmp->child[word[i]-'a'] = new TrieNode();
            tmp = tmp->child[word[i]-'a'];
        }
        tmp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* tmp = root;
        for(int i=0; i<word.size(); i++){
            if(!tmp->child[word[i]-'a'])
                return false;
            tmp = tmp->child[word[i]-'a'];
        }
        return tmp->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* tmp = root;
        for(int i=0; i<prefix.size(); i++){
            if(!tmp->child[prefix[i]-'a'])
                return false;
            tmp = tmp->child[prefix[i]-'a'];
        }
        return true;       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
