#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Pair {
    int end;
    int edgeLen;

    Pair(int toVertex, int lengthToVertex) : end(toVertex), edgeLen(lengthToVertex) {}
};

struct Vertex {
    int number;
    long long label;

    Vertex(int num, long long labbell) : number(num), label(labbell) {}
};

struct Priority {
    bool operator()(const Vertex& v1, const Vertex& v2) const {
        return v1.label > v2.label;
    }
};

class Fileee {
public:
    ifstream inFile;
    ofstream outFile;

    Fileee(const string& inFileName, const string& outFileName) {
        inFile.open(inFileName);
        outFile.open(outFileName);
    }

    ~Fileee() {
        inFile.close();
        outFile.close();
    }

    bool isOpen() const {
        return inFile.is_open() && outFile.is_open();
    }

    ifstream& InFile() {
        return inFile;
    }

    ofstream& OutFile() {
        return outFile;
    }
};

class Dijkstra {
public:
    void solve(const string& inFileName, const string& outFileName) {
        Fileee files(inFileName, outFileName);


        int n, m;
        files.InFile() >> n >> m;

        vector<bool> visited(n, false);
        vector<long long> len(n, 0LL);

        priority_queue<Vertex, vector<Vertex>, Priority> Queue;

        vector<vector<Pair>> list(n);

        int start, end, edgeLen;
        for (int i = 0; i < m; i++) {
            files.InFile() >> start >> end >> edgeLen;

            if (start != end) {
                list[start - 1].emplace_back(end - 1, edgeLen);
                list[end - 1].emplace_back(start - 1, edgeLen);
            }
        }

        Queue.push(Vertex(0, 0LL));

        while (!Queue.empty()) {
            Vertex ver = Queue.top();
            Queue.pop();

            if (!visited[ver.number]) {
                visited[ver.number] = true;
                len[ver.number] = (ver.number == 0) ? 0LL : ver.label;

              for (const Pair& paiir : list[ver.number]) {
                    Queue.push(Vertex(paiir.end, len[ver.number] + paiir.edgeLen));
              }
            }
        }

        files.OutFile() << len[n - 1] << endl;
    }
};

int main() {
    Dijkstra dijkstra;
    dijkstra.solve("input.txt", "output.txt");

    return 0;
}