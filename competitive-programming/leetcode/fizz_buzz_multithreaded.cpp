// https://leetcode.com/problems/fizz-buzz-multithreaded

class FizzBuzz
{
  private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

    void do_work(function<bool(int)> cond, function<void(int)> work)
    {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return i > n or cond(i); });
            if (i > n)
                break;
            work(i++);
            lock.unlock();
            cv.notify_all();
        }
    }

  public:
    FizzBuzz(int n)
    {
        this->n = n;
        this->i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz)
    {
        do_work([](int i) { return (i % 3 == 0) and (i % 5 > 0); },
                [&](int i) { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz)
    {
        do_work([](int i) { return (i % 3 > 0) and (i % 5 == 0); },
                [&](int i) { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz)
    {
        do_work([](int i) { return (i % 3 == 0) and (i % 5 == 0); },
                [&](int i) { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber)
    {
        do_work([](int i) { return (i % 3 > 0) and (i % 5 > 0); },
                [&](int i) { printNumber(i); });
    }
};