class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int tar) {
        int g = __gcd(jug1, jug2);
        return tar % g == 0 && jug1 + jug2 >= tar;
    }
};