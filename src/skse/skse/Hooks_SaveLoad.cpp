#include "Hooks_SaveLoad.h"
#include "SafeWrite.h"
#include "Utilities.h"
#include "Serialization.h"
#include "GlobalLocks.h"
#include "GameData.h"

void BGSSaveLoadManager::SaveGame_Hook(const char * saveName)
{
#ifdef DEBUG
	_MESSAGE("Executing BGSSaveLoadManager::SaveGame_Hook. saveName: %s", saveName);
#endif

	Serialization::SetSaveName(saveName);
	CALL_MEMBER_FN(this, SaveGame_HookTarget)(saveName);
	Serialization::SetSaveName(NULL);

#ifdef DEBUG
	_MESSAGE("Executed BGSSaveLoadManager::SaveGame_Hook.");
#endif
}

bool BGSSaveLoadManager::LoadGame_Hook(const char * saveName, bool unk1)
{
#ifdef DEBUG
	_MESSAGE("Executing BGSSaveLoadManager::LoadGame_Hook. saveName: %s", saveName);
#endif

	g_loadGameLock.Enter();

	Serialization::SetSaveName(saveName);
	bool result = CALL_MEMBER_FN(this, LoadGame_HookTarget)(saveName, unk1);
	Serialization::SetSaveName(NULL);

	g_loadGameLock.Leave();

#ifdef DEBUG
	_MESSAGE("Executed BGSSaveLoadManager::LoadGame_Hook.");
#endif

	return result;
}

bool		s_requestedSave	= false;
bool		s_requestedLoad	= false;
std::string	s_reqSaveName;
std::string	s_reqLoadName;

void BGSSaveLoadManager::RequestSave(const char * name)
{
	s_requestedSave = true;
	s_reqSaveName = name;
}

void BGSSaveLoadManager::RequestLoad(const char * name)
{
	s_requestedLoad = true;
	s_reqLoadName = name;
}

void BGSSaveLoadManager::ProcessEvents_Hook(void)
{
	CALL_MEMBER_FN(this, ProcessEvents_Internal)();

	// wants both? gets nothing.
	if(s_requestedSave && s_requestedLoad)
		_MESSAGE("BGSSaveLoadManager: save and load requested in the same frame, ignoring both");
	else if(s_requestedSave)
		Save(s_reqSaveName.c_str());
	else if(s_requestedLoad)
		Load(s_reqLoadName.c_str());

	s_requestedSave = false;
	s_requestedLoad = false;
	s_reqSaveName.clear();
	s_reqLoadName.clear();
}

#if 0

// 008
class BSStorage
{
public:
	virtual	~BSStorage();

	virtual SInt32	Unk_01(void);						// pure
	virtual UInt32	Unk_02(void);						// pure
	virtual SInt32	Unk_03(UInt32 unk0, UInt32 unk1);	// pure
	virtual SInt32	Unk_04(UInt32 len, void * out);		// pure
	virtual UInt32	Unk_05(UInt32 unk0, UInt32 unk1);	// pure

//	void					** _vtbl;	// 000
	BSIntrusiveRefCounted	refCount;	// 004
	UInt32					unk008;		// 008
	void					* unk00C;	// 00C
	void					* unk010;	// 010
};


// vtbl 0107F8E4
class SaveStorageWrapper : public BSStorage
{
public:
	virtual	~SaveStorageWrapper();

	virtual SInt32	Unk_01(void);
	virtual UInt32	Unk_02(void);
	virtual SInt32	Unk_03(UInt32 unk0, UInt32 unk1);
	virtual SInt32	Unk_04(UInt32 len, void * out);
	virtual UInt32	Unk_05(UInt32 unk0, UInt32 unk1);
};

// vtbl 0107F8FC
class LoadStorageWrapper : public BSStorage
{
public:
	virtual	~LoadStorageWrapper();

	virtual SInt32	Unk_01(void);						// 04
	virtual UInt32	Unk_02(void);						// 08
	virtual SInt32	Unk_03(UInt32 unk0, UInt32 unk1);	// 0C
	virtual SInt32	Unk_04(UInt32 len, void * out);		// 10
	virtual UInt32	Unk_05(UInt32 unk0, UInt32 unk1);	// 14
};

class IHandleReaderWriter
{
};

class BaseHandleReaderWriter : public IHandleReaderWriter
{
};

// vtbl 0109D0F0
class SaveFileHandleReaderWriter : public BaseHandleReaderWriter
{
public:
	virtual	~SaveFileHandleReaderWriter();
	//	void					** _vtbl;	// 000

	virtual SInt32	Unk_01(void);	// 04
	virtual UInt8	Unk_02(void);	// 08
	virtual UInt8	Unk_03(BSStorage * storageWrapper, UInt64 * handleOut);	// 0C
	virtual UInt8	Unk_04(void);	// 10
	virtual UInt8	Unk_05(void);	// 14
};

#endif

void Hooks_SaveLoad_Commit(void)
{
	// Load & save
	WriteRelCall(0x00680CB0 + 0x01E2, GetFnAddr(&BGSSaveLoadManager::SaveGame_Hook));
	WriteRelCall(0x006819A0 + 0x00B5, GetFnAddr(&BGSSaveLoadManager::LoadGame_Hook));
	WriteRelCall(0x0069C860 + 0x0064, GetFnAddr(&BGSSaveLoadManager::ProcessEvents_Hook));
}