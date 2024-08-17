#include "../include/common.h"
#include "../include/Logs.h"


int main(int argc, char *argv[]) {
    Logs log;
    ShellExecuteInfoAsAdmin SEIAA;

    //log.LogSeparate();
    for(int i=0; i<argc; i++) {
        //printf("argv[%d] = %s\n", i, argv[i]);
    }
    //log.LogMessage("Command Line Arguments^\n");

    SEIAA.StartingExecutionProcess();
    SEIAA.AskForRestart();
    // Pause so that user can read the Console
    system("pause");

    return 0;
}
