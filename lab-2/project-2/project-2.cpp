#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;

int readArchiveContent(const BYTE* buffer, unsigned int bufferSize)
{
    int filesNumber = 0;
    const BYTE RarSignatures[] = { 0x52, 0x61, 0x72, 0x21, 0x1A, 0x07, 0x00 };
    unsigned int fileOffset = sizeof(RarSignatures);
    while (fileOffset < bufferSize)
    {
        const BYTE* currentHeader = buffer + fileOffset;
        const BYTE* headerType = currentHeader + 2;
        unsigned int headerSize = (*(currentHeader + 6) << 8) | *(currentHeader + 5);

        if (*headerType == 0x73)
        {
            // MAIN_HEAD, skip
            fileOffset += headerSize;
            continue;
        }

        if (*headerType == 0x74)
        {
            // FILE_HEAD
            unsigned int fileNameSize = (*(currentHeader + 7 + 20) << 8) | *(currentHeader + 7 + 19);
            const BYTE* fileName = currentHeader + 32;

            for (unsigned int i = 0; i < fileNameSize; i++)
            {
                cout << fileName[i];
            }
            cout << endl;

            filesNumber++;
            unsigned int packSize = (*(currentHeader + 10) << 24) |
                (*(currentHeader + 9) << 16) |
                (*(currentHeader + 8) << 8) |
                *(currentHeader + 7);
            fileOffset += headerSize + packSize;
            continue;
        }

        if (*headerType == 0x7b)
        {
            // End of archive
            break;
        }
    }

    return filesNumber;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const WCHAR* fileName = L"C:\\Users\\ruots\\Downloads\\Example.rar";

    // Открытие файла
    HANDLE hFile = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    // обработка ошибок при открытии файла
    if (hFile == INVALID_HANDLE_VALUE)
    {
        CloseHandle(hFile);
        return -1;
    }

    // Получение размера файла
    DWORD fileSize = GetFileSize(hFile, NULL);
    vector<BYTE> buffer(fileSize);
    DWORD bytesRead;
    bool readOk = ReadFile(hFile, buffer.data(), fileSize, &bytesRead, NULL);

    if (!readOk)
    {
        cout << "Failed to read file" << endl;
        return -1;
    }

    readArchiveContent(buffer.data(), bytesRead);
    CloseHandle(hFile);
    return 0;
}