#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

using namespace std;

class Solver {
	string s;
public:	
	vector <long long> hashes;
	int x;
	int p;
	Solver(string s) : s(s) {	
		    p = 1000000007;
    		x = 1;
			pre_hash(s, p, x);

    // cout<<pHash<<endl;
            
	}
		bool ask(int a, int b, int l) {
		
		const long long m1 = 1000000007;
		const long long m2 = 1000000009;
		long long h_a = hashes[a+l] - pow(x, l)*hashes[a];
		long long h_b = hashes[b+l] - pow(x, l)*hashes[b];
		// cout<<h_a<<" "<<h_b<<endl;
		if((h_a+m1)%m1==((h_b+m1)%m1)&&((h_b+m2)%m2==(h_a+m2)%m2)) return 1;
		return 0;


	}
	void pre_hash(string t, int p, int x)
{
    hashes.resize((t.length())+1);
	hashes[0] = 0;

	long long multiplier = pow(x, t.length()-1);

	for (size_t i = 1; i <= t.length(); i++)
	{
		hashes[i] = (hashes[i-1] + t[i-1]*multiplier+p)%p;
		multiplier/=x;
	}

    
    

}

};


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
