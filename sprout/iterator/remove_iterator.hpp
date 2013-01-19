#ifndef SPROUT_ITERATOR_REMOVE_ITERATOR_HPP
#define SPROUT_ITERATOR_REMOVE_ITERATOR_HPP

#include <sprout/config.hpp>
#include <sprout/iterator/filter_iterator.hpp>

namespace sprout {
	//
	// remove_filter
	//
	template<typename T>
	class remove_filter {
	public:
		typedef bool result_type;
	private:
		T value_;
	public:
		SPROUT_CONSTEXPR remove_filter(T const& value)
			: value_(value)
		{}
		template<typename U>
		SPROUT_CONSTEXPR bool operator()(U const& value) const {
			return value != value_;
		}
	};

	//
	// make_remove_iterator
	//
	template<typename T, typename Iterator>
	inline SPROUT_CONSTEXPR sprout::filter_iterator<sprout::remove_filter<T>, Iterator>
	make_remove_iterator(T const& value, Iterator it, Iterator last = Iterator()) {
		return sprout::filter_iterator<sprout::remove_filter<T>, Iterator>(
			sprout::remove_filter<T>(value), it, last
			);
	}
}	// namespace sprout

#endif	// SPROUT_ITERATOR_REMOVE_ITERATOR_HPP
