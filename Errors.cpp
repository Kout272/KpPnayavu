#include "Errors.h"
#include <string>
#include <stdexcept>
#include <cctype> 

int GetInt(int min, int max, istream& in)
{
	int value;
	bool flag = false;
	while (!flag)
	{
		cout << "Введите число от " << min << " до " << max << ":";
		in >> value;
		try
		{
			if (!in.good() || in.peek() != '\n')
			{
				throw Exception_vvod("Неверный ввод, введите целое число!\n");
			}
			if (value < min || value > max) throw Exception_vvod("Число вне диапозона!\n");
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return value;
}

int GetInt(int min, int max)
{
	int value;
	bool flag = false;
	while (!flag)
	{
		cout << "Введите число от " << min << " до " << max << ":";
		cin >> value;
		try
		{
			if (!cin.good() || cin.peek() != '\n')
			{
				throw Exception_vvod("Неверный ввод, введите целое число!\n");
			}
			if (value < min || value > max) throw Exception_vvod("Число вне диапозона!\n");
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return value;
}

string GetDate()
{
	string Date;
	bool flag = false;

	while (!flag)
	{
		cout << "Введите дату в формате xx.xx.xxxx: ";
		cin >> Date;

		try
		{
			if (Date.length() != 10)
			{
				throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
			}

			if (Date[2] != '.' || Date[5] != '.')
			{
				throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
			}

			for (int i = 0; i < Date.length(); ++i)
			{
				if ((i != 2 && i != 5) && !isdigit(Date[i]))
				{
					throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
				}
			}

			int day = stoi(Date.substr(0, 2));
			int month = stoi(Date.substr(3, 2));
			int year = stoi(Date.substr(6, 4));

			if (day < 1 || day > 31 || month < 1 || month > 12) {
				throw Exception_vvod("Дата введена неверно! Дни: 1-31, Месяцы: 1-12.\n");
			}

			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Date;
}

string GetDate(istream& in)
{
	string Date;
	bool flag = false;

	while (!flag)
	{
		cout << "Введите дату в формате xx.xx.xxxx: ";
		in >> Date;

		try
		{
			if (Date.length() != 10)
			{
				throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
			}

			if (Date[2] != '.' || Date[5] != '.')
			{
				throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
			}

			for (int i = 0; i < Date.length(); ++i)
			{
				if ((i != 2 && i != 5) && !isdigit(Date[i]))
				{
					throw Exception_vvod("Дата введена неверно! Формат: xx.xx.xxxx\n");
				}
			}

			int day = stoi(Date.substr(0, 2));
			int month = stoi(Date.substr(3, 2));
			int year = stoi(Date.substr(6, 4));

			if (day < 1 || day > 31 || month < 1 || month > 12) {
				throw Exception_vvod("Дата введена неверно! Дни: 1-31, Месяцы: 1-12.\n");
			}

			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Date;
}

string GetName()
{
	string Name;
	bool flag = false;
	while (!flag)
	{
		cin >> Name;
		try
		{
			if (!isupper(Name[0])) throw Exception_vvod("Первая буква должна быть заглавной! Повторите ввод\n");
			if (Name.length() < 2) throw Exception_vvod("Должно быть более одной буквы! Повторите ввод\n");
			if (Name.length() > 30) throw Exception_vvod("Должно быть менее тридцати букв! Повторите ввод\n");
			for (size_t i = 0; i < Name.length(); i++)
			{
				if (!isalpha(Name[i])) throw Exception_vvod("Не должно ничего кроме букв! Повторите ввод\n");
			}
			for (size_t i = 1; i < Name.length(); i++)
			{
				if (isupper(Name[i])) throw Exception_vvod("Буквы после первой должны быть строчными! Повторите ввод\n");
			}
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Name;
}

string GetName(istream& in)
{
	string Name;
	bool flag = false;
	while (!flag)
	{
		in >> Name;
		try
		{
			if (!isupper(Name[0])) throw Exception_vvod("Первая буква должна быть заглавной! Повторите ввод\n");
			if (Name.length() < 2) throw Exception_vvod("Должно быть более одной буквы! Повторите ввод\n");
			if (Name.length() > 30) throw Exception_vvod("Должно быть менее тридцати букв! Повторите ввод\n");
			for (size_t i = 0; i < Name.length(); i++)
			{
				if (!isalpha(Name[i])) throw Exception_vvod("Не должно ничего кроме букв! Повторите ввод\n");
			}
			for (size_t i = 1; i < Name.length(); i++)
			{
				if (isupper(Name[i])) throw Exception_vvod("Буквы после первой должны быть строчными! Повторите ввод\n");
			}
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				in.clear();
			in.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Name;
}

string GetTitle()
{
	string Name;
	bool flag = false;
	while (!flag)
	{
		cin >> Name;
		try
		{
			if (!isupper(Name[0])) throw Exception_vvod("Первая буква должна быть заглавной! Повторите ввод\n");
			if (Name.length() < 2) throw Exception_vvod("Должно быть более одной буквы! Повторите ввод\n");
			if (Name.length() > 30) throw Exception_vvod("Должно быть менее тридцати букв! Повторите ввод\n");
			for (int i = 0; i < Name.length(); i++)
			{
				if (isalpha(Name[i]) == 0 && isdigit(Name[i]) == 0) throw Exception_vvod("Должны быть только буквы или цифры\n");
			}
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Name;
}

string GetTitle(istream& in)
{
	string Name;
	bool flag = false;
	while (!flag)
	{
		in >> Name;
		try
		{
			if (!isupper(Name[0])) throw Exception_vvod("Первая буква должна быть заглавной! Повторите ввод\n");
			if (Name.length() < 2) throw Exception_vvod("Должно быть более одной буквы! Повторите ввод\n");
			if (Name.length() > 30) throw Exception_vvod("Должно быть менее тридцати букв! Повторите ввод\n");
			for (int i = 0; i < Name.length(); i++)
			{
				if (isalpha(Name[i]) == 0 && isdigit(Name[i]) == 0) throw Exception_vvod("Должно быть только буквы или цифры\n");
			}
			flag = true;
		}
		catch (Exception_vvod& ex)
		{
			RED
				in.clear();
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ex.What();
			RESET
				system("pause");
		}
	}
	return Name;
}