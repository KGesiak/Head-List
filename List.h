#pragma once
#include "global.h"
typedef struct tagListItem
{
	LISTINFO* pInfo;
	tagListItem* pNext;
} ListItem;
ListItem* CreateList(); 
int InsertFront( ListItem* pList,LISTINFO* pInfo);
int Insert( ListItem* pAfter,LISTINFO* pInfo);
LISTINFO* RemoveFront( ListItem* pList );
LISTINFO* Remove( ListItem* pAfter );
LISTINFO* Front( ListItem* pList );
int IsEmpty( ListItem* pList );
void ClearList( ListItem* pList, void( __cdecl* freeMem )( const void* ) );
void RemoveList( ListItem* pList, void( __cdecl* freeMem )( const void* ) );
void SortList( ListItem* pList, int( __cdecl* compareItem )( const void*, const void* ) );
ListItem* Find( ListItem* pList, const void* info,ListItem** pPrev, int( __cdecl* compareItem )( const void*, const void* ) );
void PrintTab( ListItem* pList, void( __cdecl* printitem )( const void* ) );