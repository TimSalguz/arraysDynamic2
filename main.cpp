// 2.	Ввести последовательность натуральных
// чисел {Aj}j=1...n (n<=1000). Упорядочить
// последовательность по неубыванию первой
// цифры числа, числа с одинаковыми первыми
// цифрами дополнительно упорядочить по неубыванию
// суммы цифр числа, числа с одинаковыми первыми
// цифрами и одинаковыми суммами цифр дополнительно
// упорядочить по неубыванию самого числа.

#include <iostream>
#include <fstream>

//Сумма цифр числа
int numSum(int a)
{
    int sum = 0;
    while (a != 0)
    {
        //узнает последнюю цифру числа
        sum += a % 10;
        //убирает последнюю цифру числа
        a /= 10;
    }
    return sum;
}

//Показывает первую цифру в числе
int firstDigit(int number)
{
    int firstDigit;
    do
    {
        firstDigit = number;
        number /= 10;
    } while (number);
    return firstDigit;
}

int main()
{
    int* arr = new int;
    bool containsFirst1;
    int chislo;
    int massize = 0;

    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    std::cout << "Before:" << std::endl;

    //Считывает из файла и записывает в массив
    for (int i = 0; !in.eof(); i++)
    {
        in >> arr[i];
        massize++;
        // Пишет массив в консоль
        std::cout << arr[i] << std::endl;
    }

    //Сортирую числа по первому числу
    for (int i = 0; i < massize - 1; i++)
    {
        for (int j = i + 1; j < massize; j++)
            if (firstDigit(arr[i]) >= firstDigit(arr[j]))
            {
                std::swap(arr[i], arr[j]);
            }
    }

    //Проверяю цифры от 1 до 9
    for (int inum = 1; inum < 10; inum++)
    {
        //Проверяю весь массив на наличие первым нужной цифры
        for (int i = 0; i < massize; i++)
        {
            for (int j = i + 1; j < massize; j++)
            {
                //Если первая цифра = нужная цифра, то
                if (firstDigit(arr[i] == inum && firstDigit(arr[j]) == inum))
                {
                    //сумму цифр отсортировать.
                    if (numSum(arr[i]) >= numSum(arr[j]))
                    {
                        std::swap(arr[i], arr[j]);
                    }
                }
            }
        }
    }

    //Проверяю, если первое число равно нужному числу, и если сумма цифр одинаковая, то поменять местами 1 и 2 элементы массива
    //Проверяю цифры от 1 до 9
    for (int inum = 1; inum < 10; inum++)
    {
        //Проверяю весь массив на наличие первым нужной цифры
        for (int i = 0; i < massize; i++)
        {
            for (int j = i + 1; j < massize; j++)
            {
                //Если первая цифра = нужная цифра, и сумма чисел одинаковая,
                if (firstDigit(arr[i] == inum && firstDigit(arr[j]) == inum && (numSum(arr[i]) == numSum(arr[j]))))
                {
                    //то отсортировать по неубыванию
                    if (arr[i] >= arr[j])
                    {
                        std::swap(arr[i], arr[j]);
                    }
                }
            }
        }
    }
    std::cout << "After:" << std::endl;
    // Пишет массив в файл и консоль
    for (int i = 0; i < massize; i++)
    {
        out << arr[i] << std::endl;
        std::cout << arr[i] << std::endl;
    }
    //delete arr;
}