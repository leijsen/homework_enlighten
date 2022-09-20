#include<bits/stdc++.h>
using namespace std;
typedef struct L{
    int data;
    L *next;
}L;
L *Lnode = (L*)malloc(sizeof(L));
void print(){
    L *temp = (L*)malloc(sizeof(L));
    temp = Lnode->next;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
void pop(int minn, int maxn){
    L *temp= (L*)malloc(sizeof(L));
    L *front = (L*)malloc(sizeof(L));
    temp = Lnode->next;
    front = Lnode;
    while(temp!=NULL){
        if(temp->data > minn){
            while(front->next != temp){
                front = front->next;
            }
            while(temp && temp->data < maxn){
                temp=temp->next;
            }
            L *q = (L*)malloc(sizeof(L));
            q = front;
            while(q->next != temp){
                q = q->next;
            }
            q->next = NULL;
            q = front->next;
            front->next = temp;
            while(q){
                front = q->next;
                free(q);
                q = front;
            }
            break;
        }
        else{
            temp = temp->next;
        }
    }
}
void create(int length){
    int a;
    L* t = (L*)malloc(sizeof(L));
    t = Lnode;
    while(length--){
        cin>>a;
        L* node = (L*)malloc(sizeof(L));
        node->data = a;
        t->next = node;
        node->next = NULL;
        t = node;
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){    
        int length;
        cin >> length;
        create(length);
        int q;
        cin >> q;
        while(q--){
            int n;
            cin>>n;
            if(n==1){
                print();
            }
            else{
                int minn,maxn;
                cin>>minn>>maxn;
                pop(minn,maxn);
            }
        }
    }
    return 0;
}