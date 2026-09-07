#include "Parm.h"
#include "Error.h"
#include <cstring>
#include <cwchar>
#include <stdlib.h>

namespace Parm
{
    PARM getparm(int argc, wchar_t* argv[])
    {
        PARM parm;

        // �������������� ������� ��������
        parm.in[0] = L'\0';
        parm.out[0] = L'\0';
        parm.log[0] = L'\0';

        bool foundIn = false;

        for (int i = 1; i < argc; i++)
        {
            wchar_t* arg = argv[i];

            // ��������� �����
            if (wcslen(arg) >= PARM_MAX_SIZE)
            {
                throw ERROR_THROW(104);
            }

            // ��������� ���� -in:
            if (wcsstr(arg, PARM_IN) == arg)
            {
                foundIn = true;
                wcscpy_s(parm.in, arg + wcslen(PARM_IN));
            }
            // ��������� ���� -out:
            else if (wcsstr(arg, PARM_OUT) == arg)
            {
                wcscpy_s(parm.out, arg + wcslen(PARM_OUT));
            }
            // ��������� ���� -log:
            else if (wcsstr(arg, PARM_LOG) == arg)
            {
                wcscpy_s(parm.log, arg + wcslen(PARM_LOG));
            }
        }

        // ���� -in �� ����� - ������ 100
        if (!foundIn)
        {
            throw ERROR_THROW(100);
        }

        // ��������� �������� �� ��������� ��� -out
        if (wcslen(parm.out) == 0)
        {
            wcscpy_s(parm.out, parm.in);
            wcsncat_s(parm.out, PARM_OUT_DEFAULT_EXT, _TRUNCATE);
        }

        // ��������� �������� �� ��������� ��� -log
        if (wcslen(parm.log) == 0)
        {
            wcscpy_s(parm.log, parm.in);
            wcsncat_s(parm.log, PARM_LOG_DEFAULT_EXT, _TRUNCATE);
        }

        return parm;
    }
}