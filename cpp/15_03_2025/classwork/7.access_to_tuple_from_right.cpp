#include <iostream>

template<typename... Types>
struct tuple {
    static_assert(false, "The non-specialized 'tuple<>' should never be instantiated.");
};


template<typename HeadType, typename... BodyTypes>
struct tuple<HeadType, BodyTypes...> {
    typedef HeadType head_type;
    typedef tuple<BodyTypes...> inner_type;

    static constexpr int size = 1 + tuple<BodyTypes...>::size;
    HeadType _head;
    inner_type _body;

    tuple (const HeadType& head_, BodyTypes... body_)
        : _head(head_), _body(body_...) {}
};


template<>
struct tuple<> {
    static constexpr int size = 0;
};

template<typename TupleType, unsigned int Index>
struct getter {
    typedef typename TupleType::inner_type inner_tuple_type;
    typedef typename getter<inner_tuple_type, Index - 1>::index_type index_type;
    typedef getter<inner_tuple_type, Index - 1> inner_getter_type;

    static const index_type& get(const TupleType& t) {
        return inner_getter_type::get(t._body);
    }

    static index_type& get(TupleType& t) {
        return inner_getter_type::get(t._body);
    }
};


template<typename TupleType>
struct getter<TupleType, 0> {
    typedef typename TupleType::head_type index_type;

    static const index_type& get(const TupleType& t) {
        return t._head;
    }

    static index_type& get(TupleType& t) {
        return t._head;
    }
};

// Helper struct to calculate the correct index from the right
template<unsigned int Size, unsigned int Index>
struct right_index {
    static constexpr unsigned int value = Size - Index - 1;
};

template<typename TupleType, unsigned int Index>
struct right_getter {
    static constexpr unsigned int adjusted_index = right_index<TupleType::size, Index>::value;
    typedef typename getter<TupleType, adjusted_index>::index_type index_type;

    static const index_type& get(const TupleType& t) {
        return getter<TupleType, adjusted_index>::get(t);
    }

    static index_type& get(TupleType& t) {
        return getter<TupleType, adjusted_index>::get(t);
    }
};


template<unsigned int Index, typename TupleType>
const typename getter<TupleType, Index>::index_type& get(const TupleType& t) {
    return getter<TupleType, Index>::get(t);
}

template<unsigned int Index, typename TupleType>
typename getter<TupleType, Index>::index_type& get(TupleType& t) {
    return getter<TupleType, Index>::get(t);
}


template<unsigned int Index, typename TupleType>
const typename right_getter<TupleType, Index>::index_type& right_get(const TupleType& t) {
    return right_getter<TupleType, Index>::get(t);
}

template<unsigned int Index, typename TupleType>
typename right_getter<TupleType, Index>::index_type& right_get(TupleType& t) {
    return right_getter<TupleType, Index>::get(t);
}

int main() {
    tuple<float, std::string, int> t(5.2f, "letter", 61);
    std::cout << "The second item is: "<< get<1>(t) << std::endl;
    get<2>(t) += 12;
    std::cout << "The third item is: " << get<2>(t) << std::endl;
    std::cout << "t.size = " << t.size << std::endl;
    std::cout << "The last item is: " << right_get<1>(t) << std::endl;
    return 0;
}
