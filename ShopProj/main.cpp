#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <conio.h>
#include <iomanip>


#if defined(max)
#undef max
#endif

//functios define
void AddEmployee();
void ChangeStaff();
void RemoveFromStorage();
bool isStringDigit(std::string string);
void RefillStorage();
void CreateStaticStorage();
void ShowStorage();
template<typename ArrType> void FillStorage(ArrType staticArr[], ArrType dynamicArr[], int size);
// std::pair <std::string, std::string> logining_pass(); for a while, this function isn't needable
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
	std::cout << "ID\tНазвание\t\t\tКол-во\tЦена\n";
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

void AddEmployee() {
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];

	std::string newLogin, newPass;

	std::cout << "Введите логин нового сотрудника: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "Введите пароль нового сотрудника: ";
	std::getline(std::cin, newPass, '\n');

	tempLogin[userCount - 1] = newLogin;
	tempPass[userCount - 1] = newPass;

	std::swap(tempLogin, loginArr);
	std::swap(tempPass, passwordArr);

	delete[] tempLogin;
	delete[] tempPass;
	std::cout << "Пользователь был успешно добавлен!";
	Sleep(3500);
	system("cls");
}

void ChangeStaff() {
	system("cls");
	std::string choose1;

	while (true) {
		std::cout << "1 - Добавить нового сотрудника\n2 - Отредактировать учетную запись сотрудника\n"
			"3 - Удалить сотрудника\n0 - Выход\n\nВвод: ";
		std::getline(std::cin, choose1, '\n');

		if (choose1 == "1")
		{
			AddEmployee();
		}
		if (choose1 == "2")
		{

		}
		if (choose1 == "3")
		{

		}
		if (choose1 == "0")
		{
			system("cls");
			break;
		}
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

void RemoveFromStorage()
{
	system("cls");
	ShowStorage();
	std::cout << "\n\n\n";
	std::string idStr, removeStr, choose;
	int id{}, remove;
	bool exit = false;
	while (!exit)
	{

		while (true)
		{
			std::cout << "Cписание со склада склада \nВведите id товара: ";
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
				std::cout << "Ошибка ввода";

			}
			if (id > 0 && id <= typesize)
			{
				system("cls");
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
		}
		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n Кол-во товара: " << countArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "Введите кол-во товаров на списание со склада: ";
			std::getline(std::cin, removeStr, '\n');
			if (isStringDigit(removeStr))
			{
				remove = std::stoi(removeStr);
			}
			if (remove >= 0 && remove < countArr[id - 1])
			{
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
		}
		while (true)
		{

			std::cout << "Списать? " << remove << " товара(ов)" << nameArr[id - 1] << "?\n";
			std::cout << "1 - Да\t\t2 - Нет\t\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				countArr[id - 1] -= remove;
				std::cout << "Товар успешно списан\n\n";
				exit = true;
				break;
			}
			if (choose == "2")
			{
				break;
			}
			if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cerr << "Ошибка ввода";
			}
		}

	}
}

void ChangePrice()
{
	system("cls");
	ShowStorage();
	std::cout << "\n\n\n";
	std::string idStr, changeStr, choose;
	int id{};
	double change;
	bool exit = false;

	while (!exit)
	{

		while (true)
		{
			std::cout << "Изменение цены товара\nВведите id товара: ";
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
				std::cout << "Ошибка ввода";

			}
			if (id > 0 && id <= typesize)
			{
				system("cls");
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
		}
		std::cout << "\n\n" << idArr[id - 1] << " " << nameArr[id - 1] << "\n Цена товара: " << priceArr[id - 1] << "\n\n";

		while (true)
		{
			std::cout << "Введите новую цену арбуза за кг: ";
			std::getline(std::cin, changeStr, '\n');
			if (isStringDigit(changeStr))
			{
				change = std::stoi(changeStr);
			}
			if (change >= 0 && change <= 150)
			{
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
		}
		while (true)
		{

			std::cout << "Назначить товару " <<  nameArr[id - 1] << " новую цену" << "?\n";
			std::cout << "1 - Да\t\t2 - Нет\t\t3 - Отмена\n\n";
			std::getline(std::cin, choose, '\n');

			if (choose == "1")
			{
				priceArr[id - 1] = (change + 0.9);
				std::cout << "Цена успешно установлена\n\n";
				exit = true;
				break;
			}
			if (choose == "2")
			{
				break;
			}
			if (choose == "3")
			{
				exit = true;
				break;
			}
			else
			{
				std::cerr << "Ошибка ввода";
			}
		}

	}
}

void RefillStorage() {

	system("cls");
	ShowStorage();
	std::cout << "\n\n\n";
	std::string idStr, addStr, choose;
	int id{}, add;
	bool exit = false;
	while (!exit)
	{

		while (true)
		{
			std::cout << "Пополнение склада \nВведите id товара: ";
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
				std::cout << "Ошибка ввода";

			}
			if (id > 0 && id <= typesize)
			{
				system("cls");
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
		}
		std::cout << "\n\n" << idArr[id - 1] << "\t" << nameArr[id - 1] <<"\t" << countArr[id - 1] << "\n\n";

	while (true)
	{
		std::cout << "Введите кол-во товаров на пополнение: ";
		std::getline(std::cin, addStr, '\n');
			if (isStringDigit(addStr))
			{
				add = std::stoi(addStr);
			}
			if (add >= 0 && add < 30)
			{
				break;
			}
			else
			{
				std::cout << "Ошибка ввода";
			}
	}
	while(true)
	{

		std::cout << "Добавить " << add << " товара(ов)" << nameArr[id - 1] << "?\n";
		std::cout << "1 - Да\t\t2 - Нет\t\t3 - Отмена\n\n";
		std::getline(std::cin, choose, '\n');

		if (choose == "1")
		{
			countArr[id - 1] += add;
			std::cout << "Товар успешно пополнен\n\n";
			exit = true;
			break;
		}
		if (choose == "2")
		{
			break;
		}
		if (choose == "3")
		{
			exit = true;
			break;
		}
		else
		{
			std::cerr << "Ошибка ввода";
		}
	}

}

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
			RemoveFromStorage();
		}
		else if (choose == "4")
		{
			
		}
		else if (choose == "5")
		{
			RefillStorage();
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

		std::string choose;


		do
		{
			std::cout << "Ввод: ";
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
				RefillStorage();
			}
			else if (choose == "4")
			{
				RemoveFromStorage();
			}
			else if (choose == "5")
			{
				ChangePrice();
			}
			else if (choose == "6")
			{

			}
			else if (choose == "7")
			{
				ChangeStaff();
			}
			else if (choose == "8")
			{

			}
			else
			{
				std::cerr << "AdminMenuError";
				Sleep(3000);
				system("cls");
				break;
			}
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);
	}
}

void start()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SetConsoleCP(CP_UTF8);
	//setlocale(LC_ALL, "ru");
	std::cout << "\n\n\t\t\t Кругляш \n\n\n";
	if (login() == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		{
			bool enter = false;
			while(!enter)
			{
				std::cout << "1 - Использовать готовый склад \n2 - Создать новый склад\n";
				char key = _getch();
				if (key == '1')
				{
					CreateStaticStorage();
					enter = true;
				}
				else if (key == '2')
				{
					// Динамический склад
					std::cerr << "error type: 403";
					Sleep(3000);
					system("cls");
					continue;
				}
				else
				{
					std::cerr << "Ошибка ввода";
					Sleep(3000);
					system("cls");
					continue;
				}
			}

			std::cout << "\n\n";
			ShopAdminMenu();
		}
		else
		{
			std::cout << "\n\n";
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
		return true;
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
/*
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
*/