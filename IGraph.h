struct IGraph {
    virtual ~IGraph() {}
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const = 0;
    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func) {
    std::queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        func(curr);
        
        for (int next: graph.GetNextVertices(curr)) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

void mainBFS(const IGraph &graph, const std::function<void(int)> &func) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        if (!visited[v]) {
            BFS(graph, v, visited, func);
        }
    }
}

void DFS(const IGraph &graph, int vertex, std::vector<bool> &visited, const std::function<void(int)> &func) {
    visited[vertex] = true;
    func(vertex);
    
    for (int next: graph.GetNextVertices(vertex)) {
        if (!visited[next]) {
            DFS(graph, next, visited, func);
        }
    }
}

void mainDFS(const IGraph &graph, const std::function<void(int)> &func) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        if (!visited[v]) {
            DFS(graph, v, visited, func);
        }
    }
}

void topoSort(const IGraph &graph, int vertex, std::vector<bool> &visited, std::deque<int> &sorted) {
    visited[vertex] = true;
    
    for (int next: graph.GetNextVertices(vertex)) {
        if (!visited[next]) {
            topoSort(graph, next, visited, sorted);
        }
    }
    
    sorted.push_front(vertex);
}

std::deque<int> topologicalSort(const IGraph &graph) {
    std::deque<int> sorted;
    std::vector<bool> visited(graph.VerticesCount(), false);
    
    for (int v = 0; v < graph.VerticesCount(); ++v) {
        if (!visited[v]) {
            topoSort(graph, v, visited, sorted);
        }
    }
    
    return sorted;
}
