            //OUR OWN ATOMIC CLASS


/*
    std::atomic<int> counter(10);
    std::atomic<int> counter=10;   //error   (make explicit construtor in order not to allow initialzing objects like counter=10;)
        eg:  explicit atomic(int val):m_val(val){};


*/


template<typename T>
class my_atomic
{
    T m_val;
    std::mutex m1;//or std::unique_lock<std::mutex> ulck(m1);
    public:
        explicit my_atomic(T val):m_val(val){}
        my_atomic<T>& operator++()
        {
            m1.lock();
            ++m_val;
            m1.unlock();
            return *this;
        }
        my_atomic<T>& operator--()
        {
            m1.lock();
            --m_val;
            m1.unlock();
            return *this;
        }
        my_atomic<T>& operator=(int val)
        {
            m1.lock();
            ++m_val;
            m1.unlock();
            return *this;
        }
};