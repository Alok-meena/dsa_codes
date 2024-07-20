#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

long long findMinSquaredDifferenceSum(const std::vector<long long>& x, const std::vector<long long>& y) {
    if (x.size() != y.size() || x.size() < 2) {
        std::cerr << "Vectors must be of the same size and contain at least two elements." << std::endl;
        return -1;  // Invalid input
    }

    // Copy vectors to avoid modifying the original ones
    std::vector<long long> sorted_x = x;
    std::vector<long long> sorted_y = y;

    // Sort both vectors
    std::sort(sorted_x.begin(), sorted_x.end());
    std::sort(sorted_y.begin(), sorted_y.end());

    long long min_sum = LLONG_MAX;

    // Calculate squared differences
    for (size_t i = 1; i < sorted_x.size(); ++i) {
        long long x_diff = sorted_x[i] - sorted_x[i - 1];
        long long y_diff = sorted_y[i] - sorted_y[i - 1];
        long long sum_squared_diff = x_diff * x_diff + y_diff * y_diff;

        // Debug output
        std::cout << "x_diff: " << x_diff << ", y_diff: " << y_diff << ", sum_squared_diff: " << sum_squared_diff << std::endl;

        // Update the minimum sum using std::min
        min_sum = std::min(min_sum, sum_squared_diff);
    }

    return min_sum;
}

int main() {
    std::vector<long long> x = {0, 543432};
    std::vector<long long> y = {500, 600};

    long long result = findMinSquaredDifferenceSum(x, y);

    if (result != -1) {
        std::cout << "The minimum sum of squared differences is: " << result << std::endl;
    }

    return 0;
}
