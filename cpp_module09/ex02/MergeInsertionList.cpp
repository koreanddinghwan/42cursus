#include "./PmergeMe.hpp"

void PmergeMe::merge_list(std::list<int> &input_list) 
{
	// 입력 리스트를 두 개의 부분 리스트로 분할
	std::list<int>::iterator middle;
	std::list<int> left, right;

	// 입력 리스트를 두 개의 부분 리스트로 분할
	middle = input_list.begin();
	std::advance(middle, input_list.size() / 2);
	left.splice(left.end(), input_list, input_list.begin(), middle);
	right.splice(right.end(), input_list);

	// 왼쪽과 오른쪽 부분 리스트에 대해 재귀적으로 Merge-insertion sort를 호출
	merge_insertion_sort_list(left);
	merge_insertion_sort_list(right);

	// 왼쪽과 오른쪽 부분 리스트를 병합
	std::list<int> temp;
	std::list<int>::iterator i = left.begin(), j = right.begin();
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
	input_list.swap(temp);
}

void PmergeMe::insertion_list(std::list<int> &input_list) 
{
	for (std::list<int>::iterator i = ++input_list.begin(); i != input_list.end(); ++i) {
		std::list<int>::iterator j = i;
		std::list<int>::iterator prev = i;
		--prev;
		while (j != input_list.begin() && *(prev) > *j) {
			std::iter_swap(j, prev);
			j = prev;
			if (j != input_list.begin()) --prev;
		}
	}
}

void PmergeMe::merge_insertion_sort_list(std::list<int> &input_list) 
{
	//임계값. 배열이 얼마나 작을때 merge대신 insertion쓸것인가
	//merge대신 insertion사용하면 공간복잡도가 감소하는 장점이 있음.
	//merge를 사용하면 재귀를 사용해서 stack영역이 계속 증가하는데, 큰 데이터셋에서는 merge-insert 로 두개 모두를 차용하는게 효율적.

	//input 배열이 임계값보다 클때는 병합정렬수행
	if (input_list.size() > this->thresHold) 
		merge_list(input_list);
	else // 작은 부분 배열에 대해서는 Insertion sort를 호출
		insertion_list(input_list);
}
