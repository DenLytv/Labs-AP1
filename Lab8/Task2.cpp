#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h>

struct Book {
	std::string title;
	std::string author;
	std::string publisher;
	unsigned int year;
	unsigned int pagesNumber;
};


void menu(const std::string& fileName, std::vector<Book>& books);
std::vector<Book> readBooksFromFile(const std::string& fileName);
void addBook(std::vector<Book>& books, const std::string& fileName);
void showLibrary(std::vector<Book>& books);
std::string stringPropertyInput(std::string propName);
unsigned int pagesNumberPropertyInput();
unsigned int yearPropertyInput();
void writeDataInFile(std::vector<Book>& books, const std::string& fileName);
void modifyBook(std::vector<Book>& books, const std::string& fileName);
void deleteBook(std::vector<Book>& books, const std::string& fileName);
bool compareByAuthor(const Book& a, const Book& b);
bool compareByPublisher(const Book& a, const Book& b);
bool compareByYear(const Book& a, const Book& b);
bool compareByTitle(const Book& a, const Book& b);
bool compareByPagesNumber(const Book& a, const Book& b);
void sortLibrary(std::vector<Book>& books, const std::string& fileName);
void searchBooks(const std::vector<Book>& books, char option);
void printBook(std::vector<Book>& books, std::vector<int>& indexes, std::string propValue, std::string propName);
void searchMenu(std::vector<Book>& books);
unsigned int inputSearchProp(std::string propName);

int main() {
	const std::string fileName = "MyLibrary.txt";
	std::vector<Book> books = readBooksFromFile("MyLibrary.txt");
	if (books.size() == 0) {
		return 1;
	}
	menu(fileName, books);
	system("cls");
	std::cout << "Thank you!!";
	return 0;
}

void menu(const std::string& fileName, std::vector<Book>& books) {
	char answer;
	do
	{
		while (true)
		{
			system("cls");
			std::cout << "================== Library ===================\n";
			std::cout << "Choose option:\n[1] - Add a new book to the library;\n[2] - Search a book;\n[3] - See the entire library;\n[4] - Modify a book in the library;\n";
			std::cout << "[5] - Delete a book;\n[6] - Sort the library;\n[0] - Exit; \nInput: ";
			std::cin >> answer;
			if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '5' || answer == '6' || answer == '0')
			{
				break;
			}
		}
		switch (answer)
		{
		case '1':
			addBook(books, fileName);
			break;
		case '2':
			searchMenu(books);
			break;
		case '3':
			showLibrary(books);
			break;
		case '4':
			modifyBook(books, fileName);
			break;
		case '5':
			deleteBook(books, fileName);
			break;
		case '6':
			sortLibrary(books, fileName);
			break;
		}
	} while (answer != '0');
}

void searchMenu(std::vector<Book>& books) {
	char answer;
	do
	{
		while (true)
		{
			system("cls");
			std::cout << "================== Book Searching ===================\n";
			std::cout << "Please choose option:\n[1] - By title;\n[2] - By author;\n[3] - By publisher;\n[4] - By year;\n[5] - By number of the pages;\n[0] - Exit;\nInput: ";
			std::cin >> answer;
			if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '5' || answer == '0')
			{
				break;
			}
		}
		system("cls");
		if (answer != '0') {
			std::cin.ignore();
			searchBooks(books, answer);
		}
	} while (answer != '0');
}

std::vector<Book> readBooksFromFile(const std::string& fileName) {
	std::vector<Book> books{};
	std::ifstream file(fileName);

	if (!file.is_open()) {
		std::cerr << "Error opening file. Please add at least one book and create the library file '" << fileName << "'" << std::endl;
		return books;
	}

	std::string line = "";
	while (getline(file, line)) {
		Book book;
		std::stringstream iss(line);

		getline(iss, book.title, '\t');
		getline(iss, book.author, '\t');
		getline(iss, book.publisher, '\t');

		iss >> book.year;
		iss >> book.pagesNumber;

		books.push_back(book);
	}
	file.close();
	return books;
}

void printBook(std::vector<Book>& books, std::vector<int>& indexes, std::string propValue, std::string propName) {
	system("cls");
	if (books.empty()) {
		std::cout << "No books found for the " << propName << "'" << propValue << "'." << std::endl;
	}
	else {
		std::cout << "========= Books by " << propName << " '" << propValue << "' ========" << std::endl << std::endl;
		for (size_t i = 0, s = books.size(); i < s; i++)
		{
			std::cout << "--------- Book " << indexes[i] + 1 << " ---------" << std::endl;
			std::cout << "Title: " << books[i].title << std::endl;
			std::cout << "Author: " << books[i].author << std::endl;
			std::cout << "Publisher: " << books[i].publisher << std::endl;
			std::cout << "Publish year: " << books[i].year << std::endl;
			std::cout << "Number of pages: " << books[i].pagesNumber << std::endl << std::endl;
		}
	}
	std::cout << "\nPress any button to continue:\n";
	_getch();
}

void addBook(std::vector<Book>& books, const std::string& fileName) {
	system("cls");
	Book newbook;
	system("cls");
	std::cout << "================== Book Adding ===================\n";

	std::cin.ignore();
	newbook.title = stringPropertyInput("title");
	newbook.author = stringPropertyInput("author's surname and name");
	newbook.publisher = stringPropertyInput("publisher");
	newbook.year = yearPropertyInput();
	newbook.pagesNumber = pagesNumberPropertyInput();

	books.push_back(newbook);
	std::ofstream outputFile(fileName, std::ios::app);
	if (!outputFile.is_open())
	{
		system("cls");
		std::cerr << "Error opening the file for writing." << std::endl;
		return;
	}
	outputFile << newbook.title << '\t' << newbook.author << '\t' << newbook.publisher << '\t' << newbook.year << '\t' << newbook.pagesNumber << std::endl;
	outputFile.close();
	std::cout << '\n' << "New book added and written to the file successfully." << '\n' << std::endl;
	std::cout << "Press any button to continue:\n";
	_getch();
}

void searchBooks(const std::vector<Book>& books, char option) {
	system("cls");
	std::vector<Book> result{};
	std::vector<int> indexes{};
	size_t index = 0;
	std::string propName = "";
	std::string propValue = "";
	if (option == '1' || option == '2' || option == '3')
	{
		std::string propToFind = "";
		if (option == '1') {
			propName = "title";
		}
		else if (option == '2') {
			propName = "author";
		}
		else {
			propName = "publisher";
		}

		std::cout << "================== Books Searching ===================\n";
		propToFind = stringPropertyInput(propName);
		propValue = propToFind;

		transform(propToFind.begin(), propToFind.end(), propToFind.begin(), ::tolower);

		std::string propLowerCase = "";
		for (const Book& book : books) {
			if (option == '1')
				propLowerCase = book.title;
			else if (option == '2')
				propLowerCase = book.author;
			else
				propLowerCase = book.publisher;

			transform(propLowerCase.begin(), propLowerCase.end(), propLowerCase.begin(), ::tolower);

			if (propLowerCase == propToFind) {
				result.push_back(book);
				indexes.push_back(index);
			}
			++index;
		}
	}
	else
	{
		std::cout << "================== Books Searching ===================\n";
		if (option == '4') {
			propName = "year";
		}
		else {
			propName = "number of pages";
		}

		unsigned int propToFind;

		propToFind = inputSearchProp(propName);
		
		std::stringstream ss;
		ss << propToFind;
		propValue = ss.str();
		for (const Book& book : books) {
			if (option == '4') {
				if (book.year == propToFind) {
					result.push_back(book);
					indexes.push_back(index);
				}
			}
			else
			{
				if (book.pagesNumber == propToFind) {
					result.push_back(book);
					indexes.push_back(index);
				}
			}
			++index;
		}
	}

	printBook(result, indexes, propValue, propName);
}

unsigned int inputSearchProp(std::string propName) {
	unsigned int propToFind = 0;
	std::string inputStr = "";

	while (true)
	{
		try
		{
			std::cout << "Please enter the " << propName <<  " (> 0) : ";
			std::getline(std::cin, inputStr);
			propToFind = std::stoi(inputStr);
			if (propToFind > 4000000000) {
				std::cout << "Error " << propName << " of book!!!Your " << propName << " is < 0" << std::endl;
			}
			if (propToFind < 4000000000) {
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Error " << propName << " of book!!!Your " << propName << " is not a number or too big" << std::endl;
		}
	}

	return propToFind;
}

void showLibrary(std::vector<Book>& books) {
	system("cls");
	if (books.size() == 0) {
		std::cout << "The library is empty, you should add a book at first." << std::endl;
	}
	else {
		std::cout << "========= Library" << " =========" << std::endl << std::endl;
		size_t i = 0;
		for (const Book& book : books) {
			std::cout << "--------- Book " << ++i << " ---------" << std::endl;
			std::cout << "Title: " << book.title << std::endl;
			std::cout << "Author: " << book.author << std::endl;
			std::cout << "Publisher: " << book.publisher << std::endl;
			std::cout << "Publish year: " << book.year << std::endl;
			std::cout << "Number of pages: " << book.pagesNumber << std::endl << std::endl;
		}
	}
	std::cout << "Press any button to continue:\n";
	_getch();
}

std::string stringPropertyInput(std::string propName) {
	std::string newProp = "";
	do
	{
		std::cout << "Please enter the " << propName << ": ";
		std::getline(std::cin, newProp);
		if (newProp.empty()) {
			std::cout << "Error " << propName << "!!!Your " << propName << " is empty" << std::endl;
		}
	} while (newProp.empty());
	return newProp;
}

unsigned int yearPropertyInput() {
	unsigned int newProp = 0;
	std::string inputStr = "";

	while (true)
	{
		try
		{		
			std::cout << "Please enter the publish year of book (< 3000 and >= 0): ";
			std::getline(std::cin, inputStr);
			newProp = std::stoi(inputStr);
			if (newProp > 3000) {
				std::cout << "Error publish year of book!!!Your year is >= 3000 or < 0" << std::endl;
			}
			if (newProp < 3000) {
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Error publish year of book!!!Your year is not a number or too big" << std::endl;
		}
	}
	return newProp;
}

unsigned int pagesNumberPropertyInput() {
	unsigned int newProp = 0;
	std::string inputStr = "";

	while (true)
	{
		try
		{
			std::cout << "Please enter the pages number of book (< 21 541 and > 0): ";
			std::getline(std::cin, inputStr);
			newProp = std::stoi(inputStr);
			if (newProp >= 21541 || newProp == 0) {
				std::cout << "Error pages number of book!!!Your number is >= 21 541 or < 0" << std::endl;
			}
			if (newProp < 21541 && newProp > 0) {
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Error pages number of book!!!It's not a number or it's too big" << std::endl;
		}
	}
	return newProp;
}

void writeDataInFile(std::vector<Book>& books, const std::string& fileName) {
	std::ofstream outputFile(fileName);
	if (!outputFile.is_open()) {
		std::cerr << "Error opening the file for writing." << std::endl;
		return;
	}

	for (const Book& book : books) {
		outputFile << book.title << '\t' << book.author << '\t' << book.publisher << '\t' << book.year << '\t' << book.pagesNumber << std::endl;
	}

	outputFile.close();
	std::cout << "\n";
	std::cout << "File successfully updated." << std::endl << std::endl;
	std::cout << "Press any button to continue:\n";
	_getch();
}

void modifyBook(std::vector<Book>& books, const std::string& fileName) {
	system("cls");
	std::cout << "================== Book Editing ===================\n";
	size_t bookIndex = 0;
	std::string inputStr = "";
	std::cin.ignore();
	while (true)
	{
		try
		{
			std::cout << "Enter the number of the book you want to modify: ";
			std::getline(std::cin, inputStr);
			bookIndex = std::stoi(inputStr);
			if (bookIndex > books.size() || bookIndex == 0) {
				std::cout << "Error book number!!!Your number must be > 0 and < " << books.size() + 1 << std::endl;
			}
			if (bookIndex < books.size() + 1 && bookIndex > 0) {
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Error number of book!!!It's not a number or it's too big" << std::endl;
		}
	}

	Book& bookToModify = books[bookIndex - 1];

	char answer = '0';
	do
	{
		while (true)
		{
			system("cls");
			std::cout << "================== Book Editing ===================\n";
			std::cout << "Please choose what you want to modify:\n[1] - Title;\n[2] - Author;\n[3] - Publisher;\n[4] - Year;\n[5] - Number of pages;\n[0] - Exit;\nInput: ";
			std::cin >> answer;
			if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '5' || answer == '0')
			{
				break;
			}
		}
		system("cls");
		std::cout << "================== Book Editing ===================\n";
		switch (answer)
		{
		case '1':
			std::cout << "Current Title: " << bookToModify.title << std::endl << std::endl;
			std::cin.ignore();
			bookToModify.title = stringPropertyInput("title");
			writeDataInFile(books, fileName);
			break;
		case '2':
			std::cout << "Current Author: " << bookToModify.author << std::endl << std::endl;
			std::cin.ignore();
			bookToModify.author = stringPropertyInput("author");
			writeDataInFile(books, fileName);
			break;
		case '3':
			std::cout << "Current Publisher: " << bookToModify.publisher << std::endl << std::endl;
			std::cin.ignore();
			bookToModify.publisher = stringPropertyInput("publisher");
			writeDataInFile(books, fileName);
			break;
		case '4':
			std::cout << "Current Year: " << bookToModify.year << std::endl << std::endl;
			std::cin.ignore();
			bookToModify.year = yearPropertyInput();
			writeDataInFile(books, fileName);
			break;
		case '5':
			std::cout << "Current Number of Pages: " << bookToModify.pagesNumber << std::endl << std::endl;
			std::cin.ignore();
			bookToModify.pagesNumber = pagesNumberPropertyInput();
			writeDataInFile(books, fileName);
			break;
		}
	} while (answer != '0');
}

void deleteBook(std::vector<Book>& books, const std::string& fileName) {
	system("cls");
	std::cout << "================== Book Deleting ===================\n";

	size_t bookIndex = 0;
	std::string inputStr = "";
	std::cin.ignore();
	while (true)
	{
		try
		{
			std::cout << "Enter the number of the book you want to modify: ";
			std::getline(std::cin, inputStr);
			bookIndex = std::stoi(inputStr);
			if (bookIndex > books.size() || bookIndex == 0) {
				std::cout << "Error book number!!!Your number must be > 0 and < " << books.size() + 1 << std::endl;
			}
			if (bookIndex < books.size() + 1 && bookIndex > 0) {
				break;
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Error number of book!!!It's not a number or it's too big" << std::endl;
		}
	}

	char answer;
	while (true)
	{
		std::cout << "Are you sure?\n[Y] or [y] - Yes;\n[N] or [n] - No;\nInput: ";
		std::cin >> answer;
		answer = tolower(answer);
		if (answer == 'y' || answer == 'n')
		{
			break;
		}
	}

	if (answer == 'y') {
		Book& bookToDelete = books[bookIndex - 1];

		system("cls");
		std::cout << "================== Book Deleting ===================\n";
		std::cout << "Deleting the following book:" << std::endl;
		std::cout << "Title: " << bookToDelete.title << std::endl;
		std::cout << "Author: " << bookToDelete.author << std::endl;
		std::cout << "Publisher: " << bookToDelete.publisher << std::endl;
		std::cout << "Year: " << bookToDelete.year << std::endl;
		std::cout << "Number of Pages: " << bookToDelete.pagesNumber << std::endl << std::endl;

		books.erase(books.begin() + (bookIndex - 1));
		writeDataInFile(books, fileName);
	}
}

bool compareByTitle(const Book& a, const Book& b) {
	return a.title < b.title;
}

bool compareByAuthor(const Book& a, const Book& b) {
	return a.author < b.author;
}

bool compareByPublisher(const Book& a, const Book& b) {
	return a.publisher < b.publisher;
}

bool compareByYear(const Book& a, const Book& b) {
	return a.year < b.year;
}

bool compareByPagesNumber(const Book& a, const Book& b) {
	return a.pagesNumber < b.pagesNumber;
}

void sortLibrary(std::vector<Book>& books, const std::string& fileName) {
	char answer = '0';
	do
	{
		while (true)
		{
			system("cls");
			std::cout << "================== Books Sorting ===================\n";
			std::cout << "Please choose how you want to sort the Library:\n[1] - Title;\n[2] - Author;\n[3] - Publisher;\n[4] - Year;\n[5] - Number of pages;\n[0] - Exit\nInput: ";
			std::cin >> answer;
			if (answer == '1' || answer == '2' || answer == '3' || answer == '4' || answer == '5' || answer == '0')
			{
				break;
			}
		}
		switch (answer)
		{
		case '1':
			sort(books.begin(), books.end(), compareByTitle);
			writeDataInFile(books, fileName);
			showLibrary(books);
			break;
		case '2':
			sort(books.begin(), books.end(), compareByAuthor);
			writeDataInFile(books, fileName);
			showLibrary(books);
			break;
		case '3':
			sort(books.begin(), books.end(), compareByPublisher);
			writeDataInFile(books, fileName);
			showLibrary(books);
			break;
		case '4':
			sort(books.begin(), books.end(), compareByYear);
			writeDataInFile(books, fileName);
			showLibrary(books);
			break;
		case '5':
			sort(books.begin(), books.end(), compareByPagesNumber);
			writeDataInFile(books, fileName);
			showLibrary(books);
			break;
		}
	} while (answer != '0');
}