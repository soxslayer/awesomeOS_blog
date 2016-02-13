#ifndef __BITS__
#define __BITS__

#define _b(b) (1 << (0x1f & (b)))

#define set_bit(i,b) ((i) |= _b(b))
#define clr_bit(i,b) ((i) &= ~_b(b))

#define mask_bits(i,m) ((i) & (m))
#define get_bit(i,b) mask_bits(i, _b(b))
#define bit_set(i,b) (mask_bits(i, _b(b)) != 0)
#define bit_clr(i,b) !bit_set(i,b)

#define while_bits_set(i,m) while(mask_bits(i,m) == m)
#define while_bits_clr(i,m) while(mask_bits(i,m) == 0)

#endif /* __BITS__ */
