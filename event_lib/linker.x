ENTRY(_start)
SECTIONS
{
  .text : {
    code = .;
    *(.text.main);
    *(.text)
    *(.rodata)
  }
  .data :
  {
    data = .;
    *(.data)
  } 
  .bss :
  {
    bss = .;
    *(.bss)
  }
  end = .;
}