
#pragma once

#include "beginh.dex"

class TCollections;

/////////////////////////////////////////////////////////////////////////////
//							ADMCollectionsObj
/////////////////////////////////////////////////////////////////////////////
//
class TB_EXPORT ADMCollectionsObj : public ADMObj
{     
	DECLARE_ADMCLASS(ADMCollectionsObj)
		
public:
	virtual	ADMObj*				GetADM					()					= 0;
	virtual	TCollections*	GetCollections	()			const	= 0;
};

#include "endh.dex"
