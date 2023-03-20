
#pragma once

#include "beginh.dex"

class TB_EXPORT TTmpLoadComics : public SqlRecord
{
	DECLARE_DYNCREATE(TTmpLoadComics) 

public:
	DataLng		f_EntryId;
	DataLng		f_SubId;
	DataStr		f_BoxNo;
	DataStr		f_Item;
	DataStr		f_Description;
	DataStr		f_Collection;
	DataDate	f_InvEntryDate;

public:
	TTmpLoadComics(BOOL bCallInit = TRUE);

public:
	virtual void	BindRecord	();	

public:
	static  LPCTSTR  GetStaticName();
};

#include "endh.dex"
