struct ArcGraph : public IGraph {
private:
    std::vector<std::pair<int, int>> edges;
    int numVertices;

public:
    ArcGraph(int size) 
        : numVertices(size) {}
    
    ArcGraph(const IGraph &other) {
        numVertices = other.VerticesCount();
        for (int from = 0; from < numVertices; ++from) {
            std::vector<int> neighbors = other.GetNextVertices(from);
            for (int to : neighbors) {
                edges.push_back({from, to});
            }
        }
    }
    
    ~ArcGraph() override = default;
    
    void AddEdge(int from, int to) override {
        assert(from >= 0 && from < numVertices);
        assert(to >= 0 && to < numVertices);
        edges.push_back({from, to});
    }
    
    int VerticesCount() const override {
        return numVertices;
    }
    
    std::vector<int> GetNextVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < numVertices);
        std::vector<int> outgoing;
        
        for (const auto& [start, end] : edges) {
            if (start == vertex) {
                outgoing.push_back(end);
            }
        }
        return outgoing;
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < numVertices);
        std::vector<int> incoming;
        
        for (const auto& [start, end] : edges) {
            if (end == vertex) {
                incoming.push_back(start);
            }
        }
        return incoming;
    }
};
