#ifndef _IOBJ_
#define _IOBJ_

enum ObjType
{
	ObjType_Null = 0,
	ObjType_Human,
	ObjType_Monster,
};

class CObj
{
public:
	CObj(ObjType eObjType) : m_eObjType(eObjType) { }
	virtual ~CObj() { }

	void SetObjId(unsigned int nObjId) { m_nObjId = nObjId; }
	unsigned int GetObjId() const { return m_nObjId; }

private:
	ObjType m_eObjType;
	unsigned int m_nObjId;

};

#endif