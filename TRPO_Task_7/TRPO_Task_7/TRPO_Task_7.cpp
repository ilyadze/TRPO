#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

struct fio
{
	string name;
	string surname;
	string patronymic;
};

struct date
{
	int day;
	int month;
	int year;
};

struct studentsList
{
	fio Fio;
	date birthaday;
	double averageScore;
	date age;
};

void writeListInFile(string , studentsList* , int& );
void outStruct(int& , studentsList*);
studentsList* fillList(studentsList*, int&);
string searchName(studentsList*, int&);
void sortList(studentsList*, int&);
void getCurrentDate(int& currentYear, int& currentMonth, int& currentDay);
void getAgeStudent(studentsList*, int& size, int& currentYear, int& currentMonth, int& currentDay);
void outAgeStudent(studentsList*, int& size);
date averageAge(studentsList*, int&);


int main()
{
	int size;
	cout << "Enter the number of students ";
	cin >> size;
	studentsList* groupList = new studentsList[size];
	wcout << "Fill in the group list" << endl;
	fillList(groupList, size);
	outStruct(size, groupList);
	
	string popularName = searchName(groupList, size);
	cout << "The most popular name - " << popularName << endl;

	sortList(groupList, size);
	cout << "\nSorted List" << endl;
	outStruct(size, groupList);
	
	int nowYear, nowMonth, nowDay;
	getCurrentDate(nowYear, nowMonth, nowDay);
	getAgeStudent(groupList, size, nowYear, nowMonth, nowDay);
	outAgeStudent(groupList, size);

	date averageAgeStudents = averageAge(groupList,size);
	cout << "Average age students - " << averageAgeStudents.year << " years "
		<< averageAgeStudents.month << " months "
		<< averageAgeStudents.day << " days";

	delete[]groupList;
}


studentsList* fillList(studentsList* List, int& size)
{
	int numberOfLines = 0;
	while (numberOfLines < size)
	{
		/*if (numberOfLines == size)
		{
			List = resireArray(size, size + 1, List);
		}*/
		cout << "Surname - ";
		cin >> List[numberOfLines].Fio.surname;
		cout << "Name - ";
		cin >> List[numberOfLines].Fio.name;
		cout << "Patronymic - ";
		cin >> List[numberOfLines].Fio.patronymic;
		cout << "Average score - ";
		scanf_s("%lf", &List[numberOfLines].averageScore);
		cout << "Date of birthday - ";
		scanf_s("%d.%d.%d", &List[numberOfLines].birthaday.day, &List[numberOfLines].birthaday.month, &List[numberOfLines].birthaday.year);
		numberOfLines++;
	}
	//List = resireArray(size, numberOfLines - 1, List);
	//size = numberOfLines - 1;
	return List;
}

void outStruct(int& size, studentsList* lists)
{
	for (int i = 0;i < size;i++)
	{
		cout << "Fio - " << lists[i].Fio.surname << " " << lists[i].Fio.name << " " << lists[i].Fio.patronymic << endl
			<< "Average score - " << lists[i].averageScore << endl
			<< "Date of birthday - " << lists[i].birthaday.day << "."
			<< lists[i].birthaday.month << "."
			<< lists[i].birthaday.year << endl;
	}
}


void writeListInFile(string fileName, studentsList* lists, int& size)
{
	ofstream file(fileName, ios_base::app);
	if (!file.is_open())
	{
		return;
	}
	for (int i = 0;i < size;i++)
	{
		file << "\n" << lists[i].Fio.surname << " " << lists[i].Fio.name << " " << lists[i].Fio.patronymic << " "
			<< lists[i].averageScore << " "
			<< lists[i].birthaday.day << "."
			<< lists[i].birthaday.month << "."
			<< lists[i].birthaday.year << endl;;
	}
	file.close();
}


string searchName(studentsList* list, int& size)
{
	string popularName;
	int max = 0,maxPopular = 0;
	for (int i = 0;i < size - 1;i++)
	{
		max = 0;
		for (int j = i + 1;j < size;j++)
		{
			if (list[i].Fio.name == list[j].Fio.name)
			{
				max++;
			}
		}
		if (max > maxPopular)
		{
			maxPopular = max;
			popularName = list[i].Fio.name;
		}
	}
	return popularName;
}

void sortList(studentsList* list, int& size)
{
	studentsList sort;
	for (int i = 0;i < size / 2;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (list[i].Fio.surname <= list[j].Fio.surname)
			{
				sort = list[i];
				list[i] = list[j];
				list[j] = sort;
			}
		}
	}
}

void getCurrentDate(int& currentYear, int& currentMonth, int& currentDay)
{
	time_t now = time(0);
	struct tm* ltm = new tm;
	localtime_s(ltm, &now);

	currentYear = 1900 + ltm->tm_year;
	currentMonth = 1 + ltm->tm_mon;
	currentDay = ltm->tm_mday;
}

void getAgeStudent(studentsList* list, int& size, int& currentYear, int& currentMonth, int& currentDay)
{
	for (int i = 0;i < size;i++)
	{
		list[i].age.year = currentYear - list[i].birthaday.year;
		if (currentMonth >= list[i].birthaday.month)
		{
			list[i].age.month = currentMonth - list[i].birthaday.month;
		}
		else
		{
			list[i].age.year--;
			list[i].age.month = 12 + currentMonth - list[i].birthaday.month;
		}
		if (currentDay >= list[i].birthaday.day)
		{
			list[i].age.day = currentDay - list[i].birthaday.day;
		}
		else
		{
			if (list[i].age.month == 0)
			{
				list[i].age.year--;
				list[i].age.day = 31 + currentDay - list[i].birthaday.day;
				list[i].age.month == 11;
			}
			else
			{
				list[i].age.month--;
				list[i].age.day = currentDay - list[i].birthaday.day;
				switch(currentMonth - 2)
				{
				case 0:
					list[i].age.day += 31;
					break;
				case 1:
					if (!currentYear % 4)
					{
						list[i].age.day += 29;
					}
					else
					{
						list[i].age.day += 28;
					}
					break;
				case 2:
					list[i].age.day+=31;
					break;
				case 3:
					list[i].age.day+=30;
					break;
				case 4:
					list[i].age.day+=31;
					break;
				case 5:
					list[i].age.day+=30;
					break;
				case 6:
					list[i].age.day+=31;
					break;
				case 7:
					list[i].age.day+=31;
					break;
				case 8:
					list[i].age.day+=30;
					break;
				case 9:
					list[i].age.day+=31;
					break;
				case 10:
					list[i].age.day+=30;
					break;
				case 11:
					list[i].age.day+=31;
					break;
				}
			}
		}
	}
}

void outAgeStudent(studentsList* list, int& size)
{
	cout << "Age student:" << endl;
	for (int i = 0;i < size;i++)
	{
		cout << list[i].Fio.surname << " " << list[i].Fio.name << " " << list[i].Fio.patronymic
			<< " - " << list[i].age.year << " years, " << list[i].age.month << " months, " << list[i].age.day << " days" << endl;
	}
}

date averageAge(studentsList* list, int& size)
{
	date age = { 0,0,0 };
	for (int i = 0;i < size;i++)
	{
		age.day += list[i].age.day;
		age.month += list[i].age.month;
		age.year += list[i].age.year;
	}
	age.day /= size;
	age.month /= size;
	age.year /= size;
	return age;
}