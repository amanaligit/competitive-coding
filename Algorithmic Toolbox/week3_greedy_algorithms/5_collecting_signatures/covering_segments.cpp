#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

struct Segment
{
  int start, end;
};

bool structsort(Segment a, Segment b)
{
  return a.start<b.start;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  int j = segments[0].end;
  points.push_back(segments[0].end);
  for (size_t i = 1; i < segments.size(); ++i)
  {
    if(segments[i].start>j)
    {
      points.push_back(segments[i].end);
      j=segments[i].end;
    }
    else if(segments[i].end<j)
    {
      points[points.size()-1]=segments[i].end;
      j = segments[i].end;
    }

  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  sort(segments.begin(), segments.end(), structsort );
    //for (size_t i = 0; i < segments.size(); ++i) {
    //std::cout << segments[i].start << " "<< segments[i].end<< endl;
  //}
  vector<int> points = optimal_points(segments);

  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
