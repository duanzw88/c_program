#include <stdio.h>
#include <signal.h>

/*
*信号处理函数
*/
void handler(int data)
{
    printf("signal data = %d\n",data);
}

/*
*产生信号函数
*/
void raise_sig(void)
{
    raise(SIGINT);
}

int main()
{
    void (*orig_handler)(int);
    int a[10] = {0};

    printf("SININT = %d\n",SIGINT);
    orig_handler = signal(SIGINT,handler);
    raise_sig();
    printf("end\n\n\n");

    printf("Changing handler to SIGIGB\n");
    signal(SIGINT,SIG_IGN);
    raise_sig();
    printf("end\n\n\n");

    printf("Restoring original handler\n");
    signal(SIGINT,orig_handler);
    raise_sig();
    
    printf("end\n");
    
    return 0;
}
