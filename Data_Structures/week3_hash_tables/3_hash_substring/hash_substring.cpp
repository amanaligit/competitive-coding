#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
typedef unsigned long long ull;

long long hash_func(const string& s, int x)
    {
        static const size_t multiplier = x;
        static const size_t prime = 1000000007;
        long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash ;
    }

vector <long long> pre_hash(string t, int l, int p, int x)
{
    vector <long long> hashes((t.length())-l+1);
    hashes[t.length()-l] = hash_func(t.substr(t.length()-l), x);
    long long y = 1;
    for (size_t i = 1; i <= l; i++)
    {
        y = (y*x)%p;
    }
    for (int i =t.length()-l - 1; i >= 0; i--)
    {
        hashes[i] = ((x*hashes[i+1] + t[i] - y*t[i+l])+p)%p; 
    }
    return hashes;
    
    


}
struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    int p = 1000000007;
    int x = 1;
    long long pHash = hash_func(input.pattern, x);
    // cout<<pHash<<endl;
            std::vector<int> ans;
    vector <long long> hashes = pre_hash(input.text, input.pattern.length(), p, x);
    for (int i = 0; i <= input.text.length() - input.pattern.length(); i++)
    {
        // cout<<hashes[i]<<endl;
        if(pHash!=hashes[i])
        {
            continue;
        }
        // cout<<input.text.substr(i, i + input.pattern.length())<<endl;
        if(input.pattern == input.text.substr(i, input.pattern.length())) ans.push_back(i);
        
    }
    return ans;
    



    // const string& s = input.pattern, t = input.text;
    // std::vector<int> ans;
    // for (size_t i = 0; i + s.size() <= t.size(); ++i)
    //     if (t.substr(i, s.size()) == s)
    //         ans.push_back(i);
    // return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
