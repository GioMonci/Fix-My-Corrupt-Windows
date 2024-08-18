# Fix-My-Corrupt-Windows

My friend Juan Carter always has corrupt Windows files. This little program is designed to fix issues related to corrupt Windows files. 
However, it works under the pretense that System File Checker (SFC) and Deployment Image Servicing, Management (DISM), and Check Disk (CHKDSK) are still functioning on your PC. 
If SFC, DISM, and CHKDSK are themselves corrupt, this program won't be able to help. Run the program and then restart your PC, and all should work like a charm.

## What does this program do?

This program opens CMD as an administrator and runs a series of commands to fix any corrupt files on your Windows machine.

## How to use it?

### Method 1: Using the EXE file

#### Steps:

1. Download the repository as a zip file.
2. Extract the zip file.
3. Open the project folder, then open the subfolder called `EXE`.
4. Run the `FixMyCorruptWindows.exe` file.
5. If your antivirus or Windows flags the file as unsafe, you can click "More info" and choose "Run anyway".

### Method 2: Compiling the files yourself

#### Steps:

1. Download and install a C++ compiler.
2. Clone this repository or download it as a zip file and extract it.
3. Open the project folder in your C++ development environment.
4. Compile the source code.
5. Run the resulting executable file.

## Commands Used

This program runs the following commands to fix corrupt Windows files:

1. **System File Checker (SFC):**
- Scannow:
  ```
  sfc/scannow
  ```
This scans and repairs corrupted system files.

2. **Deployment Image Servicing and Management (DISM):**
- ScanHealth:
  ```
  dism /online /cleanup-image /scanhealth
  ```
  This checks the health of the Windows image.

- CheckHealth:
  ```
  dism /online /cleanup-image /checkhealth
  ```
  This checks if the Windows image is repairable.

- RestoreHealth:
  ```
  dism /online /cleanup-image /restorehealth
  ```
  This repairs the Windows image.
  
3. **Check Disk (CHKDSK):**
- CheckDisk:
  ```
  chkdsk C: /f /r /x
  ```
Scans your hard drive for file system errors.

## Notes

- Read the instructions in the program thoroughly
- Ensure you run the program with administrative privileges.
- Restart your computer after running the program to apply the changes.
- If you encounter any issues, make sure that SFC and DISM are not corrupted themselves.

## Disclaimer

Use this program at your own risk. The author is not responsible for any potential damage to your system.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
