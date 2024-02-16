#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string>& strs, int start, int end) {
    if (start == end) {
        return strs[start];
    }

    int mid = (start + end) / 2;
    std::string leftPrefix = longestCommonPrefix(strs, start, mid);
    std::string rightPrefix = longestCommonPrefix(strs, mid + 1, end);

    int minLength = std::min(leftPrefix.length(), rightPrefix.length());
    for (int i = 0; i < minLength; i++) {
        if (leftPrefix[i] != rightPrefix[i]) {
            return leftPrefix.substr(0, i);
        }
    }

    return leftPrefix.substr(0, minLength);
}

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    return longestCommonPrefix(strs, 0, strs.size() - 1);
}

int main() {
    int n;
    std::cout << "Enter the number of strings: ";
    std::cin >> n;

    std::vector<std::string> strs(n);
    std::cout << "Enter the strings:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];
    }

    std::string commonPrefix = longestCommonPrefix(strs);
    std::cout << "Longest common prefix: " << commonPrefix << std::endl;

    return 0;
}
