/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& v1,
        const std::vector<int>& v2)
    {
        // Let A.size() <= B.size()
        const auto& A = (v1.size() < v2.size() ? v1 : v2);
        const auto& B = (v1.size() < v2.size() ? v2 : v1);
        const int m = A.size();
        const int n = B.size();

        // Pad space between numbers
        // 0 1 2 3 4 5 6
        // # 0 # 1 # 2 #
        // Left index = (Cut - 1) / 2
        // Right index = Cut / 2
        int L = 0, R = m * 2 + 1;
        while (L < R) {
            int C1 = (L + R) / 2;
            int C2 = m + n - C1;

            double L1 = (C1 == 0) ? MIN_INT : A[(C1 - 1) / 2];
            double L2 = (C2 == 0) ? MIN_INT : B[(C2 - 1) / 2];
            double R1 = (C1 == m * 2) ? MAX_INT : A[C1 / 2];
            double R2 = (C2 == n * 2) ? MAX_INT : B[C2 / 2];
            if (L1 > R2) {
                R = C1;
            } else if (L2 > R1) {
                L = C1 + 1;
            } else {
                return (std::max(L1, L2) + std::min(R1, R2)) / 2.0;
            }
        }
        return -1;
    }
};
