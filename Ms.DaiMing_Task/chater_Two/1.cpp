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
    cout << "������Ϊ��";
    int n;
    cin>>n; 
    cout << "��ʼ����Ϊ��";       
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
    cout << "��Ҫɾ�������֣�";
    int d;
    cin>>d;
    pop(L, d);
    printf("ɾ��������Ϊ��");
    while(L->next != NULL){
        cout << L->next->data << " ";
        L = L->next;
    }
    return 0;
}