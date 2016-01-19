
// MFCApplicationDoc.h : CMFCApplicationDoc ��Ľӿ�
//
#pragma once

#include "Obj.h"

class CMFCApplicationDoc : public CDocument
{
protected: // �������л�����
	CMFCApplicationDoc();
	DECLARE_DYNCREATE(CMFCApplicationDoc)

// ����
public:

// ����
public:
	//���һ��ģ�͵�Doc�У�ͬʱ���ظ�Obj��
	CObj& AddObj(CObj& pObj);

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFCApplicationDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
