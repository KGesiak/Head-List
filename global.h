#pragma once
typedef struct
{
	int nKey;
	int* pTab;
} ListInfo;
int compareItem( const void* inf1, const void* inf2 );
void freeMem( const void* item );
void printitem( const void* item );
#define LISTINFO ListInfo