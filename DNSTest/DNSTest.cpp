
#include <winsock.h>
#include <wsipx.h>
#include <wsnwlink.h>
#include <stdio.h>
#pragma comment(lib, "WS2_32.lib")
int main()
{

	WORD wVersionRequested = MAKEWORD(1, 1);
	WSADATA wsaData;
	if (WSAStartup(wVersionRequested, &wsaData)) 
	{
		printf("WSAStartup failed %s\n", WSAGetLastError());
		return -1;
	}

//////////////////
// ���������.
//
	char hostname[256];
	do{
		/*
		int res = gethostname(hostname, sizeof(hostname));
		if (res != 0) {
			printf("Error: %u\n", WSAGetLastError());
			return -1;
		}
		*/
		memset(hostname, '\0', sizeof(hostname));
		printf("Input the Domain Name that you wanna to know its IP\n");
		scanf("%s", &hostname);
	////////////////
	// ������������ȡ������Ϣ. 
	//
		hostent* pHostent = gethostbyname(hostname);
		if (pHostent==NULL) 
		{
			printf("Error: %u\n", WSAGetLastError());
			return -1;
		}
	//////////////////
	// �������ص�hostent��Ϣ.
	//
		hostent& he = *pHostent;
		/*
		printf("name=%s\naliases=%s\naddrtype=%d\nlength=%d\n",

		he.h_name, he.h_aliases, he.h_addrtype, he.h_length);
		*/
		sockaddr_in sa;
		for (int nAdapter=0; he.h_addr_list[nAdapter]; nAdapter++) 
		{
			memcpy ( &sa.sin_addr.s_addr, he.h_addr_list[nAdapter],he.h_length);
		// ���������IP��ַ.
			printf("Address: %s\n", inet_ntoa(sa.sin_addr)); // ��ʾ��ַ��
		}
	}while(strcmp(hostname, "q") && strcmp(hostname, "Q"));
//////////////////
// ��ֹ Windows sockets API
//
	
	WSACleanup();
	return 0;
}
/*��֪����S={��A������B������C��}����������n��Ҫ��������������������ַ���������Ϊn���ַ�����ÿ���ַ����Ǽ���S��Ԫ��*/
char S[3] = {'A', 'B', 'C'};
void DFS(int n, int i)
{
	printf("%c", S[i]);
	if(n > 0)		//����ȵ���0ʱ���ٵݹ飬��ʼ����
	{
		for(int index = 0; index < 3; ++index)
		{
			DFS(n - 1, index);	//ÿ����һ�εݹ���ȼ�һ
		}
	}
}
//���������е�������DFS������n=5����Ϊ5�������ַ������
for(int i = 0; i < 3; ++i)
	DFS(5, i);

  search(int deep, int i)
If deep > 0
  Print  Si
  For index 1 to 3
    search(deep-1, index);