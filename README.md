# Fix-My-Corrupt-Windows

My friend Juan Carter always has corrupt Windows files. This little program is designed to fix issues related to corrupt Windows files. However, it works under the pretense that System File Checker (SFC), Deployment Image Servicing, Management (DISM), and Check Disk (CHKDSK) are still functioning on your PC. 
If SFC, DISM, and CHKDSK are themselves corrupt, this program won't be able to help. Run the program and then restart your PC, and all should work like a charm.

## Table of Contents
1. [What does this program do?](#what-does-this-program-do)
2. [How to use it?](#how-to-use-it)
    - [Method 1: Using the EXE file](#method-1-using-the-exe-file)
    - [Method 2: Compiling the Files Yourself](#method-2-compiling-the-files-yourself)
3. [Prerequisites](#prerequisites)
4. [Steps](#steps)
5. [Commands Used](#commands-used)
6. [Notes](#notes)
7. [Disclaimer](#disclaimer)
8. [License](#license)


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

1. Clone the repository from GitHub.

2. Navigate to the downloaded project directory:

    ```bash
    cd Fix-My-Corrupt-Windows-main
    ```

---

#### Option 2: Manual Download (No Git Required)

1. Go to the GitHub repository page: [GitHub Repository](https://github.com/GioMonci/Fix-My-Corrupt-Windows).

2. Click on the green **Code** button, then select **Download ZIP**.

3. Once the ZIP file is downloaded, extract it to a folder of your choice.

#### Install MinGW Compiler

1. Go on preferred browser and search up MinGW.
   
2. Download from offical website or Souce Forge.
   
3. TBH any C++ compiler should work, i'm just using MinGW.


#### Compile and Run the Program

1. Open project folder in preferred text editor or IDE.

2. Compile source code (added cmake file for ease of use).

3. Profit!


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

## Disclaimer

Use this program at your own risk. The author is not responsible for any potential damage to your system.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
