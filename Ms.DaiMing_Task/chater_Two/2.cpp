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
    cout << "������Ϊ��";
    int n;
    cin>>n;
    cout << "��ʼ����Ϊ��";
    creat(n);
    
    // cout << "��Ҫɾ�������֣�";
    // int d;
    // cin>>d;
    // pop(L, d);
    // printf("ɾ��������Ϊ��");
    
    cout << "ֵΪx�Ľ��,����ֵΪeΪ��";
    int x,e;
    cin >> x >> e;
    insert(x, e);

    cout << "����������ʽ��";
    while(L->next != NULL){
        cout << L->next->data << " ";
        L = L->next;
    }
    return 0;
}