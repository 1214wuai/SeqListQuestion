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

//2. ��β��ͷ��ӡ������ 
void PrintTailToHead(plist);
//3. ɾ��һ����ͷ������ķ�β�ڵ� 
void EraseNotTail(pNode pos);
//4. ����ͷ�������һ���ڵ�ǰ����һ���ڵ�
void InsertNode(pNode pos, Datatype d);
//5. ������ʵ��Լɪ�� 
void pLinkNodeJosephCycle(pNode * pplist, int num);
//6. ����/��ת������ 
Node* ReverseList(pNode * pplist);
//7. ����������ð������ 
void BubbleSort(pNode * pplist);
//8. �ϲ�������������,�ϲ�����Ȼ���� 
Node* Merge(pNode list1, pNode list2);
//9. ���ҵ�������м�ڵ㣬Ҫ��ֻ�ܱ���һ������ 
Node* FindMidNode(pNode head);
//10. ���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������ 
void FindLastKNode(pNode *pplist, int k);
//11. �жϵ������Ƿ���������������󻷵ĳ��ȣ��󻷵���ڵ㣿������ÿ���㷨��ʱ�临�Ӷ�&�ռ临�Ӷȡ� 
Node* CheckCycle(pNode pList);
int GetCircleLength(pNode meet);
pNode GetCycleEntryNode(pNode list, pNode meetNode);
//12. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣���������������� 
Node * CheckCross(pNode list1, pNode list2);
//13. �ж����������Ƿ��ཻ�����ཻ���󽻵㡣������������ܴ������������桿 
Node * CheckCycleCross(pNode list1, pNode list2);
//14. ��������ĸ��ơ� 
//һ�������ÿ���ڵ㣬��һ��ָ��nextָ��ָ����һ���ڵ㣬 
//����һ��randomָ��ָ����������е�һ������ڵ����NULL�� 
//����Ҫ��ʵ�ָ�������������ظ��ƺ�������� 
typedef struct ComplexNode
{
	Datatype _data;
	struct ComplexNode* _next;
	struct ComplexNode* _random;
}ComplexNode,*pComplexNode;

ComplexNode *Copy(pComplexNode *plist);//����������
//15. ����������������(�)�� 
void UnionSet(pNode l1, pNode l2);

#endif //_LINKLIST_H__