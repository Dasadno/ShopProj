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
	std::cout << "ID\tНазвание\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < typesize; i++)
	{
		std::cout << idArr[i] << std::left << std::setw(40) << "\t" << nameArr[i] << "\t"
			<< countArr[i] << "\t" << priceArr[i] << "\n";
	}
}

void StartSells() 
{

}

void ShowWarehouse()
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
		"Арбуз Гаваи", "Арбуз желтый, без семечек",
		"Арбуз Абхазский", "Арбуз Волгоградский",
		"Арбуз Азербайджанский", "Арбуз Ахмад", "Арбуз Чеченский",
		"Дыня Азербайджанская", "Дыня Чеченская", "Дыня Шишка"
	};

	int countStaticArr[staticSize]{ 12,8,6,11,7,15,8,9,7,8 };
	double priceStaticArr[staticSize]{ 49.9, 69.9, 29.9, 35.9, 39.9, 26.9, 34.9, 34.9, 41.5, 32.9 };

	FillStorage(idStaticArr, idArr, staticSize);
	FillStorage(nameStaticArr, nameArr, staticSize);
	FillStorage(countStaticArr, countArr, staticSize);
	FillStorage(priceStaticArr, priceArr, staticSize);

}
void RemoveStoragePoint()
{

}
void ChangePrice()
{

}

void ShopUserMenu()
{
	std::string choose;
	while (true)
	{

		do
		{
			std::cout << "1. Начать продажу \n";
			std::cout << "2. Показать склад \n";
			std::cout << "3. Списать со склада\n";
			std::cout << "4. Отчет о прибыли\n";
			std::cout << "5. Пополнить склад\n";
			std::cout << "0. Закрыть смену \n";

			std::cout << "Ввод: ";
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

void ShopAdminMenu()
{
	std::string choose;
	while (true)
	{
			std::cout << "1. Начать продажу \n";
			std::cout << "2. Показать склад \n";
			std::cout << "3. Пополнить склад \n";
			std::cout << "4. Списать со склада\n";
			std::cout << "5. Изменить цену \n";
			std::cout << "6. Изменить склад\n";
			std::cout << "7. Изменить персонал\n";
			std::cout << "8. Отчет о прибыли\n";
			std::cout << "0. Закрыть смену \n";

			char choose = _getch();
		
		if (choose == '1')
		{

		}
		else if (choose == '1')
		{

		}
		else if (choose == '2')
		{

		}
		else if (choose == '3')
		{

		}
		else if (choose == '4')
		{

		}
		else if (choose == '5')
		{

		}
		else if (choose == '6')
		{

		}
		else if (choose == '7')
		{

		}
		else if (choose == '8')
		{

		}
	}
}

void start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "\n\n\t\t\t Кругляш \n\n\n";
	if (login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			
			std::cout << "1 - Использовать готовый склад \n2 - Создать новый склад\n";
			char key = _getch();
			if (key == '1')
			{
				CreateStaticStorage();
			}
			else if (key == '2')
			{
				// Динамический склад
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
	std::cout << "Введите логин: ";
	std::getline(std::cin, login, '\n');
	std::cout << "Введите пароль: ";
	std::getline(std::cin, pass, '\n');

	if (login == loginArr[0] && pass == passwordArr[0])
	{
		std::cout << "Добро пожаловать " << loginArr[0] << '\n';
		isAdmin = true;

	}



	for (int i = 1; i < userCount; i++)
	{
		if (login == loginArr[0] && pass == passwordArr[0])
		{
			std::cout << "Добро пожаловать " << loginArr[0] << '\n'; // admin module
			isAdmin = true;
			return true;
		}
		if (login == loginArr[i] && pass == passwordArr[i])
		{
			std::cout << "Добро пожаловать " << loginArr[i] << '\n';
			isAdmin = false;
			return true;
		}
	}
	system("cls");
	std::cout << "Логин или пароль введены неправильно";
}


//register helper if i will use db
std::pair <std::string, std::string> register_pass()
{
	std::string login_pass;
	std::string password_pass;
	std::cout << "Введите логин: ";
	std::getline(std::cin, login_pass, '\n');
	bool check1 = false;
	bool check2 = false;
	bool check3 = false;
	do
	{
		check1 = false;
		check2 = false;
		check3 = false;
		std::cout << "Введите пароль: ";
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
				std::cout << "Пароль не может быть меньше 8 символов.\n";
			}
			if (check1 == true && check2 == true && check3 == true)
			{
				break;
			}
			else
			{
				std::cout << "В пароле должны использоваться заглавные буквы и цифры.\n";
			}

		}
	} while (check1 == false || check2 == false || check3 == false);

	return std::make_pair(login_pass, password_pass);
}