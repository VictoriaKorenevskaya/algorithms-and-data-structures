
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class VectorUpdater {
public:
    static void updateVectors(vector<long long>& vec1, vector<long long>& vec2, int i, long long x) {
        int index = i / vec2.size();
        vec1[i] += x;
        vec2[index] += x;
    }
};

class VectorCalculator {
public:
    static long long calculateSum(const vector<long long>& vec1, const vector<long long>& vec2, int left, long long right) {
        long long sum = 0;
        for (int i = left; i < right;) {
            if (i % vec2.size() == 0 && i + vec2.size() - 1 < right) {
                sum += vec2[i / vec2.size()];
                i += vec2.size();
            }
            else {
                sum += vec1[i++];
            }
        }
        return sum;
    }
};

class VectorPopulator {
public:
    static void populate(vector<long long>& vec1, vector<long long>& vec2) {
        int len = vec2.size();
        for (size_t i = 0; i < vec1.size(); ++i) {
            int index = i / len;
            vec2[index] += vec1[i];
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int size;
    cin >> size;

    vector<long long> vec1(size);
    for (int i = 0; i < size; ++i) {
        cin >> vec1[i];
    }

    int len = static_cast<int>(sqrt(size)) + 1;
    vector<long long> vec2(len);
    VectorPopulator::populate(vec1, vec2);

    int num;
    cin >> num;

    string striing;
    int i;
    long long x;

    for (int j = 0; j < num; ++j) {
        cin >> striing >> i >> x;
        if (striing == "FindSum") {
            cout << VectorCalculator::calculateSum(vec1, vec2, i, x) << '\n';
        }
        else if (striing == "Add") {
            VectorUpdater::updateVectors(vec1, vec2, i, x);
        }
    }

    return 0;
}