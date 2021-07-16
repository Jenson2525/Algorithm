#include<iostream>
#include"Linerlist.h"
using namespace std;
//类arraylist，线性表的数组实现
template<class T>
class arraylist: public linerlist<T>
{
    protected:
        T* element;  //存储线性表元素的一维数组
        int arraylength;  //一维数组的容量
        int listsize;  //线性表的元素个数
    public:
        //构造函数、复制构造函数和析构函数
        arraylist(int capacity = 10);
        arraylist(const arraylist<T>&);
        ~arraylist()
        {
            delete [] element;
        }

        //ADT方法
        bool empty() const
        {
            return listsize == 0;
        }
        int size() const
        {
            return listsize;
        }
        T& get(int theIndex) const;
        int indexOf(const T& theElement) const;
        void erase(int theIndex);
        void insert(int the Index, const T& the Element);
        void output(ostream& out) const;

        //其他方法
        int capacity() const
        {
            return arraylength;
        }
};