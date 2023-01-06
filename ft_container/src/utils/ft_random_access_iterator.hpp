#include <iterator>

namespace ft {

template <typename T>
class random_access_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
  private:
    T* ptr_;

  public:
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
};

}
