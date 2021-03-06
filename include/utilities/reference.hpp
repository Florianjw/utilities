#ifndef UTILITIES_REFERENCE_HPP
#define UTILITIES_REFERENCE_HPP

#include <cassert>
#include <cstddef>
#include <type_traits>

#include "core.hpp"

namespace util {

template<typename T>
class reference {
public:
	static_assert(std::is_same<T, std::decay_t<T>>(),
			"T must be a fully decayed type");
	
	// there is no reasonable default-value, so:
	reference() = delete;
	
	// these are all just the defaults but it is nice to see them explicitly
	reference(const reference&) = default;
	reference(reference&&) = default;
	reference& operator=(const reference&) = default;
	reference& operator=(reference&&) = default;
	
	//Constructing from pointers is as fine as from references; we can however
	//not allow const references, since the saved value may be modified through
	//this class:
	reference(pointer<T> pointee) : ptr{pointee} {assert(ptr);}
	reference(T& pointee) : ptr{&pointee} {assert(ptr);}
	
	// there is no point in having a reference to a temporary object:
	reference(T&&) = delete;
	
	//disable illegal creation from nullptr, null, 0 and other stuff:
	reference(std::nullptr_t) = delete;
	template<typename Targ,
		class = typename std::enable_if<
			(!std::is_same<std::decay_t<Targ>, T>())
			|| (std::is_base_of<std::decay_t<T>, Targ>())>::type
	>
	reference(Targ) = delete;
	
	T& operator*() {return *ptr;}
	const T& operator*() const {return *ptr;}
	
	pointer<T> operator->() {return ptr;}
	const pointer<T> operator->() const {return ptr;}
	
	T& get() {return *ptr;}
	const T& get() const {return *ptr;}
	
	pointer<T> get_ptr() {return ptr;}
	const pointer<T> get_ptr() const {return ptr;}
	
	// we need this one for using this template in std::set and the like:
	bool friend operator<(const reference& l, const reference& r) {
		return l.ptr < r.ptr;
	}
	
	// comparing for equality is always usefull:
	bool friend operator==(const reference& l, const reference& r) {
		return l.ptr == r.ptr;
	}
	bool friend operator!=(const reference& l, const reference& r) {
		return l.ptr != r.ptr;
	}
	
	// The pointer in this class always points to something:
	explicit constexpr operator bool() const {return true;}
	constexpr bool operator!() const {return false;}
	
private:
	pointer<T> ptr;
};


}


#endif
