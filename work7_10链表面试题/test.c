#include"LinkList.h"

TestPushFront()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	PrintList(plist);
	DestroyLinkList(&plist);
}

TestPrintTailToHead()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	PrintList(plist);
	PrintTailToHead(plist);
	DestroyLinkList(&plist);
}

TestFind()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	Node *pos = Find(plist, 3);
	if (pos == NULL)
	{
		printf("û���ҵ�\n");
	}
	printf("%d\n", pos->data);
	DestroyLinkList(&plist);
}

TestEraseNotTail()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	PrintList(plist);
	Node *pos = Find(plist, 3);
	if (pos == NULL)
	{
		printf("û���ҵ�\n");
	}
	printf("%d\n", pos->data);
	EraseNotTail(pos);
	PrintList(plist);
	DestroyLinkList(&plist);
}

TestInsertNode()
{
	pNode plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	Node *pos = Find(plist, 3);
	InsertNode(pos, 6);
	PrintList(plist);
	DestroyLinkList(&plist);

}

creat_Link(int num)
{
	Node *p;
	Node *q;
	Node *head;
	int i = 0;
	p = (Node *)malloc(sizeof(Node));
	head = p;
	p->data = 1;
	for (i = 2; i <= num; i++)
	{
		q = (Node*)malloc(sizeof(Node));
		q->data = i;
		p->next = q;
		p = q;
	}
	p->next = head;
	return head;
}
void DestroyLinkList1(pNode *pplist)
{
	pNode cur = NULL;
	assert(pplist != NULL);
	cur = *pplist;
	while (cur->next != *pplist)
	{
		pNode dell = cur;
		cur = cur->next;
		free(dell);
		dell = NULL;
	}
	*pplist = NULL;
}
TestpLinkNodeJosephCycle()
{
	Node *plist = creat_Link(5);
	pLinkNodeJosephCycle(&plist, 3);
	/*plist->next = NULL;
	DestroyLinkList(&plist);*/
}

TestReverseList()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	PrintList(plist);
	plist = ReverseList(&plist);
	PrintList(plist);
	DestroyLinkList(&plist);
}

TestBubbleSort()
{
	Node *plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PrintList(plist);
	BubbleSort(&plist);
	PrintList(plist);
	DestroyLinkList(&plist);

}

TestMerge()
{
	Node *plist1 = NULL;
	PushFront(&plist1, 5);
	PushFront(&plist1, 3);
	PushFront(&plist1, 1);
	Node *plist2 = NULL;
	PushFront(&plist2, 6);
	PushFront(&plist2, 4);
	PushFront(&plist2, 2);
	Node *plist = Merge(plist1, plist2);
	PrintList(plist);
	DestroyLinkList(&plist);
	

}

TestFindMidNode()
{
	Node* plist = NULL;
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	Node * plist2 = FindMidNode(plist);
	PrintList(plist2);
	DestroyLinkList(&plist);
}

TestFindLastKNode()
{
	Node *plist = NULL;
	PushFront(&plist, 7);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	FindLastKNode(&plist,3);
	DestroyLinkList(&plist);
}

Node* MakeCycle(pNode *pplist)
{
	pNode cur1 = NULL;
	pNode cur2 = NULL;
	assert(pplist != NULL);
	cur1 = *pplist;
	cur2 = *pplist;

	while (cur1->next != NULL)
	{
		cur1 = cur1->next;
	}
	for (int i = 0; i < 3; i++)
	{
		cur2 = cur2->next;
	}
	cur1->next = cur2;
	return cur1;
}
TestCheckCycle()
{
	Node *plist = NULL;
	PushFront(&plist, 7);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	Node * p = MakeCycle(&plist);
	pNode plist2 = CheckCycle(plist);
	if (plist2 == NULL)
	{
		printf("û�гɻ�\n");
	}
	else
	{
		printf("����ɻ�\n");
	}
	p->next = NULL;
	DestroyLinkList(&plist);
}
TestGetCircleLength()
{
	Node *plist = NULL;
	PushFront(&plist, 7);
	PushFront(&plist, 6);
	PushFront(&plist, 5);
	PushFront(&plist, 4);
	PushFront(&plist, 3);
	PushFront(&plist, 2);
	PushFront(&plist, 1);
	Node *p = MakeCycle(&plist);
	pNode meet = CheckCycle(plist);
	if (meet == NULL)
	{
		printf("û�гɻ�\n");
	}
	else
	{
		printf("����ɻ�\n");
		printf("���ĳ����ǣ�%d\n", GetCircleLength(meet));
		pNode cur = GetCycleEntryNode(plist, meet);
		printf("������ڵ��ǣ�%d\n",cur->data );
	}
	p->next = NULL;
	DestroyLinkList(&plist);
}


TestCheckCross()
{
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	PushFront(&plist1, 5);
	PushFront(&plist1, 4);
	PushFront(&plist1, 3);
	PushFront(&plist1, 2);
	PushFront(&plist1, 1);
	PushFront(&plist2, 3);
	PushFront(&plist2, 2);
	PushFront(&plist2, 1);
	pNode cur1 = plist1;
	pNode cur2 = plist2;
	
	while (cur2->next != NULL)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	cur2->next = cur1;
	Node * ret = CheckCross(plist1, plist2);
	if (ret != NULL)
	{
		printf("���������ཻ\n");
		printf("�����ǣ�%d\n", ret->data);
	}
	else
	{
		printf("���������ཻ\n");
	}
	DestroyLinkList(&plist1);
	cur2->next = NULL;
	DestroyLinkList(&plist2);

}

TestCheckCycleCross()
{
	/////////////////////////////////////////��������һ
	pNode plist1 = NULL;
	PushFront(&plist1, 7);
	PushFront(&plist1, 6);
	PushFront(&plist1, 5);
	PushFront(&plist1, 4);
	PushFront(&plist1, 3);
	PushFront(&plist1, 2);
	PushFront(&plist1, 1);
	pNode cur1 = plist1;
	pNode cur2 = plist1;
	pNode cur3 = plist1;
	pNode cur4 = plist1;
	cur3 = cur3->next->next;//����ڵ�3
	cur4 = cur4->next->next->next->next->next;//���ڽڵ�6
	for (int i = 0; i < 4; i++)
	{
		cur1 = cur1->next;//�������5
	}
	while (cur2->next != NULL)
	{
		cur2 = cur2->next;//����һ��������β
	}
	cur2->next = cur1;//���� 567 �ɻ�
	//////////////////////////////////////////
	pNode plist2 = NULL;//���������
	PushFront(&plist2, 9);
	PushFront(&plist2, 8);
	pNode cur5 = plist2;
	pNode cur6 = plist2;
	while (cur5->next != NULL)
	{
		cur5=cur5->next;//�������������β
	}
	//cur5->next = cur3;//����ڵ�����Ϊ����
	cur5->next = cur4;//���ڽڵ�����Ϊ���㣬����ѡ����һ���ɣ�ע�͵�����һ��
	///////////////////////////////////////////
	pNode ret1 = CheckCycleCross(plist1, plist2);
	if (ret1 != NULL)
	{
		printf("���������ཻ\n");
		printf("�ཻ���ǣ�%d\n",ret1->data);
	}
	cur2->next = NULL;
	cur5->next = NULL;//�ָ�������
	DestroyLinkList(&plist1);
	DestroyLinkList(&plist2);
}

TestComplexNode()
{
	ComplexNode *p1 = BuyComplexNode(1);
	ComplexNode *p2 = BuyComplexNode(2);
	ComplexNode *p3 = BuyComplexNode(3);
	ComplexNode *p4 = BuyComplexNode(4);
	p1->_next = p2;
	p2->_next = p3;
	p3->_next = p4;
	p4->_next = NULL;
	p1->_random = p3;
	p3->_random = p4;
	p4->_random = p2;
	p2->_random = NULL;
	ComplexNode *ret = Copy(&p1);
	

	
	
}

TestUnionSet()
{
	pNode plist1 = NULL;
	pNode plist2 = NULL;
	PushFront(&plist1, 5);
	PushFront(&plist1, 4);
	PushFront(&plist1, 3);
	PushFront(&plist1, 2);
	PushFront(&plist2, 3);
	PushFront(&plist2, 2);
	PushFront(&plist2, 1);
	UnionSet(plist1, plist2);
	DestroyLinkList(&plist1);
	DestroyLinkList(&plist2);
}
int main()
{
	TestPushFront();
	TestPrintTailToHead();
	TestFind();
	TestEraseNotTail();
	TestInsertNode();
	TestpLinkNodeJosephCycle();
	TestReverseList();
	TestBubbleSort();
	TestMerge();
	TestFindMidNode();
	TestCheckCycle();
	TestGetCircleLength();
	TestCheckCross();
	TestCheckCycleCross();
	TestComplexNode();
	TestUnionSet();//
	system("pause");
	return 0;
}