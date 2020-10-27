
std::promise<int> p1;
int compute() {
  int i;
  for(i=0;i<len;i++)
	std::cout << "Hello.." << i << "\n";
  //try some delay here
  p1.set_value(10);
  //some more code
  return sum;
}

int main() {
  int arr[10];
  std::thread t1(compute);
  std::future<int> result = p1.get_future();
  std::cout << result.get() << "\n";
  t1.join();
  return 0;
}
