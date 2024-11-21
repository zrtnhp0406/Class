#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets;
vector<int> element_to_index;
vector<int> score;
vector<vector<int>> element_sets;
map<int, bool> element_present;
set<pair<int, int>> available_sets;

void input_data(int n, int m) {
    for (int i = 1; i <= n; i++) {
        int element;
        cin >> element;
        element_to_index.push_back(i);
        element_present[element] = i;
    }

    subsets.resize(m + 1);
    score.resize(m + 1, 0);
    element_sets.resize(n + 1);

    for (int i = 1; i <= m; i++) {
        int subset_size;
        cin >> subset_size;
        subsets[i].push_back(0);
        subsets[i][0] = subset_size;

        for (int j = 1; j <= subset_size; j++) {
            int x;
            cin >> x;
            x = element_present[x];
            subsets[i].push_back(x);
            element_sets[x].push_back(i);
        }

        score[i] = subset_size;
        available_sets.insert({score[i], i});
    }
}

void update_sets(int element) {
    for (int set_id : element_sets[element]) {
        available_sets.erase({score[set_id], set_id});
        score[set_id]--;
        if (score[set_id] > 0) {
            available_sets.insert({score[set_id], set_id});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    input_data(n, m);

    int total_count = 0, ans = 0;
    vector<bool> covered(n + 1, false);

    while (total_count < n && !available_sets.empty()) {
        auto best_set = *available_sets.rbegin();
        available_sets.erase(prev(available_sets.end()));

        ans++;
        total_count += best_set.first;

        for (int element : subsets[best_set.second]) {
            if (!covered[element]) {
                covered[element] = true;
                update_sets(element);
            }
        }
    }

    cout << ans;
    return 0;
}
