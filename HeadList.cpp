#include "global.h"
#include "List.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	srand( time( NULL ) );
	ListItem* List = CreateList();
	for( int i = 0; i < 20; i++ )
	{
		LISTINFO* I1 = ( LISTINFO* )calloc( 1,sizeof( LISTINFO ) );
		I1->pTab = ( int* )calloc( 1,sizeof( int ) );
		if( i==9 ) I1->nKey = 2000;
		else I1->nKey = rand()%50;
		I1->pTab[0] = i;
		InsertFront(List,I1);
	}
	PrintTab( List,printitem );
	SortList( List,compareItem );
	printf( "\n" );
	PrintTab( List,printitem );
	printf( "\n" );

	LISTINFO* TEST = ( LISTINFO* )calloc( 1,sizeof( LISTINFO ) );
	TEST->nKey = 2000;

	ListItem* preTEST;
	ListItem* Found = Find( List,TEST,&preTEST,compareItem );

	LISTINFO* NewItem = ( LISTINFO* )calloc( 1,sizeof( LISTINFO ) );
	NewItem->nKey = 3000;

	Insert( preTEST,NewItem );
	PrintTab( List,printitem );
	printf( "\n" );

	Find( List,TEST,&preTEST,compareItem );
	Remove( preTEST );
	PrintTab( List,printitem );
	printf( "\n" );

	ClearList( List,freeMem );
	PrintTab( List,printitem );
	printf( "\n" );

	LISTINFO* New1 = ( LISTINFO* )calloc( 1,sizeof( LISTINFO ) );
	New1->pTab = ( int* )calloc( 1,sizeof( int ) );
	New1->pTab[0] = 1;
	New1->nKey = 100;
	LISTINFO* New2 = ( LISTINFO* )calloc( 1,sizeof( LISTINFO ) );
	New2->pTab = ( int* )calloc( 1,sizeof( int ) );
	New2->pTab[0] = 2;
	New2->nKey = 140;
	InsertFront( List,New1 );
	InsertFront( List,New2 );
	PrintTab( List,printitem );
	printf( "\n" );

	RemoveList( List,freeMem );
}
int compareItem( const void* inf1, const void* inf2 )
{
	if( ( ( LISTINFO* )inf1 )->nKey > ( ( LISTINFO* )inf2 )->nKey )  return 1;
	else if ( ( ( LISTINFO* )inf1 )->nKey < ( ( LISTINFO* )inf2 )->nKey ) return -1;
	return 0;

}
void freeMem(const void* item)
{
	free( ( ( LISTINFO* )item )->pTab );
	free( ( LISTINFO* )item );
}
void printitem(const void* item)
{
	printf("[%d], ", ( ( LISTINFO* )item )->nKey );
}