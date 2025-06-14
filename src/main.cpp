/*
AUTH: GM
DATE: 6/9/25
DESC: main file where app starts
*/

#include "../include/logger.h"
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
	logger::info("Launching FMCW on Windows.");
	
	// Determine Mode: CLI VS GUI
	if (argc > 1) {
		// CLI MODE
		bool cli = true;
		std::string cmd = argv[1];
		while (cli) {
			logger::info("CLI MODE");
			if (cmd == "repair") {
				logger::info("Entered repair.");
				system("pause");
				std::cout << "Do you want to exit? \n";
				std::cout << "Y/N: ";
				char exit;
				std::cin >> exit;
				bool repairChoice = true;
				while (repairChoice) {
					if (exit == 'Y'|| exit == 'y') {
						cli = false;
						repairChoice = false;
					}
					else if (exit == 'N' || exit =='n') {
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						repairChoice = false;
					}
					else {
						logger::warning("Invalid command, try again.");
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						repairChoice = false;
					}
				}
			}
			else if (cmd == "update") {
				logger::info("Entered Update");
				system("pause");
				std::cout << "Do you want to exit? \n";
				std::cout << "Y/N: ";
				char exit;
				std::cin >> exit;
				bool updateChoice = true;
				while (updateChoice) {
					if (exit == 'Y' || exit == 'y') {
						cli = false;
						updateChoice = false;
					}
					else if (exit == 'N' || exit == 'n') {
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						updateChoice = false;
					}
					else {
						logger::warning("Invalid command, try again.");
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						updateChoice = false;
					}
				}
			}
			else if (cmd == "Template") {
				logger::info("Entered Template");
				system("pause");
				std::cout << "Do you want to exit? \n";
				std::cout << "Y/N: ";
				char exit;
				std::cin >> exit;
				bool templateChoice = true;
				while (templateChoice) {
					if (exit == 'Y' || exit == 'y') {
						cli = false;
						templateChoice = false;
					}
					else if (exit == 'N' || exit == 'n') {
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						templateChoice = false;
					}
					else {
						logger::warning("Invalid command, try again.");
						std::cout << "Enter command (ex: repair, update, [....]: ";
						std::cin >> cmd;
						templateChoice = false;
					}
				}
			}
			else {
				logger::warning("Invalid command, try again.");
				std::cout << "Enter command (ex: repair, update, [....]: ";
				std::cin >> cmd;
			}
		}
		return 0;
	}
	else {
		// GUI MODE
		logger::info("GUI MODE");
		// RUN GUI FUNCTION
		// 
	}
}