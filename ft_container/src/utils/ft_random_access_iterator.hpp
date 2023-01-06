#include <iterator>

namespace ft {

template <typename T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
  private:
    T* ptr_;

  public:
	typedef random_access_iterator<T> iterator_type;
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

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

    random_access_iterator operator+(size_t n) const
    {
        return random_access_iterator(ptr_ + n);
    }

    random_access_iterator operator-(size_t n) const
    {
        return random_access_iterator(ptr_ - n);
    }

    random_access_iterator operator+(int n) const
    {
        return random_access_iterator(ptr_ + n);
    }

    random_access_iterator operator-(int n) const
    {
        return random_access_iterator(ptr_ - n);
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

	iterator_type& operator+=(difference_type n) { 
		this->ptr_ += n; 
		return *this; 
	}

    iterator_type& operator-=(difference_type n) { 
		this->ptr_ -= n; 
		return *this; 
	}

    iterator_type operator+(difference_type n) const { 
		return iterator_type(this->ptr_ + n); 
	}

    iterator_type operator-(difference_type n) const { 
		return iterator_type(this->ptr_ - n); 
	}



    difference_type operator-(const iterator_type& other) const {
		return this->ptr_ - other.ptr_; }
};

}
