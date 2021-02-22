/*
 MB96670 Series I/O register declaration file V01L04
 ALL RIGHTS RESERVED, COPYRIGHT (C) FUJITSU SEMICONDUCTOR LIMITED 2010
 LICENSED MATERIAL - PROGRAM PROPERTY OF FUJITSU SEMICONDUCTOR LIMITED
*/

#ifdef  __IO_NEAR
#ifdef  __IO_FAR
#error "__IO_NEAR and __IO_FAR must not be defined at the same time"
#else
#define ___IOWIDTH __near
#endif
#else
#ifdef __IO_FAR
#define ___IOWIDTH __far
#else                               /* specified by memory model */
#define ___IOWIDTH
#endif
#endif

#ifdef  __IO_DEFINE
#define __IO_EXTERN __io
#define __IO_EXTENDED volatile ___IOWIDTH
#else
#define __IO_EXTERN   extern __io      /* for data, which can have __io */
#define __IO_EXTENDED extern volatile ___IOWIDTH
#endif

typedef unsigned char        __BYTE;
typedef unsigned short       __WORD;
typedef unsigned long        __LWORD;
typedef const unsigned short __WORD_READ;

#define	CONSTANT_0	(0)
#define	CONSTANT_1	(1)
#define	CONSTANT_2	(2)
#define	CONSTANT_3	(3)
#define	CONSTANT_4	(4)
#define	CONSTANT_5	(5)
#define	CONSTANT_6	(6)
#define	CONSTANT_7	(7)
#define	CONSTANT_8	(8)
#define	CONSTANT_9	(9)
#define	CONSTANT_10	(10)
#define	CONSTANT_11	(11)
#define	CONSTANT_12	(12)
#define	CONSTANT_13	(13)
#define	CONSTANT_14	(14)
#define	CONSTANT_15	(15)
#define	CONSTANT_16	(16)
#define	CONSTANT_17	(17)
#define	CONSTANT_18	(18)
#define	CONSTANT_19	(19)
#define	CONSTANT_20	(20)
#define	CONSTANT_21	(21)
#define	CONSTANT_22	(22)
#define	CONSTANT_23	(23)
#define	CONSTANT_24	(24)
#define	CONSTANT_25	(25)
#define	CONSTANT_26	(26)
#define	CONSTANT_27	(27)
#define	CONSTANT_28	(28)
#define	CONSTANT_29	(29)
#define	CONSTANT_30	(30)
#define	CONSTANT_31	(31)
#define	CONSTANT_32	(32)
#define	CONSTANT_33	(33)
#define	CONSTANT_34	(34)
#define	CONSTANT_35	(35)
#define	CONSTANT_36	(36)
#define	CONSTANT_37	(37)
#define	CONSTANT_38	(38)
#define	CONSTANT_39	(39)
#define	CONSTANT_40	(40)
#define	CONSTANT_41	(41)
#define	CONSTANT_42	(42)
#define	CONSTANT_43	(43)
#define	CONSTANT_44	(44)
#define	CONSTANT_45	(45)
#define	CONSTANT_46	(46)
#define	CONSTANT_47	(47)
#define	CONSTANT_48	(48)
#define	CONSTANT_49	(49)
#define	CONSTANT_50	(50)
#define	CONSTANT_51	(51)
#define	CONSTANT_52	(52)
#define	CONSTANT_53	(53)
#define	CONSTANT_54	(54)
#define	CONSTANT_55	(55)
#define	CONSTANT_56	(56)
#define	CONSTANT_57	(57)
#define	CONSTANT_58	(58)
#define	CONSTANT_59	(59)
#define	CONSTANT_60	(60)
#define	CONSTANT_61	(61)
#define	CONSTANT_62	(62)
#define	CONSTANT_63	(63)


#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR00, locate=0x0
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR00STR;

__IO_EXTERN	  PDR00STR	IO_PDR00;
#define	_pdr00		(IO_PDR00)
#define	PDR00		(IO_PDR00.byte)
#define	PDR00_P0  	(IO_PDR00.bit.P0)
#define	PDR00_P1  	(IO_PDR00.bit.P1)
#define	PDR00_P2  	(IO_PDR00.bit.P2)
#define	PDR00_P3  	(IO_PDR00.bit.P3)
#define	PDR00_P4  	(IO_PDR00.bit.P4)
#define	PDR00_P5  	(IO_PDR00.bit.P5)
#define	PDR00_P6  	(IO_PDR00.bit.P6)
#define	PDR00_P7  	(IO_PDR00.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR01, locate=0x1
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR01STR;

__IO_EXTERN	  PDR01STR	IO_PDR01;
#define	_pdr01		(IO_PDR01)
#define	PDR01		(IO_PDR01.byte)
#define	PDR01_P0  	(IO_PDR01.bit.P0)
#define	PDR01_P1  	(IO_PDR01.bit.P1)
#define	PDR01_P2  	(IO_PDR01.bit.P2)
#define	PDR01_P3  	(IO_PDR01.bit.P3)
#define	PDR01_P4  	(IO_PDR01.bit.P4)
#define	PDR01_P5  	(IO_PDR01.bit.P5)
#define	PDR01_P6  	(IO_PDR01.bit.P6)
#define	PDR01_P7  	(IO_PDR01.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR02, locate=0x2
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR02STR;

__IO_EXTERN	  PDR02STR	IO_PDR02;
#define	_pdr02		(IO_PDR02)
#define	PDR02		(IO_PDR02.byte)
#define	PDR02_P0  	(IO_PDR02.bit.P0)
#define	PDR02_P1  	(IO_PDR02.bit.P1)
#define	PDR02_P2  	(IO_PDR02.bit.P2)
#define	PDR02_P3  	(IO_PDR02.bit.P3)
#define	PDR02_P4  	(IO_PDR02.bit.P4)
#define	PDR02_P5  	(IO_PDR02.bit.P5)
#define	PDR02_P6  	(IO_PDR02.bit.P6)
#define	PDR02_P7  	(IO_PDR02.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR03, locate=0x3
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR03STR;

__IO_EXTERN	  PDR03STR	IO_PDR03;
#define	_pdr03		(IO_PDR03)
#define	PDR03		(IO_PDR03.byte)
#define	PDR03_P0  	(IO_PDR03.bit.P0)
#define	PDR03_P1  	(IO_PDR03.bit.P1)
#define	PDR03_P2  	(IO_PDR03.bit.P2)
#define	PDR03_P3  	(IO_PDR03.bit.P3)
#define	PDR03_P4  	(IO_PDR03.bit.P4)
#define	PDR03_P5  	(IO_PDR03.bit.P5)
#define	PDR03_P6  	(IO_PDR03.bit.P6)
#define	PDR03_P7  	(IO_PDR03.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR04, locate=0x4
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR04STR;

__IO_EXTERN	  PDR04STR	IO_PDR04;
#define	_pdr04		(IO_PDR04)
#define	PDR04		(IO_PDR04.byte)
#define	PDR04_P0  	(IO_PDR04.bit.P0)
#define	PDR04_P1  	(IO_PDR04.bit.P1)
#define	PDR04_P2  	(IO_PDR04.bit.P2)
#define	PDR04_P3  	(IO_PDR04.bit.P3)
#define	PDR04_P4  	(IO_PDR04.bit.P4)
#define	PDR04_P5  	(IO_PDR04.bit.P5)
#define	PDR04_P6  	(IO_PDR04.bit.P6)
#define	PDR04_P7  	(IO_PDR04.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR05, locate=0x5
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR05STR;

__IO_EXTERN	  PDR05STR	IO_PDR05;
#define	_pdr05		(IO_PDR05)
#define	PDR05		(IO_PDR05.byte)
#define	PDR05_P0  	(IO_PDR05.bit.P0)
#define	PDR05_P1  	(IO_PDR05.bit.P1)
#define	PDR05_P2  	(IO_PDR05.bit.P2)
#define	PDR05_P3  	(IO_PDR05.bit.P3)
#define	PDR05_P4  	(IO_PDR05.bit.P4)
#define	PDR05_P5  	(IO_PDR05.bit.P5)
#define	PDR05_P6  	(IO_PDR05.bit.P6)
#define	PDR05_P7  	(IO_PDR05.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR06, locate=0x6
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR06STR;

__IO_EXTERN	  PDR06STR	IO_PDR06;
#define	_pdr06		(IO_PDR06)
#define	PDR06		(IO_PDR06.byte)
#define	PDR06_P0  	(IO_PDR06.bit.P0)
#define	PDR06_P1  	(IO_PDR06.bit.P1)
#define	PDR06_P2  	(IO_PDR06.bit.P2)
#define	PDR06_P3  	(IO_PDR06.bit.P3)
#define	PDR06_P4  	(IO_PDR06.bit.P4)
#define	PDR06_P5  	(IO_PDR06.bit.P5)
#define	PDR06_P6  	(IO_PDR06.bit.P6)
#define	PDR06_P7  	(IO_PDR06.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR08, locate=0x8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR08STR;

__IO_EXTERN	  PDR08STR	IO_PDR08;
#define	_pdr08		(IO_PDR08)
#define	PDR08		(IO_PDR08.byte)
#define	PDR08_P0  	(IO_PDR08.bit.P0)
#define	PDR08_P1  	(IO_PDR08.bit.P1)
#define	PDR08_P2  	(IO_PDR08.bit.P2)
#define	PDR08_P3  	(IO_PDR08.bit.P3)
#define	PDR08_P4  	(IO_PDR08.bit.P4)
#define	PDR08_P5  	(IO_PDR08.bit.P5)
#define	PDR08_P6  	(IO_PDR08.bit.P6)
#define	PDR08_P7  	(IO_PDR08.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR11, locate=0xB
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR11STR;

__IO_EXTERN	  PDR11STR	IO_PDR11;
#define	_pdr11		(IO_PDR11)
#define	PDR11		(IO_PDR11.byte)
#define	PDR11_P0  	(IO_PDR11.bit.P0)
#define	PDR11_P1  	(IO_PDR11.bit.P1)
#define	PDR11_P2  	(IO_PDR11.bit.P2)
#define	PDR11_P3  	(IO_PDR11.bit.P3)
#define	PDR11_P4  	(IO_PDR11.bit.P4)
#define	PDR11_P5  	(IO_PDR11.bit.P5)
#define	PDR11_P6  	(IO_PDR11.bit.P6)
#define	PDR11_P7  	(IO_PDR11.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR12, locate=0xC
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR12STR;

__IO_EXTERN	  PDR12STR	IO_PDR12;
#define	_pdr12		(IO_PDR12)
#define	PDR12		(IO_PDR12.byte)
#define	PDR12_P0  	(IO_PDR12.bit.P0)
#define	PDR12_P1  	(IO_PDR12.bit.P1)
#define	PDR12_P2  	(IO_PDR12.bit.P2)
#define	PDR12_P3  	(IO_PDR12.bit.P3)
#define	PDR12_P4  	(IO_PDR12.bit.P4)
#define	PDR12_P5  	(IO_PDR12.bit.P5)
#define	PDR12_P6  	(IO_PDR12.bit.P6)
#define	PDR12_P7  	(IO_PDR12.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR13, locate=0xD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR13STR;

__IO_EXTERN	  PDR13STR	IO_PDR13;
#define	_pdr13		(IO_PDR13)
#define	PDR13		(IO_PDR13.byte)
#define	PDR13_P0  	(IO_PDR13.bit.P0)
#define	PDR13_P1  	(IO_PDR13.bit.P1)
#define	PDR13_P2  	(IO_PDR13.bit.P2)
#define	PDR13_P3  	(IO_PDR13.bit.P3)
#define	PDR13_P4  	(IO_PDR13.bit.P4)
#define	PDR13_P5  	(IO_PDR13.bit.P5)
#define	PDR13_P6  	(IO_PDR13.bit.P6)
#define	PDR13_P7  	(IO_PDR13.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDR17, locate=0x11
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	P7:1;
			__BYTE	P6:1;
			__BYTE	P5:1;
			__BYTE	P4:1;
			__BYTE	P3:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
#else
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	P3:1;
			__BYTE	P4:1;
			__BYTE	P5:1;
			__BYTE	P6:1;
			__BYTE	P7:1;
#endif
	} bitc;
} PDR17STR;

__IO_EXTERN	  PDR17STR	IO_PDR17;
#define	_pdr17		(IO_PDR17)
#define	PDR17		(IO_PDR17.byte)
#define	PDR17_P0  	(IO_PDR17.bit.P0)
#define	PDR17_P1  	(IO_PDR17.bit.P1)
#define	PDR17_P2  	(IO_PDR17.bit.P2)
#define	PDR17_P3  	(IO_PDR17.bit.P3)
#define	PDR17_P4  	(IO_PDR17.bit.P4)
#define	PDR17_P5  	(IO_PDR17.bit.P5)
#define	PDR17_P6  	(IO_PDR17.bit.P6)
#define	PDR17_P7  	(IO_PDR17.bit.P7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADCSL, locate=0x18
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD:2;
			__BYTE	S10:1;
			__BYTE	CSEN:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CSEN:1;
			__BYTE	S10:1;
			__BYTE	MD:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD1:1;
			__BYTE	MD0:1;
			__BYTE	S10:1;
			__BYTE	CSEN:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CSEN:1;
			__BYTE	S10:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
#endif
	} bitc;
} ADCSLSTR;

__IO_EXTERN	  ADCSLSTR	IO_ADCSL;
#define	_adcsl		(IO_ADCSL)
#define	ADCSL		(IO_ADCSL.byte)
#define	ADCSL_CSEN  	(IO_ADCSL.bit.CSEN)
#define	ADCSL_S10  	(IO_ADCSL.bit.S10)
#define	ADCSL_MD  	(IO_ADCSL.bit.MD)
#define	ADCSL_MD0  	(IO_ADCSL.bitc.MD0)
#define	ADCSL_MD1  	(IO_ADCSL.bitc.MD1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADCSH, locate=0x19
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BUSY:1;
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	PAUS:1;
			__BYTE	STS:2;
			__BYTE	STRT:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	STRT:1;
			__BYTE	STS:2;
			__BYTE	PAUS:1;
			__BYTE	INTE:1;
			__BYTE	INT:1;
			__BYTE	BUSY:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BUSY:1;
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	PAUS:1;
			__BYTE	STS1:1;
			__BYTE	STS0:1;
			__BYTE	STRT:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	STRT:1;
			__BYTE	STS0:1;
			__BYTE	STS1:1;
			__BYTE	PAUS:1;
			__BYTE	INTE:1;
			__BYTE	INT:1;
			__BYTE	BUSY:1;
#endif
	} bitc;
} ADCSHSTR;

__IO_EXTERN	  ADCSHSTR	IO_ADCSH;
#define	_adcsh		(IO_ADCSH)
#define	ADCSH		(IO_ADCSH.byte)
#define	ADCSH_STRT  	(IO_ADCSH.bit.STRT)
#define	ADCSH_STS  	(IO_ADCSH.bit.STS)
#define	ADCSH_STS0  	(IO_ADCSH.bitc.STS0)
#define	ADCSH_STS1  	(IO_ADCSH.bitc.STS1)
#define	ADCSH_PAUS  	(IO_ADCSH.bit.PAUS)
#define	ADCSH_INTE  	(IO_ADCSH.bit.INTE)
#define	ADCSH_INT  	(IO_ADCSH.bit.INT)
#define	ADCSH_BUSY  	(IO_ADCSH.bit.BUSY)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADCRLH, locate=0x1A
#endif

__IO_EXTERN	const	union {
	__WORD	word;
	__BYTE	DATA8;
	__WORD	DATA10;
} IO_ADCRLH;

#define	ADCRLH		(IO_ADCRLH.word)
#define	ADCRLH_DATA8	(IO_ADCRLH.DATA8)
#define	ADCRLH_DATA10	(IO_ADCRLH.DATA10)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ADSR, locate=0x1C
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ST:3;
			__WORD	CT:3;
			__WORD	ANS:5;
			__WORD	ANE:5;
#else
			__WORD	ANE:5;
			__WORD	ANS:5;
			__WORD	CT:3;
			__WORD	ST:3;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ST2:1;
			__WORD	ST1:1;
			__WORD	ST0:1;
			__WORD	CT2:1;
			__WORD	CT1:1;
			__WORD	CT0:1;
			__WORD	ANS4:1;
			__WORD	ANS3:1;
			__WORD	ANS2:1;
			__WORD	ANS1:1;
			__WORD	ANS0:1;
			__WORD	ANE4:1;
			__WORD	ANE3:1;
			__WORD	ANE2:1;
			__WORD	ANE1:1;
			__WORD	ANE0:1;
#else
			__WORD	ANE0:1;
			__WORD	ANE1:1;
			__WORD	ANE2:1;
			__WORD	ANE3:1;
			__WORD	ANE4:1;
			__WORD	ANS0:1;
			__WORD	ANS1:1;
			__WORD	ANS2:1;
			__WORD	ANS3:1;
			__WORD	ANS4:1;
			__WORD	CT0:1;
			__WORD	CT1:1;
			__WORD	CT2:1;
			__WORD	ST0:1;
			__WORD	ST1:1;
			__WORD	ST2:1;
#endif
	} bitc;
} ADSRSTR;

__IO_EXTERN	  ADSRSTR	IO_ADSR;
#define	_adsr		(IO_ADSR)
#define	ADSR		(IO_ADSR.word)
#define	ADSR_ANE  	(IO_ADSR.bit.ANE)
#define	ADSR_ANE0  	(IO_ADSR.bitc.ANE0)
#define	ADSR_ANE1  	(IO_ADSR.bitc.ANE1)
#define	ADSR_ANE2  	(IO_ADSR.bitc.ANE2)
#define	ADSR_ANE3  	(IO_ADSR.bitc.ANE3)
#define	ADSR_ANE4  	(IO_ADSR.bitc.ANE4)
#define	ADSR_ANS  	(IO_ADSR.bit.ANS)
#define	ADSR_ANS0  	(IO_ADSR.bitc.ANS0)
#define	ADSR_ANS1  	(IO_ADSR.bitc.ANS1)
#define	ADSR_ANS2  	(IO_ADSR.bitc.ANS2)
#define	ADSR_ANS3  	(IO_ADSR.bitc.ANS3)
#define	ADSR_ANS4  	(IO_ADSR.bitc.ANS4)
#define	ADSR_CT  	(IO_ADSR.bit.CT)
#define	ADSR_CT0  	(IO_ADSR.bitc.CT0)
#define	ADSR_CT1  	(IO_ADSR.bitc.CT1)
#define	ADSR_CT2  	(IO_ADSR.bitc.CT2)
#define	ADSR_ST  	(IO_ADSR.bit.ST)
#define	ADSR_ST0  	(IO_ADSR.bitc.ST0)
#define	ADSR_ST1  	(IO_ADSR.bitc.ST1)
#define	ADSR_ST2  	(IO_ADSR.bitc.ST2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCDT0, locate=0x20
#endif

__IO_EXTERN	__WORD	IO_TCDT0;
#define	_tcdt0		(IO_TCDT0)
#define	TCDT0	(_tcdt0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCCS0, locate=0x22
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ECKE:1;
			__WORD	FSEL:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	IVF:1;
			__WORD	IVFE:1;
			__WORD	STOP:1;
			__WORD	MODE:1;
			__WORD	CLR:1;
			__WORD	CLK:3;
#else
			__WORD	CLK:3;
			__WORD	CLR:1;
			__WORD	MODE:1;
			__WORD	STOP:1;
			__WORD	IVFE:1;
			__WORD	IVF:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	FSEL:1;
			__WORD	ECKE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ECKE:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	IVF:1;
			__WORD	IVFE:1;
			__WORD	STOP:1;
			__WORD	MODE:1;
			__WORD	CLR:1;
			__WORD	CLK2:1;
			__WORD	CLK1:1;
			__WORD	CLK0:1;
#else
			__WORD	CLK0:1;
			__WORD	CLK1:1;
			__WORD	CLK2:1;
			__WORD	CLR:1;
			__WORD	MODE:1;
			__WORD	STOP:1;
			__WORD	IVFE:1;
			__WORD	IVF:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	ECKE:1;
#endif
	} bitc;
} TCCS0STR;

__IO_EXTERN	  TCCS0STR	IO_TCCS0;
#define	_tccs0		(IO_TCCS0)
#define	TCCS0		(IO_TCCS0.word)
#define	TCCS0_CLK  	(IO_TCCS0.bit.CLK)
#define	TCCS0_CLK0  	(IO_TCCS0.bitc.CLK0)
#define	TCCS0_CLK1  	(IO_TCCS0.bitc.CLK1)
#define	TCCS0_CLK2  	(IO_TCCS0.bitc.CLK2)
#define	TCCS0_CLR  	(IO_TCCS0.bit.CLR)
#define	TCCS0_MODE  	(IO_TCCS0.bit.MODE)
#define	TCCS0_STOP  	(IO_TCCS0.bit.STOP)
#define	TCCS0_IVFE  	(IO_TCCS0.bit.IVFE)
#define	TCCS0_IVF  	(IO_TCCS0.bit.IVF)
#define	TCCS0_FSEL  	(IO_TCCS0.bit.FSEL)
#define	TCCS0_ECKE  	(IO_TCCS0.bit.ECKE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCDT1, locate=0x24
#endif

__IO_EXTERN	__WORD	IO_TCDT1;
#define	_tcdt1		(IO_TCDT1)
#define	TCDT1	(_tcdt1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TCCS1, locate=0x26
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ECKE:1;
			__WORD	FSEL:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	IVF:1;
			__WORD	IVFE:1;
			__WORD	STOP:1;
			__WORD	MODE:1;
			__WORD	CLR:1;
			__WORD	CLK:3;
#else
			__WORD	CLK:3;
			__WORD	CLR:1;
			__WORD	MODE:1;
			__WORD	STOP:1;
			__WORD	IVFE:1;
			__WORD	IVF:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	FSEL:1;
			__WORD	ECKE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ECKE:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	IVF:1;
			__WORD	IVFE:1;
			__WORD	STOP:1;
			__WORD	MODE:1;
			__WORD	CLR:1;
			__WORD	CLK2:1;
			__WORD	CLK1:1;
			__WORD	CLK0:1;
#else
			__WORD	CLK0:1;
			__WORD	CLK1:1;
			__WORD	CLK2:1;
			__WORD	CLR:1;
			__WORD	MODE:1;
			__WORD	STOP:1;
			__WORD	IVFE:1;
			__WORD	IVF:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	ECKE:1;
#endif
	} bitc;
} TCCS1STR;

__IO_EXTERN	  TCCS1STR	IO_TCCS1;
#define	_tccs1		(IO_TCCS1)
#define	TCCS1		(IO_TCCS1.word)
#define	TCCS1_CLK  	(IO_TCCS1.bit.CLK)
#define	TCCS1_CLK0  	(IO_TCCS1.bitc.CLK0)
#define	TCCS1_CLK1  	(IO_TCCS1.bitc.CLK1)
#define	TCCS1_CLK2  	(IO_TCCS1.bitc.CLK2)
#define	TCCS1_CLR  	(IO_TCCS1.bit.CLR)
#define	TCCS1_MODE  	(IO_TCCS1.bit.MODE)
#define	TCCS1_STOP  	(IO_TCCS1.bit.STOP)
#define	TCCS1_IVFE  	(IO_TCCS1.bit.IVFE)
#define	TCCS1_IVF  	(IO_TCCS1.bit.IVF)
#define	TCCS1_FSEL  	(IO_TCCS1.bit.FSEL)
#define	TCCS1_ECKE  	(IO_TCCS1.bit.ECKE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ICS01, locate=0x40
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP1:1;
			__BYTE	ICP0:1;
			__BYTE	ICE1:1;
			__BYTE	ICE0:1;
			__BYTE	EG1:2;
			__BYTE	EG0:2;
#else
			__BYTE	EG0:2;
			__BYTE	EG1:2;
			__BYTE	ICE0:1;
			__BYTE	ICE1:1;
			__BYTE	ICP0:1;
			__BYTE	ICP1:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP1:1;
			__BYTE	ICP0:1;
			__BYTE	ICE1:1;
			__BYTE	ICE0:1;
			__BYTE	EG11:1;
			__BYTE	EG10:1;
			__BYTE	EG01:1;
			__BYTE	EG00:1;
#else
			__BYTE	EG00:1;
			__BYTE	EG01:1;
			__BYTE	EG10:1;
			__BYTE	EG11:1;
			__BYTE	ICE0:1;
			__BYTE	ICE1:1;
			__BYTE	ICP0:1;
			__BYTE	ICP1:1;
#endif
	} bitc;
} ICS01STR;

__IO_EXTERN	  ICS01STR	IO_ICS01;
#define	_ics01		(IO_ICS01)
#define	ICS01		(IO_ICS01.byte)
#define	ICS01_EG0  	(IO_ICS01.bit.EG0)
#define	ICS01_EG00  	(IO_ICS01.bitc.EG00)
#define	ICS01_EG01  	(IO_ICS01.bitc.EG01)
#define	ICS01_EG1  	(IO_ICS01.bit.EG1)
#define	ICS01_EG10  	(IO_ICS01.bitc.EG10)
#define	ICS01_EG11  	(IO_ICS01.bitc.EG11)
#define	ICS01_ICE0  	(IO_ICS01.bit.ICE0)
#define	ICS01_ICE1  	(IO_ICS01.bit.ICE1)
#define	ICS01_ICP0  	(IO_ICS01.bit.ICP0)
#define	ICS01_ICP1  	(IO_ICS01.bit.ICP1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ICE01, locate=0x41
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS0:1;
			__BYTE	IEI1:1;
			__BYTE	IEI0:1;
#else
			__BYTE	IEI0:1;
			__BYTE	IEI1:1;
			__BYTE	ICUS0:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS0:1;
			__BYTE	IEI1:1;
			__BYTE	IEI0:1;
#else
			__BYTE	IEI0:1;
			__BYTE	IEI1:1;
			__BYTE	ICUS0:1;
			__BYTE	RESV3:1;
			__BYTE	ICUS1:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ICE01STR;

__IO_EXTERN	  ICE01STR	IO_ICE01;
#define	_ice01		(IO_ICE01)
#define	ICE01		(IO_ICE01.byte)
#define	ICE01_IEI0  	(IO_ICE01.bit.IEI0)
#define	ICE01_IEI1  	(IO_ICE01.bit.IEI1)
#define	ICE01_ICUS0  	(IO_ICE01.bit.ICUS0)
#define	ICE01_ICUS1  	(IO_ICE01.bit.ICUS1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IPCP0, locate=0x42
#endif

__IO_EXTERN	const __WORD	IO_IPCP0;
#define	_ipcp0		(IO_IPCP0)
#define	IPCP0	(_ipcp0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IPCP1, locate=0x44
#endif

__IO_EXTERN	const __WORD	IO_IPCP1;
#define	_ipcp1		(IO_IPCP1)
#define	IPCP1	(_ipcp1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ICS45, locate=0x4C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP5:1;
			__BYTE	ICP4:1;
			__BYTE	ICE5:1;
			__BYTE	ICE4:1;
			__BYTE	EG5:2;
			__BYTE	EG4:2;
#else
			__BYTE	EG4:2;
			__BYTE	EG5:2;
			__BYTE	ICE4:1;
			__BYTE	ICE5:1;
			__BYTE	ICP4:1;
			__BYTE	ICP5:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ICP5:1;
			__BYTE	ICP4:1;
			__BYTE	ICE5:1;
			__BYTE	ICE4:1;
			__BYTE	EG51:1;
			__BYTE	EG50:1;
			__BYTE	EG41:1;
			__BYTE	EG40:1;
#else
			__BYTE	EG40:1;
			__BYTE	EG41:1;
			__BYTE	EG50:1;
			__BYTE	EG51:1;
			__BYTE	ICE4:1;
			__BYTE	ICE5:1;
			__BYTE	ICP4:1;
			__BYTE	ICP5:1;
#endif
	} bitc;
} ICS45STR;

__IO_EXTERN	  ICS45STR	IO_ICS45;
#define	_ics45		(IO_ICS45)
#define	ICS45		(IO_ICS45.byte)
#define	ICS45_EG4  	(IO_ICS45.bit.EG4)
#define	ICS45_EG40  	(IO_ICS45.bitc.EG40)
#define	ICS45_EG41  	(IO_ICS45.bitc.EG41)
#define	ICS45_EG5  	(IO_ICS45.bit.EG5)
#define	ICS45_EG50  	(IO_ICS45.bitc.EG50)
#define	ICS45_EG51  	(IO_ICS45.bitc.EG51)
#define	ICS45_ICE4  	(IO_ICS45.bit.ICE4)
#define	ICS45_ICE5  	(IO_ICS45.bit.ICE5)
#define	ICS45_ICP4  	(IO_ICS45.bit.ICP4)
#define	ICS45_ICP5  	(IO_ICS45.bit.ICP5)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ICE45, locate=0x4D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	IEI5:1;
			__BYTE	IEI4:1;
#else
			__BYTE	IEI4:1;
			__BYTE	IEI5:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	IEI5:1;
			__BYTE	IEI4:1;
#else
			__BYTE	IEI4:1;
			__BYTE	IEI5:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ICE45STR;

__IO_EXTERN	  ICE45STR	IO_ICE45;
#define	_ice45		(IO_ICE45)
#define	ICE45		(IO_ICE45.byte)
#define	ICE45_IEI4  	(IO_ICE45.bit.IEI4)
#define	ICE45_IEI5  	(IO_ICE45.bit.IEI5)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IPCP4, locate=0x4E
#endif

__IO_EXTERN	const __WORD	IO_IPCP4;
#define	_ipcp4		(IO_IPCP4)
#define	IPCP4	(_ipcp4)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IPCP5, locate=0x50
#endif

__IO_EXTERN	const __WORD	IO_IPCP5;
#define	_ipcp5		(IO_IPCP5)
#define	IPCP5	(_ipcp5)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ENIR0, locate=0x58
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	EN7:1;
			__BYTE	EN6:1;
			__BYTE	EN5:1;
			__BYTE	EN4:1;
			__BYTE	EN3:1;
			__BYTE	EN2:1;
			__BYTE	EN1:1;
			__BYTE	EN0:1;
#else
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	EN3:1;
			__BYTE	EN4:1;
			__BYTE	EN5:1;
			__BYTE	EN6:1;
			__BYTE	EN7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	EN7:1;
			__BYTE	EN6:1;
			__BYTE	EN5:1;
			__BYTE	EN4:1;
			__BYTE	EN3:1;
			__BYTE	EN2:1;
			__BYTE	EN1:1;
			__BYTE	EN0:1;
#else
			__BYTE	EN0:1;
			__BYTE	EN1:1;
			__BYTE	EN2:1;
			__BYTE	EN3:1;
			__BYTE	EN4:1;
			__BYTE	EN5:1;
			__BYTE	EN6:1;
			__BYTE	EN7:1;
#endif
	} bitc;
} ENIR0STR;

__IO_EXTERN	  ENIR0STR	IO_ENIR0;
#define	_enir0		(IO_ENIR0)
#define	ENIR0		(IO_ENIR0.byte)
#define	ENIR0_EN0  	(IO_ENIR0.bit.EN0)
#define	ENIR0_EN1  	(IO_ENIR0.bit.EN1)
#define	ENIR0_EN2  	(IO_ENIR0.bit.EN2)
#define	ENIR0_EN3  	(IO_ENIR0.bit.EN3)
#define	ENIR0_EN4  	(IO_ENIR0.bit.EN4)
#define	ENIR0_EN5  	(IO_ENIR0.bit.EN5)
#define	ENIR0_EN6  	(IO_ENIR0.bit.EN6)
#define	ENIR0_EN7  	(IO_ENIR0.bit.EN7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_EIRR0, locate=0x59
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ER7:1;
			__BYTE	ER6:1;
			__BYTE	ER5:1;
			__BYTE	ER4:1;
			__BYTE	ER3:1;
			__BYTE	ER2:1;
			__BYTE	ER1:1;
			__BYTE	ER0:1;
#else
			__BYTE	ER0:1;
			__BYTE	ER1:1;
			__BYTE	ER2:1;
			__BYTE	ER3:1;
			__BYTE	ER4:1;
			__BYTE	ER5:1;
			__BYTE	ER6:1;
			__BYTE	ER7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ER7:1;
			__BYTE	ER6:1;
			__BYTE	ER5:1;
			__BYTE	ER4:1;
			__BYTE	ER3:1;
			__BYTE	ER2:1;
			__BYTE	ER1:1;
			__BYTE	ER0:1;
#else
			__BYTE	ER0:1;
			__BYTE	ER1:1;
			__BYTE	ER2:1;
			__BYTE	ER3:1;
			__BYTE	ER4:1;
			__BYTE	ER5:1;
			__BYTE	ER6:1;
			__BYTE	ER7:1;
#endif
	} bitc;
} EIRR0STR;

__IO_EXTERN	  EIRR0STR	IO_EIRR0;
#define	_eirr0		(IO_EIRR0)
#define	EIRR0		(IO_EIRR0.byte)
#define	EIRR0_ER0  	(IO_EIRR0.bit.ER0)
#define	EIRR0_ER1  	(IO_EIRR0.bit.ER1)
#define	EIRR0_ER2  	(IO_EIRR0.bit.ER2)
#define	EIRR0_ER3  	(IO_EIRR0.bit.ER3)
#define	EIRR0_ER4  	(IO_EIRR0.bit.ER4)
#define	EIRR0_ER5  	(IO_EIRR0.bit.ER5)
#define	EIRR0_ER6  	(IO_EIRR0.bit.ER6)
#define	EIRR0_ER7  	(IO_EIRR0.bit.ER7)

#ifdef __IO_DEFINE
#pragma segment IO=IO_ELVR0, locate=0x5A
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	LALB7:2;
			__WORD	LALB6:2;
			__WORD	LALB5:2;
			__WORD	LALB4:2;
			__WORD	LALB3:2;
			__WORD	LALB2:2;
			__WORD	LALB1:2;
			__WORD	LALB0:2;
#else
			__WORD	LALB0:2;
			__WORD	LALB1:2;
			__WORD	LALB2:2;
			__WORD	LALB3:2;
			__WORD	LALB4:2;
			__WORD	LALB5:2;
			__WORD	LALB6:2;
			__WORD	LALB7:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	LALB71:1;
			__WORD	LALB70:1;
			__WORD	LALB61:1;
			__WORD	LALB60:1;
			__WORD	LALB51:1;
			__WORD	LALB50:1;
			__WORD	LALB41:1;
			__WORD	LALB40:1;
			__WORD	LALB31:1;
			__WORD	LALB30:1;
			__WORD	LALB21:1;
			__WORD	LALB20:1;
			__WORD	LALB11:1;
			__WORD	LALB10:1;
			__WORD	LALB01:1;
			__WORD	LALB00:1;
#else
			__WORD	LALB00:1;
			__WORD	LALB01:1;
			__WORD	LALB10:1;
			__WORD	LALB11:1;
			__WORD	LALB20:1;
			__WORD	LALB21:1;
			__WORD	LALB30:1;
			__WORD	LALB31:1;
			__WORD	LALB40:1;
			__WORD	LALB41:1;
			__WORD	LALB50:1;
			__WORD	LALB51:1;
			__WORD	LALB60:1;
			__WORD	LALB61:1;
			__WORD	LALB70:1;
			__WORD	LALB71:1;
#endif
	} bitc;
} ELVR0STR;

__IO_EXTERN	  ELVR0STR	IO_ELVR0;
#define	_elvr0		(IO_ELVR0)
#define	ELVR0		(IO_ELVR0.word)
#define	ELVR0_LALB0  	(IO_ELVR0.bit.LALB0)
#define	ELVR0_LALB00  	(IO_ELVR0.bitc.LALB00)
#define	ELVR0_LALB01  	(IO_ELVR0.bitc.LALB01)
#define	ELVR0_LALB1  	(IO_ELVR0.bit.LALB1)
#define	ELVR0_LALB10  	(IO_ELVR0.bitc.LALB10)
#define	ELVR0_LALB11  	(IO_ELVR0.bitc.LALB11)
#define	ELVR0_LALB2  	(IO_ELVR0.bit.LALB2)
#define	ELVR0_LALB20  	(IO_ELVR0.bitc.LALB20)
#define	ELVR0_LALB21  	(IO_ELVR0.bitc.LALB21)
#define	ELVR0_LALB3  	(IO_ELVR0.bit.LALB3)
#define	ELVR0_LALB30  	(IO_ELVR0.bitc.LALB30)
#define	ELVR0_LALB31  	(IO_ELVR0.bitc.LALB31)
#define	ELVR0_LALB4  	(IO_ELVR0.bit.LALB4)
#define	ELVR0_LALB40  	(IO_ELVR0.bitc.LALB40)
#define	ELVR0_LALB41  	(IO_ELVR0.bitc.LALB41)
#define	ELVR0_LALB5  	(IO_ELVR0.bit.LALB5)
#define	ELVR0_LALB50  	(IO_ELVR0.bitc.LALB50)
#define	ELVR0_LALB51  	(IO_ELVR0.bitc.LALB51)
#define	ELVR0_LALB6  	(IO_ELVR0.bit.LALB6)
#define	ELVR0_LALB60  	(IO_ELVR0.bitc.LALB60)
#define	ELVR0_LALB61  	(IO_ELVR0.bitc.LALB61)
#define	ELVR0_LALB7  	(IO_ELVR0.bit.LALB7)
#define	ELVR0_LALB70  	(IO_ELVR0.bitc.LALB70)
#define	ELVR0_LALB71  	(IO_ELVR0.bitc.LALB71)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSR1, locate=0x64
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV10:1;
			__WORD	FSEL:1;
			__WORD	CSL:2;
			__WORD	MOD:3;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD:3;
			__WORD	CSL:2;
			__WORD	FSEL:1;
			__WORD	RESV10:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	CSL1:1;
			__WORD	CSL0:1;
			__WORD	MOD2:1;
			__WORD	MOD1:1;
			__WORD	MOD0:1;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD0:1;
			__WORD	MOD1:1;
			__WORD	MOD2:1;
			__WORD	CSL0:1;
			__WORD	CSL1:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bitc;
} TMCSR1STR;

__IO_EXTERN	  TMCSR1STR	IO_TMCSR1;
#define	_tmcsr1		(IO_TMCSR1)
#define	TMCSR1		(IO_TMCSR1.word)
#define	TMCSR1_TRG  	(IO_TMCSR1.bit.TRG)
#define	TMCSR1_CNTE  	(IO_TMCSR1.bit.CNTE)
#define	TMCSR1_UF  	(IO_TMCSR1.bit.UF)
#define	TMCSR1_INTE  	(IO_TMCSR1.bit.INTE)
#define	TMCSR1_RELD  	(IO_TMCSR1.bit.RELD)
#define	TMCSR1_OUTL  	(IO_TMCSR1.bit.OUTL)
#define	TMCSR1_OUTE  	(IO_TMCSR1.bit.OUTE)
#define	TMCSR1_MOD  	(IO_TMCSR1.bit.MOD)
#define	TMCSR1_MOD0  	(IO_TMCSR1.bitc.MOD0)
#define	TMCSR1_MOD1  	(IO_TMCSR1.bitc.MOD1)
#define	TMCSR1_MOD2  	(IO_TMCSR1.bitc.MOD2)
#define	TMCSR1_CSL  	(IO_TMCSR1.bit.CSL)
#define	TMCSR1_CSL0  	(IO_TMCSR1.bitc.CSL0)
#define	TMCSR1_CSL1  	(IO_TMCSR1.bitc.CSL1)
#define	TMCSR1_FSEL  	(IO_TMCSR1.bit.FSEL)
#define	TMCSR1_EN  	(IO_TMCSR1.bit.EN)
#define	TMCSR1_DIN  	(IO_TMCSR1.bit.DIN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMR1, locate=0x66
#endif

__IO_EXTERN	__WORD	IO_TMR1;
#define	_tmr1		(IO_TMR1)
#define	TMR1	(_tmr1)
#define	_tmrlr1		(IO_TMR1)
#define	TMRLR1	(_tmrlr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSR2, locate=0x68
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV10:1;
			__WORD	FSEL:1;
			__WORD	CSL:2;
			__WORD	MOD:3;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD:3;
			__WORD	CSL:2;
			__WORD	FSEL:1;
			__WORD	RESV10:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	CSL1:1;
			__WORD	CSL0:1;
			__WORD	MOD2:1;
			__WORD	MOD1:1;
			__WORD	MOD0:1;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD0:1;
			__WORD	MOD1:1;
			__WORD	MOD2:1;
			__WORD	CSL0:1;
			__WORD	CSL1:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bitc;
} TMCSR2STR;

__IO_EXTERN	  TMCSR2STR	IO_TMCSR2;
#define	_tmcsr2		(IO_TMCSR2)
#define	TMCSR2		(IO_TMCSR2.word)
#define	TMCSR2_TRG  	(IO_TMCSR2.bit.TRG)
#define	TMCSR2_CNTE  	(IO_TMCSR2.bit.CNTE)
#define	TMCSR2_UF  	(IO_TMCSR2.bit.UF)
#define	TMCSR2_INTE  	(IO_TMCSR2.bit.INTE)
#define	TMCSR2_RELD  	(IO_TMCSR2.bit.RELD)
#define	TMCSR2_OUTL  	(IO_TMCSR2.bit.OUTL)
#define	TMCSR2_OUTE  	(IO_TMCSR2.bit.OUTE)
#define	TMCSR2_MOD  	(IO_TMCSR2.bit.MOD)
#define	TMCSR2_MOD0  	(IO_TMCSR2.bitc.MOD0)
#define	TMCSR2_MOD1  	(IO_TMCSR2.bitc.MOD1)
#define	TMCSR2_MOD2  	(IO_TMCSR2.bitc.MOD2)
#define	TMCSR2_CSL  	(IO_TMCSR2.bit.CSL)
#define	TMCSR2_CSL0  	(IO_TMCSR2.bitc.CSL0)
#define	TMCSR2_CSL1  	(IO_TMCSR2.bitc.CSL1)
#define	TMCSR2_FSEL  	(IO_TMCSR2.bit.FSEL)
#define	TMCSR2_EN  	(IO_TMCSR2.bit.EN)
#define	TMCSR2_DIN  	(IO_TMCSR2.bit.DIN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMR2, locate=0x6A
#endif

__IO_EXTERN	__WORD	IO_TMR2;
#define	_tmr2		(IO_TMR2)
#define	TMR2	(_tmr2)
#define	_tmrlr2		(IO_TMR2)
#define	TMRLR2	(_tmrlr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMCSR6, locate=0x70
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV10:1;
			__WORD	FSEL:1;
			__WORD	CSL:2;
			__WORD	MOD:3;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD:3;
			__WORD	CSL:2;
			__WORD	FSEL:1;
			__WORD	RESV10:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	DIN:1;
			__WORD	EN:1;
			__WORD	RESV13:1;
			__WORD	FSEL:1;
			__WORD	CSL1:1;
			__WORD	CSL0:1;
			__WORD	MOD2:1;
			__WORD	MOD1:1;
			__WORD	MOD0:1;
			__WORD	OUTE:1;
			__WORD	OUTL:1;
			__WORD	RELD:1;
			__WORD	INTE:1;
			__WORD	UF:1;
			__WORD	CNTE:1;
			__WORD	TRG:1;
#else
			__WORD	TRG:1;
			__WORD	CNTE:1;
			__WORD	UF:1;
			__WORD	INTE:1;
			__WORD	RELD:1;
			__WORD	OUTL:1;
			__WORD	OUTE:1;
			__WORD	MOD0:1;
			__WORD	MOD1:1;
			__WORD	MOD2:1;
			__WORD	CSL0:1;
			__WORD	CSL1:1;
			__WORD	FSEL:1;
			__WORD	RESV13:1;
			__WORD	EN:1;
			__WORD	DIN:1;
#endif
	} bitc;
} TMCSR6STR;

__IO_EXTERN	  TMCSR6STR	IO_TMCSR6;
#define	_tmcsr6		(IO_TMCSR6)
#define	TMCSR6		(IO_TMCSR6.word)
#define	TMCSR6_TRG  	(IO_TMCSR6.bit.TRG)
#define	TMCSR6_CNTE  	(IO_TMCSR6.bit.CNTE)
#define	TMCSR6_UF  	(IO_TMCSR6.bit.UF)
#define	TMCSR6_INTE  	(IO_TMCSR6.bit.INTE)
#define	TMCSR6_RELD  	(IO_TMCSR6.bit.RELD)
#define	TMCSR6_OUTL  	(IO_TMCSR6.bit.OUTL)
#define	TMCSR6_OUTE  	(IO_TMCSR6.bit.OUTE)
#define	TMCSR6_MOD  	(IO_TMCSR6.bit.MOD)
#define	TMCSR6_MOD0  	(IO_TMCSR6.bitc.MOD0)
#define	TMCSR6_MOD1  	(IO_TMCSR6.bitc.MOD1)
#define	TMCSR6_MOD2  	(IO_TMCSR6.bitc.MOD2)
#define	TMCSR6_CSL  	(IO_TMCSR6.bit.CSL)
#define	TMCSR6_CSL0  	(IO_TMCSR6.bitc.CSL0)
#define	TMCSR6_CSL1  	(IO_TMCSR6.bitc.CSL1)
#define	TMCSR6_FSEL  	(IO_TMCSR6.bit.FSEL)
#define	TMCSR6_EN  	(IO_TMCSR6.bit.EN)
#define	TMCSR6_DIN  	(IO_TMCSR6.bit.DIN)

#ifdef __IO_DEFINE
#pragma segment IO=IO_TMR6, locate=0x72
#endif

__IO_EXTERN	__WORD	IO_TMR6;
#define	_tmr6		(IO_TMR6)
#define	TMR6	(_tmr6)
#define	_tmrlr6		(IO_TMR6)
#define	TMRLR6	(_tmrlr6)

#ifdef __IO_DEFINE
#pragma segment IO=IO_GCN10, locate=0x74
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	TSEL3:4;
			__WORD	TSEL2:4;
			__WORD	TSEL1:4;
			__WORD	TSEL0:4;
#else
			__WORD	TSEL0:4;
			__WORD	TSEL1:4;
			__WORD	TSEL2:4;
			__WORD	TSEL3:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	TSEL33:1;
			__WORD	TSEL32:1;
			__WORD	TSEL31:1;
			__WORD	TSEL30:1;
			__WORD	TSEL23:1;
			__WORD	TSEL22:1;
			__WORD	TSEL21:1;
			__WORD	TSEL20:1;
			__WORD	TSEL13:1;
			__WORD	TSEL12:1;
			__WORD	TSEL11:1;
			__WORD	TSEL10:1;
			__WORD	TSEL03:1;
			__WORD	TSEL02:1;
			__WORD	TSEL01:1;
			__WORD	TSEL00:1;
#else
			__WORD	TSEL00:1;
			__WORD	TSEL01:1;
			__WORD	TSEL02:1;
			__WORD	TSEL03:1;
			__WORD	TSEL10:1;
			__WORD	TSEL11:1;
			__WORD	TSEL12:1;
			__WORD	TSEL13:1;
			__WORD	TSEL20:1;
			__WORD	TSEL21:1;
			__WORD	TSEL22:1;
			__WORD	TSEL23:1;
			__WORD	TSEL30:1;
			__WORD	TSEL31:1;
			__WORD	TSEL32:1;
			__WORD	TSEL33:1;
#endif
	} bitc;
} GCN10STR;

__IO_EXTERN	  GCN10STR	IO_GCN10;
#define	_gcn10		(IO_GCN10)
#define	GCN10		(IO_GCN10.word)
#define	GCN10_TSEL0  	(IO_GCN10.bit.TSEL0)
#define	GCN10_TSEL00  	(IO_GCN10.bitc.TSEL00)
#define	GCN10_TSEL01  	(IO_GCN10.bitc.TSEL01)
#define	GCN10_TSEL02  	(IO_GCN10.bitc.TSEL02)
#define	GCN10_TSEL03  	(IO_GCN10.bitc.TSEL03)
#define	GCN10_TSEL1  	(IO_GCN10.bit.TSEL1)
#define	GCN10_TSEL10  	(IO_GCN10.bitc.TSEL10)
#define	GCN10_TSEL11  	(IO_GCN10.bitc.TSEL11)
#define	GCN10_TSEL12  	(IO_GCN10.bitc.TSEL12)
#define	GCN10_TSEL13  	(IO_GCN10.bitc.TSEL13)
#define	GCN10_TSEL2  	(IO_GCN10.bit.TSEL2)
#define	GCN10_TSEL20  	(IO_GCN10.bitc.TSEL20)
#define	GCN10_TSEL21  	(IO_GCN10.bitc.TSEL21)
#define	GCN10_TSEL22  	(IO_GCN10.bitc.TSEL22)
#define	GCN10_TSEL23  	(IO_GCN10.bitc.TSEL23)
#define	GCN10_TSEL3  	(IO_GCN10.bit.TSEL3)
#define	GCN10_TSEL30  	(IO_GCN10.bitc.TSEL30)
#define	GCN10_TSEL31  	(IO_GCN10.bitc.TSEL31)
#define	GCN10_TSEL32  	(IO_GCN10.bitc.TSEL32)
#define	GCN10_TSEL33  	(IO_GCN10.bitc.TSEL33)

#ifdef __IO_DEFINE
#pragma segment IO=IO_GCN20, locate=0x76
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	CKSEL3:1;
			__WORD	CKSEL2:1;
			__WORD	CKSEL1:1;
			__WORD	CKSEL0:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	EN3:1;
			__WORD	EN2:1;
			__WORD	EN1:1;
			__WORD	EN0:1;
#else
			__WORD	EN0:1;
			__WORD	EN1:1;
			__WORD	EN2:1;
			__WORD	EN3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	CKSEL0:1;
			__WORD	CKSEL1:1;
			__WORD	CKSEL2:1;
			__WORD	CKSEL3:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	CKSEL3:1;
			__WORD	CKSEL2:1;
			__WORD	CKSEL1:1;
			__WORD	CKSEL0:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	EN3:1;
			__WORD	EN2:1;
			__WORD	EN1:1;
			__WORD	EN0:1;
#else
			__WORD	EN0:1;
			__WORD	EN1:1;
			__WORD	EN2:1;
			__WORD	EN3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	CKSEL0:1;
			__WORD	CKSEL1:1;
			__WORD	CKSEL2:1;
			__WORD	CKSEL3:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} GCN20STR;

__IO_EXTERN	  GCN20STR	IO_GCN20;
#define	_gcn20		(IO_GCN20)
#define	GCN20		(IO_GCN20.word)
#define	GCN20_EN0  	(IO_GCN20.bit.EN0)
#define	GCN20_EN1  	(IO_GCN20.bit.EN1)
#define	GCN20_EN2  	(IO_GCN20.bit.EN2)
#define	GCN20_EN3  	(IO_GCN20.bit.EN3)
#define	GCN20_CKSEL0  	(IO_GCN20.bit.CKSEL0)
#define	GCN20_CKSEL1  	(IO_GCN20.bit.CKSEL1)
#define	GCN20_CKSEL2  	(IO_GCN20.bit.CKSEL2)
#define	GCN20_CKSEL3  	(IO_GCN20.bit.CKSEL3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PTMR0, locate=0x78
#endif

__IO_EXTERN	const __WORD	IO_PTMR0;
#define	_ptmr0		(IO_PTMR0)
#define	PTMR0	(_ptmr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCSR0, locate=0x7A
#endif

__IO_EXTERN	__WORD	IO_PCSR0;
#define	_pcsr0		(IO_PCSR0)
#define	PCSR0	(_pcsr0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDUT0, locate=0x7C
#endif

__IO_EXTERN	__WORD	IO_PDUT0;
#define	_pdut0		(IO_PDUT0)
#define	PDUT0	(_pdut0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCN0, locate=0x7E
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS:2;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS:2;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS:2;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS:2;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS:2;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS:2;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS1:1;
			__WORD	CKS0:1;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS1:1;
			__WORD	EGS0:1;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS1:1;
			__WORD	IRS0:1;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS0:1;
			__WORD	IRS1:1;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS0:1;
			__WORD	EGS1:1;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS0:1;
			__WORD	CKS1:1;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bitc;
} PCN0STR;

__IO_EXTERN	  PCN0STR	IO_PCN0;
#define	_pcn0		(IO_PCN0)
#define	PCN0		(IO_PCN0.word)
#define	PCN0_OSEL  	(IO_PCN0.bit.OSEL)
#define	PCN0_OE  	(IO_PCN0.bit.OE)
#define	PCN0_IRS  	(IO_PCN0.bit.IRS)
#define	PCN0_IRS0  	(IO_PCN0.bitc.IRS0)
#define	PCN0_IRS1  	(IO_PCN0.bitc.IRS1)
#define	PCN0_IRQF  	(IO_PCN0.bit.IRQF)
#define	PCN0_IREN  	(IO_PCN0.bit.IREN)
#define	PCN0_EGS  	(IO_PCN0.bit.EGS)
#define	PCN0_EGS0  	(IO_PCN0.bitc.EGS0)
#define	PCN0_EGS1  	(IO_PCN0.bitc.EGS1)
#define	PCN0_MOD  	(IO_PCN0.bit.MOD)
#define	PCN0_PGMS  	(IO_PCN0.bit.PGMS)
#define	PCN0_CKS  	(IO_PCN0.bit.CKS)
#define	PCN0_CKS0  	(IO_PCN0.bitc.CKS0)
#define	PCN0_CKS1  	(IO_PCN0.bitc.CKS1)
#define	PCN0_RTRG  	(IO_PCN0.bit.RTRG)
#define	PCN0_MDSE  	(IO_PCN0.bit.MDSE)
#define	PCN0_STGR  	(IO_PCN0.bit.STGR)
#define	PCN0_CNTE  	(IO_PCN0.bit.CNTE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PTMR1, locate=0x80
#endif

__IO_EXTERN	const __WORD	IO_PTMR1;
#define	_ptmr1		(IO_PTMR1)
#define	PTMR1	(_ptmr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCSR1, locate=0x82
#endif

__IO_EXTERN	__WORD	IO_PCSR1;
#define	_pcsr1		(IO_PCSR1)
#define	PCSR1	(_pcsr1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDUT1, locate=0x84
#endif

__IO_EXTERN	__WORD	IO_PDUT1;
#define	_pdut1		(IO_PDUT1)
#define	PDUT1	(_pdut1)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCN1, locate=0x86
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS:2;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS:2;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS:2;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS:2;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS:2;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS:2;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS1:1;
			__WORD	CKS0:1;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS1:1;
			__WORD	EGS0:1;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS1:1;
			__WORD	IRS0:1;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS0:1;
			__WORD	IRS1:1;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS0:1;
			__WORD	EGS1:1;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS0:1;
			__WORD	CKS1:1;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bitc;
} PCN1STR;

__IO_EXTERN	  PCN1STR	IO_PCN1;
#define	_pcn1		(IO_PCN1)
#define	PCN1		(IO_PCN1.word)
#define	PCN1_OSEL  	(IO_PCN1.bit.OSEL)
#define	PCN1_OE  	(IO_PCN1.bit.OE)
#define	PCN1_IRS  	(IO_PCN1.bit.IRS)
#define	PCN1_IRS0  	(IO_PCN1.bitc.IRS0)
#define	PCN1_IRS1  	(IO_PCN1.bitc.IRS1)
#define	PCN1_IRQF  	(IO_PCN1.bit.IRQF)
#define	PCN1_IREN  	(IO_PCN1.bit.IREN)
#define	PCN1_EGS  	(IO_PCN1.bit.EGS)
#define	PCN1_EGS0  	(IO_PCN1.bitc.EGS0)
#define	PCN1_EGS1  	(IO_PCN1.bitc.EGS1)
#define	PCN1_MOD  	(IO_PCN1.bit.MOD)
#define	PCN1_PGMS  	(IO_PCN1.bit.PGMS)
#define	PCN1_CKS  	(IO_PCN1.bit.CKS)
#define	PCN1_CKS0  	(IO_PCN1.bitc.CKS0)
#define	PCN1_CKS1  	(IO_PCN1.bitc.CKS1)
#define	PCN1_RTRG  	(IO_PCN1.bit.RTRG)
#define	PCN1_MDSE  	(IO_PCN1.bit.MDSE)
#define	PCN1_STGR  	(IO_PCN1.bit.STGR)
#define	PCN1_CNTE  	(IO_PCN1.bit.CNTE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PTMR2, locate=0x88
#endif

__IO_EXTERN	const __WORD	IO_PTMR2;
#define	_ptmr2		(IO_PTMR2)
#define	PTMR2	(_ptmr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCSR2, locate=0x8A
#endif

__IO_EXTERN	__WORD	IO_PCSR2;
#define	_pcsr2		(IO_PCSR2)
#define	PCSR2	(_pcsr2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDUT2, locate=0x8C
#endif

__IO_EXTERN	__WORD	IO_PDUT2;
#define	_pdut2		(IO_PDUT2)
#define	PDUT2	(_pdut2)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCN2, locate=0x8E
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS:2;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS:2;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS:2;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS:2;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS:2;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS:2;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS1:1;
			__WORD	CKS0:1;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS1:1;
			__WORD	EGS0:1;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS1:1;
			__WORD	IRS0:1;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS0:1;
			__WORD	IRS1:1;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS0:1;
			__WORD	EGS1:1;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS0:1;
			__WORD	CKS1:1;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bitc;
} PCN2STR;

__IO_EXTERN	  PCN2STR	IO_PCN2;
#define	_pcn2		(IO_PCN2)
#define	PCN2		(IO_PCN2.word)
#define	PCN2_OSEL  	(IO_PCN2.bit.OSEL)
#define	PCN2_OE  	(IO_PCN2.bit.OE)
#define	PCN2_IRS  	(IO_PCN2.bit.IRS)
#define	PCN2_IRS0  	(IO_PCN2.bitc.IRS0)
#define	PCN2_IRS1  	(IO_PCN2.bitc.IRS1)
#define	PCN2_IRQF  	(IO_PCN2.bit.IRQF)
#define	PCN2_IREN  	(IO_PCN2.bit.IREN)
#define	PCN2_EGS  	(IO_PCN2.bit.EGS)
#define	PCN2_EGS0  	(IO_PCN2.bitc.EGS0)
#define	PCN2_EGS1  	(IO_PCN2.bitc.EGS1)
#define	PCN2_MOD  	(IO_PCN2.bit.MOD)
#define	PCN2_PGMS  	(IO_PCN2.bit.PGMS)
#define	PCN2_CKS  	(IO_PCN2.bit.CKS)
#define	PCN2_CKS0  	(IO_PCN2.bitc.CKS0)
#define	PCN2_CKS1  	(IO_PCN2.bitc.CKS1)
#define	PCN2_RTRG  	(IO_PCN2.bit.RTRG)
#define	PCN2_MDSE  	(IO_PCN2.bit.MDSE)
#define	PCN2_STGR  	(IO_PCN2.bit.STGR)
#define	PCN2_CNTE  	(IO_PCN2.bit.CNTE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PTMR3, locate=0x90
#endif

__IO_EXTERN	const __WORD	IO_PTMR3;
#define	_ptmr3		(IO_PTMR3)
#define	PTMR3	(_ptmr3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCSR3, locate=0x92
#endif

__IO_EXTERN	__WORD	IO_PCSR3;
#define	_pcsr3		(IO_PCSR3)
#define	PCSR3	(_pcsr3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PDUT3, locate=0x94
#endif

__IO_EXTERN	__WORD	IO_PDUT3;
#define	_pdut3		(IO_PDUT3)
#define	PDUT3	(_pdut3)

#ifdef __IO_DEFINE
#pragma segment IO=IO_PCN3, locate=0x96
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS:2;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS:2;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS:2;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS:2;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS:2;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS:2;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	CNTE:1;
			__WORD	STGR:1;
			__WORD	MDSE:1;
			__WORD	RTRG:1;
			__WORD	CKS1:1;
			__WORD	CKS0:1;
			__WORD	PGMS:1;
			__WORD	MOD:1;
			__WORD	EGS1:1;
			__WORD	EGS0:1;
			__WORD	IREN:1;
			__WORD	IRQF:1;
			__WORD	IRS1:1;
			__WORD	IRS0:1;
			__WORD	OE:1;
			__WORD	OSEL:1;
#else
			__WORD	OSEL:1;
			__WORD	OE:1;
			__WORD	IRS0:1;
			__WORD	IRS1:1;
			__WORD	IRQF:1;
			__WORD	IREN:1;
			__WORD	EGS0:1;
			__WORD	EGS1:1;
			__WORD	MOD:1;
			__WORD	PGMS:1;
			__WORD	CKS0:1;
			__WORD	CKS1:1;
			__WORD	RTRG:1;
			__WORD	MDSE:1;
			__WORD	STGR:1;
			__WORD	CNTE:1;
#endif
	} bitc;
} PCN3STR;

__IO_EXTERN	  PCN3STR	IO_PCN3;
#define	_pcn3		(IO_PCN3)
#define	PCN3		(IO_PCN3.word)
#define	PCN3_OSEL  	(IO_PCN3.bit.OSEL)
#define	PCN3_OE  	(IO_PCN3.bit.OE)
#define	PCN3_IRS  	(IO_PCN3.bit.IRS)
#define	PCN3_IRS0  	(IO_PCN3.bitc.IRS0)
#define	PCN3_IRS1  	(IO_PCN3.bitc.IRS1)
#define	PCN3_IRQF  	(IO_PCN3.bit.IRQF)
#define	PCN3_IREN  	(IO_PCN3.bit.IREN)
#define	PCN3_EGS  	(IO_PCN3.bit.EGS)
#define	PCN3_EGS0  	(IO_PCN3.bitc.EGS0)
#define	PCN3_EGS1  	(IO_PCN3.bitc.EGS1)
#define	PCN3_MOD  	(IO_PCN3.bit.MOD)
#define	PCN3_PGMS  	(IO_PCN3.bit.PGMS)
#define	PCN3_CKS  	(IO_PCN3.bit.CKS)
#define	PCN3_CKS0  	(IO_PCN3.bitc.CKS0)
#define	PCN3_CKS1  	(IO_PCN3.bitc.CKS1)
#define	PCN3_RTRG  	(IO_PCN3.bit.RTRG)
#define	PCN3_MDSE  	(IO_PCN3.bit.MDSE)
#define	PCN3_STGR  	(IO_PCN3.bit.STGR)
#define	PCN3_CNTE  	(IO_PCN3.bit.CNTE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_IIC0, locate=0xAC
#endif

__IO_EXTERN	struct {
	const union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BB:1;
			__BYTE	RSC:1;
			__BYTE	AL:1;
			__BYTE	LRB:1;
			__BYTE	TRX:1;
			__BYTE	AAS:1;
			__BYTE	GCA:1;
			__BYTE	ADT:1;
#else
			__BYTE	ADT:1;
			__BYTE	GCA:1;
			__BYTE	AAS:1;
			__BYTE	TRX:1;
			__BYTE	LRB:1;
			__BYTE	AL:1;
			__BYTE	RSC:1;
			__BYTE	BB:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BB:1;
			__BYTE	RSC:1;
			__BYTE	AL:1;
			__BYTE	LRB:1;
			__BYTE	TRX:1;
			__BYTE	AAS:1;
			__BYTE	GCA:1;
			__BYTE	ADT:1;
#else
			__BYTE	ADT:1;
			__BYTE	GCA:1;
			__BYTE	AAS:1;
			__BYTE	TRX:1;
			__BYTE	LRB:1;
			__BYTE	AL:1;
			__BYTE	RSC:1;
			__BYTE	BB:1;
#endif
		} bitc;
	} IBSR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BER:1;
			__BYTE	BEIE:1;
			__BYTE	SCC:1;
			__BYTE	MSS:1;
			__BYTE	ACK:1;
			__BYTE	GCAA:1;
			__BYTE	INTE:1;
			__BYTE	INT:1;
#else
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	GCAA:1;
			__BYTE	ACK:1;
			__BYTE	MSS:1;
			__BYTE	SCC:1;
			__BYTE	BEIE:1;
			__BYTE	BER:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BER:1;
			__BYTE	BEIE:1;
			__BYTE	SCC:1;
			__BYTE	MSS:1;
			__BYTE	ACK:1;
			__BYTE	GCAA:1;
			__BYTE	INTE:1;
			__BYTE	INT:1;
#else
			__BYTE	INT:1;
			__BYTE	INTE:1;
			__BYTE	GCAA:1;
			__BYTE	ACK:1;
			__BYTE	MSS:1;
			__BYTE	SCC:1;
			__BYTE	BEIE:1;
			__BYTE	BER:1;
#endif
		} bitc;
	} IBCR0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV26:1;
			__WORD	RESV25:1;
			__WORD	RESV24:1;
			__WORD	RESV23:1;
			__WORD	RESV22:1;
			__WORD	RESV21:1;
			__WORD	TA:10;
#else
			__WORD	TA:10;
			__WORD	RESV21:1;
			__WORD	RESV22:1;
			__WORD	RESV23:1;
			__WORD	RESV24:1;
			__WORD	RESV25:1;
			__WORD	RESV26:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV215:1;
			__WORD	RESV214:1;
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	TA9:1;
			__WORD	TA8:1;
			__WORD	TA7:1;
			__WORD	TA6:1;
			__WORD	TA5:1;
			__WORD	TA4:1;
			__WORD	TA3:1;
			__WORD	TA2:1;
			__WORD	TA1:1;
			__WORD	TA0:1;
#else
			__WORD	TA0:1;
			__WORD	TA1:1;
			__WORD	TA2:1;
			__WORD	TA3:1;
			__WORD	TA4:1;
			__WORD	TA5:1;
			__WORD	TA6:1;
			__WORD	TA7:1;
			__WORD	TA8:1;
			__WORD	TA9:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
			__WORD	RESV214:1;
			__WORD	RESV215:1;
#endif
		} bitc;
	} ITBA0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ENTB:1;
			__WORD	RAL:1;
			__WORD	RESV44:1;
			__WORD	RESV43:1;
			__WORD	RESV42:1;
			__WORD	RESV41:1;
			__WORD	TM:10;
#else
			__WORD	TM:10;
			__WORD	RESV41:1;
			__WORD	RESV42:1;
			__WORD	RESV43:1;
			__WORD	RESV44:1;
			__WORD	RAL:1;
			__WORD	ENTB:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	ENTB:1;
			__WORD	RAL:1;
			__WORD	RESV413:1;
			__WORD	RESV412:1;
			__WORD	RESV411:1;
			__WORD	RESV410:1;
			__WORD	TM9:1;
			__WORD	TM8:1;
			__WORD	TM7:1;
			__WORD	TM6:1;
			__WORD	TM5:1;
			__WORD	TM4:1;
			__WORD	TM3:1;
			__WORD	TM2:1;
			__WORD	TM1:1;
			__WORD	TM0:1;
#else
			__WORD	TM0:1;
			__WORD	TM1:1;
			__WORD	TM2:1;
			__WORD	TM3:1;
			__WORD	TM4:1;
			__WORD	TM5:1;
			__WORD	TM6:1;
			__WORD	TM7:1;
			__WORD	TM8:1;
			__WORD	TM9:1;
			__WORD	RESV410:1;
			__WORD	RESV411:1;
			__WORD	RESV412:1;
			__WORD	RESV413:1;
			__WORD	RAL:1;
			__WORD	ENTB:1;
#endif
		} bitc;
	} ITMK0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV61:1;
			__BYTE	SA:7;
#else
			__BYTE	SA:7;
			__BYTE	RESV61:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV67:1;
			__BYTE	SA6:1;
			__BYTE	SA5:1;
			__BYTE	SA4:1;
			__BYTE	SA3:1;
			__BYTE	SA2:1;
			__BYTE	SA1:1;
			__BYTE	SA0:1;
#else
			__BYTE	SA0:1;
			__BYTE	SA1:1;
			__BYTE	SA2:1;
			__BYTE	SA3:1;
			__BYTE	SA4:1;
			__BYTE	SA5:1;
			__BYTE	SA6:1;
			__BYTE	RESV67:1;
#endif
		} bitc;
	} ISBA0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ENSB:1;
			__BYTE	SM:7;
#else
			__BYTE	SM:7;
			__BYTE	ENSB:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ENSB:1;
			__BYTE	SM6:1;
			__BYTE	SM5:1;
			__BYTE	SM4:1;
			__BYTE	SM3:1;
			__BYTE	SM2:1;
			__BYTE	SM1:1;
			__BYTE	SM0:1;
#else
			__BYTE	SM0:1;
			__BYTE	SM1:1;
			__BYTE	SM2:1;
			__BYTE	SM3:1;
			__BYTE	SM4:1;
			__BYTE	SM5:1;
			__BYTE	SM6:1;
			__BYTE	ENSB:1;
#endif
		} bitc;
	} ISMK0;
	__BYTE	IDAR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV93:1;
			__BYTE	NSF:1;
			__BYTE	EN:1;
			__BYTE	CS:5;
#else
			__BYTE	CS:5;
			__BYTE	EN:1;
			__BYTE	NSF:1;
			__BYTE	RESV93:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV97:1;
			__BYTE	NSF:1;
			__BYTE	EN:1;
			__BYTE	CS4:1;
			__BYTE	CS3:1;
			__BYTE	CS2:1;
			__BYTE	CS1:1;
			__BYTE	CS0:1;
#else
			__BYTE	CS0:1;
			__BYTE	CS1:1;
			__BYTE	CS2:1;
			__BYTE	CS3:1;
			__BYTE	CS4:1;
			__BYTE	EN:1;
			__BYTE	NSF:1;
			__BYTE	RESV97:1;
#endif
		} bitc;
	} ICCR0;
} IO_IIC0;

#define	IIC0_IBSR0			(IO_IIC0.IBSR0.byte)
#define	IIC0_IBSR0_ADT    	(IO_IIC0.IBSR0.bit.ADT)
#define	IIC0_IBSR0_GCA    	(IO_IIC0.IBSR0.bit.GCA)
#define	IIC0_IBSR0_AAS    	(IO_IIC0.IBSR0.bit.AAS)
#define	IIC0_IBSR0_TRX    	(IO_IIC0.IBSR0.bit.TRX)
#define	IIC0_IBSR0_LRB    	(IO_IIC0.IBSR0.bit.LRB)
#define	IIC0_IBSR0_AL    	(IO_IIC0.IBSR0.bit.AL)
#define	IIC0_IBSR0_RSC    	(IO_IIC0.IBSR0.bit.RSC)
#define	IIC0_IBSR0_BB    	(IO_IIC0.IBSR0.bit.BB)
#define	IIC0_IBCR0			(IO_IIC0.IBCR0.byte)
#define	IIC0_IBCR0_INT    	(IO_IIC0.IBCR0.bit.INT)
#define	IIC0_IBCR0_INTE    	(IO_IIC0.IBCR0.bit.INTE)
#define	IIC0_IBCR0_GCAA    	(IO_IIC0.IBCR0.bit.GCAA)
#define	IIC0_IBCR0_ACK    	(IO_IIC0.IBCR0.bit.ACK)
#define	IIC0_IBCR0_MSS    	(IO_IIC0.IBCR0.bit.MSS)
#define	IIC0_IBCR0_SCC    	(IO_IIC0.IBCR0.bit.SCC)
#define	IIC0_IBCR0_BEIE    	(IO_IIC0.IBCR0.bit.BEIE)
#define	IIC0_IBCR0_BER    	(IO_IIC0.IBCR0.bit.BER)
#define	IIC0_ITBA0			(IO_IIC0.ITBA0.word)
#define	IIC0_ITBA0_TA    	(IO_IIC0.ITBA0.bit.TA)
#define	IIC0_ITBA0_TA0    	(IO_IIC0.ITBA0.bitc.TA0)
#define	IIC0_ITBA0_TA1    	(IO_IIC0.ITBA0.bitc.TA1)
#define	IIC0_ITBA0_TA2    	(IO_IIC0.ITBA0.bitc.TA2)
#define	IIC0_ITBA0_TA3    	(IO_IIC0.ITBA0.bitc.TA3)
#define	IIC0_ITBA0_TA4    	(IO_IIC0.ITBA0.bitc.TA4)
#define	IIC0_ITBA0_TA5    	(IO_IIC0.ITBA0.bitc.TA5)
#define	IIC0_ITBA0_TA6    	(IO_IIC0.ITBA0.bitc.TA6)
#define	IIC0_ITBA0_TA7    	(IO_IIC0.ITBA0.bitc.TA7)
#define	IIC0_ITBA0_TA8    	(IO_IIC0.ITBA0.bitc.TA8)
#define	IIC0_ITBA0_TA9    	(IO_IIC0.ITBA0.bitc.TA9)
#define	IIC0_ITMK0			(IO_IIC0.ITMK0.word)
#define	IIC0_ITMK0_TM    	(IO_IIC0.ITMK0.bit.TM)
#define	IIC0_ITMK0_TM0    	(IO_IIC0.ITMK0.bitc.TM0)
#define	IIC0_ITMK0_TM1    	(IO_IIC0.ITMK0.bitc.TM1)
#define	IIC0_ITMK0_TM2    	(IO_IIC0.ITMK0.bitc.TM2)
#define	IIC0_ITMK0_TM3    	(IO_IIC0.ITMK0.bitc.TM3)
#define	IIC0_ITMK0_TM4    	(IO_IIC0.ITMK0.bitc.TM4)
#define	IIC0_ITMK0_TM5    	(IO_IIC0.ITMK0.bitc.TM5)
#define	IIC0_ITMK0_TM6    	(IO_IIC0.ITMK0.bitc.TM6)
#define	IIC0_ITMK0_TM7    	(IO_IIC0.ITMK0.bitc.TM7)
#define	IIC0_ITMK0_TM8    	(IO_IIC0.ITMK0.bitc.TM8)
#define	IIC0_ITMK0_TM9    	(IO_IIC0.ITMK0.bitc.TM9)
#define	IIC0_ITMK0_RAL    	(IO_IIC0.ITMK0.bit.RAL)
#define	IIC0_ITMK0_ENTB    	(IO_IIC0.ITMK0.bit.ENTB)
#define	IIC0_ISBA0			(IO_IIC0.ISBA0.byte)
#define	IIC0_ISBA0_SA    	(IO_IIC0.ISBA0.bit.SA)
#define	IIC0_ISBA0_SA0    	(IO_IIC0.ISBA0.bitc.SA0)
#define	IIC0_ISBA0_SA1    	(IO_IIC0.ISBA0.bitc.SA1)
#define	IIC0_ISBA0_SA2    	(IO_IIC0.ISBA0.bitc.SA2)
#define	IIC0_ISBA0_SA3    	(IO_IIC0.ISBA0.bitc.SA3)
#define	IIC0_ISBA0_SA4    	(IO_IIC0.ISBA0.bitc.SA4)
#define	IIC0_ISBA0_SA5    	(IO_IIC0.ISBA0.bitc.SA5)
#define	IIC0_ISBA0_SA6    	(IO_IIC0.ISBA0.bitc.SA6)
#define	IIC0_ISMK0			(IO_IIC0.ISMK0.byte)
#define	IIC0_ISMK0_SM    	(IO_IIC0.ISMK0.bit.SM)
#define	IIC0_ISMK0_SM0    	(IO_IIC0.ISMK0.bitc.SM0)
#define	IIC0_ISMK0_SM1    	(IO_IIC0.ISMK0.bitc.SM1)
#define	IIC0_ISMK0_SM2    	(IO_IIC0.ISMK0.bitc.SM2)
#define	IIC0_ISMK0_SM3    	(IO_IIC0.ISMK0.bitc.SM3)
#define	IIC0_ISMK0_SM4    	(IO_IIC0.ISMK0.bitc.SM4)
#define	IIC0_ISMK0_SM5    	(IO_IIC0.ISMK0.bitc.SM5)
#define	IIC0_ISMK0_SM6    	(IO_IIC0.ISMK0.bitc.SM6)
#define	IIC0_ISMK0_ENSB    	(IO_IIC0.ISMK0.bit.ENSB)
#define	IIC0_IDAR0	(IO_IIC0.IDAR0)
#define	IIC0_ICCR0			(IO_IIC0.ICCR0.byte)
#define	IIC0_ICCR0_CS    	(IO_IIC0.ICCR0.bit.CS)
#define	IIC0_ICCR0_CS0    	(IO_IIC0.ICCR0.bitc.CS0)
#define	IIC0_ICCR0_CS1    	(IO_IIC0.ICCR0.bitc.CS1)
#define	IIC0_ICCR0_CS2    	(IO_IIC0.ICCR0.bitc.CS2)
#define	IIC0_ICCR0_CS3    	(IO_IIC0.ICCR0.bitc.CS3)
#define	IIC0_ICCR0_CS4    	(IO_IIC0.ICCR0.bitc.CS4)
#define	IIC0_ICCR0_EN    	(IO_IIC0.ICCR0.bit.EN)
#define	IIC0_ICCR0_NSF    	(IO_IIC0.ICCR0.bit.NSF)

#ifdef __IO_DEFINE
#pragma segment IO=IO_UART0, locate=0xC0
#endif

__IO_EXTERN	struct {
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD:2;
			__BYTE	OTO:1;
			__BYTE	EXT:1;
			__BYTE	REST:1;
			__BYTE	UPCL:1;
			__BYTE	SCKE:1;
			__BYTE	SOE:1;
#else
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD:2;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD1:1;
			__BYTE	MD0:1;
			__BYTE	OTO:1;
			__BYTE	EXT:1;
			__BYTE	REST:1;
			__BYTE	UPCL:1;
			__BYTE	SCKE:1;
			__BYTE	SOE:1;
#else
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
#endif
		} bitc;
	} SMR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PEN:1;
			__BYTE	P:1;
			__BYTE	SBL:1;
			__BYTE	CL:1;
			__BYTE	AD:1;
			__BYTE	CRE:1;
			__BYTE	RXE:1;
			__BYTE	TXE:1;
#else
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PEN:1;
			__BYTE	P:1;
			__BYTE	SBL:1;
			__BYTE	CL:1;
			__BYTE	AD:1;
			__BYTE	CRE:1;
			__BYTE	RXE:1;
			__BYTE	TXE:1;
#else
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
#endif
		} bitc;
	} SCR0;
	__BYTE	RDR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PE:1;
			__BYTE	ORE:1;
			__BYTE	FRE:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	BDS:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
#else
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PE:1;
			__BYTE	ORE:1;
			__BYTE	FRE:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	BDS:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
#else
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
#endif
		} bitc;
	} SSR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	INV:1;
			__BYTE	LBR:1;
			__BYTE	MS:1;
			__BYTE	SCDE:1;
			__BYTE	SSM:1;
			__BYTE	RESV42:1;
			__BYTE	RBI:1;
			__BYTE	TBI:1;
#else
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV42:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	INV:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	INV:1;
			__BYTE	LBR:1;
			__BYTE	MS:1;
			__BYTE	SCDE:1;
			__BYTE	SSM:1;
			__BYTE	RESV42:1;
			__BYTE	RBI:1;
			__BYTE	TBI:1;
#else
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV42:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	INV:1;
#endif
		} bitc;
	} ECCR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LBIE:1;
			__BYTE	LBD:1;
			__BYTE	LBL:2;
			__BYTE	SOPE:1;
			__BYTE	SIOP:1;
			__BYTE	CCO:1;
			__BYTE	SCES:1;
#else
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL:2;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LBIE:1;
			__BYTE	LBD:1;
			__BYTE	LBL1:1;
			__BYTE	LBL0:1;
			__BYTE	SOPE:1;
			__BYTE	SIOP:1;
			__BYTE	CCO:1;
			__BYTE	SCES:1;
#else
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL0:1;
			__BYTE	LBL1:1;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
#endif
		} bitc;
	} ESCR0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BGRH0:8;
			__WORD	BGRL0:8;
#else
			__WORD	BGRL0:8;
			__WORD	BGRH0:8;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BGRH07:1;
			__WORD	BGRH06:1;
			__WORD	BGRH05:1;
			__WORD	BGRH04:1;
			__WORD	BGRH03:1;
			__WORD	BGRH02:1;
			__WORD	BGRH01:1;
			__WORD	BGRH00:1;
			__WORD	BGRL07:1;
			__WORD	BGRL06:1;
			__WORD	BGRL05:1;
			__WORD	BGRL04:1;
			__WORD	BGRL03:1;
			__WORD	BGRL02:1;
			__WORD	BGRL01:1;
			__WORD	BGRL00:1;
#else
			__WORD	BGRL00:1;
			__WORD	BGRL01:1;
			__WORD	BGRL02:1;
			__WORD	BGRL03:1;
			__WORD	BGRL04:1;
			__WORD	BGRL05:1;
			__WORD	BGRL06:1;
			__WORD	BGRL07:1;
			__WORD	BGRH00:1;
			__WORD	BGRH01:1;
			__WORD	BGRH02:1;
			__WORD	BGRH03:1;
			__WORD	BGRH04:1;
			__WORD	BGRH05:1;
			__WORD	BGRH06:1;
			__WORD	BGRH07:1;
#endif
		} bitc;
	} BGR0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV87:1;
			__BYTE	RESV86:1;
			__BYTE	RESV85:1;
			__BYTE	RESV84:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	RBI:1;
			__BYTE	AICD:1;
#else
			__BYTE	AICD:1;
			__BYTE	RBI:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	RESV84:1;
			__BYTE	RESV85:1;
			__BYTE	RESV86:1;
			__BYTE	RESV87:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV87:1;
			__BYTE	RESV86:1;
			__BYTE	RESV85:1;
			__BYTE	RESV84:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	RBI:1;
			__BYTE	AICD:1;
#else
			__BYTE	AICD:1;
			__BYTE	RBI:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	RESV84:1;
			__BYTE	RESV85:1;
			__BYTE	RESV86:1;
			__BYTE	RESV87:1;
#endif
		} bitc;
	} ESIR0;
	__BYTE	FIDR0;
} IO_UART0;

#define	UART0_SMR0			(IO_UART0.SMR0.byte)
#define	UART0_SMR0_SOE    	(IO_UART0.SMR0.bit.SOE)
#define	UART0_SMR0_SCKE    	(IO_UART0.SMR0.bit.SCKE)
#define	UART0_SMR0_UPCL    	(IO_UART0.SMR0.bit.UPCL)
#define	UART0_SMR0_REST    	(IO_UART0.SMR0.bit.REST)
#define	UART0_SMR0_EXT    	(IO_UART0.SMR0.bit.EXT)
#define	UART0_SMR0_OTO    	(IO_UART0.SMR0.bit.OTO)
#define	UART0_SMR0_MD    	(IO_UART0.SMR0.bit.MD)
#define	UART0_SMR0_MD0    	(IO_UART0.SMR0.bitc.MD0)
#define	UART0_SMR0_MD1    	(IO_UART0.SMR0.bitc.MD1)
#define	UART0_SCR0			(IO_UART0.SCR0.byte)
#define	UART0_SCR0_TXE    	(IO_UART0.SCR0.bit.TXE)
#define	UART0_SCR0_RXE    	(IO_UART0.SCR0.bit.RXE)
#define	UART0_SCR0_CRE    	(IO_UART0.SCR0.bit.CRE)
#define	UART0_SCR0_AD    	(IO_UART0.SCR0.bit.AD)
#define	UART0_SCR0_CL    	(IO_UART0.SCR0.bit.CL)
#define	UART0_SCR0_SBL    	(IO_UART0.SCR0.bit.SBL)
#define	UART0_SCR0_P    	(IO_UART0.SCR0.bit.P)
#define	UART0_SCR0_PEN    	(IO_UART0.SCR0.bit.PEN)
#define	UART0_RDR0	(IO_UART0.RDR0)
#define	UART0_TDR0	(IO_UART0.RDR0)
#define	UART0_SSR0			(IO_UART0.SSR0.byte)
#define	UART0_SSR0_TIE    	(IO_UART0.SSR0.bit.TIE)
#define	UART0_SSR0_RIE    	(IO_UART0.SSR0.bit.RIE)
#define	UART0_SSR0_BDS    	(IO_UART0.SSR0.bit.BDS)
#define	UART0_SSR0_TDRE    	(IO_UART0.SSR0.bit.TDRE)
#define	UART0_SSR0_RDRF    	(IO_UART0.SSR0.bit.RDRF)
#define	UART0_SSR0_FRE    	(IO_UART0.SSR0.bit.FRE)
#define	UART0_SSR0_ORE    	(IO_UART0.SSR0.bit.ORE)
#define	UART0_SSR0_PE    	(IO_UART0.SSR0.bit.PE)
#define	UART0_ECCR0			(IO_UART0.ECCR0.byte)
#define	UART0_ECCR0_TBI    	(IO_UART0.ECCR0.bit.TBI)
#define	UART0_ECCR0_RBI    	(IO_UART0.ECCR0.bit.RBI)
#define	UART0_ECCR0_SSM    	(IO_UART0.ECCR0.bit.SSM)
#define	UART0_ECCR0_SCDE    	(IO_UART0.ECCR0.bit.SCDE)
#define	UART0_ECCR0_MS    	(IO_UART0.ECCR0.bit.MS)
#define	UART0_ECCR0_LBR    	(IO_UART0.ECCR0.bit.LBR)
#define	UART0_ECCR0_INV    	(IO_UART0.ECCR0.bit.INV)
#define	UART0_ESCR0			(IO_UART0.ESCR0.byte)
#define	UART0_ESCR0_SCES    	(IO_UART0.ESCR0.bit.SCES)
#define	UART0_ESCR0_CCO    	(IO_UART0.ESCR0.bit.CCO)
#define	UART0_ESCR0_SIOP    	(IO_UART0.ESCR0.bit.SIOP)
#define	UART0_ESCR0_SOPE    	(IO_UART0.ESCR0.bit.SOPE)
#define	UART0_ESCR0_LBL    	(IO_UART0.ESCR0.bit.LBL)
#define	UART0_ESCR0_LBL0    	(IO_UART0.ESCR0.bitc.LBL0)
#define	UART0_ESCR0_LBL1    	(IO_UART0.ESCR0.bitc.LBL1)
#define	UART0_ESCR0_LBD    	(IO_UART0.ESCR0.bit.LBD)
#define	UART0_ESCR0_LBIE    	(IO_UART0.ESCR0.bit.LBIE)
#define	UART0_BGR0			(IO_UART0.BGR0.word)
#define	UART0_BGR0_BGRL0    	(IO_UART0.BGR0.bit.BGRL0)
#define	UART0_BGR0_BGRL00    	(IO_UART0.BGR0.bitc.BGRL00)
#define	UART0_BGR0_BGRL01    	(IO_UART0.BGR0.bitc.BGRL01)
#define	UART0_BGR0_BGRL02    	(IO_UART0.BGR0.bitc.BGRL02)
#define	UART0_BGR0_BGRL03    	(IO_UART0.BGR0.bitc.BGRL03)
#define	UART0_BGR0_BGRL04    	(IO_UART0.BGR0.bitc.BGRL04)
#define	UART0_BGR0_BGRL05    	(IO_UART0.BGR0.bitc.BGRL05)
#define	UART0_BGR0_BGRL06    	(IO_UART0.BGR0.bitc.BGRL06)
#define	UART0_BGR0_BGRL07    	(IO_UART0.BGR0.bitc.BGRL07)
#define	UART0_BGR0_BGRH0    	(IO_UART0.BGR0.bit.BGRH0)
#define	UART0_BGR0_BGRH00    	(IO_UART0.BGR0.bitc.BGRH00)
#define	UART0_BGR0_BGRH01    	(IO_UART0.BGR0.bitc.BGRH01)
#define	UART0_BGR0_BGRH02    	(IO_UART0.BGR0.bitc.BGRH02)
#define	UART0_BGR0_BGRH03    	(IO_UART0.BGR0.bitc.BGRH03)
#define	UART0_BGR0_BGRH04    	(IO_UART0.BGR0.bitc.BGRH04)
#define	UART0_BGR0_BGRH05    	(IO_UART0.BGR0.bitc.BGRH05)
#define	UART0_BGR0_BGRH06    	(IO_UART0.BGR0.bitc.BGRH06)
#define	UART0_BGR0_BGRH07    	(IO_UART0.BGR0.bitc.BGRH07)
#define	UART0_ESIR0			(IO_UART0.ESIR0.byte)
#define	UART0_ESIR0_AICD    	(IO_UART0.ESIR0.bit.AICD)
#define	UART0_ESIR0_RBI    	(IO_UART0.ESIR0.bit.RBI)
#define	UART0_ESIR0_RDRF    	(IO_UART0.ESIR0.bit.RDRF)
#define	UART0_ESIR0_TDRE    	(IO_UART0.ESIR0.bit.TDRE)
#define	UART0_FIDR0			(IO_UART0.FIDR0)

#ifdef __IO_DEFINE
#pragma segment IO=IO_UART1, locate=0xCA
#endif

__IO_EXTERN	struct {
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD:2;
			__BYTE	OTO:1;
			__BYTE	EXT:1;
			__BYTE	REST:1;
			__BYTE	UPCL:1;
			__BYTE	SCKE:1;
			__BYTE	SOE:1;
#else
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD:2;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	MD1:1;
			__BYTE	MD0:1;
			__BYTE	OTO:1;
			__BYTE	EXT:1;
			__BYTE	REST:1;
			__BYTE	UPCL:1;
			__BYTE	SCKE:1;
			__BYTE	SOE:1;
#else
			__BYTE	SOE:1;
			__BYTE	SCKE:1;
			__BYTE	UPCL:1;
			__BYTE	REST:1;
			__BYTE	EXT:1;
			__BYTE	OTO:1;
			__BYTE	MD0:1;
			__BYTE	MD1:1;
#endif
		} bitc;
	} SMR1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PEN:1;
			__BYTE	P:1;
			__BYTE	SBL:1;
			__BYTE	CL:1;
			__BYTE	AD:1;
			__BYTE	CRE:1;
			__BYTE	RXE:1;
			__BYTE	TXE:1;
#else
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PEN:1;
			__BYTE	P:1;
			__BYTE	SBL:1;
			__BYTE	CL:1;
			__BYTE	AD:1;
			__BYTE	CRE:1;
			__BYTE	RXE:1;
			__BYTE	TXE:1;
#else
			__BYTE	TXE:1;
			__BYTE	RXE:1;
			__BYTE	CRE:1;
			__BYTE	AD:1;
			__BYTE	CL:1;
			__BYTE	SBL:1;
			__BYTE	P:1;
			__BYTE	PEN:1;
#endif
		} bitc;
	} SCR1;
	__BYTE	RDR1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PE:1;
			__BYTE	ORE:1;
			__BYTE	FRE:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	BDS:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
#else
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PE:1;
			__BYTE	ORE:1;
			__BYTE	FRE:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	BDS:1;
			__BYTE	RIE:1;
			__BYTE	TIE:1;
#else
			__BYTE	TIE:1;
			__BYTE	RIE:1;
			__BYTE	BDS:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	FRE:1;
			__BYTE	ORE:1;
			__BYTE	PE:1;
#endif
		} bitc;
	} SSR1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	INV:1;
			__BYTE	LBR:1;
			__BYTE	MS:1;
			__BYTE	SCDE:1;
			__BYTE	SSM:1;
			__BYTE	RESV42:1;
			__BYTE	RBI:1;
			__BYTE	TBI:1;
#else
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV42:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	INV:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	INV:1;
			__BYTE	LBR:1;
			__BYTE	MS:1;
			__BYTE	SCDE:1;
			__BYTE	SSM:1;
			__BYTE	RESV42:1;
			__BYTE	RBI:1;
			__BYTE	TBI:1;
#else
			__BYTE	TBI:1;
			__BYTE	RBI:1;
			__BYTE	RESV42:1;
			__BYTE	SSM:1;
			__BYTE	SCDE:1;
			__BYTE	MS:1;
			__BYTE	LBR:1;
			__BYTE	INV:1;
#endif
		} bitc;
	} ECCR1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LBIE:1;
			__BYTE	LBD:1;
			__BYTE	LBL:2;
			__BYTE	SOPE:1;
			__BYTE	SIOP:1;
			__BYTE	CCO:1;
			__BYTE	SCES:1;
#else
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL:2;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LBIE:1;
			__BYTE	LBD:1;
			__BYTE	LBL1:1;
			__BYTE	LBL0:1;
			__BYTE	SOPE:1;
			__BYTE	SIOP:1;
			__BYTE	CCO:1;
			__BYTE	SCES:1;
#else
			__BYTE	SCES:1;
			__BYTE	CCO:1;
			__BYTE	SIOP:1;
			__BYTE	SOPE:1;
			__BYTE	LBL0:1;
			__BYTE	LBL1:1;
			__BYTE	LBD:1;
			__BYTE	LBIE:1;
#endif
		} bitc;
	} ESCR1;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BGRH1:8;
			__WORD	BGRL1:8;
#else
			__WORD	BGRL1:8;
			__WORD	BGRH1:8;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BGRH17:1;
			__WORD	BGRH16:1;
			__WORD	BGRH15:1;
			__WORD	BGRH14:1;
			__WORD	BGRH13:1;
			__WORD	BGRH12:1;
			__WORD	BGRH11:1;
			__WORD	BGRH10:1;
			__WORD	BGRL17:1;
			__WORD	BGRL16:1;
			__WORD	BGRL15:1;
			__WORD	BGRL14:1;
			__WORD	BGRL13:1;
			__WORD	BGRL12:1;
			__WORD	BGRL11:1;
			__WORD	BGRL10:1;
#else
			__WORD	BGRL10:1;
			__WORD	BGRL11:1;
			__WORD	BGRL12:1;
			__WORD	BGRL13:1;
			__WORD	BGRL14:1;
			__WORD	BGRL15:1;
			__WORD	BGRL16:1;
			__WORD	BGRL17:1;
			__WORD	BGRH10:1;
			__WORD	BGRH11:1;
			__WORD	BGRH12:1;
			__WORD	BGRH13:1;
			__WORD	BGRH14:1;
			__WORD	BGRH15:1;
			__WORD	BGRH16:1;
			__WORD	BGRH17:1;
#endif
		} bitc;
	} BGR1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV87:1;
			__BYTE	RESV86:1;
			__BYTE	RESV85:1;
			__BYTE	RESV84:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	RBI:1;
			__BYTE	AICD:1;
#else
			__BYTE	AICD:1;
			__BYTE	RBI:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	RESV84:1;
			__BYTE	RESV85:1;
			__BYTE	RESV86:1;
			__BYTE	RESV87:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV87:1;
			__BYTE	RESV86:1;
			__BYTE	RESV85:1;
			__BYTE	RESV84:1;
			__BYTE	TDRE:1;
			__BYTE	RDRF:1;
			__BYTE	RBI:1;
			__BYTE	AICD:1;
#else
			__BYTE	AICD:1;
			__BYTE	RBI:1;
			__BYTE	RDRF:1;
			__BYTE	TDRE:1;
			__BYTE	RESV84:1;
			__BYTE	RESV85:1;
			__BYTE	RESV86:1;
			__BYTE	RESV87:1;
#endif
		} bitc;
	} ESIR1;
} IO_UART1;

#define	UART1_SMR1			(IO_UART1.SMR1.byte)
#define	UART1_SMR1_SOE    	(IO_UART1.SMR1.bit.SOE)
#define	UART1_SMR1_SCKE    	(IO_UART1.SMR1.bit.SCKE)
#define	UART1_SMR1_UPCL    	(IO_UART1.SMR1.bit.UPCL)
#define	UART1_SMR1_REST    	(IO_UART1.SMR1.bit.REST)
#define	UART1_SMR1_EXT    	(IO_UART1.SMR1.bit.EXT)
#define	UART1_SMR1_OTO    	(IO_UART1.SMR1.bit.OTO)
#define	UART1_SMR1_MD    	(IO_UART1.SMR1.bit.MD)
#define	UART1_SMR1_MD0    	(IO_UART1.SMR1.bitc.MD0)
#define	UART1_SMR1_MD1    	(IO_UART1.SMR1.bitc.MD1)
#define	UART1_SCR1			(IO_UART1.SCR1.byte)
#define	UART1_SCR1_TXE    	(IO_UART1.SCR1.bit.TXE)
#define	UART1_SCR1_RXE    	(IO_UART1.SCR1.bit.RXE)
#define	UART1_SCR1_CRE    	(IO_UART1.SCR1.bit.CRE)
#define	UART1_SCR1_AD    	(IO_UART1.SCR1.bit.AD)
#define	UART1_SCR1_CL    	(IO_UART1.SCR1.bit.CL)
#define	UART1_SCR1_SBL    	(IO_UART1.SCR1.bit.SBL)
#define	UART1_SCR1_P    	(IO_UART1.SCR1.bit.P)
#define	UART1_SCR1_PEN    	(IO_UART1.SCR1.bit.PEN)
#define	UART1_RDR1	(IO_UART1.RDR1)
#define	UART1_TDR1	(IO_UART1.RDR1)
#define	UART1_SSR1			(IO_UART1.SSR1.byte)
#define	UART1_SSR1_TIE    	(IO_UART1.SSR1.bit.TIE)
#define	UART1_SSR1_RIE    	(IO_UART1.SSR1.bit.RIE)
#define	UART1_SSR1_BDS    	(IO_UART1.SSR1.bit.BDS)
#define	UART1_SSR1_TDRE    	(IO_UART1.SSR1.bit.TDRE)
#define	UART1_SSR1_RDRF    	(IO_UART1.SSR1.bit.RDRF)
#define	UART1_SSR1_FRE    	(IO_UART1.SSR1.bit.FRE)
#define	UART1_SSR1_ORE    	(IO_UART1.SSR1.bit.ORE)
#define	UART1_SSR1_PE    	(IO_UART1.SSR1.bit.PE)
#define	UART1_ECCR1			(IO_UART1.ECCR1.byte)
#define	UART1_ECCR1_TBI    	(IO_UART1.ECCR1.bit.TBI)
#define	UART1_ECCR1_RBI    	(IO_UART1.ECCR1.bit.RBI)
#define	UART1_ECCR1_SSM    	(IO_UART1.ECCR1.bit.SSM)
#define	UART1_ECCR1_SCDE    	(IO_UART1.ECCR1.bit.SCDE)
#define	UART1_ECCR1_MS    	(IO_UART1.ECCR1.bit.MS)
#define	UART1_ECCR1_LBR    	(IO_UART1.ECCR1.bit.LBR)
#define	UART1_ECCR1_INV    	(IO_UART1.ECCR1.bit.INV)
#define	UART1_ESCR1			(IO_UART1.ESCR1.byte)
#define	UART1_ESCR1_SCES    	(IO_UART1.ESCR1.bit.SCES)
#define	UART1_ESCR1_CCO    	(IO_UART1.ESCR1.bit.CCO)
#define	UART1_ESCR1_SIOP    	(IO_UART1.ESCR1.bit.SIOP)
#define	UART1_ESCR1_SOPE    	(IO_UART1.ESCR1.bit.SOPE)
#define	UART1_ESCR1_LBL    	(IO_UART1.ESCR1.bit.LBL)
#define	UART1_ESCR1_LBL0    	(IO_UART1.ESCR1.bitc.LBL0)
#define	UART1_ESCR1_LBL1    	(IO_UART1.ESCR1.bitc.LBL1)
#define	UART1_ESCR1_LBD    	(IO_UART1.ESCR1.bit.LBD)
#define	UART1_ESCR1_LBIE    	(IO_UART1.ESCR1.bit.LBIE)
#define	UART1_BGR1			(IO_UART1.BGR1.word)
#define	UART1_BGR1_BGRL1    	(IO_UART1.BGR1.bit.BGRL1)
#define	UART1_BGR1_BGRL10    	(IO_UART1.BGR1.bitc.BGRL10)
#define	UART1_BGR1_BGRL11    	(IO_UART1.BGR1.bitc.BGRL11)
#define	UART1_BGR1_BGRL12    	(IO_UART1.BGR1.bitc.BGRL12)
#define	UART1_BGR1_BGRL13    	(IO_UART1.BGR1.bitc.BGRL13)
#define	UART1_BGR1_BGRL14    	(IO_UART1.BGR1.bitc.BGRL14)
#define	UART1_BGR1_BGRL15    	(IO_UART1.BGR1.bitc.BGRL15)
#define	UART1_BGR1_BGRL16    	(IO_UART1.BGR1.bitc.BGRL16)
#define	UART1_BGR1_BGRL17    	(IO_UART1.BGR1.bitc.BGRL17)
#define	UART1_BGR1_BGRH1    	(IO_UART1.BGR1.bit.BGRH1)
#define	UART1_BGR1_BGRH10    	(IO_UART1.BGR1.bitc.BGRH10)
#define	UART1_BGR1_BGRH11    	(IO_UART1.BGR1.bitc.BGRH11)
#define	UART1_BGR1_BGRH12    	(IO_UART1.BGR1.bitc.BGRH12)
#define	UART1_BGR1_BGRH13    	(IO_UART1.BGR1.bitc.BGRH13)
#define	UART1_BGR1_BGRH14    	(IO_UART1.BGR1.bitc.BGRH14)
#define	UART1_BGR1_BGRH15    	(IO_UART1.BGR1.bitc.BGRH15)
#define	UART1_BGR1_BGRH16    	(IO_UART1.BGR1.bitc.BGRH16)
#define	UART1_BGR1_BGRH17    	(IO_UART1.BGR1.bitc.BGRH17)
#define	UART1_ESIR1			(IO_UART1.ESIR1.byte)
#define	UART1_ESIR1_AICD    	(IO_UART1.ESIR1.bit.AICD)
#define	UART1_ESIR1_RBI    	(IO_UART1.ESIR1.bit.RBI)
#define	UART1_ESIR1_RDRF    	(IO_UART1.ESIR1.bit.RDRF)
#define	UART1_ESIR1_TDRE    	(IO_UART1.ESIR1.bit.TDRE)

#ifdef __IO_DEFINE
#pragma segment IO=IO_GCNR0, locate=0xEC
#endif

__IO_EXTERN	__BYTE	IO_GCNR0;
#define	_gcnr0		(IO_GCNR0)
#define	GCNR0	(_gcnr0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BAPML0,   locate=0x100
#pragma segment FAR_DATA=IO_BAPML0, locate=0x100
#endif

__IO_EXTENDED	__WORD	IO_BAPML0;
#define	_bapml0		(IO_BAPML0)
#define	BAPML0	(_bapml0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BAPH0,   locate=0x102
#pragma segment FAR_DATA=IO_BAPH0, locate=0x102
#endif

__IO_EXTENDED	__BYTE	IO_BAPH0;
#define	_baph0		(IO_BAPH0)
#define	BAPH0	(_baph0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DMACS0,   locate=0x103
#pragma segment FAR_DATA=IO_DMACS0, locate=0x103
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DMACS0STR;

__IO_EXTENDED	  DMACS0STR	IO_DMACS0;
#define	_dmacs0		(IO_DMACS0)
#define	DMACS0		(IO_DMACS0.byte)
#define	DMACS0_SE  	(IO_DMACS0.bit.SE)
#define	DMACS0_DIR  	(IO_DMACS0.bit.DIR)
#define	DMACS0_BF  	(IO_DMACS0.bit.BF)
#define	DMACS0_BW  	(IO_DMACS0.bit.BW)
#define	DMACS0_IF  	(IO_DMACS0.bit.IF)
#define	DMACS0_BPD  	(IO_DMACS0.bit.BPD)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IOA0,   locate=0x104
#pragma segment FAR_DATA=IO_IOA0, locate=0x104
#endif

__IO_EXTENDED	__WORD	IO_IOA0;
#define	_ioa0		(IO_IOA0)
#define	IOA0	(_ioa0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DCT0,   locate=0x106
#pragma segment FAR_DATA=IO_DCT0, locate=0x106
#endif

__IO_EXTENDED	__WORD	IO_DCT0;
#define	_dct0		(IO_DCT0)
#define	DCT0	(_dct0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BAPML1,   locate=0x108
#pragma segment FAR_DATA=IO_BAPML1, locate=0x108
#endif

__IO_EXTENDED	__WORD	IO_BAPML1;
#define	_bapml1		(IO_BAPML1)
#define	BAPML1	(_bapml1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_BAPH1,   locate=0x10A
#pragma segment FAR_DATA=IO_BAPH1, locate=0x10A
#endif

__IO_EXTENDED	__BYTE	IO_BAPH1;
#define	_baph1		(IO_BAPH1)
#define	BAPH1	(_baph1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DMACS1,   locate=0x10B
#pragma segment FAR_DATA=IO_DMACS1, locate=0x10B
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	BPD:1;
			__BYTE	IF:1;
			__BYTE	BW:1;
			__BYTE	BF:1;
			__BYTE	DIR:1;
			__BYTE	SE:1;
#else
			__BYTE	SE:1;
			__BYTE	DIR:1;
			__BYTE	BF:1;
			__BYTE	BW:1;
			__BYTE	IF:1;
			__BYTE	BPD:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DMACS1STR;

__IO_EXTENDED	  DMACS1STR	IO_DMACS1;
#define	_dmacs1		(IO_DMACS1)
#define	DMACS1		(IO_DMACS1.byte)
#define	DMACS1_SE  	(IO_DMACS1.bit.SE)
#define	DMACS1_DIR  	(IO_DMACS1.bit.DIR)
#define	DMACS1_BF  	(IO_DMACS1.bit.BF)
#define	DMACS1_BW  	(IO_DMACS1.bit.BW)
#define	DMACS1_IF  	(IO_DMACS1.bit.IF)
#define	DMACS1_BPD  	(IO_DMACS1.bit.BPD)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IOA1,   locate=0x10C
#pragma segment FAR_DATA=IO_IOA1, locate=0x10C
#endif

__IO_EXTENDED	__WORD	IO_IOA1;
#define	_ioa1		(IO_IOA1)
#define	IOA1	(_ioa1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DCT1,   locate=0x10E
#pragma segment FAR_DATA=IO_DCT1, locate=0x10E
#endif

__IO_EXTENDED	__WORD	IO_DCT1;
#define	_dct1		(IO_DCT1)
#define	DCT1	(_dct1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DISEL0,   locate=0x380
#pragma segment FAR_DATA=IO_DISEL0, locate=0x380
#endif

__IO_EXTENDED	__BYTE	IO_DISEL0;
#define	_disel0		(IO_DISEL0)
#define	DISEL0	(_disel0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DISEL1,   locate=0x381
#pragma segment FAR_DATA=IO_DISEL1, locate=0x381
#endif

__IO_EXTENDED	__BYTE	IO_DISEL1;
#define	_disel1		(IO_DISEL1)
#define	DISEL1	(_disel1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DSR,   locate=0x390
#pragma segment FAR_DATA=IO_DSR, locate=0x390
#endif

__IO_EXTENDED	__WORD	IO_DSR;
#define	_dsr		(IO_DSR)
#define	DSR	(_dsr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DSSR,   locate=0x392
#pragma segment FAR_DATA=IO_DSSR, locate=0x392
#endif

__IO_EXTENDED	__WORD	IO_DSSR;
#define	_dssr		(IO_DSSR)
#define	DSSR	(_dssr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DER,   locate=0x394
#pragma segment FAR_DATA=IO_DER, locate=0x394
#endif

__IO_EXTENDED	__WORD	IO_DER;
#define	_der		(IO_DER)
#define	DER	(_der)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ICR,   locate=0x3A0
#pragma segment FAR_DATA=IO_ICR, locate=0x3A0
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	IX:8;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	IL:3;
#else
			__WORD	IL:3;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	IX:8;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	IX7:1;
			__WORD	IX6:1;
			__WORD	IX5:1;
			__WORD	IX4:1;
			__WORD	IX3:1;
			__WORD	IX2:1;
			__WORD	IX1:1;
			__WORD	IX0:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	IL2:1;
			__WORD	IL1:1;
			__WORD	IL0:1;
#else
			__WORD	IL0:1;
			__WORD	IL1:1;
			__WORD	IL2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	IX0:1;
			__WORD	IX1:1;
			__WORD	IX2:1;
			__WORD	IX3:1;
			__WORD	IX4:1;
			__WORD	IX5:1;
			__WORD	IX6:1;
			__WORD	IX7:1;
#endif
	} bitc;
} ICRSTR;

__IO_EXTENDED	  ICRSTR	IO_ICR;
#define	_icr		(IO_ICR)
#define	ICR		(IO_ICR.word)
#define	ICR_IL  	(IO_ICR.bit.IL)
#define	ICR_IL0  	(IO_ICR.bitc.IL0)
#define	ICR_IL1  	(IO_ICR.bitc.IL1)
#define	ICR_IL2  	(IO_ICR.bitc.IL2)
#define	ICR_IX  	(IO_ICR.bit.IX)
#define	ICR_IX0  	(IO_ICR.bitc.IX0)
#define	ICR_IX1  	(IO_ICR.bitc.IX1)
#define	ICR_IX2  	(IO_ICR.bitc.IX2)
#define	ICR_IX3  	(IO_ICR.bitc.IX3)
#define	ICR_IX4  	(IO_ICR.bitc.IX4)
#define	ICR_IX5  	(IO_ICR.bitc.IX5)
#define	ICR_IX6  	(IO_ICR.bitc.IX6)
#define	ICR_IX7  	(IO_ICR.bitc.IX7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TBR,   locate=0x3A2
#pragma segment FAR_DATA=IO_TBR, locate=0x3A2
#endif

__IO_EXTENDED	__WORD	IO_TBR;
#define	_tbr		(IO_TBR)
#define	TBR	(_tbr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DIRR,   locate=0x3A4
#pragma segment FAR_DATA=IO_DIRR, locate=0x3A4
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	R0:1;
#else
			__BYTE	R0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	R0:1;
#else
			__BYTE	R0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DIRRSTR;

__IO_EXTENDED	  DIRRSTR	IO_DIRR;
#define	_dirr		(IO_DIRR)
#define	DIRR		(IO_DIRR.byte)
#define	DIRR_R0  	(IO_DIRR.bit.R0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_NMI,   locate=0x3A5
#pragma segment FAR_DATA=IO_NMI, locate=0x3A5
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	LEV:1;
			__BYTE	EN:1;
			__BYTE	FLAG:1;
#else
			__BYTE	FLAG:1;
			__BYTE	EN:1;
			__BYTE	LEV:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	LEV:1;
			__BYTE	EN:1;
			__BYTE	FLAG:1;
#else
			__BYTE	FLAG:1;
			__BYTE	EN:1;
			__BYTE	LEV:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} NMISTR;

__IO_EXTENDED	  NMISTR	IO_NMI;
#define	_nmi		(IO_NMI)
#define	NMI		(IO_NMI.byte)
#define	NMI_FLAG  	(IO_NMI.bit.FLAG)
#define	NMI_EN  	(IO_NMI.bit.EN)
#define	NMI_LEV  	(IO_NMI.bit.LEV)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ROMM,   locate=0x3AE
#pragma segment FAR_DATA=IO_ROMM, locate=0x3AE
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BS:4;
			__BYTE	RESV2:1;
			__BYTE	SZ:2;
			__BYTE	MI:1;
#else
			__BYTE	MI:1;
			__BYTE	SZ:2;
			__BYTE	RESV2:1;
			__BYTE	BS:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	BS3:1;
			__BYTE	BS2:1;
			__BYTE	BS1:1;
			__BYTE	BS0:1;
			__BYTE	RESV3:1;
			__BYTE	SZ1:1;
			__BYTE	SZ0:1;
			__BYTE	MI:1;
#else
			__BYTE	MI:1;
			__BYTE	SZ0:1;
			__BYTE	SZ1:1;
			__BYTE	RESV3:1;
			__BYTE	BS0:1;
			__BYTE	BS1:1;
			__BYTE	BS2:1;
			__BYTE	BS3:1;
#endif
	} bitc;
} ROMMSTR;

__IO_EXTENDED	  ROMMSTR	IO_ROMM;
#define	_romm		(IO_ROMM)
#define	ROMM		(IO_ROMM.byte)
#define	ROMM_MI  	(IO_ROMM.bit.MI)
#define	ROMM_SZ  	(IO_ROMM.bit.SZ)
#define	ROMM_SZ0  	(IO_ROMM.bitc.SZ0)
#define	ROMM_SZ1  	(IO_ROMM.bitc.SZ1)
#define	ROMM_BS  	(IO_ROMM.bit.BS)
#define	ROMM_BS0  	(IO_ROMM.bitc.BS0)
#define	ROMM_BS1  	(IO_ROMM.bitc.BS1)
#define	ROMM_BS2  	(IO_ROMM.bitc.BS2)
#define	ROMM_BS3  	(IO_ROMM.bitc.BS3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFCA,   locate=0x3E8
#pragma segment FAR_DATA=IO_DFCA, locate=0x3E8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	TMG:1;
			__BYTE	CSWE:1;
			__BYTE	WE:1;
#else
			__BYTE	WE:1;
			__BYTE	CSWE:1;
			__BYTE	TMG:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	TMG:1;
			__BYTE	CSWE:1;
			__BYTE	WE:1;
#else
			__BYTE	WE:1;
			__BYTE	CSWE:1;
			__BYTE	TMG:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DFCASTR;

__IO_EXTENDED	  DFCASTR	IO_DFCA;
#define	_dfca		(IO_DFCA)
#define	DFCA		(IO_DFCA.byte)
#define	DFCA_WE  	(IO_DFCA.bit.WE)
#define	DFCA_CSWE  	(IO_DFCA.bit.CSWE)
#define	DFCA_TMG  	(IO_DFCA.bit.TMG)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFICA,   locate=0x3E9
#pragma segment FAR_DATA=IO_DFICA, locate=0x3E9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	ERINTE:1;
			__BYTE	FININTE:1;
			__BYTE	IDLINTE:1;
			__BYTE	WBINTE:1;
			__BYTE	WPSINTE:1;
			__BYTE	HANGINTE:1;
			__BYTE	RDYINTE:1;
#else
			__BYTE	RDYINTE:1;
			__BYTE	HANGINTE:1;
			__BYTE	WPSINTE:1;
			__BYTE	WBINTE:1;
			__BYTE	IDLINTE:1;
			__BYTE	FININTE:1;
			__BYTE	ERINTE:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	ERINTE:1;
			__BYTE	FININTE:1;
			__BYTE	IDLINTE:1;
			__BYTE	WBINTE:1;
			__BYTE	WPSINTE:1;
			__BYTE	HANGINTE:1;
			__BYTE	RDYINTE:1;
#else
			__BYTE	RDYINTE:1;
			__BYTE	HANGINTE:1;
			__BYTE	WPSINTE:1;
			__BYTE	WBINTE:1;
			__BYTE	IDLINTE:1;
			__BYTE	FININTE:1;
			__BYTE	ERINTE:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DFICASTR;

__IO_EXTENDED	  DFICASTR	IO_DFICA;
#define	_dfica		(IO_DFICA)
#define	DFICA		(IO_DFICA.byte)
#define	DFICA_RDYINTE  	(IO_DFICA.bit.RDYINTE)
#define	DFICA_HANGINTE  	(IO_DFICA.bit.HANGINTE)
#define	DFICA_WPSINTE  	(IO_DFICA.bit.WPSINTE)
#define	DFICA_WBINTE  	(IO_DFICA.bit.WBINTE)
#define	DFICA_IDLINTE  	(IO_DFICA.bit.IDLINTE)
#define	DFICA_FININTE  	(IO_DFICA.bit.FININTE)
#define	DFICA_ERINTE  	(IO_DFICA.bit.ERINTE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFSA,   locate=0x3EA
#pragma segment FAR_DATA=IO_DFSA, locate=0x3EA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ST:2;
			__BYTE	PGMS:1;
			__BYTE	SERS:1;
			__BYTE	ESPS:1;
			__BYTE	CERS:1;
			__BYTE	HANG:1;
			__BYTE	RDY:1;
#else
			__BYTE	RDY:1;
			__BYTE	HANG:1;
			__BYTE	CERS:1;
			__BYTE	ESPS:1;
			__BYTE	SERS:1;
			__BYTE	PGMS:1;
			__BYTE	ST:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ST1:1;
			__BYTE	ST0:1;
			__BYTE	PGMS:1;
			__BYTE	SERS:1;
			__BYTE	ESPS:1;
			__BYTE	CERS:1;
			__BYTE	HANG:1;
			__BYTE	RDY:1;
#else
			__BYTE	RDY:1;
			__BYTE	HANG:1;
			__BYTE	CERS:1;
			__BYTE	ESPS:1;
			__BYTE	SERS:1;
			__BYTE	PGMS:1;
			__BYTE	ST0:1;
			__BYTE	ST1:1;
#endif
	} bitc;
} DFSASTR;

__IO_EXTENDED	 const  DFSASTR	IO_DFSA;
#define	_dfsa		(IO_DFSA)
#define	DFSA		(IO_DFSA.byte)
#define	DFSA_RDY  	(IO_DFSA.bit.RDY)
#define	DFSA_HANG  	(IO_DFSA.bit.HANG)
#define	DFSA_CERS  	(IO_DFSA.bit.CERS)
#define	DFSA_ESPS  	(IO_DFSA.bit.ESPS)
#define	DFSA_SERS  	(IO_DFSA.bit.SERS)
#define	DFSA_PGMS  	(IO_DFSA.bit.PGMS)
#define	DFSA_ST  	(IO_DFSA.bit.ST)
#define	DFSA_ST0  	(IO_DFSA.bitc.ST0)
#define	DFSA_ST1  	(IO_DFSA.bitc.ST1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFISA,   locate=0x3EB
#pragma segment FAR_DATA=IO_DFISA, locate=0x3EB
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	ERINT:1;
			__BYTE	FININT:1;
			__BYTE	IDLINT:1;
			__BYTE	WBINT:1;
			__BYTE	WPSINT:1;
			__BYTE	HANGINT:1;
			__BYTE	RDYINT:1;
#else
			__BYTE	RDYINT:1;
			__BYTE	HANGINT:1;
			__BYTE	WPSINT:1;
			__BYTE	WBINT:1;
			__BYTE	IDLINT:1;
			__BYTE	FININT:1;
			__BYTE	ERINT:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	ERINT:1;
			__BYTE	FININT:1;
			__BYTE	IDLINT:1;
			__BYTE	WBINT:1;
			__BYTE	WPSINT:1;
			__BYTE	HANGINT:1;
			__BYTE	RDYINT:1;
#else
			__BYTE	RDYINT:1;
			__BYTE	HANGINT:1;
			__BYTE	WPSINT:1;
			__BYTE	WBINT:1;
			__BYTE	IDLINT:1;
			__BYTE	FININT:1;
			__BYTE	ERINT:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DFISASTR;

__IO_EXTENDED	  DFISASTR	IO_DFISA;
#define	_dfisa		(IO_DFISA)
#define	DFISA		(IO_DFISA.byte)
#define	DFISA_RDYINT  	(IO_DFISA.bit.RDYINT)
#define	DFISA_HANGINT  	(IO_DFISA.bit.HANGINT)
#define	DFISA_WPSINT  	(IO_DFISA.bit.WPSINT)
#define	DFISA_WBINT  	(IO_DFISA.bit.WBINT)
#define	DFISA_IDLINT  	(IO_DFISA.bit.IDLINT)
#define	DFISA_FININT  	(IO_DFISA.bit.FININT)
#define	DFISA_ERINT  	(IO_DFISA.bit.ERINT)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFWC0A,   locate=0x3F9
#pragma segment FAR_DATA=IO_DFWC0A, locate=0x3F9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	SA:4;
			__BYTE	SAS:1;
#else
			__BYTE	SAS:1;
			__BYTE	SA:4;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	SA4:1;
			__BYTE	SA3:1;
			__BYTE	SA2:1;
			__BYTE	SA1:1;
			__BYTE	SAS:1;
#else
			__BYTE	SAS:1;
			__BYTE	SA1:1;
			__BYTE	SA2:1;
			__BYTE	SA3:1;
			__BYTE	SA4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} DFWC0ASTR;

__IO_EXTENDED	  DFWC0ASTR	IO_DFWC0A;
#define	_dfwc0a		(IO_DFWC0A)
#define	DFWC0A		(IO_DFWC0A.byte)
#define	DFWC0A_SAS  	(IO_DFWC0A.bit.SAS)
#define	DFWC0A_SA  	(IO_DFWC0A.bit.SA)
#define	DFWC0A_SA1  	(IO_DFWC0A.bitc.SA1)
#define	DFWC0A_SA2  	(IO_DFWC0A.bitc.SA2)
#define	DFWC0A_SA3  	(IO_DFWC0A.bitc.SA3)
#define	DFWC0A_SA4  	(IO_DFWC0A.bitc.SA4)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DFWC1A,   locate=0x3FD
#pragma segment FAR_DATA=IO_DFWC1A, locate=0x3FD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SA3:8;
#else
			__BYTE	SA3:8;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SA39:1;
			__BYTE	SA38:1;
			__BYTE	SA37:1;
			__BYTE	SA36:1;
			__BYTE	SA35:1;
			__BYTE	SA34:1;
			__BYTE	SA33:1;
			__BYTE	SA32:1;
#else
			__BYTE	SA32:1;
			__BYTE	SA33:1;
			__BYTE	SA34:1;
			__BYTE	SA35:1;
			__BYTE	SA36:1;
			__BYTE	SA37:1;
			__BYTE	SA38:1;
			__BYTE	SA39:1;
#endif
	} bitc;
} DFWC1ASTR;

__IO_EXTENDED	  DFWC1ASTR	IO_DFWC1A;
#define	_dfwc1a		(IO_DFWC1A)
#define	DFWC1A		(IO_DFWC1A.byte)
#define	DFWC1A_SA3  	(IO_DFWC1A.bit.SA3)
#define	DFWC1A_SA32  	(IO_DFWC1A.bitc.SA32)
#define	DFWC1A_SA33  	(IO_DFWC1A.bitc.SA33)
#define	DFWC1A_SA34  	(IO_DFWC1A.bitc.SA34)
#define	DFWC1A_SA35  	(IO_DFWC1A.bitc.SA35)
#define	DFWC1A_SA36  	(IO_DFWC1A.bitc.SA36)
#define	DFWC1A_SA37  	(IO_DFWC1A.bitc.SA37)
#define	DFWC1A_SA38  	(IO_DFWC1A.bitc.SA38)
#define	DFWC1A_SA39  	(IO_DFWC1A.bitc.SA39)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SMCR,   locate=0x400
#pragma segment FAR_DATA=IO_SMCR, locate=0x400
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	LPMSS:1;
			__BYTE	RESV2:1;
			__BYTE	SPL:1;
			__BYTE	SMS:2;
#else
			__BYTE	SMS:2;
			__BYTE	SPL:1;
			__BYTE	RESV2:1;
			__BYTE	LPMSS:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	LPMSS:1;
			__BYTE	RESV3:1;
			__BYTE	SPL:1;
			__BYTE	SMS1:1;
			__BYTE	SMS0:1;
#else
			__BYTE	SMS0:1;
			__BYTE	SMS1:1;
			__BYTE	SPL:1;
			__BYTE	RESV3:1;
			__BYTE	LPMSS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} SMCRSTR;

__IO_EXTENDED	  SMCRSTR	IO_SMCR;
#define	_smcr		(IO_SMCR)
#define	SMCR		(IO_SMCR.byte)
#define	SMCR_SMS  	(IO_SMCR.bit.SMS)
#define	SMCR_SMS0  	(IO_SMCR.bitc.SMS0)
#define	SMCR_SMS1  	(IO_SMCR.bitc.SMS1)
#define	SMCR_SPL  	(IO_SMCR.bit.SPL)
#define	SMCR_LPMSS  	(IO_SMCR.bit.LPMSS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CKSR,   locate=0x401
#pragma segment FAR_DATA=IO_CKSR, locate=0x401
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCE:1;
			__BYTE	PCE:1;
			__BYTE	MCE:1;
			__BYTE	RCE:1;
			__BYTE	SC2S:2;
			__BYTE	SC1S:2;
#else
			__BYTE	SC1S:2;
			__BYTE	SC2S:2;
			__BYTE	RCE:1;
			__BYTE	MCE:1;
			__BYTE	PCE:1;
			__BYTE	SCE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCE:1;
			__BYTE	PCE:1;
			__BYTE	MCE:1;
			__BYTE	RCE:1;
			__BYTE	SC2S1:1;
			__BYTE	SC2S0:1;
			__BYTE	SC1S1:1;
			__BYTE	SC1S0:1;
#else
			__BYTE	SC1S0:1;
			__BYTE	SC1S1:1;
			__BYTE	SC2S0:1;
			__BYTE	SC2S1:1;
			__BYTE	RCE:1;
			__BYTE	MCE:1;
			__BYTE	PCE:1;
			__BYTE	SCE:1;
#endif
	} bitc;
} CKSRSTR;

__IO_EXTENDED	  CKSRSTR	IO_CKSR;
#define	_cksr		(IO_CKSR)
#define	CKSR		(IO_CKSR.byte)
#define	CKSR_SC1S  	(IO_CKSR.bit.SC1S)
#define	CKSR_SC1S0  	(IO_CKSR.bitc.SC1S0)
#define	CKSR_SC1S1  	(IO_CKSR.bitc.SC1S1)
#define	CKSR_SC2S  	(IO_CKSR.bit.SC2S)
#define	CKSR_SC2S0  	(IO_CKSR.bitc.SC2S0)
#define	CKSR_SC2S1  	(IO_CKSR.bitc.SC2S1)
#define	CKSR_RCE  	(IO_CKSR.bit.RCE)
#define	CKSR_MCE  	(IO_CKSR.bit.MCE)
#define	CKSR_PCE  	(IO_CKSR.bit.PCE)
#define	CKSR_SCE  	(IO_CKSR.bit.SCE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CKSSR,   locate=0x402
#pragma segment FAR_DATA=IO_CKSSR, locate=0x402
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	PCST:1;
			__BYTE	SCST:2;
			__BYTE	MCST:3;
#else
			__BYTE	MCST:3;
			__BYTE	SCST:2;
			__BYTE	PCST:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	PCST:1;
			__BYTE	SCST1:1;
			__BYTE	SCST0:1;
			__BYTE	MCST2:1;
			__BYTE	MCST1:1;
			__BYTE	MCST0:1;
#else
			__BYTE	MCST0:1;
			__BYTE	MCST1:1;
			__BYTE	MCST2:1;
			__BYTE	SCST0:1;
			__BYTE	SCST1:1;
			__BYTE	PCST:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} CKSSRSTR;

__IO_EXTENDED	  CKSSRSTR	IO_CKSSR;
#define	_ckssr		(IO_CKSSR)
#define	CKSSR		(IO_CKSSR.byte)
#define	CKSSR_MCST  	(IO_CKSSR.bit.MCST)
#define	CKSSR_MCST0  	(IO_CKSSR.bitc.MCST0)
#define	CKSSR_MCST1  	(IO_CKSSR.bitc.MCST1)
#define	CKSSR_MCST2  	(IO_CKSSR.bitc.MCST2)
#define	CKSSR_SCST  	(IO_CKSSR.bit.SCST)
#define	CKSSR_SCST0  	(IO_CKSSR.bitc.SCST0)
#define	CKSSR_SCST1  	(IO_CKSSR.bitc.SCST1)
#define	CKSSR_PCST  	(IO_CKSSR.bit.PCST)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CKMR,   locate=0x403
#pragma segment FAR_DATA=IO_CKMR, locate=0x403
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCM:1;
			__BYTE	PCM:1;
			__BYTE	MCM:1;
			__BYTE	RCM:1;
			__BYTE	SC2M:2;
			__BYTE	SC1M:2;
#else
			__BYTE	SC1M:2;
			__BYTE	SC2M:2;
			__BYTE	RCM:1;
			__BYTE	MCM:1;
			__BYTE	PCM:1;
			__BYTE	SCM:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCM:1;
			__BYTE	PCM:1;
			__BYTE	MCM:1;
			__BYTE	RCM:1;
			__BYTE	SC2M1:1;
			__BYTE	SC2M0:1;
			__BYTE	SC1M1:1;
			__BYTE	SC1M0:1;
#else
			__BYTE	SC1M0:1;
			__BYTE	SC1M1:1;
			__BYTE	SC2M0:1;
			__BYTE	SC2M1:1;
			__BYTE	RCM:1;
			__BYTE	MCM:1;
			__BYTE	PCM:1;
			__BYTE	SCM:1;
#endif
	} bitc;
} CKMRSTR;

__IO_EXTENDED	 const  CKMRSTR	IO_CKMR;
#define	_ckmr		(IO_CKMR)
#define	CKMR		(IO_CKMR.byte)
#define	CKMR_SC1M  	(IO_CKMR.bit.SC1M)
#define	CKMR_SC1M0  	(IO_CKMR.bitc.SC1M0)
#define	CKMR_SC1M1  	(IO_CKMR.bitc.SC1M1)
#define	CKMR_SC2M  	(IO_CKMR.bit.SC2M)
#define	CKMR_SC2M0  	(IO_CKMR.bitc.SC2M0)
#define	CKMR_SC2M1  	(IO_CKMR.bitc.SC2M1)
#define	CKMR_RCM  	(IO_CKMR.bit.RCM)
#define	CKMR_MCM  	(IO_CKMR.bit.MCM)
#define	CKMR_PCM  	(IO_CKMR.bit.PCM)
#define	CKMR_SCM  	(IO_CKMR.bit.SCM)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CKFCR,   locate=0x404
#pragma segment FAR_DATA=IO_CKFCR, locate=0x404
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	PC2D:4;
			__WORD	PC1D:4;
			__WORD	BCD:4;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	RCFS:1;
#else
			__WORD	RCFS:1;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	BCD:4;
			__WORD	PC1D:4;
			__WORD	PC2D:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	PC2D3:1;
			__WORD	PC2D2:1;
			__WORD	PC2D1:1;
			__WORD	PC2D0:1;
			__WORD	PC1D3:1;
			__WORD	PC1D2:1;
			__WORD	PC1D1:1;
			__WORD	PC1D0:1;
			__WORD	BCD3:1;
			__WORD	BCD2:1;
			__WORD	BCD1:1;
			__WORD	BCD0:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	RCFS:1;
#else
			__WORD	RCFS:1;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	BCD0:1;
			__WORD	BCD1:1;
			__WORD	BCD2:1;
			__WORD	BCD3:1;
			__WORD	PC1D0:1;
			__WORD	PC1D1:1;
			__WORD	PC1D2:1;
			__WORD	PC1D3:1;
			__WORD	PC2D0:1;
			__WORD	PC2D1:1;
			__WORD	PC2D2:1;
			__WORD	PC2D3:1;
#endif
	} bitc;
} CKFCRSTR;

__IO_EXTENDED	  CKFCRSTR	IO_CKFCR;
#define	_ckfcr		(IO_CKFCR)
#define	CKFCR		(IO_CKFCR.word)
#define	CKFCR_RCFS  	(IO_CKFCR.bit.RCFS)
#define	CKFCR_BCD  	(IO_CKFCR.bit.BCD)
#define	CKFCR_BCD0  	(IO_CKFCR.bitc.BCD0)
#define	CKFCR_BCD1  	(IO_CKFCR.bitc.BCD1)
#define	CKFCR_BCD2  	(IO_CKFCR.bitc.BCD2)
#define	CKFCR_BCD3  	(IO_CKFCR.bitc.BCD3)
#define	CKFCR_PC1D  	(IO_CKFCR.bit.PC1D)
#define	CKFCR_PC1D0  	(IO_CKFCR.bitc.PC1D0)
#define	CKFCR_PC1D1  	(IO_CKFCR.bitc.PC1D1)
#define	CKFCR_PC1D2  	(IO_CKFCR.bitc.PC1D2)
#define	CKFCR_PC1D3  	(IO_CKFCR.bitc.PC1D3)
#define	CKFCR_PC2D  	(IO_CKFCR.bit.PC2D)
#define	CKFCR_PC2D0  	(IO_CKFCR.bitc.PC2D0)
#define	CKFCR_PC2D1  	(IO_CKFCR.bitc.PC2D1)
#define	CKFCR_PC2D2  	(IO_CKFCR.bitc.PC2D2)
#define	CKFCR_PC2D3  	(IO_CKFCR.bitc.PC2D3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PLLCR,   locate=0x406
#pragma segment FAR_DATA=IO_PLLCR, locate=0x406
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	VMS:3;
			__WORD	RESV1:1;
			__WORD	PMS:4;
#else
			__WORD	PMS:4;
			__WORD	RESV1:1;
			__WORD	VMS:3;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	VMS2:1;
			__WORD	VMS1:1;
			__WORD	VMS0:1;
			__WORD	RESV4:1;
			__WORD	PMS3:1;
			__WORD	PMS2:1;
			__WORD	PMS1:1;
			__WORD	PMS0:1;
#else
			__WORD	PMS0:1;
			__WORD	PMS1:1;
			__WORD	PMS2:1;
			__WORD	PMS3:1;
			__WORD	RESV4:1;
			__WORD	VMS0:1;
			__WORD	VMS1:1;
			__WORD	VMS2:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} PLLCRSTR;

__IO_EXTENDED	  PLLCRSTR	IO_PLLCR;
#define	_pllcr		(IO_PLLCR)
#define	PLLCR		(IO_PLLCR.word)
#define	PLLCR_PMS  	(IO_PLLCR.bit.PMS)
#define	PLLCR_PMS0  	(IO_PLLCR.bitc.PMS0)
#define	PLLCR_PMS1  	(IO_PLLCR.bitc.PMS1)
#define	PLLCR_PMS2  	(IO_PLLCR.bitc.PMS2)
#define	PLLCR_PMS3  	(IO_PLLCR.bitc.PMS3)
#define	PLLCR_VMS  	(IO_PLLCR.bit.VMS)
#define	PLLCR_VMS0  	(IO_PLLCR.bitc.VMS0)
#define	PLLCR_VMS1  	(IO_PLLCR.bitc.VMS1)
#define	PLLCR_VMS2  	(IO_PLLCR.bitc.VMS2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RCTCR,   locate=0x408
#pragma segment FAR_DATA=IO_RCTCR, locate=0x408
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RCTIE:1;
			__BYTE	RCTIF:1;
			__BYTE	RCTR:1;
			__BYTE	RCTI:4;
#else
			__BYTE	RCTI:4;
			__BYTE	RCTR:1;
			__BYTE	RCTIF:1;
			__BYTE	RCTIE:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RCTIE:1;
			__BYTE	RCTIF:1;
			__BYTE	RCTR:1;
			__BYTE	RCTI3:1;
			__BYTE	RCTI2:1;
			__BYTE	RCTI1:1;
			__BYTE	RCTI0:1;
#else
			__BYTE	RCTI0:1;
			__BYTE	RCTI1:1;
			__BYTE	RCTI2:1;
			__BYTE	RCTI3:1;
			__BYTE	RCTR:1;
			__BYTE	RCTIF:1;
			__BYTE	RCTIE:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} RCTCRSTR;

__IO_EXTENDED	  RCTCRSTR	IO_RCTCR;
#define	_rctcr		(IO_RCTCR)
#define	RCTCR		(IO_RCTCR.byte)
#define	RCTCR_RCTI  	(IO_RCTCR.bit.RCTI)
#define	RCTCR_RCTI0  	(IO_RCTCR.bitc.RCTI0)
#define	RCTCR_RCTI1  	(IO_RCTCR.bitc.RCTI1)
#define	RCTCR_RCTI2  	(IO_RCTCR.bitc.RCTI2)
#define	RCTCR_RCTI3  	(IO_RCTCR.bitc.RCTI3)
#define	RCTCR_RCTR  	(IO_RCTCR.bit.RCTR)
#define	RCTCR_RCTIF  	(IO_RCTCR.bit.RCTIF)
#define	RCTCR_RCTIE  	(IO_RCTCR.bit.RCTIE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_MCTCR,   locate=0x409
#pragma segment FAR_DATA=IO_MCTCR, locate=0x409
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	MCTIE:1;
			__BYTE	MCTIF:1;
			__BYTE	MCTR:1;
			__BYTE	MCTI:4;
#else
			__BYTE	MCTI:4;
			__BYTE	MCTR:1;
			__BYTE	MCTIF:1;
			__BYTE	MCTIE:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	MCTIE:1;
			__BYTE	MCTIF:1;
			__BYTE	MCTR:1;
			__BYTE	MCTI3:1;
			__BYTE	MCTI2:1;
			__BYTE	MCTI1:1;
			__BYTE	MCTI0:1;
#else
			__BYTE	MCTI0:1;
			__BYTE	MCTI1:1;
			__BYTE	MCTI2:1;
			__BYTE	MCTI3:1;
			__BYTE	MCTR:1;
			__BYTE	MCTIF:1;
			__BYTE	MCTIE:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} MCTCRSTR;

__IO_EXTENDED	  MCTCRSTR	IO_MCTCR;
#define	_mctcr		(IO_MCTCR)
#define	MCTCR		(IO_MCTCR.byte)
#define	MCTCR_MCTI  	(IO_MCTCR.bit.MCTI)
#define	MCTCR_MCTI0  	(IO_MCTCR.bitc.MCTI0)
#define	MCTCR_MCTI1  	(IO_MCTCR.bitc.MCTI1)
#define	MCTCR_MCTI2  	(IO_MCTCR.bitc.MCTI2)
#define	MCTCR_MCTI3  	(IO_MCTCR.bitc.MCTI3)
#define	MCTCR_MCTR  	(IO_MCTCR.bit.MCTR)
#define	MCTCR_MCTIF  	(IO_MCTCR.bit.MCTIF)
#define	MCTCR_MCTIE  	(IO_MCTCR.bit.MCTIE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SCTCR,   locate=0x40A
#pragma segment FAR_DATA=IO_SCTCR, locate=0x40A
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV5:1;
			__BYTE	SCTIE:1;
			__BYTE	SCTIF:1;
			__BYTE	SCTR:1;
			__BYTE	RESV1:1;
			__BYTE	SCTI:3;
#else
			__BYTE	SCTI:3;
			__BYTE	RESV1:1;
			__BYTE	SCTR:1;
			__BYTE	SCTIF:1;
			__BYTE	SCTIE:1;
			__BYTE	RESV5:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	SCTIE:1;
			__BYTE	SCTIF:1;
			__BYTE	SCTR:1;
			__BYTE	RESV3:1;
			__BYTE	SCTI2:1;
			__BYTE	SCTI1:1;
			__BYTE	SCTI0:1;
#else
			__BYTE	SCTI0:1;
			__BYTE	SCTI1:1;
			__BYTE	SCTI2:1;
			__BYTE	RESV3:1;
			__BYTE	SCTR:1;
			__BYTE	SCTIF:1;
			__BYTE	SCTIE:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} SCTCRSTR;

__IO_EXTENDED	  SCTCRSTR	IO_SCTCR;
#define	_sctcr		(IO_SCTCR)
#define	SCTCR		(IO_SCTCR.byte)
#define	SCTCR_SCTI  	(IO_SCTCR.bit.SCTI)
#define	SCTCR_SCTI0  	(IO_SCTCR.bitc.SCTI0)
#define	SCTCR_SCTI1  	(IO_SCTCR.bitc.SCTI1)
#define	SCTCR_SCTI2  	(IO_SCTCR.bitc.SCTI2)
#define	SCTCR_SCTR  	(IO_SCTCR.bit.SCTR)
#define	SCTCR_SCTIF  	(IO_SCTCR.bit.SCTIF)
#define	SCTCR_SCTIE  	(IO_SCTCR.bit.SCTIE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RCCSRC,   locate=0x40B
#pragma segment FAR_DATA=IO_RCCSRC, locate=0x40B
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCMF:1;
			__BYTE	MCMF:1;
			__BYTE	WRST:1;
			__BYTE	SRST:1;
			__BYTE	SCRST:1;
			__BYTE	MCRST:1;
			__BYTE	ERST:1;
			__BYTE	PRST:1;
#else
			__BYTE	PRST:1;
			__BYTE	ERST:1;
			__BYTE	MCRST:1;
			__BYTE	SCRST:1;
			__BYTE	SRST:1;
			__BYTE	WRST:1;
			__BYTE	MCMF:1;
			__BYTE	SCMF:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCMF:1;
			__BYTE	MCMF:1;
			__BYTE	WRST:1;
			__BYTE	SRST:1;
			__BYTE	SCRST:1;
			__BYTE	MCRST:1;
			__BYTE	ERST:1;
			__BYTE	PRST:1;
#else
			__BYTE	PRST:1;
			__BYTE	ERST:1;
			__BYTE	MCRST:1;
			__BYTE	SCRST:1;
			__BYTE	SRST:1;
			__BYTE	WRST:1;
			__BYTE	MCMF:1;
			__BYTE	SCMF:1;
#endif
	} bitc;
} RCCSRCSTR;

__IO_EXTENDED	 const  RCCSRCSTR	IO_RCCSRC;
#define	_rccsrc		(IO_RCCSRC)
#define	RCCSRC		(IO_RCCSRC.byte)
#define	RCCSRC_PRST  	(IO_RCCSRC.bit.PRST)
#define	RCCSRC_ERST  	(IO_RCCSRC.bit.ERST)
#define	RCCSRC_MCRST  	(IO_RCCSRC.bit.MCRST)
#define	RCCSRC_SCRST  	(IO_RCCSRC.bit.SCRST)
#define	RCCSRC_SRST  	(IO_RCCSRC.bit.SRST)
#define	RCCSRC_WRST  	(IO_RCCSRC.bit.WRST)
#define	RCCSRC_MCMF  	(IO_RCCSRC.bit.MCMF)
#define	RCCSRC_SCMF  	(IO_RCCSRC.bit.SCMF)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RCR,   locate=0x40C
#pragma segment FAR_DATA=IO_RCR, locate=0x40C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	SCSDI:1;
			__BYTE	MCSDI:1;
			__BYTE	CSDRE:1;
			__BYTE	LVDE:1;
			__BYTE	LVRE:1;
			__BYTE	SRSTG:1;
#else
			__BYTE	SRSTG:1;
			__BYTE	LVRE:1;
			__BYTE	LVDE:1;
			__BYTE	CSDRE:1;
			__BYTE	MCSDI:1;
			__BYTE	SCSDI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	SCSDI:1;
			__BYTE	MCSDI:1;
			__BYTE	CSDRE:1;
			__BYTE	LVDE:1;
			__BYTE	LVRE:1;
			__BYTE	SRSTG:1;
#else
			__BYTE	SRSTG:1;
			__BYTE	LVRE:1;
			__BYTE	LVDE:1;
			__BYTE	CSDRE:1;
			__BYTE	MCSDI:1;
			__BYTE	SCSDI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} RCRSTR;

__IO_EXTENDED	  RCRSTR	IO_RCR;
#define	_rcr		(IO_RCR)
#define	RCR		(IO_RCR.byte)
#define	RCR_SRSTG  	(IO_RCR.bit.SRSTG)
#define	RCR_LVRE  	(IO_RCR.bit.LVRE)
#define	RCR_LVDE  	(IO_RCR.bit.LVDE)
#define	RCR_CSDRE  	(IO_RCR.bit.CSDRE)
#define	RCR_MCSDI  	(IO_RCR.bit.MCSDI)
#define	RCR_SCSDI  	(IO_RCR.bit.SCSDI)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_RCCSR,   locate=0x40D
#pragma segment FAR_DATA=IO_RCCSR, locate=0x40D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCMF:1;
			__BYTE	MCMF:1;
			__BYTE	WRST:1;
			__BYTE	SRST:1;
			__BYTE	SCRST:1;
			__BYTE	MCRST:1;
			__BYTE	ERST:1;
			__BYTE	PRST:1;
#else
			__BYTE	PRST:1;
			__BYTE	ERST:1;
			__BYTE	MCRST:1;
			__BYTE	SCRST:1;
			__BYTE	SRST:1;
			__BYTE	WRST:1;
			__BYTE	MCMF:1;
			__BYTE	SCMF:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SCMF:1;
			__BYTE	MCMF:1;
			__BYTE	WRST:1;
			__BYTE	SRST:1;
			__BYTE	SCRST:1;
			__BYTE	MCRST:1;
			__BYTE	ERST:1;
			__BYTE	PRST:1;
#else
			__BYTE	PRST:1;
			__BYTE	ERST:1;
			__BYTE	MCRST:1;
			__BYTE	SCRST:1;
			__BYTE	SRST:1;
			__BYTE	WRST:1;
			__BYTE	MCMF:1;
			__BYTE	SCMF:1;
#endif
	} bitc;
} RCCSRSTR;

__IO_EXTENDED	 const  RCCSRSTR	IO_RCCSR;
#define	_rccsr		(IO_RCCSR)
#define	RCCSR		(IO_RCCSR.byte)
#define	RCCSR_PRST  	(IO_RCCSR.bit.PRST)
#define	RCCSR_ERST  	(IO_RCCSR.bit.ERST)
#define	RCCSR_MCRST  	(IO_RCCSR.bit.MCRST)
#define	RCCSR_SCRST  	(IO_RCCSR.bit.SCRST)
#define	RCCSR_SRST  	(IO_RCCSR.bit.SRST)
#define	RCCSR_WRST  	(IO_RCCSR.bit.WRST)
#define	RCCSR_MCMF  	(IO_RCCSR.bit.MCMF)
#define	RCCSR_SCMF  	(IO_RCCSR.bit.SCMF)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WDT,   locate=0x40E
#pragma segment FAR_DATA=IO_WDT, locate=0x40E
#endif

__IO_EXTENDED	union {
	__WORD	word;
    struct {
        __BYTE	IO_WDTC;
        __BYTE	IO_WDTCP;
    } byte;
    union {
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV011:1;
			__WORD	RESV010:1;
			__WORD	RESV09:1;
			__WORD	RESV08:1;
			__WORD	RESV07:1;
			__WORD	RESV06:1;
			__WORD	RESV05:1;
			__WORD	RESV04:1;
			__WORD	WD:1;
			__WORD	RSTP:1;
			__WORD	WTCS:2;
			__WORD	WTI:4;
#else
			__WORD	WTI:4;
			__WORD	WTCS:2;
			__WORD	RSTP:1;
			__WORD	WD:1;
			__WORD	RESV04:1;
			__WORD	RESV05:1;
			__WORD	RESV06:1;
			__WORD	RESV07:1;
			__WORD	RESV08:1;
			__WORD	RESV09:1;
			__WORD	RESV010:1;
			__WORD	RESV011:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV015:1;
			__WORD	RESV014:1;
			__WORD	RESV013:1;
			__WORD	RESV012:1;
			__WORD	RESV011:1;
			__WORD	RESV010:1;
			__WORD	RESV09:1;
			__WORD	RESV08:1;
			__WORD	WD:1;
			__WORD	RSTP:1;
			__WORD	WTCS1:1;
			__WORD	WTCS0:1;
			__WORD	WTI3:1;
			__WORD	WTI2:1;
			__WORD	WTI1:1;
			__WORD	WTI0:1;
#else
			__WORD	WTI0:1;
			__WORD	WTI1:1;
			__WORD	WTI2:1;
			__WORD	WTI3:1;
			__WORD	WTCS0:1;
			__WORD	WTCS1:1;
			__WORD	RSTP:1;
			__WORD	WD:1;
			__WORD	RESV08:1;
			__WORD	RESV09:1;
			__WORD	RESV010:1;
			__WORD	RESV011:1;
			__WORD	RESV012:1;
			__WORD	RESV013:1;
			__WORD	RESV014:1;
			__WORD	RESV015:1;
#endif
		} bitc;
	} WDTC;
} IO_WDT;

#define	WDT			(IO_WDT.word)
#define	WDTCP_		(IO_WDT.byte.IO_WDTCP)
#define	WDTC_		(IO_WDT.byte.IO_WDTC)
#define	WDTC_WTI  	(IO_WDT.WDTC.bit.WTI)
#define	WDTC_WTI0  	(IO_WDT.WDTC.bitc.WTI0)
#define	WDTC_WTI1  	(IO_WDT.WDTC.bitc.WTI1)
#define	WDTC_WTI2  	(IO_WDT.WDTC.bitc.WTI2)
#define	WDTC_WTI3  	(IO_WDT.WDTC.bitc.WTI3)
#define	WDTC_WTCS  	(IO_WDT.WDTC.bit.WTCS)
#define	WDTC_WTCS0 	(IO_WDT.WDTC.bitc.WTCS0)
#define	WDTC_WTCS1 	(IO_WDT.WDTC.bitc.WTCS1)
#define	WDTC_RSTP  	(IO_WDT.WDTC.bit.RSTP)
#define	WDTC_WD  	(IO_WDT.WDTC.bit.WD)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_COAR,   locate=0x415
#pragma segment FAR_DATA=IO_COAR, locate=0x415
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RUNM1:1;
			__BYTE	RUNC1:1;
			__BYTE	CKOXE1:1;
			__BYTE	CKOE1:1;
			__BYTE	RUNM0:1;
			__BYTE	RUNC0:1;
			__BYTE	CKOXE0:1;
			__BYTE	CKOE0:1;
#else
			__BYTE	CKOE0:1;
			__BYTE	CKOXE0:1;
			__BYTE	RUNC0:1;
			__BYTE	RUNM0:1;
			__BYTE	CKOE1:1;
			__BYTE	CKOXE1:1;
			__BYTE	RUNC1:1;
			__BYTE	RUNM1:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RUNM1:1;
			__BYTE	RUNC1:1;
			__BYTE	CKOXE1:1;
			__BYTE	CKOE1:1;
			__BYTE	RUNM0:1;
			__BYTE	RUNC0:1;
			__BYTE	CKOXE0:1;
			__BYTE	CKOE0:1;
#else
			__BYTE	CKOE0:1;
			__BYTE	CKOXE0:1;
			__BYTE	RUNC0:1;
			__BYTE	RUNM0:1;
			__BYTE	CKOE1:1;
			__BYTE	CKOXE1:1;
			__BYTE	RUNC1:1;
			__BYTE	RUNM1:1;
#endif
	} bitc;
} COARSTR;

__IO_EXTENDED	  COARSTR	IO_COAR;
#define	_coar		(IO_COAR)
#define	COAR		(IO_COAR.byte)
#define	COAR_CKOE0  	(IO_COAR.bit.CKOE0)
#define	COAR_CKOXE0  	(IO_COAR.bit.CKOXE0)
#define	COAR_RUNC0  	(IO_COAR.bit.RUNC0)
#define	COAR_RUNM0  	(IO_COAR.bit.RUNM0)
#define	COAR_CKOE1  	(IO_COAR.bit.CKOE1)
#define	COAR_CKOXE1  	(IO_COAR.bit.CKOXE1)
#define	COAR_RUNC1  	(IO_COAR.bit.RUNC1)
#define	COAR_RUNM1  	(IO_COAR.bit.RUNM1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_COCR0,   locate=0x416
#pragma segment FAR_DATA=IO_COCR0, locate=0x416
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV2:1;
			__BYTE	DIV:3;
			__BYTE	SEL:4;
#else
			__BYTE	SEL:4;
			__BYTE	DIV:3;
			__BYTE	RESV2:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	DIV2:1;
			__BYTE	DIV1:1;
			__BYTE	DIV0:1;
			__BYTE	SEL3:1;
			__BYTE	SEL2:1;
			__BYTE	SEL1:1;
			__BYTE	SEL0:1;
#else
			__BYTE	SEL0:1;
			__BYTE	SEL1:1;
			__BYTE	SEL2:1;
			__BYTE	SEL3:1;
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	DIV2:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} COCR0STR;

__IO_EXTENDED	  COCR0STR	IO_COCR0;
#define	_cocr0		(IO_COCR0)
#define	COCR0		(IO_COCR0.byte)
#define	COCR0_SEL  	(IO_COCR0.bit.SEL)
#define	COCR0_SEL0  	(IO_COCR0.bitc.SEL0)
#define	COCR0_SEL1  	(IO_COCR0.bitc.SEL1)
#define	COCR0_SEL2  	(IO_COCR0.bitc.SEL2)
#define	COCR0_SEL3  	(IO_COCR0.bitc.SEL3)
#define	COCR0_DIV  	(IO_COCR0.bit.DIV)
#define	COCR0_DIV0  	(IO_COCR0.bitc.DIV0)
#define	COCR0_DIV1  	(IO_COCR0.bitc.DIV1)
#define	COCR0_DIV2  	(IO_COCR0.bitc.DIV2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_COCR1,   locate=0x417
#pragma segment FAR_DATA=IO_COCR1, locate=0x417
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV2:1;
			__BYTE	DIV:3;
			__BYTE	SEL:4;
#else
			__BYTE	SEL:4;
			__BYTE	DIV:3;
			__BYTE	RESV2:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	DIV2:1;
			__BYTE	DIV1:1;
			__BYTE	DIV0:1;
			__BYTE	SEL3:1;
			__BYTE	SEL2:1;
			__BYTE	SEL1:1;
			__BYTE	SEL0:1;
#else
			__BYTE	SEL0:1;
			__BYTE	SEL1:1;
			__BYTE	SEL2:1;
			__BYTE	SEL3:1;
			__BYTE	DIV0:1;
			__BYTE	DIV1:1;
			__BYTE	DIV2:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} COCR1STR;

__IO_EXTENDED	  COCR1STR	IO_COCR1;
#define	_cocr1		(IO_COCR1)
#define	COCR1		(IO_COCR1.byte)
#define	COCR1_SEL  	(IO_COCR1.bit.SEL)
#define	COCR1_SEL0  	(IO_COCR1.bitc.SEL0)
#define	COCR1_SEL1  	(IO_COCR1.bitc.SEL1)
#define	COCR1_SEL2  	(IO_COCR1.bitc.SEL2)
#define	COCR1_SEL3  	(IO_COCR1.bitc.SEL3)
#define	COCR1_DIV  	(IO_COCR1.bit.DIV)
#define	COCR1_DIV0  	(IO_COCR1.bitc.DIV0)
#define	COCR1_DIV1  	(IO_COCR1.bitc.DIV1)
#define	COCR1_DIV2  	(IO_COCR1.bitc.DIV2)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WDTEC,   locate=0x420
#pragma segment FAR_DATA=IO_WDTEC, locate=0x420
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	WTWE:1;
			__BYTE	WTLI:4;
#else
			__BYTE	WTLI:4;
			__BYTE	WTWE:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	WTWE:1;
			__BYTE	WTLI3:1;
			__BYTE	WTLI2:1;
			__BYTE	WTLI1:1;
			__BYTE	WTLI0:1;
#else
			__BYTE	WTLI0:1;
			__BYTE	WTLI1:1;
			__BYTE	WTLI2:1;
			__BYTE	WTLI3:1;
			__BYTE	WTWE:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} WDTECSTR;

__IO_EXTENDED	  WDTECSTR	IO_WDTEC;
#define	_wdtec		(IO_WDTEC)
#define	WDTEC		(IO_WDTEC.byte)
#define	WDTEC_WTLI  	(IO_WDTEC.bit.WTLI)
#define	WDTEC_WTLI0  	(IO_WDTEC.bitc.WTLI0)
#define	WDTEC_WTLI1  	(IO_WDTEC.bitc.WTLI1)
#define	WDTEC_WTLI2  	(IO_WDTEC.bitc.WTLI2)
#define	WDTEC_WTLI3  	(IO_WDTEC.bitc.WTLI3)
#define	WDTEC_WTWE  	(IO_WDTEC.bit.WTWE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRCR,   locate=0x42C
#pragma segment FAR_DATA=IO_VRCR, locate=0x42C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HPM:2;
			__BYTE	RESV3:1;
			__BYTE	LPMA:2;
			__BYTE	RESV1:1;
			__BYTE	LPMB:2;
#else
			__BYTE	LPMB:2;
			__BYTE	RESV1:1;
			__BYTE	LPMA:2;
			__BYTE	RESV3:1;
			__BYTE	HPM:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HPM1:1;
			__BYTE	HPM0:1;
			__BYTE	RESV5:1;
			__BYTE	LPMA1:1;
			__BYTE	LPMA0:1;
			__BYTE	RESV2:1;
			__BYTE	LPMB1:1;
			__BYTE	LPMB0:1;
#else
			__BYTE	LPMB0:1;
			__BYTE	LPMB1:1;
			__BYTE	RESV2:1;
			__BYTE	LPMA0:1;
			__BYTE	LPMA1:1;
			__BYTE	RESV5:1;
			__BYTE	HPM0:1;
			__BYTE	HPM1:1;
#endif
	} bitc;
} VRCRSTR;

__IO_EXTENDED	  VRCRSTR	IO_VRCR;
#define	_vrcr		(IO_VRCR)
#define	VRCR		(IO_VRCR.byte)
#define	VRCR_LPMB  	(IO_VRCR.bit.LPMB)
#define	VRCR_LPMB0  	(IO_VRCR.bitc.LPMB0)
#define	VRCR_LPMB1  	(IO_VRCR.bitc.LPMB1)
#define	VRCR_LPMA  	(IO_VRCR.bit.LPMA)
#define	VRCR_LPMA0  	(IO_VRCR.bitc.LPMA0)
#define	VRCR_LPMA1  	(IO_VRCR.bitc.LPMA1)
#define	VRCR_HPM  	(IO_VRCR.bit.HPM)
#define	VRCR_HPM0  	(IO_VRCR.bitc.HPM0)
#define	VRCR_HPM1  	(IO_VRCR.bitc.HPM1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CILCR,   locate=0x42D
#pragma segment FAR_DATA=IO_CILCR, locate=0x42D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LVINTE:1;
			__BYTE	LVINT:1;
			__BYTE	LVHYS:1;
			__BYTE	FCI:1;
			__BYTE	LVL:4;
#else
			__BYTE	LVL:4;
			__BYTE	FCI:1;
			__BYTE	LVHYS:1;
			__BYTE	LVINT:1;
			__BYTE	LVINTE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	LVINTE:1;
			__BYTE	LVINT:1;
			__BYTE	LVHYS:1;
			__BYTE	FCI:1;
			__BYTE	LVL3:1;
			__BYTE	LVL2:1;
			__BYTE	LVL1:1;
			__BYTE	LVL0:1;
#else
			__BYTE	LVL0:1;
			__BYTE	LVL1:1;
			__BYTE	LVL2:1;
			__BYTE	LVL3:1;
			__BYTE	FCI:1;
			__BYTE	LVHYS:1;
			__BYTE	LVINT:1;
			__BYTE	LVINTE:1;
#endif
	} bitc;
} CILCRSTR;

__IO_EXTENDED	  CILCRSTR	IO_CILCR;
#define	_cilcr		(IO_CILCR)
#define	CILCR		(IO_CILCR.byte)
#define	CILCR_LVL  	(IO_CILCR.bit.LVL)
#define	CILCR_LVL0  	(IO_CILCR.bitc.LVL0)
#define	CILCR_LVL1  	(IO_CILCR.bitc.LVL1)
#define	CILCR_LVL2  	(IO_CILCR.bitc.LVL2)
#define	CILCR_LVL3  	(IO_CILCR.bitc.LVL3)
#define	CILCR_FCI  	(IO_CILCR.bit.FCI)
#define	CILCR_LVHYS  	(IO_CILCR.bit.LVHYS)
#define	CILCR_LVINT  	(IO_CILCR.bit.LVINT)
#define	CILCR_LVINTE  	(IO_CILCR.bit.LVINTE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ESMCR,   locate=0x42E
#pragma segment FAR_DATA=IO_ESMCR, locate=0x42E
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	FPDS:1;
			__BYTE	BSD:4;
#else
			__BYTE	BSD:4;
			__BYTE	FPDS:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	FPDS:1;
			__BYTE	BSD3:1;
			__BYTE	BSD2:1;
			__BYTE	BSD1:1;
			__BYTE	BSD0:1;
#else
			__BYTE	BSD0:1;
			__BYTE	BSD1:1;
			__BYTE	BSD2:1;
			__BYTE	BSD3:1;
			__BYTE	FPDS:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ESMCRSTR;

__IO_EXTENDED	  ESMCRSTR	IO_ESMCR;
#define	_esmcr		(IO_ESMCR)
#define	ESMCR		(IO_ESMCR.byte)
#define	ESMCR_BSD  	(IO_ESMCR.bit.BSD)
#define	ESMCR_BSD0  	(IO_ESMCR.bitc.BSD0)
#define	ESMCR_BSD1  	(IO_ESMCR.bitc.BSD1)
#define	ESMCR_BSD2  	(IO_ESMCR.bitc.BSD2)
#define	ESMCR_BSD3  	(IO_ESMCR.bitc.BSD3)
#define	ESMCR_FPDS  	(IO_ESMCR.bit.FPDS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR00,   locate=0x430
#pragma segment FAR_DATA=IO_DDR00, locate=0x430
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR00STR;

__IO_EXTENDED	  DDR00STR	IO_DDR00;
#define	_ddr00		(IO_DDR00)
#define	DDR00		(IO_DDR00.byte)
#define	DDR00_D0  	(IO_DDR00.bit.D0)
#define	DDR00_D1  	(IO_DDR00.bit.D1)
#define	DDR00_D2  	(IO_DDR00.bit.D2)
#define	DDR00_D3  	(IO_DDR00.bit.D3)
#define	DDR00_D4  	(IO_DDR00.bit.D4)
#define	DDR00_D5  	(IO_DDR00.bit.D5)
#define	DDR00_D6  	(IO_DDR00.bit.D6)
#define	DDR00_D7  	(IO_DDR00.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR01,   locate=0x431
#pragma segment FAR_DATA=IO_DDR01, locate=0x431
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR01STR;

__IO_EXTENDED	  DDR01STR	IO_DDR01;
#define	_ddr01		(IO_DDR01)
#define	DDR01		(IO_DDR01.byte)
#define	DDR01_D0  	(IO_DDR01.bit.D0)
#define	DDR01_D1  	(IO_DDR01.bit.D1)
#define	DDR01_D2  	(IO_DDR01.bit.D2)
#define	DDR01_D3  	(IO_DDR01.bit.D3)
#define	DDR01_D4  	(IO_DDR01.bit.D4)
#define	DDR01_D5  	(IO_DDR01.bit.D5)
#define	DDR01_D6  	(IO_DDR01.bit.D6)
#define	DDR01_D7  	(IO_DDR01.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR02,   locate=0x432
#pragma segment FAR_DATA=IO_DDR02, locate=0x432
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR02STR;

__IO_EXTENDED	  DDR02STR	IO_DDR02;
#define	_ddr02		(IO_DDR02)
#define	DDR02		(IO_DDR02.byte)
#define	DDR02_D0  	(IO_DDR02.bit.D0)
#define	DDR02_D1  	(IO_DDR02.bit.D1)
#define	DDR02_D2  	(IO_DDR02.bit.D2)
#define	DDR02_D3  	(IO_DDR02.bit.D3)
#define	DDR02_D4  	(IO_DDR02.bit.D4)
#define	DDR02_D5  	(IO_DDR02.bit.D5)
#define	DDR02_D6  	(IO_DDR02.bit.D6)
#define	DDR02_D7  	(IO_DDR02.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR03,   locate=0x433
#pragma segment FAR_DATA=IO_DDR03, locate=0x433
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR03STR;

__IO_EXTENDED	  DDR03STR	IO_DDR03;
#define	_ddr03		(IO_DDR03)
#define	DDR03		(IO_DDR03.byte)
#define	DDR03_D0  	(IO_DDR03.bit.D0)
#define	DDR03_D1  	(IO_DDR03.bit.D1)
#define	DDR03_D2  	(IO_DDR03.bit.D2)
#define	DDR03_D3  	(IO_DDR03.bit.D3)
#define	DDR03_D4  	(IO_DDR03.bit.D4)
#define	DDR03_D5  	(IO_DDR03.bit.D5)
#define	DDR03_D6  	(IO_DDR03.bit.D6)
#define	DDR03_D7  	(IO_DDR03.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR04,   locate=0x434
#pragma segment FAR_DATA=IO_DDR04, locate=0x434
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR04STR;

__IO_EXTENDED	  DDR04STR	IO_DDR04;
#define	_ddr04		(IO_DDR04)
#define	DDR04		(IO_DDR04.byte)
#define	DDR04_D0  	(IO_DDR04.bit.D0)
#define	DDR04_D1  	(IO_DDR04.bit.D1)
#define	DDR04_D2  	(IO_DDR04.bit.D2)
#define	DDR04_D3  	(IO_DDR04.bit.D3)
#define	DDR04_D4  	(IO_DDR04.bit.D4)
#define	DDR04_D5  	(IO_DDR04.bit.D5)
#define	DDR04_D6  	(IO_DDR04.bit.D6)
#define	DDR04_D7  	(IO_DDR04.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR05,   locate=0x435
#pragma segment FAR_DATA=IO_DDR05, locate=0x435
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR05STR;

__IO_EXTENDED	  DDR05STR	IO_DDR05;
#define	_ddr05		(IO_DDR05)
#define	DDR05		(IO_DDR05.byte)
#define	DDR05_D0  	(IO_DDR05.bit.D0)
#define	DDR05_D1  	(IO_DDR05.bit.D1)
#define	DDR05_D2  	(IO_DDR05.bit.D2)
#define	DDR05_D3  	(IO_DDR05.bit.D3)
#define	DDR05_D4  	(IO_DDR05.bit.D4)
#define	DDR05_D5  	(IO_DDR05.bit.D5)
#define	DDR05_D6  	(IO_DDR05.bit.D6)
#define	DDR05_D7  	(IO_DDR05.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR06,   locate=0x436
#pragma segment FAR_DATA=IO_DDR06, locate=0x436
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR06STR;

__IO_EXTENDED	  DDR06STR	IO_DDR06;
#define	_ddr06		(IO_DDR06)
#define	DDR06		(IO_DDR06.byte)
#define	DDR06_D0  	(IO_DDR06.bit.D0)
#define	DDR06_D1  	(IO_DDR06.bit.D1)
#define	DDR06_D2  	(IO_DDR06.bit.D2)
#define	DDR06_D3  	(IO_DDR06.bit.D3)
#define	DDR06_D4  	(IO_DDR06.bit.D4)
#define	DDR06_D5  	(IO_DDR06.bit.D5)
#define	DDR06_D6  	(IO_DDR06.bit.D6)
#define	DDR06_D7  	(IO_DDR06.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR08,   locate=0x438
#pragma segment FAR_DATA=IO_DDR08, locate=0x438
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR08STR;

__IO_EXTENDED	  DDR08STR	IO_DDR08;
#define	_ddr08		(IO_DDR08)
#define	DDR08		(IO_DDR08.byte)
#define	DDR08_D0  	(IO_DDR08.bit.D0)
#define	DDR08_D1  	(IO_DDR08.bit.D1)
#define	DDR08_D2  	(IO_DDR08.bit.D2)
#define	DDR08_D3  	(IO_DDR08.bit.D3)
#define	DDR08_D4  	(IO_DDR08.bit.D4)
#define	DDR08_D5  	(IO_DDR08.bit.D5)
#define	DDR08_D6  	(IO_DDR08.bit.D6)
#define	DDR08_D7  	(IO_DDR08.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR11,   locate=0x43B
#pragma segment FAR_DATA=IO_DDR11, locate=0x43B
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR11STR;

__IO_EXTENDED	  DDR11STR	IO_DDR11;
#define	_ddr11		(IO_DDR11)
#define	DDR11		(IO_DDR11.byte)
#define	DDR11_D0  	(IO_DDR11.bit.D0)
#define	DDR11_D1  	(IO_DDR11.bit.D1)
#define	DDR11_D2  	(IO_DDR11.bit.D2)
#define	DDR11_D3  	(IO_DDR11.bit.D3)
#define	DDR11_D4  	(IO_DDR11.bit.D4)
#define	DDR11_D5  	(IO_DDR11.bit.D5)
#define	DDR11_D6  	(IO_DDR11.bit.D6)
#define	DDR11_D7  	(IO_DDR11.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR12,   locate=0x43C
#pragma segment FAR_DATA=IO_DDR12, locate=0x43C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR12STR;

__IO_EXTENDED	  DDR12STR	IO_DDR12;
#define	_ddr12		(IO_DDR12)
#define	DDR12		(IO_DDR12.byte)
#define	DDR12_D0  	(IO_DDR12.bit.D0)
#define	DDR12_D1  	(IO_DDR12.bit.D1)
#define	DDR12_D2  	(IO_DDR12.bit.D2)
#define	DDR12_D3  	(IO_DDR12.bit.D3)
#define	DDR12_D4  	(IO_DDR12.bit.D4)
#define	DDR12_D5  	(IO_DDR12.bit.D5)
#define	DDR12_D6  	(IO_DDR12.bit.D6)
#define	DDR12_D7  	(IO_DDR12.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR13,   locate=0x43D
#pragma segment FAR_DATA=IO_DDR13, locate=0x43D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR13STR;

__IO_EXTENDED	  DDR13STR	IO_DDR13;
#define	_ddr13		(IO_DDR13)
#define	DDR13		(IO_DDR13.byte)
#define	DDR13_D0  	(IO_DDR13.bit.D0)
#define	DDR13_D1  	(IO_DDR13.bit.D1)
#define	DDR13_D2  	(IO_DDR13.bit.D2)
#define	DDR13_D3  	(IO_DDR13.bit.D3)
#define	DDR13_D4  	(IO_DDR13.bit.D4)
#define	DDR13_D5  	(IO_DDR13.bit.D5)
#define	DDR13_D6  	(IO_DDR13.bit.D6)
#define	DDR13_D7  	(IO_DDR13.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_DDR17,   locate=0x441
#pragma segment FAR_DATA=IO_DDR17, locate=0x441
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	D7:1;
			__BYTE	D6:1;
			__BYTE	D5:1;
			__BYTE	D4:1;
			__BYTE	D3:1;
			__BYTE	D2:1;
			__BYTE	D1:1;
			__BYTE	D0:1;
#else
			__BYTE	D0:1;
			__BYTE	D1:1;
			__BYTE	D2:1;
			__BYTE	D3:1;
			__BYTE	D4:1;
			__BYTE	D5:1;
			__BYTE	D6:1;
			__BYTE	D7:1;
#endif
	} bitc;
} DDR17STR;

__IO_EXTENDED	  DDR17STR	IO_DDR17;
#define	_ddr17		(IO_DDR17)
#define	DDR17		(IO_DDR17.byte)
#define	DDR17_D0  	(IO_DDR17.bit.D0)
#define	DDR17_D1  	(IO_DDR17.bit.D1)
#define	DDR17_D2  	(IO_DDR17.bit.D2)
#define	DDR17_D3  	(IO_DDR17.bit.D3)
#define	DDR17_D4  	(IO_DDR17.bit.D4)
#define	DDR17_D5  	(IO_DDR17.bit.D5)
#define	DDR17_D6  	(IO_DDR17.bit.D6)
#define	DDR17_D7  	(IO_DDR17.bit.D7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER00,   locate=0x444
#pragma segment FAR_DATA=IO_PIER00, locate=0x444
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER00STR;

__IO_EXTENDED	  PIER00STR	IO_PIER00;
#define	_pier00		(IO_PIER00)
#define	PIER00		(IO_PIER00.byte)
#define	PIER00_IE0  	(IO_PIER00.bit.IE0)
#define	PIER00_IE1  	(IO_PIER00.bit.IE1)
#define	PIER00_IE2  	(IO_PIER00.bit.IE2)
#define	PIER00_IE3  	(IO_PIER00.bit.IE3)
#define	PIER00_IE4  	(IO_PIER00.bit.IE4)
#define	PIER00_IE5  	(IO_PIER00.bit.IE5)
#define	PIER00_IE6  	(IO_PIER00.bit.IE6)
#define	PIER00_IE7  	(IO_PIER00.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER01,   locate=0x445
#pragma segment FAR_DATA=IO_PIER01, locate=0x445
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER01STR;

__IO_EXTENDED	  PIER01STR	IO_PIER01;
#define	_pier01		(IO_PIER01)
#define	PIER01		(IO_PIER01.byte)
#define	PIER01_IE0  	(IO_PIER01.bit.IE0)
#define	PIER01_IE1  	(IO_PIER01.bit.IE1)
#define	PIER01_IE2  	(IO_PIER01.bit.IE2)
#define	PIER01_IE3  	(IO_PIER01.bit.IE3)
#define	PIER01_IE4  	(IO_PIER01.bit.IE4)
#define	PIER01_IE5  	(IO_PIER01.bit.IE5)
#define	PIER01_IE6  	(IO_PIER01.bit.IE6)
#define	PIER01_IE7  	(IO_PIER01.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER02,   locate=0x446
#pragma segment FAR_DATA=IO_PIER02, locate=0x446
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER02STR;

__IO_EXTENDED	  PIER02STR	IO_PIER02;
#define	_pier02		(IO_PIER02)
#define	PIER02		(IO_PIER02.byte)
#define	PIER02_IE0  	(IO_PIER02.bit.IE0)
#define	PIER02_IE1  	(IO_PIER02.bit.IE1)
#define	PIER02_IE2  	(IO_PIER02.bit.IE2)
#define	PIER02_IE3  	(IO_PIER02.bit.IE3)
#define	PIER02_IE4  	(IO_PIER02.bit.IE4)
#define	PIER02_IE5  	(IO_PIER02.bit.IE5)
#define	PIER02_IE6  	(IO_PIER02.bit.IE6)
#define	PIER02_IE7  	(IO_PIER02.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER03,   locate=0x447
#pragma segment FAR_DATA=IO_PIER03, locate=0x447
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER03STR;

__IO_EXTENDED	  PIER03STR	IO_PIER03;
#define	_pier03		(IO_PIER03)
#define	PIER03		(IO_PIER03.byte)
#define	PIER03_IE0  	(IO_PIER03.bit.IE0)
#define	PIER03_IE1  	(IO_PIER03.bit.IE1)
#define	PIER03_IE2  	(IO_PIER03.bit.IE2)
#define	PIER03_IE3  	(IO_PIER03.bit.IE3)
#define	PIER03_IE4  	(IO_PIER03.bit.IE4)
#define	PIER03_IE5  	(IO_PIER03.bit.IE5)
#define	PIER03_IE6  	(IO_PIER03.bit.IE6)
#define	PIER03_IE7  	(IO_PIER03.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER04,   locate=0x448
#pragma segment FAR_DATA=IO_PIER04, locate=0x448
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER04STR;

__IO_EXTENDED	  PIER04STR	IO_PIER04;
#define	_pier04		(IO_PIER04)
#define	PIER04		(IO_PIER04.byte)
#define	PIER04_IE0  	(IO_PIER04.bit.IE0)
#define	PIER04_IE1  	(IO_PIER04.bit.IE1)
#define	PIER04_IE2  	(IO_PIER04.bit.IE2)
#define	PIER04_IE3  	(IO_PIER04.bit.IE3)
#define	PIER04_IE4  	(IO_PIER04.bit.IE4)
#define	PIER04_IE5  	(IO_PIER04.bit.IE5)
#define	PIER04_IE6  	(IO_PIER04.bit.IE6)
#define	PIER04_IE7  	(IO_PIER04.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER05,   locate=0x449
#pragma segment FAR_DATA=IO_PIER05, locate=0x449
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER05STR;

__IO_EXTENDED	  PIER05STR	IO_PIER05;
#define	_pier05		(IO_PIER05)
#define	PIER05		(IO_PIER05.byte)
#define	PIER05_IE0  	(IO_PIER05.bit.IE0)
#define	PIER05_IE1  	(IO_PIER05.bit.IE1)
#define	PIER05_IE2  	(IO_PIER05.bit.IE2)
#define	PIER05_IE3  	(IO_PIER05.bit.IE3)
#define	PIER05_IE4  	(IO_PIER05.bit.IE4)
#define	PIER05_IE5  	(IO_PIER05.bit.IE5)
#define	PIER05_IE6  	(IO_PIER05.bit.IE6)
#define	PIER05_IE7  	(IO_PIER05.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER06,   locate=0x44A
#pragma segment FAR_DATA=IO_PIER06, locate=0x44A
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER06STR;

__IO_EXTENDED	  PIER06STR	IO_PIER06;
#define	_pier06		(IO_PIER06)
#define	PIER06		(IO_PIER06.byte)
#define	PIER06_IE0  	(IO_PIER06.bit.IE0)
#define	PIER06_IE1  	(IO_PIER06.bit.IE1)
#define	PIER06_IE2  	(IO_PIER06.bit.IE2)
#define	PIER06_IE3  	(IO_PIER06.bit.IE3)
#define	PIER06_IE4  	(IO_PIER06.bit.IE4)
#define	PIER06_IE5  	(IO_PIER06.bit.IE5)
#define	PIER06_IE6  	(IO_PIER06.bit.IE6)
#define	PIER06_IE7  	(IO_PIER06.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER08,   locate=0x44C
#pragma segment FAR_DATA=IO_PIER08, locate=0x44C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER08STR;

__IO_EXTENDED	  PIER08STR	IO_PIER08;
#define	_pier08		(IO_PIER08)
#define	PIER08		(IO_PIER08.byte)
#define	PIER08_IE0  	(IO_PIER08.bit.IE0)
#define	PIER08_IE1  	(IO_PIER08.bit.IE1)
#define	PIER08_IE2  	(IO_PIER08.bit.IE2)
#define	PIER08_IE3  	(IO_PIER08.bit.IE3)
#define	PIER08_IE4  	(IO_PIER08.bit.IE4)
#define	PIER08_IE5  	(IO_PIER08.bit.IE5)
#define	PIER08_IE6  	(IO_PIER08.bit.IE6)
#define	PIER08_IE7  	(IO_PIER08.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER11,   locate=0x44F
#pragma segment FAR_DATA=IO_PIER11, locate=0x44F
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER11STR;

__IO_EXTENDED	  PIER11STR	IO_PIER11;
#define	_pier11		(IO_PIER11)
#define	PIER11		(IO_PIER11.byte)
#define	PIER11_IE0  	(IO_PIER11.bit.IE0)
#define	PIER11_IE1  	(IO_PIER11.bit.IE1)
#define	PIER11_IE2  	(IO_PIER11.bit.IE2)
#define	PIER11_IE3  	(IO_PIER11.bit.IE3)
#define	PIER11_IE4  	(IO_PIER11.bit.IE4)
#define	PIER11_IE5  	(IO_PIER11.bit.IE5)
#define	PIER11_IE6  	(IO_PIER11.bit.IE6)
#define	PIER11_IE7  	(IO_PIER11.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER12,   locate=0x450
#pragma segment FAR_DATA=IO_PIER12, locate=0x450
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER12STR;

__IO_EXTENDED	  PIER12STR	IO_PIER12;
#define	_pier12		(IO_PIER12)
#define	PIER12		(IO_PIER12.byte)
#define	PIER12_IE0  	(IO_PIER12.bit.IE0)
#define	PIER12_IE1  	(IO_PIER12.bit.IE1)
#define	PIER12_IE2  	(IO_PIER12.bit.IE2)
#define	PIER12_IE3  	(IO_PIER12.bit.IE3)
#define	PIER12_IE4  	(IO_PIER12.bit.IE4)
#define	PIER12_IE5  	(IO_PIER12.bit.IE5)
#define	PIER12_IE6  	(IO_PIER12.bit.IE6)
#define	PIER12_IE7  	(IO_PIER12.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER13,   locate=0x451
#pragma segment FAR_DATA=IO_PIER13, locate=0x451
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER13STR;

__IO_EXTENDED	  PIER13STR	IO_PIER13;
#define	_pier13		(IO_PIER13)
#define	PIER13		(IO_PIER13.byte)
#define	PIER13_IE0  	(IO_PIER13.bit.IE0)
#define	PIER13_IE1  	(IO_PIER13.bit.IE1)
#define	PIER13_IE2  	(IO_PIER13.bit.IE2)
#define	PIER13_IE3  	(IO_PIER13.bit.IE3)
#define	PIER13_IE4  	(IO_PIER13.bit.IE4)
#define	PIER13_IE5  	(IO_PIER13.bit.IE5)
#define	PIER13_IE6  	(IO_PIER13.bit.IE6)
#define	PIER13_IE7  	(IO_PIER13.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PIER17,   locate=0x455
#pragma segment FAR_DATA=IO_PIER17, locate=0x455
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	IE7:1;
			__BYTE	IE6:1;
			__BYTE	IE5:1;
			__BYTE	IE4:1;
			__BYTE	IE3:1;
			__BYTE	IE2:1;
			__BYTE	IE1:1;
			__BYTE	IE0:1;
#else
			__BYTE	IE0:1;
			__BYTE	IE1:1;
			__BYTE	IE2:1;
			__BYTE	IE3:1;
			__BYTE	IE4:1;
			__BYTE	IE5:1;
			__BYTE	IE6:1;
			__BYTE	IE7:1;
#endif
	} bitc;
} PIER17STR;

__IO_EXTENDED	  PIER17STR	IO_PIER17;
#define	_pier17		(IO_PIER17)
#define	PIER17		(IO_PIER17.byte)
#define	PIER17_IE0  	(IO_PIER17.bit.IE0)
#define	PIER17_IE1  	(IO_PIER17.bit.IE1)
#define	PIER17_IE2  	(IO_PIER17.bit.IE2)
#define	PIER17_IE3  	(IO_PIER17.bit.IE3)
#define	PIER17_IE4  	(IO_PIER17.bit.IE4)
#define	PIER17_IE5  	(IO_PIER17.bit.IE5)
#define	PIER17_IE6  	(IO_PIER17.bit.IE6)
#define	PIER17_IE7  	(IO_PIER17.bit.IE7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PHDR08,   locate=0x49C
#pragma segment FAR_DATA=IO_PHDR08, locate=0x49C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HD7:1;
			__BYTE	HD6:1;
			__BYTE	HD5:1;
			__BYTE	HD4:1;
			__BYTE	HD3:1;
			__BYTE	HD2:1;
			__BYTE	HD1:1;
			__BYTE	HD0:1;
#else
			__BYTE	HD0:1;
			__BYTE	HD1:1;
			__BYTE	HD2:1;
			__BYTE	HD3:1;
			__BYTE	HD4:1;
			__BYTE	HD5:1;
			__BYTE	HD6:1;
			__BYTE	HD7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	HD7:1;
			__BYTE	HD6:1;
			__BYTE	HD5:1;
			__BYTE	HD4:1;
			__BYTE	HD3:1;
			__BYTE	HD2:1;
			__BYTE	HD1:1;
			__BYTE	HD0:1;
#else
			__BYTE	HD0:1;
			__BYTE	HD1:1;
			__BYTE	HD2:1;
			__BYTE	HD3:1;
			__BYTE	HD4:1;
			__BYTE	HD5:1;
			__BYTE	HD6:1;
			__BYTE	HD7:1;
#endif
	} bitc;
} PHDR08STR;

__IO_EXTENDED	  PHDR08STR	IO_PHDR08;
#define	_phdr08		(IO_PHDR08)
#define	PHDR08		(IO_PHDR08.byte)
#define	PHDR08_HD0  	(IO_PHDR08.bit.HD0)
#define	PHDR08_HD1  	(IO_PHDR08.bit.HD1)
#define	PHDR08_HD2  	(IO_PHDR08.bit.HD2)
#define	PHDR08_HD3  	(IO_PHDR08.bit.HD3)
#define	PHDR08_HD4  	(IO_PHDR08.bit.HD4)
#define	PHDR08_HD5  	(IO_PHDR08.bit.HD5)
#define	PHDR08_HD6  	(IO_PHDR08.bit.HD6)
#define	PHDR08_HD7  	(IO_PHDR08.bit.HD7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR00,   locate=0x4A8
#pragma segment FAR_DATA=IO_PUCR00, locate=0x4A8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR00STR;

__IO_EXTENDED	  PUCR00STR	IO_PUCR00;
#define	_pucr00		(IO_PUCR00)
#define	PUCR00		(IO_PUCR00.byte)
#define	PUCR00_PU0  	(IO_PUCR00.bit.PU0)
#define	PUCR00_PU1  	(IO_PUCR00.bit.PU1)
#define	PUCR00_PU2  	(IO_PUCR00.bit.PU2)
#define	PUCR00_PU3  	(IO_PUCR00.bit.PU3)
#define	PUCR00_PU4  	(IO_PUCR00.bit.PU4)
#define	PUCR00_PU5  	(IO_PUCR00.bit.PU5)
#define	PUCR00_PU6  	(IO_PUCR00.bit.PU6)
#define	PUCR00_PU7  	(IO_PUCR00.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR01,   locate=0x4A9
#pragma segment FAR_DATA=IO_PUCR01, locate=0x4A9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR01STR;

__IO_EXTENDED	  PUCR01STR	IO_PUCR01;
#define	_pucr01		(IO_PUCR01)
#define	PUCR01		(IO_PUCR01.byte)
#define	PUCR01_PU0  	(IO_PUCR01.bit.PU0)
#define	PUCR01_PU1  	(IO_PUCR01.bit.PU1)
#define	PUCR01_PU2  	(IO_PUCR01.bit.PU2)
#define	PUCR01_PU3  	(IO_PUCR01.bit.PU3)
#define	PUCR01_PU4  	(IO_PUCR01.bit.PU4)
#define	PUCR01_PU5  	(IO_PUCR01.bit.PU5)
#define	PUCR01_PU6  	(IO_PUCR01.bit.PU6)
#define	PUCR01_PU7  	(IO_PUCR01.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR02,   locate=0x4AA
#pragma segment FAR_DATA=IO_PUCR02, locate=0x4AA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR02STR;

__IO_EXTENDED	  PUCR02STR	IO_PUCR02;
#define	_pucr02		(IO_PUCR02)
#define	PUCR02		(IO_PUCR02.byte)
#define	PUCR02_PU0  	(IO_PUCR02.bit.PU0)
#define	PUCR02_PU1  	(IO_PUCR02.bit.PU1)
#define	PUCR02_PU2  	(IO_PUCR02.bit.PU2)
#define	PUCR02_PU3  	(IO_PUCR02.bit.PU3)
#define	PUCR02_PU4  	(IO_PUCR02.bit.PU4)
#define	PUCR02_PU5  	(IO_PUCR02.bit.PU5)
#define	PUCR02_PU6  	(IO_PUCR02.bit.PU6)
#define	PUCR02_PU7  	(IO_PUCR02.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR03,   locate=0x4AB
#pragma segment FAR_DATA=IO_PUCR03, locate=0x4AB
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR03STR;

__IO_EXTENDED	  PUCR03STR	IO_PUCR03;
#define	_pucr03		(IO_PUCR03)
#define	PUCR03		(IO_PUCR03.byte)
#define	PUCR03_PU0  	(IO_PUCR03.bit.PU0)
#define	PUCR03_PU1  	(IO_PUCR03.bit.PU1)
#define	PUCR03_PU2  	(IO_PUCR03.bit.PU2)
#define	PUCR03_PU3  	(IO_PUCR03.bit.PU3)
#define	PUCR03_PU4  	(IO_PUCR03.bit.PU4)
#define	PUCR03_PU5  	(IO_PUCR03.bit.PU5)
#define	PUCR03_PU6  	(IO_PUCR03.bit.PU6)
#define	PUCR03_PU7  	(IO_PUCR03.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR04,   locate=0x4AC
#pragma segment FAR_DATA=IO_PUCR04, locate=0x4AC
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR04STR;

__IO_EXTENDED	  PUCR04STR	IO_PUCR04;
#define	_pucr04		(IO_PUCR04)
#define	PUCR04		(IO_PUCR04.byte)
#define	PUCR04_PU0  	(IO_PUCR04.bit.PU0)
#define	PUCR04_PU1  	(IO_PUCR04.bit.PU1)
#define	PUCR04_PU2  	(IO_PUCR04.bit.PU2)
#define	PUCR04_PU3  	(IO_PUCR04.bit.PU3)
#define	PUCR04_PU4  	(IO_PUCR04.bit.PU4)
#define	PUCR04_PU5  	(IO_PUCR04.bit.PU5)
#define	PUCR04_PU6  	(IO_PUCR04.bit.PU6)
#define	PUCR04_PU7  	(IO_PUCR04.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR05,   locate=0x4AD
#pragma segment FAR_DATA=IO_PUCR05, locate=0x4AD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR05STR;

__IO_EXTENDED	  PUCR05STR	IO_PUCR05;
#define	_pucr05		(IO_PUCR05)
#define	PUCR05		(IO_PUCR05.byte)
#define	PUCR05_PU0  	(IO_PUCR05.bit.PU0)
#define	PUCR05_PU1  	(IO_PUCR05.bit.PU1)
#define	PUCR05_PU2  	(IO_PUCR05.bit.PU2)
#define	PUCR05_PU3  	(IO_PUCR05.bit.PU3)
#define	PUCR05_PU4  	(IO_PUCR05.bit.PU4)
#define	PUCR05_PU5  	(IO_PUCR05.bit.PU5)
#define	PUCR05_PU6  	(IO_PUCR05.bit.PU6)
#define	PUCR05_PU7  	(IO_PUCR05.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR06,   locate=0x4AE
#pragma segment FAR_DATA=IO_PUCR06, locate=0x4AE
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR06STR;

__IO_EXTENDED	  PUCR06STR	IO_PUCR06;
#define	_pucr06		(IO_PUCR06)
#define	PUCR06		(IO_PUCR06.byte)
#define	PUCR06_PU0  	(IO_PUCR06.bit.PU0)
#define	PUCR06_PU1  	(IO_PUCR06.bit.PU1)
#define	PUCR06_PU2  	(IO_PUCR06.bit.PU2)
#define	PUCR06_PU3  	(IO_PUCR06.bit.PU3)
#define	PUCR06_PU4  	(IO_PUCR06.bit.PU4)
#define	PUCR06_PU5  	(IO_PUCR06.bit.PU5)
#define	PUCR06_PU6  	(IO_PUCR06.bit.PU6)
#define	PUCR06_PU7  	(IO_PUCR06.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR08,   locate=0x4B0
#pragma segment FAR_DATA=IO_PUCR08, locate=0x4B0
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR08STR;

__IO_EXTENDED	  PUCR08STR	IO_PUCR08;
#define	_pucr08		(IO_PUCR08)
#define	PUCR08		(IO_PUCR08.byte)
#define	PUCR08_PU0  	(IO_PUCR08.bit.PU0)
#define	PUCR08_PU1  	(IO_PUCR08.bit.PU1)
#define	PUCR08_PU2  	(IO_PUCR08.bit.PU2)
#define	PUCR08_PU3  	(IO_PUCR08.bit.PU3)
#define	PUCR08_PU4  	(IO_PUCR08.bit.PU4)
#define	PUCR08_PU5  	(IO_PUCR08.bit.PU5)
#define	PUCR08_PU6  	(IO_PUCR08.bit.PU6)
#define	PUCR08_PU7  	(IO_PUCR08.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR11,   locate=0x4B3
#pragma segment FAR_DATA=IO_PUCR11, locate=0x4B3
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR11STR;

__IO_EXTENDED	  PUCR11STR	IO_PUCR11;
#define	_pucr11		(IO_PUCR11)
#define	PUCR11		(IO_PUCR11.byte)
#define	PUCR11_PU0  	(IO_PUCR11.bit.PU0)
#define	PUCR11_PU1  	(IO_PUCR11.bit.PU1)
#define	PUCR11_PU2  	(IO_PUCR11.bit.PU2)
#define	PUCR11_PU3  	(IO_PUCR11.bit.PU3)
#define	PUCR11_PU4  	(IO_PUCR11.bit.PU4)
#define	PUCR11_PU5  	(IO_PUCR11.bit.PU5)
#define	PUCR11_PU6  	(IO_PUCR11.bit.PU6)
#define	PUCR11_PU7  	(IO_PUCR11.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR12,   locate=0x4B4
#pragma segment FAR_DATA=IO_PUCR12, locate=0x4B4
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR12STR;

__IO_EXTENDED	  PUCR12STR	IO_PUCR12;
#define	_pucr12		(IO_PUCR12)
#define	PUCR12		(IO_PUCR12.byte)
#define	PUCR12_PU0  	(IO_PUCR12.bit.PU0)
#define	PUCR12_PU1  	(IO_PUCR12.bit.PU1)
#define	PUCR12_PU2  	(IO_PUCR12.bit.PU2)
#define	PUCR12_PU3  	(IO_PUCR12.bit.PU3)
#define	PUCR12_PU4  	(IO_PUCR12.bit.PU4)
#define	PUCR12_PU5  	(IO_PUCR12.bit.PU5)
#define	PUCR12_PU6  	(IO_PUCR12.bit.PU6)
#define	PUCR12_PU7  	(IO_PUCR12.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR13,   locate=0x4B5
#pragma segment FAR_DATA=IO_PUCR13, locate=0x4B5
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR13STR;

__IO_EXTENDED	  PUCR13STR	IO_PUCR13;
#define	_pucr13		(IO_PUCR13)
#define	PUCR13		(IO_PUCR13.byte)
#define	PUCR13_PU0  	(IO_PUCR13.bit.PU0)
#define	PUCR13_PU1  	(IO_PUCR13.bit.PU1)
#define	PUCR13_PU2  	(IO_PUCR13.bit.PU2)
#define	PUCR13_PU3  	(IO_PUCR13.bit.PU3)
#define	PUCR13_PU4  	(IO_PUCR13.bit.PU4)
#define	PUCR13_PU5  	(IO_PUCR13.bit.PU5)
#define	PUCR13_PU6  	(IO_PUCR13.bit.PU6)
#define	PUCR13_PU7  	(IO_PUCR13.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PUCR17,   locate=0x4B9
#pragma segment FAR_DATA=IO_PUCR17, locate=0x4B9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PU7:1;
			__BYTE	PU6:1;
			__BYTE	PU5:1;
			__BYTE	PU4:1;
			__BYTE	PU3:1;
			__BYTE	PU2:1;
			__BYTE	PU1:1;
			__BYTE	PU0:1;
#else
			__BYTE	PU0:1;
			__BYTE	PU1:1;
			__BYTE	PU2:1;
			__BYTE	PU3:1;
			__BYTE	PU4:1;
			__BYTE	PU5:1;
			__BYTE	PU6:1;
			__BYTE	PU7:1;
#endif
	} bitc;
} PUCR17STR;

__IO_EXTENDED	  PUCR17STR	IO_PUCR17;
#define	_pucr17		(IO_PUCR17)
#define	PUCR17		(IO_PUCR17.byte)
#define	PUCR17_PU0  	(IO_PUCR17.bit.PU0)
#define	PUCR17_PU1  	(IO_PUCR17.bit.PU1)
#define	PUCR17_PU2  	(IO_PUCR17.bit.PU2)
#define	PUCR17_PU3  	(IO_PUCR17.bit.PU3)
#define	PUCR17_PU4  	(IO_PUCR17.bit.PU4)
#define	PUCR17_PU5  	(IO_PUCR17.bit.PU5)
#define	PUCR17_PU6  	(IO_PUCR17.bit.PU6)
#define	PUCR17_PU7  	(IO_PUCR17.bit.PU7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR00,   locate=0x4BC
#pragma segment FAR_DATA=IO_EPSR00, locate=0x4BC
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR00STR;

__IO_EXTENDED	 const  EPSR00STR	IO_EPSR00;
#define	_epsr00		(IO_EPSR00)
#define	EPSR00		(IO_EPSR00.byte)
#define	EPSR00_PS0  	(IO_EPSR00.bit.PS0)
#define	EPSR00_PS1  	(IO_EPSR00.bit.PS1)
#define	EPSR00_PS2  	(IO_EPSR00.bit.PS2)
#define	EPSR00_PS3  	(IO_EPSR00.bit.PS3)
#define	EPSR00_PS4  	(IO_EPSR00.bit.PS4)
#define	EPSR00_PS5  	(IO_EPSR00.bit.PS5)
#define	EPSR00_PS6  	(IO_EPSR00.bit.PS6)
#define	EPSR00_PS7  	(IO_EPSR00.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR01,   locate=0x4BD
#pragma segment FAR_DATA=IO_EPSR01, locate=0x4BD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR01STR;

__IO_EXTENDED	 const  EPSR01STR	IO_EPSR01;
#define	_epsr01		(IO_EPSR01)
#define	EPSR01		(IO_EPSR01.byte)
#define	EPSR01_PS0  	(IO_EPSR01.bit.PS0)
#define	EPSR01_PS1  	(IO_EPSR01.bit.PS1)
#define	EPSR01_PS2  	(IO_EPSR01.bit.PS2)
#define	EPSR01_PS3  	(IO_EPSR01.bit.PS3)
#define	EPSR01_PS4  	(IO_EPSR01.bit.PS4)
#define	EPSR01_PS5  	(IO_EPSR01.bit.PS5)
#define	EPSR01_PS6  	(IO_EPSR01.bit.PS6)
#define	EPSR01_PS7  	(IO_EPSR01.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR02,   locate=0x4BE
#pragma segment FAR_DATA=IO_EPSR02, locate=0x4BE
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR02STR;

__IO_EXTENDED	 const  EPSR02STR	IO_EPSR02;
#define	_epsr02		(IO_EPSR02)
#define	EPSR02		(IO_EPSR02.byte)
#define	EPSR02_PS0  	(IO_EPSR02.bit.PS0)
#define	EPSR02_PS1  	(IO_EPSR02.bit.PS1)
#define	EPSR02_PS2  	(IO_EPSR02.bit.PS2)
#define	EPSR02_PS3  	(IO_EPSR02.bit.PS3)
#define	EPSR02_PS4  	(IO_EPSR02.bit.PS4)
#define	EPSR02_PS5  	(IO_EPSR02.bit.PS5)
#define	EPSR02_PS6  	(IO_EPSR02.bit.PS6)
#define	EPSR02_PS7  	(IO_EPSR02.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR03,   locate=0x4BF
#pragma segment FAR_DATA=IO_EPSR03, locate=0x4BF
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR03STR;

__IO_EXTENDED	 const  EPSR03STR	IO_EPSR03;
#define	_epsr03		(IO_EPSR03)
#define	EPSR03		(IO_EPSR03.byte)
#define	EPSR03_PS0  	(IO_EPSR03.bit.PS0)
#define	EPSR03_PS1  	(IO_EPSR03.bit.PS1)
#define	EPSR03_PS2  	(IO_EPSR03.bit.PS2)
#define	EPSR03_PS3  	(IO_EPSR03.bit.PS3)
#define	EPSR03_PS4  	(IO_EPSR03.bit.PS4)
#define	EPSR03_PS5  	(IO_EPSR03.bit.PS5)
#define	EPSR03_PS6  	(IO_EPSR03.bit.PS6)
#define	EPSR03_PS7  	(IO_EPSR03.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR04,   locate=0x4C0
#pragma segment FAR_DATA=IO_EPSR04, locate=0x4C0
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR04STR;

__IO_EXTENDED	 const  EPSR04STR	IO_EPSR04;
#define	_epsr04		(IO_EPSR04)
#define	EPSR04		(IO_EPSR04.byte)
#define	EPSR04_PS0  	(IO_EPSR04.bit.PS0)
#define	EPSR04_PS1  	(IO_EPSR04.bit.PS1)
#define	EPSR04_PS2  	(IO_EPSR04.bit.PS2)
#define	EPSR04_PS3  	(IO_EPSR04.bit.PS3)
#define	EPSR04_PS4  	(IO_EPSR04.bit.PS4)
#define	EPSR04_PS5  	(IO_EPSR04.bit.PS5)
#define	EPSR04_PS6  	(IO_EPSR04.bit.PS6)
#define	EPSR04_PS7  	(IO_EPSR04.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR05,   locate=0x4C1
#pragma segment FAR_DATA=IO_EPSR05, locate=0x4C1
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR05STR;

__IO_EXTENDED	 const  EPSR05STR	IO_EPSR05;
#define	_epsr05		(IO_EPSR05)
#define	EPSR05		(IO_EPSR05.byte)
#define	EPSR05_PS0  	(IO_EPSR05.bit.PS0)
#define	EPSR05_PS1  	(IO_EPSR05.bit.PS1)
#define	EPSR05_PS2  	(IO_EPSR05.bit.PS2)
#define	EPSR05_PS3  	(IO_EPSR05.bit.PS3)
#define	EPSR05_PS4  	(IO_EPSR05.bit.PS4)
#define	EPSR05_PS5  	(IO_EPSR05.bit.PS5)
#define	EPSR05_PS6  	(IO_EPSR05.bit.PS6)
#define	EPSR05_PS7  	(IO_EPSR05.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR06,   locate=0x4C2
#pragma segment FAR_DATA=IO_EPSR06, locate=0x4C2
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR06STR;

__IO_EXTENDED	 const  EPSR06STR	IO_EPSR06;
#define	_epsr06		(IO_EPSR06)
#define	EPSR06		(IO_EPSR06.byte)
#define	EPSR06_PS0  	(IO_EPSR06.bit.PS0)
#define	EPSR06_PS1  	(IO_EPSR06.bit.PS1)
#define	EPSR06_PS2  	(IO_EPSR06.bit.PS2)
#define	EPSR06_PS3  	(IO_EPSR06.bit.PS3)
#define	EPSR06_PS4  	(IO_EPSR06.bit.PS4)
#define	EPSR06_PS5  	(IO_EPSR06.bit.PS5)
#define	EPSR06_PS6  	(IO_EPSR06.bit.PS6)
#define	EPSR06_PS7  	(IO_EPSR06.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR08,   locate=0x4C4
#pragma segment FAR_DATA=IO_EPSR08, locate=0x4C4
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR08STR;

__IO_EXTENDED	 const  EPSR08STR	IO_EPSR08;
#define	_epsr08		(IO_EPSR08)
#define	EPSR08		(IO_EPSR08.byte)
#define	EPSR08_PS0  	(IO_EPSR08.bit.PS0)
#define	EPSR08_PS1  	(IO_EPSR08.bit.PS1)
#define	EPSR08_PS2  	(IO_EPSR08.bit.PS2)
#define	EPSR08_PS3  	(IO_EPSR08.bit.PS3)
#define	EPSR08_PS4  	(IO_EPSR08.bit.PS4)
#define	EPSR08_PS5  	(IO_EPSR08.bit.PS5)
#define	EPSR08_PS6  	(IO_EPSR08.bit.PS6)
#define	EPSR08_PS7  	(IO_EPSR08.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR11,   locate=0x4C7
#pragma segment FAR_DATA=IO_EPSR11, locate=0x4C7
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR11STR;

__IO_EXTENDED	 const  EPSR11STR	IO_EPSR11;
#define	_epsr11		(IO_EPSR11)
#define	EPSR11		(IO_EPSR11.byte)
#define	EPSR11_PS0  	(IO_EPSR11.bit.PS0)
#define	EPSR11_PS1  	(IO_EPSR11.bit.PS1)
#define	EPSR11_PS2  	(IO_EPSR11.bit.PS2)
#define	EPSR11_PS3  	(IO_EPSR11.bit.PS3)
#define	EPSR11_PS4  	(IO_EPSR11.bit.PS4)
#define	EPSR11_PS5  	(IO_EPSR11.bit.PS5)
#define	EPSR11_PS6  	(IO_EPSR11.bit.PS6)
#define	EPSR11_PS7  	(IO_EPSR11.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR12,   locate=0x4C8
#pragma segment FAR_DATA=IO_EPSR12, locate=0x4C8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR12STR;

__IO_EXTENDED	 const  EPSR12STR	IO_EPSR12;
#define	_epsr12		(IO_EPSR12)
#define	EPSR12		(IO_EPSR12.byte)
#define	EPSR12_PS0  	(IO_EPSR12.bit.PS0)
#define	EPSR12_PS1  	(IO_EPSR12.bit.PS1)
#define	EPSR12_PS2  	(IO_EPSR12.bit.PS2)
#define	EPSR12_PS3  	(IO_EPSR12.bit.PS3)
#define	EPSR12_PS4  	(IO_EPSR12.bit.PS4)
#define	EPSR12_PS5  	(IO_EPSR12.bit.PS5)
#define	EPSR12_PS6  	(IO_EPSR12.bit.PS6)
#define	EPSR12_PS7  	(IO_EPSR12.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR13,   locate=0x4C9
#pragma segment FAR_DATA=IO_EPSR13, locate=0x4C9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR13STR;

__IO_EXTENDED	 const  EPSR13STR	IO_EPSR13;
#define	_epsr13		(IO_EPSR13)
#define	EPSR13		(IO_EPSR13.byte)
#define	EPSR13_PS0  	(IO_EPSR13.bit.PS0)
#define	EPSR13_PS1  	(IO_EPSR13.bit.PS1)
#define	EPSR13_PS2  	(IO_EPSR13.bit.PS2)
#define	EPSR13_PS3  	(IO_EPSR13.bit.PS3)
#define	EPSR13_PS4  	(IO_EPSR13.bit.PS4)
#define	EPSR13_PS5  	(IO_EPSR13.bit.PS5)
#define	EPSR13_PS6  	(IO_EPSR13.bit.PS6)
#define	EPSR13_PS7  	(IO_EPSR13.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPSR17,   locate=0x4CD
#pragma segment FAR_DATA=IO_EPSR17, locate=0x4CD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PS7:1;
			__BYTE	PS6:1;
			__BYTE	PS5:1;
			__BYTE	PS4:1;
			__BYTE	PS3:1;
			__BYTE	PS2:1;
			__BYTE	PS1:1;
			__BYTE	PS0:1;
#else
			__BYTE	PS0:1;
			__BYTE	PS1:1;
			__BYTE	PS2:1;
			__BYTE	PS3:1;
			__BYTE	PS4:1;
			__BYTE	PS5:1;
			__BYTE	PS6:1;
			__BYTE	PS7:1;
#endif
	} bitc;
} EPSR17STR;

__IO_EXTENDED	 const  EPSR17STR	IO_EPSR17;
#define	_epsr17		(IO_EPSR17)
#define	EPSR17		(IO_EPSR17.byte)
#define	EPSR17_PS0  	(IO_EPSR17.bit.PS0)
#define	EPSR17_PS1  	(IO_EPSR17.bit.PS1)
#define	EPSR17_PS2  	(IO_EPSR17.bit.PS2)
#define	EPSR17_PS3  	(IO_EPSR17.bit.PS3)
#define	EPSR17_PS4  	(IO_EPSR17.bit.PS4)
#define	EPSR17_PS5  	(IO_EPSR17.bit.PS5)
#define	EPSR17_PS6  	(IO_EPSR17.bit.PS6)
#define	EPSR17_PS7  	(IO_EPSR17.bit.PS7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADER1,   locate=0x4D1
#pragma segment FAR_DATA=IO_ADER1, locate=0x4D1
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ADE15:1;
			__BYTE	ADE14:1;
			__BYTE	ADE13:1;
			__BYTE	ADE12:1;
			__BYTE	ADE11:1;
			__BYTE	ADE10:1;
			__BYTE	ADE9:1;
			__BYTE	ADE8:1;
#else
			__BYTE	ADE8:1;
			__BYTE	ADE9:1;
			__BYTE	ADE10:1;
			__BYTE	ADE11:1;
			__BYTE	ADE12:1;
			__BYTE	ADE13:1;
			__BYTE	ADE14:1;
			__BYTE	ADE15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ADE15:1;
			__BYTE	ADE14:1;
			__BYTE	ADE13:1;
			__BYTE	ADE12:1;
			__BYTE	ADE11:1;
			__BYTE	ADE10:1;
			__BYTE	ADE9:1;
			__BYTE	ADE8:1;
#else
			__BYTE	ADE8:1;
			__BYTE	ADE9:1;
			__BYTE	ADE10:1;
			__BYTE	ADE11:1;
			__BYTE	ADE12:1;
			__BYTE	ADE13:1;
			__BYTE	ADE14:1;
			__BYTE	ADE15:1;
#endif
	} bitc;
} ADER1STR;

__IO_EXTENDED	  ADER1STR	IO_ADER1;
#define	_ader1		(IO_ADER1)
#define	ADER1		(IO_ADER1.byte)
#define	ADER1_ADE8  	(IO_ADER1.bit.ADE8)
#define	ADER1_ADE9  	(IO_ADER1.bit.ADE9)
#define	ADER1_ADE10  	(IO_ADER1.bit.ADE10)
#define	ADER1_ADE11  	(IO_ADER1.bit.ADE11)
#define	ADER1_ADE12  	(IO_ADER1.bit.ADE12)
#define	ADER1_ADE13  	(IO_ADER1.bit.ADE13)
#define	ADER1_ADE14  	(IO_ADER1.bit.ADE14)
#define	ADER1_ADE15  	(IO_ADER1.bit.ADE15)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADER2,   locate=0x4D2
#pragma segment FAR_DATA=IO_ADER2, locate=0x4D2
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ADE23:1;
			__BYTE	ADE22:1;
			__BYTE	ADE21:1;
			__BYTE	ADE20:1;
			__BYTE	ADE19:1;
			__BYTE	ADE18:1;
			__BYTE	ADE17:1;
			__BYTE	ADE16:1;
#else
			__BYTE	ADE16:1;
			__BYTE	ADE17:1;
			__BYTE	ADE18:1;
			__BYTE	ADE19:1;
			__BYTE	ADE20:1;
			__BYTE	ADE21:1;
			__BYTE	ADE22:1;
			__BYTE	ADE23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	ADE23:1;
			__BYTE	ADE22:1;
			__BYTE	ADE21:1;
			__BYTE	ADE20:1;
			__BYTE	ADE19:1;
			__BYTE	ADE18:1;
			__BYTE	ADE17:1;
			__BYTE	ADE16:1;
#else
			__BYTE	ADE16:1;
			__BYTE	ADE17:1;
			__BYTE	ADE18:1;
			__BYTE	ADE19:1;
			__BYTE	ADE20:1;
			__BYTE	ADE21:1;
			__BYTE	ADE22:1;
			__BYTE	ADE23:1;
#endif
	} bitc;
} ADER2STR;

__IO_EXTENDED	  ADER2STR	IO_ADER2;
#define	_ader2		(IO_ADER2)
#define	ADER2		(IO_ADER2.byte)
#define	ADER2_ADE16  	(IO_ADER2.bit.ADE16)
#define	ADER2_ADE17  	(IO_ADER2.bit.ADE17)
#define	ADER2_ADE18  	(IO_ADER2.bit.ADE18)
#define	ADER2_ADE19  	(IO_ADER2.bit.ADE19)
#define	ADER2_ADE20  	(IO_ADER2.bit.ADE20)
#define	ADER2_ADE21  	(IO_ADER2.bit.ADE21)
#define	ADER2_ADE22  	(IO_ADER2.bit.ADE22)
#define	ADER2_ADE23  	(IO_ADER2.bit.ADE23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR0,   locate=0x4D6
#pragma segment FAR_DATA=IO_PRRR0, locate=0x4D6
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	INT2_R:1;
			__BYTE	INT1_R:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	INT1_R:1;
			__BYTE	INT2_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	INT2_R:1;
			__BYTE	INT1_R:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	INT1_R:1;
			__BYTE	INT2_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR0STR;

__IO_EXTENDED	  PRRR0STR	IO_PRRR0;
#define	_prrr0		(IO_PRRR0)
#define	PRRR0		(IO_PRRR0.byte)
#define	PRRR0_INT1_R  	(IO_PRRR0.bit.INT1_R)
#define	PRRR0_INT2_R  	(IO_PRRR0.bit.INT2_R)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR2,   locate=0x4D8
#pragma segment FAR_DATA=IO_PRRR2, locate=0x4D8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	PPG2_R:1;
			__BYTE	PPG1_R:1;
			__BYTE	PPG0_R:1;
#else
			__BYTE	PPG0_R:1;
			__BYTE	PPG1_R:1;
			__BYTE	PPG2_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	PPG2_R:1;
			__BYTE	PPG1_R:1;
			__BYTE	PPG0_R:1;
#else
			__BYTE	PPG0_R:1;
			__BYTE	PPG1_R:1;
			__BYTE	PPG2_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR2STR;

__IO_EXTENDED	  PRRR2STR	IO_PRRR2;
#define	_prrr2		(IO_PRRR2)
#define	PRRR2		(IO_PRRR2.byte)
#define	PRRR2_PPG0_R  	(IO_PRRR2.bit.PPG0_R)
#define	PRRR2_PPG1_R  	(IO_PRRR2.bit.PPG1_R)
#define	PRRR2_PPG2_R  	(IO_PRRR2.bit.PPG2_R)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR3,   locate=0x4D9
#pragma segment FAR_DATA=IO_PRRR3, locate=0x4D9
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TOT2_R:1;
			__BYTE	TIN2_R:1;
			__BYTE	TOT1_R:1;
			__BYTE	TIN1_R:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	TIN1_R:1;
			__BYTE	TOT1_R:1;
			__BYTE	TIN2_R:1;
			__BYTE	TOT2_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TOT2_R:1;
			__BYTE	TIN2_R:1;
			__BYTE	TOT1_R:1;
			__BYTE	TIN1_R:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	TIN1_R:1;
			__BYTE	TOT1_R:1;
			__BYTE	TIN2_R:1;
			__BYTE	TOT2_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR3STR;

__IO_EXTENDED	  PRRR3STR	IO_PRRR3;
#define	_prrr3		(IO_PRRR3)
#define	PRRR3		(IO_PRRR3.byte)
#define	PRRR3_TIN1_R  	(IO_PRRR3.bit.TIN1_R)
#define	PRRR3_TOT1_R  	(IO_PRRR3.bit.TOT1_R)
#define	PRRR3_TIN2_R  	(IO_PRRR3.bit.TIN2_R)
#define	PRRR3_TOT2_R  	(IO_PRRR3.bit.TOT2_R)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR4,   locate=0x4DA
#pragma segment FAR_DATA=IO_PRRR4, locate=0x4DA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	IN5_R:1;
			__BYTE	IN4_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	IN1_R:1;
			__BYTE	IN0_R:1;
#else
			__BYTE	IN0_R:1;
			__BYTE	IN1_R:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	IN4_R:1;
			__BYTE	IN5_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	IN5_R:1;
			__BYTE	IN4_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	IN1_R:1;
			__BYTE	IN0_R:1;
#else
			__BYTE	IN0_R:1;
			__BYTE	IN1_R:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	IN4_R:1;
			__BYTE	IN5_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR4STR;

__IO_EXTENDED	  PRRR4STR	IO_PRRR4;
#define	_prrr4		(IO_PRRR4)
#define	PRRR4		(IO_PRRR4.byte)
#define	PRRR4_IN0_R  	(IO_PRRR4.bit.IN0_R)
#define	PRRR4_IN1_R  	(IO_PRRR4.bit.IN1_R)
#define	PRRR4_IN4_R  	(IO_PRRR4.bit.IN4_R)
#define	PRRR4_IN5_R  	(IO_PRRR4.bit.IN5_R)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR9,   locate=0x4DF
#pragma segment FAR_DATA=IO_PRRR9, locate=0x4DF
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CKOT0_R:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	CKOT0_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CKOT0_R:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	CKOT0_R:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR9STR;

__IO_EXTENDED	  PRRR9STR	IO_PRRR9;
#define	_prrr9		(IO_PRRR9)
#define	PRRR9		(IO_PRRR9.byte)
#define	PRRR9_CKOT0_R  	(IO_PRRR9.bit.CKOT0_R)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_WT,   locate=0x4E0
#pragma segment FAR_DATA=IO_WT, locate=0x4E0
#endif

__IO_EXTENDED	struct {
	__BYTE	WTBRL0;
	__BYTE	WTBRH0;
	__BYTE	WTBR1;
	__BYTE	WTSR;
	__BYTE	WTMR;
	__BYTE	WTHR;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV67:1;
			__BYTE	RESV66:1;
			__BYTE	RESV65:1;
			__BYTE	RESV64:1;
			__BYTE	RESV63:1;
			__BYTE	RESV62:1;
			__BYTE	INTE4:1;
			__BYTE	INT4:1;
#else
			__BYTE	INT4:1;
			__BYTE	INTE4:1;
			__BYTE	RESV62:1;
			__BYTE	RESV63:1;
			__BYTE	RESV64:1;
			__BYTE	RESV65:1;
			__BYTE	RESV66:1;
			__BYTE	RESV67:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV67:1;
			__BYTE	RESV66:1;
			__BYTE	RESV65:1;
			__BYTE	RESV64:1;
			__BYTE	RESV63:1;
			__BYTE	RESV62:1;
			__BYTE	INTE4:1;
			__BYTE	INT4:1;
#else
			__BYTE	INT4:1;
			__BYTE	INTE4:1;
			__BYTE	RESV62:1;
			__BYTE	RESV63:1;
			__BYTE	RESV64:1;
			__BYTE	RESV65:1;
			__BYTE	RESV66:1;
			__BYTE	RESV67:1;
#endif
		} bitc;
	} WTCER;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV76:1;
			__BYTE	RESV75:1;
			__BYTE	RESV74:1;
			__BYTE	RESV73:1;
			__BYTE	RESV72:1;
			__BYTE	RESV71:1;
			__BYTE	CKSEL:2;
#else
			__BYTE	CKSEL:2;
			__BYTE	RESV71:1;
			__BYTE	RESV72:1;
			__BYTE	RESV73:1;
			__BYTE	RESV74:1;
			__BYTE	RESV75:1;
			__BYTE	RESV76:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV77:1;
			__BYTE	RESV76:1;
			__BYTE	RESV75:1;
			__BYTE	RESV74:1;
			__BYTE	RESV73:1;
			__BYTE	RESV72:1;
			__BYTE	CKSEL1:1;
			__BYTE	CKSEL0:1;
#else
			__BYTE	CKSEL0:1;
			__BYTE	CKSEL1:1;
			__BYTE	RESV72:1;
			__BYTE	RESV73:1;
			__BYTE	RESV74:1;
			__BYTE	RESV75:1;
			__BYTE	RESV76:1;
			__BYTE	RESV77:1;
#endif
		} bitc;
	} WTCKSR;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	INTE3:1;
			__WORD	INT3:1;
			__WORD	INTE2:1;
			__WORD	INT2:1;
			__WORD	INTE1:1;
			__WORD	INT1:1;
			__WORD	INTE0:1;
			__WORD	INT0:1;
			__WORD	RESV87:1;
			__WORD	RESV86:1;
			__WORD	RESV85:1;
			__WORD	RESV84:1;
			__WORD	RUN:1;
			__WORD	UPDT:1;
			__WORD	OE:1;
			__WORD	ST:1;
#else
			__WORD	ST:1;
			__WORD	OE:1;
			__WORD	UPDT:1;
			__WORD	RUN:1;
			__WORD	RESV84:1;
			__WORD	RESV85:1;
			__WORD	RESV86:1;
			__WORD	RESV87:1;
			__WORD	INT0:1;
			__WORD	INTE0:1;
			__WORD	INT1:1;
			__WORD	INTE1:1;
			__WORD	INT2:1;
			__WORD	INTE2:1;
			__WORD	INT3:1;
			__WORD	INTE3:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	INTE3:1;
			__WORD	INT3:1;
			__WORD	INTE2:1;
			__WORD	INT2:1;
			__WORD	INTE1:1;
			__WORD	INT1:1;
			__WORD	INTE0:1;
			__WORD	INT0:1;
			__WORD	RESV87:1;
			__WORD	RESV86:1;
			__WORD	RESV85:1;
			__WORD	RESV84:1;
			__WORD	RUN:1;
			__WORD	UPDT:1;
			__WORD	OE:1;
			__WORD	ST:1;
#else
			__WORD	ST:1;
			__WORD	OE:1;
			__WORD	UPDT:1;
			__WORD	RUN:1;
			__WORD	RESV84:1;
			__WORD	RESV85:1;
			__WORD	RESV86:1;
			__WORD	RESV87:1;
			__WORD	INT0:1;
			__WORD	INTE0:1;
			__WORD	INT1:1;
			__WORD	INTE1:1;
			__WORD	INT2:1;
			__WORD	INTE2:1;
			__WORD	INT3:1;
			__WORD	INTE3:1;
#endif
		} bitc;
	} WTCR;
} IO_WT;

#define	WT_WTBRL0 	(IO_WT.WTBRL0)
#define	WT_WTBRH0 	(IO_WT.WTBRH0)
#define	WT_WTBR1	(IO_WT.WTBR1)
#define	WT_WTSR	(IO_WT.WTSR)
#define	WT_WTMR	(IO_WT.WTMR)
#define	WT_WTHR	(IO_WT.WTHR)
#define	WT_WTCER			(IO_WT.WTCER.byte)
#define	WT_WTCER_INT4    	(IO_WT.WTCER.bit.INT4)
#define	WT_WTCER_INTE4    	(IO_WT.WTCER.bit.INTE4)
#define	WT_WTCKSR			(IO_WT.WTCKSR.byte)
#define	WT_WTCKSR_CKSEL    	(IO_WT.WTCKSR.bit.CKSEL)
#define	WT_WTCKSR_CKSEL0    	(IO_WT.WTCKSR.bitc.CKSEL0)
#define	WT_WTCKSR_CKSEL1    	(IO_WT.WTCKSR.bitc.CKSEL1)
#define	WT_WTCR			(IO_WT.WTCR.word)
#define	WT_WTCR_ST    	(IO_WT.WTCR.bit.ST)
#define	WT_WTCR_OE    	(IO_WT.WTCR.bit.OE)
#define	WT_WTCR_UPDT    	(IO_WT.WTCR.bit.UPDT)
#define	WT_WTCR_RUN    	(IO_WT.WTCR.bit.RUN)
#define	WT_WTCR_INT0    	(IO_WT.WTCR.bit.INT0)
#define	WT_WTCR_INTE0    	(IO_WT.WTCR.bit.INTE0)
#define	WT_WTCR_INT1    	(IO_WT.WTCR.bit.INT1)
#define	WT_WTCR_INTE1    	(IO_WT.WTCR.bit.INTE1)
#define	WT_WTCR_INT2    	(IO_WT.WTCR.bit.INT2)
#define	WT_WTCR_INTE2    	(IO_WT.WTCR.bit.INTE2)
#define	WT_WTCR_INT3    	(IO_WT.WTCR.bit.INT3)
#define	WT_WTCR_INTE3    	(IO_WT.WTCR.bit.INTE3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CUCR,   locate=0x4EA
#pragma segment FAR_DATA=IO_CUCR, locate=0x4EA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	STRT:1;
			__BYTE	RESV3:1;
			__BYTE	CKSEL:1;
			__BYTE	INT:1;
			__BYTE	INTEN:1;
#else
			__BYTE	INTEN:1;
			__BYTE	INT:1;
			__BYTE	CKSEL:1;
			__BYTE	RESV3:1;
			__BYTE	STRT:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	STRT:1;
			__BYTE	RESV3:1;
			__BYTE	CKSEL:1;
			__BYTE	INT:1;
			__BYTE	INTEN:1;
#else
			__BYTE	INTEN:1;
			__BYTE	INT:1;
			__BYTE	CKSEL:1;
			__BYTE	RESV3:1;
			__BYTE	STRT:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} CUCRSTR;

__IO_EXTENDED	  CUCRSTR	IO_CUCR;
#define	_cucr		(IO_CUCR)
#define	CUCR		(IO_CUCR.byte)
#define	CUCR_INTEN  	(IO_CUCR.bit.INTEN)
#define	CUCR_INT  	(IO_CUCR.bit.INT)
#define	CUCR_CKSEL  	(IO_CUCR.bit.CKSEL)
#define	CUCR_STRT  	(IO_CUCR.bit.STRT)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CUTD,   locate=0x4EC
#pragma segment FAR_DATA=IO_CUTD, locate=0x4EC
#endif

__IO_EXTENDED	__WORD	IO_CUTD;
#define	_cutd		(IO_CUTD)
#define	CUTD	(_cutd)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CUTR,   locate=0x4EE
#pragma segment FAR_DATA=IO_CUTR, locate=0x4EE
#endif

__IO_EXTENDED	const __LWORD	IO_CUTR;
#define	_cutr		(IO_CUTR)
#define	CUTR	(_cutr)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_TMISR,   locate=0x4FA
#pragma segment FAR_DATA=IO_TMISR, locate=0x4FA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TMS5:1;
			__BYTE	TMS4:1;
			__BYTE	TMS3:1;
			__BYTE	TMS2:1;
			__BYTE	TMS1:1;
			__BYTE	TMS0:1;
#else
			__BYTE	TMS0:1;
			__BYTE	TMS1:1;
			__BYTE	TMS2:1;
			__BYTE	TMS3:1;
			__BYTE	TMS4:1;
			__BYTE	TMS5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TMS5:1;
			__BYTE	TMS4:1;
			__BYTE	TMS3:1;
			__BYTE	TMS2:1;
			__BYTE	TMS1:1;
			__BYTE	TMS0:1;
#else
			__BYTE	TMS0:1;
			__BYTE	TMS1:1;
			__BYTE	TMS2:1;
			__BYTE	TMS3:1;
			__BYTE	TMS4:1;
			__BYTE	TMS5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} TMISRSTR;

__IO_EXTENDED	  TMISRSTR	IO_TMISR;
#define	_tmisr		(IO_TMISR)
#define	TMISR		(IO_TMISR.byte)
#define	TMISR_TMS0  	(IO_TMISR.bit.TMS0)
#define	TMISR_TMS1  	(IO_TMISR.bit.TMS1)
#define	TMISR_TMS2  	(IO_TMISR.bit.TMS2)
#define	TMISR_TMS3  	(IO_TMISR.bit.TMS3)
#define	TMISR_TMS4  	(IO_TMISR.bit.TMS4)
#define	TMISR_TMS5  	(IO_TMISR.bit.TMS5)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PWC0,   locate=0x5E0
#pragma segment FAR_DATA=IO_PWC0, locate=0x5E0
#endif

__IO_EXTENDED	struct {
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV05:1;
			__BYTE	P:3;
			__BYTE	CE:1;
			__BYTE	SC:1;
			__BYTE	RESV01:1;
			__BYTE	RESV00:1;
#else
			__BYTE	RESV00:1;
			__BYTE	RESV01:1;
			__BYTE	SC:1;
			__BYTE	CE:1;
			__BYTE	P:3;
			__BYTE	RESV05:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV07:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	CE:1;
			__BYTE	SC:1;
			__BYTE	RESV01:1;
			__BYTE	RESV00:1;
#else
			__BYTE	RESV00:1;
			__BYTE	RESV01:1;
			__BYTE	SC:1;
			__BYTE	CE:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	RESV07:1;
#endif
		} bitc;
	} PWC0;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV17:1;
			__BYTE	RESV16:1;
			__BYTE	RESV15:1;
			__BYTE	RESV14:1;
			__BYTE	RESV13:1;
			__BYTE	RESV12:1;
			__BYTE	OE2:1;
			__BYTE	OE1:1;
#else
			__BYTE	OE1:1;
			__BYTE	OE2:1;
			__BYTE	RESV12:1;
			__BYTE	RESV13:1;
			__BYTE	RESV14:1;
			__BYTE	RESV15:1;
			__BYTE	RESV16:1;
			__BYTE	RESV17:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV17:1;
			__BYTE	RESV16:1;
			__BYTE	RESV15:1;
			__BYTE	RESV14:1;
			__BYTE	RESV13:1;
			__BYTE	RESV12:1;
			__BYTE	OE2:1;
			__BYTE	OE1:1;
#else
			__BYTE	OE1:1;
			__BYTE	OE2:1;
			__BYTE	RESV12:1;
			__BYTE	RESV13:1;
			__BYTE	RESV14:1;
			__BYTE	RESV15:1;
			__BYTE	RESV16:1;
			__BYTE	RESV17:1;
#endif
		} bitc;
	} PWEC0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV215:1;
			__WORD	RESV214:1;
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
			__WORD	RESV214:1;
			__WORD	RESV215:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV215:1;
			__WORD	RESV214:1;
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
			__WORD	RESV214:1;
			__WORD	RESV215:1;
#endif
		} bitc;
	} PWC10;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV415:1;
			__WORD	RESV414:1;
			__WORD	RESV413:1;
			__WORD	RESV412:1;
			__WORD	RESV411:1;
			__WORD	RESV410:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV410:1;
			__WORD	RESV411:1;
			__WORD	RESV412:1;
			__WORD	RESV413:1;
			__WORD	RESV414:1;
			__WORD	RESV415:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV415:1;
			__WORD	RESV414:1;
			__WORD	RESV413:1;
			__WORD	RESV412:1;
			__WORD	RESV411:1;
			__WORD	RESV410:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV410:1;
			__WORD	RESV411:1;
			__WORD	RESV412:1;
			__WORD	RESV413:1;
			__WORD	RESV414:1;
			__WORD	RESV415:1;
#endif
		} bitc;
	} PWC20;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV63:1;
			__BYTE	RESV62:1;
			__BYTE	P:3;
			__BYTE	M:3;
#else
			__BYTE	M:3;
			__BYTE	P:3;
			__BYTE	RESV62:1;
			__BYTE	RESV63:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV67:1;
			__BYTE	RESV66:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	M2:1;
			__BYTE	M1:1;
			__BYTE	M0:1;
#else
			__BYTE	M0:1;
			__BYTE	M1:1;
			__BYTE	M2:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	RESV66:1;
			__BYTE	RESV67:1;
#endif
		} bitc;
	} PWS10;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV73:1;
			__BYTE	BS:1;
			__BYTE	P:3;
			__BYTE	M:3;
#else
			__BYTE	M:3;
			__BYTE	P:3;
			__BYTE	BS:1;
			__BYTE	RESV73:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV77:1;
			__BYTE	BS:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	M2:1;
			__BYTE	M1:1;
			__BYTE	M0:1;
#else
			__BYTE	M0:1;
			__BYTE	M1:1;
			__BYTE	M2:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	BS:1;
			__BYTE	RESV77:1;
#endif
		} bitc;
	} PWS20;
} IO_PWC0;

#define	PWC0_PWC0			(IO_PWC0.PWC0.byte)
#define	PWC0_PWC0_SC    	(IO_PWC0.PWC0.bit.SC)
#define	PWC0_PWC0_CE    	(IO_PWC0.PWC0.bit.CE)
#define	PWC0_PWC0_P    	(IO_PWC0.PWC0.bit.P)
#define	PWC0_PWC0_P0    	(IO_PWC0.PWC0.bitc.P0)
#define	PWC0_PWC0_P1    	(IO_PWC0.PWC0.bitc.P1)
#define	PWC0_PWC0_P2    	(IO_PWC0.PWC0.bitc.P2)
#define	PWC0_PWEC0			(IO_PWC0.PWEC0.byte)
#define	PWC0_PWEC0_OE1    	(IO_PWC0.PWEC0.bit.OE1)
#define	PWC0_PWEC0_OE2    	(IO_PWC0.PWEC0.bit.OE2)
#define	PWC0_PWC10			(IO_PWC0.PWC10.word)
#define	PWC0_PWC10_D0    	(IO_PWC0.PWC10.bit.D0)
#define	PWC0_PWC10_D1    	(IO_PWC0.PWC10.bit.D1)
#define	PWC0_PWC10_D2    	(IO_PWC0.PWC10.bit.D2)
#define	PWC0_PWC10_D3    	(IO_PWC0.PWC10.bit.D3)
#define	PWC0_PWC10_D4    	(IO_PWC0.PWC10.bit.D4)
#define	PWC0_PWC10_D5    	(IO_PWC0.PWC10.bit.D5)
#define	PWC0_PWC10_D6    	(IO_PWC0.PWC10.bit.D6)
#define	PWC0_PWC10_D7    	(IO_PWC0.PWC10.bit.D7)
#define	PWC0_PWC10_D8    	(IO_PWC0.PWC10.bit.D8)
#define	PWC0_PWC10_D9    	(IO_PWC0.PWC10.bit.D9)
#define	PWC0_PWC20			(IO_PWC0.PWC20.word)
#define	PWC0_PWC20_D0    	(IO_PWC0.PWC20.bit.D0)
#define	PWC0_PWC20_D1    	(IO_PWC0.PWC20.bit.D1)
#define	PWC0_PWC20_D2    	(IO_PWC0.PWC20.bit.D2)
#define	PWC0_PWC20_D3    	(IO_PWC0.PWC20.bit.D3)
#define	PWC0_PWC20_D4    	(IO_PWC0.PWC20.bit.D4)
#define	PWC0_PWC20_D5    	(IO_PWC0.PWC20.bit.D5)
#define	PWC0_PWC20_D6    	(IO_PWC0.PWC20.bit.D6)
#define	PWC0_PWC20_D7    	(IO_PWC0.PWC20.bit.D7)
#define	PWC0_PWC20_D8    	(IO_PWC0.PWC20.bit.D8)
#define	PWC0_PWC20_D9    	(IO_PWC0.PWC20.bit.D9)
#define	PWC0_PWS10			(IO_PWC0.PWS10.byte)
#define	PWC0_PWS10_M    	(IO_PWC0.PWS10.bit.M)
#define	PWC0_PWS10_M0    	(IO_PWC0.PWS10.bitc.M0)
#define	PWC0_PWS10_M1    	(IO_PWC0.PWS10.bitc.M1)
#define	PWC0_PWS10_M2    	(IO_PWC0.PWS10.bitc.M2)
#define	PWC0_PWS10_P    	(IO_PWC0.PWS10.bit.P)
#define	PWC0_PWS10_P0    	(IO_PWC0.PWS10.bitc.P0)
#define	PWC0_PWS10_P1    	(IO_PWC0.PWS10.bitc.P1)
#define	PWC0_PWS10_P2    	(IO_PWC0.PWS10.bitc.P2)
#define	PWC0_PWS20			(IO_PWC0.PWS20.byte)
#define	PWC0_PWS20_M    	(IO_PWC0.PWS20.bit.M)
#define	PWC0_PWS20_M0    	(IO_PWC0.PWS20.bitc.M0)
#define	PWC0_PWS20_M1    	(IO_PWC0.PWS20.bitc.M1)
#define	PWC0_PWS20_M2    	(IO_PWC0.PWS20.bitc.M2)
#define	PWC0_PWS20_P    	(IO_PWC0.PWS20.bit.P)
#define	PWC0_PWS20_P0    	(IO_PWC0.PWS20.bitc.P0)
#define	PWC0_PWS20_P1    	(IO_PWC0.PWS20.bitc.P1)
#define	PWC0_PWS20_P2    	(IO_PWC0.PWS20.bitc.P2)
#define	PWC0_PWS20_BS    	(IO_PWC0.PWS20.bit.BS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PWC1,   locate=0x5EA
#pragma segment FAR_DATA=IO_PWC1, locate=0x5EA
#endif

__IO_EXTENDED	struct {
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV05:1;
			__BYTE	P:3;
			__BYTE	CE:1;
			__BYTE	SC:1;
			__BYTE	RESV01:1;
			__BYTE	RESV00:1;
#else
			__BYTE	RESV00:1;
			__BYTE	RESV01:1;
			__BYTE	SC:1;
			__BYTE	CE:1;
			__BYTE	P:3;
			__BYTE	RESV05:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV07:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	CE:1;
			__BYTE	SC:1;
			__BYTE	RESV01:1;
			__BYTE	RESV00:1;
#else
			__BYTE	RESV00:1;
			__BYTE	RESV01:1;
			__BYTE	SC:1;
			__BYTE	CE:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	RESV07:1;
#endif
		} bitc;
	} PWC1;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV17:1;
			__BYTE	RESV16:1;
			__BYTE	RESV15:1;
			__BYTE	RESV14:1;
			__BYTE	RESV13:1;
			__BYTE	RESV12:1;
			__BYTE	OE2:1;
			__BYTE	OE1:1;
#else
			__BYTE	OE1:1;
			__BYTE	OE2:1;
			__BYTE	RESV12:1;
			__BYTE	RESV13:1;
			__BYTE	RESV14:1;
			__BYTE	RESV15:1;
			__BYTE	RESV16:1;
			__BYTE	RESV17:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV17:1;
			__BYTE	RESV16:1;
			__BYTE	RESV15:1;
			__BYTE	RESV14:1;
			__BYTE	RESV13:1;
			__BYTE	RESV12:1;
			__BYTE	OE2:1;
			__BYTE	OE1:1;
#else
			__BYTE	OE1:1;
			__BYTE	OE2:1;
			__BYTE	RESV12:1;
			__BYTE	RESV13:1;
			__BYTE	RESV14:1;
			__BYTE	RESV15:1;
			__BYTE	RESV16:1;
			__BYTE	RESV17:1;
#endif
		} bitc;
	} PWEC1;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV26:1;
			__WORD	RESV25:1;
			__WORD	RESV24:1;
			__WORD	RESV23:1;
			__WORD	RESV22:1;
			__WORD	RESV21:1;
			__WORD	D:10;
#else
			__WORD	D:10;
			__WORD	RESV21:1;
			__WORD	RESV22:1;
			__WORD	RESV23:1;
			__WORD	RESV24:1;
			__WORD	RESV25:1;
			__WORD	RESV26:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV215:1;
			__WORD	RESV214:1;
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
			__WORD	RESV214:1;
			__WORD	RESV215:1;
#endif
		} bitc;
	} PWC11;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV46:1;
			__WORD	RESV45:1;
			__WORD	RESV44:1;
			__WORD	RESV43:1;
			__WORD	RESV42:1;
			__WORD	RESV41:1;
			__WORD	D:10;
#else
			__WORD	D:10;
			__WORD	RESV41:1;
			__WORD	RESV42:1;
			__WORD	RESV43:1;
			__WORD	RESV44:1;
			__WORD	RESV45:1;
			__WORD	RESV46:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV415:1;
			__WORD	RESV414:1;
			__WORD	RESV413:1;
			__WORD	RESV412:1;
			__WORD	RESV411:1;
			__WORD	RESV410:1;
			__WORD	D9:1;
			__WORD	D8:1;
			__WORD	D7:1;
			__WORD	D6:1;
			__WORD	D5:1;
			__WORD	D4:1;
			__WORD	D3:1;
			__WORD	D2:1;
			__WORD	D1:1;
			__WORD	D0:1;
#else
			__WORD	D0:1;
			__WORD	D1:1;
			__WORD	D2:1;
			__WORD	D3:1;
			__WORD	D4:1;
			__WORD	D5:1;
			__WORD	D6:1;
			__WORD	D7:1;
			__WORD	D8:1;
			__WORD	D9:1;
			__WORD	RESV410:1;
			__WORD	RESV411:1;
			__WORD	RESV412:1;
			__WORD	RESV413:1;
			__WORD	RESV414:1;
			__WORD	RESV415:1;
#endif
		} bitc;
	} PWC21;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV63:1;
			__BYTE	RESV62:1;
			__BYTE	P:3;
			__BYTE	M:3;
#else
			__BYTE	M:3;
			__BYTE	P:3;
			__BYTE	RESV62:1;
			__BYTE	RESV63:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV67:1;
			__BYTE	RESV66:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	M2:1;
			__BYTE	M1:1;
			__BYTE	M0:1;
#else
			__BYTE	M0:1;
			__BYTE	M1:1;
			__BYTE	M2:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	RESV66:1;
			__BYTE	RESV67:1;
#endif
		} bitc;
	} PWS11;
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV73:1;
			__BYTE	BS:1;
			__BYTE	P:3;
			__BYTE	M:3;
#else
			__BYTE	M:3;
			__BYTE	P:3;
			__BYTE	BS:1;
			__BYTE	RESV73:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV77:1;
			__BYTE	BS:1;
			__BYTE	P2:1;
			__BYTE	P1:1;
			__BYTE	P0:1;
			__BYTE	M2:1;
			__BYTE	M1:1;
			__BYTE	M0:1;
#else
			__BYTE	M0:1;
			__BYTE	M1:1;
			__BYTE	M2:1;
			__BYTE	P0:1;
			__BYTE	P1:1;
			__BYTE	P2:1;
			__BYTE	BS:1;
			__BYTE	RESV77:1;
#endif
		} bitc;
	} PWS21;
} IO_PWC1;

#define	PWC1_PWC1			(IO_PWC1.PWC1.byte)
#define	PWC1_PWC1_SC    	(IO_PWC1.PWC1.bit.SC)
#define	PWC1_PWC1_CE    	(IO_PWC1.PWC1.bit.CE)
#define	PWC1_PWC1_P    	(IO_PWC1.PWC1.bit.P)
#define	PWC1_PWC1_P0    	(IO_PWC1.PWC1.bitc.P0)
#define	PWC1_PWC1_P1    	(IO_PWC1.PWC1.bitc.P1)
#define	PWC1_PWC1_P2    	(IO_PWC1.PWC1.bitc.P2)
#define	PWC1_PWEC1			(IO_PWC1.PWEC1.byte)
#define	PWC1_PWEC1_OE1    	(IO_PWC1.PWEC1.bit.OE1)
#define	PWC1_PWEC1_OE2    	(IO_PWC1.PWEC1.bit.OE2)
#define	PWC1_PWC11			(IO_PWC1.PWC11.word)
#define	PWC1_PWC11_D    	(IO_PWC1.PWC11.bit.D)
#define	PWC1_PWC11_D0    	(IO_PWC1.PWC11.bitc.D0)
#define	PWC1_PWC11_D1    	(IO_PWC1.PWC11.bitc.D1)
#define	PWC1_PWC11_D2    	(IO_PWC1.PWC11.bitc.D2)
#define	PWC1_PWC11_D3    	(IO_PWC1.PWC11.bitc.D3)
#define	PWC1_PWC11_D4    	(IO_PWC1.PWC11.bitc.D4)
#define	PWC1_PWC11_D5    	(IO_PWC1.PWC11.bitc.D5)
#define	PWC1_PWC11_D6    	(IO_PWC1.PWC11.bitc.D6)
#define	PWC1_PWC11_D7    	(IO_PWC1.PWC11.bitc.D7)
#define	PWC1_PWC11_D8    	(IO_PWC1.PWC11.bitc.D8)
#define	PWC1_PWC11_D9    	(IO_PWC1.PWC11.bitc.D9)
#define	PWC1_PWC21			(IO_PWC1.PWC21.word)
#define	PWC1_PWC21_D    	(IO_PWC1.PWC21.bit.D)
#define	PWC1_PWC21_D0    	(IO_PWC1.PWC21.bitc.D0)
#define	PWC1_PWC21_D1    	(IO_PWC1.PWC21.bitc.D1)
#define	PWC1_PWC21_D2    	(IO_PWC1.PWC21.bitc.D2)
#define	PWC1_PWC21_D3    	(IO_PWC1.PWC21.bitc.D3)
#define	PWC1_PWC21_D4    	(IO_PWC1.PWC21.bitc.D4)
#define	PWC1_PWC21_D5    	(IO_PWC1.PWC21.bitc.D5)
#define	PWC1_PWC21_D6    	(IO_PWC1.PWC21.bitc.D6)
#define	PWC1_PWC21_D7    	(IO_PWC1.PWC21.bitc.D7)
#define	PWC1_PWC21_D8    	(IO_PWC1.PWC21.bitc.D8)
#define	PWC1_PWC21_D9    	(IO_PWC1.PWC21.bitc.D9)
#define	PWC1_PWS11			(IO_PWC1.PWS11.byte)
#define	PWC1_PWS11_M    	(IO_PWC1.PWS11.bit.M)
#define	PWC1_PWS11_M0    	(IO_PWC1.PWS11.bitc.M0)
#define	PWC1_PWS11_M1    	(IO_PWC1.PWS11.bitc.M1)
#define	PWC1_PWS11_M2    	(IO_PWC1.PWS11.bitc.M2)
#define	PWC1_PWS11_P    	(IO_PWC1.PWS11.bit.P)
#define	PWC1_PWS11_P0    	(IO_PWC1.PWS11.bitc.P0)
#define	PWC1_PWS11_P1    	(IO_PWC1.PWS11.bitc.P1)
#define	PWC1_PWS11_P2    	(IO_PWC1.PWS11.bitc.P2)
#define	PWC1_PWS21			(IO_PWC1.PWS21.byte)
#define	PWC1_PWS21_M    	(IO_PWC1.PWS21.bit.M)
#define	PWC1_PWS21_M0    	(IO_PWC1.PWS21.bitc.M0)
#define	PWC1_PWS21_M1    	(IO_PWC1.PWS21.bitc.M1)
#define	PWC1_PWS21_M2    	(IO_PWC1.PWS21.bitc.M2)
#define	PWC1_PWS21_P    	(IO_PWC1.PWS21.bit.P)
#define	PWC1_PWS21_P0    	(IO_PWC1.PWS21.bitc.P0)
#define	PWC1_PWS21_P1    	(IO_PWC1.PWS21.bitc.P1)
#define	PWC1_PWS21_P2    	(IO_PWC1.PWS21.bitc.P2)
#define	PWC1_PWS21_BS    	(IO_PWC1.PWS21.bit.BS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER0,   locate=0x61C
#pragma segment FAR_DATA=IO_LCDER0, locate=0x61C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG7:1;
			__BYTE	SEG6:1;
			__BYTE	SEG5:1;
			__BYTE	SEG4:1;
			__BYTE	SEG3:1;
			__BYTE	SEG2:1;
			__BYTE	SEG1:1;
			__BYTE	SEG0:1;
#else
			__BYTE	SEG0:1;
			__BYTE	SEG1:1;
			__BYTE	SEG2:1;
			__BYTE	SEG3:1;
			__BYTE	SEG4:1;
			__BYTE	SEG5:1;
			__BYTE	SEG6:1;
			__BYTE	SEG7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG7:1;
			__BYTE	SEG6:1;
			__BYTE	SEG5:1;
			__BYTE	SEG4:1;
			__BYTE	SEG3:1;
			__BYTE	SEG2:1;
			__BYTE	SEG1:1;
			__BYTE	SEG0:1;
#else
			__BYTE	SEG0:1;
			__BYTE	SEG1:1;
			__BYTE	SEG2:1;
			__BYTE	SEG3:1;
			__BYTE	SEG4:1;
			__BYTE	SEG5:1;
			__BYTE	SEG6:1;
			__BYTE	SEG7:1;
#endif
	} bitc;
} LCDER0STR;

__IO_EXTENDED	  LCDER0STR	IO_LCDER0;
#define	_lcder0		(IO_LCDER0)
#define	LCDER0		(IO_LCDER0.byte)
#define	LCDER0_SEG0  	(IO_LCDER0.bit.SEG0)
#define	LCDER0_SEG1  	(IO_LCDER0.bit.SEG1)
#define	LCDER0_SEG2  	(IO_LCDER0.bit.SEG2)
#define	LCDER0_SEG3  	(IO_LCDER0.bit.SEG3)
#define	LCDER0_SEG4  	(IO_LCDER0.bit.SEG4)
#define	LCDER0_SEG5  	(IO_LCDER0.bit.SEG5)
#define	LCDER0_SEG6  	(IO_LCDER0.bit.SEG6)
#define	LCDER0_SEG7  	(IO_LCDER0.bit.SEG7)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER1,   locate=0x61D
#pragma segment FAR_DATA=IO_LCDER1, locate=0x61D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG15:1;
			__BYTE	SEG14:1;
			__BYTE	SEG13:1;
			__BYTE	SEG12:1;
			__BYTE	SEG11:1;
			__BYTE	SEG10:1;
			__BYTE	SEG9:1;
			__BYTE	SEG8:1;
#else
			__BYTE	SEG8:1;
			__BYTE	SEG9:1;
			__BYTE	SEG10:1;
			__BYTE	SEG11:1;
			__BYTE	SEG12:1;
			__BYTE	SEG13:1;
			__BYTE	SEG14:1;
			__BYTE	SEG15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG15:1;
			__BYTE	SEG14:1;
			__BYTE	SEG13:1;
			__BYTE	SEG12:1;
			__BYTE	SEG11:1;
			__BYTE	SEG10:1;
			__BYTE	SEG9:1;
			__BYTE	SEG8:1;
#else
			__BYTE	SEG8:1;
			__BYTE	SEG9:1;
			__BYTE	SEG10:1;
			__BYTE	SEG11:1;
			__BYTE	SEG12:1;
			__BYTE	SEG13:1;
			__BYTE	SEG14:1;
			__BYTE	SEG15:1;
#endif
	} bitc;
} LCDER1STR;

__IO_EXTENDED	  LCDER1STR	IO_LCDER1;
#define	_lcder1		(IO_LCDER1)
#define	LCDER1		(IO_LCDER1.byte)
#define	LCDER1_SEG8  	(IO_LCDER1.bit.SEG8)
#define	LCDER1_SEG9  	(IO_LCDER1.bit.SEG9)
#define	LCDER1_SEG10  	(IO_LCDER1.bit.SEG10)
#define	LCDER1_SEG11  	(IO_LCDER1.bit.SEG11)
#define	LCDER1_SEG12  	(IO_LCDER1.bit.SEG12)
#define	LCDER1_SEG13  	(IO_LCDER1.bit.SEG13)
#define	LCDER1_SEG14  	(IO_LCDER1.bit.SEG14)
#define	LCDER1_SEG15  	(IO_LCDER1.bit.SEG15)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER2,   locate=0x61E
#pragma segment FAR_DATA=IO_LCDER2, locate=0x61E
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG23:1;
			__BYTE	SEG22:1;
			__BYTE	SEG21:1;
			__BYTE	SEG20:1;
			__BYTE	SEG19:1;
			__BYTE	SEG18:1;
			__BYTE	SEG17:1;
			__BYTE	SEG16:1;
#else
			__BYTE	SEG16:1;
			__BYTE	SEG17:1;
			__BYTE	SEG18:1;
			__BYTE	SEG19:1;
			__BYTE	SEG20:1;
			__BYTE	SEG21:1;
			__BYTE	SEG22:1;
			__BYTE	SEG23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG23:1;
			__BYTE	SEG22:1;
			__BYTE	SEG21:1;
			__BYTE	SEG20:1;
			__BYTE	SEG19:1;
			__BYTE	SEG18:1;
			__BYTE	SEG17:1;
			__BYTE	SEG16:1;
#else
			__BYTE	SEG16:1;
			__BYTE	SEG17:1;
			__BYTE	SEG18:1;
			__BYTE	SEG19:1;
			__BYTE	SEG20:1;
			__BYTE	SEG21:1;
			__BYTE	SEG22:1;
			__BYTE	SEG23:1;
#endif
	} bitc;
} LCDER2STR;

__IO_EXTENDED	  LCDER2STR	IO_LCDER2;
#define	_lcder2		(IO_LCDER2)
#define	LCDER2		(IO_LCDER2.byte)
#define	LCDER2_SEG16  	(IO_LCDER2.bit.SEG16)
#define	LCDER2_SEG17  	(IO_LCDER2.bit.SEG17)
#define	LCDER2_SEG18  	(IO_LCDER2.bit.SEG18)
#define	LCDER2_SEG19  	(IO_LCDER2.bit.SEG19)
#define	LCDER2_SEG20  	(IO_LCDER2.bit.SEG20)
#define	LCDER2_SEG21  	(IO_LCDER2.bit.SEG21)
#define	LCDER2_SEG22  	(IO_LCDER2.bit.SEG22)
#define	LCDER2_SEG23  	(IO_LCDER2.bit.SEG23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER3,   locate=0x61F
#pragma segment FAR_DATA=IO_LCDER3, locate=0x61F
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG31:1;
			__BYTE	SEG30:1;
			__BYTE	SEG29:1;
			__BYTE	SEG28:1;
			__BYTE	SEG27:1;
			__BYTE	SEG26:1;
			__BYTE	SEG25:1;
			__BYTE	SEG24:1;
#else
			__BYTE	SEG24:1;
			__BYTE	SEG25:1;
			__BYTE	SEG26:1;
			__BYTE	SEG27:1;
			__BYTE	SEG28:1;
			__BYTE	SEG29:1;
			__BYTE	SEG30:1;
			__BYTE	SEG31:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG31:1;
			__BYTE	SEG30:1;
			__BYTE	SEG29:1;
			__BYTE	SEG28:1;
			__BYTE	SEG27:1;
			__BYTE	SEG26:1;
			__BYTE	SEG25:1;
			__BYTE	SEG24:1;
#else
			__BYTE	SEG24:1;
			__BYTE	SEG25:1;
			__BYTE	SEG26:1;
			__BYTE	SEG27:1;
			__BYTE	SEG28:1;
			__BYTE	SEG29:1;
			__BYTE	SEG30:1;
			__BYTE	SEG31:1;
#endif
	} bitc;
} LCDER3STR;

__IO_EXTENDED	  LCDER3STR	IO_LCDER3;
#define	_lcder3		(IO_LCDER3)
#define	LCDER3		(IO_LCDER3.byte)
#define	LCDER3_SEG24  	(IO_LCDER3.bit.SEG24)
#define	LCDER3_SEG25  	(IO_LCDER3.bit.SEG25)
#define	LCDER3_SEG26  	(IO_LCDER3.bit.SEG26)
#define	LCDER3_SEG27  	(IO_LCDER3.bit.SEG27)
#define	LCDER3_SEG28  	(IO_LCDER3.bit.SEG28)
#define	LCDER3_SEG29  	(IO_LCDER3.bit.SEG29)
#define	LCDER3_SEG30  	(IO_LCDER3.bit.SEG30)
#define	LCDER3_SEG31  	(IO_LCDER3.bit.SEG31)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER4,   locate=0x620
#pragma segment FAR_DATA=IO_LCDER4, locate=0x620
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG39:1;
			__BYTE	SEG38:1;
			__BYTE	SEG37:1;
			__BYTE	SEG36:1;
			__BYTE	SEG35:1;
			__BYTE	SEG34:1;
			__BYTE	SEG33:1;
			__BYTE	SEG32:1;
#else
			__BYTE	SEG32:1;
			__BYTE	SEG33:1;
			__BYTE	SEG34:1;
			__BYTE	SEG35:1;
			__BYTE	SEG36:1;
			__BYTE	SEG37:1;
			__BYTE	SEG38:1;
			__BYTE	SEG39:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG39:1;
			__BYTE	SEG38:1;
			__BYTE	SEG37:1;
			__BYTE	SEG36:1;
			__BYTE	SEG35:1;
			__BYTE	SEG34:1;
			__BYTE	SEG33:1;
			__BYTE	SEG32:1;
#else
			__BYTE	SEG32:1;
			__BYTE	SEG33:1;
			__BYTE	SEG34:1;
			__BYTE	SEG35:1;
			__BYTE	SEG36:1;
			__BYTE	SEG37:1;
			__BYTE	SEG38:1;
			__BYTE	SEG39:1;
#endif
	} bitc;
} LCDER4STR;

__IO_EXTENDED	  LCDER4STR	IO_LCDER4;
#define	_lcder4		(IO_LCDER4)
#define	LCDER4		(IO_LCDER4.byte)
#define	LCDER4_SEG32  	(IO_LCDER4.bit.SEG32)
#define	LCDER4_SEG33  	(IO_LCDER4.bit.SEG33)
#define	LCDER4_SEG34  	(IO_LCDER4.bit.SEG34)
#define	LCDER4_SEG35  	(IO_LCDER4.bit.SEG35)
#define	LCDER4_SEG36  	(IO_LCDER4.bit.SEG36)
#define	LCDER4_SEG37  	(IO_LCDER4.bit.SEG37)
#define	LCDER4_SEG38  	(IO_LCDER4.bit.SEG38)
#define	LCDER4_SEG39  	(IO_LCDER4.bit.SEG39)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER5,   locate=0x621
#pragma segment FAR_DATA=IO_LCDER5, locate=0x621
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG47:1;
			__BYTE	SEG46:1;
			__BYTE	SEG45:1;
			__BYTE	SEG44:1;
			__BYTE	SEG43:1;
			__BYTE	SEG42:1;
			__BYTE	SEG41:1;
			__BYTE	SEG40:1;
#else
			__BYTE	SEG40:1;
			__BYTE	SEG41:1;
			__BYTE	SEG42:1;
			__BYTE	SEG43:1;
			__BYTE	SEG44:1;
			__BYTE	SEG45:1;
			__BYTE	SEG46:1;
			__BYTE	SEG47:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG47:1;
			__BYTE	SEG46:1;
			__BYTE	SEG45:1;
			__BYTE	SEG44:1;
			__BYTE	SEG43:1;
			__BYTE	SEG42:1;
			__BYTE	SEG41:1;
			__BYTE	SEG40:1;
#else
			__BYTE	SEG40:1;
			__BYTE	SEG41:1;
			__BYTE	SEG42:1;
			__BYTE	SEG43:1;
			__BYTE	SEG44:1;
			__BYTE	SEG45:1;
			__BYTE	SEG46:1;
			__BYTE	SEG47:1;
#endif
	} bitc;
} LCDER5STR;

__IO_EXTENDED	  LCDER5STR	IO_LCDER5;
#define	_lcder5		(IO_LCDER5)
#define	LCDER5		(IO_LCDER5.byte)
#define	LCDER5_SEG40  	(IO_LCDER5.bit.SEG40)
#define	LCDER5_SEG41  	(IO_LCDER5.bit.SEG41)
#define	LCDER5_SEG42  	(IO_LCDER5.bit.SEG42)
#define	LCDER5_SEG43  	(IO_LCDER5.bit.SEG43)
#define	LCDER5_SEG44  	(IO_LCDER5.bit.SEG44)
#define	LCDER5_SEG45  	(IO_LCDER5.bit.SEG45)
#define	LCDER5_SEG46  	(IO_LCDER5.bit.SEG46)
#define	LCDER5_SEG47  	(IO_LCDER5.bit.SEG47)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER6,   locate=0x622
#pragma segment FAR_DATA=IO_LCDER6, locate=0x622
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG55:1;
			__BYTE	SEG54:1;
			__BYTE	SEG53:1;
			__BYTE	SEG52:1;
			__BYTE	SEG51:1;
			__BYTE	SEG50:1;
			__BYTE	SEG49:1;
			__BYTE	SEG48:1;
#else
			__BYTE	SEG48:1;
			__BYTE	SEG49:1;
			__BYTE	SEG50:1;
			__BYTE	SEG51:1;
			__BYTE	SEG52:1;
			__BYTE	SEG53:1;
			__BYTE	SEG54:1;
			__BYTE	SEG55:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG55:1;
			__BYTE	SEG54:1;
			__BYTE	SEG53:1;
			__BYTE	SEG52:1;
			__BYTE	SEG51:1;
			__BYTE	SEG50:1;
			__BYTE	SEG49:1;
			__BYTE	SEG48:1;
#else
			__BYTE	SEG48:1;
			__BYTE	SEG49:1;
			__BYTE	SEG50:1;
			__BYTE	SEG51:1;
			__BYTE	SEG52:1;
			__BYTE	SEG53:1;
			__BYTE	SEG54:1;
			__BYTE	SEG55:1;
#endif
	} bitc;
} LCDER6STR;

__IO_EXTENDED	  LCDER6STR	IO_LCDER6;
#define	_lcder6		(IO_LCDER6)
#define	LCDER6		(IO_LCDER6.byte)
#define	LCDER6_SEG48  	(IO_LCDER6.bit.SEG48)
#define	LCDER6_SEG49  	(IO_LCDER6.bit.SEG49)
#define	LCDER6_SEG50  	(IO_LCDER6.bit.SEG50)
#define	LCDER6_SEG51  	(IO_LCDER6.bit.SEG51)
#define	LCDER6_SEG52  	(IO_LCDER6.bit.SEG52)
#define	LCDER6_SEG53  	(IO_LCDER6.bit.SEG53)
#define	LCDER6_SEG54  	(IO_LCDER6.bit.SEG54)
#define	LCDER6_SEG55  	(IO_LCDER6.bit.SEG55)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDER7,   locate=0x623
#pragma segment FAR_DATA=IO_LCDER7, locate=0x623
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG63:1;
			__BYTE	SEG62:1;
			__BYTE	SEG61:1;
			__BYTE	SEG60:1;
			__BYTE	SEG59:1;
			__BYTE	SEG58:1;
			__BYTE	SEG57:1;
			__BYTE	SEG56:1;
#else
			__BYTE	SEG56:1;
			__BYTE	SEG57:1;
			__BYTE	SEG58:1;
			__BYTE	SEG59:1;
			__BYTE	SEG60:1;
			__BYTE	SEG61:1;
			__BYTE	SEG62:1;
			__BYTE	SEG63:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	SEG63:1;
			__BYTE	SEG62:1;
			__BYTE	SEG61:1;
			__BYTE	SEG60:1;
			__BYTE	SEG59:1;
			__BYTE	SEG58:1;
			__BYTE	SEG57:1;
			__BYTE	SEG56:1;
#else
			__BYTE	SEG56:1;
			__BYTE	SEG57:1;
			__BYTE	SEG58:1;
			__BYTE	SEG59:1;
			__BYTE	SEG60:1;
			__BYTE	SEG61:1;
			__BYTE	SEG62:1;
			__BYTE	SEG63:1;
#endif
	} bitc;
} LCDER7STR;

__IO_EXTENDED	  LCDER7STR	IO_LCDER7;
#define	_lcder7		(IO_LCDER7)
#define	LCDER7		(IO_LCDER7.byte)
#define	LCDER7_SEG56  	(IO_LCDER7.bit.SEG56)
#define	LCDER7_SEG57  	(IO_LCDER7.bit.SEG57)
#define	LCDER7_SEG58  	(IO_LCDER7.bit.SEG58)
#define	LCDER7_SEG59  	(IO_LCDER7.bit.SEG59)
#define	LCDER7_SEG60  	(IO_LCDER7.bit.SEG60)
#define	LCDER7_SEG61  	(IO_LCDER7.bit.SEG61)
#define	LCDER7_SEG62  	(IO_LCDER7.bit.SEG62)
#define	LCDER7_SEG63  	(IO_LCDER7.bit.SEG63)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDVER,   locate=0x626
#pragma segment FAR_DATA=IO_LCDVER, locate=0x626
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	V:4;
#else
			__BYTE	V:4;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	V3:1;
			__BYTE	V2:1;
			__BYTE	V1:1;
			__BYTE	V0:1;
#else
			__BYTE	V0:1;
			__BYTE	V1:1;
			__BYTE	V2:1;
			__BYTE	V3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} LCDVERSTR;

__IO_EXTENDED	  LCDVERSTR	IO_LCDVER;
#define	_lcdver		(IO_LCDVER)
#define	LCDVER		(IO_LCDVER.byte)
#define	LCDVER_V  	(IO_LCDVER.bit.V)
#define	LCDVER_V0  	(IO_LCDVER.bitc.V0)
#define	LCDVER_V1  	(IO_LCDVER.bitc.V1)
#define	LCDVER_V2  	(IO_LCDVER.bitc.V2)
#define	LCDVER_V3  	(IO_LCDVER.bitc.V3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LECR,   locate=0x627
#pragma segment FAR_DATA=IO_LECR, locate=0x627
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	EXFP:1;
			__BYTE	MCSEL:1;
			__BYTE	CKSEL:1;
#else
			__BYTE	CKSEL:1;
			__BYTE	MCSEL:1;
			__BYTE	EXFP:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	EXFP:1;
			__BYTE	MCSEL:1;
			__BYTE	CKSEL:1;
#else
			__BYTE	CKSEL:1;
			__BYTE	MCSEL:1;
			__BYTE	EXFP:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} LECRSTR;

__IO_EXTENDED	  LECRSTR	IO_LECR;
#define	_lecr		(IO_LECR)
#define	LECR		(IO_LECR.byte)
#define	LECR_CKSEL  	(IO_LECR.bit.CKSEL)
#define	LECR_MCSEL  	(IO_LECR.bit.MCSEL)
#define	LECR_EXFP  	(IO_LECR.bit.EXFP)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCDCMR,   locate=0x628
#pragma segment FAR_DATA=IO_LCDCMR, locate=0x628
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DTCH:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	COMEN3:1;
			__BYTE	COMEN2:1;
			__BYTE	COMEN1:1;
			__BYTE	COMEN0:1;
#else
			__BYTE	COMEN0:1;
			__BYTE	COMEN1:1;
			__BYTE	COMEN2:1;
			__BYTE	COMEN3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	DTCH:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DTCH:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	COMEN3:1;
			__BYTE	COMEN2:1;
			__BYTE	COMEN1:1;
			__BYTE	COMEN0:1;
#else
			__BYTE	COMEN0:1;
			__BYTE	COMEN1:1;
			__BYTE	COMEN2:1;
			__BYTE	COMEN3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	DTCH:1;
#endif
	} bitc;
} LCDCMRSTR;

__IO_EXTENDED	  LCDCMRSTR	IO_LCDCMR;
#define	_lcdcmr		(IO_LCDCMR)
#define	LCDCMR		(IO_LCDCMR.byte)
#define	LCDCMR_COMEN0  	(IO_LCDCMR.bit.COMEN0)
#define	LCDCMR_COMEN1  	(IO_LCDCMR.bit.COMEN1)
#define	LCDCMR_COMEN2  	(IO_LCDCMR.bit.COMEN2)
#define	LCDCMR_COMEN3  	(IO_LCDCMR.bit.COMEN3)
#define	LCDCMR_DTCH  	(IO_LCDCMR.bit.DTCH)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_LCR,   locate=0x629
#pragma segment FAR_DATA=IO_LCR, locate=0x629
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CSS:1;
			__BYTE	LCEN:1;
			__BYTE	VSEL:1;
			__BYTE	BK:1;
			__BYTE	MS:2;
			__BYTE	FP:2;
#else
			__BYTE	FP:2;
			__BYTE	MS:2;
			__BYTE	BK:1;
			__BYTE	VSEL:1;
			__BYTE	LCEN:1;
			__BYTE	CSS:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CSS:1;
			__BYTE	LCEN:1;
			__BYTE	VSEL:1;
			__BYTE	BK:1;
			__BYTE	MS1:1;
			__BYTE	MS0:1;
			__BYTE	FP1:1;
			__BYTE	FP0:1;
#else
			__BYTE	FP0:1;
			__BYTE	FP1:1;
			__BYTE	MS0:1;
			__BYTE	MS1:1;
			__BYTE	BK:1;
			__BYTE	VSEL:1;
			__BYTE	LCEN:1;
			__BYTE	CSS:1;
#endif
	} bitc;
} LCRSTR;

__IO_EXTENDED	  LCRSTR	IO_LCR;
#define	_lcr		(IO_LCR)
#define	LCR		(IO_LCR.byte)
#define	LCR_FP  	(IO_LCR.bit.FP)
#define	LCR_FP0  	(IO_LCR.bitc.FP0)
#define	LCR_FP1  	(IO_LCR.bitc.FP1)
#define	LCR_MS  	(IO_LCR.bit.MS)
#define	LCR_MS0  	(IO_LCR.bitc.MS0)
#define	LCR_MS1  	(IO_LCR.bitc.MS1)
#define	LCR_BK  	(IO_LCR.bit.BK)
#define	LCR_VSEL  	(IO_LCR.bit.VSEL)
#define	LCR_LCEN  	(IO_LCR.bit.LCEN)
#define	LCR_CSS  	(IO_LCR.bit.CSS)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM1,   locate=0x62B
#pragma segment FAR_DATA=IO_VRAM1, locate=0x62B
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM1STR;

__IO_EXTENDED	  VRAM1STR	IO_VRAM1;
#define	_vram1		(IO_VRAM1)
#define	VRAM1		(IO_VRAM1.byte)
#define	VRAM1_DL  	(IO_VRAM1.bit.DL)
#define	VRAM1_DL0  	(IO_VRAM1.bitc.DL0)
#define	VRAM1_DL1  	(IO_VRAM1.bitc.DL1)
#define	VRAM1_DL2  	(IO_VRAM1.bitc.DL2)
#define	VRAM1_DL3  	(IO_VRAM1.bitc.DL3)
#define	VRAM1_DH  	(IO_VRAM1.bit.DH)
#define	VRAM1_DH0  	(IO_VRAM1.bitc.DH0)
#define	VRAM1_DH1  	(IO_VRAM1.bitc.DH1)
#define	VRAM1_DH2  	(IO_VRAM1.bitc.DH2)
#define	VRAM1_DH3  	(IO_VRAM1.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM2,   locate=0x62C
#pragma segment FAR_DATA=IO_VRAM2, locate=0x62C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM2STR;

__IO_EXTENDED	  VRAM2STR	IO_VRAM2;
#define	_vram2		(IO_VRAM2)
#define	VRAM2		(IO_VRAM2.byte)
#define	VRAM2_DL  	(IO_VRAM2.bit.DL)
#define	VRAM2_DL0  	(IO_VRAM2.bitc.DL0)
#define	VRAM2_DL1  	(IO_VRAM2.bitc.DL1)
#define	VRAM2_DL2  	(IO_VRAM2.bitc.DL2)
#define	VRAM2_DL3  	(IO_VRAM2.bitc.DL3)
#define	VRAM2_DH  	(IO_VRAM2.bit.DH)
#define	VRAM2_DH0  	(IO_VRAM2.bitc.DH0)
#define	VRAM2_DH1  	(IO_VRAM2.bitc.DH1)
#define	VRAM2_DH2  	(IO_VRAM2.bitc.DH2)
#define	VRAM2_DH3  	(IO_VRAM2.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM3,   locate=0x62D
#pragma segment FAR_DATA=IO_VRAM3, locate=0x62D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM3STR;

__IO_EXTENDED	  VRAM3STR	IO_VRAM3;
#define	_vram3		(IO_VRAM3)
#define	VRAM3		(IO_VRAM3.byte)
#define	VRAM3_DL  	(IO_VRAM3.bit.DL)
#define	VRAM3_DL0  	(IO_VRAM3.bitc.DL0)
#define	VRAM3_DL1  	(IO_VRAM3.bitc.DL1)
#define	VRAM3_DL2  	(IO_VRAM3.bitc.DL2)
#define	VRAM3_DL3  	(IO_VRAM3.bitc.DL3)
#define	VRAM3_DH  	(IO_VRAM3.bit.DH)
#define	VRAM3_DH0  	(IO_VRAM3.bitc.DH0)
#define	VRAM3_DH1  	(IO_VRAM3.bitc.DH1)
#define	VRAM3_DH2  	(IO_VRAM3.bitc.DH2)
#define	VRAM3_DH3  	(IO_VRAM3.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM4,   locate=0x62E
#pragma segment FAR_DATA=IO_VRAM4, locate=0x62E
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM4STR;

__IO_EXTENDED	  VRAM4STR	IO_VRAM4;
#define	_vram4		(IO_VRAM4)
#define	VRAM4		(IO_VRAM4.byte)
#define	VRAM4_DL  	(IO_VRAM4.bit.DL)
#define	VRAM4_DL0  	(IO_VRAM4.bitc.DL0)
#define	VRAM4_DL1  	(IO_VRAM4.bitc.DL1)
#define	VRAM4_DL2  	(IO_VRAM4.bitc.DL2)
#define	VRAM4_DL3  	(IO_VRAM4.bitc.DL3)
#define	VRAM4_DH  	(IO_VRAM4.bit.DH)
#define	VRAM4_DH0  	(IO_VRAM4.bitc.DH0)
#define	VRAM4_DH1  	(IO_VRAM4.bitc.DH1)
#define	VRAM4_DH2  	(IO_VRAM4.bitc.DH2)
#define	VRAM4_DH3  	(IO_VRAM4.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM5,   locate=0x62F
#pragma segment FAR_DATA=IO_VRAM5, locate=0x62F
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM5STR;

__IO_EXTENDED	  VRAM5STR	IO_VRAM5;
#define	_vram5		(IO_VRAM5)
#define	VRAM5		(IO_VRAM5.byte)
#define	VRAM5_DL  	(IO_VRAM5.bit.DL)
#define	VRAM5_DL0  	(IO_VRAM5.bitc.DL0)
#define	VRAM5_DL1  	(IO_VRAM5.bitc.DL1)
#define	VRAM5_DL2  	(IO_VRAM5.bitc.DL2)
#define	VRAM5_DL3  	(IO_VRAM5.bitc.DL3)
#define	VRAM5_DH  	(IO_VRAM5.bit.DH)
#define	VRAM5_DH0  	(IO_VRAM5.bitc.DH0)
#define	VRAM5_DH1  	(IO_VRAM5.bitc.DH1)
#define	VRAM5_DH2  	(IO_VRAM5.bitc.DH2)
#define	VRAM5_DH3  	(IO_VRAM5.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM9,   locate=0x633
#pragma segment FAR_DATA=IO_VRAM9, locate=0x633
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM9STR;

__IO_EXTENDED	  VRAM9STR	IO_VRAM9;
#define	_vram9		(IO_VRAM9)
#define	VRAM9		(IO_VRAM9.byte)
#define	VRAM9_DL  	(IO_VRAM9.bit.DL)
#define	VRAM9_DL0  	(IO_VRAM9.bitc.DL0)
#define	VRAM9_DL1  	(IO_VRAM9.bitc.DL1)
#define	VRAM9_DL2  	(IO_VRAM9.bitc.DL2)
#define	VRAM9_DL3  	(IO_VRAM9.bitc.DL3)
#define	VRAM9_DH  	(IO_VRAM9.bit.DH)
#define	VRAM9_DH0  	(IO_VRAM9.bitc.DH0)
#define	VRAM9_DH1  	(IO_VRAM9.bitc.DH1)
#define	VRAM9_DH2  	(IO_VRAM9.bitc.DH2)
#define	VRAM9_DH3  	(IO_VRAM9.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM10,   locate=0x634
#pragma segment FAR_DATA=IO_VRAM10, locate=0x634
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM10STR;

__IO_EXTENDED	  VRAM10STR	IO_VRAM10;
#define	_vram10		(IO_VRAM10)
#define	VRAM10		(IO_VRAM10.byte)
#define	VRAM10_DL  	(IO_VRAM10.bit.DL)
#define	VRAM10_DL0  	(IO_VRAM10.bitc.DL0)
#define	VRAM10_DL1  	(IO_VRAM10.bitc.DL1)
#define	VRAM10_DL2  	(IO_VRAM10.bitc.DL2)
#define	VRAM10_DL3  	(IO_VRAM10.bitc.DL3)
#define	VRAM10_DH  	(IO_VRAM10.bit.DH)
#define	VRAM10_DH0  	(IO_VRAM10.bitc.DH0)
#define	VRAM10_DH1  	(IO_VRAM10.bitc.DH1)
#define	VRAM10_DH2  	(IO_VRAM10.bitc.DH2)
#define	VRAM10_DH3  	(IO_VRAM10.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM11,   locate=0x635
#pragma segment FAR_DATA=IO_VRAM11, locate=0x635
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM11STR;

__IO_EXTENDED	  VRAM11STR	IO_VRAM11;
#define	_vram11		(IO_VRAM11)
#define	VRAM11		(IO_VRAM11.byte)
#define	VRAM11_DL  	(IO_VRAM11.bit.DL)
#define	VRAM11_DL0  	(IO_VRAM11.bitc.DL0)
#define	VRAM11_DL1  	(IO_VRAM11.bitc.DL1)
#define	VRAM11_DL2  	(IO_VRAM11.bitc.DL2)
#define	VRAM11_DL3  	(IO_VRAM11.bitc.DL3)
#define	VRAM11_DH  	(IO_VRAM11.bit.DH)
#define	VRAM11_DH0  	(IO_VRAM11.bitc.DH0)
#define	VRAM11_DH1  	(IO_VRAM11.bitc.DH1)
#define	VRAM11_DH2  	(IO_VRAM11.bitc.DH2)
#define	VRAM11_DH3  	(IO_VRAM11.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM15,   locate=0x639
#pragma segment FAR_DATA=IO_VRAM15, locate=0x639
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM15STR;

__IO_EXTENDED	  VRAM15STR	IO_VRAM15;
#define	_vram15		(IO_VRAM15)
#define	VRAM15		(IO_VRAM15.byte)
#define	VRAM15_DL  	(IO_VRAM15.bit.DL)
#define	VRAM15_DL0  	(IO_VRAM15.bitc.DL0)
#define	VRAM15_DL1  	(IO_VRAM15.bitc.DL1)
#define	VRAM15_DL2  	(IO_VRAM15.bitc.DL2)
#define	VRAM15_DL3  	(IO_VRAM15.bitc.DL3)
#define	VRAM15_DH  	(IO_VRAM15.bit.DH)
#define	VRAM15_DH0  	(IO_VRAM15.bitc.DH0)
#define	VRAM15_DH1  	(IO_VRAM15.bitc.DH1)
#define	VRAM15_DH2  	(IO_VRAM15.bitc.DH2)
#define	VRAM15_DH3  	(IO_VRAM15.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM18,   locate=0x63C
#pragma segment FAR_DATA=IO_VRAM18, locate=0x63C
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM18STR;

__IO_EXTENDED	  VRAM18STR	IO_VRAM18;
#define	_vram18		(IO_VRAM18)
#define	VRAM18		(IO_VRAM18.byte)
#define	VRAM18_DL  	(IO_VRAM18.bit.DL)
#define	VRAM18_DL0  	(IO_VRAM18.bitc.DL0)
#define	VRAM18_DL1  	(IO_VRAM18.bitc.DL1)
#define	VRAM18_DL2  	(IO_VRAM18.bitc.DL2)
#define	VRAM18_DL3  	(IO_VRAM18.bitc.DL3)
#define	VRAM18_DH  	(IO_VRAM18.bit.DH)
#define	VRAM18_DH0  	(IO_VRAM18.bitc.DH0)
#define	VRAM18_DH1  	(IO_VRAM18.bitc.DH1)
#define	VRAM18_DH2  	(IO_VRAM18.bitc.DH2)
#define	VRAM18_DH3  	(IO_VRAM18.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM19,   locate=0x63D
#pragma segment FAR_DATA=IO_VRAM19, locate=0x63D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM19STR;

__IO_EXTENDED	  VRAM19STR	IO_VRAM19;
#define	_vram19		(IO_VRAM19)
#define	VRAM19		(IO_VRAM19.byte)
#define	VRAM19_DL  	(IO_VRAM19.bit.DL)
#define	VRAM19_DL0  	(IO_VRAM19.bitc.DL0)
#define	VRAM19_DL1  	(IO_VRAM19.bitc.DL1)
#define	VRAM19_DL2  	(IO_VRAM19.bitc.DL2)
#define	VRAM19_DL3  	(IO_VRAM19.bitc.DL3)
#define	VRAM19_DH  	(IO_VRAM19.bit.DH)
#define	VRAM19_DH0  	(IO_VRAM19.bitc.DH0)
#define	VRAM19_DH1  	(IO_VRAM19.bitc.DH1)
#define	VRAM19_DH2  	(IO_VRAM19.bitc.DH2)
#define	VRAM19_DH3  	(IO_VRAM19.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM21,   locate=0x63F
#pragma segment FAR_DATA=IO_VRAM21, locate=0x63F
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM21STR;

__IO_EXTENDED	  VRAM21STR	IO_VRAM21;
#define	_vram21		(IO_VRAM21)
#define	VRAM21		(IO_VRAM21.byte)
#define	VRAM21_DL  	(IO_VRAM21.bit.DL)
#define	VRAM21_DL0  	(IO_VRAM21.bitc.DL0)
#define	VRAM21_DL1  	(IO_VRAM21.bitc.DL1)
#define	VRAM21_DL2  	(IO_VRAM21.bitc.DL2)
#define	VRAM21_DL3  	(IO_VRAM21.bitc.DL3)
#define	VRAM21_DH  	(IO_VRAM21.bit.DH)
#define	VRAM21_DH0  	(IO_VRAM21.bitc.DH0)
#define	VRAM21_DH1  	(IO_VRAM21.bitc.DH1)
#define	VRAM21_DH2  	(IO_VRAM21.bitc.DH2)
#define	VRAM21_DH3  	(IO_VRAM21.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM22,   locate=0x640
#pragma segment FAR_DATA=IO_VRAM22, locate=0x640
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM22STR;

__IO_EXTENDED	  VRAM22STR	IO_VRAM22;
#define	_vram22		(IO_VRAM22)
#define	VRAM22		(IO_VRAM22.byte)
#define	VRAM22_DL  	(IO_VRAM22.bit.DL)
#define	VRAM22_DL0  	(IO_VRAM22.bitc.DL0)
#define	VRAM22_DL1  	(IO_VRAM22.bitc.DL1)
#define	VRAM22_DL2  	(IO_VRAM22.bitc.DL2)
#define	VRAM22_DL3  	(IO_VRAM22.bitc.DL3)
#define	VRAM22_DH  	(IO_VRAM22.bit.DH)
#define	VRAM22_DH0  	(IO_VRAM22.bitc.DH0)
#define	VRAM22_DH1  	(IO_VRAM22.bitc.DH1)
#define	VRAM22_DH2  	(IO_VRAM22.bitc.DH2)
#define	VRAM22_DH3  	(IO_VRAM22.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM23,   locate=0x641
#pragma segment FAR_DATA=IO_VRAM23, locate=0x641
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM23STR;

__IO_EXTENDED	  VRAM23STR	IO_VRAM23;
#define	_vram23		(IO_VRAM23)
#define	VRAM23		(IO_VRAM23.byte)
#define	VRAM23_DL  	(IO_VRAM23.bit.DL)
#define	VRAM23_DL0  	(IO_VRAM23.bitc.DL0)
#define	VRAM23_DL1  	(IO_VRAM23.bitc.DL1)
#define	VRAM23_DL2  	(IO_VRAM23.bitc.DL2)
#define	VRAM23_DL3  	(IO_VRAM23.bitc.DL3)
#define	VRAM23_DH  	(IO_VRAM23.bit.DH)
#define	VRAM23_DH0  	(IO_VRAM23.bitc.DH0)
#define	VRAM23_DH1  	(IO_VRAM23.bitc.DH1)
#define	VRAM23_DH2  	(IO_VRAM23.bitc.DH2)
#define	VRAM23_DH3  	(IO_VRAM23.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM27,   locate=0x645
#pragma segment FAR_DATA=IO_VRAM27, locate=0x645
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM27STR;

__IO_EXTENDED	  VRAM27STR	IO_VRAM27;
#define	_vram27		(IO_VRAM27)
#define	VRAM27		(IO_VRAM27.byte)
#define	VRAM27_DL  	(IO_VRAM27.bit.DL)
#define	VRAM27_DL0  	(IO_VRAM27.bitc.DL0)
#define	VRAM27_DL1  	(IO_VRAM27.bitc.DL1)
#define	VRAM27_DL2  	(IO_VRAM27.bitc.DL2)
#define	VRAM27_DL3  	(IO_VRAM27.bitc.DL3)
#define	VRAM27_DH  	(IO_VRAM27.bit.DH)
#define	VRAM27_DH0  	(IO_VRAM27.bitc.DH0)
#define	VRAM27_DH1  	(IO_VRAM27.bitc.DH1)
#define	VRAM27_DH2  	(IO_VRAM27.bitc.DH2)
#define	VRAM27_DH3  	(IO_VRAM27.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_VRAM28,   locate=0x646
#pragma segment FAR_DATA=IO_VRAM28, locate=0x646
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH:4;
			__BYTE	DL:4;
#else
			__BYTE	DL:4;
			__BYTE	DH:4;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DH3:1;
			__BYTE	DH2:1;
			__BYTE	DH1:1;
			__BYTE	DH0:1;
			__BYTE	DL3:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	DL3:1;
			__BYTE	DH0:1;
			__BYTE	DH1:1;
			__BYTE	DH2:1;
			__BYTE	DH3:1;
#endif
	} bitc;
} VRAM28STR;

__IO_EXTENDED	  VRAM28STR	IO_VRAM28;
#define	_vram28		(IO_VRAM28)
#define	VRAM28		(IO_VRAM28.byte)
#define	VRAM28_DL  	(IO_VRAM28.bit.DL)
#define	VRAM28_DL0  	(IO_VRAM28.bitc.DL0)
#define	VRAM28_DL1  	(IO_VRAM28.bitc.DL1)
#define	VRAM28_DL2  	(IO_VRAM28.bitc.DL2)
#define	VRAM28_DL3  	(IO_VRAM28.bitc.DL3)
#define	VRAM28_DH  	(IO_VRAM28.bit.DH)
#define	VRAM28_DH0  	(IO_VRAM28.bitc.DH0)
#define	VRAM28_DH1  	(IO_VRAM28.bitc.DH1)
#define	VRAM28_DH2  	(IO_VRAM28.bitc.DH2)
#define	VRAM28_DH3  	(IO_VRAM28.bitc.DH3)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_PRRR13,   locate=0x663
#pragma segment FAR_DATA=IO_PRRR13, locate=0x663
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	WOT_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	WOT_R:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	WOT_R:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RESV0:1;
#else
			__BYTE	RESV0:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	WOT_R:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} PRRR13STR;

__IO_EXTENDED	  PRRR13STR	IO_PRRR13;
#define	_prrr13		(IO_PRRR13)
#define	PRRR13		(IO_PRRR13.byte)
#define	PRRR13_WOT_R  	(IO_PRRR13.bit.WOT_R)

#if defined(__CPU_MB96F673RA__) || \
    defined(__CPU_MB96F675RA__) || \
    defined(__CPU_MB96F673RB__) || \
    defined(__CPU_MB96F675RB__) 

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CAN0,   locate=0x700
#pragma segment FAR_DATA=IO_CAN0, locate=0x700
#endif

__IO_EXTENDED	struct {
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV015:1;
			__WORD	RESV014:1;
			__WORD	RESV013:1;
			__WORD	RESV012:1;
			__WORD	RESV011:1;
			__WORD	RESV010:1;
			__WORD	RESV09:1;
			__WORD	RESV08:1;
			__WORD	TEST:1;
			__WORD	CCE:1;
			__WORD	DAR:1;
			__WORD	RESV04:1;
			__WORD	EIE:1;
			__WORD	SIE:1;
			__WORD	IE:1;
			__WORD	INIT:1;
#else
			__WORD	INIT:1;
			__WORD	IE:1;
			__WORD	SIE:1;
			__WORD	EIE:1;
			__WORD	RESV04:1;
			__WORD	DAR:1;
			__WORD	CCE:1;
			__WORD	TEST:1;
			__WORD	RESV08:1;
			__WORD	RESV09:1;
			__WORD	RESV010:1;
			__WORD	RESV011:1;
			__WORD	RESV012:1;
			__WORD	RESV013:1;
			__WORD	RESV014:1;
			__WORD	RESV015:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV015:1;
			__WORD	RESV014:1;
			__WORD	RESV013:1;
			__WORD	RESV012:1;
			__WORD	RESV011:1;
			__WORD	RESV010:1;
			__WORD	RESV09:1;
			__WORD	RESV08:1;
			__WORD	TEST:1;
			__WORD	CCE:1;
			__WORD	DAR:1;
			__WORD	RESV04:1;
			__WORD	EIE:1;
			__WORD	SIE:1;
			__WORD	IE:1;
			__WORD	INIT:1;
#else
			__WORD	INIT:1;
			__WORD	IE:1;
			__WORD	SIE:1;
			__WORD	EIE:1;
			__WORD	RESV04:1;
			__WORD	DAR:1;
			__WORD	CCE:1;
			__WORD	TEST:1;
			__WORD	RESV08:1;
			__WORD	RESV09:1;
			__WORD	RESV010:1;
			__WORD	RESV011:1;
			__WORD	RESV012:1;
			__WORD	RESV013:1;
			__WORD	RESV014:1;
			__WORD	RESV015:1;
#endif
		} bitc;
	} CTRLR0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	RESV29:1;
			__WORD	RESV28:1;
			__WORD	RESV27:1;
			__WORD	RESV26:1;
			__WORD	BOFF:1;
			__WORD	EWARN:1;
			__WORD	EPASS:1;
			__WORD	RXOK:1;
			__WORD	TXOK:1;
			__WORD	LEC:3;
#else
			__WORD	LEC:3;
			__WORD	TXOK:1;
			__WORD	RXOK:1;
			__WORD	EPASS:1;
			__WORD	EWARN:1;
			__WORD	BOFF:1;
			__WORD	RESV26:1;
			__WORD	RESV27:1;
			__WORD	RESV28:1;
			__WORD	RESV29:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV215:1;
			__WORD	RESV214:1;
			__WORD	RESV213:1;
			__WORD	RESV212:1;
			__WORD	RESV211:1;
			__WORD	RESV210:1;
			__WORD	RESV29:1;
			__WORD	RESV28:1;
			__WORD	BOFF:1;
			__WORD	EWARN:1;
			__WORD	EPASS:1;
			__WORD	RXOK:1;
			__WORD	TXOK:1;
			__WORD	LEC2:1;
			__WORD	LEC1:1;
			__WORD	LEC0:1;
#else
			__WORD	LEC0:1;
			__WORD	LEC1:1;
			__WORD	LEC2:1;
			__WORD	TXOK:1;
			__WORD	RXOK:1;
			__WORD	EPASS:1;
			__WORD	EWARN:1;
			__WORD	BOFF:1;
			__WORD	RESV28:1;
			__WORD	RESV29:1;
			__WORD	RESV210:1;
			__WORD	RESV211:1;
			__WORD	RESV212:1;
			__WORD	RESV213:1;
			__WORD	RESV214:1;
			__WORD	RESV215:1;
#endif
		} bitc;
	} STATR0;
	const union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RP:1;
			__WORD	REC:7;
			__WORD	TEC:8;
#else
			__WORD	TEC:8;
			__WORD	REC:7;
			__WORD	RP:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RP:1;
			__WORD	REC6:1;
			__WORD	REC5:1;
			__WORD	REC4:1;
			__WORD	REC3:1;
			__WORD	REC2:1;
			__WORD	REC1:1;
			__WORD	REC0:1;
			__WORD	TEC7:1;
			__WORD	TEC6:1;
			__WORD	TEC5:1;
			__WORD	TEC4:1;
			__WORD	TEC3:1;
			__WORD	TEC2:1;
			__WORD	TEC1:1;
			__WORD	TEC0:1;
#else
			__WORD	TEC0:1;
			__WORD	TEC1:1;
			__WORD	TEC2:1;
			__WORD	TEC3:1;
			__WORD	TEC4:1;
			__WORD	TEC5:1;
			__WORD	TEC6:1;
			__WORD	TEC7:1;
			__WORD	REC0:1;
			__WORD	REC1:1;
			__WORD	REC2:1;
			__WORD	REC3:1;
			__WORD	REC4:1;
			__WORD	REC5:1;
			__WORD	REC6:1;
			__WORD	RP:1;
#endif
		} bitc;
	} ERRCNT0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV64:1;
			__WORD	TSEG2:3;
			__WORD	TSEG1:4;
			__WORD	SJW:2;
			__WORD	BRP:6;
#else
			__WORD	BRP:6;
			__WORD	SJW:2;
			__WORD	TSEG1:4;
			__WORD	TSEG2:3;
			__WORD	RESV64:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV615:1;
			__WORD	TSEG22:1;
			__WORD	TSEG21:1;
			__WORD	TSEG20:1;
			__WORD	TSEG13:1;
			__WORD	TSEG12:1;
			__WORD	TSEG11:1;
			__WORD	TSEG10:1;
			__WORD	SJW1:1;
			__WORD	SJW0:1;
			__WORD	BRP5:1;
			__WORD	BRP4:1;
			__WORD	BRP3:1;
			__WORD	BRP2:1;
			__WORD	BRP1:1;
			__WORD	BRP0:1;
#else
			__WORD	BRP0:1;
			__WORD	BRP1:1;
			__WORD	BRP2:1;
			__WORD	BRP3:1;
			__WORD	BRP4:1;
			__WORD	BRP5:1;
			__WORD	SJW0:1;
			__WORD	SJW1:1;
			__WORD	TSEG10:1;
			__WORD	TSEG11:1;
			__WORD	TSEG12:1;
			__WORD	TSEG13:1;
			__WORD	TSEG20:1;
			__WORD	TSEG21:1;
			__WORD	TSEG22:1;
			__WORD	RESV615:1;
#endif
		} bitc;
	} BTR0;
	const __WORD	INTR0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1014:1;
			__WORD	RESV1013:1;
			__WORD	RESV1012:1;
			__WORD	RESV1011:1;
			__WORD	RESV1010:1;
			__WORD	RESV109:1;
			__WORD	RESV108:1;
			__WORD	RESV107:1;
			__WORD	RX:1;
			__WORD	TX:2;
			__WORD	LBACK:1;
			__WORD	SILENT:1;
			__WORD	BASIC:1;
			__WORD	RESV101:1;
			__WORD	RESV100:1;
#else
			__WORD	RESV100:1;
			__WORD	RESV101:1;
			__WORD	BASIC:1;
			__WORD	SILENT:1;
			__WORD	LBACK:1;
			__WORD	TX:2;
			__WORD	RX:1;
			__WORD	RESV107:1;
			__WORD	RESV108:1;
			__WORD	RESV109:1;
			__WORD	RESV1010:1;
			__WORD	RESV1011:1;
			__WORD	RESV1012:1;
			__WORD	RESV1013:1;
			__WORD	RESV1014:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1015:1;
			__WORD	RESV1014:1;
			__WORD	RESV1013:1;
			__WORD	RESV1012:1;
			__WORD	RESV1011:1;
			__WORD	RESV1010:1;
			__WORD	RESV109:1;
			__WORD	RESV108:1;
			__WORD	RX:1;
			__WORD	TX1:1;
			__WORD	TX0:1;
			__WORD	LBACK:1;
			__WORD	SILENT:1;
			__WORD	BASIC:1;
			__WORD	RESV101:1;
			__WORD	RESV100:1;
#else
			__WORD	RESV100:1;
			__WORD	RESV101:1;
			__WORD	BASIC:1;
			__WORD	SILENT:1;
			__WORD	LBACK:1;
			__WORD	TX0:1;
			__WORD	TX1:1;
			__WORD	RX:1;
			__WORD	RESV108:1;
			__WORD	RESV109:1;
			__WORD	RESV1010:1;
			__WORD	RESV1011:1;
			__WORD	RESV1012:1;
			__WORD	RESV1013:1;
			__WORD	RESV1014:1;
			__WORD	RESV1015:1;
#endif
		} bitc;
	} TESTR0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1212:1;
			__WORD	RESV1211:1;
			__WORD	RESV1210:1;
			__WORD	RESV129:1;
			__WORD	RESV128:1;
			__WORD	RESV127:1;
			__WORD	RESV126:1;
			__WORD	RESV125:1;
			__WORD	RESV124:1;
			__WORD	RESV123:1;
			__WORD	RESV122:1;
			__WORD	RESV121:1;
			__WORD	BRPE:4;
#else
			__WORD	BRPE:4;
			__WORD	RESV121:1;
			__WORD	RESV122:1;
			__WORD	RESV123:1;
			__WORD	RESV124:1;
			__WORD	RESV125:1;
			__WORD	RESV126:1;
			__WORD	RESV127:1;
			__WORD	RESV128:1;
			__WORD	RESV129:1;
			__WORD	RESV1210:1;
			__WORD	RESV1211:1;
			__WORD	RESV1212:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1215:1;
			__WORD	RESV1214:1;
			__WORD	RESV1213:1;
			__WORD	RESV1212:1;
			__WORD	RESV1211:1;
			__WORD	RESV1210:1;
			__WORD	RESV129:1;
			__WORD	RESV128:1;
			__WORD	RESV127:1;
			__WORD	RESV126:1;
			__WORD	RESV125:1;
			__WORD	RESV124:1;
			__WORD	BRPE3:1;
			__WORD	BRPE2:1;
			__WORD	BRPE1:1;
			__WORD	BRPE0:1;
#else
			__WORD	BRPE0:1;
			__WORD	BRPE1:1;
			__WORD	BRPE2:1;
			__WORD	BRPE3:1;
			__WORD	RESV124:1;
			__WORD	RESV125:1;
			__WORD	RESV126:1;
			__WORD	RESV127:1;
			__WORD	RESV128:1;
			__WORD	RESV129:1;
			__WORD	RESV1210:1;
			__WORD	RESV1211:1;
			__WORD	RESV1212:1;
			__WORD	RESV1213:1;
			__WORD	RESV1214:1;
			__WORD	RESV1215:1;
#endif
		} bitc;
	} BRPER0;
	__WORD	RESV1;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BUSY:1;
			__WORD	RESV167:1;
			__WORD	RESV166:1;
			__WORD	RESV165:1;
			__WORD	RESV164:1;
			__WORD	RESV163:1;
			__WORD	RESV162:1;
			__WORD	RESV161:1;
			__WORD	MSGN:8;
#else
			__WORD	MSGN:8;
			__WORD	RESV161:1;
			__WORD	RESV162:1;
			__WORD	RESV163:1;
			__WORD	RESV164:1;
			__WORD	RESV165:1;
			__WORD	RESV166:1;
			__WORD	RESV167:1;
			__WORD	BUSY:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BUSY:1;
			__WORD	RESV1614:1;
			__WORD	RESV1613:1;
			__WORD	RESV1612:1;
			__WORD	RESV1611:1;
			__WORD	RESV1610:1;
			__WORD	RESV169:1;
			__WORD	RESV168:1;
			__WORD	MSGN7:1;
			__WORD	MSGN6:1;
			__WORD	MSGN5:1;
			__WORD	MSGN4:1;
			__WORD	MSGN3:1;
			__WORD	MSGN2:1;
			__WORD	MSGN1:1;
			__WORD	MSGN0:1;
#else
			__WORD	MSGN0:1;
			__WORD	MSGN1:1;
			__WORD	MSGN2:1;
			__WORD	MSGN3:1;
			__WORD	MSGN4:1;
			__WORD	MSGN5:1;
			__WORD	MSGN6:1;
			__WORD	MSGN7:1;
			__WORD	RESV168:1;
			__WORD	RESV169:1;
			__WORD	RESV1610:1;
			__WORD	RESV1611:1;
			__WORD	RESV1612:1;
			__WORD	RESV1613:1;
			__WORD	RESV1614:1;
			__WORD	BUSY:1;
#endif
		} bitc;
	} IF1CREQ0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1815:1;
			__WORD	RESV1814:1;
			__WORD	RESV1813:1;
			__WORD	RESV1812:1;
			__WORD	RESV1811:1;
			__WORD	RESV1810:1;
			__WORD	RESV189:1;
			__WORD	RESV188:1;
			__WORD	WRRD:1;
			__WORD	MASK:1;
			__WORD	ARB:1;
			__WORD	CONTROL:1;
			__WORD	CIP:1;
			__WORD	TXREQ:1;
			__WORD	DATAA:1;
			__WORD	DATAB:1;
#else
			__WORD	DATAB:1;
			__WORD	DATAA:1;
			__WORD	TXREQ:1;
			__WORD	CIP:1;
			__WORD	CONTROL:1;
			__WORD	ARB:1;
			__WORD	MASK:1;
			__WORD	WRRD:1;
			__WORD	RESV188:1;
			__WORD	RESV189:1;
			__WORD	RESV1810:1;
			__WORD	RESV1811:1;
			__WORD	RESV1812:1;
			__WORD	RESV1813:1;
			__WORD	RESV1814:1;
			__WORD	RESV1815:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV1815:1;
			__WORD	RESV1814:1;
			__WORD	RESV1813:1;
			__WORD	RESV1812:1;
			__WORD	RESV1811:1;
			__WORD	RESV1810:1;
			__WORD	RESV189:1;
			__WORD	RESV188:1;
			__WORD	WRRD:1;
			__WORD	MASK:1;
			__WORD	ARB:1;
			__WORD	CONTROL:1;
			__WORD	CIP:1;
			__WORD	TXREQ:1;
			__WORD	DATAA:1;
			__WORD	DATAB:1;
#else
			__WORD	DATAB:1;
			__WORD	DATAA:1;
			__WORD	TXREQ:1;
			__WORD	CIP:1;
			__WORD	CONTROL:1;
			__WORD	ARB:1;
			__WORD	MASK:1;
			__WORD	WRRD:1;
			__WORD	RESV188:1;
			__WORD	RESV189:1;
			__WORD	RESV1810:1;
			__WORD	RESV1811:1;
			__WORD	RESV1812:1;
			__WORD	RESV1813:1;
			__WORD	RESV1814:1;
			__WORD	RESV1815:1;
#endif
		} bitc;
	} IF1CMSK0;
	union {
		__LWORD	lword;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MXTD:1;
			__LWORD	MDIR:1;
			__LWORD	RESV201:1;
			__LWORD	MSK:29;
#else
			__LWORD	MSK:29;
			__LWORD	RESV201:1;
			__LWORD	MDIR:1;
			__LWORD	MXTD:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MXTD:1;
			__LWORD	MDIR:1;
			__LWORD	RESV2029:1;
			__LWORD	MSK28:1;
			__LWORD	MSK27:1;
			__LWORD	MSK26:1;
			__LWORD	MSK25:1;
			__LWORD	MSK24:1;
			__LWORD	MSK23:1;
			__LWORD	MSK22:1;
			__LWORD	MSK21:1;
			__LWORD	MSK20:1;
			__LWORD	MSK19:1;
			__LWORD	MSK18:1;
			__LWORD	MSK17:1;
			__LWORD	MSK16:1;
			__LWORD	MSK15:1;
			__LWORD	MSK14:1;
			__LWORD	MSK13:1;
			__LWORD	MSK12:1;
			__LWORD	MSK11:1;
			__LWORD	MSK10:1;
			__LWORD	MSK9:1;
			__LWORD	MSK8:1;
			__LWORD	MSK7:1;
			__LWORD	MSK6:1;
			__LWORD	MSK5:1;
			__LWORD	MSK4:1;
			__LWORD	MSK3:1;
			__LWORD	MSK2:1;
			__LWORD	MSK1:1;
			__LWORD	MSK0:1;
#else
			__LWORD	MSK0:1;
			__LWORD	MSK1:1;
			__LWORD	MSK2:1;
			__LWORD	MSK3:1;
			__LWORD	MSK4:1;
			__LWORD	MSK5:1;
			__LWORD	MSK6:1;
			__LWORD	MSK7:1;
			__LWORD	MSK8:1;
			__LWORD	MSK9:1;
			__LWORD	MSK10:1;
			__LWORD	MSK11:1;
			__LWORD	MSK12:1;
			__LWORD	MSK13:1;
			__LWORD	MSK14:1;
			__LWORD	MSK15:1;
			__LWORD	MSK16:1;
			__LWORD	MSK17:1;
			__LWORD	MSK18:1;
			__LWORD	MSK19:1;
			__LWORD	MSK20:1;
			__LWORD	MSK21:1;
			__LWORD	MSK22:1;
			__LWORD	MSK23:1;
			__LWORD	MSK24:1;
			__LWORD	MSK25:1;
			__LWORD	MSK26:1;
			__LWORD	MSK27:1;
			__LWORD	MSK28:1;
			__LWORD	RESV2029:1;
			__LWORD	MDIR:1;
			__LWORD	MXTD:1;
#endif
		} bitc;
	} IF1MSK0;
	union {
		__LWORD	lword;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MSGVAL:1;
			__LWORD	XTD:1;
			__LWORD	DIR:1;
			__LWORD	ID:29;
#else
			__LWORD	ID:29;
			__LWORD	DIR:1;
			__LWORD	XTD:1;
			__LWORD	MSGVAL:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MSGVAL:1;
			__LWORD	XTD:1;
			__LWORD	DIR:1;
			__LWORD	ID28:1;
			__LWORD	ID27:1;
			__LWORD	ID26:1;
			__LWORD	ID25:1;
			__LWORD	ID24:1;
			__LWORD	ID23:1;
			__LWORD	ID22:1;
			__LWORD	ID21:1;
			__LWORD	ID20:1;
			__LWORD	ID19:1;
			__LWORD	ID18:1;
			__LWORD	ID17:1;
			__LWORD	ID16:1;
			__LWORD	ID15:1;
			__LWORD	ID14:1;
			__LWORD	ID13:1;
			__LWORD	ID12:1;
			__LWORD	ID11:1;
			__LWORD	ID10:1;
			__LWORD	ID9:1;
			__LWORD	ID8:1;
			__LWORD	ID7:1;
			__LWORD	ID6:1;
			__LWORD	ID5:1;
			__LWORD	ID4:1;
			__LWORD	ID3:1;
			__LWORD	ID2:1;
			__LWORD	ID1:1;
			__LWORD	ID0:1;
#else
			__LWORD	ID0:1;
			__LWORD	ID1:1;
			__LWORD	ID2:1;
			__LWORD	ID3:1;
			__LWORD	ID4:1;
			__LWORD	ID5:1;
			__LWORD	ID6:1;
			__LWORD	ID7:1;
			__LWORD	ID8:1;
			__LWORD	ID9:1;
			__LWORD	ID10:1;
			__LWORD	ID11:1;
			__LWORD	ID12:1;
			__LWORD	ID13:1;
			__LWORD	ID14:1;
			__LWORD	ID15:1;
			__LWORD	ID16:1;
			__LWORD	ID17:1;
			__LWORD	ID18:1;
			__LWORD	ID19:1;
			__LWORD	ID20:1;
			__LWORD	ID21:1;
			__LWORD	ID22:1;
			__LWORD	ID23:1;
			__LWORD	ID24:1;
			__LWORD	ID25:1;
			__LWORD	ID26:1;
			__LWORD	ID27:1;
			__LWORD	ID28:1;
			__LWORD	DIR:1;
			__LWORD	XTD:1;
			__LWORD	MSGVAL:1;
#endif
		} bitc;
	} IF1ARB0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	NEWDAT:1;
			__WORD	MSGLST:1;
			__WORD	INTPND:1;
			__WORD	UMASK:1;
			__WORD	TXIE:1;
			__WORD	RXIE:1;
			__WORD	RMTEN:1;
			__WORD	TXRQST:1;
			__WORD	EOB:1;
			__WORD	RESV283:1;
			__WORD	RESV282:1;
			__WORD	RESV281:1;
			__WORD	DLC:4;
#else
			__WORD	DLC:4;
			__WORD	RESV281:1;
			__WORD	RESV282:1;
			__WORD	RESV283:1;
			__WORD	EOB:1;
			__WORD	TXRQST:1;
			__WORD	RMTEN:1;
			__WORD	RXIE:1;
			__WORD	TXIE:1;
			__WORD	UMASK:1;
			__WORD	INTPND:1;
			__WORD	MSGLST:1;
			__WORD	NEWDAT:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	NEWDAT:1;
			__WORD	MSGLST:1;
			__WORD	INTPND:1;
			__WORD	UMASK:1;
			__WORD	TXIE:1;
			__WORD	RXIE:1;
			__WORD	RMTEN:1;
			__WORD	TXRQST:1;
			__WORD	EOB:1;
			__WORD	RESV286:1;
			__WORD	RESV285:1;
			__WORD	RESV284:1;
			__WORD	DLC3:1;
			__WORD	DLC2:1;
			__WORD	DLC1:1;
			__WORD	DLC0:1;
#else
			__WORD	DLC0:1;
			__WORD	DLC1:1;
			__WORD	DLC2:1;
			__WORD	DLC3:1;
			__WORD	RESV284:1;
			__WORD	RESV285:1;
			__WORD	RESV286:1;
			__WORD	EOB:1;
			__WORD	TXRQST:1;
			__WORD	RMTEN:1;
			__WORD	RXIE:1;
			__WORD	TXIE:1;
			__WORD	UMASK:1;
			__WORD	INTPND:1;
			__WORD	MSGLST:1;
			__WORD	NEWDAT:1;
#endif
		} bitc;
	} IF1MCTR0;
	__WORD	IF1DTA10;
	__WORD	IF1DTA20;
	__WORD	IF1DTB10;
	__WORD	IF1DTB20;
	__BYTE	RESV2[CONSTANT_26];
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BUSY:1;
			__WORD	RESV647:1;
			__WORD	RESV646:1;
			__WORD	RESV645:1;
			__WORD	RESV644:1;
			__WORD	RESV643:1;
			__WORD	RESV642:1;
			__WORD	RESV641:1;
			__WORD	MSGN:8;
#else
			__WORD	MSGN:8;
			__WORD	RESV641:1;
			__WORD	RESV642:1;
			__WORD	RESV643:1;
			__WORD	RESV644:1;
			__WORD	RESV645:1;
			__WORD	RESV646:1;
			__WORD	RESV647:1;
			__WORD	BUSY:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	BUSY:1;
			__WORD	RESV6414:1;
			__WORD	RESV6413:1;
			__WORD	RESV6412:1;
			__WORD	RESV6411:1;
			__WORD	RESV6410:1;
			__WORD	RESV649:1;
			__WORD	RESV648:1;
			__WORD	MSGN7:1;
			__WORD	MSGN6:1;
			__WORD	MSGN5:1;
			__WORD	MSGN4:1;
			__WORD	MSGN3:1;
			__WORD	MSGN2:1;
			__WORD	MSGN1:1;
			__WORD	MSGN0:1;
#else
			__WORD	MSGN0:1;
			__WORD	MSGN1:1;
			__WORD	MSGN2:1;
			__WORD	MSGN3:1;
			__WORD	MSGN4:1;
			__WORD	MSGN5:1;
			__WORD	MSGN6:1;
			__WORD	MSGN7:1;
			__WORD	RESV648:1;
			__WORD	RESV649:1;
			__WORD	RESV6410:1;
			__WORD	RESV6411:1;
			__WORD	RESV6412:1;
			__WORD	RESV6413:1;
			__WORD	RESV6414:1;
			__WORD	BUSY:1;
#endif
		} bitc;
	} IF2CREQ0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6615:1;
			__WORD	RESV6614:1;
			__WORD	RESV6613:1;
			__WORD	RESV6612:1;
			__WORD	RESV6611:1;
			__WORD	RESV6610:1;
			__WORD	RESV669:1;
			__WORD	RESV668:1;
			__WORD	WRRD:1;
			__WORD	MASK:1;
			__WORD	ARB:1;
			__WORD	CONTROL:1;
			__WORD	CIP:1;
			__WORD	TXREQ:1;
			__WORD	DATAA:1;
			__WORD	DATAB:1;
#else
			__WORD	DATAB:1;
			__WORD	DATAA:1;
			__WORD	TXREQ:1;
			__WORD	CIP:1;
			__WORD	CONTROL:1;
			__WORD	ARB:1;
			__WORD	MASK:1;
			__WORD	WRRD:1;
			__WORD	RESV668:1;
			__WORD	RESV669:1;
			__WORD	RESV6610:1;
			__WORD	RESV6611:1;
			__WORD	RESV6612:1;
			__WORD	RESV6613:1;
			__WORD	RESV6614:1;
			__WORD	RESV6615:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6615:1;
			__WORD	RESV6614:1;
			__WORD	RESV6613:1;
			__WORD	RESV6612:1;
			__WORD	RESV6611:1;
			__WORD	RESV6610:1;
			__WORD	RESV669:1;
			__WORD	RESV668:1;
			__WORD	WRRD:1;
			__WORD	MASK:1;
			__WORD	ARB:1;
			__WORD	CONTROL:1;
			__WORD	CIP:1;
			__WORD	TXREQ:1;
			__WORD	DATAA:1;
			__WORD	DATAB:1;
#else
			__WORD	DATAB:1;
			__WORD	DATAA:1;
			__WORD	TXREQ:1;
			__WORD	CIP:1;
			__WORD	CONTROL:1;
			__WORD	ARB:1;
			__WORD	MASK:1;
			__WORD	WRRD:1;
			__WORD	RESV668:1;
			__WORD	RESV669:1;
			__WORD	RESV6610:1;
			__WORD	RESV6611:1;
			__WORD	RESV6612:1;
			__WORD	RESV6613:1;
			__WORD	RESV6614:1;
			__WORD	RESV6615:1;
#endif
		} bitc;
	} IF2CMSK0;
	union {
		__LWORD	lword;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MXTD:1;
			__LWORD	MDIR:1;
			__LWORD	RESV681:1;
			__LWORD	MSK:29;
#else
			__LWORD	MSK:29;
			__LWORD	RESV681:1;
			__LWORD	MDIR:1;
			__LWORD	MXTD:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MXTD:1;
			__LWORD	MDIR:1;
			__LWORD	RESV6829:1;
			__LWORD	MSK28:1;
			__LWORD	MSK27:1;
			__LWORD	MSK26:1;
			__LWORD	MSK25:1;
			__LWORD	MSK24:1;
			__LWORD	MSK23:1;
			__LWORD	MSK22:1;
			__LWORD	MSK21:1;
			__LWORD	MSK20:1;
			__LWORD	MSK19:1;
			__LWORD	MSK18:1;
			__LWORD	MSK17:1;
			__LWORD	MSK16:1;
			__LWORD	MSK15:1;
			__LWORD	MSK14:1;
			__LWORD	MSK13:1;
			__LWORD	MSK12:1;
			__LWORD	MSK11:1;
			__LWORD	MSK10:1;
			__LWORD	MSK9:1;
			__LWORD	MSK8:1;
			__LWORD	MSK7:1;
			__LWORD	MSK6:1;
			__LWORD	MSK5:1;
			__LWORD	MSK4:1;
			__LWORD	MSK3:1;
			__LWORD	MSK2:1;
			__LWORD	MSK1:1;
			__LWORD	MSK0:1;
#else
			__LWORD	MSK0:1;
			__LWORD	MSK1:1;
			__LWORD	MSK2:1;
			__LWORD	MSK3:1;
			__LWORD	MSK4:1;
			__LWORD	MSK5:1;
			__LWORD	MSK6:1;
			__LWORD	MSK7:1;
			__LWORD	MSK8:1;
			__LWORD	MSK9:1;
			__LWORD	MSK10:1;
			__LWORD	MSK11:1;
			__LWORD	MSK12:1;
			__LWORD	MSK13:1;
			__LWORD	MSK14:1;
			__LWORD	MSK15:1;
			__LWORD	MSK16:1;
			__LWORD	MSK17:1;
			__LWORD	MSK18:1;
			__LWORD	MSK19:1;
			__LWORD	MSK20:1;
			__LWORD	MSK21:1;
			__LWORD	MSK22:1;
			__LWORD	MSK23:1;
			__LWORD	MSK24:1;
			__LWORD	MSK25:1;
			__LWORD	MSK26:1;
			__LWORD	MSK27:1;
			__LWORD	MSK28:1;
			__LWORD	RESV6829:1;
			__LWORD	MDIR:1;
			__LWORD	MXTD:1;
#endif
		} bitc;
	} IF2MSK0;
	union {
		__LWORD	lword;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MSGVAL:1;
			__LWORD	XTD:1;
			__LWORD	DIR:1;
			__LWORD	ID:29;
#else
			__LWORD	ID:29;
			__LWORD	DIR:1;
			__LWORD	XTD:1;
			__LWORD	MSGVAL:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__LWORD	MSGVAL:1;
			__LWORD	XTD:1;
			__LWORD	DIR:1;
			__LWORD	ID28:1;
			__LWORD	ID27:1;
			__LWORD	ID26:1;
			__LWORD	ID25:1;
			__LWORD	ID24:1;
			__LWORD	ID23:1;
			__LWORD	ID22:1;
			__LWORD	ID21:1;
			__LWORD	ID20:1;
			__LWORD	ID19:1;
			__LWORD	ID18:1;
			__LWORD	ID17:1;
			__LWORD	ID16:1;
			__LWORD	ID15:1;
			__LWORD	ID14:1;
			__LWORD	ID13:1;
			__LWORD	ID12:1;
			__LWORD	ID11:1;
			__LWORD	ID10:1;
			__LWORD	ID9:1;
			__LWORD	ID8:1;
			__LWORD	ID7:1;
			__LWORD	ID6:1;
			__LWORD	ID5:1;
			__LWORD	ID4:1;
			__LWORD	ID3:1;
			__LWORD	ID2:1;
			__LWORD	ID1:1;
			__LWORD	ID0:1;
#else
			__LWORD	ID0:1;
			__LWORD	ID1:1;
			__LWORD	ID2:1;
			__LWORD	ID3:1;
			__LWORD	ID4:1;
			__LWORD	ID5:1;
			__LWORD	ID6:1;
			__LWORD	ID7:1;
			__LWORD	ID8:1;
			__LWORD	ID9:1;
			__LWORD	ID10:1;
			__LWORD	ID11:1;
			__LWORD	ID12:1;
			__LWORD	ID13:1;
			__LWORD	ID14:1;
			__LWORD	ID15:1;
			__LWORD	ID16:1;
			__LWORD	ID17:1;
			__LWORD	ID18:1;
			__LWORD	ID19:1;
			__LWORD	ID20:1;
			__LWORD	ID21:1;
			__LWORD	ID22:1;
			__LWORD	ID23:1;
			__LWORD	ID24:1;
			__LWORD	ID25:1;
			__LWORD	ID26:1;
			__LWORD	ID27:1;
			__LWORD	ID28:1;
			__LWORD	DIR:1;
			__LWORD	XTD:1;
			__LWORD	MSGVAL:1;
#endif
		} bitc;
	} IF2ARB0;
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	NEWDAT:1;
			__WORD	MSGLST:1;
			__WORD	INTPND:1;
			__WORD	UMASK:1;
			__WORD	TXIE:1;
			__WORD	RXIE:1;
			__WORD	RMTEN:1;
			__WORD	TXRQST:1;
			__WORD	EOB:1;
			__WORD	RESV763:1;
			__WORD	RESV762:1;
			__WORD	RESV761:1;
			__WORD	DLC:4;
#else
			__WORD	DLC:4;
			__WORD	RESV761:1;
			__WORD	RESV762:1;
			__WORD	RESV763:1;
			__WORD	EOB:1;
			__WORD	TXRQST:1;
			__WORD	RMTEN:1;
			__WORD	RXIE:1;
			__WORD	TXIE:1;
			__WORD	UMASK:1;
			__WORD	INTPND:1;
			__WORD	MSGLST:1;
			__WORD	NEWDAT:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	NEWDAT:1;
			__WORD	MSGLST:1;
			__WORD	INTPND:1;
			__WORD	UMASK:1;
			__WORD	TXIE:1;
			__WORD	RXIE:1;
			__WORD	RMTEN:1;
			__WORD	TXRQST:1;
			__WORD	EOB:1;
			__WORD	RESV766:1;
			__WORD	RESV765:1;
			__WORD	RESV764:1;
			__WORD	DLC3:1;
			__WORD	DLC2:1;
			__WORD	DLC1:1;
			__WORD	DLC0:1;
#else
			__WORD	DLC0:1;
			__WORD	DLC1:1;
			__WORD	DLC2:1;
			__WORD	DLC3:1;
			__WORD	RESV764:1;
			__WORD	RESV765:1;
			__WORD	RESV766:1;
			__WORD	EOB:1;
			__WORD	TXRQST:1;
			__WORD	RMTEN:1;
			__WORD	RXIE:1;
			__WORD	TXIE:1;
			__WORD	UMASK:1;
			__WORD	INTPND:1;
			__WORD	MSGLST:1;
			__WORD	NEWDAT:1;
#endif
		} bitc;
	} IF2MCTR0;
	__WORD	IF2DTA10;
	__WORD	IF2DTA20;
	__WORD	IF2DTB10;
	__WORD	IF2DTB20;
	__BYTE	RESV3[CONSTANT_42];
	const __LWORD	TREQR0;
	__BYTE	RESV4[CONSTANT_12];
	const __LWORD	NEWDT0;
	__BYTE	RESV5[CONSTANT_12];
	const __LWORD	INTPND0;
	__BYTE	RESV6[CONSTANT_12];
	const __LWORD	MSGVAL0;
	__BYTE	RESV7[CONSTANT_12];
	__BYTE	RESV8[CONSTANT_14];
	union {
		__BYTE	byte;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV2067:1;
			__BYTE	RESV2066:1;
			__BYTE	RESV2065:1;
			__BYTE	RESV2064:1;
			__BYTE	RESV2063:1;
			__BYTE	RESV2062:1;
			__BYTE	RESV2061:1;
			__BYTE	OE:1;
#else
			__BYTE	OE:1;
			__BYTE	RESV2061:1;
			__BYTE	RESV2062:1;
			__BYTE	RESV2063:1;
			__BYTE	RESV2064:1;
			__BYTE	RESV2065:1;
			__BYTE	RESV2066:1;
			__BYTE	RESV2067:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV2067:1;
			__BYTE	RESV2066:1;
			__BYTE	RESV2065:1;
			__BYTE	RESV2064:1;
			__BYTE	RESV2063:1;
			__BYTE	RESV2062:1;
			__BYTE	RESV2061:1;
			__BYTE	OE:1;
#else
			__BYTE	OE:1;
			__BYTE	RESV2061:1;
			__BYTE	RESV2062:1;
			__BYTE	RESV2063:1;
			__BYTE	RESV2064:1;
			__BYTE	RESV2065:1;
			__BYTE	RESV2066:1;
			__BYTE	RESV2067:1;
#endif
		} bitc;
	} COER0;
} IO_CAN0;

#define	CAN0_CTRLR0			(IO_CAN0.CTRLR0.word)
#define	CAN0_CTRLR0_INIT    	(IO_CAN0.CTRLR0.bit.INIT)
#define	CAN0_CTRLR0_IE    	(IO_CAN0.CTRLR0.bit.IE)
#define	CAN0_CTRLR0_SIE    	(IO_CAN0.CTRLR0.bit.SIE)
#define	CAN0_CTRLR0_EIE    	(IO_CAN0.CTRLR0.bit.EIE)
#define	CAN0_CTRLR0_DAR    	(IO_CAN0.CTRLR0.bit.DAR)
#define	CAN0_CTRLR0_CCE    	(IO_CAN0.CTRLR0.bit.CCE)
#define	CAN0_CTRLR0_TEST    	(IO_CAN0.CTRLR0.bit.TEST)
#define	CAN0_STATR0			(IO_CAN0.STATR0.word)
#define	CAN0_STATR0_LEC    	(IO_CAN0.STATR0.bit.LEC)
#define	CAN0_STATR0_LEC0    	(IO_CAN0.STATR0.bitc.LEC0)
#define	CAN0_STATR0_LEC1    	(IO_CAN0.STATR0.bitc.LEC1)
#define	CAN0_STATR0_LEC2    	(IO_CAN0.STATR0.bitc.LEC2)
#define	CAN0_STATR0_TXOK    	(IO_CAN0.STATR0.bit.TXOK)
#define	CAN0_STATR0_RXOK    	(IO_CAN0.STATR0.bit.RXOK)
#define	CAN0_STATR0_EPASS    	(IO_CAN0.STATR0.bit.EPASS)
#define	CAN0_STATR0_EWARN    	(IO_CAN0.STATR0.bit.EWARN)
#define	CAN0_STATR0_BOFF    	(IO_CAN0.STATR0.bit.BOFF)
#define	CAN0_ERRCNT0			(IO_CAN0.ERRCNT0.word)
#define	CAN0_ERRCNT0_TEC    	(IO_CAN0.ERRCNT0.bit.TEC)
#define	CAN0_ERRCNT0_TEC0    	(IO_CAN0.ERRCNT0.bitc.TEC0)
#define	CAN0_ERRCNT0_TEC1    	(IO_CAN0.ERRCNT0.bitc.TEC1)
#define	CAN0_ERRCNT0_TEC2    	(IO_CAN0.ERRCNT0.bitc.TEC2)
#define	CAN0_ERRCNT0_TEC3    	(IO_CAN0.ERRCNT0.bitc.TEC3)
#define	CAN0_ERRCNT0_TEC4    	(IO_CAN0.ERRCNT0.bitc.TEC4)
#define	CAN0_ERRCNT0_TEC5    	(IO_CAN0.ERRCNT0.bitc.TEC5)
#define	CAN0_ERRCNT0_TEC6    	(IO_CAN0.ERRCNT0.bitc.TEC6)
#define	CAN0_ERRCNT0_TEC7    	(IO_CAN0.ERRCNT0.bitc.TEC7)
#define	CAN0_ERRCNT0_REC    	(IO_CAN0.ERRCNT0.bit.REC)
#define	CAN0_ERRCNT0_REC0    	(IO_CAN0.ERRCNT0.bitc.REC0)
#define	CAN0_ERRCNT0_REC1    	(IO_CAN0.ERRCNT0.bitc.REC1)
#define	CAN0_ERRCNT0_REC2    	(IO_CAN0.ERRCNT0.bitc.REC2)
#define	CAN0_ERRCNT0_REC3    	(IO_CAN0.ERRCNT0.bitc.REC3)
#define	CAN0_ERRCNT0_REC4    	(IO_CAN0.ERRCNT0.bitc.REC4)
#define	CAN0_ERRCNT0_REC5    	(IO_CAN0.ERRCNT0.bitc.REC5)
#define	CAN0_ERRCNT0_REC6    	(IO_CAN0.ERRCNT0.bitc.REC6)
#define	CAN0_ERRCNT0_RP    	(IO_CAN0.ERRCNT0.bit.RP)
#define	CAN0_BTR0			(IO_CAN0.BTR0.word)
#define	CAN0_BTR0_BRP    	(IO_CAN0.BTR0.bit.BRP)
#define	CAN0_BTR0_BRP0    	(IO_CAN0.BTR0.bitc.BRP0)
#define	CAN0_BTR0_BRP1    	(IO_CAN0.BTR0.bitc.BRP1)
#define	CAN0_BTR0_BRP2    	(IO_CAN0.BTR0.bitc.BRP2)
#define	CAN0_BTR0_BRP3    	(IO_CAN0.BTR0.bitc.BRP3)
#define	CAN0_BTR0_BRP4    	(IO_CAN0.BTR0.bitc.BRP4)
#define	CAN0_BTR0_BRP5    	(IO_CAN0.BTR0.bitc.BRP5)
#define	CAN0_BTR0_SJW    	(IO_CAN0.BTR0.bit.SJW)
#define	CAN0_BTR0_SJW0    	(IO_CAN0.BTR0.bitc.SJW0)
#define	CAN0_BTR0_SJW1    	(IO_CAN0.BTR0.bitc.SJW1)
#define	CAN0_BTR0_TSEG1    	(IO_CAN0.BTR0.bit.TSEG1)
#define	CAN0_BTR0_TSEG10    	(IO_CAN0.BTR0.bitc.TSEG10)
#define	CAN0_BTR0_TSEG11    	(IO_CAN0.BTR0.bitc.TSEG11)
#define	CAN0_BTR0_TSEG12    	(IO_CAN0.BTR0.bitc.TSEG12)
#define	CAN0_BTR0_TSEG13    	(IO_CAN0.BTR0.bitc.TSEG13)
#define	CAN0_BTR0_TSEG2    	(IO_CAN0.BTR0.bit.TSEG2)
#define	CAN0_BTR0_TSEG20    	(IO_CAN0.BTR0.bitc.TSEG20)
#define	CAN0_BTR0_TSEG21    	(IO_CAN0.BTR0.bitc.TSEG21)
#define	CAN0_BTR0_TSEG22    	(IO_CAN0.BTR0.bitc.TSEG22)
#define	CAN0_INTR0	(IO_CAN0.INTR0)
#define	CAN0_TESTR0			(IO_CAN0.TESTR0.word)
#define	CAN0_TESTR0_BASIC    	(IO_CAN0.TESTR0.bit.BASIC)
#define	CAN0_TESTR0_SILENT    	(IO_CAN0.TESTR0.bit.SILENT)
#define	CAN0_TESTR0_LBACK    	(IO_CAN0.TESTR0.bit.LBACK)
#define	CAN0_TESTR0_TX    	(IO_CAN0.TESTR0.bit.TX)
#define	CAN0_TESTR0_TX0    	(IO_CAN0.TESTR0.bitc.TX0)
#define	CAN0_TESTR0_TX1    	(IO_CAN0.TESTR0.bitc.TX1)
#define	CAN0_TESTR0_RX    	(IO_CAN0.TESTR0.bit.RX)
#define	CAN0_BRPER0			(IO_CAN0.BRPER0.word)
#define	CAN0_BRPER0_BRPE    	(IO_CAN0.BRPER0.bit.BRPE)
#define	CAN0_BRPER0_BRPE0    	(IO_CAN0.BRPER0.bitc.BRPE0)
#define	CAN0_BRPER0_BRPE1    	(IO_CAN0.BRPER0.bitc.BRPE1)
#define	CAN0_BRPER0_BRPE2    	(IO_CAN0.BRPER0.bitc.BRPE2)
#define	CAN0_BRPER0_BRPE3    	(IO_CAN0.BRPER0.bitc.BRPE3)
#define	CAN0_IF1CREQ0			(IO_CAN0.IF1CREQ0.word)
#define	CAN0_IF1CREQ0_MSGN    	(IO_CAN0.IF1CREQ0.bit.MSGN)
#define	CAN0_IF1CREQ0_MSGN0    	(IO_CAN0.IF1CREQ0.bitc.MSGN0)
#define	CAN0_IF1CREQ0_MSGN1    	(IO_CAN0.IF1CREQ0.bitc.MSGN1)
#define	CAN0_IF1CREQ0_MSGN2    	(IO_CAN0.IF1CREQ0.bitc.MSGN2)
#define	CAN0_IF1CREQ0_MSGN3    	(IO_CAN0.IF1CREQ0.bitc.MSGN3)
#define	CAN0_IF1CREQ0_MSGN4    	(IO_CAN0.IF1CREQ0.bitc.MSGN4)
#define	CAN0_IF1CREQ0_MSGN5    	(IO_CAN0.IF1CREQ0.bitc.MSGN5)
#define	CAN0_IF1CREQ0_MSGN6    	(IO_CAN0.IF1CREQ0.bitc.MSGN6)
#define	CAN0_IF1CREQ0_MSGN7    	(IO_CAN0.IF1CREQ0.bitc.MSGN7)
#define	CAN0_IF1CREQ0_BUSY    	(IO_CAN0.IF1CREQ0.bit.BUSY)
#define	CAN0_IF1CMSK0			(IO_CAN0.IF1CMSK0.word)
#define	CAN0_IF1CMSK0_DATAB    	(IO_CAN0.IF1CMSK0.bit.DATAB)
#define	CAN0_IF1CMSK0_DATAA    	(IO_CAN0.IF1CMSK0.bit.DATAA)
#define	CAN0_IF1CMSK0_TXREQ    	(IO_CAN0.IF1CMSK0.bit.TXREQ)
#define	CAN0_IF1CMSK0_CIP    	(IO_CAN0.IF1CMSK0.bit.CIP)
#define	CAN0_IF1CMSK0_CONTROL    	(IO_CAN0.IF1CMSK0.bit.CONTROL)
#define	CAN0_IF1CMSK0_ARB    	(IO_CAN0.IF1CMSK0.bit.ARB)
#define	CAN0_IF1CMSK0_MASK    	(IO_CAN0.IF1CMSK0.bit.MASK)
#define	CAN0_IF1CMSK0_WRRD    	(IO_CAN0.IF1CMSK0.bit.WRRD)
#define	CAN0_IF1MSK0			(IO_CAN0.IF1MSK0.lword)
#define	CAN0_IF1MSK0_MSK    	(IO_CAN0.IF1MSK0.bit.MSK)
#define	CAN0_IF1MSK0_MSK0    	(IO_CAN0.IF1MSK0.bitc.MSK0)
#define	CAN0_IF1MSK0_MSK1    	(IO_CAN0.IF1MSK0.bitc.MSK1)
#define	CAN0_IF1MSK0_MSK2    	(IO_CAN0.IF1MSK0.bitc.MSK2)
#define	CAN0_IF1MSK0_MSK3    	(IO_CAN0.IF1MSK0.bitc.MSK3)
#define	CAN0_IF1MSK0_MSK4    	(IO_CAN0.IF1MSK0.bitc.MSK4)
#define	CAN0_IF1MSK0_MSK5    	(IO_CAN0.IF1MSK0.bitc.MSK5)
#define	CAN0_IF1MSK0_MSK6    	(IO_CAN0.IF1MSK0.bitc.MSK6)
#define	CAN0_IF1MSK0_MSK7    	(IO_CAN0.IF1MSK0.bitc.MSK7)
#define	CAN0_IF1MSK0_MSK8    	(IO_CAN0.IF1MSK0.bitc.MSK8)
#define	CAN0_IF1MSK0_MSK9    	(IO_CAN0.IF1MSK0.bitc.MSK9)
#define	CAN0_IF1MSK0_MSK10    	(IO_CAN0.IF1MSK0.bitc.MSK10)
#define	CAN0_IF1MSK0_MSK11    	(IO_CAN0.IF1MSK0.bitc.MSK11)
#define	CAN0_IF1MSK0_MSK12    	(IO_CAN0.IF1MSK0.bitc.MSK12)
#define	CAN0_IF1MSK0_MSK13    	(IO_CAN0.IF1MSK0.bitc.MSK13)
#define	CAN0_IF1MSK0_MSK14    	(IO_CAN0.IF1MSK0.bitc.MSK14)
#define	CAN0_IF1MSK0_MSK15    	(IO_CAN0.IF1MSK0.bitc.MSK15)
#define	CAN0_IF1MSK0_MSK16    	(IO_CAN0.IF1MSK0.bitc.MSK16)
#define	CAN0_IF1MSK0_MSK17    	(IO_CAN0.IF1MSK0.bitc.MSK17)
#define	CAN0_IF1MSK0_MSK18    	(IO_CAN0.IF1MSK0.bitc.MSK18)
#define	CAN0_IF1MSK0_MSK19    	(IO_CAN0.IF1MSK0.bitc.MSK19)
#define	CAN0_IF1MSK0_MSK20    	(IO_CAN0.IF1MSK0.bitc.MSK20)
#define	CAN0_IF1MSK0_MSK21    	(IO_CAN0.IF1MSK0.bitc.MSK21)
#define	CAN0_IF1MSK0_MSK22    	(IO_CAN0.IF1MSK0.bitc.MSK22)
#define	CAN0_IF1MSK0_MSK23    	(IO_CAN0.IF1MSK0.bitc.MSK23)
#define	CAN0_IF1MSK0_MSK24    	(IO_CAN0.IF1MSK0.bitc.MSK24)
#define	CAN0_IF1MSK0_MSK25    	(IO_CAN0.IF1MSK0.bitc.MSK25)
#define	CAN0_IF1MSK0_MSK26    	(IO_CAN0.IF1MSK0.bitc.MSK26)
#define	CAN0_IF1MSK0_MSK27    	(IO_CAN0.IF1MSK0.bitc.MSK27)
#define	CAN0_IF1MSK0_MSK28    	(IO_CAN0.IF1MSK0.bitc.MSK28)
#define	CAN0_IF1MSK0_MDIR    	(IO_CAN0.IF1MSK0.bit.MDIR)
#define	CAN0_IF1MSK0_MXTD    	(IO_CAN0.IF1MSK0.bit.MXTD)
#define	CAN0_IF1ARB0			(IO_CAN0.IF1ARB0.lword)
#define	CAN0_IF1ARB0_ID    	(IO_CAN0.IF1ARB0.bit.ID)
#define	CAN0_IF1ARB0_ID0    	(IO_CAN0.IF1ARB0.bitc.ID0)
#define	CAN0_IF1ARB0_ID1    	(IO_CAN0.IF1ARB0.bitc.ID1)
#define	CAN0_IF1ARB0_ID2    	(IO_CAN0.IF1ARB0.bitc.ID2)
#define	CAN0_IF1ARB0_ID3    	(IO_CAN0.IF1ARB0.bitc.ID3)
#define	CAN0_IF1ARB0_ID4    	(IO_CAN0.IF1ARB0.bitc.ID4)
#define	CAN0_IF1ARB0_ID5    	(IO_CAN0.IF1ARB0.bitc.ID5)
#define	CAN0_IF1ARB0_ID6    	(IO_CAN0.IF1ARB0.bitc.ID6)
#define	CAN0_IF1ARB0_ID7    	(IO_CAN0.IF1ARB0.bitc.ID7)
#define	CAN0_IF1ARB0_ID8    	(IO_CAN0.IF1ARB0.bitc.ID8)
#define	CAN0_IF1ARB0_ID9    	(IO_CAN0.IF1ARB0.bitc.ID9)
#define	CAN0_IF1ARB0_ID10    	(IO_CAN0.IF1ARB0.bitc.ID10)
#define	CAN0_IF1ARB0_ID11    	(IO_CAN0.IF1ARB0.bitc.ID11)
#define	CAN0_IF1ARB0_ID12    	(IO_CAN0.IF1ARB0.bitc.ID12)
#define	CAN0_IF1ARB0_ID13    	(IO_CAN0.IF1ARB0.bitc.ID13)
#define	CAN0_IF1ARB0_ID14    	(IO_CAN0.IF1ARB0.bitc.ID14)
#define	CAN0_IF1ARB0_ID15    	(IO_CAN0.IF1ARB0.bitc.ID15)
#define	CAN0_IF1ARB0_ID16    	(IO_CAN0.IF1ARB0.bitc.ID16)
#define	CAN0_IF1ARB0_ID17    	(IO_CAN0.IF1ARB0.bitc.ID17)
#define	CAN0_IF1ARB0_ID18    	(IO_CAN0.IF1ARB0.bitc.ID18)
#define	CAN0_IF1ARB0_ID19    	(IO_CAN0.IF1ARB0.bitc.ID19)
#define	CAN0_IF1ARB0_ID20    	(IO_CAN0.IF1ARB0.bitc.ID20)
#define	CAN0_IF1ARB0_ID21    	(IO_CAN0.IF1ARB0.bitc.ID21)
#define	CAN0_IF1ARB0_ID22    	(IO_CAN0.IF1ARB0.bitc.ID22)
#define	CAN0_IF1ARB0_ID23    	(IO_CAN0.IF1ARB0.bitc.ID23)
#define	CAN0_IF1ARB0_ID24    	(IO_CAN0.IF1ARB0.bitc.ID24)
#define	CAN0_IF1ARB0_ID25    	(IO_CAN0.IF1ARB0.bitc.ID25)
#define	CAN0_IF1ARB0_ID26    	(IO_CAN0.IF1ARB0.bitc.ID26)
#define	CAN0_IF1ARB0_ID27    	(IO_CAN0.IF1ARB0.bitc.ID27)
#define	CAN0_IF1ARB0_ID28    	(IO_CAN0.IF1ARB0.bitc.ID28)
#define	CAN0_IF1ARB0_DIR    	(IO_CAN0.IF1ARB0.bit.DIR)
#define	CAN0_IF1ARB0_XTD    	(IO_CAN0.IF1ARB0.bit.XTD)
#define	CAN0_IF1ARB0_MSGVAL    	(IO_CAN0.IF1ARB0.bit.MSGVAL)
#define	CAN0_IF1MCTR0			(IO_CAN0.IF1MCTR0.word)
#define	CAN0_IF1MCTR0_DLC    	(IO_CAN0.IF1MCTR0.bit.DLC)
#define	CAN0_IF1MCTR0_DLC0    	(IO_CAN0.IF1MCTR0.bitc.DLC0)
#define	CAN0_IF1MCTR0_DLC1    	(IO_CAN0.IF1MCTR0.bitc.DLC1)
#define	CAN0_IF1MCTR0_DLC2    	(IO_CAN0.IF1MCTR0.bitc.DLC2)
#define	CAN0_IF1MCTR0_DLC3    	(IO_CAN0.IF1MCTR0.bitc.DLC3)
#define	CAN0_IF1MCTR0_EOB    	(IO_CAN0.IF1MCTR0.bit.EOB)
#define	CAN0_IF1MCTR0_TXRQST    	(IO_CAN0.IF1MCTR0.bit.TXRQST)
#define	CAN0_IF1MCTR0_RMTEN    	(IO_CAN0.IF1MCTR0.bit.RMTEN)
#define	CAN0_IF1MCTR0_RXIE    	(IO_CAN0.IF1MCTR0.bit.RXIE)
#define	CAN0_IF1MCTR0_TXIE    	(IO_CAN0.IF1MCTR0.bit.TXIE)
#define	CAN0_IF1MCTR0_UMASK    	(IO_CAN0.IF1MCTR0.bit.UMASK)
#define	CAN0_IF1MCTR0_INTPND    	(IO_CAN0.IF1MCTR0.bit.INTPND)
#define	CAN0_IF1MCTR0_MSGLST    	(IO_CAN0.IF1MCTR0.bit.MSGLST)
#define	CAN0_IF1MCTR0_NEWDAT    	(IO_CAN0.IF1MCTR0.bit.NEWDAT)
#define	CAN0_IF1DTA10	(IO_CAN0.IF1DTA10)
#define	CAN0_IF1DTA20	(IO_CAN0.IF1DTA20)
#define	CAN0_IF1DTB10	(IO_CAN0.IF1DTB10)
#define	CAN0_IF1DTB20	(IO_CAN0.IF1DTB20)
#define	CAN0_RESV2_0  	(IO_CAN0.RESV2[CONSTANT_0])
#define	CAN0_RESV2_1  	(IO_CAN0.RESV2[CONSTANT_1])
#define	CAN0_RESV2_2  	(IO_CAN0.RESV2[CONSTANT_2])
#define	CAN0_RESV2_3  	(IO_CAN0.RESV2[CONSTANT_3])
#define	CAN0_RESV2_4  	(IO_CAN0.RESV2[CONSTANT_4])
#define	CAN0_RESV2_5  	(IO_CAN0.RESV2[CONSTANT_5])
#define	CAN0_RESV2_6  	(IO_CAN0.RESV2[CONSTANT_6])
#define	CAN0_RESV2_7  	(IO_CAN0.RESV2[CONSTANT_7])
#define	CAN0_RESV2_8  	(IO_CAN0.RESV2[CONSTANT_8])
#define	CAN0_RESV2_9  	(IO_CAN0.RESV2[CONSTANT_9])
#define	CAN0_RESV2_10  	(IO_CAN0.RESV2[CONSTANT_10])
#define	CAN0_RESV2_11  	(IO_CAN0.RESV2[CONSTANT_11])
#define	CAN0_RESV2_12  	(IO_CAN0.RESV2[CONSTANT_12])
#define	CAN0_RESV2_13  	(IO_CAN0.RESV2[CONSTANT_13])
#define	CAN0_RESV2_14  	(IO_CAN0.RESV2[CONSTANT_14])
#define	CAN0_RESV2_15  	(IO_CAN0.RESV2[CONSTANT_15])
#define	CAN0_RESV2_16  	(IO_CAN0.RESV2[CONSTANT_16])
#define	CAN0_RESV2_17  	(IO_CAN0.RESV2[CONSTANT_17])
#define	CAN0_RESV2_18  	(IO_CAN0.RESV2[CONSTANT_18])
#define	CAN0_RESV2_19  	(IO_CAN0.RESV2[CONSTANT_19])
#define	CAN0_RESV2_20  	(IO_CAN0.RESV2[CONSTANT_20])
#define	CAN0_RESV2_21  	(IO_CAN0.RESV2[CONSTANT_21])
#define	CAN0_RESV2_22  	(IO_CAN0.RESV2[CONSTANT_22])
#define	CAN0_RESV2_23  	(IO_CAN0.RESV2[CONSTANT_23])
#define	CAN0_RESV2_24  	(IO_CAN0.RESV2[CONSTANT_24])
#define	CAN0_RESV2_25  	(IO_CAN0.RESV2[CONSTANT_25])
#define	CAN0_IF2CREQ0			(IO_CAN0.IF2CREQ0.word)
#define	CAN0_IF2CREQ0_MSGN    	(IO_CAN0.IF2CREQ0.bit.MSGN)
#define	CAN0_IF2CREQ0_MSGN0    	(IO_CAN0.IF2CREQ0.bitc.MSGN0)
#define	CAN0_IF2CREQ0_MSGN1    	(IO_CAN0.IF2CREQ0.bitc.MSGN1)
#define	CAN0_IF2CREQ0_MSGN2    	(IO_CAN0.IF2CREQ0.bitc.MSGN2)
#define	CAN0_IF2CREQ0_MSGN3    	(IO_CAN0.IF2CREQ0.bitc.MSGN3)
#define	CAN0_IF2CREQ0_MSGN4    	(IO_CAN0.IF2CREQ0.bitc.MSGN4)
#define	CAN0_IF2CREQ0_MSGN5    	(IO_CAN0.IF2CREQ0.bitc.MSGN5)
#define	CAN0_IF2CREQ0_MSGN6    	(IO_CAN0.IF2CREQ0.bitc.MSGN6)
#define	CAN0_IF2CREQ0_MSGN7    	(IO_CAN0.IF2CREQ0.bitc.MSGN7)
#define	CAN0_IF2CREQ0_BUSY    	(IO_CAN0.IF2CREQ0.bit.BUSY)
#define	CAN0_IF2CMSK0			(IO_CAN0.IF2CMSK0.word)
#define	CAN0_IF2CMSK0_DATAB    	(IO_CAN0.IF2CMSK0.bit.DATAB)
#define	CAN0_IF2CMSK0_DATAA    	(IO_CAN0.IF2CMSK0.bit.DATAA)
#define	CAN0_IF2CMSK0_TXREQ    	(IO_CAN0.IF2CMSK0.bit.TXREQ)
#define	CAN0_IF2CMSK0_CIP    	(IO_CAN0.IF2CMSK0.bit.CIP)
#define	CAN0_IF2CMSK0_CONTROL    	(IO_CAN0.IF2CMSK0.bit.CONTROL)
#define	CAN0_IF2CMSK0_ARB    	(IO_CAN0.IF2CMSK0.bit.ARB)
#define	CAN0_IF2CMSK0_MASK    	(IO_CAN0.IF2CMSK0.bit.MASK)
#define	CAN0_IF2CMSK0_WRRD    	(IO_CAN0.IF2CMSK0.bit.WRRD)
#define	CAN0_IF2MSK0			(IO_CAN0.IF2MSK0.lword)
#define	CAN0_IF2MSK0_MSK    	(IO_CAN0.IF2MSK0.bit.MSK)
#define	CAN0_IF2MSK0_MSK0    	(IO_CAN0.IF2MSK0.bitc.MSK0)
#define	CAN0_IF2MSK0_MSK1    	(IO_CAN0.IF2MSK0.bitc.MSK1)
#define	CAN0_IF2MSK0_MSK2    	(IO_CAN0.IF2MSK0.bitc.MSK2)
#define	CAN0_IF2MSK0_MSK3    	(IO_CAN0.IF2MSK0.bitc.MSK3)
#define	CAN0_IF2MSK0_MSK4    	(IO_CAN0.IF2MSK0.bitc.MSK4)
#define	CAN0_IF2MSK0_MSK5    	(IO_CAN0.IF2MSK0.bitc.MSK5)
#define	CAN0_IF2MSK0_MSK6    	(IO_CAN0.IF2MSK0.bitc.MSK6)
#define	CAN0_IF2MSK0_MSK7    	(IO_CAN0.IF2MSK0.bitc.MSK7)
#define	CAN0_IF2MSK0_MSK8    	(IO_CAN0.IF2MSK0.bitc.MSK8)
#define	CAN0_IF2MSK0_MSK9    	(IO_CAN0.IF2MSK0.bitc.MSK9)
#define	CAN0_IF2MSK0_MSK10    	(IO_CAN0.IF2MSK0.bitc.MSK10)
#define	CAN0_IF2MSK0_MSK11    	(IO_CAN0.IF2MSK0.bitc.MSK11)
#define	CAN0_IF2MSK0_MSK12    	(IO_CAN0.IF2MSK0.bitc.MSK12)
#define	CAN0_IF2MSK0_MSK13    	(IO_CAN0.IF2MSK0.bitc.MSK13)
#define	CAN0_IF2MSK0_MSK14    	(IO_CAN0.IF2MSK0.bitc.MSK14)
#define	CAN0_IF2MSK0_MSK15    	(IO_CAN0.IF2MSK0.bitc.MSK15)
#define	CAN0_IF2MSK0_MSK16    	(IO_CAN0.IF2MSK0.bitc.MSK16)
#define	CAN0_IF2MSK0_MSK17    	(IO_CAN0.IF2MSK0.bitc.MSK17)
#define	CAN0_IF2MSK0_MSK18    	(IO_CAN0.IF2MSK0.bitc.MSK18)
#define	CAN0_IF2MSK0_MSK19    	(IO_CAN0.IF2MSK0.bitc.MSK19)
#define	CAN0_IF2MSK0_MSK20    	(IO_CAN0.IF2MSK0.bitc.MSK20)
#define	CAN0_IF2MSK0_MSK21    	(IO_CAN0.IF2MSK0.bitc.MSK21)
#define	CAN0_IF2MSK0_MSK22    	(IO_CAN0.IF2MSK0.bitc.MSK22)
#define	CAN0_IF2MSK0_MSK23    	(IO_CAN0.IF2MSK0.bitc.MSK23)
#define	CAN0_IF2MSK0_MSK24    	(IO_CAN0.IF2MSK0.bitc.MSK24)
#define	CAN0_IF2MSK0_MSK25    	(IO_CAN0.IF2MSK0.bitc.MSK25)
#define	CAN0_IF2MSK0_MSK26    	(IO_CAN0.IF2MSK0.bitc.MSK26)
#define	CAN0_IF2MSK0_MSK27    	(IO_CAN0.IF2MSK0.bitc.MSK27)
#define	CAN0_IF2MSK0_MSK28    	(IO_CAN0.IF2MSK0.bitc.MSK28)
#define	CAN0_IF2MSK0_MDIR    	(IO_CAN0.IF2MSK0.bit.MDIR)
#define	CAN0_IF2MSK0_MXTD    	(IO_CAN0.IF2MSK0.bit.MXTD)
#define	CAN0_IF2ARB0			(IO_CAN0.IF2ARB0.lword)
#define	CAN0_IF2ARB0_ID    	(IO_CAN0.IF2ARB0.bit.ID)
#define	CAN0_IF2ARB0_ID0    	(IO_CAN0.IF2ARB0.bitc.ID0)
#define	CAN0_IF2ARB0_ID1    	(IO_CAN0.IF2ARB0.bitc.ID1)
#define	CAN0_IF2ARB0_ID2    	(IO_CAN0.IF2ARB0.bitc.ID2)
#define	CAN0_IF2ARB0_ID3    	(IO_CAN0.IF2ARB0.bitc.ID3)
#define	CAN0_IF2ARB0_ID4    	(IO_CAN0.IF2ARB0.bitc.ID4)
#define	CAN0_IF2ARB0_ID5    	(IO_CAN0.IF2ARB0.bitc.ID5)
#define	CAN0_IF2ARB0_ID6    	(IO_CAN0.IF2ARB0.bitc.ID6)
#define	CAN0_IF2ARB0_ID7    	(IO_CAN0.IF2ARB0.bitc.ID7)
#define	CAN0_IF2ARB0_ID8    	(IO_CAN0.IF2ARB0.bitc.ID8)
#define	CAN0_IF2ARB0_ID9    	(IO_CAN0.IF2ARB0.bitc.ID9)
#define	CAN0_IF2ARB0_ID10    	(IO_CAN0.IF2ARB0.bitc.ID10)
#define	CAN0_IF2ARB0_ID11    	(IO_CAN0.IF2ARB0.bitc.ID11)
#define	CAN0_IF2ARB0_ID12    	(IO_CAN0.IF2ARB0.bitc.ID12)
#define	CAN0_IF2ARB0_ID13    	(IO_CAN0.IF2ARB0.bitc.ID13)
#define	CAN0_IF2ARB0_ID14    	(IO_CAN0.IF2ARB0.bitc.ID14)
#define	CAN0_IF2ARB0_ID15    	(IO_CAN0.IF2ARB0.bitc.ID15)
#define	CAN0_IF2ARB0_ID16    	(IO_CAN0.IF2ARB0.bitc.ID16)
#define	CAN0_IF2ARB0_ID17    	(IO_CAN0.IF2ARB0.bitc.ID17)
#define	CAN0_IF2ARB0_ID18    	(IO_CAN0.IF2ARB0.bitc.ID18)
#define	CAN0_IF2ARB0_ID19    	(IO_CAN0.IF2ARB0.bitc.ID19)
#define	CAN0_IF2ARB0_ID20    	(IO_CAN0.IF2ARB0.bitc.ID20)
#define	CAN0_IF2ARB0_ID21    	(IO_CAN0.IF2ARB0.bitc.ID21)
#define	CAN0_IF2ARB0_ID22    	(IO_CAN0.IF2ARB0.bitc.ID22)
#define	CAN0_IF2ARB0_ID23    	(IO_CAN0.IF2ARB0.bitc.ID23)
#define	CAN0_IF2ARB0_ID24    	(IO_CAN0.IF2ARB0.bitc.ID24)
#define	CAN0_IF2ARB0_ID25    	(IO_CAN0.IF2ARB0.bitc.ID25)
#define	CAN0_IF2ARB0_ID26    	(IO_CAN0.IF2ARB0.bitc.ID26)
#define	CAN0_IF2ARB0_ID27    	(IO_CAN0.IF2ARB0.bitc.ID27)
#define	CAN0_IF2ARB0_ID28    	(IO_CAN0.IF2ARB0.bitc.ID28)
#define	CAN0_IF2ARB0_DIR    	(IO_CAN0.IF2ARB0.bit.DIR)
#define	CAN0_IF2ARB0_XTD    	(IO_CAN0.IF2ARB0.bit.XTD)
#define	CAN0_IF2ARB0_MSGVAL    	(IO_CAN0.IF2ARB0.bit.MSGVAL)
#define	CAN0_IF2MCTR0			(IO_CAN0.IF2MCTR0.word)
#define	CAN0_IF2MCTR0_DLC    	(IO_CAN0.IF2MCTR0.bit.DLC)
#define	CAN0_IF2MCTR0_DLC0    	(IO_CAN0.IF2MCTR0.bitc.DLC0)
#define	CAN0_IF2MCTR0_DLC1    	(IO_CAN0.IF2MCTR0.bitc.DLC1)
#define	CAN0_IF2MCTR0_DLC2    	(IO_CAN0.IF2MCTR0.bitc.DLC2)
#define	CAN0_IF2MCTR0_DLC3    	(IO_CAN0.IF2MCTR0.bitc.DLC3)
#define	CAN0_IF2MCTR0_EOB    	(IO_CAN0.IF2MCTR0.bit.EOB)
#define	CAN0_IF2MCTR0_TXRQST    	(IO_CAN0.IF2MCTR0.bit.TXRQST)
#define	CAN0_IF2MCTR0_RMTEN    	(IO_CAN0.IF2MCTR0.bit.RMTEN)
#define	CAN0_IF2MCTR0_RXIE    	(IO_CAN0.IF2MCTR0.bit.RXIE)
#define	CAN0_IF2MCTR0_TXIE    	(IO_CAN0.IF2MCTR0.bit.TXIE)
#define	CAN0_IF2MCTR0_UMASK    	(IO_CAN0.IF2MCTR0.bit.UMASK)
#define	CAN0_IF2MCTR0_INTPND    	(IO_CAN0.IF2MCTR0.bit.INTPND)
#define	CAN0_IF2MCTR0_MSGLST    	(IO_CAN0.IF2MCTR0.bit.MSGLST)
#define	CAN0_IF2MCTR0_NEWDAT    	(IO_CAN0.IF2MCTR0.bit.NEWDAT)
#define	CAN0_IF2DTA10	(IO_CAN0.IF2DTA10)
#define	CAN0_IF2DTA20	(IO_CAN0.IF2DTA20)
#define	CAN0_IF2DTB10	(IO_CAN0.IF2DTB10)
#define	CAN0_IF2DTB20	(IO_CAN0.IF2DTB20)
#define	CAN0_RESV3_0  	(IO_CAN0.RESV3[CONSTANT_0])
#define	CAN0_RESV3_1  	(IO_CAN0.RESV3[CONSTANT_1])
#define	CAN0_RESV3_2  	(IO_CAN0.RESV3[CONSTANT_2])
#define	CAN0_RESV3_3  	(IO_CAN0.RESV3[CONSTANT_3])
#define	CAN0_RESV3_4  	(IO_CAN0.RESV3[CONSTANT_4])
#define	CAN0_RESV3_5  	(IO_CAN0.RESV3[CONSTANT_5])
#define	CAN0_RESV3_6  	(IO_CAN0.RESV3[CONSTANT_6])
#define	CAN0_RESV3_7  	(IO_CAN0.RESV3[CONSTANT_7])
#define	CAN0_RESV3_8  	(IO_CAN0.RESV3[CONSTANT_8])
#define	CAN0_RESV3_9  	(IO_CAN0.RESV3[CONSTANT_9])
#define	CAN0_RESV3_10  	(IO_CAN0.RESV3[CONSTANT_10])
#define	CAN0_RESV3_11  	(IO_CAN0.RESV3[CONSTANT_11])
#define	CAN0_RESV3_12  	(IO_CAN0.RESV3[CONSTANT_12])
#define	CAN0_RESV3_13  	(IO_CAN0.RESV3[CONSTANT_13])
#define	CAN0_RESV3_14  	(IO_CAN0.RESV3[CONSTANT_14])
#define	CAN0_RESV3_15  	(IO_CAN0.RESV3[CONSTANT_15])
#define	CAN0_RESV3_16  	(IO_CAN0.RESV3[CONSTANT_16])
#define	CAN0_RESV3_17  	(IO_CAN0.RESV3[CONSTANT_17])
#define	CAN0_RESV3_18  	(IO_CAN0.RESV3[CONSTANT_18])
#define	CAN0_RESV3_19  	(IO_CAN0.RESV3[CONSTANT_19])
#define	CAN0_RESV3_20  	(IO_CAN0.RESV3[CONSTANT_20])
#define	CAN0_RESV3_21  	(IO_CAN0.RESV3[CONSTANT_21])
#define	CAN0_RESV3_22  	(IO_CAN0.RESV3[CONSTANT_22])
#define	CAN0_RESV3_23  	(IO_CAN0.RESV3[CONSTANT_23])
#define	CAN0_RESV3_24  	(IO_CAN0.RESV3[CONSTANT_24])
#define	CAN0_RESV3_25  	(IO_CAN0.RESV3[CONSTANT_25])
#define	CAN0_RESV3_26  	(IO_CAN0.RESV3[CONSTANT_26])
#define	CAN0_RESV3_27  	(IO_CAN0.RESV3[CONSTANT_27])
#define	CAN0_RESV3_28  	(IO_CAN0.RESV3[CONSTANT_28])
#define	CAN0_RESV3_29  	(IO_CAN0.RESV3[CONSTANT_29])
#define	CAN0_RESV3_30  	(IO_CAN0.RESV3[CONSTANT_30])
#define	CAN0_RESV3_31  	(IO_CAN0.RESV3[CONSTANT_31])
#define	CAN0_RESV3_32  	(IO_CAN0.RESV3[CONSTANT_32])
#define	CAN0_RESV3_33  	(IO_CAN0.RESV3[CONSTANT_33])
#define	CAN0_RESV3_34  	(IO_CAN0.RESV3[CONSTANT_34])
#define	CAN0_RESV3_35  	(IO_CAN0.RESV3[CONSTANT_35])
#define	CAN0_RESV3_36  	(IO_CAN0.RESV3[CONSTANT_36])
#define	CAN0_RESV3_37  	(IO_CAN0.RESV3[CONSTANT_37])
#define	CAN0_RESV3_38  	(IO_CAN0.RESV3[CONSTANT_38])
#define	CAN0_RESV3_39  	(IO_CAN0.RESV3[CONSTANT_39])
#define	CAN0_RESV3_40  	(IO_CAN0.RESV3[CONSTANT_40])
#define	CAN0_RESV3_41  	(IO_CAN0.RESV3[CONSTANT_41])
#define	CAN0_TREQR0	(IO_CAN0.TREQR0)
#define	CAN0_RESV4_0  	(IO_CAN0.RESV4[CONSTANT_0])
#define	CAN0_RESV4_1  	(IO_CAN0.RESV4[CONSTANT_1])
#define	CAN0_RESV4_2  	(IO_CAN0.RESV4[CONSTANT_2])
#define	CAN0_RESV4_3  	(IO_CAN0.RESV4[CONSTANT_3])
#define	CAN0_RESV4_4  	(IO_CAN0.RESV4[CONSTANT_4])
#define	CAN0_RESV4_5  	(IO_CAN0.RESV4[CONSTANT_5])
#define	CAN0_RESV4_6  	(IO_CAN0.RESV4[CONSTANT_6])
#define	CAN0_RESV4_7  	(IO_CAN0.RESV4[CONSTANT_7])
#define	CAN0_RESV4_8  	(IO_CAN0.RESV4[CONSTANT_8])
#define	CAN0_RESV4_9  	(IO_CAN0.RESV4[CONSTANT_9])
#define	CAN0_RESV4_10  	(IO_CAN0.RESV4[CONSTANT_10])
#define	CAN0_RESV4_11  	(IO_CAN0.RESV4[CONSTANT_11])
#define	CAN0_NEWDT0	(IO_CAN0.NEWDT0)
#define	CAN0_RESV5_0  	(IO_CAN0.RESV5[CONSTANT_0])
#define	CAN0_RESV5_1  	(IO_CAN0.RESV5[CONSTANT_1])
#define	CAN0_RESV5_2  	(IO_CAN0.RESV5[CONSTANT_2])
#define	CAN0_RESV5_3  	(IO_CAN0.RESV5[CONSTANT_3])
#define	CAN0_RESV5_4  	(IO_CAN0.RESV5[CONSTANT_4])
#define	CAN0_RESV5_5  	(IO_CAN0.RESV5[CONSTANT_5])
#define	CAN0_RESV5_6  	(IO_CAN0.RESV5[CONSTANT_6])
#define	CAN0_RESV5_7  	(IO_CAN0.RESV5[CONSTANT_7])
#define	CAN0_RESV5_8  	(IO_CAN0.RESV5[CONSTANT_8])
#define	CAN0_RESV5_9  	(IO_CAN0.RESV5[CONSTANT_9])
#define	CAN0_RESV5_10  	(IO_CAN0.RESV5[CONSTANT_10])
#define	CAN0_RESV5_11  	(IO_CAN0.RESV5[CONSTANT_11])
#define	CAN0_INTPND0	(IO_CAN0.INTPND0)
#define	CAN0_RESV6_0  	(IO_CAN0.RESV6[CONSTANT_0])
#define	CAN0_RESV6_1  	(IO_CAN0.RESV6[CONSTANT_1])
#define	CAN0_RESV6_2  	(IO_CAN0.RESV6[CONSTANT_2])
#define	CAN0_RESV6_3  	(IO_CAN0.RESV6[CONSTANT_3])
#define	CAN0_RESV6_4  	(IO_CAN0.RESV6[CONSTANT_4])
#define	CAN0_RESV6_5  	(IO_CAN0.RESV6[CONSTANT_5])
#define	CAN0_RESV6_6  	(IO_CAN0.RESV6[CONSTANT_6])
#define	CAN0_RESV6_7  	(IO_CAN0.RESV6[CONSTANT_7])
#define	CAN0_RESV6_8  	(IO_CAN0.RESV6[CONSTANT_8])
#define	CAN0_RESV6_9  	(IO_CAN0.RESV6[CONSTANT_9])
#define	CAN0_RESV6_10  	(IO_CAN0.RESV6[CONSTANT_10])
#define	CAN0_RESV6_11  	(IO_CAN0.RESV6[CONSTANT_11])
#define	CAN0_MSGVAL0	(IO_CAN0.MSGVAL0)
#define	CAN0_RESV7_0  	(IO_CAN0.RESV7[CONSTANT_0])
#define	CAN0_RESV7_1  	(IO_CAN0.RESV7[CONSTANT_1])
#define	CAN0_RESV7_2  	(IO_CAN0.RESV7[CONSTANT_2])
#define	CAN0_RESV7_3  	(IO_CAN0.RESV7[CONSTANT_3])
#define	CAN0_RESV7_4  	(IO_CAN0.RESV7[CONSTANT_4])
#define	CAN0_RESV7_5  	(IO_CAN0.RESV7[CONSTANT_5])
#define	CAN0_RESV7_6  	(IO_CAN0.RESV7[CONSTANT_6])
#define	CAN0_RESV7_7  	(IO_CAN0.RESV7[CONSTANT_7])
#define	CAN0_RESV7_8  	(IO_CAN0.RESV7[CONSTANT_8])
#define	CAN0_RESV7_9  	(IO_CAN0.RESV7[CONSTANT_9])
#define	CAN0_RESV7_10  	(IO_CAN0.RESV7[CONSTANT_10])
#define	CAN0_RESV7_11  	(IO_CAN0.RESV7[CONSTANT_11])
#define	CAN0_RESV8_0  	(IO_CAN0.RESV8[CONSTANT_0])
#define	CAN0_RESV8_1  	(IO_CAN0.RESV8[CONSTANT_1])
#define	CAN0_RESV8_2  	(IO_CAN0.RESV8[CONSTANT_2])
#define	CAN0_RESV8_3  	(IO_CAN0.RESV8[CONSTANT_3])
#define	CAN0_RESV8_4  	(IO_CAN0.RESV8[CONSTANT_4])
#define	CAN0_RESV8_5  	(IO_CAN0.RESV8[CONSTANT_5])
#define	CAN0_RESV8_6  	(IO_CAN0.RESV8[CONSTANT_6])
#define	CAN0_RESV8_7  	(IO_CAN0.RESV8[CONSTANT_7])
#define	CAN0_RESV8_8  	(IO_CAN0.RESV8[CONSTANT_8])
#define	CAN0_RESV8_9  	(IO_CAN0.RESV8[CONSTANT_9])
#define	CAN0_RESV8_10  	(IO_CAN0.RESV8[CONSTANT_10])
#define	CAN0_RESV8_11  	(IO_CAN0.RESV8[CONSTANT_11])
#define	CAN0_RESV8_12  	(IO_CAN0.RESV8[CONSTANT_12])
#define	CAN0_RESV8_13  	(IO_CAN0.RESV8[CONSTANT_13])
#define	CAN0_COER0			(IO_CAN0.COER0.byte)
#define	CAN0_COER0_OE    	(IO_CAN0.COER0.bit.OE)

#endif

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_SG0,   locate=0x7D0
#pragma segment FAR_DATA=IO_SG0, locate=0x7D0
#endif

__IO_EXTENDED	struct {
	union {
		__WORD	word;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV014:1;
			__WORD	RESV013:1;
			__WORD	RESV012:1;
			__WORD	RESV011:1;
			__WORD	RESV010:1;
			__WORD	FSEL:1;
			__WORD	BUSY:1;
			__WORD	DEC:1;
			__WORD	S:2;
			__WORD	TONE:1;
			__WORD	OE2:1;
			__WORD	OE1:1;
			__WORD	INTE:1;
			__WORD	INT:1;
			__WORD	ST:1;
#else
			__WORD	ST:1;
			__WORD	INT:1;
			__WORD	INTE:1;
			__WORD	OE1:1;
			__WORD	OE2:1;
			__WORD	TONE:1;
			__WORD	S:2;
			__WORD	DEC:1;
			__WORD	BUSY:1;
			__WORD	FSEL:1;
			__WORD	RESV010:1;
			__WORD	RESV011:1;
			__WORD	RESV012:1;
			__WORD	RESV013:1;
			__WORD	RESV014:1;
#endif
		} bit;
		struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV015:1;
			__WORD	RESV014:1;
			__WORD	RESV013:1;
			__WORD	RESV012:1;
			__WORD	RESV011:1;
			__WORD	FSEL:1;
			__WORD	BUSY:1;
			__WORD	DEC:1;
			__WORD	S1:1;
			__WORD	S0:1;
			__WORD	TONE:1;
			__WORD	OE2:1;
			__WORD	OE1:1;
			__WORD	INTE:1;
			__WORD	INT:1;
			__WORD	ST:1;
#else
			__WORD	ST:1;
			__WORD	INT:1;
			__WORD	INTE:1;
			__WORD	OE1:1;
			__WORD	OE2:1;
			__WORD	TONE:1;
			__WORD	S0:1;
			__WORD	S1:1;
			__WORD	DEC:1;
			__WORD	BUSY:1;
			__WORD	FSEL:1;
			__WORD	RESV011:1;
			__WORD	RESV012:1;
			__WORD	RESV013:1;
			__WORD	RESV014:1;
			__WORD	RESV015:1;
#endif
		} bitc;
	} SGCR0;
	__BYTE	SGFR0;
	__BYTE	SGAR0;
	__BYTE	SGDR0;
	__BYTE	SGTR0;
} IO_SG0;

#define	SG0_SGCR0			(IO_SG0.SGCR0.word)
#define	SG0_SGCR0_ST    	(IO_SG0.SGCR0.bit.ST)
#define	SG0_SGCR0_INT    	(IO_SG0.SGCR0.bit.INT)
#define	SG0_SGCR0_INTE    	(IO_SG0.SGCR0.bit.INTE)
#define	SG0_SGCR0_OE1    	(IO_SG0.SGCR0.bit.OE1)
#define	SG0_SGCR0_OE2    	(IO_SG0.SGCR0.bit.OE2)
#define	SG0_SGCR0_TONE    	(IO_SG0.SGCR0.bit.TONE)
#define	SG0_SGCR0_S    	(IO_SG0.SGCR0.bit.S)
#define	SG0_SGCR0_S0    	(IO_SG0.SGCR0.bitc.S0)
#define	SG0_SGCR0_S1    	(IO_SG0.SGCR0.bitc.S1)
#define	SG0_SGCR0_DEC    	(IO_SG0.SGCR0.bit.DEC)
#define	SG0_SGCR0_BUSY    	(IO_SG0.SGCR0.bit.BUSY)
#define	SG0_SGCR0_FSEL    	(IO_SG0.SGCR0.bit.FSEL)
#define	SG0_SGFR0	(IO_SG0.SGFR0)
#define	SG0_SGAR0	(IO_SG0.SGAR0)
#define	SG0_SGDR0	(IO_SG0.SGDR0)
#define	SG0_SGTR0	(IO_SG0.SGTR0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IOABK0,   locate=0xA00
#pragma segment FAR_DATA=IO_IOABK0, locate=0xA00
#endif

__IO_EXTENDED	__BYTE	IO_IOABK0;
#define	_ioabk0		(IO_IOABK0)
#define	IOABK0	(_ioabk0)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_IOABK1,   locate=0xA01
#pragma segment FAR_DATA=IO_IOABK1, locate=0xA01
#endif

__IO_EXTENDED	__BYTE	IO_IOABK1;
#define	_ioabk1		(IO_IOABK1)
#define	IOABK1	(_ioabk1)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPCN10,   locate=0xA80
#pragma segment FAR_DATA=IO_EPCN10, locate=0xA80
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EPCN10STR;

__IO_EXTENDED	  EPCN10STR	IO_EPCN10;
#define	_epcn10		(IO_EPCN10)
#define	EPCN10		(IO_EPCN10.word)
#define	EPCN10_STRD  	(IO_EPCN10.bit.STRD)
#define	EPCN10_TPCL  	(IO_EPCN10.bit.TPCL)
#define	EPCN10_TPCH  	(IO_EPCN10.bit.TPCH)
#define	EPCN10_RAMPL  	(IO_EPCN10.bit.RAMPL)
#define	EPCN10_RAMPH  	(IO_EPCN10.bit.RAMPH)
#define	EPCN10_RIDL  	(IO_EPCN10.bit.RIDL)
#define	EPCN10_RIDH  	(IO_EPCN10.bit.RIDH)
#define	EPCN10_OSEL2  	(IO_EPCN10.bit.OSEL2)
#define	EPCN10_FRML  	(IO_EPCN10.bit.FRML)
#define	EPCN10_FRMH  	(IO_EPCN10.bit.FRMH)
#define	EPCN10_OE2  	(IO_EPCN10.bit.OE2)
#define	EPCN10_IRS2  	(IO_EPCN10.bit.IRS2)
#define	EPCN10_TRIG  	(IO_EPCN10.bit.TRIG)
#define	EPCN10_WFGG  	(IO_EPCN10.bit.WFGG)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPCN11,   locate=0xA82
#pragma segment FAR_DATA=IO_EPCN11, locate=0xA82
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EPCN11STR;

__IO_EXTENDED	  EPCN11STR	IO_EPCN11;
#define	_epcn11		(IO_EPCN11)
#define	EPCN11		(IO_EPCN11.word)
#define	EPCN11_STRD  	(IO_EPCN11.bit.STRD)
#define	EPCN11_TPCL  	(IO_EPCN11.bit.TPCL)
#define	EPCN11_TPCH  	(IO_EPCN11.bit.TPCH)
#define	EPCN11_RAMPL  	(IO_EPCN11.bit.RAMPL)
#define	EPCN11_RAMPH  	(IO_EPCN11.bit.RAMPH)
#define	EPCN11_RIDL  	(IO_EPCN11.bit.RIDL)
#define	EPCN11_RIDH  	(IO_EPCN11.bit.RIDH)
#define	EPCN11_OSEL2  	(IO_EPCN11.bit.OSEL2)
#define	EPCN11_FRML  	(IO_EPCN11.bit.FRML)
#define	EPCN11_FRMH  	(IO_EPCN11.bit.FRMH)
#define	EPCN11_OE2  	(IO_EPCN11.bit.OE2)
#define	EPCN11_IRS2  	(IO_EPCN11.bit.IRS2)
#define	EPCN11_TRIG  	(IO_EPCN11.bit.TRIG)
#define	EPCN11_WFGG  	(IO_EPCN11.bit.WFGG)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPCN12,   locate=0xA84
#pragma segment FAR_DATA=IO_EPCN12, locate=0xA84
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EPCN12STR;

__IO_EXTENDED	  EPCN12STR	IO_EPCN12;
#define	_epcn12		(IO_EPCN12)
#define	EPCN12		(IO_EPCN12.word)
#define	EPCN12_STRD  	(IO_EPCN12.bit.STRD)
#define	EPCN12_TPCL  	(IO_EPCN12.bit.TPCL)
#define	EPCN12_TPCH  	(IO_EPCN12.bit.TPCH)
#define	EPCN12_RAMPL  	(IO_EPCN12.bit.RAMPL)
#define	EPCN12_RAMPH  	(IO_EPCN12.bit.RAMPH)
#define	EPCN12_RIDL  	(IO_EPCN12.bit.RIDL)
#define	EPCN12_RIDH  	(IO_EPCN12.bit.RIDH)
#define	EPCN12_OSEL2  	(IO_EPCN12.bit.OSEL2)
#define	EPCN12_FRML  	(IO_EPCN12.bit.FRML)
#define	EPCN12_FRMH  	(IO_EPCN12.bit.FRMH)
#define	EPCN12_OE2  	(IO_EPCN12.bit.OE2)
#define	EPCN12_IRS2  	(IO_EPCN12.bit.IRS2)
#define	EPCN12_TRIG  	(IO_EPCN12.bit.TRIG)
#define	EPCN12_WFGG  	(IO_EPCN12.bit.WFGG)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_EPCN13,   locate=0xA86
#pragma segment FAR_DATA=IO_EPCN13, locate=0xA86
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	WFGG:1;
			__WORD	TRIG:1;
			__WORD	IRS2:1;
			__WORD	OE2:1;
			__WORD	FRMH:1;
			__WORD	FRML:1;
			__WORD	OSEL2:1;
			__WORD	RIDH:1;
			__WORD	RIDL:1;
			__WORD	RAMPH:1;
			__WORD	RAMPL:1;
			__WORD	TPCH:1;
			__WORD	TPCL:1;
			__WORD	STRD:1;
#else
			__WORD	STRD:1;
			__WORD	TPCL:1;
			__WORD	TPCH:1;
			__WORD	RAMPL:1;
			__WORD	RAMPH:1;
			__WORD	RIDL:1;
			__WORD	RIDH:1;
			__WORD	OSEL2:1;
			__WORD	FRML:1;
			__WORD	FRMH:1;
			__WORD	OE2:1;
			__WORD	IRS2:1;
			__WORD	TRIG:1;
			__WORD	WFGG:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EPCN13STR;

__IO_EXTENDED	  EPCN13STR	IO_EPCN13;
#define	_epcn13		(IO_EPCN13)
#define	EPCN13		(IO_EPCN13.word)
#define	EPCN13_STRD  	(IO_EPCN13.bit.STRD)
#define	EPCN13_TPCL  	(IO_EPCN13.bit.TPCL)
#define	EPCN13_TPCH  	(IO_EPCN13.bit.TPCH)
#define	EPCN13_RAMPL  	(IO_EPCN13.bit.RAMPL)
#define	EPCN13_RAMPH  	(IO_EPCN13.bit.RAMPH)
#define	EPCN13_RIDL  	(IO_EPCN13.bit.RIDL)
#define	EPCN13_RIDH  	(IO_EPCN13.bit.RIDH)
#define	EPCN13_OSEL2  	(IO_EPCN13.bit.OSEL2)
#define	EPCN13_FRML  	(IO_EPCN13.bit.FRML)
#define	EPCN13_FRMH  	(IO_EPCN13.bit.FRMH)
#define	EPCN13_OE2  	(IO_EPCN13.bit.OE2)
#define	EPCN13_IRS2  	(IO_EPCN13.bit.IRS2)
#define	EPCN13_TRIG  	(IO_EPCN13.bit.TRIG)
#define	EPCN13_WFGG  	(IO_EPCN13.bit.WFGG)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADRCOOF10,   locate=0xB55
#pragma segment FAR_DATA=IO_ADRCOOF10, locate=0xB55
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOOF13:1;
			__BYTE	RCOOF12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOOF9:1;
			__BYTE	RCOOF8:1;
#else
			__BYTE	RCOOF8:1;
			__BYTE	RCOOF9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOOF12:1;
			__BYTE	RCOOF13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOOF13:1;
			__BYTE	RCOOF12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOOF9:1;
			__BYTE	RCOOF8:1;
#else
			__BYTE	RCOOF8:1;
			__BYTE	RCOOF9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOOF12:1;
			__BYTE	RCOOF13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADRCOOF10STR;

__IO_EXTENDED	 const  ADRCOOF10STR	IO_ADRCOOF10;
#define	_adrcoof10		(IO_ADRCOOF10)
#define	ADRCOOF10		(IO_ADRCOOF10.byte)
#define	ADRCOOF10_RCOOF8  	(IO_ADRCOOF10.bit.RCOOF8)
#define	ADRCOOF10_RCOOF9  	(IO_ADRCOOF10.bit.RCOOF9)
#define	ADRCOOF10_RCOOF12  	(IO_ADRCOOF10.bit.RCOOF12)
#define	ADRCOOF10_RCOOF13  	(IO_ADRCOOF10.bit.RCOOF13)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADRCOOF20,   locate=0xB56
#pragma segment FAR_DATA=IO_ADRCOOF20, locate=0xB56
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOOF23:1;
			__BYTE	RCOOF22:1;
			__BYTE	RCOOF21:1;
			__BYTE	RCOOF20:1;
			__BYTE	RCOOF19:1;
			__BYTE	RCOOF18:1;
			__BYTE	RCOOF17:1;
			__BYTE	RCOOF16:1;
#else
			__BYTE	RCOOF16:1;
			__BYTE	RCOOF17:1;
			__BYTE	RCOOF18:1;
			__BYTE	RCOOF19:1;
			__BYTE	RCOOF20:1;
			__BYTE	RCOOF21:1;
			__BYTE	RCOOF22:1;
			__BYTE	RCOOF23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOOF23:1;
			__BYTE	RCOOF22:1;
			__BYTE	RCOOF21:1;
			__BYTE	RCOOF20:1;
			__BYTE	RCOOF19:1;
			__BYTE	RCOOF18:1;
			__BYTE	RCOOF17:1;
			__BYTE	RCOOF16:1;
#else
			__BYTE	RCOOF16:1;
			__BYTE	RCOOF17:1;
			__BYTE	RCOOF18:1;
			__BYTE	RCOOF19:1;
			__BYTE	RCOOF20:1;
			__BYTE	RCOOF21:1;
			__BYTE	RCOOF22:1;
			__BYTE	RCOOF23:1;
#endif
	} bitc;
} ADRCOOF20STR;

__IO_EXTENDED	 const  ADRCOOF20STR	IO_ADRCOOF20;
#define	_adrcoof20		(IO_ADRCOOF20)
#define	ADRCOOF20		(IO_ADRCOOF20.byte)
#define	ADRCOOF20_RCOOF16  	(IO_ADRCOOF20.bit.RCOOF16)
#define	ADRCOOF20_RCOOF17  	(IO_ADRCOOF20.bit.RCOOF17)
#define	ADRCOOF20_RCOOF18  	(IO_ADRCOOF20.bit.RCOOF18)
#define	ADRCOOF20_RCOOF19  	(IO_ADRCOOF20.bit.RCOOF19)
#define	ADRCOOF20_RCOOF20  	(IO_ADRCOOF20.bit.RCOOF20)
#define	ADRCOOF20_RCOOF21  	(IO_ADRCOOF20.bit.RCOOF21)
#define	ADRCOOF20_RCOOF22  	(IO_ADRCOOF20.bit.RCOOF22)
#define	ADRCOOF20_RCOOF23  	(IO_ADRCOOF20.bit.RCOOF23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADRCOINTF10,   locate=0xB5D
#pragma segment FAR_DATA=IO_ADRCOINTF10, locate=0xB5D
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOINT13:1;
			__BYTE	RCOINT12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOINT9:1;
			__BYTE	RCOINT8:1;
#else
			__BYTE	RCOINT8:1;
			__BYTE	RCOINT9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOINT12:1;
			__BYTE	RCOINT13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOINT13:1;
			__BYTE	RCOINT12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOINT9:1;
			__BYTE	RCOINT8:1;
#else
			__BYTE	RCOINT8:1;
			__BYTE	RCOINT9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOINT12:1;
			__BYTE	RCOINT13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADRCOINTF10STR;

__IO_EXTENDED	  ADRCOINTF10STR	IO_ADRCOINTF10;
#define	_adrcointf10		(IO_ADRCOINTF10)
#define	ADRCOINTF10		(IO_ADRCOINTF10.byte)
#define	ADRCOINTF10_RCOINT8  	(IO_ADRCOINTF10.bit.RCOINT8)
#define	ADRCOINTF10_RCOINT9  	(IO_ADRCOINTF10.bit.RCOINT9)
#define	ADRCOINTF10_RCOINT12  	(IO_ADRCOINTF10.bit.RCOINT12)
#define	ADRCOINTF10_RCOINT13  	(IO_ADRCOINTF10.bit.RCOINT13)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADRCOINTF20,   locate=0xB5E
#pragma segment FAR_DATA=IO_ADRCOINTF20, locate=0xB5E
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOINT23:1;
			__BYTE	RCOINT22:1;
			__BYTE	RCOINT21:1;
			__BYTE	RCOINT20:1;
			__BYTE	RCOINT19:1;
			__BYTE	RCOINT18:1;
			__BYTE	RCOINT17:1;
			__BYTE	RCOINT16:1;
#else
			__BYTE	RCOINT16:1;
			__BYTE	RCOINT17:1;
			__BYTE	RCOINT18:1;
			__BYTE	RCOINT19:1;
			__BYTE	RCOINT20:1;
			__BYTE	RCOINT21:1;
			__BYTE	RCOINT22:1;
			__BYTE	RCOINT23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOINT23:1;
			__BYTE	RCOINT22:1;
			__BYTE	RCOINT21:1;
			__BYTE	RCOINT20:1;
			__BYTE	RCOINT19:1;
			__BYTE	RCOINT18:1;
			__BYTE	RCOINT17:1;
			__BYTE	RCOINT16:1;
#else
			__BYTE	RCOINT16:1;
			__BYTE	RCOINT17:1;
			__BYTE	RCOINT18:1;
			__BYTE	RCOINT19:1;
			__BYTE	RCOINT20:1;
			__BYTE	RCOINT21:1;
			__BYTE	RCOINT22:1;
			__BYTE	RCOINT23:1;
#endif
	} bitc;
} ADRCOINTF20STR;

__IO_EXTENDED	  ADRCOINTF20STR	IO_ADRCOINTF20;
#define	_adrcointf20		(IO_ADRCOINTF20)
#define	ADRCOINTF20		(IO_ADRCOINTF20.byte)
#define	ADRCOINTF20_RCOINT16  	(IO_ADRCOINTF20.bit.RCOINT16)
#define	ADRCOINTF20_RCOINT17  	(IO_ADRCOINTF20.bit.RCOINT17)
#define	ADRCOINTF20_RCOINT18  	(IO_ADRCOINTF20.bit.RCOINT18)
#define	ADRCOINTF20_RCOINT19  	(IO_ADRCOINTF20.bit.RCOINT19)
#define	ADRCOINTF20_RCOINT20  	(IO_ADRCOINTF20.bit.RCOINT20)
#define	ADRCOINTF20_RCOINT21  	(IO_ADRCOINTF20.bit.RCOINT21)
#define	ADRCOINTF20_RCOINT22  	(IO_ADRCOINTF20.bit.RCOINT22)
#define	ADRCOINTF20_RCOINT23  	(IO_ADRCOINTF20.bit.RCOINT23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADPCIE10,   locate=0xB65
#pragma segment FAR_DATA=IO_ADPCIE10, locate=0xB65
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CTPIE13:1;
			__BYTE	CTPIE12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	CTPIE9:1;
			__BYTE	CTPIE8:1;
#else
			__BYTE	CTPIE8:1;
			__BYTE	CTPIE9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CTPIE12:1;
			__BYTE	CTPIE13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CTPIE13:1;
			__BYTE	CTPIE12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	CTPIE9:1;
			__BYTE	CTPIE8:1;
#else
			__BYTE	CTPIE8:1;
			__BYTE	CTPIE9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CTPIE12:1;
			__BYTE	CTPIE13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADPCIE10STR;

__IO_EXTENDED	  ADPCIE10STR	IO_ADPCIE10;
#define	_adpcie10		(IO_ADPCIE10)
#define	ADPCIE10		(IO_ADPCIE10.byte)
#define	ADPCIE10_CTPIE8  	(IO_ADPCIE10.bit.CTPIE8)
#define	ADPCIE10_CTPIE9  	(IO_ADPCIE10.bit.CTPIE9)
#define	ADPCIE10_CTPIE12  	(IO_ADPCIE10.bit.CTPIE12)
#define	ADPCIE10_CTPIE13  	(IO_ADPCIE10.bit.CTPIE13)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADPCIE20,   locate=0xB66
#pragma segment FAR_DATA=IO_ADPCIE20, locate=0xB66
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CTPIE23:1;
			__BYTE	CTPIE22:1;
			__BYTE	CTPIE21:1;
			__BYTE	CTPIE20:1;
			__BYTE	CTPIE19:1;
			__BYTE	CTPIE18:1;
			__BYTE	CTPIE17:1;
			__BYTE	CTPIE16:1;
#else
			__BYTE	CTPIE16:1;
			__BYTE	CTPIE17:1;
			__BYTE	CTPIE18:1;
			__BYTE	CTPIE19:1;
			__BYTE	CTPIE20:1;
			__BYTE	CTPIE21:1;
			__BYTE	CTPIE22:1;
			__BYTE	CTPIE23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CTPIE23:1;
			__BYTE	CTPIE22:1;
			__BYTE	CTPIE21:1;
			__BYTE	CTPIE20:1;
			__BYTE	CTPIE19:1;
			__BYTE	CTPIE18:1;
			__BYTE	CTPIE17:1;
			__BYTE	CTPIE16:1;
#else
			__BYTE	CTPIE16:1;
			__BYTE	CTPIE17:1;
			__BYTE	CTPIE18:1;
			__BYTE	CTPIE19:1;
			__BYTE	CTPIE20:1;
			__BYTE	CTPIE21:1;
			__BYTE	CTPIE22:1;
			__BYTE	CTPIE23:1;
#endif
	} bitc;
} ADPCIE20STR;

__IO_EXTENDED	  ADPCIE20STR	IO_ADPCIE20;
#define	_adpcie20		(IO_ADPCIE20)
#define	ADPCIE20		(IO_ADPCIE20.byte)
#define	ADPCIE20_CTPIE16  	(IO_ADPCIE20.bit.CTPIE16)
#define	ADPCIE20_CTPIE17  	(IO_ADPCIE20.bit.CTPIE17)
#define	ADPCIE20_CTPIE18  	(IO_ADPCIE20.bit.CTPIE18)
#define	ADPCIE20_CTPIE19  	(IO_ADPCIE20.bit.CTPIE19)
#define	ADPCIE20_CTPIE20  	(IO_ADPCIE20.bit.CTPIE20)
#define	ADPCIE20_CTPIE21  	(IO_ADPCIE20.bit.CTPIE21)
#define	ADPCIE20_CTPIE22  	(IO_ADPCIE20.bit.CTPIE22)
#define	ADPCIE20_CTPIE23  	(IO_ADPCIE20.bit.CTPIE23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADPCZF10,   locate=0xB69
#pragma segment FAR_DATA=IO_ADPCZF10, locate=0xB69
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CTPZF13:1;
			__BYTE	CTPZF12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	CTPZF9:1;
			__BYTE	CTPZF8:1;
#else
			__BYTE	CTPZF8:1;
			__BYTE	CTPZF9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CTPZF12:1;
			__BYTE	CTPZF13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	CTPZF13:1;
			__BYTE	CTPZF12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	CTPZF9:1;
			__BYTE	CTPZF8:1;
#else
			__BYTE	CTPZF8:1;
			__BYTE	CTPZF9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	CTPZF12:1;
			__BYTE	CTPZF13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADPCZF10STR;

__IO_EXTENDED	  ADPCZF10STR	IO_ADPCZF10;
#define	_adpczf10		(IO_ADPCZF10)
#define	ADPCZF10		(IO_ADPCZF10.byte)
#define	ADPCZF10_CTPZF8  	(IO_ADPCZF10.bit.CTPZF8)
#define	ADPCZF10_CTPZF9  	(IO_ADPCZF10.bit.CTPZF9)
#define	ADPCZF10_CTPZF12  	(IO_ADPCZF10.bit.CTPZF12)
#define	ADPCZF10_CTPZF13  	(IO_ADPCZF10.bit.CTPZF13)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ADPCZF20,   locate=0xB6A
#pragma segment FAR_DATA=IO_ADPCZF20, locate=0xB6A
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CTPZF23:1;
			__BYTE	CTPZF22:1;
			__BYTE	CTPZF21:1;
			__BYTE	CTPZF20:1;
			__BYTE	CTPZF19:1;
			__BYTE	CTPZF18:1;
			__BYTE	CTPZF17:1;
			__BYTE	CTPZF16:1;
#else
			__BYTE	CTPZF16:1;
			__BYTE	CTPZF17:1;
			__BYTE	CTPZF18:1;
			__BYTE	CTPZF19:1;
			__BYTE	CTPZF20:1;
			__BYTE	CTPZF21:1;
			__BYTE	CTPZF22:1;
			__BYTE	CTPZF23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CTPZF23:1;
			__BYTE	CTPZF22:1;
			__BYTE	CTPZF21:1;
			__BYTE	CTPZF20:1;
			__BYTE	CTPZF19:1;
			__BYTE	CTPZF18:1;
			__BYTE	CTPZF17:1;
			__BYTE	CTPZF16:1;
#else
			__BYTE	CTPZF16:1;
			__BYTE	CTPZF17:1;
			__BYTE	CTPZF18:1;
			__BYTE	CTPZF19:1;
			__BYTE	CTPZF20:1;
			__BYTE	CTPZF21:1;
			__BYTE	CTPZF22:1;
			__BYTE	CTPZF23:1;
#endif
	} bitc;
} ADPCZF20STR;

__IO_EXTENDED	  ADPCZF20STR	IO_ADPCZF20;
#define	_adpczf20		(IO_ADPCZF20)
#define	ADPCZF20		(IO_ADPCZF20.byte)
#define	ADPCZF20_CTPZF16  	(IO_ADPCZF20.bit.CTPZF16)
#define	ADPCZF20_CTPZF17  	(IO_ADPCZF20.bit.CTPZF17)
#define	ADPCZF20_CTPZF18  	(IO_ADPCZF20.bit.CTPZF18)
#define	ADPCZF20_CTPZF19  	(IO_ADPCZF20.bit.CTPZF19)
#define	ADPCZF20_CTPZF20  	(IO_ADPCZF20.bit.CTPZF20)
#define	ADPCZF20_CTPZF21  	(IO_ADPCZF20.bit.CTPZF21)
#define	ADPCZF20_CTPZF22  	(IO_ADPCZF20.bit.CTPZF22)
#define	ADPCZF20_CTPZF23  	(IO_ADPCZF20.bit.CTPZF23)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_CSCR0,   locate=0xBAA
#pragma segment FAR_DATA=IO_CSCR0, locate=0xBAA
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CRCERRIE:1;
			__BYTE	CRCERR:1;
			__BYTE	CRCTYPE:1;
			__BYTE	CRCCHECK:1;
			__BYTE	CRCGEN:1;
			__BYTE	DL:3;
#else
			__BYTE	DL:3;
			__BYTE	CRCGEN:1;
			__BYTE	CRCCHECK:1;
			__BYTE	CRCTYPE:1;
			__BYTE	CRCERR:1;
			__BYTE	CRCERRIE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	CRCERRIE:1;
			__BYTE	CRCERR:1;
			__BYTE	CRCTYPE:1;
			__BYTE	CRCCHECK:1;
			__BYTE	CRCGEN:1;
			__BYTE	DL2:1;
			__BYTE	DL1:1;
			__BYTE	DL0:1;
#else
			__BYTE	DL0:1;
			__BYTE	DL1:1;
			__BYTE	DL2:1;
			__BYTE	CRCGEN:1;
			__BYTE	CRCCHECK:1;
			__BYTE	CRCTYPE:1;
			__BYTE	CRCERR:1;
			__BYTE	CRCERRIE:1;
#endif
	} bitc;
} CSCR0STR;

__IO_EXTENDED	  CSCR0STR	IO_CSCR0;
#define	_cscr0		(IO_CSCR0)
#define	CSCR0		(IO_CSCR0.byte)
#define	CSCR0_DL  	(IO_CSCR0.bit.DL)
#define	CSCR0_DL0  	(IO_CSCR0.bitc.DL0)
#define	CSCR0_DL1  	(IO_CSCR0.bitc.DL1)
#define	CSCR0_DL2  	(IO_CSCR0.bitc.DL2)
#define	CSCR0_CRCGEN  	(IO_CSCR0.bit.CRCGEN)
#define	CSCR0_CRCCHECK  	(IO_CSCR0.bit.CRCCHECK)
#define	CSCR0_CRCTYPE  	(IO_CSCR0.bit.CRCTYPE)
#define	CSCR0_CRCERR  	(IO_CSCR0.bit.CRCERR)
#define	CSCR0_CRCERRIE  	(IO_CSCR0.bit.CRCERRIE)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ESR0,   locate=0xBAB
#pragma segment FAR_DATA=IO_ESR0, locate=0xBAB
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ESR0STR;

__IO_EXTENDED	  ESR0STR	IO_ESR0;
#define	_esr0		(IO_ESR0)
#define	ESR0		(IO_ESR0.byte)
#define	ESR0_SYNFE  	(IO_ESR0.bit.SYNFE)
#define	ESR0_PEFRD  	(IO_ESR0.bit.PEFRD)
#define	ESR0_BUSERR  	(IO_ESR0.bit.BUSERR)
#define	ESR0_LBSOF  	(IO_ESR0.bit.LBSOF)
#define	ESR0_RXHRI  	(IO_ESR0.bit.RXHRI)
#define	ESR0_TXHRI  	(IO_ESR0.bit.TXHRI)

#ifdef __IO_DEFINE
#pragma segment     DATA=IO_ESR1,   locate=0xBAD
#pragma segment FAR_DATA=IO_ESR1, locate=0xBAD
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	TXHRI:1;
			__BYTE	RXHRI:1;
			__BYTE	LBSOF:1;
			__BYTE	BUSERR:1;
			__BYTE	PEFRD:1;
			__BYTE	SYNFE:1;
#else
			__BYTE	SYNFE:1;
			__BYTE	PEFRD:1;
			__BYTE	BUSERR:1;
			__BYTE	LBSOF:1;
			__BYTE	RXHRI:1;
			__BYTE	TXHRI:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ESR1STR;

__IO_EXTENDED	  ESR1STR	IO_ESR1;
#define	_esr1		(IO_ESR1)
#define	ESR1		(IO_ESR1.byte)
#define	ESR1_SYNFE  	(IO_ESR1.bit.SYNFE)
#define	ESR1_PEFRD  	(IO_ESR1.bit.PEFRD)
#define	ESR1_BUSERR  	(IO_ESR1.bit.BUSERR)
#define	ESR1_LBSOF  	(IO_ESR1.bit.LBSOF)
#define	ESR1_RXHRI  	(IO_ESR1.bit.RXHRI)
#define	ESR1_TXHRI  	(IO_ESR1.bit.TXHRI)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_GCN30, locate=0xE9300
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV7:1;
			__WORD	RTG3:3;
			__WORD	RESV5:1;
			__WORD	RTG2:3;
			__WORD	RESV3:1;
			__WORD	RTG1:3;
			__WORD	RESV1:1;
			__WORD	RTG0:3;
#else
			__WORD	RTG0:3;
			__WORD	RESV1:1;
			__WORD	RTG1:3;
			__WORD	RESV3:1;
			__WORD	RTG2:3;
			__WORD	RESV5:1;
			__WORD	RTG3:3;
			__WORD	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RTG32:1;
			__WORD	RTG31:1;
			__WORD	RTG30:1;
			__WORD	RESV11:1;
			__WORD	RTG22:1;
			__WORD	RTG21:1;
			__WORD	RTG20:1;
			__WORD	RESV7:1;
			__WORD	RTG12:1;
			__WORD	RTG11:1;
			__WORD	RTG10:1;
			__WORD	RESV3:1;
			__WORD	RTG02:1;
			__WORD	RTG01:1;
			__WORD	RTG00:1;
#else
			__WORD	RTG00:1;
			__WORD	RTG01:1;
			__WORD	RTG02:1;
			__WORD	RESV3:1;
			__WORD	RTG10:1;
			__WORD	RTG11:1;
			__WORD	RTG12:1;
			__WORD	RESV7:1;
			__WORD	RTG20:1;
			__WORD	RTG21:1;
			__WORD	RTG22:1;
			__WORD	RESV11:1;
			__WORD	RTG30:1;
			__WORD	RTG31:1;
			__WORD	RTG32:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} GCN30STR;

__IO_EXTENDED __far	  GCN30STR	IO_GCN30;
#define	_gcn30		(IO_GCN30)
#define	GCN30		(IO_GCN30.word)
#define	GCN30_RTG0  	(IO_GCN30.bit.RTG0)
#define	GCN30_RTG00  	(IO_GCN30.bitc.RTG00)
#define	GCN30_RTG01  	(IO_GCN30.bitc.RTG01)
#define	GCN30_RTG02  	(IO_GCN30.bitc.RTG02)
#define	GCN30_RTG1  	(IO_GCN30.bit.RTG1)
#define	GCN30_RTG10  	(IO_GCN30.bitc.RTG10)
#define	GCN30_RTG11  	(IO_GCN30.bitc.RTG11)
#define	GCN30_RTG12  	(IO_GCN30.bitc.RTG12)
#define	GCN30_RTG2  	(IO_GCN30.bit.RTG2)
#define	GCN30_RTG20  	(IO_GCN30.bitc.RTG20)
#define	GCN30_RTG21  	(IO_GCN30.bitc.RTG21)
#define	GCN30_RTG22  	(IO_GCN30.bitc.RTG22)
#define	GCN30_RTG3  	(IO_GCN30.bit.RTG3)
#define	GCN30_RTG30  	(IO_GCN30.bitc.RTG30)
#define	GCN30_RTG31  	(IO_GCN30.bitc.RTG31)
#define	GCN30_RTG32  	(IO_GCN30.bitc.RTG32)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_GCN40, locate=0xE9302
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV7:1;
			__WORD	RCK3:3;
			__WORD	RESV5:1;
			__WORD	RCK2:3;
			__WORD	RESV3:1;
			__WORD	RCK1:3;
			__WORD	RESV1:1;
			__WORD	RCK0:3;
#else
			__WORD	RCK0:3;
			__WORD	RESV1:1;
			__WORD	RCK1:3;
			__WORD	RESV3:1;
			__WORD	RCK2:3;
			__WORD	RESV5:1;
			__WORD	RCK3:3;
			__WORD	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RCK32:1;
			__WORD	RCK31:1;
			__WORD	RCK30:1;
			__WORD	RESV11:1;
			__WORD	RCK22:1;
			__WORD	RCK21:1;
			__WORD	RCK20:1;
			__WORD	RESV7:1;
			__WORD	RCK12:1;
			__WORD	RCK11:1;
			__WORD	RCK10:1;
			__WORD	RESV3:1;
			__WORD	RCK02:1;
			__WORD	RCK01:1;
			__WORD	RCK00:1;
#else
			__WORD	RCK00:1;
			__WORD	RCK01:1;
			__WORD	RCK02:1;
			__WORD	RESV3:1;
			__WORD	RCK10:1;
			__WORD	RCK11:1;
			__WORD	RCK12:1;
			__WORD	RESV7:1;
			__WORD	RCK20:1;
			__WORD	RCK21:1;
			__WORD	RCK22:1;
			__WORD	RESV11:1;
			__WORD	RCK30:1;
			__WORD	RCK31:1;
			__WORD	RCK32:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} GCN40STR;

__IO_EXTENDED __far	  GCN40STR	IO_GCN40;
#define	_gcn40		(IO_GCN40)
#define	GCN40		(IO_GCN40.word)
#define	GCN40_RCK0  	(IO_GCN40.bit.RCK0)
#define	GCN40_RCK00  	(IO_GCN40.bitc.RCK00)
#define	GCN40_RCK01  	(IO_GCN40.bitc.RCK01)
#define	GCN40_RCK02  	(IO_GCN40.bitc.RCK02)
#define	GCN40_RCK1  	(IO_GCN40.bit.RCK1)
#define	GCN40_RCK10  	(IO_GCN40.bitc.RCK10)
#define	GCN40_RCK11  	(IO_GCN40.bitc.RCK11)
#define	GCN40_RCK12  	(IO_GCN40.bitc.RCK12)
#define	GCN40_RCK2  	(IO_GCN40.bit.RCK2)
#define	GCN40_RCK20  	(IO_GCN40.bitc.RCK20)
#define	GCN40_RCK21  	(IO_GCN40.bitc.RCK21)
#define	GCN40_RCK22  	(IO_GCN40.bitc.RCK22)
#define	GCN40_RCK3  	(IO_GCN40.bit.RCK3)
#define	GCN40_RCK30  	(IO_GCN40.bitc.RCK30)
#define	GCN40_RCK31  	(IO_GCN40.bitc.RCK31)
#define	GCN40_RCK32  	(IO_GCN40.bitc.RCK32)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_GCN50, locate=0xE9304
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RSH3:2;
			__BYTE	RSH2:2;
			__BYTE	RSH1:2;
			__BYTE	RSH0:2;
#else
			__BYTE	RSH0:2;
			__BYTE	RSH1:2;
			__BYTE	RSH2:2;
			__BYTE	RSH3:2;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RSH31:1;
			__BYTE	RSH30:1;
			__BYTE	RSH21:1;
			__BYTE	RSH20:1;
			__BYTE	RSH11:1;
			__BYTE	RSH10:1;
			__BYTE	RSH01:1;
			__BYTE	RSH00:1;
#else
			__BYTE	RSH00:1;
			__BYTE	RSH01:1;
			__BYTE	RSH10:1;
			__BYTE	RSH11:1;
			__BYTE	RSH20:1;
			__BYTE	RSH21:1;
			__BYTE	RSH30:1;
			__BYTE	RSH31:1;
#endif
	} bitc;
} GCN50STR;

__IO_EXTENDED __far	  GCN50STR	IO_GCN50;
#define	_gcn50		(IO_GCN50)
#define	GCN50		(IO_GCN50.byte)
#define	GCN50_RSH0  	(IO_GCN50.bit.RSH0)
#define	GCN50_RSH00  	(IO_GCN50.bitc.RSH00)
#define	GCN50_RSH01  	(IO_GCN50.bitc.RSH01)
#define	GCN50_RSH1  	(IO_GCN50.bit.RSH1)
#define	GCN50_RSH10  	(IO_GCN50.bitc.RSH10)
#define	GCN50_RSH11  	(IO_GCN50.bitc.RSH11)
#define	GCN50_RSH2  	(IO_GCN50.bit.RSH2)
#define	GCN50_RSH20  	(IO_GCN50.bitc.RSH20)
#define	GCN50_RSH21  	(IO_GCN50.bitc.RSH21)
#define	GCN50_RSH3  	(IO_GCN50.bit.RSH3)
#define	GCN50_RSH30  	(IO_GCN50.bitc.RSH30)
#define	GCN50_RSH31  	(IO_GCN50.bitc.RSH31)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EPCN20, locate=0xE9310
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bitc;
} EPCN20STR;

__IO_EXTENDED __far	  EPCN20STR	IO_EPCN20;
#define	_epcn20		(IO_EPCN20)
#define	EPCN20		(IO_EPCN20.byte)
#define	EPCN20_PRDL  	(IO_EPCN20.bit.PRDL)
#define	EPCN20_PRDH  	(IO_EPCN20.bit.PRDH)
#define	EPCN20_DTL  	(IO_EPCN20.bit.DTL)
#define	EPCN20_DTH  	(IO_EPCN20.bit.DTH)
#define	EPCN20_EDML  	(IO_EPCN20.bit.EDML)
#define	EPCN20_EDMH  	(IO_EPCN20.bit.EDMH)
#define	EPCN20_TCL  	(IO_EPCN20.bit.TCL)
#define	EPCN20_TCH  	(IO_EPCN20.bit.TCH)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_PTPC0, locate=0xE9314
#endif

__IO_EXTENDED __far	__WORD	IO_PTPC0;
#define	_ptpc0		(IO_PTPC0)
#define	PTPC0	(_ptpc0)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EPCN21, locate=0xE9320
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bitc;
} EPCN21STR;

__IO_EXTENDED __far	  EPCN21STR	IO_EPCN21;
#define	_epcn21		(IO_EPCN21)
#define	EPCN21		(IO_EPCN21.byte)
#define	EPCN21_PRDL  	(IO_EPCN21.bit.PRDL)
#define	EPCN21_PRDH  	(IO_EPCN21.bit.PRDH)
#define	EPCN21_DTL  	(IO_EPCN21.bit.DTL)
#define	EPCN21_DTH  	(IO_EPCN21.bit.DTH)
#define	EPCN21_EDML  	(IO_EPCN21.bit.EDML)
#define	EPCN21_EDMH  	(IO_EPCN21.bit.EDMH)
#define	EPCN21_TCL  	(IO_EPCN21.bit.TCL)
#define	EPCN21_TCH  	(IO_EPCN21.bit.TCH)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_PTPC1, locate=0xE9324
#endif

__IO_EXTENDED __far	__WORD	IO_PTPC1;
#define	_ptpc1		(IO_PTPC1)
#define	PTPC1	(_ptpc1)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EPCN22, locate=0xE9330
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bitc;
} EPCN22STR;

__IO_EXTENDED __far	  EPCN22STR	IO_EPCN22;
#define	_epcn22		(IO_EPCN22)
#define	EPCN22		(IO_EPCN22.byte)
#define	EPCN22_PRDL  	(IO_EPCN22.bit.PRDL)
#define	EPCN22_PRDH  	(IO_EPCN22.bit.PRDH)
#define	EPCN22_DTL  	(IO_EPCN22.bit.DTL)
#define	EPCN22_DTH  	(IO_EPCN22.bit.DTH)
#define	EPCN22_EDML  	(IO_EPCN22.bit.EDML)
#define	EPCN22_EDMH  	(IO_EPCN22.bit.EDMH)
#define	EPCN22_TCL  	(IO_EPCN22.bit.TCL)
#define	EPCN22_TCH  	(IO_EPCN22.bit.TCH)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_PTPC2, locate=0xE9334
#endif

__IO_EXTENDED __far	__WORD	IO_PTPC2;
#define	_ptpc2		(IO_PTPC2)
#define	PTPC2	(_ptpc2)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EPCN23, locate=0xE9340
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TCH:1;
			__BYTE	TCL:1;
			__BYTE	EDMH:1;
			__BYTE	EDML:1;
			__BYTE	DTH:1;
			__BYTE	DTL:1;
			__BYTE	PRDH:1;
			__BYTE	PRDL:1;
#else
			__BYTE	PRDL:1;
			__BYTE	PRDH:1;
			__BYTE	DTL:1;
			__BYTE	DTH:1;
			__BYTE	EDML:1;
			__BYTE	EDMH:1;
			__BYTE	TCL:1;
			__BYTE	TCH:1;
#endif
	} bitc;
} EPCN23STR;

__IO_EXTENDED __far	  EPCN23STR	IO_EPCN23;
#define	_epcn23		(IO_EPCN23)
#define	EPCN23		(IO_EPCN23.byte)
#define	EPCN23_PRDL  	(IO_EPCN23.bit.PRDL)
#define	EPCN23_PRDH  	(IO_EPCN23.bit.PRDH)
#define	EPCN23_DTL  	(IO_EPCN23.bit.DTL)
#define	EPCN23_DTH  	(IO_EPCN23.bit.DTH)
#define	EPCN23_EDML  	(IO_EPCN23.bit.EDML)
#define	EPCN23_EDMH  	(IO_EPCN23.bit.EDMH)
#define	EPCN23_TCL  	(IO_EPCN23.bit.TCL)
#define	EPCN23_TCH  	(IO_EPCN23.bit.TCH)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_PTPC3, locate=0xE9344
#endif

__IO_EXTENDED __far	__WORD	IO_PTPC3;
#define	_ptpc3		(IO_PTPC3)
#define	PTPC3	(_ptpc3)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADTGCRH0, locate=0xE94A1
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RLTE:1;
#else
			__BYTE	RLTE:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RESV5:1;
			__BYTE	RESV4:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RESV1:1;
			__BYTE	RLTE:1;
#else
			__BYTE	RLTE:1;
			__BYTE	RESV1:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RESV4:1;
			__BYTE	RESV5:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADTGCRH0STR;

__IO_EXTENDED __far	  ADTGCRH0STR	IO_ADTGCRH0;
#define	_adtgcrh0		(IO_ADTGCRH0)
#define	ADTGCRH0		(IO_ADTGCRH0.byte)
#define	ADTGCRH0_RLTE  	(IO_ADTGCRH0.bit.RLTE)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADTGISEL0, locate=0xE94A2
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV9:1;
			__WORD	RESV8:1;
			__WORD	RESV7:1;
			__WORD	PP:5;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	RLT:3;
#else
			__WORD	RLT:3;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	PP:5;
			__WORD	RESV7:1;
			__WORD	RESV8:1;
			__WORD	RESV9:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	PP4:1;
			__WORD	PP3:1;
			__WORD	PP2:1;
			__WORD	PP1:1;
			__WORD	PP0:1;
			__WORD	RESV7:1;
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RLT2:1;
			__WORD	RLT1:1;
			__WORD	RLT0:1;
#else
			__WORD	RLT0:1;
			__WORD	RLT1:1;
			__WORD	RLT2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
			__WORD	RESV7:1;
			__WORD	PP0:1;
			__WORD	PP1:1;
			__WORD	PP2:1;
			__WORD	PP3:1;
			__WORD	PP4:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADTGISEL0STR;

__IO_EXTENDED __far	  ADTGISEL0STR	IO_ADTGISEL0;
#define	_adtgisel0		(IO_ADTGISEL0)
#define	ADTGISEL0		(IO_ADTGISEL0.word)
#define	ADTGISEL0_RLT  	(IO_ADTGISEL0.bit.RLT)
#define	ADTGISEL0_RLT0  	(IO_ADTGISEL0.bitc.RLT0)
#define	ADTGISEL0_RLT1  	(IO_ADTGISEL0.bitc.RLT1)
#define	ADTGISEL0_RLT2  	(IO_ADTGISEL0.bitc.RLT2)
#define	ADTGISEL0_PP  	(IO_ADTGISEL0.bit.PP)
#define	ADTGISEL0_PP0  	(IO_ADTGISEL0.bitc.PP0)
#define	ADTGISEL0_PP1  	(IO_ADTGISEL0.bitc.PP1)
#define	ADTGISEL0_PP2  	(IO_ADTGISEL0.bitc.PP2)
#define	ADTGISEL0_PP3  	(IO_ADTGISEL0.bitc.PP3)
#define	ADTGISEL0_PP4  	(IO_ADTGISEL0.bitc.PP4)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOL00, locate=0xE9520
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOL00STR;

__IO_EXTENDED __far	  ADRCOL00STR	IO_ADRCOL00;
#define	_adrcol00		(IO_ADRCOL00)
#define	ADRCOL00		(IO_ADRCOL00.word)
#define	ADRCOL00_C  	(IO_ADRCOL00.bit.C)
#define	ADRCOL00_C0  	(IO_ADRCOL00.bitc.C0)
#define	ADRCOL00_C1  	(IO_ADRCOL00.bitc.C1)
#define	ADRCOL00_C2  	(IO_ADRCOL00.bitc.C2)
#define	ADRCOL00_C3  	(IO_ADRCOL00.bitc.C3)
#define	ADRCOL00_C4  	(IO_ADRCOL00.bitc.C4)
#define	ADRCOL00_C5  	(IO_ADRCOL00.bitc.C5)
#define	ADRCOL00_C6  	(IO_ADRCOL00.bitc.C6)
#define	ADRCOL00_C7  	(IO_ADRCOL00.bitc.C7)
#define	ADRCOL00_C8  	(IO_ADRCOL00.bitc.C8)
#define	ADRCOL00_C9  	(IO_ADRCOL00.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOH00, locate=0xE9522
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOH00STR;

__IO_EXTENDED __far	  ADRCOH00STR	IO_ADRCOH00;
#define	_adrcoh00		(IO_ADRCOH00)
#define	ADRCOH00		(IO_ADRCOH00.word)
#define	ADRCOH00_C  	(IO_ADRCOH00.bit.C)
#define	ADRCOH00_C0  	(IO_ADRCOH00.bitc.C0)
#define	ADRCOH00_C1  	(IO_ADRCOH00.bitc.C1)
#define	ADRCOH00_C2  	(IO_ADRCOH00.bitc.C2)
#define	ADRCOH00_C3  	(IO_ADRCOH00.bitc.C3)
#define	ADRCOH00_C4  	(IO_ADRCOH00.bitc.C4)
#define	ADRCOH00_C5  	(IO_ADRCOH00.bitc.C5)
#define	ADRCOH00_C6  	(IO_ADRCOH00.bitc.C6)
#define	ADRCOH00_C7  	(IO_ADRCOH00.bitc.C7)
#define	ADRCOH00_C8  	(IO_ADRCOH00.bitc.C8)
#define	ADRCOH00_C9  	(IO_ADRCOH00.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOL10, locate=0xE9524
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOL10STR;

__IO_EXTENDED __far	  ADRCOL10STR	IO_ADRCOL10;
#define	_adrcol10		(IO_ADRCOL10)
#define	ADRCOL10		(IO_ADRCOL10.word)
#define	ADRCOL10_C  	(IO_ADRCOL10.bit.C)
#define	ADRCOL10_C0  	(IO_ADRCOL10.bitc.C0)
#define	ADRCOL10_C1  	(IO_ADRCOL10.bitc.C1)
#define	ADRCOL10_C2  	(IO_ADRCOL10.bitc.C2)
#define	ADRCOL10_C3  	(IO_ADRCOL10.bitc.C3)
#define	ADRCOL10_C4  	(IO_ADRCOL10.bitc.C4)
#define	ADRCOL10_C5  	(IO_ADRCOL10.bitc.C5)
#define	ADRCOL10_C6  	(IO_ADRCOL10.bitc.C6)
#define	ADRCOL10_C7  	(IO_ADRCOL10.bitc.C7)
#define	ADRCOL10_C8  	(IO_ADRCOL10.bitc.C8)
#define	ADRCOL10_C9  	(IO_ADRCOL10.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOH10, locate=0xE9526
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOH10STR;

__IO_EXTENDED __far	  ADRCOH10STR	IO_ADRCOH10;
#define	_adrcoh10		(IO_ADRCOH10)
#define	ADRCOH10		(IO_ADRCOH10.word)
#define	ADRCOH10_C  	(IO_ADRCOH10.bit.C)
#define	ADRCOH10_C0  	(IO_ADRCOH10.bitc.C0)
#define	ADRCOH10_C1  	(IO_ADRCOH10.bitc.C1)
#define	ADRCOH10_C2  	(IO_ADRCOH10.bitc.C2)
#define	ADRCOH10_C3  	(IO_ADRCOH10.bitc.C3)
#define	ADRCOH10_C4  	(IO_ADRCOH10.bitc.C4)
#define	ADRCOH10_C5  	(IO_ADRCOH10.bitc.C5)
#define	ADRCOH10_C6  	(IO_ADRCOH10.bitc.C6)
#define	ADRCOH10_C7  	(IO_ADRCOH10.bitc.C7)
#define	ADRCOH10_C8  	(IO_ADRCOH10.bitc.C8)
#define	ADRCOH10_C9  	(IO_ADRCOH10.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOL20, locate=0xE9528
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOL20STR;

__IO_EXTENDED __far	  ADRCOL20STR	IO_ADRCOL20;
#define	_adrcol20		(IO_ADRCOL20)
#define	ADRCOL20		(IO_ADRCOL20.word)
#define	ADRCOL20_C  	(IO_ADRCOL20.bit.C)
#define	ADRCOL20_C0  	(IO_ADRCOL20.bitc.C0)
#define	ADRCOL20_C1  	(IO_ADRCOL20.bitc.C1)
#define	ADRCOL20_C2  	(IO_ADRCOL20.bitc.C2)
#define	ADRCOL20_C3  	(IO_ADRCOL20.bitc.C3)
#define	ADRCOL20_C4  	(IO_ADRCOL20.bitc.C4)
#define	ADRCOL20_C5  	(IO_ADRCOL20.bitc.C5)
#define	ADRCOL20_C6  	(IO_ADRCOL20.bitc.C6)
#define	ADRCOL20_C7  	(IO_ADRCOL20.bitc.C7)
#define	ADRCOL20_C8  	(IO_ADRCOL20.bitc.C8)
#define	ADRCOL20_C9  	(IO_ADRCOL20.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOH20, locate=0xE952A
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOH20STR;

__IO_EXTENDED __far	  ADRCOH20STR	IO_ADRCOH20;
#define	_adrcoh20		(IO_ADRCOH20)
#define	ADRCOH20		(IO_ADRCOH20.word)
#define	ADRCOH20_C  	(IO_ADRCOH20.bit.C)
#define	ADRCOH20_C0  	(IO_ADRCOH20.bitc.C0)
#define	ADRCOH20_C1  	(IO_ADRCOH20.bitc.C1)
#define	ADRCOH20_C2  	(IO_ADRCOH20.bitc.C2)
#define	ADRCOH20_C3  	(IO_ADRCOH20.bitc.C3)
#define	ADRCOH20_C4  	(IO_ADRCOH20.bitc.C4)
#define	ADRCOH20_C5  	(IO_ADRCOH20.bitc.C5)
#define	ADRCOH20_C6  	(IO_ADRCOH20.bitc.C6)
#define	ADRCOH20_C7  	(IO_ADRCOH20.bitc.C7)
#define	ADRCOH20_C8  	(IO_ADRCOH20.bitc.C8)
#define	ADRCOH20_C9  	(IO_ADRCOH20.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOL30, locate=0xE952C
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOL30STR;

__IO_EXTENDED __far	  ADRCOL30STR	IO_ADRCOL30;
#define	_adrcol30		(IO_ADRCOL30)
#define	ADRCOL30		(IO_ADRCOL30.word)
#define	ADRCOL30_C  	(IO_ADRCOL30.bit.C)
#define	ADRCOL30_C0  	(IO_ADRCOL30.bitc.C0)
#define	ADRCOL30_C1  	(IO_ADRCOL30.bitc.C1)
#define	ADRCOL30_C2  	(IO_ADRCOL30.bitc.C2)
#define	ADRCOL30_C3  	(IO_ADRCOL30.bitc.C3)
#define	ADRCOL30_C4  	(IO_ADRCOL30.bitc.C4)
#define	ADRCOL30_C5  	(IO_ADRCOL30.bitc.C5)
#define	ADRCOL30_C6  	(IO_ADRCOL30.bitc.C6)
#define	ADRCOL30_C7  	(IO_ADRCOL30.bitc.C7)
#define	ADRCOL30_C8  	(IO_ADRCOL30.bitc.C8)
#define	ADRCOL30_C9  	(IO_ADRCOL30.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOH30, locate=0xE952E
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV6:1;
			__WORD	RESV5:1;
			__WORD	RESV4:1;
			__WORD	RESV3:1;
			__WORD	RESV2:1;
			__WORD	RESV1:1;
			__WORD	C:10;
#else
			__WORD	C:10;
			__WORD	RESV1:1;
			__WORD	RESV2:1;
			__WORD	RESV3:1;
			__WORD	RESV4:1;
			__WORD	RESV5:1;
			__WORD	RESV6:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	RESV13:1;
			__WORD	RESV12:1;
			__WORD	RESV11:1;
			__WORD	RESV10:1;
			__WORD	C9:1;
			__WORD	C8:1;
			__WORD	C7:1;
			__WORD	C6:1;
			__WORD	C5:1;
			__WORD	C4:1;
			__WORD	C3:1;
			__WORD	C2:1;
			__WORD	C1:1;
			__WORD	C0:1;
#else
			__WORD	C0:1;
			__WORD	C1:1;
			__WORD	C2:1;
			__WORD	C3:1;
			__WORD	C4:1;
			__WORD	C5:1;
			__WORD	C6:1;
			__WORD	C7:1;
			__WORD	C8:1;
			__WORD	C9:1;
			__WORD	RESV10:1;
			__WORD	RESV11:1;
			__WORD	RESV12:1;
			__WORD	RESV13:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} ADRCOH30STR;

__IO_EXTENDED __far	  ADRCOH30STR	IO_ADRCOH30;
#define	_adrcoh30		(IO_ADRCOH30)
#define	ADRCOH30		(IO_ADRCOH30.word)
#define	ADRCOH30_C  	(IO_ADRCOH30.bit.C)
#define	ADRCOH30_C0  	(IO_ADRCOH30.bitc.C0)
#define	ADRCOH30_C1  	(IO_ADRCOH30.bitc.C1)
#define	ADRCOH30_C2  	(IO_ADRCOH30.bitc.C2)
#define	ADRCOH30_C3  	(IO_ADRCOH30.bitc.C3)
#define	ADRCOH30_C4  	(IO_ADRCOH30.bitc.C4)
#define	ADRCOH30_C5  	(IO_ADRCOH30.bitc.C5)
#define	ADRCOH30_C6  	(IO_ADRCOH30.bitc.C6)
#define	ADRCOH30_C7  	(IO_ADRCOH30.bitc.C7)
#define	ADRCOH30_C8  	(IO_ADRCOH30.bitc.C8)
#define	ADRCOH30_C9  	(IO_ADRCOH30.bitc.C9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADDSCR10, locate=0xE9531
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	DCS13:1;
			__BYTE	DCS12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	DCS9:1;
			__BYTE	DCS8:1;
#else
			__BYTE	DCS8:1;
			__BYTE	DCS9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	DCS12:1;
			__BYTE	DCS13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	DCS13:1;
			__BYTE	DCS12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	DCS9:1;
			__BYTE	DCS8:1;
#else
			__BYTE	DCS8:1;
			__BYTE	DCS9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	DCS12:1;
			__BYTE	DCS13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADDSCR10STR;

__IO_EXTENDED __far	  ADDSCR10STR	IO_ADDSCR10;
#define	_addscr10		(IO_ADDSCR10)
#define	ADDSCR10		(IO_ADDSCR10.byte)
#define	ADDSCR10_DCS8  	(IO_ADDSCR10.bit.DCS8)
#define	ADDSCR10_DCS9  	(IO_ADDSCR10.bit.DCS9)
#define	ADDSCR10_DCS12  	(IO_ADDSCR10.bit.DCS12)
#define	ADDSCR10_DCS13  	(IO_ADDSCR10.bit.DCS13)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADDSCR20, locate=0xE9532
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DCS23:1;
			__BYTE	DCS22:1;
			__BYTE	DCS21:1;
			__BYTE	DCS20:1;
			__BYTE	DCS19:1;
			__BYTE	DCS18:1;
			__BYTE	DCS17:1;
			__BYTE	DCS16:1;
#else
			__BYTE	DCS16:1;
			__BYTE	DCS17:1;
			__BYTE	DCS18:1;
			__BYTE	DCS19:1;
			__BYTE	DCS20:1;
			__BYTE	DCS21:1;
			__BYTE	DCS22:1;
			__BYTE	DCS23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	DCS23:1;
			__BYTE	DCS22:1;
			__BYTE	DCS21:1;
			__BYTE	DCS20:1;
			__BYTE	DCS19:1;
			__BYTE	DCS18:1;
			__BYTE	DCS17:1;
			__BYTE	DCS16:1;
#else
			__BYTE	DCS16:1;
			__BYTE	DCS17:1;
			__BYTE	DCS18:1;
			__BYTE	DCS19:1;
			__BYTE	DCS20:1;
			__BYTE	DCS21:1;
			__BYTE	DCS22:1;
			__BYTE	DCS23:1;
#endif
	} bitc;
} ADDSCR20STR;

__IO_EXTENDED __far	  ADDSCR20STR	IO_ADDSCR20;
#define	_addscr20		(IO_ADDSCR20)
#define	ADDSCR20		(IO_ADDSCR20.byte)
#define	ADDSCR20_DCS16  	(IO_ADDSCR20.bit.DCS16)
#define	ADDSCR20_DCS17  	(IO_ADDSCR20.bit.DCS17)
#define	ADDSCR20_DCS18  	(IO_ADDSCR20.bit.DCS18)
#define	ADDSCR20_DCS19  	(IO_ADDSCR20.bit.DCS19)
#define	ADDSCR20_DCS20  	(IO_ADDSCR20.bit.DCS20)
#define	ADDSCR20_DCS21  	(IO_ADDSCR20.bit.DCS21)
#define	ADDSCR20_DCS22  	(IO_ADDSCR20.bit.DCS22)
#define	ADDSCR20_DCS23  	(IO_ADDSCR20.bit.DCS23)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOIRS10, locate=0xE9541
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOIRS13:1;
			__BYTE	RCOIRS12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOIRS9:1;
			__BYTE	RCOIRS8:1;
#else
			__BYTE	RCOIRS8:1;
			__BYTE	RCOIRS9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOIRS12:1;
			__BYTE	RCOIRS13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RESV7:1;
			__BYTE	RESV6:1;
			__BYTE	RCOIRS13:1;
			__BYTE	RCOIRS12:1;
			__BYTE	RESV3:1;
			__BYTE	RESV2:1;
			__BYTE	RCOIRS9:1;
			__BYTE	RCOIRS8:1;
#else
			__BYTE	RCOIRS8:1;
			__BYTE	RCOIRS9:1;
			__BYTE	RESV2:1;
			__BYTE	RESV3:1;
			__BYTE	RCOIRS12:1;
			__BYTE	RCOIRS13:1;
			__BYTE	RESV6:1;
			__BYTE	RESV7:1;
#endif
	} bitc;
} ADRCOIRS10STR;

__IO_EXTENDED __far	  ADRCOIRS10STR	IO_ADRCOIRS10;
#define	_adrcoirs10		(IO_ADRCOIRS10)
#define	ADRCOIRS10		(IO_ADRCOIRS10.byte)
#define	ADRCOIRS10_RCOIRS8  	(IO_ADRCOIRS10.bit.RCOIRS8)
#define	ADRCOIRS10_RCOIRS9  	(IO_ADRCOIRS10.bit.RCOIRS9)
#define	ADRCOIRS10_RCOIRS12  	(IO_ADRCOIRS10.bit.RCOIRS12)
#define	ADRCOIRS10_RCOIRS13  	(IO_ADRCOIRS10.bit.RCOIRS13)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADRCOIRS20, locate=0xE9542
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIRS23:1;
			__BYTE	RCOIRS22:1;
			__BYTE	RCOIRS21:1;
			__BYTE	RCOIRS20:1;
			__BYTE	RCOIRS19:1;
			__BYTE	RCOIRS18:1;
			__BYTE	RCOIRS17:1;
			__BYTE	RCOIRS16:1;
#else
			__BYTE	RCOIRS16:1;
			__BYTE	RCOIRS17:1;
			__BYTE	RCOIRS18:1;
			__BYTE	RCOIRS19:1;
			__BYTE	RCOIRS20:1;
			__BYTE	RCOIRS21:1;
			__BYTE	RCOIRS22:1;
			__BYTE	RCOIRS23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIRS23:1;
			__BYTE	RCOIRS22:1;
			__BYTE	RCOIRS21:1;
			__BYTE	RCOIRS20:1;
			__BYTE	RCOIRS19:1;
			__BYTE	RCOIRS18:1;
			__BYTE	RCOIRS17:1;
			__BYTE	RCOIRS16:1;
#else
			__BYTE	RCOIRS16:1;
			__BYTE	RCOIRS17:1;
			__BYTE	RCOIRS18:1;
			__BYTE	RCOIRS19:1;
			__BYTE	RCOIRS20:1;
			__BYTE	RCOIRS21:1;
			__BYTE	RCOIRS22:1;
			__BYTE	RCOIRS23:1;
#endif
	} bitc;
} ADRCOIRS20STR;

__IO_EXTENDED __far	  ADRCOIRS20STR	IO_ADRCOIRS20;
#define	_adrcoirs20		(IO_ADRCOIRS20)
#define	ADRCOIRS20		(IO_ADRCOIRS20.byte)
#define	ADRCOIRS20_RCOIRS16  	(IO_ADRCOIRS20.bit.RCOIRS16)
#define	ADRCOIRS20_RCOIRS17  	(IO_ADRCOIRS20.bit.RCOIRS17)
#define	ADRCOIRS20_RCOIRS18  	(IO_ADRCOIRS20.bit.RCOIRS18)
#define	ADRCOIRS20_RCOIRS19  	(IO_ADRCOIRS20.bit.RCOIRS19)
#define	ADRCOIRS20_RCOIRS20  	(IO_ADRCOIRS20.bit.RCOIRS20)
#define	ADRCOIRS20_RCOIRS21  	(IO_ADRCOIRS20.bit.RCOIRS21)
#define	ADRCOIRS20_RCOIRS22  	(IO_ADRCOIRS20.bit.RCOIRS22)
#define	ADRCOIRS20_RCOIRS23  	(IO_ADRCOIRS20.bit.RCOIRS23)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC040, locate=0xE9554
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE9:1;
			__BYTE	RCOE9:1;
			__BYTE	RCOS9:2;
			__BYTE	RCOIE8:1;
			__BYTE	RCOE8:1;
			__BYTE	RCOS8:2;
#else
			__BYTE	RCOS8:2;
			__BYTE	RCOE8:1;
			__BYTE	RCOIE8:1;
			__BYTE	RCOS9:2;
			__BYTE	RCOE9:1;
			__BYTE	RCOIE9:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE9:1;
			__BYTE	RCOE9:1;
			__BYTE	RCOS91:1;
			__BYTE	RCOS90:1;
			__BYTE	RCOIE8:1;
			__BYTE	RCOE8:1;
			__BYTE	RCOS81:1;
			__BYTE	RCOS80:1;
#else
			__BYTE	RCOS80:1;
			__BYTE	RCOS81:1;
			__BYTE	RCOE8:1;
			__BYTE	RCOIE8:1;
			__BYTE	RCOS90:1;
			__BYTE	RCOS91:1;
			__BYTE	RCOE9:1;
			__BYTE	RCOIE9:1;
#endif
	} bitc;
} ADCC040STR;

__IO_EXTENDED __far	  ADCC040STR	IO_ADCC040;
#define	_adcc040		(IO_ADCC040)
#define	ADCC040		(IO_ADCC040.byte)
#define	ADCC040_RCOS8  	(IO_ADCC040.bit.RCOS8)
#define	ADCC040_RCOS80  	(IO_ADCC040.bitc.RCOS80)
#define	ADCC040_RCOS81  	(IO_ADCC040.bitc.RCOS81)
#define	ADCC040_RCOE8  	(IO_ADCC040.bit.RCOE8)
#define	ADCC040_RCOIE8  	(IO_ADCC040.bit.RCOIE8)
#define	ADCC040_RCOS9  	(IO_ADCC040.bit.RCOS9)
#define	ADCC040_RCOS90  	(IO_ADCC040.bitc.RCOS90)
#define	ADCC040_RCOS91  	(IO_ADCC040.bitc.RCOS91)
#define	ADCC040_RCOE9  	(IO_ADCC040.bit.RCOE9)
#define	ADCC040_RCOIE9  	(IO_ADCC040.bit.RCOIE9)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC060, locate=0xE9556
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE13:1;
			__BYTE	RCOE13:1;
			__BYTE	RCOS13:2;
			__BYTE	RCOIE12:1;
			__BYTE	RCOE12:1;
			__BYTE	RCOS12:2;
#else
			__BYTE	RCOS12:2;
			__BYTE	RCOE12:1;
			__BYTE	RCOIE12:1;
			__BYTE	RCOS13:2;
			__BYTE	RCOE13:1;
			__BYTE	RCOIE13:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE13:1;
			__BYTE	RCOE13:1;
			__BYTE	RCOS131:1;
			__BYTE	RCOS130:1;
			__BYTE	RCOIE12:1;
			__BYTE	RCOE12:1;
			__BYTE	RCOS121:1;
			__BYTE	RCOS120:1;
#else
			__BYTE	RCOS120:1;
			__BYTE	RCOS121:1;
			__BYTE	RCOE12:1;
			__BYTE	RCOIE12:1;
			__BYTE	RCOS130:1;
			__BYTE	RCOS131:1;
			__BYTE	RCOE13:1;
			__BYTE	RCOIE13:1;
#endif
	} bitc;
} ADCC060STR;

__IO_EXTENDED __far	  ADCC060STR	IO_ADCC060;
#define	_adcc060		(IO_ADCC060)
#define	ADCC060		(IO_ADCC060.byte)
#define	ADCC060_RCOS12  	(IO_ADCC060.bit.RCOS12)
#define	ADCC060_RCOS120  	(IO_ADCC060.bitc.RCOS120)
#define	ADCC060_RCOS121  	(IO_ADCC060.bitc.RCOS121)
#define	ADCC060_RCOE12  	(IO_ADCC060.bit.RCOE12)
#define	ADCC060_RCOIE12  	(IO_ADCC060.bit.RCOIE12)
#define	ADCC060_RCOS13  	(IO_ADCC060.bit.RCOS13)
#define	ADCC060_RCOS130  	(IO_ADCC060.bitc.RCOS130)
#define	ADCC060_RCOS131  	(IO_ADCC060.bitc.RCOS131)
#define	ADCC060_RCOE13  	(IO_ADCC060.bit.RCOE13)
#define	ADCC060_RCOIE13  	(IO_ADCC060.bit.RCOIE13)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC080, locate=0xE9558
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE17:1;
			__BYTE	RCOE17:1;
			__BYTE	RCOS17:2;
			__BYTE	RCOIE16:1;
			__BYTE	RCOE16:1;
			__BYTE	RCOS16:2;
#else
			__BYTE	RCOS16:2;
			__BYTE	RCOE16:1;
			__BYTE	RCOIE16:1;
			__BYTE	RCOS17:2;
			__BYTE	RCOE17:1;
			__BYTE	RCOIE17:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE17:1;
			__BYTE	RCOE17:1;
			__BYTE	RCOS171:1;
			__BYTE	RCOS170:1;
			__BYTE	RCOIE16:1;
			__BYTE	RCOE16:1;
			__BYTE	RCOS161:1;
			__BYTE	RCOS160:1;
#else
			__BYTE	RCOS160:1;
			__BYTE	RCOS161:1;
			__BYTE	RCOE16:1;
			__BYTE	RCOIE16:1;
			__BYTE	RCOS170:1;
			__BYTE	RCOS171:1;
			__BYTE	RCOE17:1;
			__BYTE	RCOIE17:1;
#endif
	} bitc;
} ADCC080STR;

__IO_EXTENDED __far	  ADCC080STR	IO_ADCC080;
#define	_adcc080		(IO_ADCC080)
#define	ADCC080		(IO_ADCC080.byte)
#define	ADCC080_RCOS16  	(IO_ADCC080.bit.RCOS16)
#define	ADCC080_RCOS160  	(IO_ADCC080.bitc.RCOS160)
#define	ADCC080_RCOS161  	(IO_ADCC080.bitc.RCOS161)
#define	ADCC080_RCOE16  	(IO_ADCC080.bit.RCOE16)
#define	ADCC080_RCOIE16  	(IO_ADCC080.bit.RCOIE16)
#define	ADCC080_RCOS17  	(IO_ADCC080.bit.RCOS17)
#define	ADCC080_RCOS170  	(IO_ADCC080.bitc.RCOS170)
#define	ADCC080_RCOS171  	(IO_ADCC080.bitc.RCOS171)
#define	ADCC080_RCOE17  	(IO_ADCC080.bit.RCOE17)
#define	ADCC080_RCOIE17  	(IO_ADCC080.bit.RCOIE17)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC090, locate=0xE9559
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE19:1;
			__BYTE	RCOE19:1;
			__BYTE	RCOS19:2;
			__BYTE	RCOIE18:1;
			__BYTE	RCOE18:1;
			__BYTE	RCOS18:2;
#else
			__BYTE	RCOS18:2;
			__BYTE	RCOE18:1;
			__BYTE	RCOIE18:1;
			__BYTE	RCOS19:2;
			__BYTE	RCOE19:1;
			__BYTE	RCOIE19:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE19:1;
			__BYTE	RCOE19:1;
			__BYTE	RCOS191:1;
			__BYTE	RCOS190:1;
			__BYTE	RCOIE18:1;
			__BYTE	RCOE18:1;
			__BYTE	RCOS181:1;
			__BYTE	RCOS180:1;
#else
			__BYTE	RCOS180:1;
			__BYTE	RCOS181:1;
			__BYTE	RCOE18:1;
			__BYTE	RCOIE18:1;
			__BYTE	RCOS190:1;
			__BYTE	RCOS191:1;
			__BYTE	RCOE19:1;
			__BYTE	RCOIE19:1;
#endif
	} bitc;
} ADCC090STR;

__IO_EXTENDED __far	  ADCC090STR	IO_ADCC090;
#define	_adcc090		(IO_ADCC090)
#define	ADCC090		(IO_ADCC090.byte)
#define	ADCC090_RCOS18  	(IO_ADCC090.bit.RCOS18)
#define	ADCC090_RCOS180  	(IO_ADCC090.bitc.RCOS180)
#define	ADCC090_RCOS181  	(IO_ADCC090.bitc.RCOS181)
#define	ADCC090_RCOE18  	(IO_ADCC090.bit.RCOE18)
#define	ADCC090_RCOIE18  	(IO_ADCC090.bit.RCOIE18)
#define	ADCC090_RCOS19  	(IO_ADCC090.bit.RCOS19)
#define	ADCC090_RCOS190  	(IO_ADCC090.bitc.RCOS190)
#define	ADCC090_RCOS191  	(IO_ADCC090.bitc.RCOS191)
#define	ADCC090_RCOE19  	(IO_ADCC090.bit.RCOE19)
#define	ADCC090_RCOIE19  	(IO_ADCC090.bit.RCOIE19)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC100, locate=0xE955A
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE21:1;
			__BYTE	RCOE21:1;
			__BYTE	RCOS21:2;
			__BYTE	RCOIE20:1;
			__BYTE	RCOE20:1;
			__BYTE	RCOS20:2;
#else
			__BYTE	RCOS20:2;
			__BYTE	RCOE20:1;
			__BYTE	RCOIE20:1;
			__BYTE	RCOS21:2;
			__BYTE	RCOE21:1;
			__BYTE	RCOIE21:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE21:1;
			__BYTE	RCOE21:1;
			__BYTE	RCOS211:1;
			__BYTE	RCOS210:1;
			__BYTE	RCOIE20:1;
			__BYTE	RCOE20:1;
			__BYTE	RCOS201:1;
			__BYTE	RCOS200:1;
#else
			__BYTE	RCOS200:1;
			__BYTE	RCOS201:1;
			__BYTE	RCOE20:1;
			__BYTE	RCOIE20:1;
			__BYTE	RCOS210:1;
			__BYTE	RCOS211:1;
			__BYTE	RCOE21:1;
			__BYTE	RCOIE21:1;
#endif
	} bitc;
} ADCC100STR;

__IO_EXTENDED __far	  ADCC100STR	IO_ADCC100;
#define	_adcc100		(IO_ADCC100)
#define	ADCC100		(IO_ADCC100.byte)
#define	ADCC100_RCOS20  	(IO_ADCC100.bit.RCOS20)
#define	ADCC100_RCOS200  	(IO_ADCC100.bitc.RCOS200)
#define	ADCC100_RCOS201  	(IO_ADCC100.bitc.RCOS201)
#define	ADCC100_RCOE20  	(IO_ADCC100.bit.RCOE20)
#define	ADCC100_RCOIE20  	(IO_ADCC100.bit.RCOIE20)
#define	ADCC100_RCOS21  	(IO_ADCC100.bit.RCOS21)
#define	ADCC100_RCOS210  	(IO_ADCC100.bitc.RCOS210)
#define	ADCC100_RCOS211  	(IO_ADCC100.bitc.RCOS211)
#define	ADCC100_RCOE21  	(IO_ADCC100.bit.RCOE21)
#define	ADCC100_RCOIE21  	(IO_ADCC100.bit.RCOIE21)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADCC110, locate=0xE955B
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE23:1;
			__BYTE	RCOE23:1;
			__BYTE	RCOS23:2;
			__BYTE	RCOIE22:1;
			__BYTE	RCOE22:1;
			__BYTE	RCOS22:2;
#else
			__BYTE	RCOS22:2;
			__BYTE	RCOE22:1;
			__BYTE	RCOIE22:1;
			__BYTE	RCOS23:2;
			__BYTE	RCOE23:1;
			__BYTE	RCOIE23:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	RCOIE23:1;
			__BYTE	RCOE23:1;
			__BYTE	RCOS231:1;
			__BYTE	RCOS230:1;
			__BYTE	RCOIE22:1;
			__BYTE	RCOE22:1;
			__BYTE	RCOS221:1;
			__BYTE	RCOS220:1;
#else
			__BYTE	RCOS220:1;
			__BYTE	RCOS221:1;
			__BYTE	RCOE22:1;
			__BYTE	RCOIE22:1;
			__BYTE	RCOS230:1;
			__BYTE	RCOS231:1;
			__BYTE	RCOE23:1;
			__BYTE	RCOIE23:1;
#endif
	} bitc;
} ADCC110STR;

__IO_EXTENDED __far	  ADCC110STR	IO_ADCC110;
#define	_adcc110		(IO_ADCC110)
#define	ADCC110		(IO_ADCC110.byte)
#define	ADCC110_RCOS22  	(IO_ADCC110.bit.RCOS22)
#define	ADCC110_RCOS220  	(IO_ADCC110.bitc.RCOS220)
#define	ADCC110_RCOS221  	(IO_ADCC110.bitc.RCOS221)
#define	ADCC110_RCOE22  	(IO_ADCC110.bit.RCOE22)
#define	ADCC110_RCOIE22  	(IO_ADCC110.bit.RCOIE22)
#define	ADCC110_RCOS23  	(IO_ADCC110.bit.RCOS23)
#define	ADCC110_RCOS230  	(IO_ADCC110.bitc.RCOS230)
#define	ADCC110_RCOS231  	(IO_ADCC110.bitc.RCOS231)
#define	ADCC110_RCOE23  	(IO_ADCC110.bit.RCOE23)
#define	ADCC110_RCOIE23  	(IO_ADCC110.bit.RCOIE23)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD80, locate=0xE95A0
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD80;
#define	_adpctprd80		(IO_ADPCTPRD80)
#define	ADPCTPRD80	(_adpctprd80)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD80, locate=0xE95A1
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD80;
#define	_adpctnrd80		(IO_ADPCTNRD80)
#define	ADPCTNRD80	(_adpctnrd80)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD90, locate=0xE95A2
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD90;
#define	_adpctprd90		(IO_ADPCTPRD90)
#define	ADPCTPRD90	(_adpctprd90)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD90, locate=0xE95A3
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD90;
#define	_adpctnrd90		(IO_ADPCTNRD90)
#define	ADPCTNRD90	(_adpctnrd90)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD120, locate=0xE95A8
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD120;
#define	_adpctprd120		(IO_ADPCTPRD120)
#define	ADPCTPRD120	(_adpctprd120)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD120, locate=0xE95A9
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD120;
#define	_adpctnrd120		(IO_ADPCTNRD120)
#define	ADPCTNRD120	(_adpctnrd120)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD130, locate=0xE95AA
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD130;
#define	_adpctprd130		(IO_ADPCTPRD130)
#define	ADPCTPRD130	(_adpctprd130)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD130, locate=0xE95AB
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD130;
#define	_adpctnrd130		(IO_ADPCTNRD130)
#define	ADPCTNRD130	(_adpctnrd130)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD160, locate=0xE95B0
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD160;
#define	_adpctprd160		(IO_ADPCTPRD160)
#define	ADPCTPRD160	(_adpctprd160)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD160, locate=0xE95B1
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD160;
#define	_adpctnrd160		(IO_ADPCTNRD160)
#define	ADPCTNRD160	(_adpctnrd160)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD170, locate=0xE95B2
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD170;
#define	_adpctprd170		(IO_ADPCTPRD170)
#define	ADPCTPRD170	(_adpctprd170)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD170, locate=0xE95B3
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD170;
#define	_adpctnrd170		(IO_ADPCTNRD170)
#define	ADPCTNRD170	(_adpctnrd170)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD180, locate=0xE95B4
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD180;
#define	_adpctprd180		(IO_ADPCTPRD180)
#define	ADPCTPRD180	(_adpctprd180)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD180, locate=0xE95B5
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD180;
#define	_adpctnrd180		(IO_ADPCTNRD180)
#define	ADPCTNRD180	(_adpctnrd180)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD190, locate=0xE95B6
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD190;
#define	_adpctprd190		(IO_ADPCTPRD190)
#define	ADPCTPRD190	(_adpctprd190)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD190, locate=0xE95B7
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD190;
#define	_adpctnrd190		(IO_ADPCTNRD190)
#define	ADPCTNRD190	(_adpctnrd190)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD200, locate=0xE95B8
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD200;
#define	_adpctprd200		(IO_ADPCTPRD200)
#define	ADPCTPRD200	(_adpctprd200)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD200, locate=0xE95B9
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD200;
#define	_adpctnrd200		(IO_ADPCTNRD200)
#define	ADPCTNRD200	(_adpctnrd200)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD210, locate=0xE95BA
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD210;
#define	_adpctprd210		(IO_ADPCTPRD210)
#define	ADPCTPRD210	(_adpctprd210)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD210, locate=0xE95BB
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD210;
#define	_adpctnrd210		(IO_ADPCTNRD210)
#define	ADPCTNRD210	(_adpctnrd210)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD220, locate=0xE95BC
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD220;
#define	_adpctprd220		(IO_ADPCTPRD220)
#define	ADPCTPRD220	(_adpctprd220)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD220, locate=0xE95BD
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD220;
#define	_adpctnrd220		(IO_ADPCTNRD220)
#define	ADPCTNRD220	(_adpctnrd220)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPRD230, locate=0xE95BE
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTPRD230;
#define	_adpctprd230		(IO_ADPCTPRD230)
#define	ADPCTPRD230	(_adpctprd230)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNRD230, locate=0xE95BF
#endif

__IO_EXTENDED __far	__BYTE	IO_ADPCTNRD230;
#define	_adpctnrd230		(IO_ADPCTNRD230)
#define	ADPCTNRD230	(_adpctnrd230)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT80, locate=0xE95E0
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT80;
#define	_adpctpct80		(IO_ADPCTPCT80)
#define	ADPCTPCT80	(_adpctpct80)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT80, locate=0xE95E1
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT80;
#define	_adpctnct80		(IO_ADPCTNCT80)
#define	ADPCTNCT80	(_adpctnct80)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT90, locate=0xE95E2
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT90;
#define	_adpctpct90		(IO_ADPCTPCT90)
#define	ADPCTPCT90	(_adpctpct90)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT90, locate=0xE95E3
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT90;
#define	_adpctnct90		(IO_ADPCTNCT90)
#define	ADPCTNCT90	(_adpctnct90)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT120, locate=0xE95E8
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT120;
#define	_adpctpct120		(IO_ADPCTPCT120)
#define	ADPCTPCT120	(_adpctpct120)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT120, locate=0xE95E9
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT120;
#define	_adpctnct120		(IO_ADPCTNCT120)
#define	ADPCTNCT120	(_adpctnct120)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT130, locate=0xE95EA
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT130;
#define	_adpctpct130		(IO_ADPCTPCT130)
#define	ADPCTPCT130	(_adpctpct130)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT130, locate=0xE95EB
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT130;
#define	_adpctnct130		(IO_ADPCTNCT130)
#define	ADPCTNCT130	(_adpctnct130)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT160, locate=0xE95F0
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT160;
#define	_adpctpct160		(IO_ADPCTPCT160)
#define	ADPCTPCT160	(_adpctpct160)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT160, locate=0xE95F1
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT160;
#define	_adpctnct160		(IO_ADPCTNCT160)
#define	ADPCTNCT160	(_adpctnct160)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT170, locate=0xE95F2
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT170;
#define	_adpctpct170		(IO_ADPCTPCT170)
#define	ADPCTPCT170	(_adpctpct170)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT170, locate=0xE95F3
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT170;
#define	_adpctnct170		(IO_ADPCTNCT170)
#define	ADPCTNCT170	(_adpctnct170)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT180, locate=0xE95F4
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT180;
#define	_adpctpct180		(IO_ADPCTPCT180)
#define	ADPCTPCT180	(_adpctpct180)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT180, locate=0xE95F5
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT180;
#define	_adpctnct180		(IO_ADPCTNCT180)
#define	ADPCTNCT180	(_adpctnct180)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT190, locate=0xE95F6
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT190;
#define	_adpctpct190		(IO_ADPCTPCT190)
#define	ADPCTPCT190	(_adpctpct190)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT190, locate=0xE95F7
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT190;
#define	_adpctnct190		(IO_ADPCTNCT190)
#define	ADPCTNCT190	(_adpctnct190)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT200, locate=0xE95F8
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT200;
#define	_adpctpct200		(IO_ADPCTPCT200)
#define	ADPCTPCT200	(_adpctpct200)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT200, locate=0xE95F9
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT200;
#define	_adpctnct200		(IO_ADPCTNCT200)
#define	ADPCTNCT200	(_adpctnct200)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT210, locate=0xE95FA
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT210;
#define	_adpctpct210		(IO_ADPCTPCT210)
#define	ADPCTPCT210	(_adpctpct210)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT210, locate=0xE95FB
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT210;
#define	_adpctnct210		(IO_ADPCTNCT210)
#define	ADPCTNCT210	(_adpctnct210)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT220, locate=0xE95FC
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT220;
#define	_adpctpct220		(IO_ADPCTPCT220)
#define	ADPCTPCT220	(_adpctpct220)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT220, locate=0xE95FD
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT220;
#define	_adpctnct220		(IO_ADPCTNCT220)
#define	ADPCTNCT220	(_adpctnct220)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTPCT230, locate=0xE95FE
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTPCT230;
#define	_adpctpct230		(IO_ADPCTPCT230)
#define	ADPCTPCT230	(_adpctpct230)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_ADPCTNCT230, locate=0xE95FF
#endif

__IO_EXTENDED __far	const __BYTE	IO_ADPCTNCT230;
#define	_adpctnct230		(IO_ADPCTNCT230)
#define	ADPCTNCT230	(_adpctnct230)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EFER0, locate=0xE97C0
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	INTLBEN:1;
			__WORD	BRGR:1;
			__WORD	FIDPE:1;
			__WORD	DBE:1;
			__WORD	FIDE:1;
			__WORD	LBL2:1;
			__WORD	LBDSF:1;
			__WORD	OSDE:1;
			__WORD	DTSTART:1;
			__WORD	RSTRFM:1;
			__WORD	LBEDGE:1;
			__WORD	ABRE:1;
			__WORD	ENRXHR:1;
			__WORD	ENTXHR:1;
#else
			__WORD	ENTXHR:1;
			__WORD	ENRXHR:1;
			__WORD	ABRE:1;
			__WORD	LBEDGE:1;
			__WORD	RSTRFM:1;
			__WORD	DTSTART:1;
			__WORD	OSDE:1;
			__WORD	LBDSF:1;
			__WORD	LBL2:1;
			__WORD	FIDE:1;
			__WORD	DBE:1;
			__WORD	FIDPE:1;
			__WORD	BRGR:1;
			__WORD	INTLBEN:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	INTLBEN:1;
			__WORD	BRGR:1;
			__WORD	FIDPE:1;
			__WORD	DBE:1;
			__WORD	FIDE:1;
			__WORD	LBL2:1;
			__WORD	LBDSF:1;
			__WORD	OSDE:1;
			__WORD	DTSTART:1;
			__WORD	RSTRFM:1;
			__WORD	LBEDGE:1;
			__WORD	ABRE:1;
			__WORD	ENRXHR:1;
			__WORD	ENTXHR:1;
#else
			__WORD	ENTXHR:1;
			__WORD	ENRXHR:1;
			__WORD	ABRE:1;
			__WORD	LBEDGE:1;
			__WORD	RSTRFM:1;
			__WORD	DTSTART:1;
			__WORD	OSDE:1;
			__WORD	LBDSF:1;
			__WORD	LBL2:1;
			__WORD	FIDE:1;
			__WORD	DBE:1;
			__WORD	FIDPE:1;
			__WORD	BRGR:1;
			__WORD	INTLBEN:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EFER0STR;

__IO_EXTENDED __far	  EFER0STR	IO_EFER0;
#define	_efer0		(IO_EFER0)
#define	EFER0		(IO_EFER0.word)
#define	EFER0_ENTXHR  	(IO_EFER0.bit.ENTXHR)
#define	EFER0_ENRXHR  	(IO_EFER0.bit.ENRXHR)
#define	EFER0_ABRE  	(IO_EFER0.bit.ABRE)
#define	EFER0_LBEDGE  	(IO_EFER0.bit.LBEDGE)
#define	EFER0_RSTRFM  	(IO_EFER0.bit.RSTRFM)
#define	EFER0_DTSTART  	(IO_EFER0.bit.DTSTART)
#define	EFER0_OSDE  	(IO_EFER0.bit.OSDE)
#define	EFER0_LBDSF  	(IO_EFER0.bit.LBDSF)
#define	EFER0_LBL2  	(IO_EFER0.bit.LBL2)
#define	EFER0_FIDE  	(IO_EFER0.bit.FIDE)
#define	EFER0_DBE  	(IO_EFER0.bit.DBE)
#define	EFER0_FIDPE  	(IO_EFER0.bit.FIDPE)
#define	EFER0_BRGR  	(IO_EFER0.bit.BRGR)
#define	EFER0_INTLBEN  	(IO_EFER0.bit.INTLBEN)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_SFTR0, locate=0xE97C6
#endif

__IO_EXTENDED __far	__WORD	IO_SFTR0;
#define	_sftr0		(IO_SFTR0)
#define	SFTR0	(_sftr0)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EIER0, locate=0xE97C8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bitc;
} EIER0STR;

__IO_EXTENDED __far	  EIER0STR	IO_EIER0;
#define	_eier0		(IO_EIER0)
#define	EIER0		(IO_EIER0.byte)
#define	EIER0_LBSOIE  	(IO_EIER0.bit.LBSOIE)
#define	EIER0_BUSERRIE  	(IO_EIER0.bit.BUSERRIE)
#define	EIER0_PEFRDIE  	(IO_EIER0.bit.PEFRDIE)
#define	EIER0_TXHDIE  	(IO_EIER0.bit.TXHDIE)
#define	EIER0_RXHDIE  	(IO_EIER0.bit.RXHDIE)
#define	EIER0_SYNFEIE  	(IO_EIER0.bit.SYNFEIE)
#define	EIER0_RXFIE  	(IO_EIER0.bit.RXFIE)
#define	EIER0_TXFIE  	(IO_EIER0.bit.TXFIE)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EFER1, locate=0xE97D0
#endif

typedef union {
	__WORD	word;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	INTLBEN:1;
			__WORD	BRGR:1;
			__WORD	FIDPE:1;
			__WORD	DBE:1;
			__WORD	FIDE:1;
			__WORD	LBL2:1;
			__WORD	LBDSF:1;
			__WORD	OSDE:1;
			__WORD	DTSTART:1;
			__WORD	RSTRFM:1;
			__WORD	LBEDGE:1;
			__WORD	ABRE:1;
			__WORD	ENRXHR:1;
			__WORD	ENTXHR:1;
#else
			__WORD	ENTXHR:1;
			__WORD	ENRXHR:1;
			__WORD	ABRE:1;
			__WORD	LBEDGE:1;
			__WORD	RSTRFM:1;
			__WORD	DTSTART:1;
			__WORD	OSDE:1;
			__WORD	LBDSF:1;
			__WORD	LBL2:1;
			__WORD	FIDE:1;
			__WORD	DBE:1;
			__WORD	FIDPE:1;
			__WORD	BRGR:1;
			__WORD	INTLBEN:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__WORD	RESV15:1;
			__WORD	RESV14:1;
			__WORD	INTLBEN:1;
			__WORD	BRGR:1;
			__WORD	FIDPE:1;
			__WORD	DBE:1;
			__WORD	FIDE:1;
			__WORD	LBL2:1;
			__WORD	LBDSF:1;
			__WORD	OSDE:1;
			__WORD	DTSTART:1;
			__WORD	RSTRFM:1;
			__WORD	LBEDGE:1;
			__WORD	ABRE:1;
			__WORD	ENRXHR:1;
			__WORD	ENTXHR:1;
#else
			__WORD	ENTXHR:1;
			__WORD	ENRXHR:1;
			__WORD	ABRE:1;
			__WORD	LBEDGE:1;
			__WORD	RSTRFM:1;
			__WORD	DTSTART:1;
			__WORD	OSDE:1;
			__WORD	LBDSF:1;
			__WORD	LBL2:1;
			__WORD	FIDE:1;
			__WORD	DBE:1;
			__WORD	FIDPE:1;
			__WORD	BRGR:1;
			__WORD	INTLBEN:1;
			__WORD	RESV14:1;
			__WORD	RESV15:1;
#endif
	} bitc;
} EFER1STR;

__IO_EXTENDED __far	  EFER1STR	IO_EFER1;
#define	_efer1		(IO_EFER1)
#define	EFER1		(IO_EFER1.word)
#define	EFER1_ENTXHR  	(IO_EFER1.bit.ENTXHR)
#define	EFER1_ENRXHR  	(IO_EFER1.bit.ENRXHR)
#define	EFER1_ABRE  	(IO_EFER1.bit.ABRE)
#define	EFER1_LBEDGE  	(IO_EFER1.bit.LBEDGE)
#define	EFER1_RSTRFM  	(IO_EFER1.bit.RSTRFM)
#define	EFER1_DTSTART  	(IO_EFER1.bit.DTSTART)
#define	EFER1_OSDE  	(IO_EFER1.bit.OSDE)
#define	EFER1_LBDSF  	(IO_EFER1.bit.LBDSF)
#define	EFER1_LBL2  	(IO_EFER1.bit.LBL2)
#define	EFER1_FIDE  	(IO_EFER1.bit.FIDE)
#define	EFER1_DBE  	(IO_EFER1.bit.DBE)
#define	EFER1_FIDPE  	(IO_EFER1.bit.FIDPE)
#define	EFER1_BRGR  	(IO_EFER1.bit.BRGR)
#define	EFER1_INTLBEN  	(IO_EFER1.bit.INTLBEN)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_EIER1, locate=0xE97D8
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	TXFIE:1;
			__BYTE	RXFIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	LBSOIE:1;
#else
			__BYTE	LBSOIE:1;
			__BYTE	BUSERRIE:1;
			__BYTE	PEFRDIE:1;
			__BYTE	TXHDIE:1;
			__BYTE	RXHDIE:1;
			__BYTE	SYNFEIE:1;
			__BYTE	RXFIE:1;
			__BYTE	TXFIE:1;
#endif
	} bitc;
} EIER1STR;

__IO_EXTENDED __far	  EIER1STR	IO_EIER1;
#define	_eier1		(IO_EIER1)
#define	EIER1		(IO_EIER1.byte)
#define	EIER1_LBSOIE  	(IO_EIER1.bit.LBSOIE)
#define	EIER1_BUSERRIE  	(IO_EIER1.bit.BUSERRIE)
#define	EIER1_PEFRDIE  	(IO_EIER1.bit.PEFRDIE)
#define	EIER1_TXHDIE  	(IO_EIER1.bit.TXHDIE)
#define	EIER1_RXHDIE  	(IO_EIER1.bit.RXHDIE)
#define	EIER1_SYNFEIE  	(IO_EIER1.bit.SYNFEIE)
#define	EIER1_RXFIE  	(IO_EIER1.bit.RXFIE)
#define	EIER1_TXFIE  	(IO_EIER1.bit.TXFIE)

#ifdef __IO_DEFINE
#pragma segment FAR_DATA=IO_PDCR08, locate=0xE9898
#endif

typedef union {
	__BYTE	byte;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PD7:1;
			__BYTE	PD6:1;
			__BYTE	PD5:1;
			__BYTE	PD4:1;
			__BYTE	PD3:1;
			__BYTE	PD2:1;
			__BYTE	PD1:1;
			__BYTE	PD0:1;
#else
			__BYTE	PD0:1;
			__BYTE	PD1:1;
			__BYTE	PD2:1;
			__BYTE	PD3:1;
			__BYTE	PD4:1;
			__BYTE	PD5:1;
			__BYTE	PD6:1;
			__BYTE	PD7:1;
#endif
	} bit;
	struct {
#ifdef __BITFIELD_ORDER_MSB__
			__BYTE	PD7:1;
			__BYTE	PD6:1;
			__BYTE	PD5:1;
			__BYTE	PD4:1;
			__BYTE	PD3:1;
			__BYTE	PD2:1;
			__BYTE	PD1:1;
			__BYTE	PD0:1;
#else
			__BYTE	PD0:1;
			__BYTE	PD1:1;
			__BYTE	PD2:1;
			__BYTE	PD3:1;
			__BYTE	PD4:1;
			__BYTE	PD5:1;
			__BYTE	PD6:1;
			__BYTE	PD7:1;
#endif
	} bitc;
} PDCR08STR;

__IO_EXTENDED __far	  PDCR08STR	IO_PDCR08;
#define	_pdcr08		(IO_PDCR08)
#define	PDCR08		(IO_PDCR08.byte)
#define	PDCR08_PD0  	(IO_PDCR08.bit.PD0)
#define	PDCR08_PD1  	(IO_PDCR08.bit.PD1)
#define	PDCR08_PD2  	(IO_PDCR08.bit.PD2)
#define	PDCR08_PD3  	(IO_PDCR08.bit.PD3)
#define	PDCR08_PD4  	(IO_PDCR08.bit.PD4)
#define	PDCR08_PD5  	(IO_PDCR08.bit.PD5)
#define	PDCR08_PD6  	(IO_PDCR08.bit.PD6)
#define	PDCR08_PD7  	(IO_PDCR08.bit.PD7)
