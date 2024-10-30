#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>
using namespace std;

std::pair <string, string> logining_pass();
bool isAdmin = false;
int userCount = 2;

string* loginArr = new std::string[userCount]{ "admin", "user" };
string* passwordArr = new std::string[userCount]{ "admin", "user" };

int main() {
	// Учетные записи
	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "\n\n\t\t\t Кругляш \n\n\n";
	login();
	
	return 0;
}

bool login()
{
	string login, pass;
	cout << "Введите логин";
	getline(cin, login, '\n');
	cout << "Введите пароль";
	getline(cin, pass, '\n');

	if (login == loginArr[0] && pass == passwordArr[0])
	{
		cout << "Добро пожаловать " << loginArr[0] << '\n';
		isAdmin = true;
		return true;
	}

	for (int i = 1; i < userCount; i++)
	{
		
		if (login == loginArr[i] && pass == passwordArr[i])
		{
			cout << "Добро пожаловать " << loginArr[i] << '\n';
			isAdmin = false;
			return true;
		}
	}
	system("cls");
	cout << "Логин или пароль введены неправильно";
}



std::pair <string, string> register_pass()
{
	string login_pass;
	string password_pass;
	std::cout << "Введите логин: ";
	getline(cin, login_pass, '\n');
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	do
	{
		check1 = false;
		check2 = false;
		check3 = false;
		std::cout << "Введите пароль: ";
		getline(cin, password_pass, '\n');
		for (int i = 0; i < password_pass.length(); i++)
		{
			if (isupper(password_pass[i]))
			{
				check1 = true;
			}
			if (isdigit(password_pass[i]))
			{
				check2 = true;
			}
			if ((password_pass.length() < 15))
			{
				check3 = true;
			}
			if (check1 == true && check2 == true && check3 == true)
			{
				break;
			}

		}
	} while (check1 == false || check2 == false || check3 == false);

	return std::make_pair(login_pass, password_pass);
}