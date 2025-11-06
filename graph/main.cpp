#include <iostream>
#include <vector>
#include <string>
#include "graph.hpp" // 确保 Graph.hpp 和 main.cpp 在同一个目录下

// 辅助函数，用于打印遍历结果
void print_traversal(const std::string& name, const std::vector<int>& result) {
    std::cout << name << " 遍历结果: ";
    if (result.empty()) {
        std::cout << "(空)";
    } else {
        for (int node : result) {
            std::cout << node << " ";
        }
    }
    std::cout << std::endl;
}

// 主测试函数
void run_tests() {
    // ===================================================================
    // 测试 1: 连通图 (使用双向边模拟无向图)
    // ===================================================================
    std::cout << "--- 测试 1: 连通图 ---" << std::endl;
    Graph g1(6, 7); // 6个顶点(0-5), 7对边
    // 添加双向边来模拟无向图
    g1.add_edge(0, 1); g1.add_edge(1, 0);
    g1.add_edge(0, 2); g1.add_edge(2, 0);
    g1.add_edge(1, 3); g1.add_edge(3, 1);
    g1.add_edge(2, 3); g1.add_edge(3, 2);
    g1.add_edge(2, 4); g1.add_edge(4, 2);
    g1.add_edge(3, 5); g1.add_edge(5, 3);
    g1.add_edge(4, 5); g1.add_edge(5, 4);

    g1.init_is_connected();
    if (g1.get_is_connected()) {
        std::cout << "状态: 图 g1 被正确识别为连通图。" << std::endl;

        // 从节点 0 开始遍历
        std::cout << "\n* 从节点 0 开始遍历:" << std::endl;
        g1.bfs(0);
        print_traversal("BFS", g1.get_bfs_result());
        g1.dfs(0);
        print_traversal("DFS", g1.get_dfs_result());

        // 从节点 5 开始遍历
        std::cout << "\n* 从节点 5 开始遍历:" << std::endl;
        g1.bfs(5);
        print_traversal("BFS", g1.get_bfs_result());
        g1.dfs(5);
        print_traversal("DFS", g1.get_dfs_result());
    } else {
        std::cout << "错误: 图 g1 未被识别为连通图。" << std::endl;
    }
    std::cout << "--------------------------------\n" << std::endl;

    // ===================================================================
    // 测试 2: 非连通图
    // ===================================================================
    std::cout << "--- 测试 2: 非连通图 ---" << std::endl;
    Graph g2(5, 3); // 5个顶点(0-4), 两个连通分量: {0,1,2} 和 {3,4}
    g2.add_edge(0, 1); g2.add_edge(1, 0);
    g2.add_edge(1, 2); g2.add_edge(2, 1);
    g2.add_edge(3, 4); g2.add_edge(4, 3);

    g2.init_is_connected();
    if (!g2.get_is_connected()) {
        std::cout << "状态: 图 g2 被正确识别为非连通图。" << std::endl;
        // 尝试在非连通图上调用遍历函数
        std::cout << "尝试调用 bfs(0) (预期输出错误信息):" << std::endl;
        g2.bfs(0);
        std::cout << "尝试调用 dfs(3) (预期输出错误信息):" << std::endl;
        g2.dfs(3);
    } else {
        std::cout << "错误: 图 g2 未被识别为非连通图。" << std::endl;
    }
    std::cout << "--------------------------------\n" << std::endl;

    // ===================================================================
    // 测试 3: 带权有向图
    // ===================================================================
    std::cout << "--- 测试 3: 带权有向图 ---" << std::endl;
    Graph g3(4, 5); // 4个顶点(0-3)
    g3.add_edge(0, 1, 10); // 0 -> 1 (权10)
    g3.add_edge(0, 2, 5);  // 0 -> 2 (权5)
    g3.add_edge(1, 2);     // 1 -> 2 (默认权1)
    g3.add_edge(1, 3, 8);  // 1 -> 3 (权8)
    g3.add_edge(2, 3, 2);  // 2 -> 3 (权2)
    
    // 对于有向图，连通性检查的是弱连通
    g3.init_is_connected();
    std::cout << "状态: 有向图 g3 的连通性为: " 
              << (g3.get_is_connected() ? "连通" : "非连通") << std::endl;
    if (g3.get_is_connected()){
        std::cout << "从节点 0 开始遍历 (只关心连通性，不关心权重):" << std::endl;
        g3.bfs(0);
        print_traversal("BFS", g3.get_bfs_result());
        g3.dfs(0);
        print_traversal("DFS", g3.get_dfs_result());
    }
    std::cout << "--------------------------------\n" << std::endl;


    // ===================================================================
    // 测试 4: 边界条件和无效输入
    // ===================================================================
    std::cout << "--- 测试 4: 边界条件和无效输入 ---" << std::endl;
    // 单顶点图
    Graph g4(1, 0);
    g4.init_is_connected();
    std::cout << "状态: 单顶点图连通性: " << (g4.get_is_connected() ? "连通" : "非连通") << std::endl;
    g4.bfs(0);
    print_traversal("BFS (单顶点)", g4.get_bfs_result());

    // 空图
    Graph g5(0, 0);
    g5.init_is_connected();
    std::cout << "状态: 空图连通性: " << (g5.get_is_connected() ? "连通" : "非连通") << std::endl;

    // 无效输入
    std::cout << "\n测试无效输入 (预期输出错误信息):" << std::endl;
    g1.add_edge(0, 99); // 顶点99越界
    g1.bfs(10);      // 起始节点10越界
    g1.dfs(-1);      // 起始节点-1越界
    std::cout << "--------------------------------\n" << std::endl;

    // ===================================================================
    // 测试 5: 异常处理 (顶点数超过 MAX_V)
    // ===================================================================
    std::cout << "--- 测试 5: 异常处理 ---" << std::endl;
    try {
        std::cout << "尝试创建顶点数超过 " << MAX_V << " 的图..." << std::endl;
        Graph g_large(MAX_V + 1, 0);
    } catch (const std::out_of_range& e) {
        std::cout << "成功捕获异常: " << e.what() << std::endl;
    }
    std::cout << "--------------------------------\n" << std::endl;
}

int main() {
    run_tests();
    return 0;
}
