#include "doubleContainer.h"

using namespace std;

int main() {
	double nums1[5] = { 2,6,9,4,6 }, nums2[7] = {1,6,4,0,-6.5,0.75,2};
	DoubleContainer d1, d2(nums1, 5), d3(nums2, 7), d4(d2);
	cout << "---Printing vectors---" << endl;
	cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << endl;

	cout << "---add/remove functioins---" << endl;
	d2.add(5); d3.remove();
	cout << "new d2: " << d2 << endl << "new d3: " << d3 << endl;

	cout << "---Addition operator overload test---" << endl;
	cout << "d2 + d3: " << d2 + d3 << endl;
	cout << "d2 - d3: " << d2 - d3 << endl;
	cout << "d2 - d1 (wrong size): "; cout << d2 - d1 << endl;

	cout << "---multiplication test---" << endl;
	cout << "5 * d2: " << 5 * d2 << endl;

	cout << "---dot product test---" << endl;
	cout << "d2 * d3: " << d2 * d3 << endl;

	cout << "d2 * d1 (wrong size): "; cout << d2 * d1 << endl;

	return 0;
}