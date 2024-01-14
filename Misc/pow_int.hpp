
#ifndef POW_INT_HPP
#define POW_INT_HPP

template<class B, class P, class R = B> R pow_int(const B& b, const P& p) {
	static_assert(std::numeric_limits<B>::is_integer);
	static_assert(std::numeric_limits<P>::is_integer);
	if(std::numeric_limits<P>::is_signed) {
		if(p < static_cast<P>(0)) {
			throw "pow_int<B, P>(B b, P p): negative value of p";
		}
	}
	R b_cast = b;
	P p_cast = p;
	R r = static_cast<R>(1);
	while(p_cast != static_cast<P>(0)) {
		while((p_cast & static_cast<P>(1)) == static_cast<P>(0)) {
			b_cast *= b_cast;
			p_cast >>= 1;
		}
		r *= b_cast;
		p_cast--;
	}
	return r;
}

#endif
