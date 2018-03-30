class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] {};
        for_each(nums.cbegin(), nums.cend(), [&](int color) {
            colors[color]++;
        });
        nums.clear();
        for (int color=0; color < 3; ++color)
            std::fill_n(back_inserter(nums), colors[color], color);
    }
};