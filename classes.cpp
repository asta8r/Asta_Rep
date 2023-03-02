#include "header.h"
#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;


Array::Array()
{
    size = 10;
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}
Array::Array(int arrSize)
{
    size = (arrSize > 0 ? arrSize : 10);
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = 0;
}
Array::Array(const Array& obj) : size(obj.size)
{
    ptr = new int[size];
    for (int i = 0; i < size; i++)
        ptr[i] = obj.ptr[i];
}
Array::~Array()
{
    delete[]ptr;
}

int Array::getSize() const
{
    return size;
}
void Array::setArray()
{
    for (int i = 0; i < size; i++)
        cin >> ptr[i];
}
void Array::getArray()
{
    for (int i = 0; i < size; i++)
        cout << std::setw(5) << ptr[i];
    cout << endl;
}

istream& operator>> (istream& input, Array& obj)
{
    for (int i = 0; i < obj.size; i++)
        input >> obj.ptr[i];
    return input;
}
ostream& operator<< (ostream& output, const Array& obj)
{
    for (int i = 0; i < obj.size; i++)
        output << setw(5) << obj.ptr[i];
    output << std::endl;
    return output;
}
int Array::search(const int key) const
{
    for (int i = 0; i < size; i++)
        if (key == ptr[i])
            return (i + 1);
    return -1;
}
void Array::sort()
{
    for (int i = 0; i < size; i++)
    {
        int temp = ptr[0];
        for (int elem = i + 1; elem < size; elem++)
        {
            if (ptr[i] > ptr[elem])
            {
                temp = ptr[i];
                ptr[i] = ptr[elem];
                ptr[elem] = temp;
            }
        }
    }
}

const Array& Array::operator = (const Array& right)
{
    if (&right != this) //чтоб не выполнялось самоприсваивание
    {
        if (size != right.size)
        {
            delete[]ptr; //free space
            size = right.size;      //установить нужный размер массива
            ptr = new int[size];    //выделить память под копируемый массив
        }
        for (int i = 0; i < size; i++)
            ptr[i] = right.ptr[i];  //скопир массив
    }
    return *this; //разрешает множеств.присваивание
}
bool Array::operator == (const Array& right) const
{
    if (size != right.size)
        return false;
    for (int i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return false;
    return true;
}
int& Array::operator[](int subscript)
{
    if (subscript < 0 || subscript >= size)
    {
        std::cerr << " \n Error of index " << subscript << std::endl;
        exit(1); //заверш прогу неправильный индекс
    }
    return ptr[subscript]; //возврат ссылки на элемент массива
}

Array Array::operator+ (const Array& right)
{
    if (size != right.size)
    {
        std::cout << " \n arrays have different sizes \n " << std::endl;
        exit(1); //заверш прогу неправильный индекс
    }
    Array result(size);
    for (int i = 0; i < size; i++)
        result.ptr[i] = ptr[i] + right.ptr[i];  //скопир массив
    return result;
}
Array Array::operator+= (const int& number)
{
    Array result(size);
    result = *this; //временно сохр тек массив
    delete[]ptr;
    size = size + 1; //величиваем размер массива на 1
    ptr = new int[size];
    for (int i = 0; i < (size - 1); i++)
        ptr[i] = result.ptr[i]; //скопируем массив
    ptr[size - 1] = number; //добавляем число в конец массива
    return *this; //каскаднй вызов перегруженного оператора
}
Array Array::operator- (const int& key)
{
    int counterKey = 0;
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == key)
            counterKey++;
    }
    Array temp(size);
    temp = *this;
    delete[] ptr;

    size = size - counterKey;
    ptr = new int[size];
    int counter = 0, i = 0;
    while (counter < size)
    {
        if (temp[counter] != key)
        {
            ptr[i] = temp.ptr[counter];
            i++;
        }
        counter;
    }
    return *this;
}

//----------------------------------------------------------------
const char* Product::getname() const
{
    return name;
}
double Product::getprice() const
{
    return price;
}
double Product::getweight() const
{
    return weight;
}

void Product::setname(const char* n)
{
    strcpy_s(name, n);
}
void Product::setprice(const double& p)
{
    price = (p >= 0) ? p : 0;
}
void Product::setweight(const double& w)
{
    weight = w;
};

int Buy::getcountProd() const
{
    return countProd;
}
double Buy::getpriceAllP() const
{
    return priceAllP;
}
double Buy::getweightAll() const
{
    return weightAll;
}
void Buy::setcountProd(const int& c)
{
    countProd = (c >= 0) ? c : 0;
    priceAllP = c * getprice();
    weightAll = c * getweight();
}

void Check::infoProduct()
{
    std::cout << getname() << std::endl;
    std::cout << getprice() << std::endl;
    std::cout << getweight() << std::endl;

}
void Check::infoBuy()
{
    std::cout << getcountProd() << std::endl;
    std::cout << getpriceAllP() << std::endl;
    std::cout << getweightAll() << std::endl;

}

//----------------------------------------------------------------
DynamicArr::DynamicArr(int count) : COUNT_ELEMENT(count)
{
    arr = new int[COUNT_ELEMENT];
}
DynamicArr::~DynamicArr()
{
    delete[]arr;
}
int& DynamicArr::set(int index)
{
    if (index >= 0 && index < COUNT_ELEMENT)
        return arr[index];
    else
        cout << "error" << endl;
}
int DynamicArr::get(int index)
{
    if (index >= 0 && index < COUNT_ELEMENT)
        return arr[index];
    else
        return -1;
}
int DynamicArr::count()
{
    return COUNT_ELEMENT;
}
void mainDynamicArr()
{
    DynamicArr* obj = new DynamicArr(10);

    for (int i = 0; i < obj->count(); i++)
    {
        obj->set(i) = i * i;
    }
    for (int i = 0; i < obj->count(); i++)
    {
        cout << obj->get(i) << endl;
    }
    delete obj;
}
//-----------------------------------------------------
int TicTacToe::operator () (size_t i, size_t j) const
{
    return Table[i][j];
}

int TicTacToe::GetCurrentPlayer() const
{
    return currentPlayer;
}

bool TicTacToe::Set(size_t i, size_t j)
{
    Table[i][j] = currentPlayer;
    currentPlayer = currentPlayer % 2 + 1;
    bool wins = CheckRow(i, j) || CheckColumn(i, j) || CheckDiagonal1(i, j) || CheckDiagonal2(i, j);
    return wins;
}

bool TicTacToe::CheckRow(size_t i, size_t j) const
{
    size_t d1 = 0;
    while (d1 <= j && Table[i][j - d1] == Table[i][j])
        ++d1;

    size_t d2 = 0;
    while (i + d2 < N && Table[i][j + d2] == Table[i][j])
        ++d2;
    return d1 + d2 > K;
}
bool TicTacToe::CheckColumn(size_t i, size_t j) const
{
    size_t d1 = 0;
    while (d1 <= i && Table[i - d1][j] == Table[i][j])
        ++d1;

    size_t d2 = 0;
    while (i + d2 < N && Table[i + d2][j] == Table[i][j])
        ++d2;
    return d1 + d2 > K;
}
bool TicTacToe::CheckDiagonal1(size_t i, size_t j) const
{
    size_t d1 = 0;
    while (d1 <= i && d1 <= j && Table[i - d1][j - d1] == Table[i][j])
        ++d1;

    size_t d2 = 0;
    while (i + d2 < N && j + d2 < N && Table[i + d2][j + d2] == Table[i][j])
        ++d2;
    return d1 + d2 > K;
}
bool TicTacToe::CheckDiagonal2(size_t i, size_t j) const
{
    size_t d1 = 0;
    while (d1 <= i && j + d1 < N && Table[i - d1][j + d1] == Table[i][j])
        ++d1;

    size_t d2 = 0;
    while (i + d2 < N && d2 <= j && Table[i + d2][j - d2] == Table[i][j])
        ++d2;
    return d1 + d2 > K;
}

std::ostream& operator << (std::ostream& out, TicTacToe& field)
{
    for (size_t i = 0; i != field.N; ++i)
    {
        for (size_t j = 0; j != field.N; ++j)
        {
            switch (field(i, j))
            {
            case 0: std::cout << '.';	break;
            case 1: std::cout << 'X';	break;
            case 2: std::cout << '0';
            }
        }
        std::cout << "\n";
    }
    return out;
}

int TicTacToemain()
{
    setlocale(LC_ALL, "rus");
    size_t n, m;
    cin >> n >> m;
    TicTacToe game(n, m);
    size_t x, y;
    while (cin >> x >> y)
    {
        int curPlayer = game.GetCurrentPlayer();
        if (game.Set(x, y))
            cout << "Player #" << curPlayer << "wins!" << endl;
    }
    cout << game;
    return 0;
}

//-------------------------------------

/*int mainArr2()
{
    // доступ к элементам
    Arr2<int, 2, 3> a{ 1, 2, 3, 4, 5, 6 };

    for (size_t i = 0; i < a.size(1); ++i)
        for (size_t j = 0; j < a.size(2); ++j)
            a(i, j) *= 2;

    // итераторы
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    // заполнение
    Arr2<int, 2, 3> b;
    b.fill(1);
    // перестановка
    a.swap(b);
    // перемещение
    Arr2<int, 2, 3> c(std::move(b));
}*/
//------------------------------------------------------

void SomeFunc()
{
    auto start1 = std::chrono::high_resolution_clock::now();
    //FirstLongFunction();
    std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
    std::cout << "FirstLongFunction elapsed: " << diff1.count() << "\n";

    auto start2 = std::chrono::high_resolution_clock::now();
    //SecondLongFunction();
    std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
    std::cout << "SecondLongFunction elapsed: " << diff2.count() << "\n";

    auto start3 = std::chrono::high_resolution_clock::now();
    //ThirdLongFunction();
    std::chrono::duration<double> diff3 = std::chrono::high_resolution_clock::now() - start3;
    std::cout << "ThirdLongFunction elapsed: " << diff3.count() << "\n";


    TimerGuard timer("FirstLongFunction elapsed: ", std::cout);
    //FirstLongFunction();

   // TimerGuard timer("SecondLongFunction elapsed: ", std::cout);
   // SecondLongFunction();

   // TimerGuard timer("ThirdLongFunction elapsed: ", std::cout);
   // ThirdLongFunction();
}

//------------------------------------------------------------

int MyString::num_strings = 0;  //кол-во строк

MyString::MyString(const char* s)
{
    len = strlen(s);   //иниц длины
    str = new char[len + 1];   //выделение памяти под строку
    strcpy(str, s);     //копирование польз.строки в базовую строку
    num_strings++;      //увеличение кол-ва строк
}
MyString::MyString()        //???
{
    len = 0;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}
MyString::MyString(const MyString& st)
{
    num_strings++;  //увел.счётчик строк
    len = st.len;           //копирование пользов.длины в базовую
    str = new char[len + 1];    //выделение памяти под строку
    strcpy(str, st.str);        //копирование строки
}
MyString::~MyString()
{
    --num_strings; //уменьш.счетчика
    delete[] str;       
}
MyString& MyString::operator=(const MyString& st)
{
    if (this == &st)           //???
        return *this;

    delete[] str;
    len = st.len;
    str = new char[len + 1];
    strcpy(str, st.str);
    return *this;
}
MyString& MyString::operator=(const char* s)
{
    delete[] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}
char& MyString::operator[] (int i)
{
    return str[i];
}
const char& MyString::operator[] (int i) const        //зачем такая же функция???
{
    return str[i];
}
void MyString::stringlow()
{
    for (int i = 0; i < len; ++i)
        str[i] = (char)tolower(str[i]);
}
void MyString::stringup()
{
    for (int i = 0; i < len; ++i)
        str[i] = (char)toupper(str[i]);
}
int MyString::has(char ch) const      //имеет ли строка заданный символ
{
    int counter = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == ch)
            ++counter;
    return counter;
}
bool operator< (const MyString& st1, const MyString& st2)
{
    return (strcmp(st1.str, st2.str) < 0);          //???
}
bool operator>(const MyString& st1, const MyString& st2)
{
    return st2 < st1;                               //???
}
bool operator== (const MyString& st1, const MyString& st2)
{
    return (strcmp(st1.str, st2.str));
}
ostream& operator<< (ostream& os, const MyString& st)
{
    os << st.str;
    return os;
}
istream& operator>> (istream& is, MyString& st)
{
    char temp[MyString::CINLIM];
    is.get(temp, MyString::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
MyString operator+ (const MyString& st1, const MyString& st2)
{
    MyString n_temp;                  //временный объект 
    delete[] n_temp.str;                     //стираем строку, выделенную в конструкторе по ум.
    n_temp.len = st1.len + st2.len;         //вычисляем длину будущей строки
    n_temp.str = new char[n_temp.len+1];            //выделяем место для новой строки + нулевой символ
    strcpy(n_temp.str, st1.str);
    strcpy(n_temp.str+st1.len, st2.str);          //сцепляем и сохр в новый обект
    return n_temp;
}
int MyString::HowMany()
{
    return num_strings;
}

