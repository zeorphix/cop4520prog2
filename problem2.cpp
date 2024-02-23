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
std::condition_variable cv;
std::mutex mtx;

void enter(int number)
{
    using namespace std;

    unique_lock<mutex> lock(mtx);

    while (!AVAILABLE)
        cv.wait(lock);

    cout << "Guest " << number << " is entering the showroom." << endl;
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
