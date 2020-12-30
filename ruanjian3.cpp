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
	int chinese;//���ĳɼ�
	int math;//��ѧ�ɼ�
	int english;//Ӣ��ɼ�
	int num;//���
	int sum = 0;//�ܷ�
}s[301];

int cmp(student p1, student p2) {//�ṹ��
	if (p1.sum == p2.sum && p1.chinese != p2.chinese) {//�ܷ���ͬ�����ĳɼ�������ǰ
		return p1.chinese > p2.chinese;
	}
	if (p1.sum == p2.sum && p1.chinese == p2.chinese) {//�ܷ���ͬ�����ĳɼ���ͬ�����С��ǰ
		return p1.num < p2.num;
	}
	else {//�����ܷ�Խ����Խǰ
		return p1.sum > p2.sum;
	}
}

int n;//����

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		s[i].num = i;
		cin >> s[i].chinese >> s[i].math >> s[i].english;
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	sort(1 + s, 1 + n + s, cmp);//����

	for (int i = 1; i <= 5; i++) {//���ǰ5��
		cout << s[i].num << " " << s[i].sum << endl;;
	}
	return 0;
}

