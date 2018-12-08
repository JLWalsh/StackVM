#ifndef INTEGER_H
#define INTEGER_H

#include "vm.h"

void op_ipush(VM* vm);
void op_iadd(VM* vm);
void op_isub(VM* vm);
void op_idiv(VM* vm);
void op_imul(VM* vm);
void op_iand(VM* vm);
void op_ior(VM* vm);
void op_ixor(VM* vm);
void op_inot(VM* vm);
void op_ilshift(VM* vm);
void op_irshift(VM* vm);

void op_uipush(VM* vm);
void op_uiadd(VM* vm);
void op_uisub(VM* vm);
void op_uidiv(VM* vm);
void op_uimul(VM* vm);
void op_uiand(VM* vm);
void op_uior(VM* vm);
void op_uixor(VM* vm);
void op_uinot(VM* vm);
void op_uilshift(VM* vm);
void op_uirshift(VM* vm);

#endif /* INTEGER_H */
