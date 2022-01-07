

#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

int child_events = 0;

void child_sig_handler(int x)
{
    // 调用次数+1
    child_events++;

    // 重新设定信号回调函数
    signal(SIGCHLD, child_sig_handler);
}

int main(int argc, char* argv[])
{
    // 设定的信号掩码sigmask和原始的信号掩码origin_sigmask
    sigset_t sigmask, orig_sigmask;
    
    // 清空信号
    sigemptyset(&sigmask);

    // 将SIGCHILD信号加入sigmask
    sigaddset(&sigmask, SIGCHLD);

    // 设定信号 SIG_BLOCK的掩码sigmask, 并将原始的掩码保存到orig_sigmask中
    sigprocmask(SIG_BLOCK, &sigmask, &orig_sigmask);

    // 挂接对信号SIGCHILD的处理函数child_sig_handler()
    signal(SIGCHLD, child_sig_handler);

    for(;;)
    {
        for(; child_events>0; child_events--)
        {
            // 处理动作
        }
        r = pselect(nfds, &rd, &wr, &er, 0, &orig_sigmask);
    }

    return 0;
}