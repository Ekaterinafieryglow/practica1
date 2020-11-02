#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <fstream>

using namespace std;

string time()  //вывод реального времени в файл 
{
	char line[26];
	time_t real_time = time(NULL);
	ctime_s(line, sizeof line, &real_time);
	return line;
}

int main()
{
	setlocale(0, "rus");
	char str[80], result[80] = { 0 };

	string logic = "log.txt";   //создание файла 
	string command, amount;
	char cipher;
	int bias;
	bool key;

	ofstream fout(logic, ios_base::app);
	fout << "INFO : The program started! " << time();

	cout << "Cообщение вводится БЕЗ пробелов на АНГЛИЙСКОМ языке!" << endl;
	cout << "Введите сообщение для кодировки: ";    //ввод сообщения с клавиатуры
	cin >> str;

	do
	{
		key = true;
		cout << "Величина сдвига: ";  //ввод величины сдвига с клавиатуры
		cin >> amount;
		for (int i = 0; i < amount.length(); i++)  //проверка строки данных на число
		{
			if ((!isdigit(amount[i])) and (amount[i] != '-'))
			{
				key = false;
				cout << "Вы ввели не число! Попробуйте ввести еще раз!" << endl;
				fout << "WARNING : The user entered an invalid offset value. " << time();
				break;
			}
		}
	} while (!key);
	bias = atoi(amount.c_str());  //преобразование строки в число целочисленного типа

	do
	{
		cout << "Возможные команды: encode, decode. Ваша команда:  ";   //ввод команды расшифровки и зашифровки
		cin >> command;
		if (command == "decode")  //преобразование формул под расшифровку
		{
			bias *= -1;
		}
		else if (command != "encode") //проверка введенной команды
		{
			cout << "Команда введена не верно! Попробуйте ввести еще раз!" << endl;
			fout << "WARNING : The user entered an invalid command. " << time();
		}
	} while ((command != "encode") and (command != "decode"));

	for (int i = 0; i < strlen(str); i++)  //перебор элементов введенной строки
	{
		if ((str[i] > 96) and (str[i] < 123)) //зашифровка строчных букв
		{
			cipher = str[i] += bias;
			cipher = char(97 + ((cipher - 97) % 26));
			result[i] = cipher;
		}
		else if ((str[i] > 64) and (str[i] < 91))  //зашифровка прописных букв
		{
			cipher = str[i] += bias;
			cipher = char(65 + ((cipher - 65) % 26));
			result[i] = cipher;
		}
		else
		{
			result[i] = str[i];
		}
	}
	cout << "Зашифрованное сообщение:  " << result << endl;  //вывод в консоль результата кодировки

	if (command == "encode")  //коментарии в файл по кодированию/разкодировке сообщения
	{
		fout << "INFO : Message successfully encoded. " << time();
	}
	else {
		fout << "INFO : Message successfully decoded. " << time();
	}

	fout << "INFO : The program completed! " << time();
	fout << endl;
	fout.close();
}
