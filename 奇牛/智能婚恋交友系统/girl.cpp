#include "Girl.h"
#include "Boy.h"
#include <sstream>
#include <iostream>

#define YANZHI_FACTOR	100

Girl::Girl() {

}

Girl::Girl(int age, string name, int yanZhi) {
	this->age = age;
	this->name = name;
	this->yanZhi = yanZhi;
}

Girl::~Girl() {
}

int Girl::getAge() const {
	return age;
}

string Girl::getName() const {
	return name;
}

int Girl::getYanZhi()  const {
	return yanZhi;
}

bool Girl::satisfied(const Boy& s) const {
	if (s.getSalary() >= yanZhi * YANZHI_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Girl::description() const {
	stringstream ret;
	ret << name << "-女-颜值(" << yanZhi << ")-年龄(" << age << ")";
	return ret.str();
}

void Girl::inputGirls(vector<Girl>& girls) {
	int age;
	string name;
	int yanZhi;
	int n = 1;

	while (1) {
		cout << "请输入第" << n << "位小姐姐的年龄【输入0结束】：";
		cin >> age;
		if (age == 0) {
			break;
		}

		cout << "请输入第" << n << "位小姐姐的姓名：";
		cin >> name;

		cout << "请输入第" << n << "位小姐姐的颜值：";
		cin >> yanZhi;

		n++;
		girls.push_back(Girl(age, name, yanZhi));
	}
}