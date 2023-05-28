#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int CB = 0;
vector<bool> sol;
int n;
int p[100];
int w[100];
int w0;

float eval(vector<bool> a, int k)
{
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp += (a[i]) ? w[i] : 0;
	}
	tmp = w0 - tmp;
	float pf = 0;
	int i = n;
	while (tmp > 0 && i >= k) {
		if (w[i] < tmp) {
			pf += p[i];
			tmp -= w[i];
		}
		else {
			pf += (p[i] * tmp)/ w[i];
			tmp = 0;
			break;
		}
	}
	return pf;
}

bool feasible(vector<bool> a)
{
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		tmp += (a[i]) ? w[i] : 0;
	}
	if (tmp <= w0) {
		return true;
	}
	return false;
}

int bnb(vector<bool> item, int cp, int last)
{
	int max = eval(item, last) + 1;
	if (max + cp < CB) {
		//cout << "eeee";
		return 0;
	}
	
	int a = 0;
	for (int i = last + 1; i <= n; i++) {
		item[i] = true;
		if (feasible(item)) {
			int x = cp + p[i];
			int t = bnb(item, x, i);
			if (t + x > CB) {
				// Updating Best n Solution.
				CB = t + x;
				sol = item;
			}
			if (t + p[i] > a) {
				a = t + p[i];
			}
		}
		item[i] = false;
	}
	return a;
}

int main()
{
	vector<bool> item;
	
	cout << "Enter number of items: ";
	cin >> n;
	
	item.push_back(false); // Indexing is from 1. so item 0 is always neglected.
	
	
	
	cout << "Enter Weights: ";
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		item.push_back(false);
	}
	sol = item;

	cout << "Weight of Knapsack: ";
	cin >> w0;

	cout << "Enter Profits: ";
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (w[j] * p[i] > w[i] * p[j]) {
				int k = w[i];
				w[i] = w[j];
				w[j] = k;
				k = p[i];
				p[i] = p[j];
				p[j] = k;
			}
		}
	}
	
	cout << "\nW: ";
	for (int i = 1; i <= n; i++) {
		cout << w[i] << " ";
	}
	cout << endl << "P: ";
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
	cout << endl;


	int x = bnb(item, 0, 0);

	cout << "You should take: ";
	for (int i = 1; i <= n; i++) {
		if (sol[i]) {
			cout << w[i] << " ";
		}
	}
	cout << endl << "Net Profit: " << x << endl;

	return 0;
}