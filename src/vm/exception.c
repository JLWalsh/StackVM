#include "exception.h"

EXCEPTION exception_init(EX_CODE code)
{
    EXCEPTION exception;
    exception.code = code;

    return exception;
}
