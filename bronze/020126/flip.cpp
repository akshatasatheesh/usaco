#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    long N, K;
    cin >> N >> K;
    vector<long> x(K);
    vector<long> y(K);
    vector<long> z(K);
    vector<long> x_freq(N+1);
    vector<long> x_visited(N+1);
    string result(N, 'O');
    long x_best = 0;

    for (long i = 0; i < K; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (long i = 0; i < K; i++) {
        x_freq[x[i]] = x_freq[x[i]] + 1;
    }
    int max_score = 0;
    int num_max_keys = 0;
    string best_key;

    for (int t = 1; t <= N; t++) {
        int score = 0;
        for (long i = 1; i <= N; i++) {
            if (x_freq[i] > x_freq[x_best] && x_visited[i] == 0) {x_best = i;}
        }
        x_visited[x_best] = 1;
        result[x_best-1] = 'M';
        for (long i = 0; i < K; i++) {
            if (result[x[i]-1] == 'M' && result[y[i]-1] == 'O' && result[z[i]-1] == 'O') {
                score++;
            }
        }
        x_best = 0;
        if (score > max_score) {
            max_score = score;
            best_key = result;
            num_max_keys = 1;
        } else if (score == max_score) {
            num_max_keys++;
        }
    }

    for (int t = 0; t < N; t++) {
        int score = 0;
        string temp_best_key = best_key;
        if (temp_best_key[t] == 'M') {
            continue;
        } else {
            temp_best_key[t] = 'M';
        }
        for (long i = 0; i < K; i++) {
            if (temp_best_key[x[i]-1] == 'M' && temp_best_key[y[i]-1] == 'O' && temp_best_key[z[i]-1] == 'O') {
                score++;
            }
        }
        if (score == max_score) {
            num_max_keys++;
        }
    }

    cout << max_score << " " << num_max_keys;
}
