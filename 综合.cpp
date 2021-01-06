#include"stdio.h"
#include"time.h"
#include"windows.h"
#include"string.h"
#include"dos.h"
#include"stdlib.h"
#include"ctype.h" 
#define Max 50//最大贮赌量
#define null 0
static int H=0;
struct Times
{//定义时钟
int hour;
int min;
int sec;
};
struct Buses{//定义汽车
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
void load();//载入车次信息
void lu(void);//声明录入函数
void chaxun(struct Buses bus[]);//声明查询路线函数
void save(struct Buses bus[]);//声明保存函数
int caidan();//声明菜单录数
void liulan(struct Buses bus[]);//声明浏览函数
void tuipiao(struct Buses bus[]);//退票
void shoupiao(struct Buses bus[]);//声明售票函数
void xitongtuichu();//声明退出函数
//工具函数
struct Buses copy(struct Buses b1,struct Buses b2);//赋值
void sort_time(struct Buses bus[]);//声明按时间发车的先后顺序排序
int compare_time(struct Times t1,struct Times t2);//时间比较函数
int compare_systime(struct Buses bus,tm *T);//比较发车时间与当前系统时间的函数
void print(struct Buses bus);//声明输入出函数
int number_search(struct Buses bus[],int num);//声明按班次查询函数
int end_search(struct Buses bus,char ends[]);//声明按终点查询函数
void main(){//主函数
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
int compare_systime(struct Buses bus,tm *T){//与系统时间的比较函数
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

void liulan(struct Buses bus[]){//浏览车次
getchar();
system("cls");
int i;
printf("\n\t\t\t\t车辆时刻表\n");
printf("\t\t\t**************************\n");
printf("\t班次 发车时间 起点站 终点站 行车时间 额定载量 已定票人数");
printf("\n\t--------------------------------------------------------------\n");
sort_time(bus);
for(i=0;i<H;i++){
print(bus[i]);
}
printf("\t--------------------------------------------------------------\n");
printf("\t\t\t\t%d条记录!\n",H);
printf("\t按任意键返回主菜单...");
getchar();
}
int compare_time(struct Times t1,struct Times t2){//比较时间大小
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
void sort_time(struct Buses bus[]){//按发车时间排序
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


int number_search(struct Buses bus[],int n){//按班次查询
int i;
for(i=0;i<H;i++){
if(bus[i].number==n)
return i;
}
return -1;

}
int end_search(struct Buses bus,char ends[]){//按终点站查询

if(strcmp(bus.end,ends)==0)
return 1;
else
return -1;
}
void print(struct Buses bus){
if(!compare_systime(bus,tnow))
printf("\t%-6d%-2d:%-2d:%-2d%6s%8s%8.1f%10d%10d(已发出)\n",bus.number,bus.time.hour,
bus.time.min,bus.time.sec,bus.start,bus.end,bus.time_cost,bus.carry_number,bus.booK_number);
else
printf("\t%-6d%-2d:%-2d:%-2d%6s%8s%8.1f%10d%10d\n",bus.number,bus.time.hour,
bus.time.min,bus.time.sec,bus.start,bus.end,bus.time_cost,bus.carry_number,bus.booK_number);
}
int caidan(){
int a;
system("cls");//以下是菜单图案
printf("\n\n");
printf("\t\t 车票管理系统 \n");
printf("\t\t ***************** (%d年%d月%d日)\n",
1900+tnow->tm_year,tnow->tm_mon+1,tnow->tm_mday);
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| 菜单 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (1) 录入班次信息 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (2) 显示班次信息 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (3) 查询班次信息 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (4) 售票 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (5) 退票 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (6) 保存车次信息 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\t\t| (0) 退出系统 |\n");
printf("\t\t|----------------------------------------------|\n");
printf("\n\t\t请选择(0-6):");
scanf("%d",&a);
return(a);
}
void save(struct Buses bus[]){//保存函数体
getchar();
FILE *fp;
int i;
if((fp=fopen("Bus_system","wb"))==null){
printf("不能打开文件\n");
return;
}
for(i=0;i<H;i++)
if(fwrite(&bus[i],sizeof(struct Buses),1,fp)!=1)
printf("文件保存出错!\n");
fclose(fp);
printf("文件保存成功!");
getchar();
}
void lu(){//录入函数
int i=H,f=1; 
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\t\t车次信息录入\n请输入车的班次:");
scanf("%d",&bus[i].number);
getchar();
while(number_search(bus,bus[i].number)>=0){
printf("你输入的班次已存在请重新输入!:");
scanf("%d",&bus[i].number);
getchar();
}
printf("请输入时间如:(20:30:00) :");
scanf("%d:%d:%d",&bus[i].time.hour,&bus[i].time.min,&bus[i].time.sec);
getchar();

printf("请输入车的起点站:");
scanf("%s",bus[i].start);
getchar();
printf("请输入车的终点站:");
scanf("%s",bus[i].end);
getchar();
printf("请输入行车时间:");
scanf("%f",&bus[i].time_cost);
getchar();
printf("请输入车的额定载量:");
scanf("%d",&bus[i].carry_number);
getchar();
bus[i].booK_number=0;
H++;
i++;
printf("信息录入成功!\n");
printf("继续录入请按(Y),返回主菜单按任意键...");
flag=getchar();
}
}
void chaxun(struct Buses bus[]){//查询路线
int a,i=0;
int m=0;
char flag='Y';
while(toupper(flag)=='Y'){
char end[30];
system("cls");
printf("\n按班次查询请按 1\n终点站查询请按 2\n请选择(1-2):");
scanf("%d",&a);
while(a!=1&&a!=2){
printf("注意只能选择1或2!\n请重新输入:");
scanf("%d",&a);
getchar();
}
switch(a)
{
case 1:{
printf("请输入车次号：");
scanf("%d",&m);
getchar();
i=number_search(bus,m);
if(i>=0){
printf("\n\t\t\t\t车辆时刻表\n");
printf("\t\t\t**************************\n");
printf("\t班次 发车时间 起点站 终点站 行车时间 额定载量 已定票人数");
printf("\n\t--------------------------------------------------------------\n");
print(bus[i]);
printf("\t--------------------------------------------------------------\n");
}
else
printf("\n\t\t\t没有你要查找的记录!\n");
}break;
case 2:{
printf("请输入车的终点站：");
scanf("%s",end);
getchar();
while(i<H){
if((m=end_search(bus[i],end))==1){
printf("\n\t\t\t\t车辆时刻表\n");
printf("\t\t\t**************************\n");
printf("\t班次 发车时间 起点站 终点站 行车时间 额定载量 已定票人数");
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
printf("\n\t\t\t没有到该站的车!\n");break;
}
}
printf("\t\t继续查找请按(Y),返回主菜单按任意键...");
flag=getchar();

}
}
void shoupiao(struct Buses bus[]){//售票函数
int i,n;
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\t\t\t\t车辆时刻表\n");
printf("\t\t\t************************** 当前时间(%d:%d:%d)\n",
tnow->tm_hour,tnow->tm_min,tnow->tm_sec);
printf("\t班次 发车时间 起点站 终点站 行车时间 额定载量 已定票人数");
printf("\n\t--------------------------------------------------------------\n");
for(int j=0;j<H;j++){
print(bus[j]);
}
printf("\t--------------------------------------------------------------\n");
printf("\t请输入车的班次：");
scanf("%d",&i);
n=number_search(bus,i);
getchar();
if(n>=0&&bus[n].carry_number>bus[n].booK_number&&compare_systime(bus[n],tnow)){
printf("\n\t\t\t售票成功!\n");
bus[n].booK_number++;
printf("\t班次 发车时间 起点站 终点站 行车时间 额定载量 已定票人数");
printf("\n\t--------------------------------------------------------------\n");
print(bus[n]);
printf("\n\t--------------------------------------------------------------\n");
}
if(bus[n].carry_number<=bus[n].booK_number)
printf("\n\t\t\t该次车的票已售完!\n");
else if(n<0)
printf("\n\t\t\t该次车不存在!\n");
else if(!compare_systime(bus[n],tnow))
printf("\n\t\t\t该次已发出!\n");
printf("\t\t继续售票请按(Y),返回主菜单按任意键...");
flag=getchar();
}
}
void tuipiao(struct Buses bus[]){//退票函数
int n,i;
char flag='Y';
while(toupper(flag)=='Y'){
system("cls");
printf("\n\n请输入车次：");
scanf("%d",&n);
getchar();
i=number_search(bus,n);
if(i>=0&&compare_systime(bus[i],tnow)){
bus[i].booK_number--;
printf("\n\t\t\t退票成功!\n");
}
else if(i<0)
printf("\n\t\t\t该车次不存在!\n");
else if(!compare_systime(bus[n],tnow))
printf("\n\t\t\t车已发出不能退票!\n");
printf("\t继续退票请按(Y),返回主菜单按任意键...");
flag=getchar();
}
}
void load()//载入车次信息
{ FILE *fp;
int i=0;
while((fp=fopen("Bus_system","rb"))==NULL) //以rb形式打开文件
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
void xitongtuichu(){//退出函数
system("cls");
getchar();
char flag=null;
printf("\n\n\t\t你确定要退出并保存信息吗?(Y/N)");
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