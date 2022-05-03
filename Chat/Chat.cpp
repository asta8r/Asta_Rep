
#include <iostream>
#include "Chat.h"
using namespace std;

void Chat::start()  //запуск
{
	isChatWork_ = true;
}

void Chat::login() //проверка логина
{
	string login, password;
	char operation;

	do
	{
		std::cout << "login: ";
		std::cin >> login;
		std::cout << "password: ";
		std::cin >>password;

		CurrentUser_ = getUserByLogin(login);  //находится указатель на данный логин

		if (CurrentUser_ == nullptr || (password != CurrentUser_->getUserPassword())) //если указ-ль не находится
		{
			CurrentUser_ == nullptr;
			std::cout<< "login failed" << endl;
			std::cout << "0 - exit or any key - repeat "<< endl;
			std::cin>>operation;

			if(operation == 0)
				break;
		}
	} while(!CurrentUser_);
}
void Chat::signUp()  //регистрация
{
	std::string login, password, name;
	std::cout << "login: ";
	std::cin >> login;
	std::cout << "password: ";
	std::cin >> password;
	std::cout << "name: ";
	std::cin >> name;

	if (getUserByLogin(login) || login == "all")  //проверка на уникльность логина 
		throw UserLoginExp();
	if (getUserByName(name) || name == "all")
		throw UserNameExp();

	User user = User(login, password, name);  //временный объект
	users_.push_back(user);                  //положили в контейнер юзеров
	CurrentUser_ = std::make_shared<User>(user);  //текущ указ-ль указывает на тот который сейчас создался

}
void Chat::showChat() const  //показать чат
{
	std::string from;
	std::string to;

	std::cout << "/*---chat---*/" << endl;

	for (auto& mess : messagesList_)  //для всех сообщений
	{
		if (CurrentUser_->getUserLogin() == mess.getFrom() || CurrentUser_->getUserLogin() == mess.getTo() || mess.getTo() == "all")
		{
			from = (CurrentUser_->getUserLogin() == mess.getFrom()) ? "me" : getUserByLogin(mess.getFrom())->getUserName();  //если сообщ от меня то пишем "Я" иначе имя юзера

			if (mess.getTo() == "all")  //если сообщ адресовано ВСЕМ
				to = "all";
			else
				to = CurrentUser_->getUserLogin() == mess.getTo() ? "me" : getUserByLogin(mess.getTo())->getUserName();

			std::cout << "Message from " << from << "to " << to << std::endl;
			std::cout << "text: " << mess.getText() << std::endl;
		}
	}
}
void Chat::showAllUsersName() const   //показать всех пользователей
{
	std::cout << "/*---users---*/" << endl;

	for (auto& user : users_)
	{
		std::cout << user.getUserName();

		if (CurrentUser_->getUserLogin() == user.getUserLogin())  //если логин текущего совпадает с логином итерируемого то пишем Я
			std::cout << "me";
		std::cout << std::endl;
	}
	std::cout<<"/*-----------*/" << std::endl;
}
void Chat::addMessage()  //добавить сообщение
{
	std::string to, text;

	std::cout << "To (name or all)";
	std::cin >> to;
	std::cout << "Text: ";
	std::cin.ignore();      //игнорировать служебные символы, н-р перевод строки
	getline(std::cin, text);    

	if (!(to == "all" || getUserByName(to)))  //если не удалось найти получателя по имени
	{
		std::cout << "error send message: can't find address" << to << endl;
		return;
	}

	if (to == "all")
		messagesList_.push_back(Message{ CurrentUser_->getUserLogin(), "all", text});  //положить в конец массива с получателем "ВСЕ"
	else                                  //либо положить в конец массива с получателем КОНКРЕТНЫМ	
		messagesList_.push_back(Message{ CurrentUser_->getUserLogin(), getUserByName(to)->getUserLogin(), text }); 
}

std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (auto& user : users_)  //проходим по всему массиву юзеров
	{
		if (login == user.getUserLogin())  // проверяем если совпал логин то возвращает указ-ль на текущего юзера
			return std::make_shared<User>(user);
	}
	return nullptr;
}

std::shared_ptr<User> Chat::getUserByName(const std::string& name) const    
{
	for (auto& user : users_)
	{
		if (name == user.getUserName())
			return std::make_shared<User>(user);
	}
	return nullptr;
}


void Chat::showLoginMenu()
{
	CurrentUser_ = nullptr;
	char act;

	do
	{
		std::cout << "1 - login " << std::endl;
		std::cout << "2 - signUp " << std::endl;
		std::cout << "3 - exit " << std::endl;
		std::cout << ">>" << std::endl;

		std::cin >> act;

		switch (act)
		{
		case '1': login();
			break;
		case '2':
			try
			{
				signUp();
			}
			catch (const std::exception& e)  //если неуникальный логин или имя сработает исключение
			{
				std::cout << e.what() << std::endl;
			}
			break;
		case '0': isChatWork_ = false;
			break;

		default:
		std:cout << "1 or 2..." << std::endl;
			break;
		}
	} while (!CurrentUser_ && isChatWork_); //пока чат работает и есть текущий юзер
}
void Chat::showUserMenu()  //меню для текущего пользователя 
{
	char operation;
	std::cout << "Hi, " << CurrentUser_->getUserName() << endl;

	while (CurrentUser_)
	{
		std::cout << "Menu: \n 1 -Show chat,\n 2 - Add message,\n 3 - Users,\n 4 - Logout";

		std::cout << std::endl << ">>";
		std::cin >> operation;
		switch (operation)
		{
		case '1': showChat();
			break;
		case '2': addMessage();
			break;
		case '3': showAllUsersName();
			break;
		case '0': CurrentUser_ = nullptr;
			break;
		default: std::cout << "unknown choice" << std::endl;
			break;
		}
	}
}

