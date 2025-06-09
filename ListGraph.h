struct ListGraph: public IGraph {
private:
    std::vector<std::vector<int>> edges;

public:
    ListGraph(int vertexCount) 
        : edges(vertexCount) {}
    
    ListGraph(const IGraph& other) {
        edges.resize(other.VerticesCount());
        for (int vertex = 0; vertex < other.VerticesCount(); ++vertex) {
            edges[vertex] = other.GetNextVertices(vertex);
        }
    }
    
    ~ListGraph() override = default;
    
    void AddEdge(int from, int to) override {
        assert(from >= 0 && from < edges.size());
        assert(to >= 0 && to < edges.size());
        edges[from].push_back(to);
    }
    
    int VerticesCount() const override {
        return static_cast<int>(edges.size());
    }
    
    std::vector<int> GetNextVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < edges.size());
        return edges[vertex];
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < edges.size());
        std::vector<int> inEdges;
        
        for (int i = 0; i < edges.size(); ++i) {
            for (int j : edges[i]) {
                if (j == vertex) {
                    inEdges.push_back(i);
                    break;
                }
            }
        }
        return inEdges;
    }
};
