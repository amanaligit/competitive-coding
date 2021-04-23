#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);

long long getSum(vector<int> &BITree, int index)
{
    long long sum = 0; // Iniialize result
    index = index + 1;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(vector<int> &BITree, int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
        BITree[index] += val;
        index += index & (-index);
    }
}

vector<int> constructBITree(vector<int> &arr, int n)
{
    vector<int> BITree(n + 1, 0);
    for (int i = 0; i < n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

// Complete the insertionSort function below.
long long insertionSort(vector<int> arr)
{
    unordered_map<int, int> mp;
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());
    int last = temp[0];
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin() + 1;
    }
    vector<int> BITree(arr.size() + 2, 0);
    long long ans = 0;
    long long c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans += c - getSum(BITree, arr[i]);
        c++;
        updateBIT(BITree, arr.size() + 1, arr[i], 1);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        long long result = insertionSort(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
