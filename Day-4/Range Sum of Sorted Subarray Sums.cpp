// Range Sum of Sorted Subarray Sums
//problem of the day

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> subarraySums;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }

        sort(subarraySums.begin(), subarraySums.end());

        for (int i = left - 1; i < right; i++) {
            total += subarraySums[i];
        }

        return static_cast<int>(total % 1000000007);
    }
};