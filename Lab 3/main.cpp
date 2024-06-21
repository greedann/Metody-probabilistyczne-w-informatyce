#include <iostream>
#include <ctime>
#include <chrono>

extern "C" int func(double);

using namespace std;

int main()
{
    // 1
    srand(time(nullptr));
    int results[10] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10000; i++)
    {
        double random = ((double)rand() / RAND_MAX);
        int x = 100 * random + 50;
        int x1 = func(random);
        int index = min(9, (int)(x1 - 50) / 10);

        results[index]++;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " : " << results[i] << "\n";
        sum += results[i];
    }
    cout << endl;

    // 2
    double possible[4] = {0.05, 0.2, 0.45, 1};
    int results2[4] = {
        0, 0, 0, 0};
    for (int i = 0; i < 10000; i++)
    {
        double random = ((double)rand() / RAND_MAX);
        for (int i = 0; i < 4; i++)
        {
            if (random <= possible[i])
            {
                results2[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << " : " << results2[i] << "\n";
        sum += results2[i];
    }

    return 0;
}
