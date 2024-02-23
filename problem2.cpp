// Evan Tieu
// Programming Assignment 2
// Problem 2: Minotaur’s Crystal Vase
// COP 4520, Spring 2024

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

const int NUM_GUESTS = 5;
bool AVAILABLE = true;
std::queue<int> guestQueue;
std::condition_variable condVar;
std::mutex mtx;

void enter(int number)
{
    using namespace std;

    {
        lock_guard<mutex> lock(mtx);
        guestQueue.push(number);
        condVar.notify_one();
    }

    unique_lock<mutex> ulock(mtx);

    ulock.unlock();
    
    condVar.wait(ulock, [number] { return guestQueue.front() == number && AVAILABLE; });

    cout << "Guest " << number << " is entering the showroom." << endl;

    lock_guard<mutex> lg(mtx);

    AVAILABLE = false;

    if (number == NUM_GUESTS) {
        condVar.notify_one();
    }
}

int main(void)
{
    using namespace std;

    cout << "Preparing " << NUM_GUESTS << " guests to visit the showroom..." << endl;

    thread guests[NUM_GUESTS];

    for (int i = 0; i < NUM_GUESTS; ++i)
        guests[i] = thread(enter, i + 1);

    for (auto& thread : guests)
        thread.join();

    cout << "All guests have visited the showroom." << endl;

    return 0;
}
