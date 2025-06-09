#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <deque>
#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"

int main(int argc, const char * argv[]) {
    // Создаем граф на 9 вершинах
    ListGraph basicGraph(9);
    basicGraph.AddEdge(0, 2);
    basicGraph.AddEdge(0, 4);
    basicGraph.AddEdge(1, 3);
    basicGraph.AddEdge(1, 5);
    basicGraph.AddEdge(2, 3);
    basicGraph.AddEdge(2, 7);
    basicGraph.AddEdge(3, 6);
    basicGraph.AddEdge(4, 7);
    basicGraph.AddEdge(4, 8);
    basicGraph.AddEdge(5, 6);
    basicGraph.AddEdge(6, 8);
    basicGraph.AddEdge(7, 8);
    
    // Обход в ширину
    mainBFS(basicGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    // Обход в глубину
    mainDFS(basicGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    // Топологическая сортировка
    for (int v: topologicalSort(basicGraph)) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";
    
    // Преобразование в матричный граф
    MatrixGraph adjacencyGraph(basicGraph);
    
    mainBFS(adjacencyGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    mainDFS(adjacencyGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    for (int v: topologicalSort(adjacencyGraph)) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";
    
    // Преобразование в граф дуг
    ArcGraph edgeGraph(adjacencyGraph);
    
    mainBFS(edgeGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    mainDFS(edgeGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    for (int v: topologicalSort(edgeGraph)) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";
    
    // Преобразование в граф множеств
    SetGraph adjSetGraph(edgeGraph);
    
    mainBFS(adjSetGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    mainDFS(adjSetGraph, [](int v){ std::cout << v << " "; });
    std::cout << "\n";
    
    for (int v: topologicalSort(adjSetGraph)) {
        std::cout << v << " ";
    }
    std::cout << "\n\n";
    
    // Проверка размеров графов
    std::cout << "Basic graph vertices: " << basicGraph.VerticesCount() << "\n";
    std::cout << "Adjacency graph vertices: " << adjacencyGraph.VerticesCount() << "\n";
    std::cout << "Edge graph vertices: " << edgeGraph.VerticesCount() << "\n";
    std::cout << "Set graph vertices: " << adjSetGraph.VerticesCount() << "\n";
    int n;
    std::cin >> n;
    return 0;
}
