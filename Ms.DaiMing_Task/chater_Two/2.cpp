#include<iostream>
#include<malloc.h>
using namespace std;
typedef int elemtype;
typedef struct Qlist{
    elemtype data;
    Qlist *next;
}Qlist;
Qlist *L = (Qlist*)malloc(sizeof(Qlist));
void creat(int n){
    Qlist *s = (Qlist*)malloc(sizeof(Qlist));
    s = L;
    while(n--){
        int a;
        cin>>a;
        Qlist *m = (Qlist*)malloc(sizeof(Qlist));
        m->data = a;
        m->next = NULL;
        s->next = m;
        s = m;
    }
}
void pop(Qlist *L, elemtype x){
    Qlist *temp = (Qlist*)malloc(sizeof(Qlist));
    temp = L;
    while(temp->next){
        if(temp->next->data == x){
            temp->next = temp->next->next;
            break;
        }
        else{
            temp = temp->next;
        }
    }
}
void insert(elemtype x, elemtype e){
    Qlist *temp =(Qlist*)malloc(sizeof(Qlist));
    temp = L;
    while(temp->next){
        if(temp->next->data == x){
            Qlist *m = (Qlist*)malloc(sizeof(Qlist));
            m->data = e;
            m->next = temp->next;
            temp->next = m;
            break;
        }
        else{
            temp = temp->next;
        }
    }
}
int main(){
    cout << "链表长度为：";
    int n;
    cin>>n;
    cout << "初始链表为：";
    creat(n);
    
    // cout << "将要删除的数字：";
    // int d;
    // cin>>d;
    // pop(L, d);
    // printf("删除后链表为：");
    
    cout << "值为x的结点,插入值为e为：";
    int x,e;
    cin >> x >> e;
    insert(x, e);

    cout << "最终链表样式：";
    while(L->next != NULL){
        cout << L->next->data << " ";
        L = L->next;
    }
    return 0;
}