#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
    ifstream input("graph.txt");
    if (!input.is_open()) {
        cout << "Ошибка файла." << endl;
        return 1;
    }

    int n, m, start;
    input >> n >> m;

    bool** graph = new bool*[n];
    for (int i = 0; i < n; i++) {
        graph[i] = new bool[n]{false};
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        input >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    input >> start;

    int* distances = new int[n]{-1};
    distances[start] = 0;

//очередь
    queue<int> q;
    q.push(start);

//обход графа
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && distances[i] == -1) {
                distances[i] = distances[current] + 1;
                q.push(i);
            }
        }
    }
//освободил память и подровнял память
    for (int i = 0; i < n; i++) {
        cout << distances[i] << " ";
    }

    for (int i = 0; i < n; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] distances;
    input.close();

    return 0;
}