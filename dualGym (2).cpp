#include <iostream>
#include <fstream>
#include "linkedlist.h"


using namespace std; 
 
void ShowMenu()
{
	cout << "Dual Gym Check In Manager\n"
			 << "1. Add Member to beginning\n"
			 << "2. Add member to end\n"
			 << "3. Remove member from a list\n"
			 << "4. Display all members\n"
			 << "5. Display totals\n"
			 << "6. Display first and last member\n"
			 << "7. Search for a member in both lists\n"
			 << "8. Quit\n\n";
}

linkedListType<string>* chooseList(linkedListType<string>& morning,
																	linkedListType<string>& evening,
																	string& label)

{
	char which;
	cout << "Which list? (M for Morning, E for evening): ";
	cin >> which;

	if (which == 'M' || which == 'm')
	{
		label = "Morning";
		return &morning;
	}
	else if (which == 'E' || which == 'e')
	{
		label = "evening";
		return &evening;
	}
	else
	{
		label = "Morning";
		cout << "Invalid Choice. Defaulting to Morning.\n";
		return &morning;
	}
}

int main()
{
	linkedListType<string> morningList;
	linkedListType<string> eveningList;
	int choice = 0;

	do
	{
		ShowMenu();
		cout << "Enter choice: ";
		cin >> choice;

		if (!cin)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid Input. Try again.\n\n";
			continue;
		}
		if (choice == 1) 
		{
			string label;
			linkedListType<string>* list = chooseList(morningList, eveningList, label);

			string name;
			cout << "Enter member name (one word): ";
			cin >> name;

			list->insertFirst(name);
			cout << "\"" << name << "\" added to the " << label << " list.\n\n";
		}
		else if (choice == 2) 
		{
			string label;
			linkedListType<string>* list = chooseList(morningList, eveningList, label);

			string name;
			cout << "Enter member name: ";
			cin >> name;

			list->insertLast(name);
			cout << "\"" << name << "\" added to the " << label << " list.\n\n";
		}
		else if (choice == 3) 
		{
			string label;
			linkedListType<string>* list = chooseList(morningList, eveningList, label);
			if (list->isEmptyList())
			{
				cout << label << " list is empty. Nothing to remove.\n\n";
			}
			else
			{
				string name;
				cout << "Enter the one-word name to remove: ";
				cin >> name;

				if (!list->search(name))
				{
					cout << "\"" << name << "\" is not in the " << label << " list.\n\n";
				}
				else
				{
					list->deleteNode(name);
					cout << "\"" << name << "\"removed from the " << label  << " list.\n\n";

				}
			}
		}
		else if (choice == 4) 
		{
			string label;
			linkedListType<string>* list = chooseList(morningList, eveningList, label);

			if (list->isEmptyList())
			{
				cout << label << " List is empty.";
			}
			else 
			{
				cout << label << " Check Ins:";
				list ->print();
				cout << "\n\n";
			}
		}
	else if (choice == 5) 
	{
		int m = morningList.length();
		int e = eveningList.length();
		cout << "Morning: " << m << endl;
		cout << "Evening: " << e << endl;
		cout << "Total check ins: " << (m + e) << endl;
	}
	else if (choice == 6) 
	{
		string label;
		linkedListType<string>* list = chooseList(morningList, eveningList, label);
		if (list->isEmptyList())
		{
			cout << label << " list is empty.";
		}
		else
		{
			cout << "First member:" << list->front();
			cout << "last member: " << list->back();
		}
	}
	else if (choice == 7) 
	{
		string name;
		cout << "Enter memebr name to search: ";
		cin >> name;

		bool inMorning = morningList.search(name);
		bool inEvening = eveningList.search(name);

		if (inMorning && inEvening)
		 cout << name << " is in both lists.";
		else if (inMorning)
		cout << name << "  is in the morning list";
	else if (inEvening)
		cout << name << " is in eveeing list.";
	else 
		cout << name << " is not in either list";
	}
	else if (choice == 8)

	{
		cout << "ending program." << endl;
	}
	else 
	{
		cout << "Invalid choice try again";
	}
} while (choice != 8);

return 0;
}