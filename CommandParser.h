#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <cstdint>

bool parse_command(const char *msg, char *color, uint32_t *duration);

#endif /* COMMAND_PARSER_H */