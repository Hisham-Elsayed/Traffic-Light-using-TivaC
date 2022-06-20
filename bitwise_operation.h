#define Set_Bit(Register,Bit)      Register |= (1<<Bit)

#define Clear_Bit(Register,Bit)    Register &= ~(1<<Bit)

#define Toggle_Bit(Register,Bit)   Register ^= (1<<Bit)

#define Get_Bit(Register,Bit)      ((Register >>Bit) & 1)

#define BIT_IS_SET (Register,Bit)  ((Register & (1<<Bit)))

#define BIT_IS_CLEAR (Register,Bit)  (!(Register & (1<<Bit)))