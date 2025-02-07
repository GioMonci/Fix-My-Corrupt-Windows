#include "../include/common.h"
#include "../include/Logs.h"

int main(int argc, char *argv[]) {
    Logs logs;
    ShellExecuteInfoAsAdmin SEIAA;

    std::cout << R"(
    88888888888  88b           d88    ,ad8888ba,   I8,        8        ,8I
    88           888b         d888   d8"'    `"8b  `8b       d8b       d8'
    88           88`8b       d8'88  d8'             "8,     ,8"8,     ,8"
    88aaaaa      88 `8b     d8' 88  88               Y8     8P Y8     8P
    88"""""      88  `8b   d8'  88  88               `8b   d8' `8b   d8'
    88           88   `8b d8'   88  Y8,               `8a a8'   `8a a8'
    88           88    `888'    88   Y8a.    .a8P      `8a8'     `8a8'
    88           88     `8'     88    `"Y8888Y"'        `8'       `8'
    )" << std::endl;

    bool running = true;
    while(running) {

        std::cout << "FMCW Menu\n";
        std::cout << "----------------------------------------\n";
        std::cout << "1. Enter FMCW Mode (Run system fixes)\n";
        std::cout << "2. Enter App Update Mode (Coming Soon)\n";
        std::cout << "3. Exit App\n";
        std::cout << "Choose an option: ";

        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
            std::cout << "\nInvalid input! Please enter a number (1-3): ";
        }

        if (choice == 1) {
            std::cout << "\nEntering FMCW Mode in 5 Seconds\n";
            logs.ProgressBar(5000);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
            SEIAA.StartingExecutionProcess();
            SEIAA.AskForRestart();
            system("pause");
            running = false;
        }
        else if (choice == 2) {
            std::cout << "\nEntering App Update Mode in 5 Seconds\n";
            logs.ProgressBar(5000);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
            // Call your update-related functions here
            system("pause");
            running = false;
        }
        else if (choice == 3) {
            std::cout << "\nExiting App...\n";
            logs.ProgressBar(1000);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            running = false;
        }
        else {
            std::cout << "\nInvalid option! Trying Again...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            system("cls");
        }
    }
    return 0;
}
