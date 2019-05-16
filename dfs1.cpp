#include <iostream>
#include <vector>
#include <list>

class G{
    public:
        int m_size;
        std::vector< std::list<int> > m_Adj;
        void addEdge(int source, int dest);
        G(int size);
        void getEdges();
};

G::G(int size): m_size{size}, m_Adj{ std::vector<std::list<int>>(size)} {
    std::cout<<"nodes are created \n"; 
}

void G::addEdge(int s, int d){
    m_Adj[s].push_back(d); 
}

void G::getEdges(){
    std::cout<<"edges are: \n"; 
    for(int i = 0; i < m_size; i++){
        for(auto it = m_Adj[i].begin(); it != m_Adj[i].end(); it++){
            std::cout<< i <<" "<<*it <<'\n';
        }
    }
}

void dfs_visit(int start, G& q1, std::vector<bool>& used){
    std::cout << start <<' ';
    used[start] = true; 

    for(auto it = q1.m_Adj[start].begin(); it != q1.m_Adj[start].end(); it++){
        if(!used[*it]){
            dfs_visit(*it, q1, used);
        }
    }
}

void dfs(G& q1){
    std::vector<bool> used(q1.m_size);
    //initialization
    for(auto it = used.begin(); it != used.end(); it++){
        *it = false;
    }
    std::cout<<"dfs travesal: ";
        dfs_visit(0, q1, used);
}

int main(){
    
    G q1 = G(6); 
    q1.addEdge(0, 1); 
    q1.addEdge(0, 2);
    q1.addEdge(2, 3);
    q1.addEdge(3, 4);
    q1.addEdge(4, 2);
    q1.addEdge(1, 4);
    q1.addEdge(4, 5);
    q1.getEdges();

    dfs(q1);
    return 0; 
}