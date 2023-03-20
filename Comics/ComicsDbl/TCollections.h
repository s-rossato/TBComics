
#pragma once
#include "beginh.dex"

/////////////////////////////////////////////////////////////////////////////
class TB_EXPORT TCollections : public SqlRecord
{
	DECLARE_DYNCREATE(TCollections) 

public:
	DataStr		f_Collection;
	DataStr		f_Description;
	DataStr		f_Notes;
	DataBool	f_Disabled;
	
public:
	TCollections(BOOL bCallInit = TRUE);

public:
    virtual void	BindRecord();
		
public:
	static  LPCTSTR  GetStaticName();
};


#include "endh.dex"