
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>


#define BUFFER_SIZE 256
TCHAR szMapFileName[] = L"MyFileMappingName";

int main(int argc, char* argv[])
{
	HANDLE hMapFile = NULL;
	LPCTSTR pBuf = NULL;

	// 1. open file map object
	hMapFile = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, szMapFileName);
	if (NULL == hMapFile) {
		_tprintf(L"Could not open file mapping object (%d).\n", GetLastError());
		return -1;
	}

	// 2. let file map kernel object map to current process address memory pBuf
	// use pBuf read and write data
	pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUFFER_SIZE);
	if (NULL == pBuf) {
		_tprintf(L"Could not map view of file (%d).\n", GetLastError());
		CloseHandle(hMapFile);
		hMapFile = NULL;
		return -1;
	}

	// 3. print receive data
	for (int i = 0; i < _tcslen(pBuf); i++) {
		_tprintf(L"%c", *(pBuf + i));
	}
	printf("\n");

	// 4. unmap file map object
	UnmapViewOfFile(pBuf);

	// 5. close file map object
	CloseHandle(hMapFile);

	int nRet = getchar();
	return 0;
}