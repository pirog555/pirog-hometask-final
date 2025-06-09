struct MatrixGraph: public IGraph {
private:
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    MatrixGraph(int vertexCount) 
        : adjacencyMatrix(vertexCount, std::vector<int>(vertexCount, 0)) {}
    
    MatrixGraph(const IGraph& other) {
        int size = other.VerticesCount();
        adjacencyMatrix.resize(size, std::vector<int>(size, 0));
        
        for (int from = 0; from < size; ++from) {
            std::vector<int> neighbors = other.GetNextVertices(from);
            for (int to : neighbors) {
                adjacencyMatrix[from][to] = 1;
            }
        }
    }
    
    ~MatrixGraph() override = default;
    
    void AddEdge(int from, int to) override {
        assert(from >= 0 && from < adjacencyMatrix.size());
        assert(to >= 0 && to < adjacencyMatrix.size());
        adjacencyMatrix[from][to] = 1;
    }
    
    int VerticesCount() const override {
        return static_cast<int>(adjacencyMatrix.size());
    }
    
    std::vector<int> GetNextVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < adjacencyMatrix.size());
        std::vector<int> neighbors;
        
        for (int i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[vertex][i]) {
                neighbors.push_back(i);
            }
        }
        
        return neighbors;
    }
    
    std::vector<int> GetPrevVertices(int vertex) const override {
        assert(vertex >= 0 && vertex < adjacencyMatrix.size());
        std::vector<int> neighbors;
        
        for (int i = 0; i < adjacencyMatrix.size(); ++i) {
            if (adjacencyMatrix[i][vertex]) {
                neighbors.push_back(i);
            }
        }
        
        return neighbors;
    }
};
