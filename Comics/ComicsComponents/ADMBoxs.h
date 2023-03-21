
#pragma once

#include "beginh.dex"

class TBoxes;
class TBoxCollections;

/////////////////////////////////////////////////////////////////////////////
//							ADMBoxsObj
/////////////////////////////////////////////////////////////////////////////
//
class TB_EXPORT ADMBoxsObj : public ADMObj
{     
	DECLARE_ADMCLASS(ADMBoxsObj)
		
public:
	virtual	ADMObj*				GetADM					()					= 0;
	virtual	TBoxes*	GetBoxes	()			const	= 0;
	
	virtual	TBoxCollections*	GetDetail	(int nRow)		const	= 0;
};

#include "endh.dex"
