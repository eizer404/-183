#include <stdio.h>
#include <stdlib.h>									//���������� 
#define maxsize 100
void king(int m,int n)
{
    int p[maxsize],q[maxsize];
    int i,j,t;
    t=0;//tΪ������λ�ã���һֻ������λ��0��ÿ����Ҫ�ȼ�һ��
    for(i=1;i<m;i++)
    {
       p[i]=1;//�����ʼ����δ��Ȧ����λ�ü�Ϊ1
    }
    //printf("���ӳ�Ȧ˳������Ϊ��\n");
    for(i=1;i<=m;i++)
    {
        j=1;//������
        while(j<=n)
        {
            t=(t+1)%m;//������Ϊ������Ҫ��Ȧʱ������λ�ü�һ
                     // ��Ϊ����λ���ܻᳬ��m����ȡ��ص���ͷ
            if(p[t]==1)j++;//������λ�÷ǿ�ʱ��������һ
        }
        p[t]=0;//�Ѿ�������n����t�����ӳ�Ȧ
        printf("%d\n",t+1);//��Ϊ�������ǣ�ʵ��λ����Ҫ��һ
        q[i]=t+1;//��ÿ�γ�Ȧ�ĺ��ӱ�ż�¼�������������ó�����
    }
    printf("����Ϊ%d",q[m]);
}
int main()
{
   int m,n;
   printf("��������Ӹ�����100���ڣ�m��ÿ��Ȧһ����Ҫ���ĸ���n\n");
   scanf("%d,%d",&m,&n);
   king(m,n);
   return king;
}


//

//#include <stdio.h>										//���������� 
//#include <stdlib.h>
//typedef struct node    //��������ڵ�����
//{
//    int data;
//    struct node*next;
//}linklist;
//void creat(int n,int m)
//{
//    linklist *head,*p,*s,*q;
//    int i,total;
///*����ѭ������ͷ�ڵ�Ҳ�洢��Ϣ*/
//     head=(linklist*)malloc(sizeof(linklist));
//     p=head;
//     p->data=1;
//     p->next=p;
///*��ʼ��ѭ������*/
// for(i=2;i<=m;i++)
// {
//     s=(linklist*)malloc(sizeof(linklist));
//     s->data=i;
//     s->next=p->next;
//     p->next=s;
//     p=p->next;
// }
//  p=head;
//  /*����ڵ�����*/
//  total=m;
//  q=head;

//  while(total!=1)  //ֻʣһ���ڵ�ʱֹͣѭ��
//  {
//      /* �������̣�pָ��Ҫɾ���Ľ��*/
//      for(i=1;i<n;i++)
//      {
//          p=p->next;
//      }
//      printf("%d\n",p->data);//���Ҫ��Ȧ�ĺ������
//    
//    /*qָ��p����ǰ�� */
//    while(q->next!=p)
//    {
//        q=q->next;
//    }
//    
//    /* ɾ��p���*/
//    q->next=p->next;
//    /* ���汻ɾ���Ľ��ָ��*/
//    s=p;
//    /* pָ��ɾ�����ĺ��*/
//    p=p->next;
//    /* �ͷű�ɾ���Ľ��*/
//    free(s);
//    /* ��������һ*/
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
//	int m,n,number,count=1;		//number�Ǻ���ʣ�������count�ǵ�ǰ����
//	int monkey[999];
//	int t;						//t�������±�
//	int i;
//	printf("��������Ӹ��� m �ͱ��� n ��");
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
//				t=(t+1)%m;		//t=(t+1)%mʵ�������±��1
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
//			printf("���Ӵ�����%d\n",monkey[i]);
//	}
//	return 0;
//}



