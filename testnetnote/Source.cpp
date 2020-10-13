#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#define MODE 0
using namespace std;


int main(int argc, char** argv) {
	if (MODE) {
		system("@echo off");
		system("del encode.exe");

		std::string file;
		std::string file1;
		std::cout << "Enter the file path\n";


		std::cin >> file;
		std::cin >> file1;

		long int size;




		FILE* in;
		fopen_s(&in, file.c_str(), "rb");



		HANDLE hFile;
		std::string result = "encode.exe";
		hFile = CreateFile(result.c_str(),
			GENERIC_WRITE,
			0,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		DWORD dwBytesWritten;

		while (1) {
			char bufer[18443] = "";
			int b = fread(bufer, 1, 18443, in);
			WriteFile(hFile, bufer, b, &dwBytesWritten, NULL);
			cout << bufer << endl;
			if (b < 18443)break;
		}
		WriteFile(hFile, "\n", 1, &dwBytesWritten, NULL);
		FILE* in1;
		DWORD dwBytesWritten1;
		fopen_s(&in1, file1.c_str(), "rb");
		if (file1 != "b") {
			while (1) {
				char bufer[1024] = "";
				int b = fread(bufer, 1, sizeof(bufer), in1);
				WriteFile(hFile, bufer, b, &dwBytesWritten1, NULL);
				cout << bufer << endl;
				if (b < 1024)break;
			}
		}
		CloseHandle(hFile);
		fclose(in);
		fclose(in1);
		return 0;
	}
	else {
		std::string file1;
		std::cout << "Enter the file path\n";
		cin >> file1;
		FILE *in;
		fopen_s(&in,file1.c_str(), "rb");
		int size=0;
		char buffer[18443] = "";
		while (fread(buffer, 1, 18443, in) > 0)  size++; 
		if (buffer[18442] == '2')cout << "DAAAAAAAA";
		system("pause");
		HANDLE hFile;
		std::string result = "decode.exe";
		hFile = CreateFile(result.c_str(),
			GENERIC_WRITE,
			0,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		DWORD dwBytesWritten1;
		WriteFile(hFile, buffer, 18443, &dwBytesWritten1, NULL);
		CloseHandle(hFile);
		///////////////////////////////
		char* buf = new char[size];
		cout << size << "sizeof = " << sizeof(buf)<<endl;
		int relsize=fread(buf, 1, size, in);
		//HANDLE hFile;
		//std::string result = "decode.exe";
		hFile = CreateFile(result.c_str(),
			GENERIC_WRITE,
			0,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		//DWORD dwBytesWritten1;
		WriteFile(hFile, buf, sizeof(buf), &dwBytesWritten1, NULL);

	}
}