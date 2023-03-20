
#include "stdafx.h"             

#include "TCollections.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
IMPLEMENT_DYNCREATE(TCollections, SqlRecord) 

//-----------------------------------------------------------------------------
TCollections::TCollections(BOOL bCallInit)
	:
	SqlRecord	(GetStaticName()),
	f_Disabled(FALSE)
{
	f_Collection.SetUpperCase();

	BindRecord();	
	if (bCallInit) Init();
}

//-----------------------------------------------------------------------------
void TCollections::BindRecord()
{
	BEGIN_BIND_DATA	();
		BIND_DATA(_NS_FLD("Collection"), f_Collection);
		BIND_DATA(_NS_FLD("Description"), f_Description);
		BIND_DATA(_NS_FLD("Notes"), f_Notes);
		BIND_DATA(_NS_FLD("Disabled"), f_Disabled);
		BIND_TB_GUID();
	END_BIND_DATA();    
}

//-----------------------------------------------------------------------------
LPCTSTR TCollections::GetStaticName() { return _NS_TBL("CO_Collections"); }