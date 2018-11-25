#include "constants.h"
#include <stdlib.h>

CONSTANTS constants_create(void* data, ULONG length)
{
    CONSTANTS constants;
    constants.data   = data;
    constants.length = length;

    return constants;
}

void constants_free(CONSTANTS constants)
{
    free(constants.data);
}