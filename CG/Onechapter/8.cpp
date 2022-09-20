#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct qlist{
    int time1;  // 进库时间点
    qlist *next;
}qlist;

qlist *park = (qlist*)malloc(sizeof(qlist)); // 栈停车场
qlist *biandao = (qlist*)malloc(sizeof(qlist)); // 队列便道
qlist *temp1, *temp2; //操作栈和队列

int main(){
    int n;
    cin>>n; // 停车场位置大小

    int q;
    cin>>q; // 操作次数
    
    temp1 = park;
    temp1->next =NULL;
    temp2 = biandao;

    int type;
    int now=0;//停车场使用车位的数量
    for(int i=0;i<q;i++){
        cin>>type;
        if(type == 1){      //进库
            
            qlist *car = (qlist*)malloc(sizeof(qlist));
            cin >> car->time1;
            if(now < n){    // 停车场未满
                
                car->next = temp1->next;
                temp1->next = car;
                now++;
            }

            else{           // 停车场满，存入便道
                
                car->next = NULL;
                temp2->next = car;
                temp2 = car;
            }
        }
        else{               // 出库
            int x, t;
            cin >> x >> t;

            // 下面这句看不懂哟

            int index = x - (n - now); //求要出的车位于第几个结点

            qlist *temp3 = park;
            while(temp3->next != NULL){
                index--;
                if(index == 0){// 找到车辆
                    qlist *dlt = temp3->next;
                    temp3->next = temp3->next->next;

                    //输出
                    cout<<(t - dlt->time1)<<endl;

                    free(dlt);
                    now--;
                    
                    //如果队列有车，就从队列中出一个到栈
                    if(temp2 != biandao){
                        qlist *target = biandao->next;
                        // 出队
                        biandao->next = biandao->next->next;
                        if(biandao->next == temp2){
                            //队列中最后一个
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