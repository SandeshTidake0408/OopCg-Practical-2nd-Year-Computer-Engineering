// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// int main()
// {
// 	string country;
// 	float population;
// 	char ch;
// 	int choice;
// 	map<string, float> m;
// 	map<string, float>::iterator itr;

// 	do
// 	{
// 		cout << "\n Main Menu \n1)Inssert the element \n2)Display \n3)Search an State " << endl;
// 		cout << "Enter your choice : ";
// 		cin >> choice;
// 		switch (choice)
// 		{
// 		case 1:
// 			cout << "Enter the name of State : ";
// 			cin >> country;
// 			cout << "Enter the Population  of state :";
// 			cin >> population;
// 			m.insert(pair<string, float>(country, population));
// 			break;
// 		case 2:
// 			cout << "State and Population are : ";
// 			for (itr = m.begin(); itr != m.end(); itr++)
// 			{
// 				cout << "[" << itr->first << " " << itr->second << "]";
// 			}
// 			break;
// 		case 3:
// 			cout << "Enter the name of state for searching ita population : ";
// 			cin >> country;
// 			if (m.count(country) != 0)
// 			{
// 				cout << "Population is " << m.find(country)->second << "Cr";
// 			}
// 			else
// 			{
// 				cout << "State is not present of Records" << endl;
// 			}
// 			break;
// 		}
// 		cout << "\nDo you want to continue ?(y/n) : ";
// 		cin >> ch;
// 	} while (ch == 'y' || ch == 'Y');
// 	return 0;
// }

#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<string, int> m;
	m["Maharashtra"] = 100;
	m.insert({"Keral", 200}); // using .insert method
	m["AndhraPradesh"] = 300;
	m["HimachalPradesh"] = 400;
	m["Goa"] = 500;
	m["Chennai"] = 600;
	m["Bihar"] = 700;
	m["Punjab"] = 800;
	m["Gujrat"] = 900;
	m["Karnataka"] = 1000;
	m["Telangana"] = 1100;
	m["Odisha"] = 1200;
	m["Assam"] = 1300;
	m["ArunachalPradesh"] = 1400;
	m["Manipur"] = 1500;
	m["WestBengal"] = 1600;
	m["UttarPradesh"] = 1700;
	m["TamilNadu"] = 1800;
	m["Sikkim"] = 1900;
	m["Manipur"] = 2000;

	string str;
	while (true)
	{
		char ch;
		cout << "Enter the name of state : ";
		cin >> str;
		map<string, int>::iterator it;
		it = m.find(str);
		if (it == m.end())
		{
			cout << "Not in List \n";
		}
		else
		{
			cout << "Population of " << it->first << " is : " << (*it).second << endl;
		}
		cout << "Do you want to continue (y/n) : ";
		cin >> ch;
		if (ch == 'n')
			break;
	}
	return 0;
}