#include <iostream>
#include <vector>

// ���� ���� (selection sort)
// ���� �ε����� ���ؼ� ���� ���� �ε����� �ڸ� ��ü
// 2�� �ݺ����� ����ϱ� ������ �־��� ��� n*n = n^2 �� �ð����⵵�� ����.
void selectionSort(std::vector<int>& _arr)
{
	int min_index = 0;

	for (int i = 0; i < _arr.size() - 1; ++i)
	{
		min_index = i;

		for (int j = i + 1; j < _arr.size(); ++j)
		{
			if (_arr[min_index] > _arr[j])
				min_index = j;
		}

		std::swap(_arr[i], _arr[min_index]);
	}
}

// ���� ���� (bubble sort)
// ��ĭ�� �Űܰ��� ����ĭ�� ����.
// �� ũ�ų� �������� �ڷ� �ű�� ���� ���� ��ġ��Ű������.
// 2�� �ݺ����� ����ϱ� ������ �־��� ��� n*n = n^2 �� �ð����⵵�� ����.
void bubbleSort(std::vector<int>& _arr)
{
	for (int i = _arr.size() - 1; i > 0; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (_arr[j] > _arr[j + 1])
				std::swap(_arr[j], _arr[j + 1]);
		}
	}
}

// ���� ���� (insertion sort)
// key�� ������ �ڽź��� ���� ���� �ڿ� ������
// 2�� �ݺ����� ����ϱ� ������ �־��� ��� n*n = n^2 �� �ð����⵵�� ����.
void insertionSort(std::vector<int>& _arr)
{
	int key = 0;
	int res_index = 0;

	for (int i = 1; i < _arr.size(); ++i)
	{
		key = _arr[i];
		res_index = i - 1;

		// key ���� �������� �߰��Ҷ����� �迭�� �ڷ� �о��
		while (res_index >= 0 && _arr[res_index] > key)
		{
			_arr[res_index + 1] = _arr[res_index];
			--res_index;
		}

		// for ���� ���߸�, _arr[j] �� key ������ �۴ٴ°�.
		_arr[res_index + 1] = key;
	}
}

// �պ� ���� (merge sort)
// �����Ϸ��� �迭�� �������� ��� ������, ���� �迭�� ũ�Ⱑ 0 �Ǵ� 1�� �ɶ����� ������.
// ���� �迭�� ù��°���� �񱳸� �����Ͽ� �۰ų� ū���� �迭�� �տ� ������ �Ѵ�.
// �̸� �ݺ�
// ���Ұ��� �ð����⵵ O(log N) / �պ����� �ð����⵵ O(N) = �պ� ���� �ð����⵵ O(N log N)
void mergeSort(std::vector<int>& _arr)
{
	// �����Ͽ� ũ�Ⱑ 0 �Ǵ� 1�̵Ǹ� �� ����

	// ��� �Լ� Ż�� ����
	if (_arr.size() <= 1)
		return;

	int seek_pos = _arr.size() / 2;
	std::vector<int> v1, v2;
	v1.assign(_arr.begin(), _arr.begin() + seek_pos);
	v2.assign(_arr.begin() + seek_pos, _arr.end());

	// ��� �Լ��� �ּҴ������� ����
	mergeSort(v1);
	mergeSort(v2);

	int i = 0;
	int j = 0;
	int insert_index = 0;

	// �迭 ���� �ϳ��� �� ����������� ��
	while (i != v1.size() && j != v2.size())
	{
		if (v1[i] < v2[j])
		{
			_arr[insert_index] = v1[i];
			++i;
		}		
		else
		{
			_arr[insert_index] = v2[j];
			++j;
		}

		++insert_index;
	}
	
	// �� �� ���� �迭 ����
	while (i != v1.size())
	{
		_arr[insert_index] = v1[i];
		++insert_index;
		++i;
	}

	while (j != v2.size())
	{
		_arr[insert_index] = v2[j];
		++insert_index;
		++j;
	}
}

// �� ���� (quick sort)
// pivot point �� ������ left, right �� �������� ū���� ��ġ��.
// left �� �迭�� ���� ������, right �� �迭�� ������ ������ �񱳸� �����Ѵ�.
// �⺻������ pivot ���� ������ �Ǵ� ū���� �߰������� �񱳸� ���߰�,
// ���� �񱳰� ������ left �� right �� ��ü�Ѵ�.
// ���� left �� pivot ���� ���, �񱳸� �ٽ� �����Ѵ�.
void quickSort(std::vector<int>& _arr)
{
	if (_arr.size() <= 1)
		return;
	// pivot �� �������� �迭�� �Ǿ�, �ǵ�, �Ǵ� �߰����̳� ������ �������.
	int pivot = 0;

	int left = 1;
	int right = _arr.size() - 1;

	// �迭�� ������ ����
	int start = 1;
	int end = _arr.size() - 1;

	while (left < right)
	{
		// left ��
		// left �� ������ �����Ҷ����� �Ǵ� pivot ���� ū���� ã���� ���� �ݺ�
		while (left <= end && _arr[left] < _arr[pivot])
		{
			++left;		
		}

		// right ��
		// right �� ���� ���� �����Ҷ����� �Ǵ� pivot ���� ���� ���� ã�� �� ���� �ݺ�
		while (right >= start && _arr[right] > _arr[pivot])
		{
			--right;
		}

		if (left < right)
			std::swap(_arr[left], _arr[right]);
	}

	// left right �� ���������� �񱳰� ���� ����̴�.
	// ���� pivot �� swap ���ְ� pivot ��ġ�� �������� ���ο� ������ ������ ����
	std::swap(_arr[right], _arr[pivot]);

	pivot = right;

	std::vector<int> v1, v2;
	v1.assign(_arr.begin(), _arr.begin() + pivot);
	v2.assign(_arr.begin() + pivot + 1, _arr.end());

	quickSort(v1);
	quickSort(v2);

	// ������ ���� �迭 ���� �迭�� ����
	for (int i = 0; i < v1.size(); ++i)
	{
		_arr[i] = v1[i];
	}

	for (int i = 0; i < v2.size(); ++i)
	{
		_arr[pivot + 1 + i] = v2[i];
	}
}

//int main()
//{
//	std::vector<int> temp{ 9,8,1,3,2,17,89,150,23,37,7,4 };
//
//	quickSort(temp);
//
//	for (int i = 0; i < temp.size(); ++i)
//	{
//		std::cout << temp[i] << std::endl;
//	}
//
//	return 0;
//}