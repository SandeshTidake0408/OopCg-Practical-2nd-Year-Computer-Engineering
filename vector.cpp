/*Write C++ program using STL for sorting and searching user defined records
such as personal records (Name, DOB, Telephone number etc) using vector container.*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

class node
{
public:
	char name[20];
	char birth[20];
	char phone[11];
};
vector<node> vec;

void create()
{
	int n, i;
	node temp;
	cout << "Enter the No. Element of you want to insert : ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "Enter Name, DOB[dd-mm-yy], Phone : ";
		cin >> temp.name >> temp.birth >> temp.phone;
		vec.push_back(temp);
	}
}

void searching()
{
	char key[20];
	vector<node>::iterator itr;
	cout << "\nEnter the name which of Record : ";
	cin >> key;
	for (itr = vec.begin(); itr != vec.end(); itr++)
	{
		if (strcmp(itr->name, key) == 0)
		{
			cout << "Record Found " << endl;
			return;
		}
	}
	cout << "Record Not Present ..!" << endl;
}

bool compare(node &r1, node &r2)
{
	if (strcmp(r1.name, r2.name) < 0)
		return true;
	else
		return false;
}

void sorting()
{
	sort(vec.begin(), vec.end(), compare);
	cout << "\nRecord Sorted Successfully " << endl;
}

void display()
{
	cout << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].name << " " << vec[i].birth << " " << vec[i].phone << endl;
	}
	cout << endl;
}

int main()
{
	create();
	searching();
	sorting();
	display();

	return 0;
}
