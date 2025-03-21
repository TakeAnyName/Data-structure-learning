#include <iostream>
#pragma once
namespace MyDataStructs
{
	template <typename T>
	class List
	{
	public:
		List();
		~List();

		void ClearList() { len = 0; }
		
		bool ListEmpty() {
			return len == 0;
		}

		int ListLength() { return len; }

		void GetElem(int x, T& e);

		int LocateElem(T e);

		void PriorElem(T cur_e, T& pre_e);
		void NextElem(T cur_e, T& next_e);
		bool ListInsert(int x, T e);
		bool ListDelete(int x);

	private:
		static const int MAXSIZE = 128;
		T* elem;
		int len;

	};
	template <typename T>
	List<T>::List():elem(new T[MAXSIZE]()),len(0)
	{
		if (!elem)
		{
			std::cout << "List created failued!" << std::endl;
		}
	}

	template <typename T>
	List<T>::~List()
	{
		delete[] elem;
		elem = 0;
		len = 0;
	}

	template <typename T>
	void List<T>::GetElem(int x, T& e)
	{
		if (1 <= x && x <= len)
		{
			e = elem[x - 1];
		}
	}

	template <typename T>
	int List<T>::LocateElem(T e)
	{
		for (int i = 0; i < len; i++)
		{
			if (elem[i] == e)
			{
				return i + 1;
			}
		}
		return 0;
	}

	template <typename T>
	void List<T>::PriorElem(T cur_e, T& pre_e)
	{
		int pos = LocateElem(cur_e);
		if (pos > 1)
		{
			pre_e = elem[pos - 2];
		}
		else
		{
			pre_e = T();
		}
	}

	template <typename T>
	void List<T>::NextElem(T cur_e, T& next_e)
	{
		int pos = LocateElem(cur_e);
		if (pos > 0 && pos < len)
		{
			next_e = elem[pos];
		}
		else
		{
			next_e = T();
		}
	}

	template <typename T>
	bool List<T>::ListInsert(int x, T e)
	{
		if (len>=MAXSIZE)
		{
			return false;
		}

		if (x <1 || x > len+1)
		{
			return false;
		}

		for (int i = len; i >= x; i--)
		{
			elem[i] = elem[i - 1];
		}
		elem[x - 1] = e;
		len++;
		return true;
	}

	template <typename T>
	bool List<T>::ListDelete(int x)
	{
		if (x < 1 || x > len)
		{
			return false;
		}

		for (int i = x - 1; i < len; i++)
		{
			elem[i] = elem[i + 1];
		}
		len--;
		return true;
	}

}