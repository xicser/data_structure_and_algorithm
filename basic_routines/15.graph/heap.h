#ifndef __HEAP_H__
#define __HEAP_H__

#include <unordered_map>
#include <functional>

using namespace std;

class Heap {
private:
	int heapSize;
	int heapSizeLimit;
	void** heapArray;
	//比较器, 用于确定堆中元素的"逻辑大小关系"
	function<bool(const void* a, const void* b)> comparator;

	//记录当前堆上某个节点在数组中的下标
	unordered_map<void*, int> indexMap;

	void heapInsert(int index);
	void heapify(int index);
	void swap(int i, int j);

public:
	Heap(int limit, function<bool(const void* a, const void* b)> comparator);
	~Heap();
	void  push(void* value);
	void* top();
	void  pop();
	void  adjust(void* value);
	bool  empty();
	bool  full();
	int   size();
};

#endif
