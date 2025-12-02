#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct par{
    char ch;
    int var;
}par;

typedef struct node{
    int num;
    node *lc;
    node *rc;
}node;

vector<par> hash;

bool cmp(const par a, const par b) { return a.var > b.var;}

string inp;

