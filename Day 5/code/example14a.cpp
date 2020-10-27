
class Stack {
  int *m_arr;
  int maxlen;
  int m_top;
  public:
  Stack(int len):maxlen(len),top(-1) { 
    m_arr = new int[len];
  }
  ~Stack() {
    if(m_arr!=nullptr)
        delete[] m_arr;
  }
  void push(int val) {
    m_arr[++m_top]=m_val;
  } 
  int pop() {
    int val=m_arr[m_top--];
    return val;
  }
  bool isFull() const { return top==maxlen-1; }
  bool isEmpty()  const { return top==-1; }
};

