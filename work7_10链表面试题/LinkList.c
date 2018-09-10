#include"LinkList.h"
void PrintList(pNode plist)
{
	pNode cur = plist;
	while (cur)
	{
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("Over\n");
}
pNode BuyNode(Datatype d)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = d;
	NewNode->next = NULL;
	return NewNode;
}
void PushFront(pNode *pplist, Datatype d)
{
	Node* NewNode = BuyNode(d);
	assert(pplist != NULL);
	NewNode->next = *pplist;
	*pplist = NewNode;
}

void PrintTailToHead(pNode plist)
{
	if (plist == NULL)
		return;
	if (plist->next == NULL)
		printf("%d", plist->data);
	pNode cur = plist;
	pNode tail = NULL;
	while (plist != tail)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		printf("%d-->", cur->data);
		tail = cur;
	}
	printf("Over\n");
}

void DestroyLinkList(pNode *pplist)
{
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur)
	{
		pNode dell = cur;
		cur = cur->next;
		free(dell);
		dell = NULL;
	}
	*pplist = NULL;
}

pNode Find(pNode plist, Datatype d)
{
	assert(plist != NULL);
	Node *cur = plist;
	while (cur->data != d)
	{
		cur = cur->next;
	}
	return cur;
}

void EraseNotTail(pNode pos)//�Ѻ���һ���ڵ��ֵ������������ɾ����������Ǹ��ڵ�
{
	pNode del = NULL;
	assert(pos != NULL);
	assert(pos->next != NULL);
	del = pos->next;
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(del);
	del = NULL;
}

void  InsertNode(pNode pos, Datatype d)
{
	pNode NewNode = BuyNode(d);
	NewNode->next = pos->next;
	pos->next = NewNode;
}

void pLinkNodeJosephCycle(pNode * pplist, int num)
{
	//ע�͵Ĳ��������ʼд�Ĵ��룬��ʱ��������ͷ�ڵ��ɾ������
	//pNode cur = NULL;
	//pNode cur2 = NULL;
	//assert(pplist != NULL);
	//assert(*pplist != NULL);
	//cur = *pplist;
	//cur2 = *pplist;
	//cur2 = cur2->next;
	//while (cur2->next != *pplist)
	//{
	//	cur2 = cur2->next;
	//}
	//while ((cur->next) != cur)
	//{
	//	for (int i = 1; i < num; i++)
	//	{
	//		cur = cur->next;
	//	}
	//	for (int i = 1; i < num; i++)
	//	{
	//		cur2 = cur2->next;
	//	}
	//	pNode del = cur;
	//	cur2->next = del->next;
	//	cur = cur->next;
	//	free(del);
	//	del = NULL;
	//}
	//printf("%d\n", cur->data);
	
	//cur->next = NULL;
	//DestroyLinkList(&cur);
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while(cur->next != cur)
	{
		for (int i = 1; i < num; i++)
		{
			cur = cur->next;
		}
		pNode dell = cur->next;
		cur->data = dell->data;
		cur->next = dell->next;
		free(dell);
		dell = NULL;
	}
	printf("%d\n", cur->data);
	//cur->next = NULL;
	//DestroyLinkList(&cur);//DestroyLinkList����Ҫ�����ղŻ�ͣ����������Ҫcur->next=NULL
	free(cur);
	cur = NULL;//����ɾ����������
}

Node* ReverseList(pNode * pplist)
{
	pNode cur = NULL;
	pNode cur1 = NULL;
	pNode cur2 = NULL;

	assert(pplist != NULL);
	assert(*pplist != NULL);
	cur = *pplist;
	while (cur)
	{
		cur1 = cur->next;
		cur->next = cur2;
		cur2 = cur;
		cur = cur1;
	}
	return cur2;
}

void BubbleSort(pNode * pplist)
{
	pNode cur = NULL;
	pNode next = NULL;
	pNode tail = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur != tail)
	{
		cur = *pplist;
		next = cur->next;
		while (next != tail)
		{
			if ((cur->data) > (next->data))
			{
				Datatype tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
			}
			cur = next;
			next = cur->next;
		}
		tail = cur;
	}
}

Node* Merge(pNode list1, pNode list2)
{
	pNode NewList = NULL;
	pNode tail = NULL;
	assert(list1 != NULL);
	assert(list2 != NULL);

	if ((list1->data) < (list2->data))
	{
		NewList = list1;
		list1 = list1->next;
	}
	else
	{
		NewList = list2;
		list2 = list2->next;
	}
	tail = NewList;
	while ((list1 != NULL) && (list2 != NULL))
	{
		if ((list1->data) < (list2->data))
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	if (list1 == NULL)
	{
		tail->next = list2;
	}
	if (list2 == NULL)
	{
		tail->next = list1;
	}
	return NewList;
}

Node* FindMidNode(pNode plist)
{
	Node *p1 = NULL;
	Node *p2 = NULL;
	assert(plist != NULL);
	p1 = plist;
	p2 = plist;
	while (p1->next != NULL)
	{
		for (int i = 0; i < 2; i++)
		{
			p1 = p1->next;
		}
		p2 = p2->next;
	}
	Node *p3 = p2;
	p3->next = NULL;
	return p3;
}

void FindLastKNode(pNode *pplist, int k)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	assert(pplist != NULL);
	p1 = *pplist;
	p2 = *pplist;

	for (int i = 1; i < k; i++)
	{
		p1 = p1->next;
	}
	while (p1->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	printf("%d\n", p2->data);
}

Node* CheckCycle(pNode pList)
{
	pNode cur1 = NULL;
	pNode cur2 = NULL;
	assert(pList != NULL);
	cur1 = pList;
	cur2 = pList;
	if ((cur1->next == NULL) || (cur1->next->next == NULL))
		return NULL;
	do
	{
		cur1 = cur1->next->next;//һ��ָ��������������һ����һ��������ǻ��Ļ�������ָ���վ�������
		cur2 = cur2->next;
	} while ((cur1 != NULL) && (cur1->next != NULL) 
			&& (cur1 != cur2));
	if (cur1 == cur2)
	{
		return cur1;
	}
	else
	{
		return NULL;
	}
}

int GetCircleLength(pNode meet)
{
	pNode fast = meet;
	pNode slow = meet;
	int count = 0;
	do
	{
		fast = fast->next->next;
		slow = slow->next;
		count++;
	} while (fast!= slow);
	return count;
}

pNode GetCycleEntryNode(pNode list, pNode meetNode)
{
	while (list != meetNode)
	{
		list = list->next;
		meetNode = meetNode->next;
	}
	return list;
}

Node * CheckCross(pNode list1, pNode list2)
{
	int len1 = 0;
	int len2 = 0;
	pNode cur1 = NULL;
	pNode cur2 = NULL;
	assert(list1&&list2);
	cur1 = list1;
	cur2 = list2;
	while (cur1->next != NULL)
	{
		cur1 = cur1->next;
		len1++;
	}
	while (cur2->next != NULL)
	{
		cur2 = cur2->next;
		len2++;
	}
	if (cur1 == cur2)//�ߵ�β�������ͬ���ཻ
	{
		int diff = abs(len1 - len2);
		if (len1 > len2)
		{
			cur1 = list1;
			cur2 = list2;
		}
		else
		{
			cur1 = list2;
			cur2 = list1;
		}
		for (int i = 0; i < diff; i++)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else 
	{
		return NULL;
	}

}
Node * CheckCycleCross(pNode list1, pNode list2)
{
	pNode p1 = NULL;
	pNode p2 = NULL;
	pNode p3 = NULL;

	pNode Cross = NULL;
	int q1 = 0;
	int q2 = 0;
	assert(list1&&list2);
	p1 = list1;
	p2 = list2;
	p3 = list2;
	pNode meet = CheckCycle(list1);//�����Ƿ�ɻ���meetΪ�����㡣
	if (meet == NULL)
	{
		printf("�����ɻ�\n");
		return NULL;
	}
	while ((p3!=NULL)&&(p3!=meet))
	{
		p3 = p3->next;
	}
	if (p3 == NULL)
	{
		printf("�����ཻ\n");//�����ཻ����һ���л���һ���޻��������ж��ˣ��϶��������ཻ��
		                       //���������л����жϵ�һ���������ײ�㣨fast��slow�����Ľڵ㣩��
		                       //������ڵڶ�������Ļ��У�����ڣ����ཻ��
		return NULL;
	}
	pNode entry = GetCycleEntryNode(list1, meet);//�������
	while (p1->next != meet)
	{
		p1 = p1->next;
		q1++;
	}
	while (p2->next != meet)
	{
		p2 = p2->next;
		q2++;
	}
	int len1 = q1 + GetCircleLength(meet);//������=����ͷָ�뵽���㳤��+���ĳ���
	int len2 = q2 + GetCircleLength(meet);
	if (len1 > len2)
	{
		p1 = list1;
		p2 = list2;
	}
	else
	{
		p1 = list2;
		p2 = list1;
	}
	int diff = abs(len1 - len2);
	for (int i = 0; i < diff; i++)
	{
		p1 = p1->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	Cross = p1;//����
	return p1;
}

ComplexNode* BuyComplexNode(Datatype x)
{
	ComplexNode* node = (ComplexNode*)malloc(sizeof(ComplexNode));
	assert(node);
	node->_next = NULL;
	node->_random = NULL;
	node->_data = x;
	return node;
}

void PushFront2(pNode *pplist, Datatype d)
{
	Node* NewNode = BuyComplexNode(d);
	assert(pplist != NULL);
	NewNode->next = *pplist;
	*pplist = NewNode;
}

ComplexNode *Copy(pComplexNode *plist)//������
{
	pComplexNode cur = NULL;
	pComplexNode cur1 = NULL;
	pComplexNode tmp = NULL;
	pComplexNode ret = NULL;
	assert(plist != NULL);
	cur = *plist;
	while (cur)//�����������Һϲ�
	{
		tmp = (ComplexNode*)malloc(sizeof(ComplexNode));
		tmp->_data = cur->_data;
		tmp->_next = cur->_next;
		cur->_next = tmp;
		cur = cur->_next->_next;
	}
	cur = *plist;
	while (cur)//�ϲ�֮���������µĽڵ�����_random
	{
		if (cur->_random != NULL)
		{
			cur->_next->_random = cur->_random->_next;
			cur = cur->_next->_next;
		}
		else
		{
			cur->_next->_random = NULL;
			cur = cur->_next->_next;
		}
	}
	cur = *plist;
	cur1 = cur->_next;
	ret = cur1;
	while (cur)//�������
	{
		cur->_next = cur->_next->_next;
		cur = cur1->_next;
		if (cur == NULL)
			break;//return ret;
		cur1->_next = cur->_next;
		cur1 = cur->_next;
	}
	return ret;
}

void UnionSet(pNode l1, pNode l2)
{
	assert(l1&&l2);
	while (l1&&l2)
	{
		if ((l1->data) < (l2->data))
		{
			l1 = l1->next;
		}
		else if ((l1->data) > (l2->data))
		{
			l2 = l2->next;
		}
		else
		{
			printf("%d  ", l1->data);
			l1 = l1->next;
			l2 = l2->next;
		}
	}
	printf("\n");
}