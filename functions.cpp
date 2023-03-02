#include "functions.h"
#include <iostream>
#include <fstream>
#include "header.h"
#include <cstdlib>
#include <vector>
#include <map>
#include <iomanip>
#include <list>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <string>
using namespace std;

void sum()
{
    setlocale(LC_ALL, "rus");
    const int sizeArr = 40;
    int n = 12;
    int array[sizeArr];
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < n; i++)
    {
        array[i] = array[i - 2] + array[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << std::endl;
    }
}
//--------------------------------

double f(double x)
{
    return x*(1-x);
}

double g(double x)
{
    return 1/x;
}

double integrate(double (*F)(double), double a, double b)
{
    int n = 1000;
    double dx = (b - a) / n;
    double s = (F(a) + F(b)) * dx / 2;
    for (int k = 1; k < n - 1; k++)
    {
        s += F(a + dx * k) * dx;
    }
    return s;
}

//--------------------------------

void scobes()
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

}
//--------------------------------

void matrix()
{
    setlocale(LC_ALL, "rus");
    int elVec = 0;
    const int sizVec=100;
    int vec[sizVec] = {};
    int row= 0, col=0;
    const int sizeR = 100;
    const int sizeC = 100;
    int arr[sizeR][sizeC] = {};
    int resVec[sizVec] = {};


    std::cout << "Введите количество строк матрицы: " << " ";
    std::cin >> row;
    std::cout << "Введите количество столбцов матрицы: " << " ";
    std::cin >> col;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "matrix[" << i+1 << "]" << "[" << j+1 << "] = "  << " ";
            std::cin >> arr[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Введите элементы вектора: " << std::endl;
    for (int i = 0; i < col; i++)
    {
        std::cout << "vector[" << i+1 << "] = " << " ";
        std::cin >> vec[i];
    }

    std::cout << "Введенная матрица: " << std::endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << setw(4) << arr[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "Введенный вектор: " << std::endl;
    for (int i = 0; i < col; i++)
    {
        std::cout << setw(4) << vec[i] << std::endl;
    }

    std::cout << "Результирующий вектор: " << std::endl;
    for (int i = 0; i < row; i++)
    {
        resVec[i] = 0;
        for (int j = 0; j < col; j++)
        {
            resVec[i] += arr[i][j] * vec[j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        std::cout << setw(4) << resVec[i] << std::endl;
    }

    int max = resVec[0];
    for (int i = 0; i < row; i++)
    {
        if (max < resVec[i])
            max = resVec[i];
    }
        std::cout << "Максимальное значение = " << max << std::endl;

}

//--------------------------------

void posInVec()
{
    setlocale(LC_ALL, "rus");

    vector<int> intArray;

    intArray.push_back(50);
    intArray.push_back(2991);
    intArray.push_back(405);
    intArray.push_back(7);
    cout << "Содержимое вектора: " << endl;

    //vector<int>::iterator arrIterator = intArray.begin();

    auto arrIterator = intArray.begin();

    while (arrIterator != intArray.end())
    {
        cout << *arrIterator << " ";
        ++arrIterator;
    }

    vector<int>::iterator elFound = find(intArray.begin(), intArray.end(), 2991);

    if (elFound != intArray.end())
    {
        int elPos = distance(intArray.begin(), elFound);
        cout << "Значение " << *elFound;
        cout << " находится в позиции " << elPos << endl;
    }
}

//---------------------------------------------------
char* resize(const char* str, unsigned size, unsigned new_size)
{
    char* new_str = new char[new_size];

    for (int i = 0; i < size && i < new_size; ++i)
    {
        new_str[i] = str[i];
    }

    delete[] str;
    return new_str;
}
//--------------------------------

char* getline()
{
    int i = 0;
    char c;
    char* tmp = new char[1];
    while (cin.get(c) && (c != '\n'))
    {
        i++;
        tmp[i - 1] = c;
        char* new_tmp = new char[i + 1];
        for (int n = 0; n < i; n++)
        {
            new_tmp[n] = tmp[n];
        }
        delete[] tmp;
        tmp = new_tmp;
    }
    tmp[i] = '\0';
    return tmp;
}
//----------------------------------------

void myArray()
{
    setlocale(LC_ALL, "rus");
    Array myArray1;   //10 элементов
    Array myArray2(15); //15 элементов

    std::cout << "Размер массива 1: " << myArray1.getSize() << std::endl;
    std::cout << "Элементы массива 1, после его создания: " << std::endl;
    myArray1.getArray();        //вывод элементов массива 

    std::cout << "Размер массива 2: " << myArray2.getSize() << std::endl;
    std::cout << "Элементы массива 2, после его создания: " << std::endl;
    cout << myArray2;       //вывод элементов масива с помощью перегружен.оператора вывода

    cout << "Введите 10 чисел ";
    myArray1.setArray();        //заполнение массива

    cout << "Введенный массив " << myArray1;
    cout << "Введите 15 чисел ";
    cin >> myArray2;        //заполнение массива спомощью перегружен.оператора вывода

    cout << "Введенный массив: " << myArray2;

    //------------------------------------------------
    Array myArray3(myArray1);   //создам объект класса Array, используя констр-р копирования

    std::cout << "Размер массива 3: " << myArray1.getSize() << std::endl;
    cout << myArray3;           //вывод элементов массива 

    myArray3 = myArray2;
    cout << myArray3;

    if (myArray1 == myArray2)
        cout << "Массивы 1 и 2 равны \n";
    else
        cout << "Массивы 1 и 2 не равны \n";

    //	вывод элементов массива используя перегруженную функция взятия индекса
    std::cout << "Элемент массива 1 : " << myArray1[myArray1.getSize() - 1] << std::endl;

    //------------------------------------------------
    Array myArray4 = myArray2 + myArray3;       //перегруженная операция сложени
    cout << "Массив 4: \n" << myArray4;

    myArray4 += 111;        //добавление 111 в конец массива
    cout << "Массив 4 + 8: \n" << ((myArray4 += 112) += 113);
    cout << (myArray4 - 111 - 112 - 113);   //удаляем элементы массива с помощю перегруженной операции минус

    int pos = 0;
    if ((pos == myArray4.search(30)) != -1)
        cout << "Позиция искомого элемента: \n" << pos << endl;
    else
        cout << "Искомый элемент не найден: \n" << pos << endl;

    myArray4.sort();
    cout << myArray4 << endl;

}

//--------------------------------
//посчитайте кол-во разрядов в произвольном числе
void countElemMain()
{
    setlocale(LC_ALL, "rus");
    cout << " Введите число " << endl;
    int a;
    std::cin >> a;
    unsigned int count = 0;
    for (count = 0; a; a >>= 1)
        count += a & 1;

    cout << "кол-во единиц в числе " << count << endl;
}
//--------------------------------

void integrateMain()
{
    setlocale(LC_ALL, "rus");

    std::cout << integrate(f, 0, 1) << std::endl;
    std::cout << integrate(g, 1, 2) << std::endl;
}
//--------------------------------
//посчитайте кол-во определенных цифр в произвольном числе
void countElemNumMain()
{
    int n, d, m, count=0, i;
    std::cout << "Кол-во чисел " << std::endl;
    std::cin >> n;
    std::cout << "цифра " << std::endl;
    std::cin >> d;

    std::cout << "Введите числа " << std::endl;
    for (i = 0; i < n; i++)
    {
        std::cin >> m;
        while (m > 0)
        {
            if (m%10 == d)      //остаток от деления
                count += 1;
            m = m / 10;     //отбрасываем дробную часть
        }
    }
    cout << "кол-во цифр в числе " << count << endl;
}
//--------------------------------
//написать функцию, которая разворачивает односвязный список. То есть первый элемент становится последним, а последний элемент становится первым.
/*void List::reverseList()
{
    Node* prev = nullptr;
    Node* curr = m_head;
    //Node* next;
    
    while(curr->m_next != nullptr)
    {

    }

}
//написать функцию вставки в односвязный список. 
void List::insert(int pos, int data)
{
    Node* node = new Node(data);

    if (m_head != nullptr)
    {
        m_head = node;      
        return;
    }
    if (pos == 0)
    {
        node->m_next = m_head;
        m_head = node;
        return;
    }

    int currPos = 0;
    Node* current = m_head;
    while (currPos < pos - 1 && current->m_next != nullptr) //идём по списку пока он не кончится, или пока не дойдём до позиции
    {
        current = current->m_next;
        currPos++;
    }
    Node* next = current->m_next;
    current->m_next = node;
    node->m_next = next;
}*/

//написать реализацию функции atoi
int my_atoi(const char* str)
{
    int base = 0;   
    int sign = 1;  //знак
    int i = 0;      
    while (str[i] == ' ') //пропускаем пробелы
        i++;

    if (str[i] == '-' || str[i] == '+')
    {
        sign = 1 - 2 * (str[i++] == '-'); //выставление знака в 1 или -1
    }
    //checking for valid input 
    while (str[i] >= '0' && str[i] <= '9')
    {
        //обработка тестового примера выполнения
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
        {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }

        base = 10 * base + (str[i++] - '0');
    }

    return base * sign;
}

//binary search 
int binary(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binary(arr, l, mid-1, x);
        else
           return binary(arr, mid-1, r, x);
    }
    return -1;
}
//---------------------------------------------------------------------------------
//qsort
int partition(int* arr, int start, int end)
{
    int pivot = arr[end];       //опорный элемент будет взят как конец массива
    int pIndex = start;         // "стена" наименьший индекс 

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);
    return pIndex;
}
void qSort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    int pivot = partition(arr, start, end);

    qSort(arr, start, pivot-1);

    qSort(arr, pivot+1, end);
}
//---------------------------------------------------------------------------------
//fibbonachi
int fibb(int n)
{
    if (n < 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;
    return fibb(n - 1) + fibb(n - 2);
}
//---------------------------------------------------------------------------------
//leap year
bool isLeap(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;
    return 0;
}
//---------------------------------------------------------------------------------
//pallindrom
bool isPallindrom(string str)
{
    int len = str.length(); //сколько символов в строке

    for (int i = 0; i < len / 2; ++i)  //до половины строки
    {
        if (str[i] != str[len - i - 1])   //не равен ли элементу двигающемуся с конца всей строки
            return false;
    }
    return true;
}
//---------------------------------------------------------------------------------
//reverese string
char reverseStr()
{
    const int size = 4;
    char str[size] = { 'c', 'o', 'o', 'l' };
    for (int i = size - 1; i >= 0; --i)
        return str[i];
}
//---------------------------------------------------------------------------------
//подсчёт слов в предложении
int CountWordsSent()
{
    string str;
    getline(cin, str);

    if (str.empty())
        return -1;
    int count = 0;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i - 1] != ' ' && (str[i] == ' ' || str[i + 1] == '\0'))   //проверка на лишний пробел 
            count++;
    }
    return count;
}
//---------------------------------------------------------------------------------
//рекурсивный поиск в дереве бинарного поиска  ????
/*struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}*/
//---------------------------------------------------------------------------------
//функция которая проверяет является ли дерево сбалансированным 
// 
//Рекурсивная функция для проверки того, является ли заданное бинарное дерево сбалансированным по высоте или нет
int isHeightBalanced(NodeN* root, bool& isBalanced)
{
    //базовый слоучай дерево пусто или не сбалансировано
    if (root == nullptr || !isBalanced)
        return 0;
    //получаем высоту левого поддерева
    int left_height = isHeightBalanced(root->left, isBalanced);
    //получаем высоту правого поддерева
    int right_height = isHeightBalanced(root->right, isBalanced);
    //дерево несбалансированное если абсол.разница между высотойего девое и правое поддерево больше 1
    if (abs(left_height - right_height) > 1)
        isBalanced = false;
    //возвращаем высоту поддерева с корнем в текущем узле 
    return max(left_height, right_height) + 1;
}
//основная функция на проверку сбалансированности
bool isHeightBalancedK(NodeN* root)
{
    bool isBalanced = true;
    isHeightBalanced(root, isBalanced);
    return isBalanced;
}
void mainBalanced()
{
    /*
                            1
                           / \
                          /   \
                         2     3
                        /\    /
                       4  5  6 
    */

    NodeN* root = new NodeN(1);
    root->left = new NodeN(2);
    root->right = new NodeN(3);
    root->left->left = new NodeN(4);
    root->left->right = new NodeN(5);
    root->right->left = new NodeN(6);

    if (isHeightBalancedK(root))
        cout << "Binary tree is balanced";
    else
        cout << "Binary tree is not balanced";
}
//---------------------------------------------------------------------------------
//поиск уникального элемента в массиве 

void findUnEl()
{
    int a[] = { 1,1,2,3,3,4,4,5,6,6,7,8,9,9,10 };
    int const n = sizeof(a) / sizeof(*a);
    for (int i = 0; i < n; ++i)
        //эл-т меньше следующего и больше предыдущего  
        if ((i == 0 || a[i] > a[i - 1]) && (i == n - 1 || a[i] < a[i + 1]))
            std::cout << a[i] << " ";
}
//---------------------------------------------------------------------------------
//реализация вектора

//реализация очереди

//функция, которая за один проход найдёт уникальный элмент в контейнере  ???

//реализация String
//---------------------------------------------------------------------------------
//реализация Singleton
class MySingleton
{
public:
    static MySingleton* getInstance()
    {
        if (!p_instance)
            p_instance = new MySingleton();
        return p_instance;
    }
private:
    static MySingleton* p_instance;
    MySingleton() {  }
    MySingleton(const MySingleton&);
    MySingleton& operator=(MySingleton&);
};
//---------------------------------------------------------------------------------
// в файле находится произвольное кол-во целых чисел. Ввыести их на экран в порядке возрастания
int mainSortVec()
{
    ifstream in("input.txt");
    if (!in)
    {
        cerr << "File not found";
        exit(1);
    }
    vector<int> v;
    int x;
    while (in >> x)
        v.push_back(x);
    sort(v.begin(), v.end());
    vector<int>::const_iterator i;
    for (i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    return 0;
}
//---------------------------------------------------------------------------------
//Напишите функцию, принимающую диапазон и возвращающую самый часто
//встречающийся элемент в этом диапазоне, а также сколько раз встретился
//этот элемент.Если в диапазоне имеется несколько самых часто встречающихся
//элементов с одинаковой частотой, тогда функция должна вернуть все элементы.
//Например, для диапазона{ 1,1,3,5,8,13,3,5,8,8,5 } она должна вернуть
//{ 5, 3 } и{ 8, 3 }.
template <typename T> std::vector<std::pair<T, size_t>> find_most_frequent(std::vector<T> const& range)
{
    std::map<T, size_t> counts; //кол-во вхождений (ключ - сам элемент, значения-число вхожд-й)
    for (auto const& e : range) 
        counts[e]++;
    auto maxelem = std::max_element( std::cbegin(counts),   std::cend(counts),   [](auto const& e1, auto const& e2){return e1.second < e2.second;});    //??? е1.значение меньше е2.значения

    std::vector<std::pair<T, size_t>> result;
    //копирует элемиенты в диапазоне, для которого pred возвр в true в диапазон начинающийся с result
    //std::copy_if( first, last, result, pred);
    std::copy_if( std::begin(counts), std::end(counts), std::back_inserter(result),
        [maxelem](auto const& kvp) { return kvp.second == maxelem->second; });       // []-список захвата
    return result;
}
//---------------------------------------------------------------------------------
// Генерация всех перестановок символов в строке
//Напишите функцию, которая выведет в консоль все возможные перестановки
//символов в строке.Реализуйте две версии функции : рекурсивную и нерекурсивную.
void print_permutations(std::string str)
{
    std::sort(std::begin(str), std::end(str));
    do
    {
        std::cout << str << std::endl;
    } while (std::next_permutation(std::begin(str), std::end(str)));
}
//рекурсивн
void next_permutation(std::string str, std::string perm)
{
    if (str.empty()) std::cout << perm << std::endl;
    else
    {
        for (size_t i = 0; i < str.size(); ++i)
        {
            next_permutation(str.substr(1), perm + str[0]); //перестановка(возврат подстроки начиная с 1го по послед,   послед + начальный элемент)
            std::rotate(std::begin(str), std::begin(str) + 1, std::end(str));   //вращение влево на ряде элементов. Меняет местами std::begin(str) и std::end(str), 
            // а std::begin(str) + 1 становится первым элементом нового диапазона
        }
    }
}
void print_permutations_recursive(std::string str)
{
    next_permutation(str, "");
}
//---------------------------------------------------------------------------------
// Средний рейтинг фильмов
//Напишите программу, которая вычислит и выведет средний рейтинг по
//списку фильмов.Каждый фильм в списке имеет рейтинг от 1 до 10 (где 1 – низший
//рейтинг, а 10 – высший).Вычисляя средний рейтинг, отбросьте 5 % фильмов
//с высшим и низшим рейтингами и по остатку вычислите среднее.Результат
//должен выводиться с десятичной точкой.
#include <numeric>
double truncated_mean(std::vector<int> values, double const percentage)
{
    std::sort(std::begin(values), std::end(values));            //отсортировать диапазон, расположив элементы по порядку
    auto remove_count = static_cast<size_t>(values.size() * percentage + 0.5);      

    values.erase(std::begin(values), std::begin(values) + remove_count);    //удалить заданный процент элементов с обоих концов
    values.erase(std::end(values) - remove_count, std::end(values));
     
    auto total = std::accumulate(std::cbegin(values), std::cend(values), 0ull,  //вычислить сумму оставшихся элементов
        [](auto const sum, auto const e) { return sum + e; });

    return static_cast<double>  (total)/values.size();  //найти среднее, разделив сумму на количество оставшихся элементов
}
struct movie
{
    int id;
    std::string title;
    std::vector<int> ratings;
};
void print_movie_ratings(std::vector<movie> const& movies)
{
    for (auto const& m : movies)
    {
        std::cout << m.title << " : "
            << std::fixed << std::setprecision(1)
            << truncated_mean(m.ratings, 0.05) << std::endl;
    }
}
void main_movie()
{
    std::vector<movie> movies
    {
    { 101, "The Matrix", {10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8} },
    { 102, "Gladiator", {10, 5, 7, 8, 9, 8, 9, 10, 10, 5, 9, 8, 10} },
    { 103, "Interstellar", {10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10} }
    };
    print_movie_ratings(movies);
}

//---------------------------------------------------------------------------------
// Алгоритм объединения в пары
//Напишите универсальную функцию, которая принимает диапазон элементов
//и возвращает новый диапазон, состоящий из пар соседних элементов.Если
//число элементов во входном диапазоне нечетное, последний элемент должен
//игнорироваться.Например, для диапазона{ 1, 1, 3, 5, 8, 13, 21 } функция
//должна вернуть{ {1, 1}, {3, 5}, {8, 13} }.
template <typename Input, typename Output>
void pairwise(Input begin, Input end, Output result)
{
    auto it = begin;
    while (it != end)
    {
        auto v1 = *it++; 
        if (it == end) break;
        auto v2 = *it++;
        result++ = std::make_pair(v1, v2);
    }
}
template <typename T>
std::vector<std::pair<T, T>> pairwise(std::vector<T> const& range)
{
    std::vector<std::pair<T, T>> result;
    pairwise(std::begin(range), std::end(range),
        std::back_inserter(result));
    return result;
}
void main_pair()
{
    std::vector<int> v{ 1, 1, 3, 5, 8, 13, 21 };
    auto result = pairwise(v);
    for (auto const& p : result)
        std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
}
//---------------------------------------------------------------------------------
// Алгоритм «сшивания»
//Напишите функцию, принимающую два диапазона и возвращающую новый
//диапазон с парами элементов из обоих диапазонов.Если два диапазона имеют
//разную длину, результат должен иметь длину по наименьшему из них.Например,
//для входных диапазонов{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } и{ 1, 1, 3, 5,
//8, 13, 21 } должен получиться результат{ {1,1}, {2,1}, {3,3}, {4,5}, {5,8},
//{6,13}, {7,21} }.
template <typename Input1, typename Input2, typename Output>
void zip(Input1 begin1, Input1 end1, Input2 begin2, Input1 end2, Output result)
{
    auto it1 = begin1;
    auto it2 = begin2;
    while (it1 != end1 && it2 != end2)
    {
        result++ = std::make_pair(*it1++, *it2++);
    }
}
template <typename T, typename U>
std::vector<std::pair<T, U>> zip(std::vector<T> const& range1, std::vector<U> const& range2)
{
    std::vector<std::pair<T, U>> result;
    zip(std::begin(range1), std::end(range1),
        std::begin(range2), std::end(range2),
        std::back_inserter(result));
    return result;
}
void main_zip()
{
    std::vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> v2{ 1, 1, 3, 5, 8, 13, 21 };
    auto result = zip(v1, v2);
    for (auto const& p : result)
    {
        std::cout << '{' << p.first << ',' << p.second << '}' << std::endl;
    }
}
//---------------------------------------------------------------------------------
// Алгоритм выбора
//Напишите функцию, которая принимает диапазон значений и функцию проекции,
//преобразует каждое значение в новое и возвращает новый диапазон с
//выбранными значениями.Например, если предположить, что у нас имеется тип
//book с полями id, title и author и диапазон значений типа book, функция должна
//позволить выбрать только названия книг.Вот пример использования функции :
    struct book
    {
    int id;
    std::string title;
    std::string author;
    };

template <typename T, typename A, typename F,
    typename R = typename std::decay<typename std::result_of<typename std::decay<F>::type& (
        typename std::vector<T, A>::const_reference)>::type>::type>
    std::vector<R> select(std::vector<T, A> const& c, F&& f)
{
    std::vector<R> v;
    std::transform(std::cbegin(c), std::cend(c),
        std::back_inserter(v),
        std::forward<F>(f));
    return v;
}
void mainBook()
{
    std::vector<book> books{
    {101, "The C++ Programming Language", "Bjarne Stroustrup"},
    {203, "Effective Modern C++", "Scott Meyers"},
    {404, "The Modern C++ Programming Cookbook", "Marius Bancila"} };
    auto titles = select(books, [](book const& b) {return b.title; });
    for (auto const& title : titles)
        std::cout << title << std::endl;
}
//---------------------------------------------------------------------------------
// Алгоритм сортировки
//Напишите функцию, которая принимает пару итераторов с произвольным
//доступом, определяющих границы диапазона, и сортирует элементы в этом
//диапазоне с использованием алгоритма быстрой сортировки.Вы должны
//определить две перегруженные версии функции : одну, использующую для
//сравнения элементов operator<, и другую, принимающую пользовательскую
//функцию сравнения.
//---------------------------------------------------------------------------------
// Кратчайший путь между узлами
//Напишите программу, принимающую сеть узлов и расстояний между ними,
//вычисляющую и отображающую кратчайшие расстояния из указанного узла во
//все остальные, а также путь между начальным и конечным узлами.Например,
//для неориентированного графа на рис. 6.1 и узла A.
template <typename Vertex, typename Weight>     //реализаций алгоритма поиска кратчайшего 
void shortest_path( graph<Vertex, Weight> const& g, 
    Vertex const source, std::map<Vertex, Weight>& min_distance, std::map<Vertex, Vertex>& previous)
{
    auto const n = g.vertex_count();
    auto const verteces = g.verteces();
    min_distance.clear();
    for (auto const& v : verteces)
        min_distance[v] = graph<Vertex, Weight>::Infinity;
    min_distance[source] = 0;
    previous.clear();
    std::set<std::pair<Weight, Vertex> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));
    while (!vertex_queue.empty())
    {
        auto dist = vertex_queue.begin()->first;
        auto u = vertex_queue.begin()->second;
        vertex_queue.erase(std::begin(vertex_queue));
        auto const& neighbors = g.neighbors(u);
        for (auto const& neighbor : neighbors)
        {
            auto v = neighbor.first;
            auto w = neighbor.second;
            auto dist_via_u = dist + w;
            if (dist_via_u < min_distance[v])
            {
                vertex_queue.erase(std::make_pair(min_distance[v], v));
                min_distance[v] = dist_via_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));
            }
        }
    }
}
template <typename Vertex>      //вспомогательная функция выводит результаты в требуемом формате
void build_path( std::map<Vertex, Vertex> const& prev, Vertex const v, std::vector<Vertex>& result)
{
    result.push_back(v);
    auto pos = prev.find(v);
    if (pos == std::end(prev)) return;
    build_path(prev, pos->second, result);
}
template <typename Vertex>
std::vector<Vertex> build_path(std::map<Vertex, Vertex> const& prev, Vertex const v)
{
    std::vector<Vertex> result;
    build_path(prev, v, result);
    std::reverse(std::begin(result), std::end(result));
    return result;
}
template <typename Vertex>
void print_path(std::vector<Vertex> const& path)
{
    for (size_t i = 0; i < path.size(); ++i)
    {
        std::cout << path[i];
        if (i < path.size() - 1) std::cout << " -> ";
    }
}
void mainDijk()
{
    graph<char, double> g;
    g.add_edge('A', 'B', 7);
    g.add_edge('A', 'C', 9);
    g.add_edge('A', 'F', 14);
    g.add_edge('B', 'C', 10);
    g.add_edge('B', 'D', 15);
    g.add_edge('C', 'D', 11);
    g.add_edge('C', 'F', 2);
    g.add_edge('D', 'E', 6);
    g.add_edge('E', 'F', 9);
    char source = 'A';
    std::map<char, double> min_distance;
    std::map<char, char> previous;
    shortest_path(g, source, min_distance, previous);
    for (auto const& kvp : min_distance)
    {
        std::cout << source << " -> " << kvp.first << " : "
            << kvp.second << '\t';
        print_path(build_path(previous, kvp.first));
        std::cout << std::endl;
    }
}
//---------------------------------------------------------------------------------
//Есть список из структур . В нём рандом указывает на какой-то ещё элемент этого же списка. 
//Требуется написать функцию, которая копирует этот список с сохранением структуры.
struct NewNode
{
    int data;
    NewNode* next;
    NewNode* random;
    NewNode(int data) : data(data), next(nullptr) {}
};
NewNode* copyList(NewNode* head)
{
    for (NewNode* cur = head; cur != NULL; cur = cur->next) //обход списка
    {
        NewNode* dupl = (NewNode*)malloc(sizeof(NewNode));      //создаём дубликаты узлов и вставляем их по next
        dupl->data = cur->data;
        dupl->next = cur->random;           //каждый нечётный ссылается на свой дубликат
        cur->random = dupl;
    }
    NewNode* res = head->random;
    for (NewNode* cur = head; cur != NULL; cur = cur->next)
    {
        NewNode* dupl =  cur->random;         
        dupl->random = dupl->next->random;      //в каждом чётном узле random = random.next
    }
    for (NewNode* cur = head; cur != NULL; cur = cur->next)
    {
        NewNode* dupl = cur->random;
        cur->random = dupl->next;           
        dupl->next = cur->next ? cur->next->random : NULL;      //в каждом узле next = next.next
    }
    return res;
}

//---------------------------------------------------------------------------------
//Напишите программу, которая читала бы информацию о фильмах из базы
//данных SQLite и выводила ее в консоль.Для каждого фильма должны выводиться :
//числовой идентификатор, название, год выхода, продолжительность
//в минутах, список режиссеров, список сценаристов и список ролей с именами
//актеров.На рис. 10.4 показана диаграмма со схемой базы данных для этой задачи.
/*struct casting_role
{
    std::string actor;
    std::string role;
};
struct movie
{
    unsigned int id;
    std::string title;
    int year;
    unsigned int length;
    std::vector<casting_role> cast;
    std::vector<std::string> directors;
    std::vector<std::string> writers;
};
using movie_list = std::vector<movie>;
//Вывод в консоль осуществляет функция print_movie():
void print_movie(movie const& m)
{
    std::cout << "[" << m.id << "] "
        << m.title << " (" << m.year << ") "
        << m.length << "min" << std::endl;
    std::cout << " directed by: ";
    for (auto const& d : m.directors) std::cout << d << ",";
    std::cout << std::endl;
    std::cout << " written by: ";
    for (auto const& w : m.writers) std::cout << w << ",";
    std::cout << std::endl;
    std::cout << " cast: ";
    for (auto const& r : m.cast)
        std::cout << r.actor << " (" << r.role << "),";
    std::cout << std::endl << std::endl;
}

std::vector<std::string> get_directors(sqlite3_int64 const movie_id, sqlite::database& db)
{
    std::vector<std::string> result;
    db << R"(select p.name from directors as d join persons as p on d.personid = p.rowid where d.movieid = ?;)"
    << movie_id  >> [&result](std::string const name)
    {
        result.emplace_back(name);
    };
    return result;
}

// функция get_writers() читает информацию о сценаристах фильма из таблицы writers :
std::vector<std::string> get_writers(sqlite3_int64 const movie_id, sqlite::database& db)
{
    std::vector<std::string> result;
    db << R"(select p.name from writers as w join persons as p on w.personid = p.rowid where w.movieid = ?;)"
    << movie_id >> [&result](std::string const name)
    {
        result.emplace_back(name);
    };
    return result;
}

std::vector<casting_role> get_cast(sqlite3_int64 const movie_id,
    sqlite::database& db)
{
    std::vector<casting_role> result;
    db << R"(select p.name, c.role from casting as c join persons as p on c.personid = p.rowid where c.movieid = ?;)"
    << movie_id >> [&result](std::string const name, std::string role)
    {
        result.emplace_back(casting_role{ name, role });
    };
    return result;
}
//Все эти функции вызываются из функции get_movies(), которая возвращает
//список всех фильмов из базы данных :
movie_list get_movies(sqlite::database& db)
{
    movie_list movies;
    db << R"(select rowid, * from movies;)"
        >> [&movies, &db](sqlite3_int64 const rowid,  std::string const& title,  int const year,  int const length)
    {
        movies.emplace_back(movie{
        static_cast<unsigned int>(rowid),
        title,
        year,
        static_cast<unsigned int>(length),
        get_cast(rowid, db),
        get_directors(rowid, db),
        get_directors(rowid, db)
            });
    };
    return movies;
}

int main()
{
    try
    {
        sqlite::database db(R"(cppchallenger85.db)");
        auto movies = get_movies(db);
        for (auto const& m : movies)
            print_movie(m);
    }
    catch (sqlite::sqlite_exception const& e)
    {
        std::cerr << e.get_code() << ": " << e.what() << " during "
            << e.get_sql() << std::endl;
    }
    catch (std::exception const& e)
    {
        std::cerr << e.what() << std::endl;
    }
}*/
//---------------------------------------------------------------------------------
//Очередь людей(класс P e r s o n) выстроилась к почтовому отделению.Класс
//P e r s o n имеет атрибуты, хранящие возраст и пол, и определен следующим образом :
//Напишите бинарный предикат для использования в   p r i o r i t y   q u e u e, который
//позволит сотруднику обслужить сначала стариков и женщин(в указанном порядке).
class Person
{
public:
    int age;
    bool isFemale;

    bool operator<(const Person& anotherP) const
    {
        bool bRet = false;
        if (age > anotherP.age)
            bRet = true;
        else if (isFemale && anotherP.isFemale)
            bRet = true;

        return bRet;
    }
};

//1. Отладка.Найдите ошибку в следующем коде :
void func1()
{
    fstream myFile;
    myFile.open("HelloFile.txt", ios_base::out);
    myFile << "Некоторый текст";
    myFile.close();
}
//Ответ:  Вы открыли файл, но не проверили успех этой операции с помощью метода myFile.is_open(); прежде чем использовать поток или закрыть его
// 
//2. Отладка.Найдите ошибку в следующем коде :
void func2()
{
    ifstream myFile("SomeFile.txt");
    if (myFile.is_open())
      //  myFile << "Некоторый текст" << endl;
    myFile.close();
}
//Ответ: Вы не можете писать в поток i f stream, который предназначен только для чтения, но не для записи, и следовательно, не поддерживает оператор вывода в поток «

#include <exception>
//1. Отладка.Что не так в следующем коде ?
class SomelntelligentStuff
{
    bool StuffGoneBad;
public:
    ~SomelntelligentStuff()
    {
        if (StuffGoneBad)
            throw "Проблема в данном классе";
    }
};
//Ответ: Никогда не генерируйте исключения в деструкторах.

//2. Отладка.Что не так в следующем коде ?
int func3()
{
    int* pMillionlntegers = new int[1000000];
    // Сделать нечто с миллионом целых чисел
    delete[]pMillionlntegers;
}
//Ответ: Вы забыли обработать исключения(пропустили блок try . . . catch).

//3. Отладка.Что не так в следующем коде ?
int func4()
{
    try
    {
        int* pMillionlntegers = new int[1000000];
        // Сделать нечто c миллионом целых чисел
        delete[]pMillionlntegers;
    }
    catch (exception& exp)
    {
        int* pAnotherMillionlntegers = new int[1000000];
        // Создать резервную копию pMillionlntegers
        // и сохранить ее на диске
    }
}
//Ответ: Не выделяйте память в блоке catch!Тем более такое большое ее количество.
//Если учесть, что вам уже не удалось выделить память в блоке try, продолжать попытки выделения не имеет никакого смысла.

//1. Отладка.Найдите ошибку в следующем коде :
/*void func5()
{
    std::auto_ptr<SampleClass> object(new SampleClass());
    std::auto_ptr<SampleClass> anotherObject(object);
    object->DoSomething();
    anotherObject->DoSomething();
}*/
//Ответ:Ошибка в строке object->DoSomething();, так как указатель потерял владение
//объектом во время предыдущего копирования.Эта строка приведет к сбою (или к какой - то иной неприятности).


//2. Используйте класс u nique_ptr для создания экземпляра класса Carp, наследника
//класса Fish.Передайте объект как указатель на Fish и отметьте комментарием срезку, если таковая имеет место.

#include <memory>

class Fish {
public:
    Fish(){
    cout << "Конструктор Fish" << endl;
    }
    ~Fish(){
        cout << "Деструктор Fish" << endl;
    }
    void Swim() const { cout << "Fish плавает в воде" << endl; }
};

class Carp : public Fish 
{   };

void MakeFishSwim(const unique_ptr<Fish>& inFish) {
    inFish->Swim();
}
int func6() {
    unique_ptr<Fish> myCarp(new Carp);
    MakeFishSwim(myCarp);
    return 0;
}
//Ответ:Поскольку здесь нет никакого копирования, при условии, что функция Маке
//FishSwimO получает аргумент как ссылку, никакой срезки не происходит.
//Кроме того, обратите внимание на синтаксис создания экземпляра переменной myCarp.

//3. Отладка.Укажите ошибку в следующем коде :
/*void func7()
{
    std::unique_ptr<Tuna> myTuna(new Tuna);
    unique_ptr<Tuna> copyTuna;
    copyTuna = myTuna;
}*/
//Ответ:Класс unique_ptr не допускает копирования и присваивания, поскольку и копирующий
//конструктор, и копирующий оператор присваивания являются закрытыми.


//787 leet
int findCheapPrice(int n, const vector<vector<int>>& flights, int src, int dst, int k)
{
    const int INF = 1000 * 1000 * 1000;
    const int SRC = 0;
    const int DST = 1;
    const int PRICE = 2;
    vector<vector<int>> minCost(1+k, vector<int>(n, INF));
    //[maxIntermediate][last] -> min cost to read 'last from src' using not more than 'maxIntermedediate' vertices
    for (const auto& flight : flights)
    {
        if (flight[SRC] == src)
            minCost[0][flight[DST]] = min(minCost[0][flight[DST]], flight[PRICE]);
    }
    minCost[0][src] = 0;
    for (int kk = 1; kk <= k; kk++)
    {
        for (int i = 0; i < n; i++)
            minCost[kk][i] = minCost[kk - 1][i];
        for (const auto& flight : flights)
        {
            int s = flight[SRC];
            int d = flight[DST];
            int p = flight[PRICE];
            minCost[kk][d] = min(minCost[kk][d], minCost[kk - 1][s] + p);
        }
    }

    if (minCost[k][dst] == INF)
        return -1;
    else
        return minCost[k][dst];

}
                                                                                        
//764 leet largest plus sign
int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
{
    vector<vector<int>> a(n, vector<int>(n, 1));
    for (auto point : mines)
        a[point[0]][point[1]] = 0;

    vector<vector<int>> jp1(n, vector<int>(n, 1));  //j -> j+1
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            if (a[i][j + 1] == 1)
                jp1[i][j] = jp1[i][j + 1] + 1; 
    vector<vector<int>> ip1(n, vector<int>(n, 1));  //i -> i+1
    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            if (a[i+1][j] == 1)
                ip1[i][j] = ip1[i+1][j] + 1;
    vector<vector<int>> jm1(n, vector<int>(n, 1));  //j -> j-1
    for (int i = 0; i < n; i++)
        for (int j = 1; j <n; j++)
            if (a[i][j-1] == 1)
                jm1[i][j] = jm1[i][j-1] + 1;
    vector<vector<int>> im1(n, vector<int>(n, 1));  //i -> i-1
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i-1][j] == 1)
                im1[i][j] = im1[i-1][j] + 1;

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 1)
                ans = max(ans, 1 + min({ im1[i][j], ip1[i][j], jm1[i][j], jp1[i][j] }));
    return ans;
}


//740 leet

int deleteAndEarn(vector<int>& nums)
{
    vector<int> points (1+10000, 0);
    for (int v : nums)
        points[v] += v;
    vector<int> maxPoints(1 + 10000, 0);
    maxPoints[1] = points[1];
    maxPoints[2] = max(points[1], points[2]);
    for (int v = 3; v <= 10000; v++)
        maxPoints[v] = max(maxPoints[v-1], points[v]+maxPoints[v-2]);
    return maxPoints.back();
}

//718 leet

int findLength(vector<int>& a, vector<int>& b)
{
    int maxLen = 0;
    for(int startA=0;startA<(int)a.size();startA++)
        for (int startB = 0; startB < (int)b.size(); startB++)
        {
            int curMaxLen = min((int)a.size() - startA, (int)b.size() - startB);
            if (curMaxLen <= maxLen)
                break;
            int len = 0;
            while (startA+len < (int)a.size() && startB+len < (int)b.size() && a[startA+len] == b[startB+len])
                len++;
            maxLen = max(maxLen, len);
        }
    return maxLen;
}

//300 leet
//вернуть длину строго возрастающей подпоследовательности
//
int lengthOfSubquenece(const vector<int>& a)
{
    vector<int> minNum(1 + a.size(), INT_MAX);
    int ans = 0;
    for (int v : a)
    {
        auto it = lower_bound(minNum.begin() + 1, minNum.end(), v);
        *it = v;
        ans = max(ans, int(it - minNum.begin()));
    }
    return ans;
}

// 673 leet
// вернуть количество строго возрастающих подпоследовательностей
int lengthOfSubquenece(const vector<int>& a)
{
    vector<int> maxLen(a.size(), 1);
    vector<unsigned> count(a.size());
    for (int i = 0; i < (int)a.size(); i++)
    {
        int len = 0;
        for (int j = 0; j < i; j++)
            if (a[i] < a[j])
                len = max(len, maxLen[j]);
        if (len == 0)
            count[i] = 1;
        else
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i] && maxLen[j] == len)
                    count[i] += count[j];
            }
        maxLen[i] = len + 1;
    }
    int len = 0;
    for (int i = 0; i < (int)a.size(); i++)
        len = max(len, maxLen[i]);
    unsigned sum = 0;
    for (int i = 0; i < (int)a.size(); i++)
        if (maxLen[i] == len)
            sum += count[i];
    return sum;
          
}

//650 leeet
//Дана клавиатура у которой две клавиши и две операции: скопировать и вставить.
//Изначально есть буква А. Нужно получить n штук букв А.
int minSteps(int n)
{
    vector<int> minSteps(1 + n, n);
    minSteps[1] = 0;
    for (int cur = 1; cur < n; cur++)
    {
        for (int mul = 2; cur*mul <= n; mul++)
        {
            minSteps[cur * mul] = min(minSteps[cur * mul], minSteps[cur] + mul);
        }
    }
    return minSteps[n];
}


// встречаются ли все символы строки в сней один раз?
bool isUniqueChars(string str)
{
    if (str.length() > 128)
        return false;
    bool* charSet = new bool[128];
    for (int i = 0; i < str.length(); i++)
    {
        int val = str.at(i);
            if (charSet[val])
                return false;
    charSet[val] = true;
    }
    delete[] charSet;
    return true;
}

//Для двух строк напишите метод, определяющий, является ли одна строка
//перестановкой другой
bool permutation(string s, string t) 
{
     if (s.length() != t.length()) 
         return false;
       
     int* letters = new int[128]; // Предположение
    
     char* s_array = new char[s.length()+1];
     s.copy(s_array, s.length() + 1);       //копирование последов-сти символов из строки в массив символов

     for(int i=0;s_array[i]!='\0';i++) // Подсчет вхождений каждого символа в s.
        letters[i];
       
     
     /*for (int j = 0; j < t.length(); j++)
     {
         int с = (int)t.at(j);
         letters[c--];
         if (letters[c] < 0)
             return false;
     }*/
  return true;
}
//
//Напишите метод, заменяющий все пробелы в строке символами '% 20'.Можете
//считать, что длина строки позволяет сохранить дополнительные символы,
//а фактическая длина строки известна заранее.

void replaceSpaces(char str[], int length)
{
    int spaceCount = 0, newLength;
    for (int i = 0; i< length;i++)
    {
        if (str[i] == ' ')
            spaceCount++;
    }

    newLength = length + spaceCount * 3;
    str[newLength] = '\0';
    for (int i = length-1; i>=0; i--)
    {
        if (str[i] == ' ')
        {
            str[newLength - 1] = '0';
            str[newLength - 2] = '2';
            str[newLength - 3] = '%';
            newLength -= 3;                 //прошли 3 символа, заменившие один пробел
        }
        else
        {
            str[newLength - 1] = str[i];   //просто копируется символ
            newLength -= 1;                 //gпрошли один символ
        }
    }
}

//Напишите функцию, которая проверяет, является ли заданная строка перестановкой
//палиндрома. Палиндром не ограничивается словами из словаря.

bool checkMaxOneOdd(int table[])
{
    bool foundOdd = false;

}


//Напишите на С++ метод для вывода последних к строк входного файла.
void printLast10Lines(char* fileName)
{
    const int K = 10;
    ifstream file(fileName);
    string L[K];
    int size = 0;
    /* Файл читается по строкам в циклический массив. Используем peek(), */
    /* чтобы маркер EOF за концом строки не считался отдельной строкой */
    while (file.peek() != EOF)
    {
        getline(file, L[size % K]); //запись из потока в каждый элемент массива L
        size++;
    }
    /* Вычисление начала циклического массива и его размера */
    int start = size > K ? (size % K) : 0;
    int count = min(K, size);

    /* Вывод элементов в порядке их чтения */
    for (int i = 0; i < count; i++) 
        cout << L[(start + i) % K] << endl;
}


int getline_vyvod()     //заполняем контйнер где каждый элемент это предложение
{
    string str;
    vector<string> vec;
    cout << "Input 4 sentences " << endl;
    while ((getline(cin, str, ';')) && (vec.size() < 4))
        vec.push_back(str);

}

//Напишите метод, получающий указатель на структуру Node в параметре и возвращающий
//полную копию переданной структуры данных.Структура данных
//Node содержит два указателя на другие узлы(другие структуры Nodes).
/*
typedef map<Node*, Node*> NodeMap;

Node* copy_recursive(Node* cur, NodeMap& nodeMap)
{
    if (cur == nullptr)
        return NULL;
    NodeMap::iterator i = nodeMap.find(cur);
    if (i != nodeMap.end())
        return i->second;       //Узел уже встречался, вернуть копию

    Node* node = new Node;
    nodeMap[cur] = node; // Сохранить текущий узел перед обходом ссылок
    node->ptrl = copy_recursive(cur->ptrl, nodeMap);
    node->ptr2 = copy_recursive(cur->ptr2, nodeMap);
    return node;
}
Node* copy_structure(Node * root)
{
        NodeMap nodeMap; // Пустой контейнер
        return copy_recursive(root, nodeMap);
}*/

//Напишите класс «умного указателя» - типа данных(обычно реализованного
//на базе шаблона), моделирующего указатель с поддержкой автоматической
//уборки мусора.Умный указатель автоматически подсчитывает количество
//ссылок на объект SmartPointer<T*> и освобождает объект типа т, когда
//число ссылок становится равным О.
template <class Т> class SmartPointer 
{
public:
     SmartPointer(T* ptr) 
     {
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
     }
    
    SmartPointer(SmartPointer<T> &sptr) 
    {
         ref = sptr.ref;
         ref_count = sptr.ref_count;
         ++(*ref_count);       
    }
    
    /* Переопределение оператора присваивания, чтобы при присваивании
    * одного умного указателя другому происходило обновление
    * счетчика ссылок старого указателя. */
    SmartPointer<T> &operator=(SmartPointer<T> &sptr) 
    {
        if (this == &sptr) 
            return* this;
            // Если счетчик ссылок положителен, удалить одну ссылку.
        if (*ref_count > 0) 
            remove();  

        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
        return *this;       
    }
    
    ~SmartPointer()
    {   remove();   }// Удалить одну ссылку на объект.       
    
    Т getValue() 
    {  return * ref;  }
    
protected:
     void remove() 
     {
         --(*ref_count);
         if (*ref_count == 0) 
         {
             delete ref;
             free(ref _count);
             ref = NULL;
             ref_count = NULL;
         }
    }
    
     Т* ref;
     unsigned* ref_count;
};

//Заполнить квадратную матрицу порядка n пo спирали по часовой стрелке начиная с левого верхнего угла
void fill_matrix()
{
    int n, k;       //порядок, счетчик
    int** a;        //матрица
    cout << "input n: ";
    cin >> n;
    a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    k = 1;

    for (int t = 0; t < (n + 1) / 2; t++)
    {
        for (int j = t; j < n - t; j++)
        {
            a[t][j] = k;
            k++;
        }
        for (int i = t+1; i < n - t; i++)
        {
            a[i][n-1-t] = k;
            k++;
        }
        for (int j = n-2-t; j>= t; j--)
        {
            a[n-1-t][j] = k;
            k++;
        }
        for (int i = n - 2 - t; i > t; i--)
        {
            a[i][t] = k;
            k++;
        }
    }

   // show_matrix(a, n, n);

    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}

//Сумма натуральных чисел, кратных 3 и 5
int main()
{
    unsigned int limit = 0;
    std::cout << "Upper limit: ";
    std::cin >> limit;
    unsigned long long sum = 0;
    for (unsigned int i = 3; i < limit; ++i)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    std::cout << "sum=" << sum << std::endl;
}

//Наибольший общий делитель
unsigned int gcd(unsigned int const a, unsigned int const b)
{
    return b == 0 ? a : gcd(b, a % b);
}

//Преобразование десятичных чисел в римские

std::string to_roman(unsigned int value)
{
    std::vector<std::pair<unsigned int, char const*>> roman
    {
    { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" },
    { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" },
    { 10, "X" },  { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" } };

    std::string result;
    for (auto const& kvp : roman) 
    {
        while (value >= kvp.first) 
        {
            result += kvp.second;
            value -= kvp.first;
        }
    }
    return result;
}
//Вот как можно использовать эту функцию :
int main()
{
    for (int i = 1; i <= 100; ++i)
    {
        std::cout << i << "\t" << to_roman(i) << std::endl;
    }
    int number = 0;
    std::cout << "number: ";
    std::cin >> number;
    std::cout << to_roman(number) << std::endl;
}

//На плоскости задан круг с центром в начале координат и набор точек. Его радиус, кол-во точек и 
//их кооординаты вводятся с клавиатуры. Найдите точку вне круга, ближайшую к нему.
void PointOutcircle()
{
    double xmin, ymin, r, x, y;
    bool flag = false;
    int n;

    cout << "input radius: ";
    cin >> r;

    cout << "Input count of points: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << "Input x and y of " << i << "point: ";
        cin >> x >> y;

        if (sqrt(x * x + y * y) > r && (!flag || sqrt(x * x + y * y) < sqrt(xmin * xmin + ymin * ymin)))
        {
            flag = true;
            xmin = x;
            ymin = y;
        }
    }
    if (flag)
    {
        cout << "xmin: " << xmin << endl;
        cout << "ymin: " << ymin << endl;
        cout << "dmin: " << sqrt(xmin * xmin + ymin * ymin) << endl;
    }
    else
        cout << "COULD NOT FOUND";
}
#include <conio.h>
//Удалить в массиве все числа которые повторяются более двух раз
void func()
{
    int arr[100];
    int n = 10;
    int i, j, count = 0;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
        cout << setw(4) << arr[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] == arr[i])
                count++;
        }
        if (count > 2)
        {
            int one = arr[i];
            for (j = i + 1; j < n; j++)
            {
                if (arr[j] == one)
                {
                    for (int k = j + 1; k < n; k++)     //delete
                    {
                        arr[k - 1] = arr[k];
                    }
                    n--;
                    j--;
                }
            }
            i--;
        }
    }
    if (n == 0)
        cout << "empty array " << endl;
    else
        for (int p = 0; p < n; p++)
            cout << setw(4) << arr[p];
    cout << endl;
    getch();        //чтение одного символа с клавиатуры, чтобы не дать консоли преждевер закрыться
}

void f_matrix()
{
    int n, m;       //порядок, счетчик
    int** a;        //матрица
    cout << "input n: ";
    cin >> n;
    cout << "input n: ";
    cin >> m;

    a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    
    for(int i=0;i<n;i++)

}
//----------------------------------------------------
class A
{
public:
    A(int x)
    {
        std::cout << "Constructor (int)" << x << "\n";
    }
    A(const A&)
    {
        std::cout << "Copy constructor\n" << "\n";
    }
    virtual ~A()
    {
        std::cout << "Destructor\n" << "\n";
    }
    virtual void foo() const
    {
        std::cout << "A::foo()\n";
    }
};

class B : public A
{
    A field;
public:
    B(): A(42), field(17)
    {   }
};

int main_class()
{
    std::unique_ptr<A> ptr(new B);
    ptr->foo();
}

//----------------------------------------
