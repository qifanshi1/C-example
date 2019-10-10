#pragma once
#pragma warning(disable:4996)
#include<string>
class U_ptr
{
	friend class smartPtr;
public:
	U_ptr(char* p = nullptr) :
		ptr(p), count(1) {};
	~U_ptr()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
private:
	char* ptr;
	int count;
};
class smartPtr
{
public:
	smartPtr(char* p) :data(new U_ptr(p)) {};
	smartPtr(const smartPtr& ptr)
	{
		data = ptr.data;
		ptr.data->count++;
	}
	smartPtr& operator=(const smartPtr& ptr)
	{
		(ptr.data->count)++;
		if (--(data->count) == 0)
		{
			delete data;
			data = nullptr;
		}
		data = ptr.data;
		return *this;
	}
	~smartPtr()
	{
		if (--(data->count) == 0)
		{
			delete data;
			data = nullptr;
		}
	}
private:
	U_ptr *data;
};

class Mystring
{
public:
	//constructor
	Mystring() :buffer(nullptr) {};
	//constructor
	Mystring(char* initial)
	{
		if (initial != nullptr)
		{
			buffer = new char[strlen(initial) + 1];
			strcpy(buffer, initial);
		}
		else
		{
			buffer = nullptr;
		}
	}
	//copy constructor
	Mystring(const Mystring& str)
	{
		if (str.buffer != nullptr)
		{
			buffer = new char[strlen(str.buffer) + 1];
			strcpy(buffer, str.buffer);
		}
		else
		{
			buffer = nullptr;
		}
	}
	Mystring& operator=(const Mystring& str)
	{
		if (buffer != nullptr)
		{
			//将之前的内存释放掉
			delete[] buffer;
			buffer = nullptr;
		}
		if (str.buffer != nullptr)
		{
			//开辟空间存储buffer
			buffer = new char[strlen(str.buffer) + 1];
			strcpy(buffer, str.buffer);
		}
		return *this;
	}
	~Mystring()
	{
		if (buffer != nullptr)
		{
			delete[] buffer;
			buffer = nullptr;
		}
	}
private:
	char* buffer;
};

extern int a = 2;
