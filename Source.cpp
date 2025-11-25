#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
#include <unordered_set>


//учетки
size_t usize = 3;
size_t staffcount = 1;
std::string userstatus[3]{ "супер админ","админ","сотрудник" };
std::string* loginarr = new std::string[usize]{ "superadmin", "admin", "user" };
std::string* passwordarr = new std::string[usize]{ "superadmin", "admin", "user" };
std::string* statusarr = new std::string[usize]{ userstatus[0], userstatus[1], userstatus[2] };
std::string currentstatus;
void Changeuser();
//служебки
std::string choose, choosecount, chooseid;
std::unordered_set<char> loginsymbols;
std::unordered_set<char> passsymbols;
void Setloginsymbols();
void Setpasssymbols();
void Changepass();
void Addnewuser();
bool isloginsetcreate = false;
bool ispasssetcreate = false;
bool Checklogin(const std::string& str);
bool Checkpass(const std::string& str);
void Start();
bool Login();
inline void Err(int time = 1500);
bool isstoragecreated = false;
void Sadminmenu();
void Deleteuser();
void Addstorage();
void Removestorage();
void Changeprice();
void Addnewitem();
void Changestorage();
void Showstorage(int mode = 0);
void Createstorage();
void Changename();
void Deleteitem();
void Showuser(int mode = 0);
bool Isnumber(const std::string& str);
//склад
size_t storagesize = 0;
unsigned int* idarr;
std::string* namearr;
unsigned int* countarr;
double* pricearr;
template<typename Arrtype>
void Fillarr(Arrtype Dynarr[], Arrtype Statarr[], int arrsize)
{
	for (size_t i = 0; i < arrsize; i++)
	{
		Dynarr[i] = Statarr[i];
	}
}
void Createstorage()
{
	const int statsize = 10;
	unsigned int id[statsize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::string name[statsize]
	{
		"ложки","вилки","ножи","дрявая ложка","вилка-ложки","двухсторонние ножи","чайные ложки","приборы против вампиров","палочки",""
	};
	storagesize = statsize;
	unsigned int count[statsize]{ 57345,534568,235387,87576,24352,86789,65465,12565,909843,2365547 };
	double price[statsize]{ 13.54,24.76,45.3,53.6,45,23, 65.3,25.1, 45.54, 64.3 };
	idarr = new unsigned int[storagesize];
	namearr = new std::string[storagesize];
	pricearr = new double[storagesize];
	countarr = new unsigned int[storagesize];
	isstoragecreated = true;
	Fillarr(idarr, id, statsize);
	Fillarr(namearr, name, statsize);
	Fillarr(countarr, count, statsize);
	Fillarr(pricearr, price, statsize);
	if (isstoragecreated == false)
	{
		delete[]idarr, namearr, pricearr;
	}
}

//
inline void Getline(std::string& str)
{
	std::getline(std::cin, str, '\n');
}
bool Login()
{
	std::cout << "\n\n\n\t\t\tlozhkin's\n\n\n";
	std::string login;
	std::string password;
	while (true)
	{
		std::cout << "введите логин и пароль\n";
		Getline(login);
		Getline(password);

		if (login == "exit" && password == "exit")
		{
			currentstatus = "";
			return false;
		}
		for (size_t i = 0; i < usize; i++)
		{
			if (login == loginarr[i] && password == passwordarr[i])
			{
				system("cls");
				std::cout << "статус - " << statusarr[i] << "\n\n";
				currentstatus = statusarr[i];
				return true;
			}
		}
	}
	Err();
}

void Sadminmenu()
{
	while (true)
	{

		std::cout << "1 - начать продажу\n";
		std::cout << "2 - показать склад\n";
		std::cout << "3 - пополнить склад\n";
		std::cout << "4 - списать товар\n";
		std::cout << "5 - изменить цену\n";
		std::cout << "6 - редактировать склад\n";
		std::cout << "7 - редактировать персонал\n";
		std::cout << "8 - отчет о прибыли\n";
		std::cout << "0 - закрыть смену\n";
		std::cout << "Вывод\n";
		Getline(choose);
		system("cls");
		if (choose == "1" && storagesize > 0)
		{

		}
		else if (choose == "2" && storagesize > 0)
		{
			Showstorage();
			system("pause");
			system("cls");
		}
		else if (choose == "3" && storagesize > 0)
		{
			Addstorage();
		}
		else if (choose == "4" && storagesize > 0)
		{
			Removestorage();
		}
		else if (choose == "5" && storagesize > 0)
		{
			Changeprice();
		}
		else if (choose == "6" && storagesize > 0)
		{
			Changestorage();
		}
		else if (choose == "7" && storagesize > 0)
		{
			Changeuser();
		}
		else if (choose == "8" && storagesize > 0)
		{

		}
		else
		{
			if (storagesize < 1)
			{
				std::cout << "склад пуст\n";
			}
			Err();
		}
	}
}
void Deleteuser()
{
	std::string checkpass;
	int userid, isadmin = 1;
	while (true)
	{
		if (currentstatus == userstatus[0] && usize < 2)
		{
			std::cout << "нет доступных пользователей";
			Sleep(1500);
			break;
		}
		else if (currentstatus == userstatus[1] && staffcount == 0)
		{
			std::cout << "нет доступных пользователей";
			Sleep(1500);
			break;
		}
		//qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
	}
}
void Addnewitem()
{
	std::string newname, newprice, newcount;
	double price = 0.0;
	unsigned int count = 0;
	bool exit = true;
	while (true)
	{
		exit = true;
		while (true)
		{
			system("cls");
			std::cout << "введите название нового товара/exit\n";
			Getline(newname);
			if (newname == "exit")
			{
				std::cout << "отмена\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (newname.size() <= 0 || newname.size() > 60)
			{
				std::cout << "Ошибка макс длина 60 символов";
				Sleep(1500);
			}
			else
			{
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "введите кол-во нового товара/exit\n";
			Getline(newcount);
			if (newcount == "exit")
			{
				std::cout << "отмена\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (Isnumber(newcount))
			{
				count = std::stoi(newcount);
				if (newcount.size() <= 0 || newcount.size() > 999999999)
				{
					std::cout << "Ошибка макс длина 999999999 символов\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
			else
			{
				std::cout << "не число\n";
				Sleep(1500);
				system("cls");
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "введите цену нового товара/exit\n";
			Getline(newprice);
			if (newprice == "exit")
			{
				std::cout << "отмена\n";
				Sleep(1500);
				exit = false;
				break;
			}
			if (Isnumber(newprice))
			{
				price = std::stod(newprice);
				if (newprice.size() <= 0 || newprice.size() > 999999999)
				{
					std::cout << "Ошибка макс длина 999999999 символов\n";
					Sleep(1500);
				}
				else
				{
					break;
				}
			}
			else
			{
				std::cout << "не число\n";
				Sleep(1500);
				system("cls");
				break;
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "новый товар - " << newname << "\n";
			std::cout << "кол-во - " << newcount << "\n";
			std::cout << "цена - " << newprice << "\n";
			std::cout << "подтвердить\n1 - да\n2 - нет\n";
			Getline(choose);
			if (choose == "1")
			{
				storagesize++;
				unsigned int* idarrtemp = new unsigned int[storagesize];
				std::string* namearrtemp = new std::string[storagesize];
				unsigned int* countarrtemp = new unsigned int[storagesize];
				double* pricearrtemp = new double[storagesize];

				Fillarr(idarrtemp, idarr, storagesize - 1);
				Fillarr(namearrtemp, namearr, storagesize - 1);
				Fillarr(countarrtemp, countarr, storagesize - 1);
				Fillarr(pricearrtemp, pricearr, storagesize - 1);

				idarrtemp[storagesize - 1] = storagesize;
				namearrtemp[storagesize - 1] = newname;
				countarrtemp[storagesize - 1] = count;
				pricearrtemp[storagesize - 1] = price;

				std::swap(idarr, idarrtemp);
				std::swap(namearr, namearrtemp);
				std::swap(countarr, countarrtemp);
				std::swap(pricearr, pricearrtemp);

				delete[] idarrtemp, namearrtemp, countarrtemp, pricearrtemp;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "отмена";
				Sleep(1500);
				break;
			}
			else
			{
				Err();
			}
		}
		break;
	}


}


void Setloginsymbols()
{
		for (char i = '0'; i <= '9'; i++)
		{
			loginsymbols.insert(i);
		}
		for (char i = 'a'; i <= 'z'; i++)
		{
			loginsymbols.insert(i);
		}
		for (char i = 'A'; i <= 'Z'; i++)
		{
			loginsymbols.insert(i);
		}
		isloginsetcreate = true;
}

void Setpasssymbols()
{
	for (char i = '!'; i <= '&'; i++)
	{
		passsymbols.insert(i);
	}
	for (char i = '('; i <= '+'; i++)
	{
		passsymbols.insert(i);
	}
	for (char i = '/'; i <= '~'; i++)
	{
		passsymbols.insert(i);
	}
	isloginsetcreate = true;
}

void Changepass()
{
	std::string newpass1, newpass2;
	int userid = 0, isadmin = 0;
	while (true)
	{
		if (currentstatus == userstatus[0])
		{
			Showuser(1);
			isadmin = 0;
		}
		else
		{
			Showuser();
			isadmin = 1;
		}
		std::cout << "\nвыберете id пользователя/exit";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "отмена";
			Sleep(1500);
			break;
		}
		else if (Isnumber(choose))
		{
			userid = std::stoi(choose);
			if (userid < isadmin || userid > usize - 1)
			{
				std::cout << "неверный id";
				Sleep(1500);
				continue;
			}
		}
		else
		{
			Err();
			continue;
		}
		while (true)
		{
			system("cls");

			if (currentstatus == userstatus[1] && statusarr[userid] == userstatus[1])
			{
				std::cout << "недостаточно прав\n";
				Sleep(1500);
				break;
			}

			std::cout << "введите новый пароль " << loginarr[userid] << ": ";
			Getline(newpass1);
			std::cout << "подтвердите новый пароль " << loginarr[userid] << ": ";
			Getline(newpass2);

			if (Checkpass(newpass1) && Checkpass(newpass2) && newpass1 == newpass2)
			{
				passwordarr[userid] = newpass1;
				std::cout << "успешно\n";
				Sleep(1500);
				break;
			}
			else
			{
				std::cout << "ещё раз";
				Sleep(1000);
			}
		}
	}
}

void Addnewuser()
{
	std::string newlogin, newname, newrole, newpass;
	bool exit = true;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::cout << "введите логин/exit \n";
			Getline(newlogin);
			if (newlogin == "exit")
			{
				std::cout << "отмена";
				Sleep(1500);
				break;
			}
			if (Checklogin(newlogin))
			{
				break;
			}
			else
			{
				std::cout << "символы a-z A-Z 0-9";
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "введите пароль/exit\n";
			Getline(newpass);
			if (newpass == "exit")
			{
				std::cout << "отмена";
				Sleep(1500);
				break;
			}
			if (Checklogin(newpass))
			{
				break;
			}
			else
			{
				std::cout << "символы a-z A-Z 0-9, и спецсимволы";
			}
		}
		while (exit)
		{
			system("cls");
			std::cout << "введите 1 - админ, 2 - сотрудник/exit";
			Getline(choose);
			if (choose == "exit")
			{
				std::cout << "отмена";
				Sleep(1500);
				break;
			}
			else if (choose == "1")
			{
				newrole = userstatus[1];
				break;
			}
			else if (choose == "2")
			{
				newrole = userstatus[2];
				break;
			}
			else
			{
				Err();
			}
		}
		while (exit)
		{
			std::cout << "пользователь " << newlogin << "\n";
			std::cout << "пароль " << newpass << "\n";
			std::cout << "роль " << newrole << "\n";
			std::cout << "потвердить 1 - да, 2 - нет\n";
			Getline(choose);
			if (choose == "1")
			{
				usize++;
				std::string* loginarrtemp = new std::string[usize];
				std::string* passarrtemp = new std::string[usize];
				std::string* rolearrtemp = new std::string[usize];

				Fillarr(loginarrtemp, loginarr, usize - 1);
				Fillarr(passarrtemp, passwordarr, usize - 1);
				Fillarr(rolearrtemp, statusarr, usize - 1);

				loginarrtemp[usize - 1] = newlogin;
				passarrtemp[usize - 1] = newpass;
				rolearrtemp[usize - 1] = newrole;

				std::swap(loginarrtemp, loginarr);
				std::swap(passarrtemp, passwordarr);
				std::swap(rolearrtemp, statusarr);

				delete[] loginarrtemp, passarrtemp, rolearrtemp;

				std::cout << "операция прошла успешно";
				Sleep(1500);
				exit = false;
				break;
			}
			else if (choose == "2")
			{
				std::cout << "отмена\n";
				Sleep(1500);
			}
			else
			{

			}
		}
		if (exit == false)
		{
			break;
		}
	}
}

bool Checklogin(const std::string& str)
{
	if (str.size() < 4 || str.size() > 20)
	{
		std::cout << "ошибка длины";
		Sleep(1500);
		return false;
	}

	for (char sym : str)
	{
		if (!loginsymbols.count(sym))
		{
			std::cout << "некоректный логин";
			Sleep(1500);
			return false;
		}
	}

	for (size_t i = 0; i < usize; i++)
	{
		if (str == namearr[i])
		{
			std::cout << "уже есть";
			Sleep(1500);
			return false;
		}
	}
	return true;
}

bool Checkpass(const std::string& str)
{
	std::unordered_set<char> specialsymbols{ '!', '@' , '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '/', '?', '|', '\\', '\"', '\'', ',', '.', '<', '>', '~', '`', ':', ';', '{', '}', '[', ']'};
	int numcount = 0, specsymcount = 0;
	if (str.size() < 8 || str.size() > 30)
	{
		std::cout << "ошибка длины";
		Sleep(1500);
		return false;
	}
	for (char sym : str)
	{
		if (!passsymbols.count(sym))
		{
			std::cout << "некоректный пароль";
			Sleep(1500);
			return false;
		}
		if (std::isdigit(sym))
		{
			numcount++;
		}
		if (specialsymbols.count(sym))
		{
			specsymcount++;
		}
	}
	if (numcount > 3 && specsymcount > 3)
	{
		return true;
	}
	else
	{
		std::cout << "должно быть больше 3 спецсимволов и чисел";
		Sleep(1500);
		return false;
	}
}

void Start()
{
	if (Login())
	{
		if (currentstatus == userstatus[0])
		{
			while (true)
			{
				std::cout << "выберете склад\n1 - готовый\n2 - создать новый\n";
				Getline(choose);
				if (choose == "1")
				{
					if (isstoragecreated == false)
					{
						Createstorage();
					}
					system("cls");
					Sadminmenu();
				}
				else if (choose == "2")
				{
					if (isstoragecreated == false)
					{
						
					}
					system("cls");
					Sadminmenu();
				}
				else
				{
					Err();
				}
			}
		}
		else if (currentstatus == userstatus[1])
		{
			if (isstoragecreated == false)
			{
				Createstorage();
			}
		}
		else if (currentstatus == userstatus[2])
		{
			if (isstoragecreated == false)
			{
				Createstorage();
			}
		}
	}
}

inline void Err(int time)
{
	std::cout << "некоректный ввод";
	Sleep(time);
	system("cls");
}
//

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Start();


	delete[]loginarr, passwordarr, statusarr;
	if (Createstorage)
	{
		delete[]idarr, namearr, pricearr;
	}
	return 0;
}
void Showstorage(int mode)
{
	if (mode == 0)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "\tназвание\t" << "кол-во\t" << "цена\n";
		for (size_t i = 0; i < storagesize; i++)
		{
			std::cout << idarr[i] << "\t" << std::left << "\t" << std::setw(25) << namearr[i] << "\t" << countarr[i] << "\t" << pricearr[i] << "\n";
		}
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "название\t\t" << "кол-во\t\n";
		for (size_t i = 0; i < storagesize; i++)
		{
			std::cout << idarr[i] << "\t" << std::left << "\t" << std::setw(25) << namearr[i] << "\t" << countarr[i] << "\n";
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(25) << "название\t\t" << "цена\n";
		for (size_t i = 0; i < storagesize; i++)
		{
			std::cout << idarr[i] << "\t" << std::left << "\t" << std::setw(25) << namearr[i] << "\t" << pricearr[i] << "\n";
		}
	}
	else if (mode == 3)
	{
		std::cout << "ID\t" << std::left << "название\t\t" << "\n";
		for (size_t i = 0; i < storagesize; i++)
		{
			std::cout << idarr[i] << "\t" << std::left << "\t" << std::setw(25) << namearr[i] << "\n";
		}
	}
}

void Addstorage()
{
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		Showstorage(1);
		std::cout << "введите id/exit\n";
		Getline(chooseid);
		if (chooseid == "exit")
		{
			std::cout << "exit\n";
			Sleep(1500);
			break;
		}
		std::cout << "введите кол-во\n";
		Getline(choosecount);

		if (Isnumber(chooseid) && Isnumber(choosecount))
		{
			id = std::stoi(chooseid) - 1;
			count = std::stoi(choosecount);
			if (id < 0 || id > storagesize - 1 || count < 0 || count > 99999999)
			{
				std::cout << "не правильный id или кол-во\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << namearr[id] << "\t" << countarr[id] << " ---> " << countarr[id] + count << "\n\n";
				std::cout << "потдвердить?\n1 - да\n2 - нет\nввод - ";
				Getline(choose);
				if (choose == "1")
				{
					countarr[id] += count;
					std::cout << "успешное пополнение";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "отмена";
					Sleep(1500);
				}
				else
				{
					Err();
				}

			}
		}
	}
}

void Removestorage()
{
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		Showstorage(1);
		std::cout << "введите id/exit\n";
		Getline(chooseid);
		if (chooseid == "exit")
		{
			std::cout << "exit\n";
			Sleep(1500);
			break;
		}
		std::cout << "введите кол-во\n";
		Getline(choosecount);

		if (Isnumber(chooseid) && Isnumber(choosecount))
		{
			id = std::stoi(chooseid) - 1;
			count = std::stoi(choosecount);
			if (id < 0 || id > storagesize - 1 || count < 0 || count > countarr[id])
			{
				std::cout << "не правильный id или кол-во\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << namearr[id] << "\t" << countarr[id] << " ---> " << countarr[id] - count << "\n\n";
				std::cout << "потдвердить?\n1 - да\n2 - нет\nввод - ";
				Getline(choose);
				if (choose == "1")
				{
					countarr[id] -= count;
					std::cout << "успешное списывание";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "отмена";
					Sleep(1500);
				}
				else
				{
					Err();
				}

			}
		}
	}
}
void Changeprice()
{
	unsigned int id = 0;
	double newprice = 0;
	std::string chooseprice;
	while (true)
	{
		system("cls");
		Showstorage(2);
		std::cout << "введите id/exit\n";
		Getline(chooseid);
		if (chooseid == "exit")
		{
			std::cout << "exit\n";
			Sleep(1500);
			break;
		}
		std::cout << "введите цену\n";
		Getline(chooseprice);

		if (Isnumber(chooseid) && Isnumber(chooseprice))
		{
			id = std::stoi(chooseid) - 1;
			newprice = std::stod(chooseprice);
			if (id < 0 || id > storagesize - 1 || newprice < 0 || newprice > 1000)
			{
				std::cout << "не правильный id или цена\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(25) << namearr[id] << "\t" << pricearr[id] << " ---> " << newprice << "\n\n";
				std::cout << "потдвердить?\n1 - да\n2 - нет\nввод - ";
				Getline(choose);
				if (choose == "1")
				{
					pricearr[id] = newprice;
					std::cout << "успешное изменение";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "отмена";
					Sleep(1500);
				}
				else
				{
					Err();
				}

			}
		}
	}
}
void Changestorage()
{
	while (true)
	{
		system("cls");
		std::cout << "1 - добавить новый товар\n";
		std::cout << "2 - изменить имя\n";
		std::cout << "3 - удалить товар\n";
		std::cout << "0 - выход\n";
		std::cout << "Вывод\n";
		Getline(choose);
		system("cls");
		if (choose == "1" && storagesize > 0)
		{
			Addnewitem();
		}
		else if (choose == "2" && storagesize > 0)
		{
			Changename();
		}
		else if (choose == "3" && storagesize > 0)
		{
			Deleteitem();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			std::cout << "склад пуст\n";
		}
	}
}
void Changename()
{
	std::string newname;
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		Showstorage(3);
		std::cout << "\nвведите id/exit";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "отмена\n";
			Sleep(1500);
			break;
		}
		std::cout << "введите новое название - ";
		Getline(newname);
		if (newname.size() <= 0 || newname.size() >= 60)
		{
			std::cout << "ошибка макс символов 60\n";
		}
		else if (Isnumber(choose))
		{
			id = std::stoi(choose) - 1;
			if (id < 0 || id >storagesize - 1)
			{
				std::cout << "ошибка\n";
				Sleep(1500);
			}
			else
			{
				std::cout << namearr[id] << " ---> " << newname << "\n\n";
				std::cout << "подтвердить \n1 - да \n2 - нет\n";
				Getline(choose);
				if (choose == "1")
				{
					namearr[id] = newname;
					break;
				}
				else if (choose == "2")
				{
					std::cout << "отмена";
					Sleep(1500);
				}
			}
		}
	}
}
void Deleteitem()
{
	unsigned int id = 0;
	while (true)
	{
		system("cls");
		Showstorage(3);
		std::cout << "\nвведите id/exit - ";
		Getline(choose);
		if (choose == "exit")
		{
			std::cout << "отмена";
			Sleep(1500);
			break;
		}
		if (Isnumber(choose))
		{
			id = std::stoi(choose) - 1;
			if (id < 0 || id > storagesize - 1)
			{
				std::cout << "неверный id";
				Sleep(1500);
			}
			else
			{
				std::cout << "удаление" << namearr[id] << "\n\n";
				std::cout << "подтвердить \n1 - да \n2 - нет\n";
				Getline(choose);
				if (choose == "1")
				{
					storagesize--;
					unsigned int* idarrtemp = new unsigned int[storagesize];
					std::string* namearrtemp = new std::string[storagesize];
					unsigned int* countarrtemp = new unsigned int[storagesize];
					double* pricearrtemp = new double[storagesize];

					for (size_t i = 0, c = 0; i < storagesize; i++, c++)
					{
						if (id == c)
						{
							c++;
						}
					idarrtemp[i] = i+1;
					namearrtemp[i] = namearr[c];
					countarrtemp[i] = countarr[c];
					pricearrtemp[i] = pricearr[c];
					}

					std::swap(idarr, idarrtemp);
					std::swap(namearr, namearrtemp);
					std::swap(countarr, countarrtemp);
					std::swap(pricearr, pricearrtemp);

					delete[] idarrtemp, namearrtemp, countarrtemp, pricearrtemp;
					break;
				}
				else if (choose == "2")
				{
					std::cout << "отмена";
					Sleep(1500);
				}
			}
		}
	}
}
void Showuser(int mode)
{
	system("cls");
	std::cout << "№\t" << std::left << std::setw(12) << "логин\t\t" << "пароль\t\t\t" << "роль\n";
	if (mode == 0)
	{
		for (size_t i = 1; i < usize; i++)
		{
			std::cout << i << std::left << std::setw(12) << loginarr[i] << "\t\t" << passwordarr[i] << "\t\t\t" << statusarr[i];
		}
	}
	else if (mode == 1)
	{
		for (size_t i = 0; i < usize; i++)
		{
			std::cout << i << std::left << std::setw(12) << loginarr[i] << "\t\t" << passwordarr[i] << "\t\t\t" << statusarr[i];
		}
	}
}
void Changeuser()
{
	while (true)
	{
		if (isloginsetcreate == false)
		{
			Setloginsymbols();
		}
		system("cls");
		std::cout << "1 - добавить нового пользователя\n";
		std::cout << "2 - показать пользователя\n";
		std::cout << "3 - изменить пароль\n";
		std::cout << "4 - удалить пользователя\n";
		std::cout << "0 - выход\n";
		std::cout << "Вывод\n";
		Getline(choose);
		system("cls");
		if (choose == "1" && usize > 1)
		{
			Addnewuser();
		}
		else if (choose == "2" && usize > 1)
		{
			Showuser();
		}
		else if (choose == "3" && usize > 1)
		{
			Changepass();
		}
		else if (choose == "0")
		{
			break;
		}
		else
		{
			
		}
	}
}


bool Isnumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "ощибка. макс 999999999\n\n";
		Sleep(1500);
		return false;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "ощибка. данные не является числом\n\n";
			Sleep(1500);
			return false;
		}
	}
}