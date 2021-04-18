#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b )
{
  if(a.first!=b.first) return a.first<b.first;
  else
  {
    return a.second<b.second;
  }
}



vector <int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  unordered_map<int, vector<int> > pos_map;

  for (size_t i = 0; i < points.size(); i++)
  {
    pos_map[points[i]].push_back(i);
  }
  vector <pair<int, int>> pts(2*starts.size());
  for (size_t i = 0; i < starts.size(); i++) {
    pts[i] =make_pair(starts[i], 1);
  }
  for (size_t i = starts.size(); i < 2*starts.size(); i++) {
    pts[i]=make_pair(ends[i-starts.size()], 3);
  }
  for (size_t i = 0; i < points.size(); i++)
  {
    pts.push_back(make_pair(points[i], 2));
  }

  sort(pts.begin(), pts.end(), comp);

  /*cout<<endl;
  for (size_t i = 0; i < pts.size(); i++)
  cout<<pts[i].first<< " "<<pts[i].second<<endl;
  cout<<endl;*/

  int counter = 0;
  for (size_t i = 0; i < pts.size(); i++) {
    if(pts[i].second==1) counter ++;
    else if(pts[i].second==3) counter --;
    else if(pts[i].second==2)
    {
      for (size_t j = 0; j < pos_map[pts[i].first].size(); j++)
      {
        cnt[pos_map[pts[i].first][j]]=counter;
      }
    } //cnt[pos_map[pts[i].first]]=counter;
  }
  return cnt;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
