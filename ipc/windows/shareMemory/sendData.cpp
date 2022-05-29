

#include <Windows.h>
#include <conio.h>
#include <tchar.h>


#define BUFFER_SIZE 256

// 映射文件名，即共享内存的名称
TCHAR szMapFileName[] = L"MyFileMappingName";
TCHAR szSendData[] = L"Message from the send process ABCDEFG.";


int main(int argc, char* argv[])
{
	HANDLE hMapFile = NULL;
	LPCTSTR pBuf = NULL;

	// 1. create a file map kernel object
	// INVALID_HANDLE_VALUE show to create one ipc obejct
	hMapFile = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE,
		0, BUFFER_SIZE, szMapFileName);
	if (NULL == hMapFile) {
		_tprintf(L"Could not create file mapping obejct (%d).\n", GetLastError());
		return -1;
	}

	// 2. let file data map to process address
	pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUFFER_SIZE);
	if (NULL == pBuf) {
		_tprintf(L"Could not map view of file (%d).\n", GetLastError());
		CloseHandle(hMapFile);
		hMapFile = NULL;
		return -1;
	}

	// 3. write to memory
	CopyMemory((void*)pBuf, szSendData, _tcslen(szSendData) * sizeof(TCHAR));
	 int nRet1 = _getch();

	// 4. unmap file data map
	UnmapViewOfFile(pBuf);

	// 5. close file map object
	CloseHandle(hMapFile);

	int nRet2 = _getch();
	return 0;
}


// @see https://www.cnblogs.com/YQ2014/p/9151813.html