#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class HuffmanTree {
public:
    struct Node {
        char value;
        int freq;
        Node *left, *right;

        Node(char v, int f) : value(v), freq(f), left(nullptr), right(nullptr) {}
    };

    struct CompareNode {
        bool operator()(Node* const& n1, Node* const& n2) {
            return n1->freq > n2->freq;
        }
    };

    HuffmanTree() : root(nullptr) {}

    ~HuffmanTree() {
        del_tree(root);
    }

    void make_tree(const std::string& text) {
        if (root) {
            del_tree(root);
            root = nullptr;
            huffman_codes.clear();
            frequencies.clear();
        }

        for (char ch : text) {
            frequencies[ch]++;
        }

        priority_queue<Node*, vector<Node*>, CompareNode> pq;
        for (auto const& [key, val] : frequencies) {
            pq.push(new Node(key, val));
        }

        while (pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            Node* newNode = new Node('$', left->freq + right->freq);
            newNode->left = left;
            newNode->right = right;
            pq.push(newNode);
        }

        root = pq.top();
        gen_codes(root, "");
    }

    int calc_length() {
        int sum = 0;
        for (auto const& [ch, freq] : frequencies) {
            if (huffman_codes.count(ch)) {
                sum += freq * huffman_codes[ch].length();
            }
        }
        return sum;
    }

    string query(char ch) { return huffman_codes[ch]; }

private:
    Node* root;
    map<char, std::string> huffman_codes; 
    map<char, int> frequencies;          
    void gen_codes(Node* node, string current_code) {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            huffman_codes[node->value] = current_code;
        }
        gen_codes(node->left, current_code + "0");
        gen_codes(node->right, current_code + "1");
    }

    void del_tree(Node* node) {
        if (node == nullptr) {
            return;
        }
        del_tree(node->left);
        del_tree(node->right);
        delete node;
    }
};

int main(){
    HuffmanTree hf;
    string s;
    cin >> s;
    hf.make_tree(s);
    cout << hf.calc_length() << endl;
    bool vis[256] = {0};
    for (int i = 0; i < s.length(); i++){
        if (!vis[s[i]]) {
            cout << s[i] << " " << hf.query(s[i]) << endl;
            vis[s[i]] = true;
        }
    }
    return 0;
}

