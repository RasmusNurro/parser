#include <cstdio>
#include "CommandParser.h"

bool parse_command(const char *msg, char *color, uint32_t *duration)
{
    if (msg[0] == 'T' && msg[1] == '\0') {
        return false;
    }
    if (sscanf(msg, "%c,%u", color, duration) == 2) {
        if (*color == 'R' ||
            *color == 'Y' ||
            *color == 'G') {
            return true;
        }
    }
    if ((msg[0] == 'R' ||
         msg[0] == 'Y' ||
         msg[0] == 'G') &&
        msg[1] == '\0') {
        *color = msg[0];
        *duration = 1000;
        return true;
    }
    return false;
}