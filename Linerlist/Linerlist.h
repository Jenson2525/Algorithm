#ifdef LINERLIST_H
#define LINSELIST_H
#include<iostream>
using namespace std;
//抽象类linerlist
template<class T>
class linerlist
{
    public:
        virtual ~linerlist();  //析构函数
        virtual bool empty() const = 0;  //返回true，当且仅当线性表为空
        virtual int size() const = 0;  //返回线性表的元素个数
        virtual T& get(int theIndex) const = 0;  //返回索引为theIndex的元素
        virtual int indexOf(const &T theElement) const = 0;  // 返回元素theElement第一次出现的索引
        virtual void erasee(int theIndex) = 0;  //删除索引为theIndex的元素
        virtual void insert(int theIndex, const T& theElement) = 0;  //插入元素
        virtual void output(ostream& out) const = 0;  //把线性表插入输出流out
};
#endif
