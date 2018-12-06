#include "executor.h"
#include "bytecode.h"
#include "opcode.h"
#include "vmstring.h"
#include <stdio.h>
#include <string.h>

STATE op_loadarg(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER offset   = bytecode_read_int(program);
    INTEGER position = state.frame_position + offset;
    OBJECT  o        = stack_at(stack, position);

    stack_push(stack, o);

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_call(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER  fun_addr = bytecode_read_ptr(program);
    UINTEGER num_args = bytecode_read_uint(program);

    POINTER return_addr = stream_position(program);

    state.instruction_ptr = fun_addr;
    state.frame_position  = stack_size(stack) - num_args;

    stack_push(stack, object_of_int(num_args));
    stack_push(stack, object_of_ptr(return_addr));
    stack_push(stack, object_of_ptr(state.frame_position));

    return state;
}

STATE op_return(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    OBJECT return_val     = stack_pop(stack);
    state.frame_position  = stack_pop(stack).ptr_val;
    state.instruction_ptr = stack_pop(stack).ptr_val;

    INTEGER num_args = stack_pop(stack).int_val;

    for (int i = 0; i < num_args; i++) {
        stack_pop(stack);
    }

    stack_push(stack, return_val);

    return state;
}

STATE op_halt(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER exit_code = bytecode_read_int(program);

    state.running   = false;
    state.exit_code = exit_code;

    return state;
}

STATE op_print(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    OBJECT o = stack_pop(stack);

    printf("%i\n", o.int_val);

    return state;
}

// Pointer operations
STATE op_ppush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER pointer = bytecode_read_ptr(program);

    stack_push(stack, object_of_ptr(pointer));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_alloc(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG   alloc_size = bytecode_read_ulong(program);
    POINTER ptr        = heap_alloc(heap, alloc_size);

    stack_push(stack, object_of_ptr(ptr));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_dealloc(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER ptr = stack_pop(stack).ptr_val;
    heap_dealloc(heap, ptr);

    return state;
}

// String operations
STATE op_scat(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER dest_ptr = stack_pop(stack).ptr_val;
    POINTER b_ptr    = stack_pop(stack).ptr_val;
    POINTER a_ptr    = stack_pop(stack).ptr_val;

    VMSTRING_HEADER* a_str    = (VMSTRING_HEADER*)heap_at(heap, a_ptr);
    VMSTRING_HEADER* b_str    = (VMSTRING_HEADER*)heap_at(heap, b_ptr);
    VMSTRING_HEADER* dest_str = (VMSTRING_HEADER*)heap_at(heap, dest_ptr);

    vmstring_concat(a_str, b_str, dest_str);

    stack_push(stack, object_of_ptr(dest_ptr));

    return state;
}

STATE op_sprint(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    POINTER str_ptr = stack_pop(stack).ptr_val;

    VMSTRING_HEADER* str = (VMSTRING_HEADER*)heap_at(heap, str_ptr);

    char* data = vmstring_data_ptr(str);
    for (int i = 0; i < str->length; i++) {
        printf("%c", data[i]);
    }

    return state;
}

STATE op_ipush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER value = bytecode_read_int(program);

    stack_push(stack, object_of_int(value));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_iadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a + b));

    return state;
}

STATE op_isub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a - b));

    return state;
}

STATE op_idiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a / b)); // TODO figure out how to handle exceptions (in this case, division by zero)

    return state;
}

STATE op_imul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a * b));

    return state;
}

STATE op_iand(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a & b));

    return state;
}

STATE op_ior(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a | b));

    return state;
}

STATE op_ixor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a ^ b));

    return state;
}

STATE op_inot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(~a));

    return state;
}

STATE op_ilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a << b));

    return state;
}

STATE op_irshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    INTEGER a = stack_pop(stack).int_val;
    INTEGER b = stack_pop(stack).int_val;

    stack_push(stack, object_of_int(a >> b));

    return state;
}

STATE op_uipush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER val = bytecode_read_uint(program);

    stack_push(stack, object_of_uint(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_uiadd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a + b));

    return state;
}

STATE op_uisub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a - b));

    return state;
}

STATE op_uidiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a / b));

    return state;
}

STATE op_uimul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a * b));

    return state;
}

STATE op_uiand(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a & b));

    return state;
}

STATE op_uior(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a | b));

    return state;
}

STATE op_uixor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a ^ b));

    return state;
}

STATE op_uinot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(~a));

    return state;
}

STATE op_uilshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a << b));

    return state;
}

STATE op_uirshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    UINTEGER a = stack_pop(stack).uint_val;
    UINTEGER b = stack_pop(stack).uint_val;

    stack_push(stack, object_of_uint(a >> b));

    return state;
}

STATE op_lpush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG val = bytecode_read_long(program);

    stack_push(stack, object_of_long(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_ladd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a + b));

    return state;
}

STATE op_lsub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a - b));

    return state;
}

STATE op_ldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a / b));

    return state;
}

STATE op_lmul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a * b));

    return state;
}

STATE op_land(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a & b));

    return state;
}

STATE op_lor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a | b));

    return state;
}

STATE op_lxor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a ^ b));

    return state;
}

STATE op_lnot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(~a));

    return state;
}

STATE op_llshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a << b));

    return state;
}

STATE op_lrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    LONG a = stack_pop(stack).long_val;
    LONG b = stack_pop(stack).long_val;

    stack_push(stack, object_of_long(a >> b));

    return state;
}

STATE op_ulpush(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG val = bytecode_read_ulong(program);

    stack_push(stack, object_of_ulong(val));

    state.instruction_ptr = stream_position(program);

    return state;
}

STATE op_uladd(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a + b));

    return state;
}

STATE op_ulsub(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a - b));

    return state;
}

STATE op_uldiv(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a / b));

    return state;
}

STATE op_ulmul(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a * b));

    return state;
}

STATE op_uland(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a & b));

    return state;
}

STATE op_ulor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a | b));

    return state;
}

STATE op_ulxor(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a ^ b));

    return state;
}

STATE op_ulnot(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(~a));

    return state;
}

STATE op_ullshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a << b));

    return state;
}

STATE op_ulrshift(STACK* stack, STREAM* program, HEAP* heap, STATE state)
{
    ULONG a = stack_pop(stack).ulong_val;
    ULONG b = stack_pop(stack).ulong_val;

    stack_push(stack, object_of_ulong(a >> b));

    return state;
}