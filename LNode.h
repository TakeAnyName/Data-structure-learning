#include <iostream>
#pragma once

namespace MyDataStructs
{
	template <typename T>
	class LNode
	{
	public:
		LNode();
		~LNode();

		bool ListEmpty();
		void ClearList();
		int ListLength();
		void GetElem(int i, T& e);
		int LocateElem(T e);
		bool ListInsert(int i, T e);
		bool ListDelete(int i);

		void PreListInsert(T e);
		void NextListInsert(T e);
		bool PriorElem(T cur_e, T& pre_e);
		bool NextElem(T cur_e, T& next_e);


	private:
		T data;
		LNode* next;

	};

	template <typename T>
	LNode<T>::LNode() :next(nullptr)
	{
	}

	template <typename T>
	LNode<T>::~LNode()
	{
		ClearList();
	}

	template <typename T>
	bool LNode<T>::ListEmpty()
	{
		return next == nullptr;
	}

	template <typename T>
	void LNode<T>::ClearList()
	{
		LNode* p = next;
		while (p != nullptr)
		{
			LNode* temp = p;
			p = p->next;
			delete temp;
		}
		next = nullptr; // 清空后将头节点的 next 置为 nullptr
	}

	template <typename T>
	int LNode<T>::ListLength()
	{
		LNode* p = this->next;
		int i = 0;
		while (p)
		{
			i++;
			p = p->next;
		}
		return i;
	}

	template <typename T>
	void LNode<T>::GetElem(int i, T& e)
	{
		LNode* p = next;
		int j = 1;
		while (p && j < i)
		{
			p = p->next;
			j++;
		}
		e = p->data;
	}

	template <typename T>
	int LNode<T>::LocateElem(T e)
	{
		LNode* p = next;
		int i = 1;
		while (p)
		{
			if (p->data == e)
			{
				return i;
			}
			p = p->next;
			i++;
		}
		return -1;
	}

	template <typename T>
	bool LNode<T>::ListInsert(int i, T e)
	{
		if (i <= 0)
		{
			return false;
		}
		LNode* p = this;
		int j = 0;
		while (p && j < i - 1)
		{
			p = p->next;
			j++;
		}
		if (!p || j > i - 1)
		{
			return false;
		}
		LNode* s = new LNode;
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}

	template <typename T>
	bool LNode<T>::ListDelete(int i)
	{
		if (i <= 0)
		{
			return false;
		}
		LNode* p = this;
		int j = 0;
		while (p->next != nullptr && j < i - 1)
		{
			p = p->next;
			j++;
		}
		if (p->next == nullptr || j > i - 1)
		{
			return false;
		}
		LNode* q = p->next;
		p->next = q->next;
		delete q;
		return true;
	}

	template <typename T>
	void LNode<T>::PreListInsert(T e)
	{
		LNode* p = new LNode;
		p->data = e;
		p->next = next;
		this->next = p;
	}

	template <typename T>
	void LNode<T>::NextListInsert(T e)
	{
		LNode* p = this;
		int j = ListLength();
		for (int i = 0; i < j; i++)
		{
			p = p->next;
		}

		LNode* q = new LNode;
		q->data = e;
		q->next = NULL;
		p->next = q;
	}

	template <typename T>
	bool LNode<T>::PriorElem(T cur_e, T& pre_e)
	{
		int j = LocateElem(cur_e);
		if (j < 0)
		{
			return false;
		}

		LNode* p = this;

		for (int i = 0; i < j - 1; i++)
		{
			p = p->next;
		}
		pre_e = p->data;
		return true;
	}

	template <typename T>
	bool LNode<T>::NextElem(T cur_e, T& next_e)
	{
		int j = LocateElem(cur_e);
		if (j < 0 || j > ListLength())
		{
			return false;
		}

		LNode* p = this;

		for (int i = 0; i < j; i++)
		{
			p = p->next;
		}
		next_e = p->next->data;
		return true;
	}

}
