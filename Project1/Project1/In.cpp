#include "In.h"
#include "Error.h"
#include <cstdio>

namespace In
{
    IN getin(wchar_t* infile)
    {
        IN in;
        in.size = 0;
        in.lines = 0;
        in.ignor = 0;

        // Инициализируем таблицу проверки
        int codeTable[] = IN_CODE_TABLE;
        for (int i = 0; i < 256; i++)
        {
            in.code[i] = codeTable[i];
        }

        // Открываем файл
        FILE* pFile = nullptr;
        errno_t err = _wfopen_s(&pFile, infile, L"rb");

        if (err != 0 || pFile == nullptr)
        {
            throw ERROR_THROW(110);  // Ошибка 110 - не удалось открыть файл
        }

        // Выделяем память
        in.text = new unsigned char[IN_MAX_LEN_TEXT];
        for (int i = 0; i < IN_MAX_LEN_TEXT; i++) {
            in.text[i] = 0;
        }

        int pos = 0;
        int line = 0;
        int col = 0;

        int ch;
        while ((ch = fgetc(pFile)) != EOF)
        {
            unsigned char uch = static_cast<unsigned char>(ch);
            int code = in.code[uch];

            if (code == IN::F)
            {
                delete[] in.text;
                fclose(pFile);
                throw ERROR_THROW_IN(111, line, col);
            }
            else if (code == IN::I)
            {
                in.ignor++;
            }
            else if (code == IN::T)
            {
                in.text[pos] = uch;
                pos++;
                in.size++;
                if (uch == IN_CODE_ENDL)
                {
                    in.lines++;
                    col = 0;
                }
                else
                {
                    col++;
                }
            }
            else
            {
                // Замена символа
                in.text[pos] = static_cast<unsigned char>(code);
                pos++;
                in.size++;
                col++;
            }
        }

        fclose(pFile);
        return in;
    }
}