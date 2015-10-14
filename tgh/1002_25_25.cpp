#include <iostream>
#include <vector>
using namespace std;

struct Poly
{
	int index;
	double coeff;
};

int main()
{
	int k;
	Poly item;
	vector<Poly> poly1, poly2, poly_sum;

	cin >> k;

	for (int i = 0; i < k; i ++) {
		cin >> item.index >> item.coeff;
		poly1.push_back(item);
	}

	cin >> k;

	for (int i = 0; i < k; i ++) {
		cin >> item.index >> item.coeff;
		poly2.push_back(item);
	}

	for (int i = 0, j = 0; i < poly1.size() || j < poly2.size();) {
		if (i >= poly1.size()) {
			poly_sum.push_back(poly2.at(j++));
		} else if (j >= poly2.size()) {
			poly_sum.push_back(poly1.at(i++));
		} else {
			if (poly1.at(i).index > poly2.at(j).index) {
				poly_sum.push_back(poly1.at(i++));
			} else if (poly1.at(i).index == poly2.at(j).index) {
				item.index = poly1.at(i).index;
				item.coeff = poly1.at(i++).coeff + poly2.at(j++).coeff;
				if (item.coeff != 0) {
					poly_sum.push_back(item);
				}
			} else if (poly1.at(i).index < poly2.at(j).index) {
				poly_sum.push_back(poly2.at(j++));
			}
		}
	}

	cout << poly_sum.size();

	vector<Poly>::iterator it;
	for (it = poly_sum.begin(); it != poly_sum.end(); it ++) {
		cout << " " << it->index << " ";
		printf("%.1f", it->coeff);
	}

	return 0;
}