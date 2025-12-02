#include <iostream>
#include <vector>
using namespace std;

class tree_array {
private:
    vector<long long> a;
    int capacity;
    static int lowbit(int x) {
        return x & (-x);
    }

public:
    explicit tree_array(int n) {
        capacity = n + 1;
        a.resize(capacity, 0);
    }
    void update(int x, int k) {
        if (x <= 0 || x >= capacity) {
            return;
        }
        while (x < capacity) {
            a[x] += k;
            x += lowbit(x);
        }
    }
    long long query(int x) const {
        long long s = 0;
        if (x >= capacity) {
            x = capacity - 1;
        }
        while (x > 0) {
            s += a[x];
            x -= lowbit(x);
        }
        return s;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    tree_array ta(n);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        ta.update(i, val);
    }

    for (int k = 0; k < q; ++k) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, x;
            cin >> i >> x;
            ta.update(i, x);
        } else { 
            int l, r;
            cin >> l >> r;
            long long result = ta.query(r) - ta.query(l - 1);
            cout << result << "\n";
        }
    }

    return 0;
}
