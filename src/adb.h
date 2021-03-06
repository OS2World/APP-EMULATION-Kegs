/****************************************************************/
/*			Apple IIgs emulator			*/
/*			Copyright 1996 Kent Dickey		*/
/*								*/
/*	This code may not be used in a commercial product	*/
/*	without prior written permission of the author.		*/
/*								*/
/*	You may freely distribute this code.			*/ 
/*								*/
/*	You can contact the author at kentd@cup.hp.com.		*/
/*	HP has nothing to do with this software.		*/
/****************************************************************/

const char rcsid_adb_h[] = "@(#)$Header: adb.h,v 1.3 97/04/28 22:53:09 kentd Exp $";

#include "defc.h"

const int a2_key_to_ascii_raw[][4] = {
	{ 0x35,	0x1b,	0x1b,	-1 },	/* Esc */
	{ 0x7a,	0x107a,	0x107a,	-1 },	/* F1 */
	{ 0x7b,	0x107b,	0x107b,	-1 },	/* F2 */
	{ 0x63,	0x1063,	0x1063,	-1 },	/* F3 */
	{ 0x76,	0x1076,	0x1076,	-1 },	/* F4 */
	{ 0x60,	0x1060,	0x1060,	-1 },	/* F5 */
	{ 0x61,	0x1061,	0x1061,	-1 },	/* F6 */
	{ 0x62,	0x1062,	0x1062,	-1 },	/* F7 */
	{ 0x64,	0x1064,	0x1064,	-1 },	/* F8 */
	{ 0x65,	0x1065,	0x1065,	-1 },	/* F9 */
	{ 0x6d,	0x106d,	0x106d,	-1 },	/* F10 */
	{ 0x67,	0x1067,	0x1067,	-1 },	/* F11 */
	{ 0x6f,	0x106f,	0x106f,	-1 },	/* F12 */
	{ 0x69,	0x1069,	0x1069,	-1 },	/* F13 */
	{ 0x6b,	0x106b,	0x106b,	-1 },	/* F14 */
	{ 0x71,	0x1071,	0x1071,	-1 },	/* F15 */
	{ 0x7f, -1,	-1,	-1 },	/* Reset */
	{ 0x32,	'`',	'~',	-1 },
	{ 0x12,	'1',	'!',	-1 },
	{ 0x13,	'2',	'@',	0x80 },
	{ 0x14,	'3',	'#',	-1 },
	{ 0x15,	'4',	'$',	-1 },
	{ 0x17,	'5',	'%',	-1 },
	{ 0x16,	'6',	'^',	0x1e },
	{ 0x1a,	'7',	'&',	-1 },
	{ 0x1c,	'8',	'*',	-1 },
	{ 0x19,	'9',	'(',	-1 },
	{ 0x1d,	'0',	')',	-1 },
	{ 0x1b,	'-',	'_',	0 },
	{ 0x18,	'=',	'+',	-1 },
	{ 0x33,	0x7f,	0x7f,	-1 },	/* Delete */
	{ 0x72,	0x1072,	0x1072,	-1 },	/* Help, insert */
	{ 0x73,	0x1073,	0x1073,	-1 },	/* Home */
	{ 0x74,	0x1074,	0x1074,	-1 },	/* Page up */
	{ 0x47,	0x1018,	0x1018,	-1 },	/* keypad Clear */
	{ 0x51,	0x103d,	0x103d,	-1 },	/* keypad = */
	{ 0x4b,	0x102f,	0x102f,	-1 },	/* keypad / */
	{ 0x43,	0x102a,	0x102a,	-1 },	/* keypad * */

	{ 0x30,	0x09,	0x09,	-1 },	/* tab */
	{ 0x0c,	'q',	'Q',	0 },
	{ 0x0d,	'w',	'W',	0 },
	{ 0x0e,	'e',	'E',	0 },
	{ 0x0f,	'r',	'R',	0 },
	{ 0x11,	't',	'T',	0 },
	{ 0x10,	'y',	'Y',	0 },
	{ 0x20,	'u',	'U',	0 },
	{ 0x22,	'i',	'I',	0 },
	{ 0x1f,	'o',	'O',	0 },
	{ 0x23,	'p',	'P',	0 },
	{ 0x21,	'[',	'{',	0 },
	{ 0x1e,	']',	'}',	0 },
	{ 0x2a,	0x5c,	'|',	0 },	/* \, | */
	{ 0x75,	0x1075,	0x1075,	-1 },	/* keypad delete */
	{ 0x77,	0x1077,	0x1077,	-1 },	/* keypad end */
	{ 0x79,	0x1079,	0x1079,	-1 },	/* keypad page down */
	{ 0x59,	0x1037, 0x1037,	-1 },	/* keypad 7 */
	{ 0x5b,	0x1038,	0x1038,	-1 },	/* keypad 8 */
	{ 0x5c,	0x1039,	0x1039,	-1 },	/* keypad 9 */
	{ 0x4e,	0x102d,	0x102d,	-1 },	/* keypad - */

	{ 0x39,	0x0400,	0x0400,	-1 },	/* caps lock */
	{ 0x00,	'a',	'A',	0 },
	{ 0x01,	's',	'S',	0 },
	{ 0x02,	'd',	'D',	0 },
	{ 0x03,	'f',	'F',	0 },
	{ 0x05,	'g',	'G',	0 },
	{ 0x04,	'h',	'H',	0 },
	{ 0x26,	'j',	'J',	0 },
	{ 0x28,	'k',	'K',	0 },
	{ 0x25,	'l',	'L',	0 },
	{ 0x29,	';',	':',	-1 },
	{ 0x27,	0x27,	'"',	-1 },	/* single quote */
	{ 0x24,	0x0d,	0x0d,	-1 },	/* return */
	{ 0x56,	0x1034,	0x1034,	-1 },	/* keypad 4 */
	{ 0x57,	0x1035, 0x1035, -1 },	/* keypad 5 */
	{ 0x58,	0x1036, 0x1036, -1 },	/* keypad 6 */
	{ 0x45,	0x102b, 0x102b, -1 },	/* keypad + */

	{ 0x38,	0x0100,	0x0100, -1 },	/* shift */
	{ 0x06,	'z',	'Z',	0 },
	{ 0x07,	'x',	'X',	0 },
	{ 0x08,	'c',	'C',	0 },
	{ 0x09,	'v',	'V',	0 },
	{ 0x0b,	'b',	'B',	0 },
	{ 0x2d,	'n',	'N',	0 },
	{ 0x2e,	'm',	'M',	0 },
	{ 0x2b,	',',	'<',	-1 },
	{ 0x2f,	'.',	'>',	-1 },
	{ 0x2c,	'/',	'?',	0x7f },
	{ 0x3e,	0x0b,	0x0b,	-1 },	/* up arrow */
	{ 0x53,	0x1031,	0x1031,	-1 },	/* keypad 1 */
	{ 0x54,	0x1032,	0x1032,	-1 },	/* keypad 2 */
	{ 0x55,	0x1033,	0x1033,	-1 },	/* keypad 3 */

	{ 0x36,	0x0200,	0x0200,	-1 },	/* control */
	{ 0x3a,	0x4000,	0x4000,	-1 },	/* Option */
	{ 0x37,	0x8000,	0x8000,	-1 },	/* Command */
	{ 0x31,	' ',	' ',	-1 },
	{ 0x3b,	0x08,	0x08,	-1 },	/* left */
	{ 0x3d,	0x0a,	0x0a,	-1 },	/* down */
	{ 0x3c,	0x15,	0x15,	-1 },	/* right */
	{ 0x52,	0x1030,	0x1030,	-1 },	/* keypad 0 */
	{ 0x41,	0x102e,	0x102e,	-1 },	/* keypad . */
	{ 0x4c,	0x100d,	0x100d,	-1 },	/* keypad enter */
	{ -1,	-1,	-1 }
};
