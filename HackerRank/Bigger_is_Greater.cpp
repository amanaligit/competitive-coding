#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w)
{
    char k = 0;
    for (size_t i = 0; i < w.size(); i++)
    {
        if (w[i] > w[k])
            k = i;
    }

    for (int i = w.size() - 2; i >= 0; i--)
    {
        char gi = k;
        bool found = 0;
        for (size_t j = i + 1; j < w.size(); j++)
        {
            if (w[j] > w[i] && w[j] <= w[gi])
            {
                found = 1;
                gi = j;
            }
        }
        if (found)
        {
            swap(w[gi], w[i]);
            sort(w.begin() + i + 1, w.end());
            return w;
        }
    }
    return "no answer";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++)
    {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
