#include "dataframe.h"

constexpr auto MAXSIZE = 100;

/// <summary>
/// ��ʼ��˳���
/// </summary>
/// <param name="L">˳���</param>
/// <returns>0��-1��ʾ�����Ƿ���������</returns>
int InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem) return -1;
	L.length = 0;
	return 0;
}

/// <summary>
/// ˳���ȡֵ
/// </summary>
/// <param name="L">������Ҫ������˳���</param>
/// <param name="i">��Ҫȡֵ��λ��(λ������±꣬��ʾ��i��Ԫ��)</param>
/// <param name="e">����һ����������ȡ����ֵ����e</param>
/// <returns>0��-1��ʾ�����Ƿ���������</returns>
int GetElem(SqList L, int i, int& e) {
	if (i<1 || i>L.length) return -1;
	e = L.elem[i - 1];
	return 0;
}

/// <summary>
/// ˳���Ĳ���
/// </summary>
/// <param name="L">��Ҫ������˳���</param>
/// <param name="e">���ҵ�Ԫ��</param>
/// <returns>Ԫ�����ڵ��±�</returns>
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i;
	}
	return -1;
}

/// <summary>
/// ˳���Ĳ���
/// </summary>
/// <param name="L">��Ҫ������˳���</param>
/// <param name="i">�����λ�ã���λ������±�</param>
/// <param name="e">�����Ԫ��</param>
/// <returns>0��-1��ʾ�����Ƿ���������</returns>
int ListInsert(SqList& L, int i, int e) {
	if ((i < 1) || (i > L.length + 1)) return -1;
	if (L.length == MAXSIZE) return -1;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return 0;
}

/// <summary>
/// ˳����ɾ��
/// </summary>
/// <param name="L">��Ҫ������˳���</param>
/// <param name="i">��Ҫɾ��Ԫ�ص�λ��</param>
/// <returns>0��-1��ʾ�����Ƿ���������</returns>
int ListDelete(SqList& L, int i) {
	if ((i < 1) || (i > L.length)) return -1;
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return 0;
}

void TraverseList(SqList L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.elem[i]<<endl;
	}
}

/// <summary>
/// ��ʼ��������
/// </summary>
/// <param name="L">����ͷָ��</param>
void InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return;
}

/// <summary>
/// ������ȡֵ
/// </summary>
/// <param name="L">Ҫȡֵ������</param>
/// <param name="i">ȡֵ��λ��</param>
/// <param name="e">��ȡ����ֵ����e</param>
/// <returns>0��-1��ʾ�����Ƿ���������</returns>
int GetLinkElem(LinkList L, int i, int& e) {
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i) return -1;
	e = p->data;
	return 0;
}

/// <summary>
/// ������İ�ֵ����
/// </summary>
/// <param name="L">��Ҫ���ҵ�����</param>
/// <param name="e">��Ҫ���ҵ�ֵ</param>
/// <returns>e���ڽ��ĵ�ַ</returns>
LNode* LocateLinkElem(LinkList L, int e) {
	LinkList p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

/// <summary>
/// ������Ĳ���
/// </summary>
/// <param name="L">Ҫ���������</param>
/// <param name="i">�����λ��</param>
/// <param name="e">�����ֵ</param>
/// <returns>-1��0��ʾ�����Ƿ���������</returns>
int ListLinkInsert(LinkList& L, int i, int e) {
	LinkList p = L;
	int j = 0;
	while (p && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!p || (j > i - 1)) return -1;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 0;
}

/// <summary>
/// ɾ��ָ��λ��Ԫ��
/// </summary>
/// <param name="L">��Ҫ����������</param>
/// <param name="i">Ԫ�ص�λ��</param>
/// <returns>����-1��0����ʾ�����Ƿ���������</returns>
int ListLinkDelete(LinkList& L, int i) {
	LinkList p = L;
	int j = 0;
	while ((p->next) && (j < i - 1)) {
		p = p->next;
		++j;
	}
	if (!(p->next) || (j > i - 1)) return -1;
	LinkList q = p->next;
	p->next = q->next;
	delete q;
	return 0;
}

/// <summary>
/// ʹ��ǰ�巨������������
/// </summary>
/// <param name="L">����ͷָ��</param>
/// <param name="n">�����ĳ���</param>
void CreateList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

/// <summary>
/// ��巨����������
/// </summary>
/// <param name="L">����ͷָ��</param>
/// <param name="n">������</param>
void CreteList_R(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LinkList r = L;
	for (int i = 0; i < n; i++) {
		LinkList p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}

/// <summary>
/// ��ʼ��ջ
/// </summary>
/// <param name="S">Ҫ������ջ</param>
/// <returns>�����ɹ�������</returns>
bool InitStack(SqStack& S) {
	S.base = new int[MAXSIZE];
	if (!S.base)return false;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return true;
}

/// <summary>
/// ѹջ����
/// </summary>
/// <param name="S">����ջ</param>
/// <param name="e">Ҫѹ�������</param>
/// <returns>�����ɹ�������</returns>
bool Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize)return false;
	*S.top = e;
	S.top++;
	return true;
}

/// <summary>
/// ��ջ����
/// </summary>
/// <param name="S">����ջ</param>
/// <param name="e">��ջ���ݸ������</param>
/// <returns>�����ɹ�������</returns>
bool Pop(SqStack& S, int& e) {
	if (S.top == S.base)return false;
	S.top--;
	e = *S.top;
	return true;
}

/// <summary>
/// ȡջ��Ԫ��
/// </summary>
/// <param name="S">����ջ</param>
/// <returns>����ջ��Ԫ��</returns>
int GetTop(SqStack S) {
	if (S.top != S.base)return *(S.top - 1);
}

bool InitStack(LinkStack& S) {
	S = nullptr;
	return true;
}

bool Push(LinkStack& S, int e) {
	LinkStack p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return true;
}

bool Pop(LinkStack& S, int& e) {
	if (S == nullptr)return false;
	LinkStack p;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return true;
}

int GetTop(LinkStack S) {
	if (S != nullptr)return S->data;
}