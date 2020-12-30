#include <stdio.h>
#include <stdlib.h>									//数组解决方案 
#define maxsize 100
void king(int m,int n)
{
    int p[maxsize],q[maxsize];
    int i,j,t;
    t=0;//t为报数的位置，第一只猴子在位置0（每步需要先加一）
    for(i=1;i<m;i++)
    {
       p[i]=1;//数组初始化，未出圈猴子位置记为1
    }
    //printf("猴子出圈顺序依次为：\n");
    for(i=1;i<=m;i++)
    {
        j=1;//报数用
        while(j<=n)
        {
            t=(t+1)%m;//当报数为报至需要出圈时，报数位置加一
                     // 因为报数位可能会超过m，故取余回到开头
            if(p[t]==1)j++;//当所在位置非空时，报数加一
        }
        p[t]=0;//已经报数了n个，t处猴子出圈
        printf("%d\n",t+1);//因为数组从零记，实际位置需要加一
        q[i]=t+1;//将每次出圈的猴子标号记录下来，用于最后得出王者
    }
    printf("王者为%d",q[m]);
}
int main()
{
   int m,n;
   printf("请输入猴子个数（100以内）m和每出圈一个需要报的个数n\n");
   scanf("%d,%d",&m,&n);
   king(m,n);
   return king;
}


//

//#include <stdio.h>										//链表解决方案 
//#include <stdlib.h>
//typedef struct node    //定义链表节点类型
//{
//    int data;
//    struct node*next;
//}linklist;
//void creat(int n,int m)
//{
//    linklist *head,*p,*s,*q;
//    int i,total;
///*创建循环链表，头节点也存储信息*/
//     head=(linklist*)malloc(sizeof(linklist));
//     p=head;
//     p->data=1;
//     p->next=p;
///*初始化循环链表*/
// for(i=2;i<=m;i++)
// {
//     s=(linklist*)malloc(sizeof(linklist));
//     s->data=i;
//     s->next=p->next;
//     p->next=s;
//     p=p->next;
// }
//  p=head;
//  /*保存节点总数*/
//  total=m;
//  q=head;

//  while(total!=1)  //只剩一个节点时停止循环
//  {
//      /* 报数过程，p指向要删除的结点*/
//      for(i=1;i<n;i++)
//      {
//          p=p->next;
//      }
//      printf("%d\n",p->data);//输出要出圈的猴子序号
//    
//    /*q指向p结点的前驱 */
//    while(q->next!=p)
//    {
//        q=q->next;
//    }
//    
//    /* 删除p结点*/
//    q->next=p->next;
//    /* 保存被删除的结点指针*/
//    s=p;
//    /* p指向被删除结点的后继*/
//    p=p->next;
//    /* 释放被删除的结点*/
//    free(s);
//    /* 结点个数减一*/
//    total--;
//  }
//  int king;
//  king=p->data;
//  free(p);
//  printf("king is %d\n",king);
//  return 0;

//}


//
//#include<stdio.h>
//int main()
//{
//	int m,n,number,count=1;		//number记猴子剩余个数，count记当前报数
//	int monkey[999];
//	int t;						//t记数组下标
//	int i;
//	printf("请输入猴子个数 m 和报数 n ：");
//	scanf("%d%d",&m,&n);
//	number = m;
//	for(i=1;i<m;i++)
//		monk
//		ey[i]=i+1;
//	t=0;
//	while(number>1)
//	{
//		if(monkey[t]>0)
//		{
//			if(count!=n)
//			{
//				count++;
//				t=(t+1)%m;		//t=(t+1)%m实现数组下标加1
//			}
//			else
//			{
//				monkey[t]=0;
//				count=1;
//				number--;
//				t=(t+1)%m;
//			}
//		}
//		else
//		{
//			t=(t+1)%m;
//		}
//	}
//	for(i=1;i<m;i++)
//	{
//		if(monkey[i]>0)
//			printf("猴子大王：%d\n",monkey[i]);
//	}
//	return 0;
//}



