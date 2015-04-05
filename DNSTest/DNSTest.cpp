
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
// 获得主机名.
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
	// 根据主机名获取主机信息. 
	//
		hostent* pHostent = gethostbyname(hostname);
		if (pHostent==NULL) 
		{
			printf("Error: %u\n", WSAGetLastError());
			return -1;
		}
	//////////////////
	// 解析返回的hostent信息.
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
		// 输出机器的IP地址.
			printf("Address: %s\n", inet_ntoa(sa.sin_addr)); // 显示地址串
		}
	}while(strcmp(hostname, "q") && strcmp(hostname, "Q"));
//////////////////
// 终止 Windows sockets API
//
	
	WSACleanup();
	return 0;
}
/*已知集合S={‘A’，’B’，’C’}，输入数字n，要求输出所有满足条件的字符串：长度为n，字符串的每个字符都是集合S的元素*/
char S[3] = {'A', 'B', 'C'};
void DFS(int n, int i)
{
	printf("%c", S[i]);
	if(n > 0)		//当深度等于0时不再递归，开始返回
	{
		for(int index = 0; index < 3; ++index)
		{
			DFS(n - 1, index);	//每进入一次递归深度减一
		}
	}
}
//在主函数中调用三次DFS，假设n=5长度为5的所有字符串输出
for(int i = 0; i < 3; ++i)
	DFS(5, i);

  search(int deep, int i)
If deep > 0
  Print  Si
  For index 1 to 3
    search(deep-1, index);