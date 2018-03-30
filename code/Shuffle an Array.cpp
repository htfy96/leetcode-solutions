class Solution {
    vector<int> original;
    int total;
public:
    Solution(vector<int> nums) {
        original = move(nums);
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> a = original;
        if (a.empty()) return a;
        for (int i=0; i<a.size() - 1; ++i)
        {
            int idx = rand() % (a.size() - i);
            swap(a[i], a[i + idx]);
        }
        return a;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */