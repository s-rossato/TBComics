
#pragma once

#include <Comics\ComicsComponents\ADMCollections.h>

#include "beginh.dex"

class TCollections;

//////////////////////////////////////////////////////////////////////////////
//             class DBTCollections definition
//////////////////////////////////////////////////////////////////////////////
//
//----------------------------------------------------------------------------
class TB_EXPORT DBTCollections : public DBTMaster
{ 
	DECLARE_DYNAMIC (DBTCollections)

public:
	DBTCollections (CRuntimeClass*, CAbstractFormDoc*);

public:
	TCollections* GetCollections () const { return (TCollections*) GetRecord(); }

protected: 
	virtual void	OnEnableControlsForFind		();
	virtual void	OnDisableControlsForEdit	();
	
	virtual	void	OnDefineQuery		();
	virtual	void	OnPrepareQuery		();
	virtual	void	OnPrepareBrowser	(SqlTable* pTable);

	virtual	BOOL	OnCheckPrimaryKey	();
	virtual	void	OnPreparePrimaryKey	() {}
};

//=============================================================================
class TB_EXPORT DCollections : public CAbstractFormDoc, public ADMCollectionsObj
{
	DECLARE_DYNCREATE(DCollections)

public:
	DCollections();
	DBTCollections*		m_pDBTCollections;
	
public:	// function Member
	virtual	TCollections*	GetCollections() const;                        
	// interfaccia ADM
	virtual	ADMObj*		GetADM		()	{ return this; }

protected:
	virtual BOOL	OnAttachData	();
};

#include "endh.dex"
