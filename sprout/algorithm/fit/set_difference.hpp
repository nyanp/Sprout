#ifndef SPROUT_ALGORITHM_FIT_SET_DIFFERENCE_HPP
#define SPROUT_ALGORITHM_FIT_SET_DIFFERENCE_HPP

#include <sprout/config.hpp>
#include <sprout/iterator/distance.hpp>
#include <sprout/container/traits.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fixed/set_union.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/sub_array/sub_array.hpp>
#include <sprout/sub_array/sub.hpp>
#include <sprout/detail/algorithm/set_overlap_count.hpp>
#include HDR_ALGORITHM_MIN_MAX_SSCRISK_CEL_OR_SPROUT
#include <sprout/iterator/type_traits/is_iterator.hpp>

namespace sprout {
	namespace fit {
		namespace detail {
			template<typename InputIterator1, typename InputIterator2, typename Result, typename Compare>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
			set_difference_impl(
				InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2,
				Result const& result, Compare comp,
				typename sprout::container_traits<Result>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::set_difference(first1, last1, first2, last2, result, comp)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT::min(
						sprout::distance(first1, last1)
							- sprout::detail::set_overlap_count(first1, last1, first2, last2, comp)
							,
						sprout::size(result)
						)
					);
			}
		}	// namespace detail
		//
		// set_difference
		//
		template<typename InputIterator1, typename InputIterator2, typename Result, typename Compare>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
		set_difference(
			InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2,
			Result const& result, Compare comp
			)
		{
			static_assert(
				sprout::is_forward_iterator<InputIterator1>::value && sprout::is_forward_iterator<InputIterator2>::value,
				"Sorry, not implemented."
				);
			return sprout::fit::detail::set_difference_impl(first1, last1, first2, last2, result, comp, sprout::internal_begin_offset(result));
		}

		namespace detail {
			template<typename InputIterator1, typename InputIterator2, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
			set_difference_impl(
				InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, InputIterator2 last2,
				Result const& result,
				typename sprout::container_traits<Result>::difference_type offset
				)
			{
				return sprout::sub_copy(
					sprout::get_internal(sprout::fixed::set_difference(first1, last1, first2, last2, result)),
					offset,
					offset + NS_SSCRISK_CEL_OR_SPROUT::min(
						sprout::distance(first1, last1)
							- sprout::detail::set_overlap_count(first1, last1, first2, last2)
							,
						sprout::size(result)
						)
					);
			}
		}	// namespace detail
		//
		// set_difference
		//
		template<typename InputIterator1, typename InputIterator2, typename Result>
		inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
		set_difference(
			InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2,
			Result const& result
			)
		{
			static_assert(
				sprout::is_forward_iterator<InputIterator1>::value && sprout::is_forward_iterator<InputIterator2>::value,
				"Sorry, not implemented."
				);
			return sprout::fit::detail::set_difference_impl(first1, last1, first2, last2, result, sprout::internal_begin_offset(result));
		}
	}	// namespace fit
}	// namespace sprout

#endif	// #ifndef SPROUT_ALGORITHM_FIT_SET_DIFFERENCE_HPP
