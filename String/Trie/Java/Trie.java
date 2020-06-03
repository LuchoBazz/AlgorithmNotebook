// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com
// Tested: https://leetcode.com/problems/implement-trie-prefix-tree/

import java.util.List;
import java.util.ArrayList;

class Trie {

    public TrieNode root;
    
    public Trie() {
        this.root = new TrieNode();
    }
    
    public void insert(String word) {
        if(word.length() == 0) return;
        
        char curr;
        int index = 0;
        
        TrieNode tmp = root;
        
        for(int i = 0; i < word.length(); ++i) {
            curr = word.charAt(i);
            index = curr - 'a';
            
            if(tmp.children[index] == null) {
                tmp.children[index] = new TrieNode();   
            }
            tmp = tmp.children[index];
        }
        tmp.isEndWord = true;
        
    }
    
    public boolean search(String word) {
        if(word.length() == 0) return false;
        
        char curr;
        int index = 0;
        
        TrieNode tmp = root;
        
        for(int i = 0; i < word.length(); ++i) {
            curr = word.charAt(i);
            index = curr - 'a';
            
            if(tmp.children[index] == null) {
                return false;  
            }
            tmp = tmp.children[index];
        }
        return tmp!=null?tmp.isEndWord:false;
    }
    
    public boolean startsWith(String prefix) {
        if(prefix.length() == 0) return false;
        
        char curr;
        int index = 0;
        
        TrieNode tmp = root;
        
        for(int i = 0; i < prefix.length(); ++i) {
            curr = prefix.charAt(i);
            index = curr - 'a';
            
            if(tmp.children[index] == null) {
                return false;  
            }
            tmp = tmp.children[index];
        }
        return true;
    }

    public List<String> getWordsWithPrefix(String prefix) {
        List<String> words = new ArrayList<>();
        
        if(prefix.length() == 0) return words;
        
        char curr;
        int index = 0;
        TrieNode tmp = this.root;
        
        for(int i = 0; i < prefix.length(); ++i) {
            curr = prefix.charAt(i);
            index = curr - 'a';
            
            if(tmp.children[index] == null) {
                return words;
            }
            tmp = tmp.children[index];
        }
        
        dfs(tmp, prefix, words);
        return words;
    }

    public List<String> getWords() {
        List<String> words = new ArrayList<>();
        
        dfs(this.root, "", words);
        return words;
    }
    
    public void dfs(TrieNode node, String characters, List<String> words) {
        if(isEmpty(node)) return;
        
        if(node.isEndWord) {
            words.add(characters);
        }
        
        String newWord = "";
        
        for(int i = 0; i < node.children.length; ++i) {
            if(!isEmpty(node.children[i])) {
                newWord = characters + (char)(i+'a')+"";
                dfs(node.children[i], newWord, words);
            }
        }
    }
    
    private boolean isEmpty(TrieNode node) {
        return node == null;
    }

    static class TrieNode {
        private final int ALPHABET = 26;
        public TrieNode[] children;
        public boolean isEndWord;
        
        TrieNode() {
            this.children = new TrieNode[ALPHABET];
            this.isEndWord = false;
        }
    }

    public static void main(String args[]) {
        String[] words = {"string", "strong", "str", "start", "begin", "hello", "state"};
        Trie trie = new Trie();
        
        for(String word : words) {
            trie.insert(word);
        }
        
        List<String> wordsTrie = trie.getWords();
        
        for(String word: wordsTrie) {
            System.out.println(word);
        }
        // Output[1]:
        // begin
        // hello
        // start
        // state
        // str
        // string
        // strong

        wordsTrie = trie.getWordsWithPrefix("sta");
        
        for(String word: wordsTrie) {
            System.out.println(word);
        }
        // Output[2]:
        // start
        // state
        
        // Output[3]:
        System.out.println(trie.search("string")); // true
        System.out.println(trie.search("strang")); // false
        System.out.println(trie.startsWith("st")); // true
    }
}