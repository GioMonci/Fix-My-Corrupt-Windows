#include "../include/ShellExecuteInfoAsAdmin.h"

void ShellExecuteInfoAsAdmin::AskForRestart() {
    // Calls Prompt Restart function & returns choice as int
    int restartChoice = PromptForRestart();

    // Self-explanatory
    if (restartChoice == IDYES) {
        // Restart the computer
        RestartComputer();
    } else if (restartChoice == IDNO) {
        // Restart later
        std::cout << "You chose to restart later. Closing the program." << std::endl;
    } else {
        // User closed the window or chose Cancel
        std::cout << "Restart prompt canceled. Closing the program." << std::endl;
    }
}

int ShellExecuteInfoAsAdmin::PromptForRestart() {
    // MessageBox function (winuser.h)
        // Taken off microsoft WIN32 API
    int choice = MessageBox(nullptr, "You need to restart your computer for changes to take effect.\n\nRestart now?",
        "Restart Required", MB_YESNOCANCEL | MB_ICONINFORMATION);
    return choice;
}

void ShellExecuteInfoAsAdmin::RestartComputer() {
    // Command to restart the computer
    system("shutdown /r /t 15");
}

void ShellExecuteInfoAsAdmin::StartingExecutionProcess() {

    /**
     * This is where you specify what commands you want to run
     * Just a simple sfc/scannow should suffice for most people
     * If the pc is cooked then run every command
     * If this doesn't fix your windows then its offically cooked - reinstall windows!
     **/

    Logs logs;

    enum pc_status_level {
        NotBad = 1,  // 1
        Bad,         // 2
        Cooked       // 3
    };

    pc_status_level level;
    int input;


    logs.LogMessage("** Please Read! **\n"
                "Welcome to Fix My Corrupt Windows (FMCW)!\n\n"
                "This program is designed to help repair corrupt Windows system files on your computer.\n"
                "It works by running a series of commands that scan your system files, identifies corrupt ones,\n"
                "and replaces them with healthy files. Please note that for the fixes to take effect, you will \n"
                "need to restart your PC after running the commands.\n"
                "Commands are categorized based on your PC's status level:\n\n"
                "1. **NotBad**: Your PC is running fine, but you want to perform a basic check.\n"
                "   - This will run the System File Checker (SFC) to scan and repair system files.\n"
                "2. **Bad**: Your PC is experiencing issues such as slow performance or malfunctioning Windows functions.\n"
                "   - This will run SFC as well as additional Deployment Image Servicing and Management (DISM) commands\n"
                "     to further diagnose and repair system files.\n"
                "3. **Cooked**: Your PC is frequently crashing, BSOD, or not functioning properly at all.\n"
                "   - This will run SFC, DISM, and CHKDSK commands to address severe issues.\n\n"
                "To reiterate, after running the program, it is essential to restart your PC for the changes to take effect.\n"
                "If running the commands for a 'Cooked' status level does not resolve the issues,\n"
                "it may indicate that the system files or tools themselves are too corrupted,\n"
                "and a clean installation of Windows might be necessary.\n"
                "Thank you for using FMCW! We hope this helps improve your system's performance.\n");

    while (true) {
        logs.LogSeparate();
        logs.LogMessage("Let us know your PC status level (1 = NotBad, 2 = Bad, 3 = Cooked): \n");
        std::cout<< ("Enter a number (1-3): ");
        int input;
        std::cin >> input;

        if (input == 1 || input == 2 || input == 3) {
            level = static_cast<pc_status_level>(input);
            break;
        }
            logs.LogMessage("Invalid input. Please try again.");
    }

    if(level >= NotBad) {
        std::cout << std::endl;
        logs.LogSeparate();
        logs.LogMessage("Starting System File Checker (SFC)...\n");
        RunCommandWithAdminPrivileges("cmd.exe", "/c sfc /scannow");
    }
    if(level >= Bad) {
        logs.LogSeparate();
        logs.LogMessage("Starting Deployment Image Servicing and Management (DISM) ScanHealth...\n");
        RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /scanhealth");

        logs.LogSeparate();
        logs.LogMessage("Starting Deployment Image Servicing and Management (DISM) CheckHealth...\n");
        RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /checkhealth");

        logs.LogSeparate();
        logs.LogMessage("Starting Deployment Image Servicing and Management (DISM) RestoreHealth...\n");
        RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /restorehealth");
    }
    if(level >= Cooked) {

        char userChoice;
        logs.LogSeparate();
        logs.LogMessage("Warning: This CHKDSK command is extensive and may take a significant amount of time to complete.\n"
                "I recommend checking that the previous commands didn't fix your PC before resorting to 'Cooked'.\n"
                "Therefore, I recommend not proceeding by typing 'n' / 'N' to exit and restart.\n"
                "Nevertheless, if the previous commands didn't fix anything and you still have problems, then proceed.\n"
                "If you proceed with this level, be aware that the process can take up to several hours.\n"
                "The initial scan may be quick, but once you restart your PC, the full scan and repair will take place during boot.\n"
                "During boot, `chkdsk` will run through multiple phases, each of which may take a considerable amount of time.\n"
                "Please do not turn off your computer during this process.\n"
                "If your PC restarts unexpectedly, it typically will not further damage your disk beyond the existing issues,\n"
                "but there is still a small risk of additional corruption.\n"
                "Only consider restarting or interrupting the process if the boot-time scan and repair process takes longer than 10-20 hours.\n"
                "If you wish to continue, enter 'y' to proceed or 'n' to cancel this process: ");

        while(true) {
            std::cout << "Enter y or n: ";
            std::cin >> userChoice;
            if (userChoice == 'y' || userChoice == 'Y') {
                logs.LogSeparate();
                logs.LogMessage("Starting CHKDSK scan...\n");
                RunCommandWithAdminPrivileges("cmd.exe", "/c chkdsk C: /f /r /x");

                logs.LogSeparate();
                logs.LogMessage("A restart is required to complete the CHKDSK operation. Please restart your computer.");
                break;
            }
            if(userChoice == 'n' || userChoice == 'N') {
                logs.LogMessage("Canceling CHKDSK");
                break;
            }
            logs.LogMessage("Invalid input. Please try again.");
        }
    }
}

void ShellExecuteInfoAsAdmin::RunCommandWithAdminPrivileges(const char* command, const char* parameters) {

     // Added the new parameters string to include '&& timeout 5' to wait for 5 seconds before closing the window
    std::string newParameters = std::string(parameters) + " && timeout /t 5";

    // Added the new parameters string to include '&& pause' to keep the window open
        // Uncomment line below if you prefer pause to timeout
    //std::string newParameters = std::string(parameters) + " && pause";

    // Initializing the SHELLEXECUTEINFO structure to zero
    SHELLEXECUTEINFO shellExecuteInfo;
    //NOTE: Compiler said I don't gotta use memset, so I commented it out
        //Junk still works, uncomment if it breaks while testing
        //memset(&shellExecuteInfo, 0, sizeof(shellExecuteInfo));

    // Setting the size of the structure
    shellExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFO);

    // Specifying that the function should not return until the launched process terminates
    shellExecuteInfo.fMask = SEE_MASK_NOCLOSEPROCESS;

    // No window handle is needed
    shellExecuteInfo.hwnd = nullptr;

    // Request elevation by using the "runas" verb
        // Note: important cuz if it's not run as admin then commands don't work
    shellExecuteInfo.lpVerb = "runas";

    // Specifying to run cmd
    shellExecuteInfo.lpFile = command;

    // Specifying the command-line parameters for the program
        // this is the old way, leaving here for history purposes
    //shellExecuteInfo.lpParameters = parameters;

    // Specifying the command-line parameters for the program
        // new way - so we can use && timeout 2
    shellExecuteInfo.lpParameters = newParameters.c_str();

    // Using the current directory for the new process
    shellExecuteInfo.lpDirectory = nullptr;

    // Make the window visible (SW_HIDE to hide the window)
    shellExecuteInfo.nShow = SW_SHOWNORMAL;

    // trying to execute the command with the specified parameters and elevated privileges
    if (ShellExecuteEx(&shellExecuteInfo)) {
        // Wait for the process to complete
            // lol wouldn't want to exit in the middle of a process
        WaitForSingleObject(shellExecuteInfo.hProcess, INFINITE);

        // Close the handle to the process
        CloseHandle(shellExecuteInfo.hProcess);

        // 1 sec delay just in case
        Sleep(1000);

    } else {
        // Print an error message if the command execution fails
        std::cerr << "Failed to execute command: " << parameters << std::endl;
    }
};

