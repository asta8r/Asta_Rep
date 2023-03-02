#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <ostream>
#include <chrono>
#include <vector>
#include "string.h""
#include <array>
#include <sstream>
using namespace std;

//#define _CRT_SECURE_NO_WARNINGS

class Array
{
    friend istream& operator>> (istream&, Array&);
    friend ostream& operator<< (ostream&, const Array&);
    int* ptr;
    int size;
public:
    Array(void);
    Array(int);
    Array(const Array& obj);
    ~Array();

    int getSize() const;
    void setArray();
    void getArray();

    int search(const int) const;
    void sort();
    const Array &operator = (const Array &);
    bool operator == (const Array&) const;
    int& operator[](int);
    Array operator+ (const Array&);
    Array operator+= (const int&);
    Array operator- (const int&);
};
//--------------------------------------------------------------------

class Product
{
    char name[50];
    double price;
    double weight;
public:
    Product()
    {       
        for (int i=0;i<50;i++)
        {
            name[i] = '\0';
        }
    }
    const char*getname() const;
    double getprice() const;
    double getweight() const;

   void setname(const char*);
   void setprice(const double&);
   void setweight(const double&);
};

class Buy : public Product
{
    int countProd;
    double priceAllP;
    double weightAll;
public:
    Buy() {       }
    Buy(int c, double pr, double we) :
        countProd(c), priceAllP(pr), weightAll(we)
    {       }
    int getcountProd() const;
    double getpriceAllP() const;
    double getweightAll() const;

    void setcountProd(const int&);

};

class Check : public Buy
{
public:
    Check() {       }
    void infoProduct();
    void infoBuy();
};

//----------------------------------------------------------------
class Swap
{
    int** arr;

public:

    void fill(int row, int col)
    {
        arr = new int* [row];
        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[col];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = i + j;
                std::cout << arr[i][j] << std::endl;
            }
        }
        std::cout << std::endl;


    }
    void replace(int row, int col)
    {
        int** arrTemp = new int* [col];
        for (int i = 0; i < col; i++)
        {
            arrTemp[i] = new int[row];
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arrTemp[i][j] = arr[j][i];
            }
            std::cout << std::endl;
        }
    }

};

//----------------------------------------------------------------
class DynamicArr
{
    const int COUNT_ELEMENT;
    int* arr;
public:
    DynamicArr(int count = 100);
    ~DynamicArr();
    int& set(int index);
    int get(int index);
    int count();
};

//----------------------------------------------------------------
struct Person
{
    char* fname;
    char* lname;
public:
    Person() {	}
    Person(char* pName, char* pSurname)
    {
        fname = new char[strlen(pName) + 1];
        strcpy(fname, pName);
        lname = new char[strlen(pSurname) + 1];
        strcpy(lname, pSurname);
    }
    ~Person()
    {
        delete[] fname;				delete[]lname;
    }

    char* fullName()
    {
        char* fullname = new char[strlen(fname) + strlen(lname) + 2];
        sprintf(fullname, "%s %s", fname, lname);
        return fullname;
    }
    virtual void print() {};

};

class Student : public Person
{
    int m_group;
public:
    Student() {		}
    Student(char* pName, char* pSurname, int group) : Person(pName, pSurname)
    {
        m_group = group;
    }
    ~Student()
    {	};
    void print()
    {
        cout << " " << endl;
    }
};

class Proffesor : public Person
{
    char* m_kafedra;
public:
    Proffesor() {		}
    Proffesor(char* pName, char* pSurname, char* kafedra) : Person(pName, pSurname)
    {
        m_kafedra = new char[strlen(kafedra) + 1];
        strcpy(m_kafedra, kafedra);
    }
    ~Proffesor()
    {
        delete[] m_kafedra;
    };

    void print()
    {
        cout << " " << endl;
    }
};

//----------------------------------------------------------------
struct ContactItem
{
    string m_name;
    string m_phone;
    string m_displayAs;

    ContactItem(const string& name, const string& phone)
    {
        m_name = name;
        m_phone = phone;
        m_displayAs = (name + ": " + phone);
    }

    bool operator == (const ContactItem& item) const
    {
        return (item.m_name == this->m_name);
    }

    bool operator < (const ContactItem& item) const
    {
        return (this->m_name < item.m_name);
    }

    operator const char* () const
    {
        return m_displayAs.c_str();
    }

};

//----------------------------------------------------------------
class TicTacToe
{
    int currentPlayer;
    std::vector<vector<int>> Table;

    bool CheckRow(size_t i, size_t j) const;
    bool CheckColumn(size_t i, size_t j) const;
    bool CheckDiagonal1(size_t i, size_t j) const;
    bool CheckDiagonal2(size_t i, size_t j) const;

public:
    const size_t N; //размер игрового пол€
    const size_t K; //сколько фишек нужно пост€авить в р€д,чтоб выиграть
    TicTacToe(size_t n, size_t k) : N(n), K(k), currentPlayer(1)
    {
        Table.resize(N);
        for (size_t i = 0; i != N; ++i)
            Table[i].resize(N);
    }
    int operator () (size_t i, size_t j) const;
    int GetCurrentPlayer() const;
    bool Set(size_t i, size_t j);

};

//----------------------------------------------

class ipv4
{
    std::array<unsigned char, 4> data;
public:
    constexpr ipv4() : data{ {0} } {}

    constexpr ipv4(unsigned char const a, unsigned char const b,
        unsigned char const c, unsigned char const d) :
        data{ {a,b,c,d} } {}

    explicit constexpr ipv4(unsigned long a) :
        data{ { static_cast<unsigned char>((a >> 24) & 0xFF),
        static_cast<unsigned char>((a >> 16) & 0xFF),
        static_cast<unsigned char>((a >> 8) & 0xFF),
        static_cast<unsigned char>(a & 0xFF) } } {}

    ipv4(ipv4 const& other) noexcept : data(other.data) {}
    ipv4& operator=(ipv4 const& other) noexcept
    {
        data = other.data;
        return *this;
    }
    std::string to_string() const
    {
        std::stringstream sstr;  //
        sstr << *this;
        return sstr.str();
    }
    constexpr unsigned long to_ulong() const noexcept
    {
        return (static_cast<unsigned long>(data[0]) << 24) |
            (static_cast<unsigned long>(data[1]) << 16) |
            (static_cast<unsigned long>(data[2]) << 8) |
            static_cast<unsigned long>(data[3]);
    }
    friend std::ostream& operator<<(std::ostream& os, const ipv4& a)
    {
        os << static_cast<int>(a.data[0]) << '.'
            << static_cast<int>(a.data[1]) << '.'
            << static_cast<int>(a.data[2]) << '.'
            << static_cast<int>(a.data[3]);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, ipv4& a)
    {
        char d1, d2, d3;
        int b1, b2, b3, b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if (d1 == '.' && d2 == '.' && d3 == '.')
            a = ipv4(b1, b2, b3, b4);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }
    ipv4& operator++()
    {
        *this = ipv4(1 + to_ulong());
        return *this;
    }
    ipv4& operator++(int)
    {
        ipv4 result(*this);
        ++(*this);
        return *this;
    }
    friend bool operator==(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return a1.data == a2.data;
    }
    friend bool operator!=(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return !(a1 == a2);
    }
    friend bool operator<(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return a1.to_ulong() < a2.to_ulong();
    }
    friend bool operator>(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return a2 < a1;
    }
    friend bool operator<=(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return !(a1 > a2);
    }
    friend bool operator>=(ipv4 const& a1, ipv4 const& a2) noexcept
    {
        return !(a1 < a2);
    }
};

//-------------------------------------------------------------

template <class T, size_t R, size_t C> class Arr2
{
    typedef T					value_type;
    typedef value_type* iterator;
    typedef value_type const* const_iterator;
    std::vector<T>				arr;
public:
    Arr2() : arr(R* C) {}
    explicit Arr2(std::initializer_list<T> l) : arr(l) {}
    constexpr T* data() noexcept
    {
        return arr.data;
    }
    constexpr T const* data() const noexcept
    {
        return arr.data;
    }

    constexpr T& at(size_t const r, size_t const c)
    {
        return arr.at(r * C + c);
    }

    constexpr T const& at(size_t const r, size_t const c)
    {
        return arr.at(r * C + c);
    }

    constexpr T& operator() (size_t const r, size_t const c)
    {
        return arr.at[r * C + c];
    }

    constexpr T const& operator() (size_t const r, size_t const c) const
    {
        return arr[r * C + c];
    }

    constexpr bool empty() const noexcept
    {
        return R == 0 || C == 0;
    }

    constexpr size_t size(int const rank) const
    {
        if (rank == 1)
            return R;
        else if (rank == 2)
            return C;
        throw std::out_of_range("Rank is out og range");
    }

    void fill(T const& value)
    {
        std::fill(std::begin(arr), std::end(arr), value);
    }

    void swap(Arr2& other) noexcept
    {
        arr.swap(other.arr);
    }

    const_iterator begin() const
    {
        return arr.data();
    }

    const_iterator end() const
    {
        return arr.data() + arr.size();
    }

    iterator begin()
    {
        return arr.data();
    }

    iterator end()
    {
        return arr.data + arr.size();
    }
};

//-------------------------------------------------
class TimerGuard
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::string outMessage;
    std::ostream& outStream;
public:
    TimerGuard(std::string message = "", std::ostream& out = std::cout) : start(std::chrono::high_resolution_clock::now()), outMessage(message), outStream(out)
    {			}
    ~TimerGuard()
    {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        outStream << outMessage << " " << diff.count() << "\n";
    }
};

//--------------------------------------------------------------
class Serializer
{
public:
    virtual void BeginArray() = 0
    {}
    virtual void AddArrayItem(const std::string&) = 0
    {}
    virtual void EndArray() = 0
    {}
    virtual ~Serializer() {  }
};

class JsonSerializer : public Serializer
{
    bool isFirst = true;
public:
    void BeginArray() override
    {
        if (!isFirst)
            std::cout << ",[";
        else
            std::cout << "[";
        isFirst = true;
    }
    void AddArrayItem(const std::string& str) override
    {
        if (!isFirst)
            std::cout << ",";

        std::cout << "\"" << str << "\"";
        isFirst = false;
    }
    void EndArray() override
    {
        std::cout << "]";
        isFirst = false;
    }
};

struct Node
{
    Node* m_next;
    int m_data;
    Node(int data) :  m_data(data), m_next(nullptr) {  }
};
class List
{
    Node* m_head;
public:
    List();
    ~List();
    void push_back(int data);
    void push_front(int data);
    void insert(int pos, int data);
    void deleteList(int data);
    void deleteNode(int data);
    void reverseList();
};


//реализаци€ String
class MyString
{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;

public:
    MyString(const char* s);
    MyString();
    MyString(const MyString&);
    ~MyString();
    int length() const
    {  return len;   }
    MyString& operator=(const MyString&);
    MyString& operator=(const char*);
    char& operator[] (int i);
    const char& operator[] (int i) const;
    void stringlow();
    void stringup();
    int has(char ch) const;

    friend bool operator< (const MyString& st1, const MyString& st2);
    friend bool operator>(const MyString& st1, const MyString& st2);
    friend bool operator== (const MyString& st1, const MyString& st2);
    friend ostream& operator<< (ostream& os, const MyString& st);
    friend istream& operator>> (istream& is, MyString& st);
    friend MyString operator+ (const MyString& st1, const MyString& st2);

    static int HowMany();
};