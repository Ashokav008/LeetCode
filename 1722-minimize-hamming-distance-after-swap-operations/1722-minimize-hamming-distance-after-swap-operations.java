

class DSU {
    int[] parent;

    public DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
}


class Solution {



    public int minimumHammingDistance(int[] source, int[] target, int[][] aS) {
        
        int n=source.length,m=aS.length;
        DSU dsu = new DSU(n);
        //take one node and its all connected edges
        
        for(int i=0;i<m;i++){
            dsu.union(aS[i][0],aS[i][1]);
        }
        
        Map<Integer,TreeSet<Integer>>components=new HashMap<>();

        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            components.computeIfAbsent(root, k -> new TreeSet<>()).add(i);
        }
        int ans=0;
     
        for (TreeSet<Integer> st : components.values()) {
        //    String ff="",ss="";

            HashMap<Integer,Integer>mp=new HashMap<>();
           for(Integer compEle:st){
               
                // System.out.print(idx+" ");
                // ff+=source[idx];
                // ss+=target[idx];
                //    System.out.println(ff+"  "+ss);

               mp.put(source[compEle], mp.getOrDefault(source[compEle], 0) + 1);
                
           }
            for (int idx : st) {
                if (mp.getOrDefault(target[idx], 0) > 0) {
                    mp.put(target[idx], mp.get(target[idx]) - 1);
                } else {
                    ans++;
                }
            }

        }

    return ans;

    }
}