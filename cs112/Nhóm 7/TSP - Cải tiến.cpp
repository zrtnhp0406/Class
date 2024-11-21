#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

double distance(int u, int v, vector<vector<double>>& graph) {
    return graph[u][v];
}

double calculate_total_distance(const vector<int>& path, vector<vector<double>>& graph) {
    double total_distance = 0.0;
    int n = path.size();
    for (int i = 0; i < n - 1; i++) {
        total_distance += graph[path[i]][path[i + 1]];
    }
    total_distance += graph[path[n - 1]][path[0]]; // quay lại đỉnh xuất phát
    return total_distance;
}

vector<int> get_neighbors(const vector<int>& path) {
    vector<int> neighbors = path;
    // Hoán đổi ngẫu nhiên 2 đỉnh để tạo hàng xóm (neighbor)
    int i = rand() % path.size();
    int j = rand() % path.size();
    swap(neighbors[i], neighbors[j]);
    return neighbors;
}

double local_search(int n, vector<vector<double>>& graph, vector<int>& path) {
    double best_distance = calculate_total_distance(path, graph);
    bool improved = true;

    while (improved) {
        improved = false;
        vector<int> best_neighbor;
        double best_neighbor_distance = best_distance;

        // Tạo các hàng xóm bằng cách hoán đổi các đỉnh trong chu trình
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Tạo một hàng xóm mới bằng cách hoán đổi đỉnh i và j
                vector<int> new_path = path;
                swap(new_path[i], new_path[j]);
                double new_distance = calculate_total_distance(new_path, graph);
                if (new_distance < best_neighbor_distance) {
                    best_neighbor_distance = new_distance;
                    best_neighbor = new_path;
                    improved = true;
                }
            }
        }

        if (improved) {
            path = best_neighbor; // Cập nhật giải pháp hiện tại với hàng xóm tốt nhất
            best_distance = best_neighbor_distance; // Cập nhật tổng trọng số mới
        }
    }
    return best_distance;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<double>> graph(n, vector<double>(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v;
        double weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    // Bắt đầu từ một chu trình tham lam (ví dụ, Nearest Neighbor)
    vector<int> path;
    vector<bool> visited(n, false);
    int current_city = 0;
    visited[current_city] = true;
    path.push_back(current_city);
    
    for (int i = 1; i < n; i++) {
        double min_dist = INF;
        int next_city = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && graph[current_city][j] < min_dist) {
                min_dist = graph[current_city][j];
                next_city = j;
            }
        }
        visited[next_city] = true;
        path.push_back(next_city);
        current_city = next_city;
    }

    // Tính tổng trọng số ban đầu của chu trình
    double initial_distance = calculate_total_distance(path, graph);
    cout << "Tổng trọng số ban đầu của chu trình: " << initial_distance << endl;

    // Áp dụng thuật toán Local Search
    double final_distance = local_search(n, graph, path);
    cout << "Tổng trọng số sau khi áp dụng Local Search: " << final_distance << endl;

    return 0;
}
