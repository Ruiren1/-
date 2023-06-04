#include "Boy.h"
#include "Girl.h"
#include <iostream>
#include <sstream>

#define SALARY_FACTOR  0.006

Boy::Boy() {
}

Boy::Boy(const Boy& other) {
	salary = other.salary;
	name = other.name;
	age = other.age;
}

Boy::Boy(int age, string name, int salary) {
	this->age = age;
	this->name = name;
	this->salary = salary;
}

Boy::~Boy() {
}

int Boy::getAge() const {
	return age;
}

string Boy::getName() const {
	return name;
}

int Boy::getSalary()  const {
	return salary;
}

bool Boy::satisfied(const Girl& s) const {
	if (s.getYanZhi() >= salary * SALARY_FACTOR) {
		return true;
	}
	else {
		return false;
	}
}

string Boy::description()const {
	stringstream ret;
	ret << name << "-��-н��(" << salary << ")-����(" << age << ")";
	return ret.str();
}

void Boy::inputBoys(vector<Boy>& boys) {
	int age;
	string name;
	int salary;
	int n = 1;
	while (1) {
		cout << "�������" << n << "λС�������䡾����0��������";
		cin >> age;
		if (age == 0) {
			break;
		}

		cout << "�������" << n << "λС����������";
		cin >> name;

		cout << "�������" << n << "λС����н�ʣ�";
		cin >> salary;

		n++;
		boys.push_back(Boy(age, name, salary));
	}
}