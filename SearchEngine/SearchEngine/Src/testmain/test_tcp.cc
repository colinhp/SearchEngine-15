#include "../Inc/TcpConnection.h"
#include "../Inc/InetAddress.h"
#include "../Inc/Socket.h"
#include "../Inc/Conf.h"
#include <iostream>
#include <string>



int main()
{
	guoshubo::Conf myconf("/home/fiona/PROJECT@WANGDAO/c++/SearchEngine/Conf/server.conf");
	const char *pIp = myconf.getIp().c_str();
	unsigned short port = myconf.getPort();

	guoshubo::InetAddress myaddr(pIp, port);
	guoshubo::Socket mysocket;
	mysocket.ready(myaddr, 10);	
	int peerfd = mysocket.accept();
	
	guoshubo::TcpConnection myconn(peerfd);
	std::cout << myconn.toString() << "已连接" << std::endl;
	myconn.sendmsg("welcome to server");
	while(1)
	{
		std::string recvstr = myconn.recvmsg();
		std::cout << "已接受：" << recvstr << std::endl;
		std::string sendstr =  recvstr;
		myconn.sendmsg(sendstr);
	}	
}
