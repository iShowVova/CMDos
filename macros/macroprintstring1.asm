%macro print_string 1
    mov si, %1
    call print_string_function
%endmacro
