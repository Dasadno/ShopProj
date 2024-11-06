#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>
#include <limits>
#include <conio.h>
#include <iomanip>


#if defined(max)
#undef max
#endif

//functios define
bool isStringDigit(std::string string);
void RefilStorage();
void CreateStaticStorage();
void ShowStorage();
template<typename ArrType> void FillStorage(ArrType staticArr[], ArrType dynamicArr[], int size);
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
// need to think about things, that i need to sale
// -----------------------------------------------
bool isAdmin = false;
int userCount = 2;

std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };

int main() {
	
	start();

	delete[] idArr;
	delete[] countArr;
	delete[] priceArr;
	delete[] nameArr;
	delete[] loginArr;
	delete[] passwordArr;

	return 0;
}
//functions -------------------------------------------

void ShowStorage()
{
	system("cls");
	std::cout << "ID\t��������\t\t\t���-��\t����\n";
	for (int i = 0; i < typesize; i++)
	{
		std::cout << idArr[i] << '\t' << std::left << std::setw(30) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
		
	}

}

void StartSells() 
{

}

template<typename ArrType>
void FillStorage(ArrType staticArr[], ArrType dynamicArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
void CreateStaticStorage()
{
	const int staticSize = 10;

	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string nameStaticArr[staticSize]
	{
		"����� �����", "����� ������, ��� �������",
		"����� ���������", "����� �������������",
		"����� ���������������", "����� �����", "����� ���������",
		"���� ���������������", "���� ���������", "���� �����"
	};

	int countStaticArr[staticSize]{ 12,8,6,11,7,15,8,9,7,8 };
	double priceStaticArr[staticSize]{ 49.9, 69.9, 29.9, 35.9, 39.9, 26.9, 34.9, 34.9, 41.5, 32.9 };

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);
	ShowStorage();
}
bool isStringDigit(std::string string)
{
	for (int i = 0; i < string.size(); i++)
	{
		if (!std::isdigit(string[i]))
		{
			return false;
		}

	}
	return true;
}

void RemoveStoragePoint()
{

}
void ChangePrice()
{

}
void RefilStorage() {
	std::string idStr, addStr, choose;
	std::cout << "���������� ������ \n������� id ������: ";
	std::getline(std::cin, idStr, '\n');
	int id{}, add;	
	
	while (true)
	{
		std::getline(std::cin, idStr, '\n');

		if (std::isdigit(idStr[0]) && idStr.size() == 1)
		{
			id = std::stoi(idStr);
			
		}
		else if (std::isdigit(idStr[0]) && std::isdigit(idStr[1]) && idStr.size() == 2)
		{
			id = std::stoi(idStr);
			
		}
		else
		{
			std::cout << "������ �����";
	
		}
		if (id > 0 && id <= typesize)
		{	
			system("cls");
		}
		else
		{
			std::cout << "������ �����";
		}
	}
	std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n\n";

	while(true)
	{
		std::cout << "������� ���-�� ������� �� ����������: ";
		std::getline(std::cin, addStr, '\n');
	if(add >= 0 && add < 100)
		if (isStringDigit(addStr))
		{
			add = std::stoi(addStr);
		}
		else
		{
			std::cout << "������ �����";
		}
	}

	std::cout << "�������� " << add << " ������(��)" << nameArr[id - 1] << "?";
	std::cout << "1 - ��\t2 - ���\t3 - ������\n\n";
	std::getline(std::cin, choose, '\n');
	if (choose == "1")
	{

	}

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
			RefilStorage();
		}
		else
		{
			std::cerr << "UserMenuError";
		}
	}
}

void ShopAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1. ������ ������� \n";
		std::cout << "2. �������� ����� \n";
		std::cout << "3. ��������� ����� \n";
		std::cout << "4. ������� �� ������\n";
		std::cout << "5. �������� ���� \n";
		std::cout << "6. �������� �����\n";
		std::cout << "7. �������� ��������\n";
		std::cout << "8. ����� � �������\n";
		std::cout << "0. ������� ����� \n";

		std::string choose;


		do
		{
			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');



			if (choose == "0")
			{

			}
			else if (choose == "1")
			{
			
			}
			else if (choose == "2")
			{
				ShowStorage();
			}
			else if (choose == "3")
			{
				RefilStorage();
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
			else
			{
				std::cerr << "UserMenuError";
				break;
			}
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);
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
			
			std::cout << "1 - ������������ ������� ����� \n2 - ������� ����� �����\n";
			char key = _getch();
			if (key == '1')
			{
				CreateStaticStorage();
			}
			else if (key == '2')
			{
				// ������������ �����
			}


			ShopAdminMenu();
		}
		else
		{
			CreateStaticStorage();
			ShopUserMenu();
		}
	}
}

bool login()
{
	std::string login, pass;
	std::cout << "������� �����: ";
	std::getline(std::cin, login, '\n');
	std::cout << "������� ������: ";
	std::getline(std::cin, pass, '\n');

	if (login == loginArr[0] && pass == passwordArr[0])
	{
		std::cout << "����� ���������� " << loginArr[0] << '\n';
		isAdmin = true;
		return true;
	}



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


//register helper if i will use db
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
			if (password_pass.length() < 15 && password_pass.length() > 8)
			{
				check3 = true;
			}
			else if (password_pass.length() < 8)
			{
				std::cout << "������ �� ����� ���� ������ 8 ��������.\n";
			}
			if (check1 == true && check2 == true && check3 == true)
			{
				break;
			}
			else
			{
				std::cout << "� ������ ������ �������������� ��������� ����� � �����.\n";
			}

		}
	} while (check1 == false || check2 == false || check3 == false);

	return std::make_pair(login_pass, password_pass);
}