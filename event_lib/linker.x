ENTRY(_start)
SECTIONS
{
    .text :
    {
        *(.text.main);
        *(.text*);
    }
    .rodata :
    {
        *(.rodata*);
    }    
    .data :
    {
        *(.data*);
    }
    .bss :
    {
        *(.bss*);
    }    
}