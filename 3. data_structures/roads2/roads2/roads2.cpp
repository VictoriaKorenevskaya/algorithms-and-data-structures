
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Roads {
    long long rod;
    long long* size;
    long long* representatives;

public:
    Roads(const long long n) : rod(n), size(new long long[n + 1]), representatives(new long long[n + 1]) {
        for (long long i = 1; i <= n; ++i) {
            representatives[i] = i;
        }
    }

    ~Roads() {
        delete[] size;
        delete[] representatives;
    }

    long long DisjointSet(const long long x) {
        return (x == representatives[x]) ? x : (representatives[x] = DisjointSet(representatives[x]));
    }

    void Union(long long x, long long y) {
        x = DisjointSet(x);
        y = DisjointSet(y);

        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }

            --rod;
            representatives[y] = x;
            size[x] += size[y];
        }
    }

    long long part() const {
        return rod;
    }
};

class Solver {
    Roads d;
    vector<pair<long long, long long>> info;
    vector<bool> veec;
    vector<long long> rooads;

public:
    Solver(const long long n, const long long m, const long long q, ifstream& inFile)
        : d(n), info(m), veec(m), rooads(q) {

        for (long long i = 0; i < m; ++i) {
            long long city1;
            long long city2;

            inFile >> city1 >> city2;
            info[i] = { city1, city2 };
            veec[i] = false;
        }

        for (long long i = 0; i < q; ++i) {
            long long city;
            inFile >> city;
            --city;
            rooads[q - 1 - i] = city;
            veec[city] = true;
        }
    }

    ~Solver() {}

    void ProcessQueries(std::ofstream& outFile) {
        string out;
        for (long long i = 0; i < info.size(); ++i) {

            if (!veec[i]) {
                d.Union(info[i].first, info[i].second);
               
            }

        }

        for (long long i = 0; i < rooads.size(); ++i) {
            auto& p = info[rooads[i]];
            out = to_string(d.part() > 1 ? 0 : 1) + out;
            d.Union(p.first, p.second);
        }

        outFile << out;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    long long n, m;
    long long q;
    inFile >> n >> m >> q;

    Solver solver(n, m, q, inFile);
    solver.ProcessQueries(outFile);

    return 0;
}