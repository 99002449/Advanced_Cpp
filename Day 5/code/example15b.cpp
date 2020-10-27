

int sumarr(int *arr, int len) {
  int sum=0,i;
  for(i=0;i<len;i++)
	sum+=arr[i];
  return sum;
}

int main() {
  int arr[10];
  //fill with random values

  std::future<int> result;
  result=std::async(sumarr, arr, 10);
  std::cout << result.get(); 
}
