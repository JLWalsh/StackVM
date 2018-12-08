#include "exception.h"

EXCEPTION exception_create(EX_CODE code)
{
    EXCEPTION exception;
    exception.code = code;

    return exception;
}
