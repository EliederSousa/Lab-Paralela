#include <windows.h>
#include <stdio.h>
#include <math.h>

unsigned long long int result = 1;

struct Args {
  int init;
  int end;
};

DWORD WINAPI thread( void* arg ) {

    HANDLE  hStdout = NULL;
    struct Args* teste = arg;
    
    if( (hStdout = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE ) return 1;
    
    int w;

    for( w = teste->init; w < teste->end+1; w++ ) {
      result *= w;
    }
    
    return 0; 
}
 
void main(int argc, char** argv) {
    int resultado1 = 1;
    int resultado2 = 1;
    struct Args um;
    struct Args dois;
    long NUM = strtol(argv[1], NULL, 10);
    um.init = 1;
    um.end = floor(NUM/2);
    dois.init = floor(NUM/2)+1;
    dois.end = NUM;

    HANDLE Handle_Of_Thread_1 = 0;
    HANDLE Handle_Of_Thread_2 = 0;
    HANDLE Array_Of_Thread_Handles[2];

    Handle_Of_Thread_1 = CreateThread( NULL, 0, thread, &um, 0, NULL);  
    if ( Handle_Of_Thread_1 == NULL) {
      ExitProcess(resultado1);
    }
        
    Handle_Of_Thread_2 = CreateThread( NULL, 0, thread, &dois, 0, NULL);  
    if ( Handle_Of_Thread_2 == NULL)
        ExitProcess(resultado2);

    Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;
    Array_Of_Thread_Handles[1] = Handle_Of_Thread_2;
    
    // Wait until all threads have terminated.
    WaitForMultipleObjects( 2, Array_Of_Thread_Handles, TRUE, INFINITE);

    // Close all thread handles upon completion.
    CloseHandle(Handle_Of_Thread_1);
    CloseHandle(Handle_Of_Thread_2);

    printf("%llu", result);
}
