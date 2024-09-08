#ifdef _WIN32
#include <windows.h>
#else
#include <signal.h>
#include <unistd.h>
#endif

#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
