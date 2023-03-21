
#pragma once

#include "beginh.dex"

class TBoxes;
class TBoxCollections;

/////////////////////////////////////////////////////////////////////////////
//							ADMBoxesObj
/////////////////////////////////////////////////////////////////////////////
//
class TB_EXPORT ADMBoxesObj : public ADMObj
{     
	DECLARE_ADMCLASS(ADMBoxesObj)
		
public:
	virtual	ADMObj*				GetADM					()					= 0;
	virtual	TBoxes*	GetBoxes	()			const	= 0;
	
	virtual	TBoxCollections*	GetDetail	(int nRow)		const	= 0;
};

#include "endh.dex"
