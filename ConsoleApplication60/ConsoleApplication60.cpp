// ConsoleApplication60.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include<clocale>
#include<string>
using namespace std;

class Book {
	string author;
	string name;
	string publishing_house;
	unsigned short year;
	unsigned short number_pages;
public:
	Book();
	Book(const Book& tmp);
	Book(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages);
	explicit Book(unsigned short number_pages);
	void init(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages);
	void show() const;
	void showAuthor(const string author);
	void showPublishing_house(const string publishing_house);
	void showYear(unsigned short year);
	void setAuthor(const string author);
	void setName(const string name);
	void setPublishing_house(const string publishing_house);
	void setYear(unsigned short year);
	void setNumber_pages(unsigned short number_pages);
	const string getAuthor()const;
	const string getName()const;
	const string getPublishing_house()const;
	unsigned short getYear()const;
	unsigned short getNumber_pages()const;
	~Book();
};

int main() {
	setlocale(LC_ALL, "Rus");
	const int size = 3;
	Book mas[size];
	mas[0].init("Адитья Бхаргава", "Grokking Algorithms: An illustrated guide for programmers and other curious people", "Питер", 2017, 370);
	mas[1].init("Игорь Савчук", "Отъявленный программист: Лайфхакинг из первых рук", "Питер", 2015, 272);
	mas[2].init("Бен Клеменс", "21st Century C", "ДМК Пресс", 2015, 376);

	cout << "Список книг Бен'a:\n";
	for (int i = 0; i < size; i++) {
		mas[i].showAuthor("Бен");
	}
	cout << "---------------------------------------------\n";

	cout << "Список книг издательства Питер:\n";
	for (int i = 0; i < size; i++) {
		mas[i].showPublishing_house("Питер");
	}
	cout << "---------------------------------------------\n";

	cout << "Список книг после 2000:\n";
	for (int i = 0; i < size; i++) {
		mas[i].showYear(2000);
	}

	system("pause");
}

Book::Book()
{
	this->year = NULL;
	this->number_pages = NULL;
}

Book::Book(const Book & tmp)
{
	this->author = tmp.author;
	this->name = tmp.name;
	this->publishing_house = tmp.publishing_house;
	this->year = tmp.year;
	this->number_pages = tmp.number_pages;
}

Book::Book(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages)
{
	this->author = author;
	this->name = name;
	this->publishing_house = publishing_house;
	this->year = year;
	this->number_pages = number_pages;
}

Book::Book(unsigned short number_pages)
{
	this->number_pages = number_pages;
}

void Book::init(const string author, const string name, const string publishing_house, unsigned short year, unsigned short number_pages)
{
	this->author = author;
	this->name = name;
	this->publishing_house = publishing_house;
	this->year = year;
	this->number_pages = number_pages;
}

void Book::show() const
{
	cout << "Author: " << author << endl;
	cout << "Name: " << name << endl;
	cout << "Publishing house: " << publishing_house << endl;
	cout << "Year: " << year << endl;
	cout << "Number page: " << number_pages << endl << endl;
}

void Book::showAuthor(const string author)
{

	if (this->author == author)
		show();
	else
	{
		string tmp = this->author;
		char *s = new char[tmp.size() + 1];
		char *nextToken;
		strcpy_s(s, tmp.size() + 1, tmp.c_str());
		char *p = strtok_s(s, " ", &nextToken);
		while (p != NULL) {
			if (strcmp(author.c_str(), p) == 0)
			{
				show();
				break;
			}
			p = strtok_s(NULL, " ", &nextToken);
		}
		delete[] s;
	}
}

void Book::showPublishing_house(const string publishing_house)
{
	if (this->publishing_house == publishing_house)
		show();
}

void Book::showYear(unsigned short year)
{
	if (this->year > year)
		show();
}

void Book::setAuthor(const string author)
{
	this->author = author;
}

void Book::setName(const string name)
{
	this->name = name;
}

void Book::setPublishing_house(const string publishing_house)
{
	this->publishing_house = publishing_house;
}

void Book::setYear(unsigned short year)
{
	this->year = year;
}

void Book::setNumber_pages(unsigned short number_pages)
{
	this->number_pages = number_pages;
}

const string Book::getAuthor() const
{
	return author;
}

const string Book::getName() const
{
	return name;
}

const string Book::getPublishing_house() const
{
	return publishing_house;
}

unsigned short Book::getYear() const
{
	return year;
}

unsigned short Book::getNumber_pages() const
{
	return number_pages;
}

Book::~Book()
{
}