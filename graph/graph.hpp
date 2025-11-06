#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept> 
#include <algorithm> 
#include <bitset>
#include <utility>

const int MAX_V = 1000;

class Graph {
private:
    int V; 
    int E;
    // pair.first = destination vertex
    // pair.second = weight 
    std::vector<std::pair<int, int>> g[MAX_V]; 
    bool is_connected; 
    std::vector<int> dfs_result; 
    std::vector<int> bfs_result; 

    std::vector<int> bfs_engine(int start_idx) const {
        if (V == 0 || start_idx < 0 || start_idx >= V) {
            return {};
        }

        std::vector<int> traversal_result;
        traversal_result.reserve(V); 
        std::bitset<MAX_V> visited;
        std::queue<int> q;
        
        q.push(start_idx);
        visited.set(start_idx);

        while (!q.empty()) {
            int u_idx = q.front();
            q.pop();
            traversal_result.push_back(u_idx);

            for (const auto& edge : g[u_idx]) {
                int v_idx = edge.first;
                if (!visited.test(v_idx)) {
                    visited.set(v_idx);
                    q.push(v_idx);
                }
            }
        }
        return traversal_result;
    }

    void dfs_recursive(int u_idx, std::bitset<MAX_V>& visited) {
        visited.set(u_idx);
        dfs_result.push_back(u_idx);

        for (const auto& edge : g[u_idx]) {
            int v_idx = edge.first;
            if (!visited.test(v_idx)) {
                dfs_recursive(v_idx, visited);
            }
        }
    }

public:
    Graph(int v, int e) : V(v), E(e) {
        if (v >= MAX_V) {
            throw std::out_of_range("Invalid Input");
        }
    }

    void add_edge(int u, int v, int weight) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            std::cerr << "Invalid Input" << std::endl;
            return;
        }
        g[u].push_back({v, weight});
    }

    void add_edge(int u, int v) {
        add_edge(u, v, 1);
    }

    void init_is_connected() {
        if (V <= 1) {
            is_connected = true; 
            return;
        }
        std::vector<int> traversal = bfs_engine(0);
        is_connected = (traversal.size() == V);
    }

    void dfs(int start_node) {
        if (!is_connected) {
            std::cerr << "Not A Connectd Graph" << std::endl;
            return;
        }
        if (start_node < 0  || start_node >= V) {
            std::cerr << "Invalid Input" << std::endl;
            return;
        }

        dfs_result.clear();
        std::bitset<MAX_V> visited;
        dfs_recursive(start_node, visited);
    }

    void bfs(int start_node) {
        if (!is_connected) {
            std::cerr << "Not A Connected Graph" << std::endl;
            return;
        }
        if (start_node < 0 || start_node >= V) {
            std::cerr << "Invalid Input" << std::endl;
            return;
        }
        bfs_result = bfs_engine(start_node);
    }

    bool get_is_connected() const {
        return is_connected;
    }

    std::vector<int> get_dfs_result() const {
        return dfs_result;
    }

    std::vector<int> get_bfs_result() const {
        return bfs_result;
    }
};

#endif
