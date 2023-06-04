#pragma once


#include <string>
#include <vector>

using namespace std;

class Boy;

class Girl
{
public:
	Girl();
	Girl(int age, string name, int yanZhi);
	~Girl();

	int getAge()const;
	string getName()const;
	int getYanZhi()const;
	bool satisfied(const  Boy& s) const;
	string description()const;

	static void inputGirls(vector<Girl>& girls);
private:
	int age;
	string name;
	int yanZhi;
};