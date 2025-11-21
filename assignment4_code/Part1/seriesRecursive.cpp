#include <iostream>
#include <cstdlib> 
#include <unordered_map>

// Memoization table for optimization
std::unordered_map<int, long long> memo;

/**
 * Computes the n-th term of the recursive sequence J(n).
 * J(n) = J(n-1) + 2*J(n-2) + 4*J(n-3) for n > 2
 * Base cases: J(0)=0, J(1)=1, J(2)=1
 * Uses memoization for optimization.
 * @param n - the term number to compute (non-negative integer)
 * @return the n-th term as a long long integer
 */
long long seriesRecursive(int n);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1; 
    }

    int n = std::atoi(argv[1]); 
    
    if (n < 0) {
        std::cerr << "Error: Input must be a non-negative integer." << std::endl;
        return 1;
    }

    long long result = seriesRecursive(n); 
    std::cout << "seriesRecursive(" << n << ") = " << result << std::endl;

    return 0; 
}

long long seriesRecursive(int n) {
    auto it = memo.find(n);
    if (it != memo.end()) {
        return it->second;
    }
    
    long long result;
    
    if (n == 0) {
        result = 0;
    }
    else if (n == 1 || n == 2) {
        result = 1;
    }
    else {
        result = seriesRecursive(n - 1) + 
                2 * seriesRecursive(n - 2) + 
                4 * seriesRecursive(n - 3);
    }
    
    memo[n] = result;
    return result;
}
