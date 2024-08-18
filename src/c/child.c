#include <string.h>
#include <stdio.h>

#include <process_bridge.h>

void sleep_millis(int millis);

int main(void)
{
    PB_process_t *parent = PB_create(PB_TYPE_PARENT);
    char buf[3][PB_STRING_SIZE_DEFAULT];
    memset(buf, 0, sizeof(buf));
    PB_receive(parent, buf[0], PB_STRING_SIZE_DEFAULT);
    PB_receive(parent, buf[1], PB_STRING_SIZE_DEFAULT);
    PB_receive(parent, buf[2], PB_STRING_SIZE_DEFAULT);

    char out[4 * PB_STRING_SIZE_DEFAULT];
    sprintf(out, "c1 %s %s %s", buf[0], buf[1], buf[2]);
    PB_send(parent, out);
    PB_send_err(parent, out);
    PB_send(parent, "c2");
    PB_send_err(parent, "c2");
    PB_send(parent, "c3");
    PB_send_err(parent, "c3");

    sleep_millis(1000);

    return 12;
}

#ifdef _WIN32
#include <windows.h>
void sleep_millis(int millis)
{
    Sleep(millis);
}
#else
#include <unistd.h>
void sleep_millis(int millis)
{
    usleep(millis * 1000);
}
#endif