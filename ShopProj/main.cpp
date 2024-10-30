#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>
#include <limits>

#if defined(max)
#undef max
#endif

//functios
std::pair <std::string, std::string> logining_pass();
void ShopAdminMenu();
void ShopUserMenu();
bool login();
void start();

//here shop db
int typesize = 10;
int* idArr = new int[typesize];
int* countArr = new int[typesize];
double* priceArr = new double[typesize];
std::string* nameArr = new std::string[typesize];


// -----------------------------------------------
bool isAdmin = false;
int userCount = 2;

std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };

int main() {
	// ������� ������
	
	start();

	
	return 0;
}

void ShopUserMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. ������ ������� \n";
			std::cout << "2. �������� ����� \n";
			std::cout << "3. ��������� ����� \n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ���� \n";
			std::cout << "6. �������� �����.";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� � �������\n";
			std::cout << "0. ������� ����� \n";

			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);
		if (choose == "1")
		{

		}
		else if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
	}
}

void ShopAdminMenu()
{
	std::string choose;
	while (true)
	{
		do
		{
			std::cout << "1. ������ ������� \n";
			std::cout << "2. �������� ����� \n";
			std::cout << "3. ������� �� ������\n";
			std::cout << "4. ����� � �������\n";
			std::cout << "5. ��������� �����\n";
			std::cout << "0. ������� ����� \n";

			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');
			system("cls");

		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);
		if (choose == "0")
		{

		}
		else if (choose == "1")
		{

		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else
		{
			std::cerr << "UserMenuError";
		}
	}
}


void start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t\t ������� \n\n\n";
	if (login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			ShopAdminMenu();
		}
		else
		{
			ShopUserMenu();
		}
	}
}



bool login()
{
	std::string login, pass;
	std::cout << "������� �����";
	std::getline(std::cin, login, '\n');
	std::cout << "������� ������";
	std::getline(std::cin, pass, '\n');



	for (int i = 1; i < userCount; i++)
	{
		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "����� ���������� " << loginArr[0] << '\n'; // admin module
			isAdmin = true;
			return true;
		}
		if (login == loginArr[i] && pass == passwordArr[i])
		{
			std::cout << "����� ���������� " << loginArr[i] << '\n';
			isAdmin = false;
			return true;
		}
	}
	system("cls");
	std::cout << "����� ��� ������ ������� �����������";
}



std::pair <std::string, std::string> register_pass()
{
	std::string login_pass;
	std::string password_pass;
	std::cout << "������� �����: ";
	std::getline(std::cin, login_pass, '\n');
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	do
	{
		check1 = false;
		check2 = false;
		check3 = false;
		std::cout << "������� ������: ";
		getline(std::cin, password_pass, '\n');
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