#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int> l;
    int n, m, r, s;
    cin >> n;
    for (int i = 0;i < n;++i) {
        cin >> s;
        l.push_back(s);
    }
    cin >> r >> m;
    auto it = l.begin();
    std::advance(it, r);
    l.insert(it, m);
    if (r > 1) {
	    it--;
	    it--;
	    it--;
	    l.erase(it);
    }
    for (const int& e : l) {cout << e << " ";}
    return 0;
}
