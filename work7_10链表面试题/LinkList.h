#ifndef __LINKLIST_H__
#define _LINKLIST_H__
#include <stdio.h>
#include <assert.h>
#include<string.h>
#include<math.h>
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node* next;
}Node,*pNode;

void PushFront(pNode *pplist,Datatype d);
void PrintList(pNode plist);
void DestroyLinkList(pNode *pplist);
pNode Find(pNode plist, Datatype d);

//2. 从尾到头打印单链表 
void PrintTailToHead(plist);
//3. 删除一个无头单链表的非尾节点 
void EraseNotTail(pNode pos);
//4. 在无头单链表的一个节点前插入一个节点
void InsertNode(pNode pos, Datatype d);
//5. 单链表实现约瑟夫环 
void pLinkNodeJosephCycle(pNode * pplist, int num);
//6. 逆置/反转单链表 
Node* ReverseList(pNode * pplist);
//7. 单链表排序（冒泡排序） 
void BubbleSort(pNode * pplist);
//8. 合并两个有序链表,合并后依然有序 
Node* Merge(pNode list1, pNode list2);
//9. 查找单链表的中间节点，要求只能遍历一次链表 
Node* FindMidNode(pNode head);
//10. 查找单链表的倒数第k个节点，要求只能遍历一次链表 
void FindLastKNode(pNode *pplist, int k);
//11. 判断单链表是否带环？若带环，求环的长度？求环的入口点？并计算每个算法的时间复杂度&空间复杂度。 
Node* CheckCycle(pNode pList);
int GetCircleLength(pNode meet);
pNode GetCycleEntryNode(pNode list, pNode meetNode);
//12. 判断两个链表是否相交，若相交，求交点。（假设链表不带环） 
Node * CheckCross(pNode list1, pNode list2);
//13. 判断两个链表是否相交，若相交，求交点。（假设链表可能带环）【升级版】 
Node * CheckCycleCross(pNode list1, pNode list2);
//14. 复杂链表的复制。 
//一个链表的每个节点，有一个指向next指针指向下一个节点， 
//还有一个random指针指向这个链表中的一个随机节点或者NULL， 
//现在要求实现复制这个链表，返回复制后的新链表。 
typedef struct ComplexNode
{
	Datatype _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode,*pComplexNode;

ComplexNode *Copy(pComplexNode *plist);//复杂链表复制
//15. 求两个有序单链表交集(差集)。 
void UnionSet(pNode l1, pNode l2);

#endif //_LINKLIST_H__