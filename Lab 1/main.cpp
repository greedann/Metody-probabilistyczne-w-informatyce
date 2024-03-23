#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

class TreeNode
{
public:
    int val;
    vector<TreeNode *> children;

    TreeNode(int val)
    {
        this->val = val;
    }
};

class Tree
{
public:
    TreeNode root;

    Tree() : root(-1)
    {
    }

    void fill1(vector<int> values)
    {
        fill_tree(&root, values, values.size());
    }

    void fill2(vector<int> values)
    {
        fill_tree(&root, values, values.size(), false);
    }

    vector<vector<int>> get_pathes(int depth)
    {
        vector<int> path;
        for (auto child : root.children)
        {
            get_pathes(depth - 1, child, path);
        }
        return paths;
    }

private:
    vector<vector<int>> paths;
    void get_pathes(int depth, TreeNode *node, vector<int> path)
    {
        if (depth == 0)
        {
            path.push_back(node->val);
            paths.push_back(path);
            return;
        }

        vector<int> new_path = path;
        new_path.push_back(node->val);
        for (auto child : node->children)
        {
            get_pathes(depth - 1, child, new_path);
        }
    }

    void fill_tree(TreeNode *node, vector<int> values, int depth, bool without_repetition = true, int min_val = -1)
    {
        if (depth == 0)
            return;
        depth--;
        for (int i = 0; i < values.size(); i++)
        {
            if (!without_repetition and values[i] < min_val)
                continue;
            TreeNode *child = new TreeNode(values[i]);
            node->children.push_back(child);

            vector<int> new_values = values;
            if (without_repetition)
                new_values.erase(new_values.begin() + i);
            fill_tree(child, new_values, depth, without_repetition, values[i]);
        }
    }
};

class City
{
public:
    string name;
    int population;
    float latitude, longitude;

    City()
    {
    }

    City(string name, int population, float latitude, float longitude)
    {
        this->name = name;
        this->population = population;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    string to_string()
    {
        return name + " " + std::to_string(population) + " " + std::to_string(latitude) + " " + std::to_string(longitude);
    }

    float distance(City city)
    {
        float radius = 6371.01;
        float lat1 = this->latitude * M_PI / 180;
        float long1 = this->longitude * M_PI / 180;
        float lat2 = city.latitude * M_PI / 180;
        float long2 = city.longitude * M_PI / 180;
        return radius * (M_PI / 2 - asin(sin(lat2) * sin(lat1) + cos(long2 - long1) * cos(lat2) * cos(lat1)));
    }
};

void find_min_path(vector<City> cities, vector<int> values, int m)
{
    Tree tree;
    tree.fill1(values);
    vector<vector<int>> paths;
    paths = tree.get_pathes(m);

    float min_distance = INFINITY;
    vector<int> min_path;
    for (auto path : paths)
    {
        float distance = 0;
        for (int i = 0; i < path.size() - 1; i++)
        {
            distance += cities[path[i] - 1].distance(cities[path[i + 1] - 1]);
        }
        if (distance < min_distance)
        {
            min_distance = distance;
            min_path = path;
        }
    }
    cout << "Distance: " << min_distance << endl;
    for (auto city : min_path)
    {
        cout << city << " ";
        cout << cities[city - 1].to_string() << endl;
    }
}

void scan_cities(vector<City> &cities)
{
    string line;
    ifstream myfile("../cities.txt");
    string name;
    int population;
    float latitude, longitude;
    if (myfile.is_open())
    {
        while (myfile >> line)
        {
            myfile >> name >> population >> latitude >> longitude;
            cities.push_back(City(name, population, latitude, longitude));
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";
}

void find_max_avg_population(vector<City> cities, vector<int> values, int m)
{
    Tree tree;
    tree.fill1(values);
    vector<vector<int>> paths;
    paths = tree.get_pathes(m);

    float max_avg_population = 0;
    vector<int> max_path;
    for (auto path : paths)
    {
        float avg_population = 0;
        for (int i = 0; i < path.size(); i++)
        {
            avg_population += cities[path[i] - 1].population;
        }
        avg_population /= path.size();
        if (avg_population > max_avg_population)
        {
            max_avg_population = avg_population;
            max_path = path;
        }
    }
    cout << "Average population: " << max_avg_population << endl;
    for (auto city : max_path)
    {
        cout << city << " ";
        cout << cities[city - 1].to_string() << endl;
    }
}

int main()
{

    int m, n;
    cout << "Enter m and n: ";
    cin >> m >> n;
    vector<int> values(n);

    for (int i = 0; i < n; i++)
    {
        values[i] = i + 1;
    }

    // 1
    Tree tree;
    tree.fill1(values);
    vector<vector<int>> paths;
    paths = tree.get_pathes(m);
    for (int i = 0; i < paths.size(); i++)
    {
        printf("%3d: ", i + 1);
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;

    // 2
    tree.fill2(values);
    paths = tree.get_pathes(m);
    for (int i = 0; i < paths.size(); i++)
    {
        printf("%3d: ", i + 1);
        for (int j = 0; j < paths[i].size(); j++)
        {
            cout << paths[i][j] << " ";
        }
        cout << endl;
    }

    vector<City> cities;

    scan_cities(cities);

    // 1d
    find_min_path(cities, values, m);
    cout << "------------------------------------" << endl;

    // 2d
    find_max_avg_population(cities, values, m);

    return 0;
}
