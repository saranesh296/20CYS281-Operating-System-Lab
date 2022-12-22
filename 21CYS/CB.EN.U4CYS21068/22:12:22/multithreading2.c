#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

// printWelcomeMessage will be called when the Thread is created in the main function 
// which takes string as an argument
void *printWelcomeMessage(void *threadid) {
    
   sleep(1);    
   long int tid=(long)threadid;
  
   printf("\n[THREAD] Hello, Welcome %ld.", tid);
   pthread_exit(NULL);
   
}

int main () {

   // thread defintion
   pthread_t threads[7];
   
   // parameter to be passed to the called function - printWelcomeMessage
   char names[10][15] = {"Amritha","Praveen","Saurabh","Sangeetha","Lakshmy","Srinivasan","Ramaguru"};
   
   int result;
   
   for(int i = 0; i < 7; i++ ) {
       sleep(1);
   
      printf("\n[MAIN] Creating thread, %d", i);
      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[i], NULL, printWelcomeMessage, (void *)threads[i]);
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
         
      }
      
   }
   
   // Exit the thread
   pthread_exit(NULL);
}
