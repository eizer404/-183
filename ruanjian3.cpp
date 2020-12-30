//#include <iostream>
//#include <string.h>
//#include <algorithm>
//using namespace std;
// 
//struct student {
//	int id;
//	int chinese;
//	int math;
//	int english;
//	int sum;
//} stu[325];
// 
//bool compare (const student &s1, const student &s2) {
//	if (s1.sum == s2.sum) {
//		if (s1.chinese == s2.chinese) {
//			return s1.id < s2.id;
//		}
//		return s1.chinese > s2.chinese;
//	}
//	return s1.sum > s2.sum;
//}
// 
//int main()
//{
//	int n;
//	cin>>n;
//	for (int i=0; i<n; i++) {
//		stu[i].id = i+1;
//		cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
//		stu[i].sum = stu[i].chinese + stu[i].english + stu[i].math; 
//	}
//	sort (stu, stu+n, compare);
//	for (int i=0; i<5; i++) {
//		cout << stu[i].id << " " << stu[i].sum << endl;
//	}
//	return 0;
//}





#include <iostream>
#include <algorithm>

using namespace std;

struct student {
	int chinese;//语文成绩
	int math;//数学成绩
	int english;//英语成绩
	int num;//序号
	int sum = 0;//总分
}s[301];

int cmp(student p1, student p2) {//结构体
	if (p1.sum == p2.sum && p1.chinese != p2.chinese) {//总分相同，语文成绩高排在前
		return p1.chinese > p2.chinese;
	}
	if (p1.sum == p2.sum && p1.chinese == p2.chinese) {//总分相同，语文成绩相同，序号小在前
		return p1.num < p2.num;
	}
	else {//否则总分越高在越前
		return p1.sum > p2.sum;
	}
}

int n;//人数

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].num = i;
		cin >> s[i].chinese >> s[i].math >> s[i].english;
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	sort(1 + s, 1 + n + s, cmp);//排序

	for (int i = 1; i <= 5; i++) {//输出前5名
		cout << s[i].num << " " << s[i].sum << endl;;
	}
	return 0;
}

