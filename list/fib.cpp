#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // 生成斐波那契数列
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (fib.back() < n) {
        fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
    
    int k = fib.size() - 1;
    int low = 0, high = n - 1;
    vector<int> result;
    bool found = false;
    
    while (low <= high && k >= 0) {
        int mid = low + fib[k] - 1;
        if (mid > high) {
            mid = high;
        }
        
        if (a[mid] == x) {
            found = true;
            // 向左寻找第一个x
            while (mid > 0 && a[mid-1] == x) {
                mid--;
            }
            break;
        } else if (a[mid] < x) {
            // 记录当前左端点值，然后移动左端点
            result.push_back(a[low]);
            low = mid + 1;
            k -= 2;
        } else {
            high = mid - 1;
            k -= 1;
        }
    }
    
    if (found) {
        for (int val : result) {
            cout << val << " ";
        }
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
