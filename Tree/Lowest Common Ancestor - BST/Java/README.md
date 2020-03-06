# Lowest Common Ancestor - Java

## Contenido

* [Contenido](#contenido)
* [Ilustración](#ilustración)
* [Implementación](#implementación)
* [Complejidad](#complejidad)

## Ilustración

<img alt=" Lowest Common Ancestor of a Binary Search Tree" src="https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/Figures/235/235_LCA_Binary_1.png" width="400">

## Implementación Recursiva

* **Nota:** Esta implementación es mas rapida que la recursiva-iterativa

```java
public TreeNode LCA(TreeNode root, int p, int q) {
    if(isEmpty(root)) return root;
    int valueRoot = root.val;
    
    if(p < valueRoot && q < valueRoot) {
        return LCA(root.left, p, q);
    } else if(p > valueRoot && q > valueRoot) {
        return LCA(root.right, p, q);
    }
    return root;
}

private boolean isEmpty(TreeNode node) {
    return node == null;
}
```

## Implementación Recursiva Iterativa

```java
public int lowestCommonAncestor(int p, int q) {
    if(p == q) {
        return p;
    }
    List<Integer> pathP = new ArrayList<>();
    List<Integer> pathQ = new ArrayList<>();

    lowestCommonAncestor(this.root, p, pathP);
    lowestCommonAncestor(this.root, q, pathQ);

    for(int i = 0; i < pathP.size() && i <pathQ.size(); ++i) {
        if(!pathP.get(i).equals(pathQ.get(i))) {
            return pathP.get(i-1);
        }
    }
    int minIndex = Math.min(pathP.size(), pathQ.size()) - 1;

    if(pathP.get(minIndex).equals(pathQ.get(minIndex))) {
        return pathP.get(minIndex);
    }
    return Integer.MIN_VALUE;
}

private TreeNode lowestCommonAncestor(TreeNode root, int key, List<Integer> list) {
    if(isEmpty(root)) return root;
    if(key < root.value) {
        list.add(root.value);
        root.left = lowestCommonAncestor(root.left, key, list);
    } else if(key > root.value) {
        list.add(root.value);
        root.right = lowestCommonAncestor(root.right, key, list);
    } else {
        list.add(root.value);
    }
    return root;
}
```

## Complejidad

![O de n](https://i.ibb.co/wsr7QLX/O-n.png)