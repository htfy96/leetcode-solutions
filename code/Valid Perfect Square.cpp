class Solution {
public:
    bool isPerfectSquare(int num) {
        return round(sqrt(num)) == sqrt(num);
    }
};