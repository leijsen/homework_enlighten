#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct qlist{
    int time1;  // ����ʱ���
    qlist *next;
}qlist;

qlist *park = (qlist*)malloc(sizeof(qlist)); // ջͣ����
qlist *biandao = (qlist*)malloc(sizeof(qlist)); // ���б��
qlist *temp1, *temp2; //����ջ�Ͷ���

int main(){
    int n;
    cin>>n; // ͣ����λ�ô�С

    int q;
    cin>>q; // ��������
    
    temp1 = park;
    temp1->next =NULL;
    temp2 = biandao;

    int type;
    int now=0;//ͣ����ʹ�ó�λ������
    for(int i=0;i<q;i++){
        cin>>type;
        if(type == 1){      //����
            
            qlist *car = (qlist*)malloc(sizeof(qlist));
            cin >> car->time1;
            if(now < n){    // ͣ����δ��
                
                car->next = temp1->next;
                temp1->next = car;
                now++;
            }

            else{           // ͣ��������������
                
                car->next = NULL;
                temp2->next = car;
                temp2 = car;
            }
        }
        else{               // ����
            int x, t;
            cin >> x >> t;

            // ������俴����Ӵ

            int index = x - (n - now); //��Ҫ���ĳ�λ�ڵڼ������

            qlist *temp3 = park;
            while(temp3->next != NULL){
                index--;
                if(index == 0){// �ҵ�����
                    qlist *dlt = temp3->next;
                    temp3->next = temp3->next->next;

                    //���
                    cout<<(t - dlt->time1)<<endl;

                    free(dlt);
                    now--;
                    
                    //��������г����ʹӶ����г�һ����ջ
                    if(temp2 != biandao){
                        qlist *target = biandao->next;
                        // ����
                        biandao->next = biandao->next->next;
                        if(biandao->next == temp2){
                            //���������һ��
                            temp2 = biandao;
                        }
                        target->time1 = t;
                        target->next = park->next;
                        park->next = target;
                        now++;
                    }
                    break;
                }
                temp3 = temp3->next;
            }
        }
    }
}