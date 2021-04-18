#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define Matrix(mat,m,n) vector<vector<int>> mat( n , vector<int> (m, 0));

using std::vector;
using std::cin;
using std::cout;
using namespace std;

  
// A class for Min Heap 
class MinHeap 
{ 
    pair <long long, int> *harr; // pointer to array of elements in heap 
     // Current number of elements in min heap 
public: 
    int capacity; // maximum possible size of min heap 
    int heap_size;
    // Constructor 
    MinHeap(int capacity); 
    
  
    // to heapify a subtree with the root at given index 
    void MinHeapify(int ); 
  
    int parent(int i) { return (i-1)/2; } 
  
    // to get index of left child of node at index i 
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int right(int i) { return (2*i + 2); } 
  
    // to extract the root which is the minimum element 
    pair<long long, int> extractMin(); 
  
    // Decreases key value of key at index i to new_val 
    void decreaseKey(int i, long long new_val); 
  
    // Returns the minimum key (key at root) from min heap 
    pair <long long, int> getMin() { return harr[0]; } 
  
    // Deletes a key stored at index i 
    void deleteKey(int i); 
  
    // Inserts a new key 'k' 
    void insertKey(long long k, int w); 
}; 
  
// Constructor: Builds a heap from a given array a[] of given size 
MinHeap::MinHeap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new pair<long long, int> [cap]; 
} 
  
// Inserts a new key 'k' 
void MinHeap::insertKey(long long k, int w) 
{ 
    if (heap_size == capacity) 
    { 
        cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    harr[i].first = k;
    harr[i].second = w; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && (harr[parent(i)].first > harr[i].first || (harr[parent(i)].first == harr[i].first&&harr[parent(i)].second > harr[i].second ))) 
    { 
       swap(harr[i], harr[parent(i)]); 
       i = parent(i); 
    } 
} 
  
// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, long long new_val) 
{ 
    harr[i] = make_pair(i, new_val); 
    while (i != 0 && (harr[parent(i)].first > harr[i].first || (harr[parent(i)].first == harr[i].first&&harr[parent(i)].second > harr[i].second ))) 
    { 
       swap(harr[i], harr[parent(i)]); 
       i = parent(i); 
    } 
} 
  
// Method to remove minimum element (or root) from min heap 
pair<long long, int> MinHeap::extractMin() 
{ 
    if (heap_size <= 0) 
        return make_pair(0, INT_MAX); 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    pair <long long, int> root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
} 
  
  
// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
} 
  
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && (harr[l].first < harr[i].first || (harr[l].first == harr[i].first && harr[l].second < harr[i].second ))) 
        smallest = l; 
    if (r < heap_size && (harr[r].first < harr[smallest].first || (harr[r].first == harr[smallest].first && harr[r].second < harr[smallest].second ))) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(harr[i], harr[smallest]); 
        MinHeapify(smallest); 
    } 
} 
  
// A utility function to swap two elements 
// void swap(long long *x, long long *y) 
// { 
//     long long temp = *x; 
//     *x = *y; 
//     *y = temp; 
// } 


class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    queue <int> free;
    for (size_t i = 0; i < num_workers_; i++)
    {
      free.push(i);
    }
    
    MinHeap workers(num_workers_);
    long long time = 0;
    int i = 0 ;
    while(i!=jobs_.size())
    {
      while(workers.getMin().first==time&&workers.heap_size>0)
      {
        // cout<<"size = "<<workers.heap_size<<endl;
        pair <long long, int> temp =  workers.extractMin();
        free.push(temp.second);
      }
      while(workers.heap_size < num_workers_)
      {
        workers.insertKey(jobs_[i]+time, free.front());
        assigned_workers_[i] = free.front();
        start_times_[i] = time;
        free.pop();

        // cout<<time<<"ok"<<endl;
        i++;
        if(i==jobs_.size()) break;
      }
      // cout<<"top= "<<workers.getMin().first<<workers.getMin().second<<endl;
      time =  workers.getMin().first;
      // cout<<"min = "<<time<<endl;

    }
    
    
    // for (int i = 0; i < jobs_.size(); ++i) {
    //   int duration = jobs_[i];
    //   int next_worker = 0;
    //   for (int j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  int m = 3;
  int n = 4;
  job_queue.Solve();
  return 0;
}
