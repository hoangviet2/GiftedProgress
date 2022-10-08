#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define N 3
#define M 4

class Node{
public:
    char s;
    unordered_map<char,Node*> children;
    // word until node:
    string word;
    bool isTerminal;
    Node(char s){
        this->s = s;
        isTerminal = 0;
        word = "";
    }
};

class Trie{
public:
    Node *root;

    Trie (){
        root = new Node('\0');
    }

    void addWord(string word){
        Node *temp = root;
        for(auto ch:word){
            if(temp->children.count(ch) == 0){
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        // last node
        temp->isTerminal = true;
        temp->word = word;
    }
};

void DFS(char board[N][M], Node *node,int i,int j,bool visited[][M], unordered_set<string> &output){
    // base case
    char ch = board[i][j];
    if(node->children.count(ch) == 0){
        return;
    }

    visited[i][j] = 1;
    node = node->children[ch];


    if(node->isTerminal){
        output.insert(node->word);
    }

    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};

    for(int k=0;k<8;++k){
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(ni>=0 && nj>=0 && ni<N && nj<M && !visited[ni][nj]){
            DFS(board,node,ni,nj,visited,output);
        }
    }
    //
    visited[i][j] = false;
    return;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string words[n];
    for(int i=0;i<n;++i){
        cin>>words[i];
    }
    char maps[N][M] = { {'S' ,'E' ,'R','T'} ,
                       {'U' ,'N' ,'K','S'} ,
                       {'T' ,'C' ,'A','T'} };

    // Trie
    Trie T;
    for(auto w:words){
        T.addWord(w);
    }

    unordered_set<string> output;

    bool visited[N][M] = {0};

    // DFS
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            DFS(maps,T.root,i,j,visited,output);
        }
    }
    for(auto words:output){
        cout<<words<<"\n";
    }
    return 0;
}
