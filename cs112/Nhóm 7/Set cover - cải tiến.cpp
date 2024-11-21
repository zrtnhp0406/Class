#include <bits/stdc++.h>
using namespace std;

// Tập con
vector<vector<int>> subsets;
// Danh sách các đỉnh U
vector<int> vertices;
// Map để lưu thông tin về các đỉnh
vector<bool> selected;

// Hàm nhập dữ liệu cho các đỉnh
void input_vertices(int n) {
    for (int i = 1; i <= n; i++) {
        int vertex;
        cin >> vertex;
        selected[vertex] = false;  // Đánh dấu tất cả các đỉnh ban đầu là chưa chọn
        vertices.push_back(vertex);
    }
}

// Hàm nhập các tập con và tính điểm số cho từng tập con
void input_subsets(int m) {
    for (int i = 1; i <= m; i++) {
        vector<int> subset;
        int size;
        cin >> size;
        subset.push_back(size);
        for (int j = 1; j <= size; j++) {
            int vertex;
            cin >> vertex;
            subset.push_back(vertex);
        }
        subsets.push_back(subset);
    }
}

// Hàm tính điểm số cho các tập con
vector<pair<int, int>> calculate_scores() {
    vector<pair<int, int>> score_sets;
    for (int i = 0; i < subsets.size(); i++) {
        int score = subsets[i][0];  // Điểm số là số lượng phần tử trong tập con
        score_sets.push_back({score, i});
    }
    return score_sets;
}

// Hàm sắp xếp các tập con theo điểm số giảm dần
void sort_subsets_by_score(vector<pair<int, int>>& score_sets) {
    sort(score_sets.rbegin(), score_sets.rend());
}

// Hàm xử lý chọn các tập con theo thứ tự giảm dần
int select_subsets(vector<pair<int, int>>& score_sets) {
    int selected_count = 0;  // Đếm số lượng đỉnh đã chọn

    for (auto& score_set : score_sets) {
        int subset_index = score_set.second;
        for (int i = 1; i < subsets[subset_index].size(); i++) {
            int vertex = subsets[subset_index][i];
            if (selected[vertex]) continue;  // Nếu đỉnh đã được chọn, bỏ qua
            selected[vertex] = true;  // Đánh dấu đỉnh đã chọn
            selected_count++;  // Tăng số lượng đỉnh đã chọn
        }
    }

    return selected_count;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Khởi tạo và nhập dữ liệu
    selected.resize(n + 1, false);  // Kích thước n+1 để dễ dàng truy cập từ 1 đến n
    input_vertices(n);
    input_subsets(m);

    // Tính điểm số cho các tập con và sắp xếp
    vector<pair<int, int>> score_sets = calculate_scores();
    sort_subsets_by_score(score_sets);

    // Xử lý và chọn các tập con theo thứ tự điểm số giảm dần
    int selected_count = select_subsets(score_sets);

    // In kết quả
    cout << "Số lượng đỉnh đã được chọn: " << selected_count << endl;

    return 0;
}
