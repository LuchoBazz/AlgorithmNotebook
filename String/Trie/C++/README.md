# Trie (Prefix Tree) - c++

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación-iterativa)
    * [Nodo](#nodo)
    * [Insertar](#insertar)
    * [Buscar](#buscar)
    * [Inicia Con?](#inicia-con)
    * [Obtener Todas las Palabras](#obtener-todas-las-palabras)
    * [Obtener Todas las Palabras que Empiezan con un Prefijo](#obtener-todas-las-palabras-que-empiezan-con-un-prefijo)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Ilustración Longest Common SubString" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/07/screen-shot-2018-01-31-at-163403.png" width="300">

## Implementación

* ## Node

```c++
class TrieNode {
public:
    array<TrieNode*, ALPHABET> children;
    bool isEnd;
    
    TrieNode() {
        children.fill(NULL);
        isEnd = false;
    }
};
```

* ## Insertar
```c++
void insert(string word) {
    int n = word.size();
    if(n==0) return;
    
    TrieNode* tmp = root;
    
    int index = 0;
    
    for(int i = 0; i < n; ++i) {
        index = word[i] - 'a';
        
        if(tmp->children[index] == NULL) {
            tmp->children[index] = new TrieNode();
        }
        tmp = tmp->children[index];
    }
    tmp->isEnd = true;
}
```

* ## Buscar
```c++
bool search(string word) {
    int n = word.size();
    if(n==0) return false;
    
    TrieNode* tmp = root;
    
    int index = 0;
    
    for(int i = 0; i < n; ++i) {
        index = word[i] - 'a';
        
        if(tmp->children[index] == NULL) {
            return false;
        }
        tmp = tmp->children[index];
    }
    return (tmp!=NULL)?tmp->isEnd:false;
}
```

* ## Inicia Con?
```c++
bool startsWith(string prefix) {
    int n = prefix.size();
    if(n==0) return false;
    
    TrieNode* tmp = root;
    
    int index = 0;
    
    for(int i = 0; i < n; ++i) {
        index = prefix[i] - 'a';
        
        if(tmp->children[index] == NULL) {
            return false;
        }
        tmp = tmp->children[index];
    }
    return true;
}
```

* ## Obtener Todas las Palabras

```c++
vector<string> getWords() {
    vector<string> words;
    
    dfs(root, "", words);
    return words;
}

void dfs(TrieNode* node, string characters, vector<string> &words) {
    if(isEmpty(node)) return;
    
    if(node->isEnd) {
        words.push_back(characters);
    }
    
    string newWord = "";
    
    int n = ALPHABET;
    
    for(int i = 0; i < n; ++i) {
        if(!isEmpty(node->children[i])) {
            newWord = characters + (char)(i+'a')+"";
            dfs(node->children[i], newWord, words);
        }
    }
}

bool isEmpty(TrieNode* node) {
    return node == NULL;
}
```

* ## Obtener Todas las Palabras que Empiezan con un Prefijo

```c++
vector<string> getWordsWithPrefix(string prefix) {
    vector<string> words;
    int n = prefix.size();
    if(n == 0) return words;
    
    int index = 0;
    TrieNode* tmp = root;
    
    for(int i = 0; i < n; ++i) {
        index = prefix[i] - 'a';
        
        if(tmp->children[index] == NULL) {
            return words;
        }
        tmp = tmp->children[index];
    }
    
    dfs(tmp, prefix, words);
    return words;
}


void dfs(TrieNode* node, string characters, vector<string> &words) {
    // ...
}

bool isEmpty(TrieNode* node) {
    // ...
}
```


## Time Complexity

* Insert(String)

    <img alt="Trie Time Complexity" src="https://i.ibb.co/swGGZrY/O-n-n-string-length.png" width="300">

* search(String)

    <img alt="Trie Time Complexity" src="https://i.ibb.co/swGGZrY/O-n-n-string-length.png" width="300">

* startsWith(String)

    <img alt="Trie Time Complexity" src="https://i.ibb.co/swGGZrY/O-n-n-string-length.png" width="300">

## Space Complexity

<img alt="Trie Space Complexity" src="https://i.ibb.co/p00qDyc/O-n-k-Trie.png" width="500">
