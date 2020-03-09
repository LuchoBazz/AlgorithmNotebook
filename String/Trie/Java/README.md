# Trie (Prefix Tree) - Java

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

```java
static class TrieNode {
    private final int ALPHABET = 26;
    public TrieNode[] children;
    public boolean isEndWord;
    
    TrieNode() {
        this.children = new TrieNode[ALPHABET];
        this.isEndWord = false;
    }
}
```

* ## Insertar
```java
public void insert(String word) {
    if(word.length() == 0) return;
    
    char curr;
    int index = 0;
    
    TrieNode tmp = root;
    
    for(int i = 0; i < word.length(); ++i) {
        curr = word.charAt(i);
        index = curr - 'a';
        
        if(tmp.children[index] == null) {
        }
        
        tmp = tmp.children[index];
    }
    tmp.isEndWord = true;
}
```

* ## Buscar
```java
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
```

* ## Inicia Con?
```java
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
```

* ## Obtener Todas las Palabras

```java
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
```

* ## Obtener Todas las Palabras que Empiezan con un Prefijo

```java
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


public void dfs(TrieNode node, String characters, List<String> words) {
    // ...
}

private boolean isEmpty(TrieNode node) {
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
