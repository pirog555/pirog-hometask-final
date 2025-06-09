struct SetGraph: public IGraph {
private:
    std::vector<std::multiset<int>> adjacencySet;

public:
    explicit SetGraph(int vertexCount) 
        : adjacencySet(vertexCount) {}
    
    explicit SetGraph(const IGraph& other) {
        adjacencySet.resize(other.VerticesCount());
        
        for (int vertex = 0; vertex < other.VerticesCount(); ++vertex) {
            std::vector<int> neighbors = other.GetNextVertices(vertex);
            adjacencySet[vertex].insert(neighbors.begin(), neighbors.end());
        }
    }
    
    ~SetGraph() override = default;
    
    void AddEdge(int from, int to) override {
        assert(from >= 0 && from < adjacencySet.size());
        assert(to >= 0 && to < adjacencySet.size());
        adjacencySet[from].insert(to);
    }
    
    int VerticesCount() const override {
        return static_cast<int>(adjacencySet.size());
    }
    
    std::vector<int> GetNextVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < adjacencySet.size());
        return std::vector<int>(adjacencySet[vertex].begin(), adjacencySet[vertex].end());
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < adjacencySet.size());
        std::vector<int> incomingVertices;
        
        for (int from = 0; from < adjacencySet.size(); ++from) {
            if (adjacencySet[from].count(vertex) > 0) {
                incomingVertices.push_back(from);
            }
        }
        
        return incomingVertices;
    }
};
