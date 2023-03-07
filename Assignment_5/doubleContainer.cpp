#include "DoubleContainer.h"

void cpy(double*, const double*, int);




DoubleContainer::DoubleContainer() {
	size = 5;
	nums = new double[size];
	for (int i = 0; i < size; i++)
		nums[i] = 0;
}
DoubleContainer::DoubleContainer(const double* arr, int size) {
	this->size = size;
	nums = new double[size];
	cpy(nums, arr, size);
}
DoubleContainer::DoubleContainer(const DoubleContainer& v) {
	size = v.size;
	nums = new double[size];
	cpy(nums, v.nums, size);
}
DoubleContainer& DoubleContainer::operator=(const DoubleContainer& v) {
	size = v.size;
	delete[] nums;
	nums = new double[size];
	cpy(nums, v.nums, size);
	return *this;
}
DoubleContainer::~DoubleContainer() {
	delete[] nums;
}


void DoubleContainer::add(double x) {
	double* newPtr = new double[size + 1];
	cpy(newPtr, nums, size);
	newPtr[size] = x;
	delete[] nums;
	nums = newPtr;
	size++;
}
double DoubleContainer::remove() {
	size--;
	return nums[size];
}
void DoubleContainer::clear() {
	size = 0;
}



DoubleContainer DoubleContainer::operator+(const DoubleContainer& v) const {
	if (size != v.size) 
	{
		cout << "Invalid size: " << size << " | " << v.size << endl;
		return DoubleContainer();
	}
	DoubleContainer sum = v;
	for (int i = 0; i < sum.size; i++) 
	{
		sum.nums[i] += nums[i];
	}
	return sum;
}
DoubleContainer DoubleContainer::operator-(const DoubleContainer& v) const {
	if (size != v.size) 
	{
		cout << "Invalid size: " << size << " | " << v.size << endl;
		return DoubleContainer();
	}
	DoubleContainer sum = -v;
	for (int i = 0; i < sum.size; i++)
		sum.nums[i] += nums[i];
	return sum;
}
DoubleContainer& DoubleContainer::operator+=(const DoubleContainer& v) {
	if (size != v.size) cout << "Invalid size: " << size << " | " << v.size << endl;
	else
		for (int i = 0; i < size; i++)
			nums[i] += v.nums[i];
	return *this;
}
DoubleContainer& DoubleContainer::operator-=(const DoubleContainer& v) {
	if (size != v.size) cout << "Invalid size: " << size << " | " << v.size << endl;
	else
		for (int i = 0; i < size; i++)
			nums[i] -= v.nums[i];
	return *this;
}


DoubleContainer DoubleContainer::operator*(double scalar) const {
	DoubleContainer product = *this;
	for (int i = 0; i < product.size; i++)
		product.nums[i] *= scalar;
	return product;
}
DoubleContainer operator*(double scalar, const DoubleContainer& v) {
	DoubleContainer product = v;
	for (int i = 0; i < product.size; i++)
		product.nums[i] *= scalar;
	return product;
}
DoubleContainer DoubleContainer::operator/(double scalar) const {
	DoubleContainer product = *this;
	for (int i = 0; i < product.size; i++)
		product.nums[i] /= scalar;
	return product;
}
DoubleContainer& DoubleContainer::operator*=(double scalar) {
	for (int i = 0; i < size; i++)
		nums[i] *= scalar;
	return *this;
}
DoubleContainer& DoubleContainer::operator/=(double scalar) {
	for (int i = 0; i < size; i++)
		nums[i] /= scalar;
	return *this;
}
DoubleContainer DoubleContainer::operator-() const {
	DoubleContainer product = *this;
	for (int i = 0; i < product.size; i++)
		product.nums[i] = -product.nums[i];
	return product;
}


double DoubleContainer::operator*(const DoubleContainer& v) const {
	if (size != v.size) 
	{
		cout << "Invalid size: " << size << " | " << v.size << endl;
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < size; i++)
		sum += nums[i] * v.nums[i];
	return sum;
}


std::ostream& operator<<(std::ostream& out, const DoubleContainer& v) {
	out << '<';
	if (v.size > 0) out << v.nums[0];
	for (int i = 1; i < v.size; i++)
		out << ", " << v.nums[i];
	out << '>';
	return out;
}


void cpy(double* target, const double* source, int size) {
	for (int i = 0; i < size; i++)
		target[i] = source[i];
}