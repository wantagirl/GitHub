#ifndef _DEFS_H
#define _DEFS_H

//typedefs
typedef char 			CHAR;
typedef char 			INT8;
typedef unsigned char 	UCHAR;
typedef unsigned char 	UINT8;
typedef unsigned char 	BYTE;
typedef short			INT16;
typedef short			SHORT;
typedef unsigned short	UINT16;
typedef unsigned short 	USHORT;
typedef int 			INT32;
typedef unsigned int 	UINT32;

typedef enum
{
	START_BOOL,	//invalid first
	FALSE,
	TRUE,
	END_BOOL
}BOOL;

typedef enum
{
	START_STATUS,	//invalid first
	FAILED,
	SUCCESS,
	END_STATUS
}STATUS;

typedef enum
{
	START_TYPE,
	NULL_T,
	LISTHEAD,
	LISTTAIL,
	END_TYPE
}TYPES;

#endif