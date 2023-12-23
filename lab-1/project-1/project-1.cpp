#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Открываем файл
    PCWSTR filename = L"file.rar";
    HANDLE File = CreateFile(filename, GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (File == INVALID_HANDLE_VALUE)
    {
        cout << "Ошибка создания файла" << endl;
        return 1;
    }

    // Получаем размер файла
    DWORD file = GetFileSize(File, NULL);

    // Читаем содержимое файла в буфер
    vector<unsigned char> buffer(file);
    DWORD bytesRead;
    bool read = ReadFile(File, &buffer, file, &bytesRead, NULL);

    // Выводим содержимое файла
    if (read)
    {
        cout << &buffer << endl;
    }

    // Закрываем файл
    CloseHandle(File);
    return 0;
}
