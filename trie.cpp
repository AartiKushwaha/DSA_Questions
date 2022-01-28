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
