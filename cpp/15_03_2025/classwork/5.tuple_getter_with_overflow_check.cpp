#include <iostream>

template<typename... Types>
struct tuple {
    static_assert(false, "The non-specialized 'tuple<>' should never be instantiated.");
};


template<typename HeadType, typename... BodyTypes>
struct tuple<HeadType, BodyTypes...> {
    typedef HeadType head_type;
    typedef tuple<BodyTypes...> inner_type;

    HeadType _head;
    inner_type _body;

    tuple (const HeadType& head_, BodyTypes... body_)
        : _head(head_), _body(body_...) {}
};


template<>
struct tuple<> {
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


template<unsigned int Index>
struct getter<tuple<>, Index> {
    static_assert(false, "Index is out of range.");
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


template<unsigned int Index, typename TupleType>
const typename getter<TupleType, Index>::index_type& get(const TupleType& t) {
    return getter<TupleType, Index>::get(t);
}

template<unsigned int Index, typename TupleType>
typename getter<TupleType, Index>::index_type& get(TupleType& t) {
    return getter<TupleType, Index>::get(t);
}


int main() {
    tuple<float, std::string, int> t(5.2f, "letter", 61);
    std::cout << "The second item is: "<< get<1>(t) << std::endl;
    get<2>(t) += 12;
    std::cout << "The third item is: " << get<2>(t) << std::endl;
    std::cout << "The tenth item is: " << get<10>(t) << std::endl;
    return 0;
}
