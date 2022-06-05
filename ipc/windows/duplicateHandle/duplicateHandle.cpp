

#include <Windows.h>
#include <iostream>

int main(int argc, char* argv[]) {

	// create a file-mapping object
	// the handle has read/write access.
	HANDLE hFileMapRW = CreateFileMapping(INVALID_HANDLE_VALUE, NULL,
		PAGE_READWRITE, 0, 10240, NULL);
	if (NULL == hFileMapRW) {
		DWORD dwRet = GetLastError();
		printf("err: %d\n", dwRet);
		return -1;
	}

	// create another handle to the file-mapping objet
	// the handle has read-only access.
	HANDLE hFileMapRO = NULL;
	DuplicateHandle(GetCurrentProcess(), hFileMapRW, GetCurrentProcess(),
		&hFileMapRO, FILE_MAP_READ, FALSE, 0);
	if (NULL == hFileMapRO) {
		DWORD dwRet = GetLastError();
		printf("err: %d\n", dwRet);
		return -1;
	}

	// call the function that should only read from the file mapping.
	//ReadFromTheFileMapping(hFileMapRO);

	// close the read-only file-mapping object.
	CloseHandle(hFileMapRO);

	// we can still read/write the file-mapping objetc using hFileMapRW.
	//...

	// when the main code does not access the file mapping anymore.
	// close it
	CloseHandle(hFileMapRW);

	return 0;
}
