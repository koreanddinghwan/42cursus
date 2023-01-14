#include <iterator>

namespace ft {

template <typename T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
  private:
    T* ptr_;

  public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
	typedef T* iterator_type;

	random_access_iterator() : ptr_(nullptr) {}
    random_access_iterator(T* ptr) : ptr_(ptr) {}

    random_access_iterator& operator++()
    {
        ++ptr_;
        return *this;
    }

    random_access_iterator operator++(int)
    {
        random_access_iterator tmp(*this);
        ++ptr_;
        return tmp;
    }

    random_access_iterator& operator--()
    {
        --ptr_;
        return *this;
    }

    random_access_iterator operator--(int)
    {
        random_access_iterator tmp(*this);
        --ptr_;
        return tmp;
    }

	template<typename _T>
    random_access_iterator operator+(_T n) const
    {
        return random_access_iterator(ptr_ + n);
    }

	template<typename _T>
    random_access_iterator operator-(_T n) const
    {
        return random_access_iterator(ptr_ - n);
    }

	difference_type operator-(const random_access_iterator& o) {
		return (this->ptr_ - o.ptr_);
	}

    bool operator==(const random_access_iterator& other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const random_access_iterator& other) const
    {
        return ptr_ != other.ptr_;
    }

    bool operator<(const random_access_iterator& other) const
    {
        return ptr_ < other.ptr_;
    }

    bool operator>(const random_access_iterator& other) const
    {
        return ptr_ > other.ptr_;
    }

    bool operator<=(const random_access_iterator& other) const
    {
        return ptr_ <= other.ptr_;
    }

    bool operator>=(const random_access_iterator& other) const
    {
        return ptr_ >= other.ptr_;
    }

    T& operator*() const
    {
        return *ptr_;
    }

    T* operator->() const
    {
        return ptr_;
    }

	random_access_iterator operator += (int) {
		this->ptr_ += 1;
		return (this->ptr_);
	}

	random_access_iterator operator -= (int) {
		this->ptr_ -= 1;
		return (this->ptr_);
	}
};

}
