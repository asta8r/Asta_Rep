# Asta_Rep
1.список участников команды - 1 (Ещанова Аксынгул)
2.Описание выбранной идеи решения:
Идея построена на вызове головного меню с возможностью добавлять пользователей, отправлять сообщения, просматривать чат.
Проект состоит из файлов: main.cpp, User.h, Chat.h, Message.h, Chat.h, Chat.cpp.
3.Описание пользовательских типов и функций в проекте:
class Chat, class User, class Message
void login();   //проверка логина
void signUp();   //регистрация
void showChat() const; //показ чата
void showAllUsersName() const;   //показ всех пользователей
void addMessage();               //отправка сообщения
std::vector<User>& getAllUsers()    //геттер на всех юзеров
std::vector<Message>& getAllMessages()    //геттер на все сообщения
std::shared_ptr<User> getUserByLogin(const std::string& login) const;    //геттер на логин юзера
std::shared_ptr<User> getUserByName(const std::string& name) const;      //геттер на имя юзера   
void start();            //запуск
bool isChatWork() const  //проверка работает ли чат
std::shared_ptr<User> getCurrentUser() const //геттер на текущего юзера
void showLoginMenu();         //показ меню
void showUserMenu();          //показ меню для тек.юзера

Использу.ются также в проекте исключения, вектор, умные указатели.
