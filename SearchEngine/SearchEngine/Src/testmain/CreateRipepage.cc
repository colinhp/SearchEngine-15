#include "../Inc/PreRipePage.h"
#include "../Inc/Conf.h"

int main()
{
	guoshubo::Conf myconf("/home/fiona/PROJECT@WANGDAO/c++/SearchEngine/Conf/server.conf");
	guoshubo::PreRipePage myripe(myconf);
	myripe.createLibs();
}
