MEMORY
{
  ddr_ram : ORIGIN = 0x80000000, LENGTH = 256M
}

SECTIONS
{
  .init : { *(.init) } > ddr_ram
  .text : { *(.text) } > ddr_ram
}
