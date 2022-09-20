#include<iostream>
#include<malloc.h>
using namespace std;
int a, n, m;
typedef struct Qlist{
    int rank;
    int secret;
    Qlist *next ;
}Qlist;
int main(){
    cin >> a;
    while(a--){
        cin>>n;
        Qlist *L = (Qlist*)malloc(sizeof(Qlist));
        Qlist *temp;
        //temp = L;
        temp = L;
        int i=1;
        int t = n;
        while(n--){
            int b;
            cin>>b;
            Qlist *node = (Qlist*)malloc(sizeof(Qlist));
            node->rank = i;
            i++;
            node->secret = b;
            temp->next = node;
            temp = node;
        }
        temp->next = L->next;
        temp = L->next;
        cin >> m;
        while(t--){
            int count = 0;
            while(temp){
                count++;
                if(count == m){
                    cout<<temp->rank<<" ";
                    m = temp->secret;
                    Qlist *temp2 = (Qlist*)malloc(sizeof(Qlist));
                    temp2 = temp->next;
                    while(temp2){
                        if(temp2->next == temp){
                            break;
                        }
                        else{
                            temp2 = temp2->next;
                        }
                    }
                    temp2->next = temp->next;
                    free(temp);
                    temp = temp2->next;
                    break;
                }
                else{
                    temp = temp->next;
                }
                if(count == m) break;
            }
        }
        cout<<endl;
    }
}