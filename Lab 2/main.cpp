#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void test1()
{
    int a = 69069;
    int c = 1;
    int n = 100000,all=0;
    unsigned int xn = 15;
    int m = pow(2, 31);
    vector<int> list;
    list.push_back(xn);

    for (int i = 0; i < n; i++)
    {
        xn = (a * xn + c) % m;
        list.push_back(xn);
    }

    int part = (m - 1) / 10;
    int iter = part;
    int* arr = new int[10];
    for (int i = 0; i < 10; i++)
        arr[i] = 0;

    for (int i = 0; i < n; i++) {
        int part_num = ceil(list[i] / part);
        arr[part_num]++;
        all++;
    }
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl << all << endl;
}

void test2()
{
    int n = 100000;
    int p = 7;
    int q = 3;

    vector<int> arr = { 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    vector<int> list;
    for (int i = 0; i < n; i++)
    {
        int iter = p;
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
    unsigned long M = pow(2, 31);
    unsigned long part = M / 10;
    int* out = new int[10];
    int all = 0;
    for (int i = 0; i < 10; i++)
        out[i] = 0;

    for (int i = 0; i < n; i++) {
        int part_num = ceil(list[i] / part);
        out[part_num]++;
        all++;
    }
    for (int i = 0; i < 10; i++)
        cout << out[i] << ' ';
    cout << endl << all << endl;
}

int main(int, char**)
{
    srand(time(NULL));
    test1();
    test2();
    return 0;
}
