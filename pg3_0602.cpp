#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int current = 1;

void PrintThread(int num) {
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&] { return current == num; });  
    cout << "thread " << num << endl;
    current++;
    cv.notify_all();  
}

int main() {
    thread t1(PrintThread, 1);
    thread t2(PrintThread, 2);
    thread t3(PrintThread, 3);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
