#include<iostream>
#define N 1000
using namespace std;
int n;
int merge[N];  //输入数组：无序
//将两个无序序列合并为一个有序序列
void Merge(int left, int right, int mid)
{
    int tmp [right - left + 1] = {0};
    int i = left;
    int j = mid + 1;
    int k = 0;
    while((i <= mid) && (j <= right))
    {
        if(merge[i] < merge[j])
        {
            tmp[k] = merge[i];
            k++;
            i++;
        }
        else
        {
            tmp[k] = merge[j];
            k++;
            j++;
        }
    }
    //其中一个序列为空时，将剩余元素依次存入tmp数组
    while(i <= mid)
    {
        tmp[k] = merge[i];
        k++;
        i++;
    }
    while(j <= right)
    {
        tmp[k] = merge[j];
        k++;
        j++;
    }
    //合并后的有序序列依次重新复制到原数组中
    for(i = 0, k = left; k <= right; i++, k++)
        merge[k] = tmp[i];
    //每步合并过程展示
    for(int m = 0; m < n; m++)
        cout << merge[m] << " ";
    cout << endl;
}
void MergeSort(int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        //递归操作
        MergeSort(left, mid);
        MergeSort(mid + 1, right);
        Merge(left, right, mid);
    }
}
int main()
{   
    cout << "Please input the number of array" << endl;
    cin >> n;
    cout << "Please input the array" << endl;
    for(int i = 0; i < n; i++)
        cin >> merge[i];
    MergeSort(0, n - 1);
    cout << "The result is " << endl;
    for(int i = 0; i < n; i++)
        cout << merge[i] << " ";
    return 0;
}
