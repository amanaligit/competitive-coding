#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#if defined(__unix__) || defined(__APPLE__)

#include <sys/resource.h>
#endif


using namespace std;




using std::map;
using std::vector;
using std::string;
using namespace std;

typedef map<char, int> edges;
typedef vector<edges> trie;
int const Letters =    4;
int const NA      =   -1;

trie build_trie(vector<string> & patterns) {
	
  trie t(500001);
  int count = 0;
  for (size_t i = 0; i < patterns.size(); i++)
  {
    int k = 0;
    for (size_t j = 0; j < patterns[i].size(); j++)
    {
      edges::iterator itr = (t[k]).find(patterns[i][j]);
      if(itr != t[k].end())
      {
        k = (*itr).second;
      }
      else
      {
        t[k].insert(make_pair(patterns[i][j], ++count));
        k = count;
      }

      
    }
    
  }
  
  return t;
}



vector <int> result;

int find(trie &t, string &text, int text_i, int tri_i)
{
	int found = 0;
	edges::iterator itr = t[tri_i].begin();
	while(itr!=t[tri_i].end())
	{
		
			if((*itr).first=='$')
			{
				found++;				
			}
			if(text_i<text.size())
			{
				if((*itr).first==text[text_i])
				{
					found+=find(t, text, text_i+1,  (*itr).second);
				}
			}


			
		itr++;
	}
	return found;
	
}

vector <int> solve (string& text, int n, vector <string>& patterns)
{
	
	trie t = build_trie(patterns);
	for (size_t i = 0; i < text.size(); i++)
	{
		int found = find(t, text, i, 0);
		if(found) result.push_back(i);
		
		

	}


	
	

	// write your code here

	return result;
}

int main_with_large_stack_space()
{
	ios_base::sync_with_stdio(0);
	string text;
	cin >> text;

	int n;
	cin >> n;

	vector <string> patterns (n);
	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
		patterns[i].append("$");
	}

	

	vector <int> ans;
	ans = solve (text, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++)
	{
		cout << ans[i];
		if (i + 1 < (int) ans.size ())
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}

	return 0;
}

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}