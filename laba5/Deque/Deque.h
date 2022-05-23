#pragma once 

#include <algorithm>

template<class T>
class deque
{
public:
    class iterator;
private:

    static constexpr size_t initial_baseArray_size = 8;

    T** baseArray;
    size_t baseArray_size;

    static constexpr size_t block_size = 16;

    size_t _size; 

    iterator start;
    iterator finish;
public:
    class iterator
    {
        friend class deque;
    private:
        T** node; 
        T* curr;
        T* first;	
        T* last;

    public:
        iterator() = default;

        iterator(const iterator& x) : curr(x.curr), first(x.first), last(x.last), node(x.node) {}

        iterator(T* x, T** baseArray_pointer)
            : curr(x), first(*baseArray_pointer), last(*baseArray_pointer + block_size), node(baseArray_pointer) {}

        iterator& operator++()
        {
            ++curr;
            if (curr == last) {
                set_node(node + 1);
                curr = first;
            }
            return *this;
        }

        iterator& operator--()
        {
            if (curr == first) {
                set_node(node - 1);
                curr = last;
            }
            else {
                --curr;
            }
            return *this;
        }

        iterator& operator+=(ptrdiff_t n)
        {
            ptrdiff_t offset = n + curr - first;

            if (offset >= 0 && offset <= block_size) {		
                curr += offset;
            }
            else {
                ptrdiff_t node_offset;
                if (offset > 0) {
                    node_offset = offset / block_size;
                }
                else {
                    node_offset = (offset + 1) / block_size - 1;
                }

                set_node(node + node_offset);

                curr = first + (offset - node_offset * block_size);
            }
            return *this;
        }

        iterator operator+(ptrdiff_t n) const
        {
            auto temp = *this;
            return temp += n;
        }

        iterator operator-(ptrdiff_t n) const
        {
            auto temp = *this;
            return temp += -n;
        }

        T& operator[](size_t index)
        {
            return *(*this + index);
        }

        T& operator*() { return *curr; }

        bool operator!=(const iterator& other) { return other.curr != curr; }

    private:
        void set_node(T** new_node)
        {
            node = new_node;
            first = *new_node;
            last = first + block_size;
        }
    };

    deque() : baseArray(nullptr), _size(0), baseArray_size(0)
    {
        create_baseArray_and_nodes(0);
    }

    ~deque()
    {
        for (T** node = start.node; node <= finish.node; ++node) {
            delete[] * node;
        }
        delete[] baseArray;
    }

    void push_back(const T& value) {
        if (finish.curr != finish.last - 1) {
            *finish.curr = value;
            ++finish.curr;
        }
        else {
            push_back_aux(value);
        }
        ++_size;
    }

    void pop_back() {
        if (!empty()) {
            if (finish.curr != finish.first) {
                --finish.curr;
            }
            else {
                finish.set_node(finish.node - 1);
                finish.curr = finish.last - 1;
            }
            --_size;
        }
    }

    void push_front(const T& value)
    {
        if (start.curr != start.first) {
            --start.curr;
            *start.curr = value;
        }
        else {
            T t_copy = value;
            reserve_baseArray_at_front();
            *(start.node - 1) = new T[block_size];
            start.set_node(start.node - 1);
            start.curr = start.last - 1;
            *start.curr = t_copy;
        }
        ++_size;
    }

    void pop_front()
    {
        if (!empty()) {
            if (start.curr != start.last - 1) {
                ++start.curr;
            }
            else {
                start.set_node(start.node + 1);
                start.curr = start.first;
            }
            --_size;
        }
    }

    void clear() {
        for (T** node = start.node; node <= finish.node; ++node) {
            delete[] * node;
        }
        delete[] baseArray;
        _size = 0;
        create_baseArray_and_nodes(0);
    }

    size_t size() const { return _size; }

    bool empty() const { return _size == 0; }

    T& operator[](size_t index) { return start[index]; }

    iterator begin() { return start; }

    iterator end() { return finish; }

    void resize(size_t count, const T& value = T())
    {
        size_t curr_size = _size;
        if (count > _size) {
            for (int i = 0; i < count - curr_size; ++i) {
                push_back(value);
            }
        }
        else {
            for (int i = 0; i < curr_size - count; ++i) {
                pop_back();
            }
        }
    }

    //+----------------------------------------------+
    //| Private functions for reallocation of memory |
    //+----------------------------------------------+

private:
    void reallocate_baseArray(size_t nodes_to_add, bool add_at_front) {
        size_t old_num_nodes = finish.node - start.node + 1;
        size_t new_num_nodes = old_num_nodes + nodes_to_add;
        T** new_nstart;
        if (baseArray_size > 2 * new_num_nodes) {
            new_nstart = baseArray + (baseArray_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
            if (new_nstart < start.node) {
                std::copy(start.node, finish.node + 1, new_nstart);
            }
            else {
                std::copy_backward(start.node, finish.node + 1, new_nstart + old_num_nodes);
            }
        }
        else {
            size_t new_baseArray_size = baseArray_size + std::max(baseArray_size, nodes_to_add) + 2;
            T** new_baseArray = new T * [new_baseArray_size];
            new_nstart = new_baseArray + (new_baseArray_size - new_num_nodes) / 2 + (add_at_front ? nodes_to_add : 0);
            std::copy(start.node, finish.node + 1, new_nstart);
            delete[] baseArray;
            baseArray = new_baseArray;
            baseArray_size = new_baseArray_size;
        }
        start.set_node(new_nstart);
        finish.set_node(new_nstart + old_num_nodes - 1);
    }

    void reserve_baseArray_at_back(size_t nodes_to_add = 1) {
        if (nodes_to_add > baseArray_size - (finish.node - baseArray) - 1) {
            reallocate_baseArray(nodes_to_add, false);
        }
    }

    void reserve_baseArray_at_front(size_t nodes_to_add = 1) {
        if (nodes_to_add > start.node - baseArray) {
            reallocate_baseArray(nodes_to_add, true);
        }
    }

    void push_back_aux(const T& t) {
        T t_copy = t;
        reserve_baseArray_at_back();
        *(finish.node + 1) = new T[block_size];
        *finish.curr = t_copy;
        finish.set_node(finish.node + 1);
        finish.curr = finish.first;
    }


    void create_baseArray_and_nodes(size_t num_elements) {
        size_t num_nodes = num_elements / block_size + 1;
        baseArray_size = std::max(initial_baseArray_size, num_nodes + 2);
        baseArray = new T * [baseArray_size];
        T** nstart = baseArray + (baseArray_size - num_nodes) / 2;
        T** nfinish = nstart + num_nodes - 1;
		
        for (T** cur = nstart; cur <= nfinish; cur++) {
            *cur = new T[block_size];
        }
		
        start.set_node(nstart);
        finish.set_node(nfinish);
        start.curr = start.first;
        finish.curr = finish.first + num_elements % block_size;
    }
};