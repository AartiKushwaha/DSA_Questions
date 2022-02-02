//Trie Implementation

struct Node{
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch-'a'] !=NULL);
    }
    Node *getNext(char ch){
        return links[ch-'a'];
    }
    void setNext(char ch, Node* node){
        links[ch- 'a'] = node;	
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    
private: Node* root;
    
public:

    /** Initialize your data structure here. */
    Trie() {
		root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
		for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->setNext(word[i], new Node());
            }
            node = node->getNext(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
		Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};



//Part two

struct Node {
    Node *links[26]; 
    int cntEndWith = 0;
    int cntPrefix = 0; 
    
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }
    Node* get(char ch) {
        return links[ch-'a']; 
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node; 
    }
    void increaseEnd() {
        cntEndWith++;  
    }
    void increasePrefix() {
        cntPrefix++; 
    }
    void deleteEnd() {
        cntEndWith--; 
    }
    void reducePrefix() {
        cntPrefix--; 
    }
    int getEnd() {
        return cntEndWith; 
    }
    int getPrefix() {
        return cntPrefix; 
    }
}; 
class Trie{
private: Node *root; 
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]); 
            node->increasePrefix(); 
        }
        node->increaseEnd(); 
    }
    
    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else {
                return 0; 
            }  
        }
        return node->getEnd(); 
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
            }
            else {
                return 0; 
            }  
        }
        return node->getPrefix(); 
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0;i<word.length();i++) {
            if(node->containsKey(word[i])) {
                node = node->get(word[i]);
                node->reducePrefix(); 
            }
            else {
                return;
            }
        }
        node->deleteEnd(); 
    }
};
