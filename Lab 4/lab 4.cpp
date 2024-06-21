#include <iostream>
#include <cstdlib>

using namespace std;

float fxy[4][4] = {{0.1, 0.0, 0.0, 0.4},
                   {0.2, 0.0, 0, 0},
                   {0, 0.1, 0, 0.1},
                   {0, 0, 0.1, 0}};

pair<int, int> random_vector(float *sum_row)
{
    float row = (float)rand() / (float)RAND_MAX;
    for (int i = 0; i < 4; i++)
    {
        row -= sum_row[i];
        if (row < 0)
        {
            float coll = ((float)rand() / (float)RAND_MAX) * sum_row[i];
            for (int j = 0; j < 4; j++)
            {
                coll -= fxy[i][j];
                if (coll < 0)
                {
                    return make_pair(i, j);
                }
            }
        }
    }

    return make_pair(-1, -1);
}

int main()
{
    srand(time(NULL));

    int out[4][4] = {{0}, {0}, {0}, {0}};
    float sum_row[4], sum;

    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum += fxy[i][j];
        }
        sum_row[i] = sum;
    }
    for (int i = 0; i < 100000; i++)
    {
        pair<int, int> p = random_vector(sum_row);

        out[p.first][p.second]++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("|%5d| ", out[i][j]);
        }
        cout << endl;
    }

    return 0;
}
