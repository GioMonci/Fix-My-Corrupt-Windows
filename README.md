# Fix-My-Corrupt-Windows

My friend Juan Carter always has corrupt Windows files. This little program is designed to fix issues related to corrupt Windows files. However, it works under the pretense that System File Checker (SFC), Deployment Image Servicing, Management (DISM), and Check Disk (CHKDSK) are still functioning on your PC. 
If SFC, DISM, and CHKDSK are themselves corrupt, this program won't be able to help. Run the program and then restart your PC, and all should work like a charm.

## Table of Contents
1. [What does this program do?](#what-does-this-program-do)
2. [How to use it?](#how-to-use-it)
    - [Method 1: Using the EXE file](#method-1-using-the-exe-file)
    - [Method 2: Compiling the Files Yourself](#method-2-compiling-the-files-yourself)
3. [Prerequisites](#prerequisites)
4. [Download Project Files](#download-project-files)
5. [Install MinGW Compiler](#install-mingw-compiler)
6. [Compile and Run the Program](#compile-and-run-the-program)
7. [Commands Used](#commands-used)
8. [Notes](#notes)
9. [Troubleshooting](#troubleshooting)
10. [Disclaimer](#disclaimer)
11. [License](#license)


## What does this program do?

This program opens CMD as an administrator and runs a series of commands to fix any corrupt files on your Windows machine.

## How to use it?

### ~~Method 1: Using the EXE file~~
Note: Marked as a virus until I can get it signed, just compile for now!

#### Steps:

1. Download the repository as a zip file.
2. Extract the zip file.
3. Open the project folder, then open the subfolder called `EXE`.
4. Run the `FixMyCorruptWindows.exe` file.
5. If your antivirus or Windows flags the file as unsafe, you can click "More info" and choose "Run anyway".

---

## Method 2: Compiling the Files Yourself

### Prerequisites
Before you can run this project, you will need:
- A Windows PC
- Internet connection
- FMWC project files or GIT
- Command prompt access with administrator privileges
- A C++ compiler (MinGW is recommended)
  
---

### Steps:

#### Option 1: Using Git

1. Clone the repository from GitHub. Open the command prompt and run the following command:

    ```bash
    git clone https://github.com/GioMonci/Fix-My-Corrupt-Windows.git
    ```

2. Navigate to the downloaded project directory:

    ```bash
    cd Fix-My-Corrupt-Windows-main
    ```

---

#### Option 2: Manual Download (No Git Required)

1. Go to the GitHub repository page: [GitHub Repository](https://github.com/GioMonci/Fix-My-Corrupt-Windows).

2. Click on the green **Code** button, then select **Download ZIP**.

3. Once the ZIP file is downloaded, extract it to a folder of your choice.

4. Open the command prompt and navigate to the folder where you extracted the files:

    ```bash
    cd path\to\extracted\folder
    ```

---

#### Install MinGW Compiler

1. Open the command prompt as an administrator.

2. Install the MinGW package manager using the following command:

    ```bash
    winget install -e --id MinGW.Mingw
    ```

3. Add MinGW to your system path by setting the environment variables:
    - Press `Win + R`, type `sysdm.cpl`, and hit Enter.
    - In the System Properties window, go to the **Advanced** tab and click **Environment Variables**.
    - Under **System variables**, find `Path` and click **Edit**.
    - Click **New** and add the path to your MinGW `bin` folder (e.g., `C:\MinGW\bin`).
    - Click **OK** to save and close all dialogs.

4. Verify that MinGW was added successfully by running:

    ```bash
    g++ --version
    ```

---

#### Compile and Run the Program

1. Navigate to the project directory:

    ```bash
    cd Fix-My-Corrupt-Windows-main
    ```

2. Compile the program using the g++ compiler:

    ```bash
    g++ -o FMCW main.cpp logs.cpp shellExecuteInfoAsAdmin.cpp
    ```

3. After compilation, run the resulting executable:

    ```bash
    FMCW.exe
    ```

4. Follow the on-screen prompts to specify your PC's status level and begin the repair process.

---

## Commands Used

This program runs the following commands to fix corrupt Windows files:

1. **System File Checker (SFC):**
    - Scannow:
      ```bash
      sfc /scannow
      ```
    This scans and repairs corrupted system files.

2. **Deployment Image Servicing and Management (DISM):**
    - ScanHealth:
      ```bash
      dism /online /cleanup-image /scanhealth
      ```
      This checks the health of the Windows image.

    - CheckHealth:
      ```bash
      dism /online /cleanup-image /checkhealth
      ```
      This checks if the Windows image is repairable.

    - RestoreHealth:
      ```bash
      dism /online /cleanup-image /restorehealth
      ```
      This repairs the Windows image.
  
3. **Check Disk (CHKDSK):**
    - CheckDisk:
      ```bash
      chkdsk C: /f /r /x
      ```
    Scans your hard drive for file system errors.

---

## Notes

- Read the instructions in the program thoroughly.
- Ensure you run the program with administrative privileges.
- Restart your computer after running the program to apply the changes.
- If you encounter any issues, make sure that SFC and DISM are not corrupted themselves.

---

## Troubleshooting

1. **MinGW not found**: If `g++` is not recognized, ensure MinGW is properly installed and added to the system's environment variables.
   
2. **Compilation errors**: Ensure all necessary files (`main.cpp`, `logs.cpp`, `shellExecuteInfoAsAdmin.cpp`, and header files) are present in the directory.

---

## Disclaimer

Use this program at your own risk. The author is not responsible for any potential damage to your system.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
