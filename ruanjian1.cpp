//#include<stdio.h>
////int fun3(int *a,int *b)                        ָ�봫�� 
////{
////    int c1,c2,c3,c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
////    c1=*a%10;
////    c2=*b/10;
////    c3=*a/10;
////    c4=*b%10;
////    return (c1*1000+c2*100+c3*10+c4);
////}

////int main()
////{
////	//int fun3; 
////    //int fun3(int *a,int *b);
////    int a,b,c;
////    printf("Please enter a:   b:   ");
////    scanf("%d"   "%d",&a,&b);  //����������a
////    c=fun3(&a,&b);
////    printf("The number c is %d",c);  //���������c
////    return 0;
////}


//#include<stdio.h>
//int fun(int a,int b)
//{
//    int c1,c2,c3,c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
//    c1=a%10;
//    c2=b/10;
//    c3=a/10;
//    c4=b%10;
//    return (c1*1000+c2*100+c3*10+c4);
//}

//int main()                                 //ֵ���� 
//{
//	//int fun; 
//    //int fun(int *a,int *b);
//    int a,b,c;
//    printf("Please enter a:   b:   ");
//    scanf("%d"   "%d",&a,&b);  //����������a
//    c=fun(&a,&b);
//    printf("The number c is %d",c);  //���������c
//    return 0;
//}






//int main()                                       //���ô��� 
//{
//	//int fun2; 
//    //int fun2(int *a,int *b);
//    int a,b,c;
//    printf("Please enter a:   b:   ");
//    scanf("%d"   "%d",&a,&b);  //����������a
//    c=fun2(&a,&b);
//    printf("The number c is %d",c);  //���������c
//    return 0;
//}

//int fun2(int&a,int&b)
//{
//    int c1,c2,c3,c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
//    c1=a%10;
//    c2=b/10;
//    c3=a/10;
//    c4=b%10;
//    return (c1*1000+c2*100+c3*10+c4);
//}



#include<stdio.h>
int main()
{
    int fun(int a,int b);
    int a,b,c;
    printf("Please enter a:   b:   ");
    scanf("%d"   "%d",&a,&b);  //����������a
    c=fun(a,b);
    printf("The number c is %d",c);  //���������c
    return 0;
}

int fun(int a,int b)
{
    int c1,c2,c3,c4;  //c1��c2��c3��c4�ֱ��Ӧc��ǧλ����λ��ʮλ����λ
    c1=a%10;
    c2=b/10;
    c3=a/10;
    c4=b%10;
    return (c1*1000+c2*100+c3*10+c4);
}
