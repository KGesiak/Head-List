#include "List.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

ListItem* CreateList()
{
	ListItem* temp = ( ListItem* )calloc( 1,sizeof( ListItem ) );
	temp->pNext = NULL;
	return temp;
}
int InsertFront( ListItem* pList,LISTINFO* pInfo)
{
	return Insert ( pList, pInfo );
}
int Insert( ListItem* pAfter,LISTINFO* pInfo)
{
	ListItem* temp = pAfter->pNext;
	pAfter->pNext = ( ListItem* )calloc( 1,sizeof( ListItem ) );
	if( !pAfter->pNext ) return 0;
	pAfter->pNext->pInfo = pInfo;
	pAfter->pNext->pNext = temp;
	return 1;
}
LISTINFO* RemoveFront( ListItem* pList )
{
	if( IsEmpty( pList ) ) 
	{
		perror( "List is empty!" );
		return NULL;
	}
	return Remove( pList );
}
LISTINFO* Remove( ListItem* pAfter )
{
	if( IsEmpty( pAfter ) )
	{
		perror( "No element to remove after the given one!" );
		return NULL;
	}
	LISTINFO* temp = pAfter->pNext->pInfo;
	pAfter->pNext = pAfter->pNext->pNext;
	return temp;

}
LISTINFO* Front( ListItem* pList )
{
	if ( IsEmpty( pList ) )
	{
		perror( "ERROR in Front: List is empty!" );
		return NULL;
	}
	return pList->pNext->pInfo;
}
int IsEmpty( ListItem* pList )
{
	return !pList->pNext;

}
void ClearList( ListItem* pList, void( __cdecl* freeMem )( const void* ) )
{
	while( !IsEmpty( pList ) )
	{
		ListItem* temp = pList->pNext;
		freeMem( RemoveFront( pList ) );
		free( temp );
	}
}
void RemoveList( ListItem* pList, void( __cdecl* freeMem )( const void* ) )
{
	ClearList ( pList, freeMem );
	pList = NULL;
}

void SortList( ListItem* pList, int( __cdecl* compareItem )( const void*, const void* ) )
{

	if ( IsEmpty( pList ) )
	{
		perror( "ERROR in SortList: List is empty!" );
		return;
	}
	ListItem* pFirst = pList;
	ListItem* pMin = pList;

	while ( pFirst->pNext )
	{
		ListItem* pCurr = pFirst->pNext;
		while ( pCurr->pNext )
		{
			if( compareItem( pMin->pNext->pInfo,pCurr->pNext->pInfo ) == 1 ) pMin = pCurr;
			pCurr = pCurr->pNext;
		}
		if ( pMin != pFirst )
		{
			pCurr = pMin->pNext->pNext;
			pMin->pNext->pNext = pFirst->pNext;
			pFirst->pNext = pMin->pNext;
			pMin->pNext = pCurr;
		}
		pFirst = pFirst->pNext;
		pMin = pFirst;
	}
}
ListItem* Find( ListItem* pList, const void* info,ListItem** pPrev, int( __cdecl* compareItem )( const void*, const void* ) )
{
	while ( pList->pNext )
	{
		*pPrev = pList;
		if( compareItem( pList->pNext->pInfo,info ) == 0 ) return pList->pNext;
		pList = pList->pNext;
	}
	perror( "Element not found" );
	*pPrev = NULL;
	return NULL;
}
void PrintTab( ListItem* pList, void( __cdecl* printitem )( const void* ) )
{
	if ( IsEmpty( pList ) )
	{
		perror( "No items in the list!" );
		return;
	}
	while( pList->pNext )
	{
		printitem( pList->pNext->pInfo );
		pList = pList->pNext;
	}
}