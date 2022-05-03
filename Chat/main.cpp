#include "Chat.h"

int main
{
	Chat chat;

    chat.start(); //запуск

	while (chat.isChatWork()) //пока чат работает
	{
		chat.showLoginMenu();  //показ меню

		while (chat.getCurrentUser())  //если текущ поль-ль не равен nullptr 
		{                              //то для него вызывается меню тек.юзера
			chat.showUserMenu();
		}
	}

	return 0;

}