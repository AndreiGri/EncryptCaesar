#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

int numEncrypt() {                                               /*Метод для проверки корректности ввода шифра*/
    while (true)
    {
        int n;
        cout << " Enter encrypt:\n ";
        std::cin >> n;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            cerr << " Input Error!\n Try again!";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
            return n;
    }
}

string encrypt_caesar(string text, int n)                       /*Метод для шифрования.*/
{
    string textNew = "";                                        /*Переменная для записи зашифрованного текста*/
    for (int i = 0; i < text.length(); i++) {                   /*Цикл кол-во итераций равно кол-ву символов*/
        char c = text[i];                                       /*Переменная для записи символа строки*/
        if (c >= 'A' && c <= 'Z') {                             /*Условие определяющее что символ является прописной буквой*/
            if (c + n > 'Z') {                                  /*Вложенное условие определяет что значение символа в сумме с числом кодировки больше максимального значения алфавита*/
                c = 'A' + ((n - ('Z' - c) - 1) % 26);           /*Тело условия записывает в пременную символа строки зашифрованное значение*/
            }
            else {
                c += n;                                         /*Иначе складываем значение переменной с числом шифрования*/
            }
        }                                                 
        else {                                            
            if (c >= 'a' && c <= 'z') {                         /*Условия единтичные предыдущим с разницей что проверяются заглавные буквы*/
                if (c + n > 'z') {                        
                    c = 'a' + ((n - ('z' - c) - 1) % 26); 
                }
                else {
                    c += n;
                }
            }
        }
        textNew += c;                                           /*Записываем значение символа в новую строку*/
    }
    return textNew;                                             /*Возвращаем новую строку*/
}

int main()
{
    // Установка цвета фона терминала и цвета текста
    system("color 80");
    string textFirst;                                          /*Переменная для записи шифруемого текста*/
    int num;                                                   /*Переменная для записи числа кодировки*/                  

    cout << endl;

    cout << " Enter text: " << endl;                           /*Запрашиваем текст*/
    cout << ' ';
    getline(cin, textFirst);                                   /*Записываем текст в переменную*/
    num = numEncrypt();
    cout << ' ';
    cout << encrypt_caesar(textFirst, num) << endl;            /*Выводим результат*/ 
    
    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}