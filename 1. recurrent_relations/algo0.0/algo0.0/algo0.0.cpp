
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_set>

int main() {
    std::ifstream fin("input.txt");
    if (!fin.is_open()) {
        std::cout << "input file is not open" << std::endl;
        return 1;
    }
    std::cout << "File is open" << std::endl;

    std::vector<int> arr;
    int num;

    while (fin >> num) {
        arr.push_back(num);
    }
    fin.close();

    std::unordered_set<int> uniqueNumbers;
    for (int i : arr) {
        uniqueNumbers.insert(i);
    }

    long long sum = 0;
    for (int uniqueNum : uniqueNumbers) {
        sum += uniqueNum;
    }

    std::ofstream fout("output.txt");
    if (!fout.is_open()) {
        std::cout << "output file is not open" << std::endl;
        return 1;
    }
    fout << sum;
    fout.close();

    return 0;
}