#include <Windows.h>

#include "Resident.h"

//https://github.com/TsudaKageyu/minhook/wiki - оригинальная идея

void ThreadMain()
{
    MessageBox(NULL, TEXT("Your system is pwned!"), TEXT("Pwned!"), MB_ICONWARNING | MB_OK);
    
    for (int i = 0; i < 1000000000; i++) {

    }

    ExitThread(0);
}