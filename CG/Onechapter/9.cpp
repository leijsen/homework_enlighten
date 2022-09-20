#include<iostream>
#include<malloc.h>
using namespace std;
int n,m;
int a[10][10];
int xdir[4]={-1,1,0,0};
int ydir[4]={0,0,1,-1};
int q=0;
typedef struct Qlist{
    int x;
    int y;
    Qlist *next;
}Qlist;
Qlist *path = (Qlist *)malloc(sizeof(Qlist)), *temp;
int bfs(int si,int sj){
    if(a[si][sj]==2){
        return 1;
    }
    for(register int i=0;i<4;i++){
        if(si+xdir[i]>=0 && si+xdir[i]<n && sj+ydir[i]>=0 && sj+ydir[i]<m
        && a[si+xdir[i]][sj+ydir[i]] != -1){
            int newi = si+xdir[i];
            int newj = sj+ydir[i];
            a[si][sj] = -1;
            if(bfs(newi,newj)){
                Qlist *node = (Qlist *)malloc(sizeof(Qlist));
                node->x = newi;
                node->y = newj;
                node->next = path->next;
                path->next = node;
                return 1;
            }
        }
        a[si][sj] = 1;
    }
    return 0;
}
int main(){
    cin >> n >> m;
    int starti,startj, endi, endj;
    path->next = NULL;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[i][j] = -1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            if(a[i][j] == 0){
                starti = i;
                startj = j;
            }
            else if(a[i][j] == 2){
                endi = i;
                endj = j;
            }
        }
    }
    if(bfs(starti, startj)){
        cout<<"YES" << endl;
        cout << '('<< starti << ',' << startj << ')' ;
        while(path->next){
            cout << "->" << '('<< path->next->x << ',' << path->next->y << ')' ;
            path = path->next;
        }
    }
    else{
        cout<<"NO";
    }
}