#include "./PmergeMe.hpp"

void PmergeMe::merge_deque(std::deque<int> &input_deque)
{
	// 입력 리스트를 두 개의 부분 리스트로 분할
	std::deque<int>::iterator middle;
	std::deque<int> left, right;

	// 입력 리스트를 두 개의 부분 리스트로 분할
	middle = input_deque.begin();
	std::advance(middle, input_deque.size() / 2);
	left.insert(left.end(), input_deque.begin(), middle);
	right.insert(right.end(), middle, input_deque.end());

	// 왼쪽과 오른쪽 부분 리스트에 대해 재귀적으로 Merge-insertion sort를 호출
	merge_insertion_sort_deque(left);
	merge_insertion_sort_deque(right);

	// 왼쪽과 오른쪽 부분 리스트를 병합
	std::deque<int> temp;
	std::deque<int>::iterator i = left.begin(), j = right.begin();
	while (i != left.end() && j != right.end()) {
		if (*i < *j) {
			temp.push_back(*i);
			++i;
		} else {
			temp.push_back(*j);
			++j;
		}
	}
	temp.insert(temp.end(), i, left.end());
	temp.insert(temp.end(), j, right.end());
	input_deque.swap(temp);
}

void PmergeMe::insertion_deque(std::deque<int> &input_deque) 
{
	for (std::deque<int>::iterator i = ++input_deque.begin(); i != input_deque.end(); ++i) {
		std::deque<int>::iterator j = i;
		std::deque<int>::iterator prev = i;
		--prev;
		while (j != input_deque.begin() && *(prev) > *j) {
			std::iter_swap(j, prev);
			j = prev;
			if (j != input_deque.begin()) --prev;
		}
	}
}

std::deque<int>::iterator PmergeMe::binary_search_deque(std::deque<int>::iterator begin, std::deque<int>::iterator end, const int& value) {
	std::deque<int>::iterator middle;
	while (begin != end) {
		middle = begin;
		std::advance(middle, std::distance(begin, end) / 2);
		if (*middle < value) {
			++middle;
			begin = middle;
		} else {
			end = middle;
		}
	}
	return end;
}


void PmergeMe::merge_insertion_sort_deque(std::deque<int> &input_deque)
{
	//임계값. 배열이 얼마나 작을때 merge대신 insertion쓸것인가
	//merge대신 insertion사용하면 공간복잡도가 감소하는 장점이 있음.
	//merge를 사용하면 재귀를 사용해서 stack영역이 계속 증가하는데, 큰 데이터셋에서는 merge-insert 로 두개 모두를 차용하는게 효율적.
	//input 배열이 임계값보다 클때는 병합정렬수행
	if (input_deque.size() > this->thresHold) 
		merge_deque(input_deque);
	else // 작은 부분 배열에 대해서는 Insertion sort를 호출
		insertion_deque(input_deque);
}

