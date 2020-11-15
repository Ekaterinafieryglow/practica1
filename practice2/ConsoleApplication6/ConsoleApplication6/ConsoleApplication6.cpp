#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    float  rows(NULL);
    cout << "Введите количество критериев: ";
    cin >> rows;

    float **arr = new float* [rows];    
    float *arrSum = new float [rows];   
   
    for (int i = 0; i < rows; i++)  
    {
        arr[i] = new float[rows];
    }

    for (int i = 0; i < rows; i++)    
    {
        for (int j = 0; j < rows; j++)
        {
            cout << i + 1 << "-я строка ";
            cout << j + 1 << "-й столбец: ";
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        arrSum[i] = 0;
        for (int j = 0; j < rows; j++)
        {
            cout << arr[i][j] << "\t";
            arrSum[i] += arr[i][j];
        }
        cout << endl;
    }

    cout << "\nСумма по строкам!\n";
    float arrSumO(NULL);
    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "-й столбец: " << arrSum[i] << endl;
        arrSumO = arrSumO + arrSum[i];
    }
    cout << "\nОбщая сумма строк!\n";
    cout << arrSumO << endl;

    float SumO;
    SumO = (arrSumO / arrSumO);
    cout << SumO << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << i + 1 << "-й столбец: " << round(arrSum[i] / arrSumO * 100) / 100 << endl;
    }



    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
    delete[] arrSum;
}
