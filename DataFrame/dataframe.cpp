#include "dataframe.h"

constexpr auto MAXSIZE = 100;

/// <summary>
/// 初始化顺序表
/// </summary>
/// <param name="L">顺序表</param>
/// <returns>0或-1表示函数是否正常运行</returns>
int InitList(SqList& L) {
	L.elem = new int[MAXSIZE];
	if (!L.elem) return -1;
	L.length = 0;
	return 0;
}

/// <summary>
/// 顺序表取值
/// </summary>
/// <param name="L">传入需要操作的顺序表</param>
/// <param name="i">需要取值的位置(位序而非下标，表示第i个元素)</param>
/// <param name="e">传入一个变量，将取到的值赋给e</param>
/// <returns>0或-1表示函数是否正常运行</returns>
int GetElem(SqList L, int i, int& e) {
	if (i<1 || i>L.length) return -1;
	e = L.elem[i - 1];
	return 0;
}

/// <summary>
/// 顺序表的查找
/// </summary>
/// <param name="L">需要操作的顺序表</param>
/// <param name="e">查找的元素</param>
/// <returns>元素所在的下标</returns>
int LocateElem(SqList L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i;
	}
	return -1;
}

/// <summary>
/// 顺序表的插入
/// </summary>
/// <param name="L">需要操作的顺序表</param>
/// <param name="i">插入的位置，是位序而非下标</param>
/// <param name="e">插入的元素</param>
/// <returns>0或-1表示函数是否正常运行</returns>
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
/// 顺序表的删除
/// </summary>
/// <param name="L">需要操作的顺序表</param>
/// <param name="i">需要删除元素的位序</param>
/// <returns>0或-1表示函数是否正常运行</returns>
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
/// 初始化单链表
/// </summary>
/// <param name="L">传入头指针</param>
void InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return;
}

/// <summary>
/// 单链表取值
/// </summary>
/// <param name="L">要取值的链表</param>
/// <param name="i">取值的位置</param>
/// <param name="e">将取到的值赋给e</param>
/// <returns>0或-1表示函数是否正常运行</returns>
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
/// 单链表的按值查找
/// </summary>
/// <param name="L">需要查找的链表</param>
/// <param name="e">需要查找的值</param>
/// <returns>e所在结点的地址</returns>
LNode* LocateLinkElem(LinkList L, int e) {
	LinkList p;
	p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}

/// <summary>
/// 单链表的插入
/// </summary>
/// <param name="L">要插入的链表</param>
/// <param name="i">插入的位序</param>
/// <param name="e">插入的值</param>
/// <returns>-1或0表示函数是否正常运行</returns>
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
/// 删除指定位置元素
/// </summary>
/// <param name="L">所要操作的链表</param>
/// <param name="i">元素的位序</param>
/// <returns>返回-1或0来表示函数是否正常运行</returns>
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
/// 使用前插法来创建单链表
/// </summary>
/// <param name="L">传入头指针</param>
/// <param name="n">创建的长度</param>
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
/// 后插法创建单链表
/// </summary>
/// <param name="L">传入头指针</param>
/// <param name="n">链表长度</param>
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
/// 初始化栈
/// </summary>
/// <param name="S">要操作的栈</param>
/// <returns>操作成功返回真</returns>
bool InitStack(SqStack& S) {
	S.base = new int[MAXSIZE];
	if (!S.base)return false;
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return true;
}

/// <summary>
/// 压栈操作
/// </summary>
/// <param name="S">操作栈</param>
/// <param name="e">要压入的数据</param>
/// <returns>操作成功返回真</returns>
bool Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize)return false;
	*S.top = e;
	S.top++;
	return true;
}

/// <summary>
/// 出栈操作
/// </summary>
/// <param name="S">操作栈</param>
/// <param name="e">出栈数据赋予变量</param>
/// <returns>操作成功返回真</returns>
bool Pop(SqStack& S, int& e) {
	if (S.top == S.base)return false;
	S.top--;
	e = *S.top;
	return true;
}

/// <summary>
/// 取栈顶元素
/// </summary>
/// <param name="S">操作栈</param>
/// <returns>返回栈顶元素</returns>
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