# Uncompressed Suffix Tree - Java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación-iterativa)
    * [Nodo](#nodo)
    * [Suffix Tree](#suffix-tree)
    * [build](#build)
    * [insert](#insert)
    * [search](#search)
    * [dfs](#dfs)
* [Time Complexity](#time-complexity)
* [Space Complexity](#space-complexity)

## Ilustración

<img alt="Ilustración Suffix Tree" src="https://i.ibb.co/X2XrjVq/Suffix-Tree.pngg" width="500">

## Implementación

* ## Nodo

```java
class Node {
    public static final int ALPHABET_SIZE = 27;
    
    public boolean isEndWord;
    public int index;
    public Node[] children;
    
    Node() {
        this.isEndWord = false;
        this.index = -1;
        this.children = new Node[ALPHABET_SIZE];
    }
}
```

* ## Suffix Tree

```java

class SuffixTree {
    public Node root;
    
    SuffixTree(String key) {
        this.root = new Node();
        
        build(key);
    }
    // ...
    // ...
}
```

* ## Build
```java
private void build(String key) {
    key += "$";
    
    for(int i = 0; i < key.length(); ++i) {
        insert(key.substring(i), i);
    }
}
```

* ## Insert

```java
private void insert(String key, int startIndex) {
    if(key.length() == 0) return;
    
    char ch;
    int index = 0;
    Node tmp = this.root;
    
    for(int i = 0; i < key.length(); ++i) {
        ch = key.charAt(i);
        if(ch == '$') index = 26;
        else index = ch - 'a';
        
        if(tmp.children[index] == null)             {
            tmp.children[index] = new Node();
        }
        tmp = tmp.children[index];
    }
    tmp.isEndWord = true;
    tmp.index = startIndex;
}
```

* ## Search

```java
public List<Integer> search(String key) {
    List<Integer> out = new ArrayList<>();
    
    if(key.length() == 0) return out;
    
    char ch;
    int index = 0;
    Node tmp = this.root;
    
    for(int i = 0; i < key.length(); ++i) {
        ch = key.charAt(i);
        index = ch - 'a';
        if(tmp.children[index] == null) {
            return out;
        }
        tmp = tmp.children[index];
    }
    dfs(tmp, out);
    return out;
}
```

* ## dfs

```java
private void dfs(Node node, List<Integer> out) {
    if(isEmpty(node)) return;
    
    if(node.isEndWord) {
        out.add(node.index);
    }
    
    for(int i = 0; i < node.children.length; ++i) {
        if(node.children[i] != null) {
            dfs(node.children[i], out);
        }
    }
}

private boolean isEmpty(Node node) {
    return node == null;
}
```

## Time Complexity

<img alt="Suffix Tree Time Complexity" src="https://i.ibb.co/ZXkzrgW/O-n-2.png" width="50">

## Space Complexity

<img alt="Suffix Tree Space Complexity" src="https://i.ibb.co/ZXkzrgW/O-n-2.png" width="50">
