#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	char str[80], result[80] = { 0 };

	string command, amount;
	char cipher;
	int bias;
	bool key;

	cout << "Cообщение вводится БЕЗ пробелов на АНГЛИЙСКОМ языке!" << endl;
	cout << "Введите сообщение для кодировки: ";    
	cin >> str;

	do
	{
		key = true;
		cout << "Величина сдвига: ";  
		cin >> amount;
		for (int i = 0; i < amount.length(); i++)  
		{
			if ((!isdigit(amount[i])) and (amount[i] != '-'))
			{
				key = false;
				cout << "Вы ввели не число! Попробуйте ввести еще раз!" << endl;
				break;
			}
		}
	} while (!key);
	bias = atoi(amount.c_str());  

	do
	{
		cout << "Возможные команды: encode, decode. Ваша команда:  ";   /
		cin >> command;
		if (command == "decode")  
		{
			bias *= -1;
		}
		else if (command != "encode") 
		{
			cout << "Команда введена не верно! Попробуйте ввести еще раз!" << endl;
		}
	} while ((command != "encode") and (command != "decode"));

	for (int i = 0; i < strlen(str); i++)  
	{
		if ((str[i] > 96) and (str[i] < 123)) 
		{
			cipher = str[i] += bias;
			cipher = char(97 + ((cipher - 97) % 26));
			result[i] = cipher;
		}
		else if ((str[i] > 64) and (str[i] < 91)) 
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
	cout << "Зашифрованное сообщение:  " << result << endl; 
	system("pause");
	return 0;
}
