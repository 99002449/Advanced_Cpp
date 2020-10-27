
class Stack {
  int *m_arr;
  int maxlen;
  int m_top;
  std::mutex m1;
  std::condition_variable ucv;
  std::condition_variable ocv;
  public:
  Stack(int len):maxlen(len),top(-1) { 
    m_arr = new int[len];
  }
  ~Stack() {
    if(m_arr!=nullptr)
        delete[] m_arr;
  }
  void push(int val) {
    std::unique_lock<std::mutex> ulck(m1);
    ocv.wait(ulck, [] { return !isFull(); }
    m_arr[++m_top]=m_val;
    ucv.notify_one();
  } 
  int pop() {
    std::unique_lock<std::mutex> ulck(m1);
    ucv.wait(ulck, [] { return !isEmpty(); }
    int val=m_arr[m_top--];
    ocv.notify_one();
    return val;
  }
  bool isFull() const { return top==maxlen-1; }
  bool isEmpty()  const { return top==-1; }
};

