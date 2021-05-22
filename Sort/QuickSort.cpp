#include<iostream>
#define N 1000
using namespace std;
int n;
int quick[N];  //输入数组：无序
//序列划分
int Partition(int left, int right)
{
    int i = left;
    int j = right + 1;
    do{
        do{
            i++;
        }while(quick[i] < quick[left]);
        do{
            j--;
        }while(quick[j] > quick[left]);
        if(i < j)
            swap(quick[i], quick[j]);  //交换i和j所指向的元素
    }while(i < j);
    swap(quick[left], quick[j]);
    for(int m = 0; m < n; m++)
        cout << quick[m] << " ";
    cout << endl;
    return j;
}
void QuickSort(int left, int right)
{
    if(left < right)
    {
        int part = Partition(left, right);
        QuickSort(left, part - 1);  //对左子序列进行快速排序
        QuickSort(part + 1, right);  //对右子序列进行快速排序
    }
}
int main()
{
    cout << "Please input the number of array" << endl;
    cin >> n;
    cout << "Please input the array" << endl;
    for(int i = 0; i < n; i++)
        cin >> quick[i];
    QuickSort(0, n - 1);
    cout << "The result is " << endl;
    for(int i = 0; i < n; i++)
        cout << quick[i] << " ";
    return 0;
}
