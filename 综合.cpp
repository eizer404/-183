#include"stdio.h"
#include"time.h"
#include"windows.h"
#include"string.h"
#include"dos.h"
#include"stdlib.h"
#include"ctype.h" 
#define Max 50//���������
#define null 0
static int H=0;
struct Times
{//����ʱ��
int hour;
int min;
int sec;
};
struct Buses{//��������
int number;
struct Times time;
char start[30];
char end[30];
float time_cost;
int carry_number;
int booK_number;
};
struct Buses bus[Max];
time_t now = time(0);
tm *tnow =localtime(&now);
void load();//���복����Ϣ
void lu(void);//����¼�뺯��
void chaxun(struct Buses bus[]);//������ѯ·�ߺ���
void save(struct Buses bus[]);//�������溯��
int caidan();//�����˵�¼��
void liulan(struct Buses bus[]);//�����������
void tuipiao(struct Buses bus[]);//��Ʊ
void shoupiao(struct Buses bus[]);//������Ʊ����
void xitongtuichu();//�����˳�����
//���ߺ���
struct Buses copy(struct Buses b1,struct Buses b2);//��ֵ
void sort_time(struct Buses bus[]);//������ʱ�䷢�����Ⱥ�˳������
int compare_time(struct Times t1,struct Times t2);//ʱ��ȽϺ���
int compare_systime(struct Buses bus,tm *T);//�ȽϷ���ʱ���뵱ǰϵͳʱ��ĺ���
void print(struct Buses bus);//�������������
int number_search(struct Buses bus[],int num);//��������β�ѯ����
int end_search(struct Buses bus,char ends[]);//�������յ��ѯ����
void main(){//������
while(1){
system("cls");
switch(caidan()){
case 1: lu(); break;
case 2: liulan(bus); break;
case 3: chaxun(bus); break;
case 4: shoupiao(bus); break;
case 5: tuipiao(bus); break;
case 6: save(bus); break;
case 0: xitongtuichu(); break;
}
}
}
int compare_systime(struct Buses bus,tm *T){//��ϵͳʱ��ıȽϺ���
if(bus.time.hour>=T->tm_hour){
return 1;
if(bus.time.min>=T->tm_min){
return 1;
if(bus.time.sec>T->tm_sec)
return 1;
else return 0;
}
return 0;
}
return 0;
}
struct Buses copy(struct Buses b1,struct Buses b2){
b1.booK_number=b2.booK_number;
b1.carry_number=b2.carry_number;
strcpy(b1.end,b2.end);
b1.number=b2.number;
strcpy(b1.start,b2.start);
b1.time.hour=b2.time.hour;
b1.time.min=b2.time.min;
b1.time.sec=b2.time.sec;
b1.time_cost=b2.time_cost;
return b1;
}

void liulan(struct Buses bus[]){//�������
getchar();
system("cls");
int i;
printf("\n\t\t\t\t����ʱ�̱�\n");
printf("\t\t\t**************************\n");
printf("\t��� ����ʱ�� ���վ �յ�վ �г�ʱ�� ����� �Ѷ�Ʊ����");
printf("\n\t--------------------------------------------------------------\n");
sort_time(bus);
for(i=0;i<H;i++){
print(bus[i]);
}
printf("\t--------------------------------------------------------------\n");
printf("\t\t\t\t%d����¼!\n",H);
printf("\t��������������˵�...");
getchar();
}
int compare_time(struct Times t1,struct Times t2){//�Ƚ�ʱ���С
if(t1.hour>t2.hour){
return 1;
if(t1.min>=t2.min){
return 1;
if(t1.sec>=t2.sec)
return 1;
else return 0;
}
return 0;
}
return 0;
}
void sort_time(struct Buses bus[]){//������ʱ������
int i,j,k;
struct Buses b={0};
for(i=0;i<H-1;i++){
k=i;
for(j=i+1;j<H;j++){
if(compare_time(bus[i].time,bus[j].time)){
k=j;
if(k!=i){
b=copy(b,bus[i]);
bus[i]=copy(bus[i],bus[k]);
bus[k]=copy(bus[k],b);
}
}
}
}
}


int number_search(struct Buses bus[],int n){//����β�ѯ
int i;
for(i=0;i<H;i++){
if(bus[i].number==n)
return i;
}
return -1;

}
int end_search(struct Buses bus,char ends[]){//���յ�վ��ѯ

if(strcmp(bus.end,ends)==0)
return 1;
else
return -1;
}
void print(struct Buses bus){
if(!compare_systime(bus,tnow))
printf("\t%-6d%-2d:%-2d:%-2d%6s%8s%8.1f%10d%10d(�ѷ���)\n",bus.number,bus.time.hour,
bus.time.min,bus.time.sec,bus.start,bus.end,bus.time_cost,bus.carry_number,bus.booK_number);
else
printf("\t%-6d%-2d:%-2d:%-2d%6s%8s%8.1f%10d%10d\n",bus.number,bus.time.hour,
bus.time.min,bus.time.sec,bus.start,bus.end,bus.time_cost,bus.carry_number,bus.booK_number);
}
int caidan(){
int a;
system("cls");//�����ǲ˵�ͼ��
printf("\n\n");
printf("\t\t ��Ʊ����ϵͳ \n");
printf("\t\t ***************** (%d��%d��%d��)\n",
1900+tnow->tm_year,tnow->tm_mon+1,tnow->tm_mday);
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| �˵� |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (1) ¼������Ϣ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (2) ��ʾ�����Ϣ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (3) ��ѯ�����Ϣ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (4) ��Ʊ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (5) ��Ʊ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (6) ���泵����Ϣ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (0) �˳�ϵͳ |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\n\t\t��ѡ��(0-6):");
scanf("%d",&a);
return(a);
}
void save(struct Buses bus[]){//���溯����
getchar();
FILE *fp;
int i;
if((fp=fopen("Bus_system","wb"))==null){
printf("���ܴ��ļ�\n");
return;
}
for(i=0;i<H;i++)
if(fwrite(&bus[i],sizeof(struct Buses),1,fp)!=1)
printf("�ļ��������!\n");
fclose(fp);
printf("�ļ�����ɹ�!");
getchar();
}
void lu(){//¼�뺯��
int i=H,f=1; 
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\t\t������Ϣ¼��\n�����복�İ��:");
scanf("%d",&bus[i].number);
getchar();
while(number_search(bus,bus[i].number)>=0){
printf("������İ���Ѵ�������������!:");
scanf("%d",&bus[i].number);
getchar();
}
printf("������ʱ����:(20:30:00) :");
scanf("%d:%d:%d",&bus[i].time.hour,&bus[i].time.min,&bus[i].time.sec);
getchar();

printf("�����복�����վ:");
scanf("%s",bus[i].start);
getchar();
printf("�����복���յ�վ:");
scanf("%s",bus[i].end);
getchar();
printf("�������г�ʱ��:");
scanf("%f",&bus[i].time_cost);
getchar();
printf("�����복�Ķ����:");
scanf("%d",&bus[i].carry_number);
getchar();
bus[i].booK_number=0;
H++;
i++;
printf("��Ϣ¼��ɹ�!\n");
printf("����¼���밴(Y),�������˵��������...");
flag=getchar();
}
}
void chaxun(struct Buses bus[]){//��ѯ·��
int a,i=0;
int m=0;
char flag='Y';
while(toupper(flag)=='Y'){
char end[30];
system("cls");
printf("\n����β�ѯ�밴 1\n�յ�վ��ѯ�밴 2\n��ѡ��(1-2):");
scanf("%d",&a);
while(a!=1&&a!=2){
printf("ע��ֻ��ѡ��1��2!\n����������:");
scanf("%d",&a);
getchar();
}
switch(a)
{
case 1:{
printf("�����복�κţ�");
scanf("%d",&m);
getchar();
i=number_search(bus,m);
if(i>=0){
printf("\n\t\t\t\t����ʱ�̱�\n");
printf("\t\t\t**************************\n");
printf("\t��� ����ʱ�� ���վ �յ�վ �г�ʱ�� ����� �Ѷ�Ʊ����");
printf("\n\t--------------------------------------------------------------\n");
print(bus[i]);
printf("\t--------------------------------------------------------------\n");
}
else
printf("\n\t\t\tû����Ҫ���ҵļ�¼!\n");
}break;
case 2:{
printf("�����복���յ�վ��");
scanf("%s",end);
getchar();
while(i<H){
if((m=end_search(bus[i],end))==1){
printf("\n\t\t\t\t����ʱ�̱�\n");
printf("\t\t\t**************************\n");
printf("\t��� ����ʱ�� ���վ �յ�վ �г�ʱ�� ����� �Ѷ�Ʊ����");
printf("\n\t--------------------------------------------------------------\n");
print(bus[i]);
i++;}
break;
}
for(i;i<H;i++){
if(end_search(bus[i],end)==1)
print(bus[i]);
}
if(m==1)printf("\t--------------------------------------------------------------\n");
}
for(i=0;i<H;i++){
if(end_search(bus[i],end)!=1)
printf("\n\t\t\tû�е���վ�ĳ�!\n");break;
}
}
printf("\t\t���������밴(Y),�������˵��������...");
flag=getchar();

}
}
void shoupiao(struct Buses bus[]){//��Ʊ����
int i,n;
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\t\t\t\t����ʱ�̱�\n");
printf("\t\t\t************************** ��ǰʱ��(%d:%d:%d)\n",
tnow->tm_hour,tnow->tm_min,tnow->tm_sec);
printf("\t��� ����ʱ�� ���վ �յ�վ �г�ʱ�� ����� �Ѷ�Ʊ����");
printf("\n\t--------------------------------------------------------------\n");
for(int j=0;j<H;j++){
print(bus[j]);
}
printf("\t--------------------------------------------------------------\n");
printf("\t�����복�İ�Σ�");
scanf("%d",&i);
n=number_search(bus,i);
getchar();
if(n>=0&&bus[n].carry_number>bus[n].booK_number&&compare_systime(bus[n],tnow)){
printf("\n\t\t\t��Ʊ�ɹ�!\n");
bus[n].booK_number++;
printf("\t��� ����ʱ�� ���վ �յ�վ �г�ʱ�� ����� �Ѷ�Ʊ����");
printf("\n\t--------------------------------------------------------------\n");
print(bus[n]);
printf("\n\t--------------------------------------------------------------\n");
}
if(bus[n].carry_number<=bus[n].booK_number)
printf("\n\t\t\t�ôγ���Ʊ������!\n");
else if(n<0)
printf("\n\t\t\t�ôγ�������!\n");
else if(!compare_systime(bus[n],tnow))
printf("\n\t\t\t�ô��ѷ���!\n");
printf("\t\t������Ʊ�밴(Y),�������˵��������...");
flag=getchar();
}
}
void tuipiao(struct Buses bus[]){//��Ʊ����
int n,i;
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\n�����복�Σ�");
scanf("%d",&n);
getchar();
i=number_search(bus,n);
if(i>=0&&compare_systime(bus[i],tnow)){
bus[i].booK_number--;
printf("\n\t\t\t��Ʊ�ɹ�!\n");
}
else if(i<0)
printf("\n\t\t\t�ó��β�����!\n");
else if(!compare_systime(bus[n],tnow))
printf("\n\t\t\t���ѷ���������Ʊ!\n");
printf("\t������Ʊ�밴(Y),�������˵��������...");
flag=getchar();
}
}
void load()//���복����Ϣ
{ FILE *fp;
int i=0;
while((fp=fopen("Bus_system","rb"))==NULL) //��rb��ʽ���ļ�
return;
for(i;!feof(fp);i++,H++)
{
if(fread(&bus[H],sizeof(struct Buses),1,fp)!=1){}
if(feof(fp)) 
{
fclose(fp);
return;
}
}
fclose(fp);
}
void xitongtuichu(){//�˳�����
system("cls");
getchar();
char flag=null;
printf("\n\n\t\t��ȷ��Ҫ�˳���������Ϣ��?(Y/N)");
flag=getchar();
if(toupper(flag)=='Y')
{
save(bus);
exit(0);
}
else if(toupper(flag)=='N')
exit(0);
else
return;
}