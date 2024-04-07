#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void test1()
{
    int a = 69069;
    int c = 1;
    int n = 100000;
    int xn = 15;
    unsigned long int m = pow(2, 31);
    vector<int> list;
    list.push_back(xn);

    for (int i = 0; i < n; i++)
    {
        xn = (a * xn + c) % m;
        list.push_back(xn);
    }

    int part = (m - 1) / 10;
    int iter = part;
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
        arr[i] = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (list.at(j) <= iter && list.at(j) > iter - part)
            {
                arr[i]++;
            }
        }
        iter += part;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void test2()
{
    int n = 100000;
    int p = 7;
    int q = 3;
    unsigned long int m = pow(2, 31);

    vector<int> arr = {1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        int iter = 7;
        while (iter != 31)
        {
            arr.at(iter) = arr.at(iter - p) ^ arr.at(iter - q);
            iter++;
        }
        unsigned long int number = 0;
        for (int j = 0; j < 31; j++)
        {
            number = (number << 1) | arr[j];
        }
        list.push_back(number);

        vector<int> tmp;
        for (int j = 24; j < 31; j++)
            tmp.push_back(arr.at(j));
        for (int j = 0; j < 31; j++)
            arr.at(j) = 0;
        for (int j = 0; j < 7; j++)
            arr.at(j) = tmp.at(j);
    }

    int part = (m - 1) / 10;
    int iter = part;
    int *out = new int[10];
    for (int i = 0; i < 10; i++)
        out[i] = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (list.at(j) <= iter && list.at(j) > iter - part)
            {
                out[i]++;
            }
        }
        iter += part;
    }
    for (int i = 0; i < 10; i++)
        cout << out[i] << ' ';
    cout << endl;
}

int main(int, char **)
{
    test2();
    return 0;
}
