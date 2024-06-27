// C. Kefa and Park

// time limit per test2 seconds
// memory limit per test256 megabytes
// inputstandard input
// outputstandard output

// Kefa decided to celebrate his first big salary by going to the restaurant. He lives by an unusual park. The park is a rooted tree consisting of n vertices with the root at vertex 1. Vertex 1 also contains Kefa's house. Unfortunaely for our hero, the park also contains cats. Kefa has already found out what are the vertices with cats in them. The leaf vertices of the park contain restaurants. Kefa wants to choose a restaurant where he will go, but unfortunately he is very afraid of cats, so there is no way he will go to the restaurant if the path from the restaurant to his house contains more than m consecutive vertices with cats. Your task is to help Kefa count the number of restaurants where he can go.

// Input
// The first line contains two integers, n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ n) — the number of vertices of the tree and the maximum number of consecutive vertices with cats that is still ok for Kefa. The second line contains n integers a1, a2, ..., an, where each ai either equals to 0 (then vertex i has no cat), or equals to 1 (then vertex i has a cat). Next n - 1 lines contains the edges of the tree in the format "xi yi" (without the quotes) (1 ≤ xi, yi ≤ n, xi ≠ yi), where xi and yi are the vertices of the tree, connected by an edge. It is guaranteed that the given set of edges specifies a tree.

// Output
// A single integer — the number of distinct leaves of a tree the path to which from Kefa's home contains at most m consecutive vertices with cats.

// Examples
// inputCopy
// 4 1
// 1 1 0 0
// 1 2
// 1 3
// 1 4
// outputCopy
// 2
// inputCopy
// 7 1
// 1 0 1 1 0 0 0
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// outputCopy
// 2

// Note
// Let us remind you that a tree is a connected graph on n vertices and n - 1 edge. A rooted tree is a tree with a special vertex called root. In a rooted tree among any two vertices connected by an edge, one vertex is a parent (the one closer to the root), and the other one is a child. A vertex is called a leaf, if it has no children.
// Note to the first sample test:The vertices containing cats are marked red. The restaurants are at vertices 2, 3, 4. Kefa can't go only to the restaurant located at vertex 2.
// Note to the second sample test:The restaurants are located at vertices 4, 5, 6, 7. Kefa can't go to restaurants 6, 7.

//My original soln -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// //Global variables

// //2D vector representing the tree structure
// vector<vector<int>> tree;

// //Vector indicating whether each vertex has a cat
// vector<int> cats;

// //Max num of cats that Kefa is okay with
// int m;

// //Storing the count of leaf nodes
// //Where the path from Kefa's house to the leaf contains at most m consecutive vertices with cats
// //OR The num of restaurants Kefa can go
// int validLeaves;

// //Applying depth first search traversal
// //node is the current node
// //parent is the parent node
// void dfs(int node, int parent, int consecutiveCats)
// {
//     //If the current node has a cat
//     //Then increment consecutiveCats
//     if (cats[node])
//     {
//         consecutiveCats++;
//     }
//     else
//     {
//         //If the current node doesn't have a cat
//         //Reset consecutiveCats
//         consecutiveCats = 0;
//     }

//     //If the consecutiveCats count exceeds m
//     //Return without exploring further
//     if (consecutiveCats > m)
//     {
//         return;
//     }

//     //If the current node is a leaf
//     //AND
//     //ConsecutiveCats <= m
//     //Then increment validLeaves
//     if (tree[node].size() == 1 && node != 1)
//     {
//         validLeaves++; //Answer variable
//         return;
//     }

//     //Recursively exploring each child node
//     for (int child : tree[node])
//     {
//         if (child != parent)
//         {
//             //Recursive function
//             //Here
//             //child is the current node
//             //node is the parent node
//             dfs(child, node, consecutiveCats);
//         }
//     }
// }

// //Main function
// int main()
// {
//     //Num of vertices of the tree
//     int n;
//     cin >> n >> m;

//     //Applying 1-based indexing
//     tree.resize(n+1);
//     cats.resize(n+1);

//     //Array representing whether a vertex has cat or not
//     for(int i=1; i<=n; i++)
//     {
//         cin >> cats[i];
//     }

//     //Reading the edges of the tree
//     for (int i = 1; i < n; i++)
//     {
//         //Vertices of the tree, connected by an edge
//         int u, v;
//         cin >> u >> v;

//         tree[u].push_back(v);
//         tree[v].push_back(u);
//     }

//     //Num of restaurants he can go
//     validLeaves = 0;

//     //Performing DFS traversal starting from vertex 1 (Kefa's house)
//     dfs(1, -1, 0);

//     cout << validLeaves << endl;

//     return 0;
// }

//Alternate code(using linked list) -

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// struct Node
// {
//     bool hasCat;
//     Node* firstChild;
//     Node* nextSibling;

//     //Constructor
//     Node(bool cat = false, Node* child = nullptr, Node* sibling = nullptr) : hasCat(cat), firstChild(child), nextSibling(sibling) {}
// };

// //Max cats
// //Num of restaurants he can go(answer)
// int m, validLeaves;

// void dfs(Node* node, int consecutiveCats)
// {
//     if (node == nullptr)
//     {
//         return;
//     }

//     //If the current node has a cat, increment consecutiveCats
//     if (node->hasCat)
//     {
//         consecutiveCats++;
//     }
//     else
//     {
//         consecutiveCats = 0; //Reset consecutiveCats if the current node doesn't have a cat
//     }

//     //If the consecutiveCats count exceeds m, return without exploring further
//     if (consecutiveCats > m)
//     {
//         return;
//     }

//     //If the current node is a leaf, and consecutiveCats <= m, increment validLeaves
//     if (node->firstChild == nullptr)
//     {
//         validLeaves++;
//         return;
//     }

//     //Recursive DFS traversal for each child
//     for (Node* child = node->firstChild; child != nullptr; child = child->nextSibling)
//     {
//         dfs(child, consecutiveCats);
//     }
// }

// int main()
// {
//     //Vertices of the tree
//     int n;
//     cin >> n >> m;

//     //Resizing and initializing nodes
//     vector<Node*> nodes(n + 1);

//     //Creating nodes for the list
//     for (int i = 1; i <= n; i++)
//     {
//         int cat;
//         cin >> cat;

//         nodes[i] = new Node(cat == 1);
//     }

//     //Connect the nodes to form the linked list representation of the tree
//     //Num of edges = num of nodes - 1
//     for (int i=1; i<n; i++)
//     {
//         int u, v;
//         cin >> u >> v;

//         //Connect parent to child
//         if (nodes[u]->firstChild == nullptr)
//         {
//             nodes[u]->firstChild = nodes[v];
//         }
//         else
//         {
//             //Traverse the siblings to find the last sibling and append the new child
//             Node* temp = nodes[u]->firstChild;
//             while (temp->nextSibling != nullptr)
//             {
//                 temp = temp->nextSibling;
//             }

//             temp->nextSibling = nodes[v];
//         }
//     }

//     //Initializing
//     validLeaves = 0;

//     //Performing DFS traversal
//     dfs(nodes[1], 0);

//     cout << validLeaves << endl;

//     // Free the allocated memory
//     for (int i = 1; i <= n; i++)
//     {
//         delete nodes[i];
//     }

//     return 0;
// }

//Alternate soln -

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long long MAX_NODES = 228228;

struct Node
{
    int vertex;
    Node* next;
    Node(int v) : vertex(v), next(nullptr) {}
};

// Function to recursively explore the tree and count the valid leaves
void exploreTree(Node* current, int parent, int consecutiveCats, int maxConsecutiveCats, int& totalValidLeaves, int* cats)
{
    // If the number of consecutive cats exceeds the limit, return
    if (consecutiveCats > maxConsecutiveCats)
    {
        return;
    }

    // Check if the current node is a leaf node
    bool isLeaf = true;
    Node* child = current;
    while (child != nullptr)
    {
        if (child->vertex != parent)
        {
            isLeaf = false;
            exploreTree(child, current->vertex, consecutiveCats * cats[child->vertex] + cats[child->vertex], maxConsecutiveCats, totalValidLeaves, cats);
        }
        child = child->next;
    }

    // If the current node is a leaf node and the number of consecutive cats is within the limit, increment the total valid leaves
    if (isLeaf && current->vertex != 0)
    {
        totalValidLeaves++;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int cats[MAX_NODES];
    for (int i = 0; i < n; i++)
    {
        cin >> cats[i];
    }

    // Constructing the tree using linked lists
    Node* adjacencyList[MAX_NODES];
    for (int i = 0; i < n; i++)
    {
        adjacencyList[i] = nullptr;
    }

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--; // Adjusting 1-based indexing to 0-based indexing

        // Adding y as a child of x
        Node* newNode = new Node(y);
        newNode->next = adjacencyList[x];
        adjacencyList[x] = newNode;

        // Adding x as a child of y
        newNode = new Node(x);
        newNode->next = adjacencyList[y];
        adjacencyList[y] = newNode;
    }

    int totalValidLeaves = 0;
    exploreTree(adjacencyList[0], -1, cats[0], m, totalValidLeaves, cats);

    // Output the total number of valid leaves
    cout << totalValidLeaves << endl;

    // Freeing allocated memory
    for (int i = 0; i < n; i++)
    {
        Node* current = adjacencyList[i];
        while (current != nullptr)
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}
