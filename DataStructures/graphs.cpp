#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Edge{
public:
    int src;
    int dest;
    int wei;
    Edge(int source,int destination,int weight){
        src = source;
        dest = destination;
        wei = weight;        
    }
};

class Edgelessthan{
public:
    bool operator()(Edge a,Edge b){
        if(a.wei < b.wei){
            return true;
        }
        return false;
    }
};

class Edgegrethan{
public:
    bool operator()(Edge a,Edge b){
        if(a.wei > b.wei){
            return true;
        }
        return false;
    }
};

class Edgeequal{
public:
    bool operator()(Edge a,Edge b){
        if(a.src ==  b.src and a.dest == b.dest and a.wei == b.wei){
            return true;
        }
        return false;
    }
};

Edgelessthan ls;
Edgegrethan gr;
Edgeequal eq;

unordered_map<int,int>parent;
unordered_map<int,int>size;

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    parent[v] = find_set(parent[v]);
    return parent[v];
}

void union_set(int a,int b){
    if(parent.find(a) == parent.end()){
        make(a);
    }
    if(parent.find(b) == parent.end()){
        make(b);
    }
    a = find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a] < size[b]){
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        size[a]+=size[b];
    }
}

unordered_map<int,vector<Edge>> insert_und_edge(unordered_map<int,vector<Edge>>umap,int src,int dest,int wei){
    if(src == dest){
        umap[src];
    }
    else{
        Edge ed = Edge(src,dest,wei);
        Edge de = Edge(dest,src,wei);
        umap[src].push_back(ed);
        umap[dest].push_back(de);
    }
    return umap;
}

unordered_map<int,vector<Edge>> insert_dir_edge(unordered_map<int,vector<Edge>>umap,int src,int dest,int wei){
    if(src == dest){
        umap[src];
    }
    else{
        Edge ed = Edge(src,dest,wei);
        umap[src].push_back(ed);
        if(umap[dest].size() == 0){
            umap[dest];
        }
    }
    return umap;
}

unordered_map<int,vector<Edge>> delete_und_edge(unordered_map<int,vector<Edge>>umap,int src,int dest){
    for(int i=0;i<umap[src].size();i++){
        if(umap[src][i].dest == dest){
            umap[src].erase(i+umap[src].begin());
            break;
        }
    }
    for(int i=0;i<umap[dest].size();i++){
        if(umap[dest][i].dest == src){
            umap[dest].erase(i+umap[dest].begin());
            break;
        }
    }
    return umap;

}

unordered_map<int,vector<Edge>> delete_dir_edge(unordered_map<int,vector<Edge>>umap,int src,int dest){
    for(int i=0;i<umap[src].size();i++){
        if(umap[src][i].dest == dest){
            umap[src].erase(i+umap[src].begin());
            break;
        }
    }
    return umap;

}

unordered_map<int,vector<Edge>> del_und_vertex(unordered_map<int,vector<Edge>>umap,int vertex){
      for(int i=0;i<umap[vertex].size();i++){
        int src = umap[vertex][i].dest;
        for(int j=0;j<umap[src].size();j++){
            if(umap[src][j].dest == vertex){
                umap[src].erase(j+umap[src].begin());
                break;
            }
        }
      }
      umap.erase(vertex);
      return umap;
}

bool is_cyclic(unordered_map<int,vector<Edge>>umap){
    unordered_map<int,bool>visited_local;
    unordered_map<int,bool>visited_global;
    for(auto i=umap.begin();i!=umap.end();i++){
            visited_global[i->first] = false;
    }
    for(auto i=visited_global.begin();i!=visited_global.end();i++){
        for(auto j=umap.begin();j!=umap.end();j++){
            visited_local[j->first] = false;
        }
        if(visited_global[i->first] == false){
            vector<int>v{i->first};
            visited_local[i->first] = true;
            visited_global[i->first]  = true;
            while(v.size()!=0){
                int temp = v[v.size()-1];
                v.pop_back();
                for(int i=0;i<umap[temp].size();i++){
                    if(visited_local[umap[temp][i].dest]){
                        return true;
                    }
                    else{
                        v.push_back(umap[temp][i].dest);
                        visited_local[umap[temp][i].dest] = true;
                        visited_global[umap[temp][i].dest] = true;
                    }
                }
            }
        }
        
    }
    return false;
}

bool is_connected(unordered_map<int,vector<Edge>>umap){
    for(auto i=umap.begin();i!=umap.end();i++){
        vector<int>v;
        vector<int>ans;
        v.push_back(i->first);
        ans.push_back(i->first);
        while(v.size()!=0){
            int temp = v[v.size()-1];
            v.pop_back();
            for(int j=0;j<umap[temp].size();j++){
                if(  count(ans.begin(),ans.end(),umap[temp][j].dest) == 0  ){
                    ans.push_back(umap[temp][j].dest);
                    v.push_back(umap[temp][j].dest);
                }
            }
        }
        if(ans.size() == umap.size()){
            return true;
        }

    }
    return false;
}

void dfs(unordered_map<int,vector<Edge>>umap,int source,unordered_map<int,bool>visited){
    vector<int>v{source};
    visited[source] = true;
    while(v.size()!=0){
        int temp = v[v.size()-1];
        v.pop_back();
        cout<<temp<<" ";
        for(int i=0;i<umap[temp].size();i++){
            if(visited[umap[temp][i].dest] == false){
                v.push_back(umap[temp][i].dest);
                visited[umap[temp][i].dest] = true;
            }
        }
    }
    cout<<endl;
    for(auto i=visited.begin();i!=visited.end();i++){
        if(i->second == false){
            cout<<"Disconnected tree"<<endl;
            dfs(umap,i->first,visited);
            break;
        }
    }
}

void bfs(unordered_map<int,vector<Edge>>umap,int source,unordered_map<int,bool>visited){
    queue<int>q;
    q.push(source);
    visited[source] = true;
    while(q.size()!=0){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(int i=0;i<umap[temp].size();i++){
            if(visited[umap[temp][i].dest] == false){
                q.push(umap[temp][i].dest);
                visited[umap[temp][i].dest] = true;
            }
        }
    }
    cout<<endl;
    for(auto i=visited.begin();i!=visited.end();i++){
        if(i->second == false){
            cout<<"Disconnected tree"<<endl;
            bfs(umap,i->first,visited);
            break;
        }
    }
}

int indegree(unordered_map<int,vector<Edge>>umap,int vertex){
    int out = 0;
    for(auto i = umap.begin();i!=umap.end();i++){
        for(int j = 0;j<(i->second).size();j++){
            if( (i->second)[j].dest == vertex ){
                out++;
            }
        }
    }
    return out;
}

int outdegree(unordered_map<int,vector<Edge>>umap,int vertex){
    return umap[vertex].size();
}

int nof_vertex(unordered_map<int,vector<Edge>>umap){
    return umap.size();
}

int nof_edges(unordered_map<int,vector<Edge>>umap){
    int out = 0;
    for(auto i=umap.begin();i!=umap.end();i++){
        out+=(i->second).size();
    }
    return out;
}

void display(unordered_map<int,vector<Edge>>umap){
    for(auto i = umap.begin();i!=umap.end();i++){
        cout<<i->first<<" --> ";
        for(int j=0;j<(i->second).size();j++){
            cout<<(i->second)[j].dest<<" ";
        }
        cout<<endl;
    }
}

vector<int>toposort_d;
void topo_sort_d(unordered_map<int,vector<Edge>>umap,int source,unordered_map<int,bool>visited){
    if(is_cyclic(umap)){
        cout<<" the given graph is cyclic. So topological sort doesn't exists."<<endl;
        return ;
    }
    else{
        vector<int>v{source};
        visited[source] = true;
        while(v.size()!=0){
            int temp = v[v.size()-1];
            int ct = 0;
            for(int i=0;i<umap[temp].size();i++){
                if(visited[umap[temp][i].dest] == false){
                    v.push_back(umap[temp][i].dest);
                    visited[umap[temp][i].dest] = true;
                    ct++;
                }
            }
            if(ct == 0){
                v.pop_back();
                toposort_d.push_back(temp);
            }
        }
        for(auto i=visited.begin();i!=visited.end();i++){
            if(i->second == false){
                topo_sort_d(umap,i->first,visited);
                break;
            }
        }    
    }
    while(toposort_d.size()!=0){
                    cout<<toposort_d[toposort_d.size()-1]<<" ";
                    toposort_d.pop_back();
    }

}

/*void mst(unordered_map<int,vector<Edge>>umap){
    for(auto i=umap.begin();i!=umap.end();i++){
        vector<vector<int>>v;
        v.push_back({i->first});
        while(v.size()!=0){
            vector<int>temp_v = v[v.size()-1];
            int temp = temp_v[temp_v.size()-1];
            v.pop_back();
            int ct = 0;
            for(int j=0;j<umap[temp].size();j++){
                if(count(temp_v.begin(),temp_v.end(),umap[temp][j].dest) == 0){
                    ct++;
                    vector<int>foo = temp_v;
                    foo.push_back(umap[temp][j].dest);
                    v.push_back(foo);
                }
            }
            if(ct == 0){
                for(int k = 0;k<temp_v.size();k++){
                    cout<<temp_v[k]<<" ";
                }
                cout<<endl;
            }
        }
    }
    
}*/

void kruskal(unordered_map<int,vector<Edge>>umap){
    list<Edge>edge_v;
    for(auto i = umap.begin();i!=umap.end();i++){
        for(int j=0;j<(i->second).size();j++){
            edge_v.push_back((i->second)[j]);
        }
    }
    edge_v.sort(ls);                                                            // Sorting the edges in the order of their weights
    int i=0;
    int cost = 0;
    while(edge_v.size()!=0){
        Edge ed = edge_v.front();
        edge_v.pop_front();
        int u = ed.src;
        int v = ed.dest;
        if(parent.find(u) == parent.end() or parent.find(v) == parent.end()){
            union_set(u,v);
            cout << " src : "<<u<<"  dest : "<<v<<" edge-weight : "<<ed.wei<<endl;
            cost +=ed.wei;
            i++;
        }
        else if(find_set(u) != find_set(v)){
            union_set(u,v);
            cout << " src : "<<u<<"  dest : "<<v<<" edge-weight : "<<ed.wei<<endl;
            cost+=ed.wei;
            i++;
        }
    }
    cout<<" cost of the mst is : "<<cost<<endl;
    parent.clear();
    size.clear();
}

void prims(unordered_map<int,vector<Edge>>umap,int source){
    list<Edge>edge_v;
    int out = 0;
    int i=0;
    int temp = source;
    for(int j=0;j<umap[temp].size();j++){
        edge_v.push_back(umap[temp][j]);
    }
    while(edge_v.size()!=0){
        edge_v.sort(ls);
        Edge ed = edge_v.front();
        edge_v.pop_front();
        int u = ed.src;
        int v = ed.dest;
        int we = ed.wei;
        if(parent.find(u) == parent.end() or parent.find(v) == parent.end()){
            union_set(u,v);
            out+=we;
            temp = v;
            for(int j=0;j<umap[temp].size();j++){
                edge_v.push_back(umap[temp][j]);
            }
            cout << " src : "<<u<<"  dest : "<<v<<" edge-weight : "<<we<<endl;
        }
        else if(find_set(u) != find_set(v)){
            union_set(u,v);
            out+=we;
            temp = v;
            for(int j=0;j<umap[temp].size();j++){
                edge_v.push_back(umap[temp][j]);
            }
            cout << " src : "<<u<<"  dest : "<<v<<" edge-weight : "<<we<<endl;
        }
        
    }
    cout<<" cost of the mst is : "<<out<<endl;
}

void dijkstra(unordered_map<int,vector<Edge>>umap,int source){
    unordered_map<int,int>dist;
    unordered_map<int,vector<int>>path;
    for(auto i=umap.begin();i!=umap.end();i++){
        if(i->first == source){
            dist[i->first] = 0;
            path[i->first].push_back(i->first);
        }
        else{
            dist[i->first] = numeric_limits<int>::max();
        }
    }
    set<pair<int,int>>s;
    s.insert({0,source});
    int i=0;
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        int temp = x.second;
        for(int j=0;j<umap[temp].size();j++){
            //if it lies in vert compare the lengths
            //else update the length
            int len = dist[temp]+umap[temp][j].wei;
            if(len < dist[umap[temp][j].dest]){
                s.erase({dist[umap[temp][j].dest],umap[temp][j].dest});
                dist[umap[temp][j].dest] = len;
                s.insert({dist[umap[temp][j].dest],umap[temp][j].dest});
                vector<int>too = path[temp];
                too.push_back(umap[temp][j].dest);
                path[umap[temp][j].dest] = too;
            }
        }
    }
    for(auto j=dist.begin();j!=dist.end();j++){
        if(j->second == numeric_limits<int>::max()){
            cout<<" "<<j->first<<" is not reachable from "<<source<<endl;
        }
        else{
            cout<<" Distance of "<<j->first<<" from "<<source<<" is : "<<j->second<<" : ";
            for(int k=0;k<path[j->first].size();k++){
                cout<<path[j->first][k]<<" ";
            }
            cout<<endl;
        }
        
    }
    cout<<endl;
}

int main(){
    
    /*unordered_map<int,vector<Edge>>und_graph;
    und_graph = insert_und_edge(und_graph,0,1,0);
    und_graph = insert_und_edge(und_graph,0,4,0);
    und_graph = insert_und_edge(und_graph,1,4,0);
    und_graph = insert_und_edge(und_graph,1,3,0);
    und_graph = insert_und_edge(und_graph,1,2,0);
    und_graph = insert_und_edge(und_graph,2,3,0);
    und_graph = insert_und_edge(und_graph,3,4,0);
    und_graph = insert_und_edge(und_graph,7,8,0);
    display(und_graph);
    unordered_map<int,bool>visited;
    for(auto i=und_graph.begin();i!=und_graph.end();i++){
        visited[i->first] = false;
    }
    cout<<"dfs: ";
    dfs(und_graph,0,visited);
    cout<<"bfs : ";
    bfs(und_graph,0,visited);*/
    
    /*unordered_map<int,vector<Edge>>dir_graph;

    dir_graph = insert_dir_edge(dir_graph,5,11,0);
    dir_graph = insert_dir_edge(dir_graph,7,11,0);
    dir_graph = insert_dir_edge(dir_graph,7,8,0);
    dir_graph = insert_dir_edge(dir_graph,3,8,0);
    dir_graph = insert_dir_edge(dir_graph,3,10,0);
    dir_graph = insert_dir_edge(dir_graph,11,2,0);
    dir_graph = insert_dir_edge(dir_graph,11,10,0);
    dir_graph = insert_dir_edge(dir_graph,11,9,0);
    */
    
    unordered_map<int,vector<Edge>>graph;                                       //initializing the graph
    graph = insert_und_edge(graph,1,2,5);
    graph = insert_und_edge(graph,3,4,2);
    graph = insert_und_edge(graph,1,3,9);
    graph = insert_und_edge(graph,2,4,6);
    graph = insert_und_edge(graph,4,5,5);
    graph = insert_und_edge(graph,5,6,10);
    graph = insert_und_edge(graph,6,7,7);
    graph = insert_und_edge(graph,5,8,1);
    graph = insert_und_edge(graph,8,7,1);
    
    unordered_map<int,bool>visited;                                             
    list<Edge>edge_v;                                                           //initializing visited map and storing edges
    for(auto i=graph.begin();i!=graph.end();i++){
        visited[i->first] = false;
        for(int j=0;j<(i->second).size();j++){
            edge_v.push_back((i->second)[j]);
        }
    }
    
    edge_v.sort(ls);
    cout<<"edges in the asceding order of their weights : "<<endl;              //Sorting the edges based on their weights
    for (auto k= edge_v.begin();k!=edge_v.end();k++) {
        cout << " src : "<<(*k).src<<"  dest : "<<(*k).dest<<" edge-weight : "<<(*k).wei<<endl;
    }

    cout<<"no.of vertex in the graph : "<<nof_vertex(graph)<<endl;              //No.of vertex and edges
    cout<<"no.of edges in the graph : "<<nof_edges(graph)<<endl;
    
    //cyclic
    if(is_cyclic(graph)){
        cout<<"The graph is cyclic"<<endl;
    }
    else{
        cout<<"The graph is acyclic"<<endl;
    }

    //connected
    if(is_connected(graph)){
        cout<<"The graph is connected"<<endl;
    }
    else{
        cout<<"The graph is not connected"<<endl;
    }

    display(graph);

    cout<<"topological sort : ";
    topo_sort_d(graph,1,visited);                                               // Topological sort
    cout<<endl;

    cout<<"dfs: ";                                                              // DFS
    dfs(graph,1,visited);
    cout<<endl;

    cout<<"bfs : ";                                                             // BFS
    bfs(graph,1,visited);
    cout<<endl;
    // Disjoint Set Union                           
    /*make(1);
    make(2);
    make(3);
    make(4);
    make(5);
    make(6);
    make(7);
    union_set(1,3);
    union_set(2,4);
    union_set(4,6);
    union_set(2,3);
    union_set(7,3);
    for(auto i=parent.begin();i!=parent.end();i++){
        cout<<"parent of "<<i->first<<" is : "<<i->second<<endl;
    }*/
    
    cout<<"MST using Kruskal Algorithm : "<<endl;
    kruskal(graph);                                                             // Kruskal Algorithm
    cout<<endl;

    cout<<"MST using Prims Algorithm : "<<endl;
    prims(graph,1);                                                             // Prims Algorithm
    cout<<endl;

    cout<<"Dijkstra Algorithm : "<<endl;
    dijkstra(graph,1);

    return 0;
}