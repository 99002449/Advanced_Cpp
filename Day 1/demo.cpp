#include <iostream>

using namespace std;

void print(const Sample& r) 
{
std::cout << "l-value ref\n";
}

void print(Sample&& r)
{
std::cout << "r-value ref\n";
}
template<typename T>
void test(T&& rr) {
print(rr);
}

void check(auto&& rr) {
print(rr);
}

int main()
{
    Sample s1;
test(s1); //check(s1)
test(std::move(s1)); //check
test(Sample(11,12)); //check
return 0;

}
