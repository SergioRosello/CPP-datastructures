#include <iostream>
#include <condition_variable>
#include <mutex>
#include <ostream>
#include <string>
#include <thread>
#include <queue>

class Message{
  public:
    int message;
    Message(int msg) :message{msg} {};
};

std::ostream& operator<<(std::ostream& output, const Message& message){
  output << message.message;
  return output;
}

// Three global variables
std::queue<Message> messageQueue;
std::condition_variable mcond; // The variable communicating events
std::mutex mmutex;  // The locking mechanism

void emmiter(){
  for(int i{0}; true; ++i){
    Message m{i};
    //std::cout << m << std::endl;
    std::unique_lock<std::mutex> lck{mmutex}; // Protect operations
    messageQueue.push(m);
    mcond.notify_one();
  }
}

void reciever(){
  while (true) {
    std::unique_lock<std::mutex> lck{mmutex}; // Aquire mmutex
    mcond.wait(lck); // release lck and wait until event wake-up
    auto m = messageQueue.front();  // get the message
    std::cout << m << std::endl;
    messageQueue.pop();   // Remove the message from the queue
    lck.unlock();   // Release the lock
  }
}

int main(int argc, char *argv[])
{
  std::thread t1{ emmiter };
  std::thread t2{ reciever };

  t1.join();
  t2.join();
  return 0;
}
