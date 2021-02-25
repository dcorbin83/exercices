#include <iostream>

#include <pthread.h>
#include <unistd.h>

#define MAX_COUNT 10
#define NUM_THREADS 2

using namespace std;
struct Data {

  int cpt = 0;

};

pthread_mutex_t mutex_sum;
pthread_cond_t cond_signal;
pthread_attr_t attr;

void * display(void * ptr) {
  Data * data = static_cast < Data * > (ptr);
  pthread_mutex_lock( & mutex_sum);
  while (data -> cpt < MAX_COUNT) {
    pthread_cond_wait( & cond_signal, & mutex_sum);
    std::cout << data -> cpt << std::endl;
  }

  pthread_mutex_unlock( & mutex_sum);
  pthread_exit(NULL);

}

void * inc(void * ptr) {

  Data * data = static_cast < Data * > (ptr);

  for (int i = 0; i < MAX_COUNT; i++) {
    pthread_mutex_lock( & mutex_sum);
    data -> cpt++;
    pthread_cond_signal( & cond_signal);
    pthread_mutex_unlock( & mutex_sum);

    /* Do some "work" so threads can alternate on mutex lock */
    usleep(500);
  }

  pthread_exit(NULL);
}

int main() {

  pthread_t threads[NUM_THREADS];
  Data * data = new Data();
  /* Initialize mutex and condition variable objects */
  pthread_mutex_init( & mutex_sum, NULL);
  pthread_cond_init( & cond_signal, NULL);

  /* For portability, explicitly create threads in a joinable state */
  pthread_attr_init( & attr);
  pthread_attr_setdetachstate( & attr, PTHREAD_CREATE_JOINABLE);
  pthread_create( & threads[0], & attr, display, (void * ) data);
  pthread_create( & threads[1], & attr, inc, (void * ) data);

  /* Wait for all threads to complete */
  for (int i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  printf("Main(): Waited on %d  threads. Done.\n", NUM_THREADS);

  /* Clean up and exit */
  pthread_attr_destroy( & attr);
  pthread_mutex_destroy( & mutex_sum);
  pthread_cond_destroy( & cond_signal);
  pthread_exit(NULL);
  return 0;
}
