#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__


namespace guoshubo
{

class Noncopyable
{
public:
	Noncopyable()
	{}

private:
	Noncopyable(const Noncopyable &rhs)	{}
	Noncopyable &operator=(const Noncopyable &rhs) {}
};

}//end of namespace

#endif
