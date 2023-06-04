#pragma once

#include <string>
#include <vector>
using namespace std;

class Girl;

class Boy
{
public:
	Boy();
	Boy(int age, string name, int salary);
	~Boy();
	Boy(const Boy& other);
	int getAge()const;
	string getName()const;
	int getSalary()const;
	bool satisfied(const  Girl& s) const;
	string description() const;

	static void inputBoys(vector<Boy>& boys);
private:
	int age;
	string name;
	int salary;
};