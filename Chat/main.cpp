#include "Chat.h"

int main
{
	Chat chat;

    chat.start(); //������

	while (chat.isChatWork()) //���� ��� ��������
	{
		chat.showLoginMenu();  //����� ����

		while (chat.getCurrentUser())  //���� ����� ����-�� �� ����� nullptr 
		{                              //�� ��� ���� ���������� ���� ���.�����
			chat.showUserMenu();
		}
	}

	return 0;

}