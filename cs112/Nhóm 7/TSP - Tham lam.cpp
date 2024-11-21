#include <bits/stdc++.h>
using namespace std;

const double INF = 1e9;

// Tính khoảng cách giữa hai đỉnh u và v
double distance(int u, int v, vector<vector<double>>& graph) {
    return graph[u][v];
}
double greedy_tsp(int n, vector<vector<double>>& graph) {
    vector<bool> visited(n, false);  // Mảng đánh dấu các đỉnh đã thăm
    double total_distance = 0.0;
    int current_city = 0;  // Bắt đầu từ đỉnh 0
    visited[current_city] = true;
    int cities_visited = 1;

    while (cities_visited < n) {
        double min_dist = INF;
        int next_city = -1;

        // Tìm đỉnh chưa thăm có cạnh nhỏ nhất
        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[current_city][i] < min_dist) {
                min_dist = graph[current_city][i];
                next_city = i;
            }
        }

        // Cập nhật quãng đường tổng và đánh dấu đỉnh đã thăm
        total_distance += min_dist;
        visited[next_city] = true;
        current_city = next_city;
        cities_visited++;
    }

    // Quay lại đỉnh ban đầu
    total_distance += graph[current_city][0];

    return total_distance;
}

int main() {
    int n, m;
    cout << "Nhập số đỉnh và số cạnh: ";
    cin >> n >> m;

    // Khởi tạo đồ thị trọng số
    vector<vector<double>> graph(n, vector<double>(n, INF));

    cout << "Nhập các cạnh (u, v, weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        double weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;  // Đồ thị vô hướng
    }

    double result = greedy_tsp(n, graph);
    cout << "Tổng trọng số chu trình: " << result << endl;

    return 0;
}
