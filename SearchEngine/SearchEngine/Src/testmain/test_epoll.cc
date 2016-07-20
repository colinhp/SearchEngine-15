#include "../Inc/TcpConnection.h"
#include "../Inc/EpollPoller.h"
#include "../Inc/InetAddress.h"
#include "../Inc/Socket.h"
#include "../Inc/Conf.h"
#include <iostream>
#include <string>


void myConnection(guoshubo::TcpConnection *pTcpConn)
{
	std::cout << pTcpConn->toString() << "已连接" << std::endl;
	std::string connmsg = "welcome to server";	
	pTcpConn->sendmsg(connmsg);
}


void myMessage(guoshubo::TcpConnection *pTcpConn)
{
	std::string recvstr = pTcpConn->recvmsg();
	std::cout << "已接收：" << recvstr << std::endl;
	pTcpConn->sendmsg(recvstr);
}


void myClose(guoshubo::TcpConnection *pTcpConn)
{
	std::cout << pTcpConn->toString() << "已断开" << std::endl;
}


int main()
{
	guoshubo::Conf myconf("/home/fiona/PROJECT@WANGDAO/c++/SearchEngine/Conf/server.conf");
	const char *pIp = myconf.getIp().c_str();
	unsigned short port = myconf.getPort();

	guoshubo::InetAddress myaddr(pIp, port);
	guoshubo::Socket mysocket;
	mysocket.ready(myaddr, 10);	
	
	guoshubo::EpollPoller myepoll(mysocket.getfd());
	myepoll.setConnectionCb(myConnection);
	myepoll.setMessageCb(myMessage);
	myepoll.setCloseCb(myClose);

	myepoll.loop();
}
