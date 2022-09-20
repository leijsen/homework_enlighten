#include<iostream>
#include<malloc.h>
using namespace std;
typedef int elemtype;
typedef struct Qlist{
    elemtype data;
    Qlist *next = NULL;
}Qlist;
void pop(Qlist *L, elemtype x){
    while(L->next){
        if(L->next->data == x){
            L->next = L->next->next;
            break;
        }
        else{
            L = L->next;
        }
    }
}
int main(){
    cout << "链表长度为：";
    int n;
    cin>>n; 
    cout << "初始链表为：";       
    Qlist *L = (Qlist*)malloc(sizeof(Qlist));
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
    cout << "将要删除的数字：";
    int d;
    cin>>d;
    pop(L, d);
    printf("删除后链表为：");
    while(L->next != NULL){
        cout << L->next->data << " ";
        L = L->next;
    }
    return 0;
}