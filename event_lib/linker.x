ENTRY(_start)
SECTIONS
{
    .text :
    {
        *(.text.main);
        *(.text*);
    }
    .data :
    {
        *(.data*);
    }
}