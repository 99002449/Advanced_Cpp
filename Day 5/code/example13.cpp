template<typename T>
class my_atomic {
  T m_val;
  std::mutex m1;
  public:
  explicit my_atomic(T val):m_val(val) { }
  my_atomic<T>& operator++() {
    m1.lock(); //std::unique_lock<std::mutex> ulck(m1)
    ++m_val;
    m1.unlock();
    return *this;
  }
  my_atomic<T>& operator--() {
    m1.lock();
    --m_val;
    m1.unlock();
    return *this;
  }
  my_atomic<T>& operator=(int val) {
    m1.lock();
    m_val=val;
    m1.unlock();
    return *this;
  }
  operator T() { return m_val; }  
};
int main() {
  my_atomic<int> counter(10);
  ++counter;
  --counter;
}
  
  
  
