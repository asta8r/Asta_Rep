int main()
{
    setlocale(LC_ALL, "rus");

    char file_name[100]; //буфер хранения пути к файлу
    std::cout << "Введите имя файла: ";
    std::cin >> file_name;

    ifstream fin(file_name); //open file for reading
    if(!fin.is_open())
        std::cout << "Невозможно открыть файл ";
    else
    {
        int counterBracketOpen = 0;
        int counterBracketClose = 0;

        char symbol; //временная перем для хранения символов считанных из файла
        fin >> symbol; //предварительно считываем из файла

        while (fin) //пока идёт считывание
        {
            if (symbol == '{')
                counterBracketOpen++;
            if (symbol == '}')
            {
                counterBracketClose++;
                if (counterBracketClose > counterBracketOpen)
                    break;
            }
            fin >> symbol; //счиитываем из файла
        }
        fin.close();// close file

        ofstream fout("./out"); //create a file for writing a result of checking

        if (counterBracketOpen == 0 && counterBracketClose == 0) //проверка баланса скобок
        {
            std::cout << "в файле нет фигур скобок " << std::endl;
            fout << "в файле нет фигур скобок " << std::endl;
        }
        else if (counterBracketOpen == counterBracketClose ) //проверка баланса скобок
        {
            std::cout << "баланс фигур скобок НЕ нарушен " << std::endl;
            fout << "баланс фигур скобок НЕ нарушен  " << std::endl;
        }
        else
        {
            std::cout << "баланс фигур скобок нарушен " << std::endl;
            fout << "баланс фигур скобок нарушен " << std::endl;
        }
        fout.close(); //закрываем файл результата
    }

    return 0;
}
