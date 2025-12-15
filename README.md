Base Conversion System

A simple in C++ program for converting numbers between different base systems (e.g., decimal, binary, octal, hexadecimal).
This tool let users easily convert numbers from one numerical base to another using console input.
"Working on giving it a UI if i did forget about it"

📌 Features

Convert numbers between common bases (e.g., binary ↔ decimal ↔ octal ↔ hexadecimal). 

Easy to run in any standard C++ environment. 

Educational tool for understanding number systems and base conversions.

🛠️ How It Works

The program reads a number and its current base from the user, then converts it to a target base using internal algorithms that handle digit-by-digit transformations.

📦 Repository Structure

base-converstion-system/
├── .vscode/                # IDE settings (optional)
├── BCS.cpp                 # Main source file
├── BCS.exe                 # Compiled executable (optional)
├── BCS.obj                 # Object files
├── BCS.pdb                 # Debug info
├── vc140.pdb               # Compiler debug data
└── README.md               # Project documentation    

🧪 Requirements

C++ compiler (e.g., g++, clang++, MSVC)

Works on Windows, macOS, or Linux

🚀 Getting Started

Clone the Repository

git clone https://github.com/kalhub96/base-converstion-system.git
cd base-converstion-system

Build the Project

Using g++ (Linux/macOS/Windows with MinGW):

g++ BCS.cpp -o BaseConversionSystem

Using Microsoft Visual Studio:

Open the project folder in VS

Build using the default configuration

Run the Program

./BaseConversionSystem

or on Windows:

BaseConversionSystem.exe

🧠 Example Usage

Enter the number:
1011
Enter base of input number:
2
Enter the base to convert to:
10
Output:
11

📝 Supported Conversions
From Base To Base
Binary Decimal, Octal, Hexadecimal
Decimal Binary, Octal, Hexadecimal
Octal Binary, Decimal, Hexadecimal
Hexadecimal Binary, Decimal, Octal

Exact supported bases depend on implementation.

💡 Contributing

Contributions are welcome! Some ideas:

Add support for arbitrary bases (base-2 to base-36)

Improve input validation

Add a menu-driven user interface

Write unit tests

📄 License

This project doesn’t currently include a license — consider adding an open-source license (e.g., MIT, Apache 2.0) if you want to encourage reuse.
