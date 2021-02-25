// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex
#include <condition_variable>
#include <chrono>

#define MAX_COUNT 5

 struct Data {

  int cpt = 0;
};

bool ready = false;
std::mutex mutex;  
std::condition_variable cv;

void show(Data* data) 
{
  std::unique_lock<std::mutex> lk(mutex);
   std::cout << "Waiting... \n";
   while(true) {
    cv.wait(lk, []{return ready;});
    std::cout << "cpt -> "<< data->cpt << std::endl;
    ready = false;
   }
}

void inc(Data* data)
{
   for(int i = 0 ; i < MAX_COUNT ; i++)
    // send data to the worker thread
    {
       std::this_thread::sleep_for(std::chrono::seconds(1));
        std::lock_guard<std::mutex> lk(mutex);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
        data->cpt++;
    
    cv.notify_one();
    }
}

int main() 
{
  
  Data data;
  std::thread t1 (show,&data);     
  std::thread t2 (inc,&data);  

  // synchronize threads:
  t1.join();                
  t2.join();               

  std::cout << "show and inc completed.\n";

  return 0;
}
