#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    float  rows(NULL);
    cout << "Введите количество критериев: ";
    cin >> rows;

    float** arr = new float* [rows];   // Динамический двумерный массив данных попарного сравнения критериев
    float* arrSum = new float[rows];   // Динамический одномерный массив суммы строк

    for (int i = 0; i < rows; i++)
    {
        arr[i] = new float[rows];
    }

    cout << "\nВведите данные попарного сравнения критериев! Ввод десятичных чисел осуществляется через точку!\n";
    for (int i = 0; i < rows; i++)    // Ввод с клавиатуры данных попарного сравнения критериев
    {
        for (int j = 0; j < rows; j++)
        {
            cout << i + 1 << "-й критерий по отношению к  ";
            cout << j + 1 << "-ому критерию: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nТаблица данных попарного сравнения критериев: \n";  
    for (int i = 0; i < rows; i++)    // Вывод на экран массива данных попарного сравнения критериев
    {
        arrSum[i] = 0;
        for (int j = 0; j < rows; j++)
        {
            cout << arr[i][j] << "\t";
            arrSum[i] += arr[i][j];
        }
        cout << endl;
    }

    cout << "\nСумма по строкам!\n";  // Подсчет суммы по строкам данных
    float arrSumO(NULL);
    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "-й критерий: " << arrSum[i] << endl;
        arrSumO = arrSumO + arrSum[i];
    }
    cout << "\nОбщая сумма строк!\n"; // Подсчет общей суммы строк данных
    cout << arrSumO << endl;

    cout << "\nСумма всех весовых коэффициентов!\n";
    float SumO;                       // Вывод суммы всех весовых коэффициентов 
    SumO = (arrSumO / arrSumO);
    cout << SumO << endl;

    cout << "\nВесовые коэффициенты каждого критерия!\n";
    for (int i = 0; i < rows; i++)    // Вывод весовых коэффициентов каждого критерия
    {
        cout << i + 1 << "-й критерий: " << round(arrSum[i] / arrSumO * 100) / 100 << endl;
    }

    for (int i = 0; i < rows; i++)    // Освобождение памяти от динамических массивов
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] arrSum;
}
