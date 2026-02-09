#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long N, Q;
    cin >> N >> Q;
    vector<long> moonies(N);

    for (long i = 0; i < N; i++) {
        cin >> moonies[i];
    }
    vector<long> pre_processed_moonies(N);

    pre_processed_moonies[0] = 1;
    for (long i = 1; i < N; i++) {
        for (long j = 0; j < i; j++) {
            long long pow_delta = 1LL << (i - j);
            if (pow_delta < 2) {pow_delta = 2;}
            if (moonies[i] > (moonies[j]*pow_delta)) {
                pre_processed_moonies[i] = 0;
            } else {
                if (pre_processed_moonies[j] == 1) {
                    pre_processed_moonies[i] = 1;
                }

            }
        }
    }

    for (long i = 0; i < Q; i++) {
        long result = 0;
        long x;
        cin >> x;
        long curr_deal_num = 0;
        while (true) {
            long long temp = 1LL << curr_deal_num;
            if (x < temp || curr_deal_num >= N) {
                break;
            }
            curr_deal_num += 1;
        }
        curr_deal_num += 1;
        while (x > 0) {
            if (pre_processed_moonies[curr_deal_num-1] == 1) {
                long long gg = 1LL << (curr_deal_num - 1);
                long quo = x/gg;
                result += (quo * moonies[curr_deal_num-1]);
                x = x - (quo * gg);
            } curr_deal_num -= 1;
        }
        cout << result << endl;
    }
    return 0;
}
