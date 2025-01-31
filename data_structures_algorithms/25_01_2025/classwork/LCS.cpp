#include <iostream>
#include <string>

std::string A = "ACATGT";
std::string B = "CTGAAT";

// 1. LCS with recursion-memoization ✅
// 2. How many percent of memoization is filled (Counted) ✅

// 3. LCS with dynamic programming
// 4. LCS with dynamic programming with space optimization

class Memo{
public:
    std::vector<std::vector<int> > memo;
    int count;

    Memo() {
        this->count = 0;
        this->memo = std::vector<std::vector<int> >(A.size(), std::vector<int>(B.size(), -1));
    }

    int memorize(int i, int j, int value) {
        if (i < 0 || j < 0) return value;
        if (this->memo[i][j] == -1) {
            this->count++;
        }
        this->memo[i][j] = value;
        return value;
    }

    int get_value(int i, int j) {
        if (i < 0 || j < 0) return -1;
        return this->memo[i][j];
    }

    int get_fill_percent() {
        return (this->count * 100) / (A.size() * B.size());
    }

    void print() {
        std::cout << "   ";
        for (int i = 0; i < B.size(); ++i) {
            std::cout << B[i] << "  ";
        }
        std::cout << std::endl;

        for (int i = 0; i < A.size(); ++i) {
            std::cout << A[i] << " ";
            for (int j = 0; j < B.size(); ++j) {
                if (this->memo[i][j] != -1) {
                    std::cout << " ";
                }
                std::cout << this->memo[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

Memo memo = Memo();

int lcs_with_memoization(const std::string& A, const std::string& B, int i, int j) {
    if (memo.get_value(i, j) != -1) {
        return memo.get_value(i, j);
    }
    if (i == -1 || j == -1) {
        return memo.memorize(i, j, 0);
    }
    if (A[i] == B[j]) {
        return memo.memorize(i, j, 1 + lcs_with_memoization(A, B, i-1, j-1));
    }
    return memo.memorize(i, j, std::max(lcs_with_memoization(A, B, i-1, j), lcs_with_memoization(A, B, i, j-1)));
}

int main() {
    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;
    std::cout << "lcs_with_memoization: " << lcs_with_memoization(A, B, A.size()-1, B.size()-1) << std::endl;
    memo.print();
    std::cout << "Fill percent: " << memo.get_fill_percent() << std::endl;
    return 0;
}