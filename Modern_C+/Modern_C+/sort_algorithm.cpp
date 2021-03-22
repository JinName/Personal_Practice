#include <iostream>
#include <vector>

// 선택 정렬 (selection sort)
// 현재 인덱스와 비교해서 제일 작은 인덱스와 자리 교체
// 2중 반복문을 사용하기 때문에 최악의 경우 n*n = n^2 의 시간복잡도를 가짐.
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

// 버블 정렬 (bubble sort)
// 한칸씩 옮겨가며 다음칸과 비교함.
// 더 크거나 작은것을 뒤로 옮기며 제일 끝에 위치시키도록함.
// 2중 반복문을 사용하기 때문에 최악의 경우 n*n = n^2 의 시간복잡도를 가짐.
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

// 삽입 정렬 (insertion sort)
// key를 지정해 자신보다 작은 숫자 뒤에 삽입함
// 2중 반복문을 사용하기 때문에 최악의 경우 n*n = n^2 의 시간복잡도를 가짐.
void insertionSort(std::vector<int>& _arr)
{
	int key = 0;
	int res_index = 0;

	for (int i = 1; i < _arr.size(); ++i)
	{
		key = _arr[i];
		res_index = i - 1;

		// key 보다 작은값을 발견할때까지 배열을 뒤로 밀어낸다
		while (res_index >= 0 && _arr[res_index] > key)
		{
			_arr[res_index + 1] = _arr[res_index];
			--res_index;
		}

		// for 문이 멈추면, _arr[j] 가 key 값보다 작다는것.
		_arr[res_index + 1] = key;
	}
}

// 합병 정렬 (merge sort)
// 정렬하려는 배열을 절반으로 계속 나누어, 나눈 배열의 크기가 0 또는 1이 될때까지 나눈다.
// 이후 배열의 첫번째부터 비교를 시작하여 작거나 큰값이 배열의 앞에 오도록 한다.
// 이를 반복
// 분할과정 시간복잡도 O(log N) / 합병과정 시간복잡도 O(N) = 합병 정렬 시간복잡도 O(N log N)
void mergeSort(std::vector<int>& _arr)
{
	// 분할하여 크기가 0 또는 1이되면 비교 시작

	// 재귀 함수 탈출 조건
	if (_arr.size() <= 1)
		return;

	int seek_pos = _arr.size() / 2;
	std::vector<int> v1, v2;
	v1.assign(_arr.begin(), _arr.begin() + seek_pos);
	v2.assign(_arr.begin() + seek_pos, _arr.end());

	// 재귀 함수로 최소단위까지 분할
	mergeSort(v1);
	mergeSort(v2);

	int i = 0;
	int j = 0;
	int insert_index = 0;

	// 배열 둘중 하나가 다 비워질때까지 비교
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
	
	// 비교 후 남은 배열 삽입
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

// 퀵 정렬 (quick sort)
// pivot point 를 지정해 left, right 로 작은값과 큰값을 배치함.
// left 는 배열의 왼쪽 끝부터, right 는 배열의 오른쪽 끝부터 비교를 시작한다.
// 기본적으로 pivot 보다 작은값 또는 큰값을 발견했을때 비교를 멈추고,
// 양쪽 비교가 끝나면 left 와 right 를 교체한다.
// 이후 left 를 pivot 으로 잡고, 비교를 다시 시작한다.
void quickSort(std::vector<int>& _arr)
{
	if (_arr.size() <= 1)
		return;
	// pivot 의 기준점은 배열의 맨앞, 맨뒤, 또는 중간값이나 랜덤등 상관없다.
	int pivot = 0;

	int left = 1;
	int right = _arr.size() - 1;

	// 배열의 시작점 끝점
	int start = 1;
	int end = _arr.size() - 1;

	while (left < right)
	{
		// left 비교
		// left 가 끝점에 도달할때까지 또는 pivot 보다 큰값을 찾을때 까지 반복
		while (left <= end && _arr[left] < _arr[pivot])
		{
			++left;		
		}

		// right 비교
		// right 가 왼쪽 끝에 도달할때까지 또는 pivot 보다 작은 값을 찾을 때 까지 반복
		while (right >= start && _arr[right] > _arr[pivot])
		{
			--right;
		}

		if (left < right)
			std::swap(_arr[left], _arr[right]);
	}

	// left right 가 엇갈렸으면 비교가 끝난 경우이다.
	// 따라서 pivot 과 swap 해주고 pivot 위치를 기준으로 새로운 퀵정렬 범위를 지정
	std::swap(_arr[right], _arr[pivot]);

	pivot = right;

	std::vector<int> v1, v2;
	v1.assign(_arr.begin(), _arr.begin() + pivot);
	v2.assign(_arr.begin() + pivot + 1, _arr.end());

	quickSort(v1);
	quickSort(v2);

	// 정렬이 끝난 배열 원래 배열에 정리
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