public class LowestCommonAncestor {
    
    TreeNode root;

    LowestCommonAncestor() {
        this.root = null;
    }

    LowestCommonAncestor(TreeNode root) {
        this.root = root;
    }

    public int LCA(int p, int q) {
        TreeNode ans = LCA(this.root, p, q);

        if(!isEmpty(root)) {
            return ans.value;
        }
        return Integer.MIN_VALUE;
    }

    // Implementación 1 - Mas rapida que la 2
    private TreeNode LCA(TreeNode root, int p, int q) {
        if(isEmpty(root)) return root;
        int valueRoot = root.val;
        
        if(p < valueRoot && q < valueRoot) {
            return LCA(root.left, p, q);
        } else if(p > valueRoot && q > valueRoot) {
            return LCA(root.right, p, q);
        }
        return root;
    }

    // Implementación 2
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
    
    private boolean isEmpty(TreeNode node) {
        return node == null;
    }

    static class TreeNode {
        public int value;
        public TreeNode left;
        public TreeNode right;
        TreeNode(int value) {
            this.value = value;
        }
     }
}