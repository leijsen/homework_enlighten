#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct type{
    int xishu;
    int zhishu;
    type* next;
}type;
void print(type *L1, type* L2, int &a1, int b1){
    type *temp;
    int count = 0;
    temp = L1->next;
    while(temp){
        if(count != a1 && temp->xishu > 0 && count != 0){
            cout << '+';
        }
        count++;
        cout<<temp->xishu<<"X^"<<temp->zhishu;
        if(count == a1) cout<<endl;
        temp = temp->next;
    }
    count = 0;
    temp = L2->next;
    while(temp){
        if(count != b1 && temp->xishu > 0 && count != 0){
             cout << '+';
        }
        count++;
        cout<<temp->xishu<<"X^"<<temp->zhishu;
        temp = temp->next;
    }
}
void print3(type *L1, type *L2, int &a1, int b1){
    type *temp, *temp1;
    temp = L1->next;
    temp1 = L2->next;
    while(temp1){
        if(temp->zhishu == temp1->zhishu){
            if(temp->xishu - temp1->xishu == 0){
                a1 -= 1;
                type *now;
                now = L1;
                while(now->next != temp){
                    now = now->next;
                }
                now->next = temp->next;
                free(temp);
                temp = now->next;
                temp1 = temp1->next;
            }
            else{
                temp->xishu -= temp1->xishu;
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        else if(temp->zhishu < temp1->zhishu){
            if(temp->next) temp = temp->next;
            else{
                while(temp1){
                    a1++;
                    type *node = (type*)malloc(sizeof(type));
                    node->xishu = -temp1->xishu;
                    node->zhishu = temp1->zhishu;
                    temp->next = node;
                    temp = node;
                    temp->next = NULL;
                    temp1 = temp1->next;
                }
            }
        }
        else if(temp->zhishu > temp1->zhishu){
            a1++;
            type *now;
            now = L1;
            while(now->next != temp){
                now = now->next;
            }
            type *node = (type*)malloc(sizeof(type));
            node->xishu = -temp1->xishu;
            node->zhishu = temp1->zhishu;
            node->next = temp;
            now->next = node;
            temp1 = temp1->next;
        }
    }
}
void print2(type *L1, type *L2, int &a1, int b1){
    type *temp, *temp1;
    temp = L1->next;
    temp1 = L2->next;
    while(temp1){
        if(temp->zhishu == temp1->zhishu){
            if(temp->xishu + temp1->xishu == 0){
                a1 -= 1;
                type *now;
                now = L1;
                while(now->next != temp){
                    now = now->next;
                }
                now->next = temp->next;
                free(temp);
                temp = now->next;
                temp1 = temp1->next;
            }
            else{
                temp->xishu += temp1->xishu;
                temp = temp->next;
                temp1 = temp1->next;
            }
        }
        else if(temp->zhishu < temp1->zhishu){
            if(temp->next) temp = temp->next;
            else{
                while(temp1){
                    a1++;
                    type *node = (type*)malloc(sizeof(type));
                    node->xishu = temp1->xishu;
                    node->zhishu = temp1->zhishu;
                    temp->next = node;
                    temp = node;
                    temp->next = NULL;
                    temp1 = temp1->next;
                }
            }
        }
        else if(temp->zhishu > temp1->zhishu){
            a1++;
            type *now;
            now = L1;
            while(now->next != temp){
                now = now->next;
            }
            type *node = (type*)malloc(sizeof(type));
            node->xishu = temp1->xishu;
            node->zhishu = temp1->zhishu;
            node->next = temp;
            now->next = node;
            temp1 = temp1->next;
        }
    }
}
int main(){
    int T;
    cin >> T;
    while(T--){
        type* L1 = (type*)malloc(sizeof(type));
        type *L2 = (type*)malloc(sizeof(type));
        type *temp, *temp1;
        int a, b;
        cin >> a >> b;
        temp = L1;
        int a1,b1;
        a1 = a, b1 = b;
        while(a--){
            int x,y;
            cin >> x >> y;
            type *node = (type*)malloc(sizeof(type));
            node->xishu = x;
            node->zhishu = y;
            temp->next =node;
            temp = node;
            temp->next = NULL;
        }
        temp = L2;
        while(b--){
            int x,y;
            cin >> x >> y;
            type *node = (type*)malloc(sizeof(type));
            node->xishu = x;
            node->zhishu = y;
            temp->next = node;
            temp = node;
            temp->next = NULL;
        }
        int t;
        cin >> t;
        while(t--){
            int q;
            cin >> q;
            if(q == 1){
                print(L1, L2, a1, b1);
                if(t!=1) cout<<endl;
            }
            else if(q == 3){
                print3(L1, L2, a1, b1);
            }
            else if(q == 2){
                print2(L1, L2, a1, b1);
            }
        }
        cout << endl;
    }
}