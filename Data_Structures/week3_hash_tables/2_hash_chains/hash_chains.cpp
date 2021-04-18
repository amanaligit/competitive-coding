#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    vector <list <string>> strmap;
    // store all strings in one vector
    vector<string> elems;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    QueryProcessor(int bucket)
    {
        bucket_count = bucket;
        strmap.resize(bucket+1);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    int hash(string s)
    {
        const int p = 1000000007;
        int x = 1; 
        int m = bucket_count;
        int hash = 0;
        for (size_t i = 0; i < s.length(); i++)
        {
            hash+= (int(s[i])*x)%p;
            x*=263;
        }
        return hash%m;
    
    }

    void processQuery(const Query& query) {
        
        list <string> :: iterator it;

        if(query.type == "check")
        {
            for (it = strmap[query.ind].begin(); it!=strmap[query.ind].end(); it++)
                     {
                         
                         cout<<*it<<" ";

                        
                     }
            cout<<endl;
            

        }
        else
            {
                if (query.type == "find")
                {
                    bool found = 0;
                    int fhash = hash_func(query.s);
                    // cout<<fhash<<endl;
                    // cout<<strmap[fhash].size()<<endl;
                    for (it = strmap[fhash].begin(); it!=strmap[fhash].end(); ++it)
                    {
                        // cout<<"loop"<<endl;
                        if(*it == query.s)
                        {
                            
                            found = 1;
                            cout<<"yes"<<endl;

                        }
                        
                    }
                    if(!found) cout<<"no"<<endl;
                    
                }

                if(query.type == "add")
                {
                    int ahash = hash_func(query.s);
                    // cout<<ahash<<endl;
                    bool found = 0;

                     for (it = strmap[ahash].begin(); it!=strmap[ahash].end(); it++)
                     {
                         if(*it == query.s)
                        {
                            found = 1;
                        }

                        
                     }
                     if(!found) 
                     {
                         strmap[ahash].push_front(query.s);
                        //  cout<<strmap[ahash].size()<<endl;
                        //  cout<<"query pushed"<<endl;
                     }
                     
                }

                if(query.type == "del")
                {
                    int ahash = hash_func(query.s);
                    it = strmap[ahash].begin();
                    bool found = 0;
                    for (; it!=strmap[ahash].end(); it++)
                     {
                         if((*it) == query.s)
                        {
                            found = 1;
                            break;
                        }
                     }
                     if(found) strmap[ahash].erase(it);
                     
                }



                
            }

        // if (query.type == "check") {
        //     // use reverse order, because we append strings to the end
        //     for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
        //         if (hash_func(elems[i]) == query.ind)
        //             std::cout << elems[i] << " ";
        //     std::cout << "\n";
        // } else {
        //     vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
        //     if (query.type == "find")
        //         writeSearchResult(it != elems.end());
        //     else if (query.type == "add") {
        //         if (it == elems.end())
        //             elems.push_back(query.s);
        //     } else if (query.type == "del") {
        //         if (it != elems.end())
        //             elems.erase(it);
        //     }
        // }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
