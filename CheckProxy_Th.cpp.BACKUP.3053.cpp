#include "CheckProxy_Th.h"
#include "externData.h"

void CheckProxy_Th::doEmitChangeRedIRCData(QString str)
{
	emit chPTh->changeRedIRCData(str);
};
void CheckProxy_Th::doEmitChangeGreenIRCData(QString str)
{
	emit chPTh->changeGreenIRCData(str);
};
void CheckProxy_Th::doEmitChangeYellowIRCData(QString str)
{
	emit chPTh->changeYellowIRCData(str);
};
void CheckProxy_Th::doEmitChangeRawIRCDataInc(QString str)
{
	emit chPTh->changeRawIRCDataInc(str);
};
void CheckProxy_Th::doEmitChangeRawIRCDataOut(QString str)
{
	emit chPTh->changeRawIRCDataOut(str);
};

void CheckProxyLogic()
{
	QString str1 = ui->ircProxyPort->text();
	QString str2 = ui->ircProxy->text();
	strcpy(ircProxy, str2.toUtf8().data());
	strcpy(ircProxyPort, str1.toUtf8().data());

	int err, yes = 1;
	SOCKET pSock;
	char precvBuff[2048] = {0};
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(ircProxyPort));

	HOSTENT *host;  

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	if(inet_addr(ircProxy) != INADDR_NONE) addr.sin_addr.S_un.S_addr = inet_addr(ircProxy);  
	else if(host = gethostbyname (ircProxy)) ((unsigned long*) &addr.sin_addr)[0] = ((unsigned long**)host->h_addr_list)[0][0];  
#else
	if(inet_addr(ircProxy) != INADDR_NONE) addr.sin_addr.s_addr = inet_addr(ircProxy);  
	else if(host=gethostbyname (ircProxy)) ((unsigned long*) &addr.sin_addr)[0] = ((unsigned long**)host->h_addr_list)[0][0];
#endif
	pSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if(pSock == INVALID_SOCKET) 
	{
<<<<<<< HEAD

		chPTh->doEmitChangeRedIRCData("CheckProxy: -INVALID SOCKET.");

=======
#pragma region QTGUI_Area
		chPTh->doEmitChangeRedIRCData("CheckProxy: -INVALID SOCKET.");
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
	}
	else
	{
		if(connect(pSock, (sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR)
		{
<<<<<<< HEAD

		chPTh->doEmitChangeRawIRCDataOut(QString::fromLocal8Bit("CONNECT 2ip.ru HTTP/1.1\r\n\r\n"));

=======
#pragma region QTGUI_Area
		chPTh->doEmitChangeRawIRCDataOut(QString::fromLocal8Bit("CONNECT 2ip.ru HTTP/1.1\r\n\r\n"));
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
			send(pSock, "CONNECT 2ip.ru HTTP/1.1\r\n\r\n", strlen("CONNECT 2ip.ru HTTP/1.1\r\n\r\n"), 0);

			while(recv(pSock, precvBuff, sizeof(precvBuff), 0) > 0) 
			{
<<<<<<< HEAD

		chPTh->doEmitChangeRawIRCDataInc(QString::fromLocal8Bit(precvBuff));

=======
#pragma region QTGUI_Area
		chPTh->doEmitChangeRawIRCDataInc(QString::fromLocal8Bit(precvBuff));
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
				if( (strstr(precvBuff, "HTTP/1.1 200 OK") || strstr(precvBuff, "200 OK")
					|| strstr(precvBuff, "OK 200") || strstr(precvBuff, "200 Connection")
					)
					&& (strlen(precvBuff) < 150) 
					&& strstr(precvBuff, "404 File Not Found") == NULL
					&& 
					(
					strstr(precvBuff, "Invalid Request") == NULL
					|| strstr(precvBuff, "Invalid request") == NULL || strstr(precvBuff, "invalid request") == NULL
					|| strstr(precvBuff, "400 Bad Request") == NULL || strstr(precvBuff, " 400 bad request") == NULL
					) 
					)
				{
					
<<<<<<< HEAD

		chPTh->doEmitChangeRawIRCDataOut(QString::fromLocal8Bit("GET / HTTP/1.1\r\nHost: 2ip.ru\r\n\r\n"));

=======
#pragma region QTGUI_Area
		chPTh->doEmitChangeRawIRCDataOut(QString::fromLocal8Bit("GET / HTTP/1.1\r\nHost: 2ip.ru\r\n\r\n"));
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
					send(pSock, "GET / HTTP/1.1\r\nHost: 2ip.ru\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: 2ip.ru\r\n\r\n"), 0);
					ZeroMemory(precvBuff, sizeof(precvBuff));
					while(recv(pSock, precvBuff, sizeof(precvBuff), 0) > 0) 
					{
						
<<<<<<< HEAD

		chPTh->doEmitChangeRawIRCDataInc(QString::fromLocal8Bit(precvBuff));

=======
#pragma region QTGUI_Area
		chPTh->doEmitChangeRawIRCDataInc(QString::fromLocal8Bit(precvBuff));
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
						if(strstr(precvBuff, "404 File Not Found") == NULL && strstr(precvBuff, "Invalid Request") == NULL
							&& strstr(precvBuff, "Invalid request") == NULL && strstr(precvBuff, "invalid request") == NULL
							&& strstr(precvBuff, "400 Bad Request") == NULL && strstr(precvBuff, "400 bad request") == NULL
							&& strstr(precvBuff, "404 Not") == NULL && strstr(precvBuff, "404 not") == NULL
							&& strstr(precvBuff, "500 Internal") == NULL && strstr(precvBuff, "500 internal") == NULL
							&& strstr(precvBuff, "401 Unauthorized") == NULL && strstr(precvBuff, "401 unauthorized") == NULL
							&& strstr(precvBuff, "InvalidUrl") == NULL && strstr(precvBuff, "invalidurl") == NULL
							&& strstr(precvBuff, "Invalid Url") == NULL && strstr(precvBuff, "invalid url") == NULL
							&& strstr(precvBuff, "Gateway Timeout") == NULL && strstr(precvBuff, "Gateway timeout") == NULL
							&& strstr(precvBuff, "gateway timeout") == NULL
							)
						{

<<<<<<< HEAD

							chPTh->doEmitChangeGreenIRCData("[OK] Success! Now using " + QString(ircProxy) + ":" + QString(ircProxyPort) + ".");

=======
#pragma region QTGUI_Area
							chPTh->doEmitChangeGreenIRCData("[OK] Success! Now using " + QString(ircProxy) + ":" + QString(ircProxyPort) + ".");
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
							proxyEnabledFlag = 1;

							CSSOCKET(pSock);
							break;
						}
						else
						{
<<<<<<< HEAD

							chPTh->doEmitChangeRedIRCData(QString(ircProxy) + ":" + QString(ircProxyPort) + " - is not CONNECT proxy? Try another one.");

=======
#pragma region QTGUI_Area
							chPTh->doEmitChangeRedIRCData(QString(ircProxy) + ":" + QString(ircProxyPort) + " - is not CONNECT proxy? Try another one.");
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
							proxyEnabledFlag = 0;

							CSSOCKET(pSock);
							break;
						};
					};
					break;
				} 
				else
				{
<<<<<<< HEAD

					chPTh->doEmitChangeRedIRCData(QString(ircProxy) + ":" + QString(ircProxyPort) + " - is not CONNECT proxy? Try another one.");

=======
#pragma region QTGUI_Area
					chPTh->doEmitChangeRedIRCData(QString(ircProxy) + ":" + QString(ircProxyPort) + " - is not CONNECT proxy? Try another one.");
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
					proxyEnabledFlag = 0;

					CSSOCKET(pSock);
					break;
				};
			};
		}
		else
		{
<<<<<<< HEAD

			chPTh->doEmitChangeRedIRCData("Cannot connect to " + QString(ircProxy) + ":" + QString(ircProxyPort) + ".");

=======
#pragma region QTGUI_Area
			chPTh->doEmitChangeRedIRCData("Cannot connect to " + QString(ircProxy) + ":" + QString(ircProxyPort) + ".");
#pragma endregion
>>>>>>> 1f26df077976493c1916f7764c83dc03da1445fa
			proxyEnabledFlag = 0;			
		};
	};	
};

void CheckProxy_Th::run()
{
	CheckProxyLogic();
};