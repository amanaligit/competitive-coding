#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>



using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

using namespace std;

typedef map<char, int> edges;
typedef map<pair<int, int>, int> s_edge;
typedef vector<s_edge> suffix_trie;
typedef vector<edges> trie;
int const Letters =    4;
int const NA      =   -1;

// int next = -1;

  string text;

trie build_trie(string text) 
{
  trie t(5000000);
  int count = 0;

    for (size_t i = 0; i < text.size(); i++)
    {
      string sub = text.substr(i, text.length()-i);
      if(sub!="$") sub.append("$");
        int k = 0;
        for (size_t j = 0; j < sub.size(); j++)
        {
          edges::iterator itr = (t[k]).find(sub[j]);
          if(itr != t[k].end())
          {
            k = (*itr).second;
          }
          else
          {
            if(sub[j]=='$')
            {
              t[k].insert(make_pair(sub[j], i));
            }
            else
            {
              t[k].insert(make_pair(sub[j], ++count));
              k = count;
            }
            
           
          }

          
        }
    }

  // for (size_t i = 0; i < patterns.size(); i++)
  // {
  //   int k = 0;
  //   for (size_t j = 0; j < patterns[i].size(); j++)
  //   {
  //     edges::iterator itr = (t[k]).find(patterns[i][j]);
  //     if(itr != t[k].end())
  //     {
  //       k = (*itr).second;
  //     }
  //     else
  //     {
  //       t[k].insert(make_pair(patterns[i][j], ++count));
  //       k = count;
  //     }

      
  //   }
    
  // }
  
  return t;
}

int build_suf(trie &t, suffix_trie &s, int t_index, int s_index,  int l, int &next)
{
  edges e = t[t_index];
  // int s_index = next;
  int length = 1;
  if(t_index==0) length = 0;
  while(e.size()==1&&e.begin()->first!='$')
  { 
    e = t[e.begin()->second];
    length++;
  }

  if(e.begin()->first=='$'&&e.size()==1)
  {
    length++;
    int start = e.begin()->second + l;
    s[s_index].insert(make_pair(make_pair(start, length), e.begin()->second));
    return e.begin()->second;
  }

  else
  {
    next++;
    int cur_index = next;
    edges::iterator itr = e.begin();
    int min_ind = INT_MAX;
    while(itr!=e.end())
    {
      if(itr->first=='$') 
      {
        s[next].insert(make_pair(make_pair(text.length()-1, 1), itr->second));
      }
      else
      {
              int temp = build_suf(t, s, itr->second, cur_index, l + length, next );
      min_ind = min(min_ind, temp);
      }
      

      itr++;
    }
    int start = min_ind + l;
    if(s_index>=0)
    s[s_index].insert(make_pair(make_pair(start, length), next));
    return min_ind;

    
  }




}
// Build a suffix tree of the string text and return a vector
// with all of the labels of its edges (the corresponding 
// substrings of the text) in any order.
vector <string> ComputeSuffixTreeEdges(const string& text) {
  trie t = build_trie(text);
  vector <string> ans;
  // cout<<"built trie"<<endl;
  suffix_trie suf(5000000);
    int next = -1;
  build_suf(t, suf, 0, -1, 0, next );

  // cout<<"built suf"<<endl;
  for (size_t i = 0; i < suf.size(); ++i) {
  for (const auto & j : suf[i]) {
    // std::cout << i << "->" << j.second << ":" << j.first << "\n";
    for (size_t k = j.first.first; k < j.first.first+j.first.second ; k++)
    {
      cout<<text[k];
    }
    cout<<endl;
    
  }
}

  return ans;

}



int main() {
	ios_base::sync_with_stdio(0);

  cin >> text;
vector <string> edges = ComputeSuffixTreeEdges(text);
  for (int i = 0; i < edges.size(); ++i) {
    cout << edges[i] << endl;
  }
  return 0;
}


