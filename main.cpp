#include <iostream>
#include <windows.h>

// Function to display a message box with restart options
int PromptForRestart() {
    int choice = MessageBox(nullptr, "You need to restart your computer for changes to take effect.\n\nRestart now?", "Restart Required", MB_YESNOCANCEL | MB_ICONINFORMATION);
    return choice;
}

// Function to restart the computer
void RestartComputer() {
    system("shutdown /r /t 15");
}

void RunCommandWithAdminPrivileges(const char* command, const char* parameters) {
    // Initializing the SHELLEXECUTEINFO structure to zero
    SHELLEXECUTEINFO shellExecuteInfo;
    memset(&shellExecuteInfo, 0, sizeof(shellExecuteInfo));

    // Setting the size of the structure
    shellExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFO);

    // Specifying that the function should not return until the launched process terminates
    shellExecuteInfo.fMask = SEE_MASK_NOCLOSEPROCESS;

    // No window handle is needed
    shellExecuteInfo.hwnd = nullptr;

    // Request elevation by using the "runas" verb
    shellExecuteInfo.lpVerb = "runas";

    // Specifying to run cmd
    shellExecuteInfo.lpFile = command;

    // Specifying the command-line parameters for the program
    shellExecuteInfo.lpParameters = parameters;

    // Using the current directory for the new process
    shellExecuteInfo.lpDirectory = nullptr;

    // Make the window visible (SW_HIDE to hide the window)
    shellExecuteInfo.nShow = SW_SHOWNORMAL;

    // Attempt to execute the command with the specified parameters and elevated privileges
    if (ShellExecuteEx(&shellExecuteInfo)) {
        // Wait for the process to complete
        WaitForSingleObject(shellExecuteInfo.hProcess, INFINITE);

        Sleep(5000);

        // Close the handle to the process
        CloseHandle(shellExecuteInfo.hProcess);

        Sleep(5000);

    } else {
        // Print an error message if the command execution fails
        std::cerr << "Failed to execute command: " << parameters << std::endl;
    }
}
int main() {
    std::cout << "Starting System File Checker (SFC)..." << std::endl;
    RunCommandWithAdminPrivileges("cmd.exe", "/c sfc /scannow");

    std::cout << "Starting Deployment Image Servicing and Management (DISM) ScanHealth..." << std::endl;
    RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /scanhealth");

    std::cout << "Starting Deployment Image Servicing and Management (DISM) CheckHealth..." << std::endl;
    RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /checkhealth");

    std::cout << "Starting Deployment Image Servicing and Management (DISM) RestoreHealth..." << std::endl;
    RunCommandWithAdminPrivileges("cmd.exe", "/c dism /online /cleanup-image /restorehealth");

    // Prompt the user to restart the computer
    int restartChoice = PromptForRestart();

    if (restartChoice == IDYES) {
        // Restart the computer
        RestartComputer();
    } else if (restartChoice == IDNO) {
        // User chose to restart later
        std::cout << "You chose to restart later. Closing the program." << std::endl;
    } else {
        // User closed the dialog or chose Cancel
        std::cout << "Restart prompt canceled. Closing the program." << std::endl;
    }

    // Pause to allow user to read console output before program exits
    system("pause");

    return 0;
}
