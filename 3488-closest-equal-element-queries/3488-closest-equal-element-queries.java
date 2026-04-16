class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
               Map<Integer, TreeSet<Integer>> mp = new HashMap<>();
        int n = nums.length;

        // Step 1: build map
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(nums[i], k -> new TreeSet<>()).add(i);
        }

        List<Integer> ans = new ArrayList<>();

        // Step 2: process queries
        for (int q : queries) {
            TreeSet<Integer> st = mp.get(nums[q]);

            if (st.size() <= 1) {
                ans.add(-1);
                continue;
            }

            Integer next = st.higher(q);
            Integer prev = st.lower(q);

            // Circular handling
            if (next == null) next = st.first();
            if (prev == null) prev = st.last();

            // Distances
            int distNext = (next - q + n) % n;
            int distPrev = (q - prev + n) % n;

            ans.add(Math.min(distNext, distPrev));
        }

        return ans;
    }
}