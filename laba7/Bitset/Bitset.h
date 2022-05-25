#pragma once

#include <stdexcept>

template<size_t Bits>
class Bitset
{
	using Type = unsigned long long;

	static constexpr size_t _Bitsperword = CHAR_BIT * sizeof(Type);
	static constexpr size_t _Words = Bits == 0 ? 0 : (Bits - 1) / _Bitsperword + 1;

	Type _Array[_Words];

public:

	class reference
	{
		friend class Bitset<Bits>;
	private:

		Bitset<Bits>* _PtrBitset;
		size_t _Mypos; // position of element in bitset

		reference(Bitset<Bits>& ptr, size_t pos) : _PtrBitset(&ptr), _Mypos(pos) {}

		reference() noexcept : _PtrBitset(nullptr), _Mypos(0) {}
	public:

		~reference() noexcept {}

		reference& operator=(bool val) noexcept
		{
			_PtrBitset->set_unchecked(_Mypos, val);
			return *this;
		}

		reference& operator=(const reference& bit_ref) {
			_PtrBitset->set_unchecked(_Mypos, static_cast<bool>(bit_ref));
			return *this;
		}

		reference& flip() {
			_PtrBitset->flip_unchecked(_Mypos);
			return *this;
		}

		bool operator~() const {
			return !_PtrBitset->subscript(_Mypos);
		}

		operator bool() const noexcept { return _PtrBitset->subscript(_Mypos); }
	};

	Bitset() : _Array{} {}

	Bitset(unsigned long long val) : _Array{ val } {}

	Bitset(const std::string& val) : _Array{}
	{
		size_t count = val.size() > Bits ? Bits : val.size(), pos = 0;

		for (size_t i = count - 1; i >= 0; --i)
		{
			set_unchecked(pos, val[i] == '1');
			++pos;
		}
	}

	reference operator[](size_t pos) {
		if (pos < Bits) {
			return reference(*this, pos);
		}

		throw std::out_of_range("bitset index outside range");
	}

	bool operator[](size_t pos) const {
		if (pos < Bits) {
			return subscript(pos);
		}

		throw std::out_of_range("bitset index outside range");
	}

	Bitset& flip() {
		for (size_t pos = 0; pos < _Words; ++pos) {
			_Array[pos] = ~_Array[pos];
		}

		trim();
		return *this;
	}

	Bitset& flip(size_t pos)
	{
		if (Bits <= pos) {
			throw std::out_of_range("bitset out of range");
		}
		_Array[pos / _Bitsperword] ^= Type{ 1 } << pos % _Bitsperword;
		return *this;
	}

	bool all() const {
		bool zero_length = Bits == 0;
		if (zero_length) { // must test for this, otherwise would count one full word
			return true;
		}

		bool no_padding = Bits % _Bitsperword == 0;
		for (size_t w_pos = 0; w_pos < _Words + no_padding - 1; ++w_pos) {
			if (_Array[w_pos] != ~static_cast<Type>(0)) {
				return false;
			}
		}

		return no_padding || _Array[_Words - 1] == (static_cast<Type>(1) << (Bits % _Bitsperword)) - 1;
	}

	bool any() const {
		for (size_t pos = 0; pos < _Words; ++pos) {
			if (_Array[pos] != 0) {
				return true;
			}
		}

		return false;
	}

	size_t size() const { return Bits; }

	bool test(size_t pos) const {
		if (Bits <= pos) {
			throw std::out_of_range("bitset out of range"); // pos off end
		}

		return subscript(pos);
	}

	bool none() const {
		return !any();
	}

	Bitset& set(size_t pos, bool val = true) noexcept { // set all bits true 
		if (Bits <= pos) {
			throw std::out_of_range("bitset out of range"); // pos off end
		}

		set_unchecked(pos, val);
		return *this;
	}

	Bitset& set() noexcept { // set all bits true
		for (size_t i = 0; i < _Words; ++i) {
			_Array[i] = ULLONG_MAX;
		}
		trim();
		return *this;
	}

	Bitset& reset() noexcept { // set all bits false
		for (size_t i = 0; i < _Words; ++i) {
			_Array[i] = 0;
		}
		return *this;
	}

	Bitset& reset(size_t pos) { // set bit at pos to false
		return set(pos, false);
	}

	Bitset operator<<(size_t pos) const {
		Bitset tmp = *this;
		tmp <<= pos;
		return tmp;
	}

	Bitset operator>>(size_t pos) const {
		Bitset tmp = *this;
		tmp >>= pos;
		return tmp;
	}

	Bitset& operator&=(const Bitset& right) noexcept {
		for (size_t w_pos = 0; w_pos < _Words; ++w_pos) {
			_Array[w_pos] &= right._Array[w_pos];
		}

		return *this;
	}

	Bitset& operator|=(const Bitset& right) noexcept {
		for (size_t w_pos = 0; w_pos < _Words; ++w_pos) {
			_Array[w_pos] |= right._Array[w_pos];
		}

		return *this;
	}

	Bitset& operator^=(const Bitset& right) noexcept {
		for (size_t w_pos = 0; w_pos < _Words; ++w_pos) {
			_Array[w_pos] ^= right._Array[w_pos];
		}

		return *this;
	}

	std::string to_string() const
	{
		std::string str;
		str.reserve(Bits);
		char zero = '0', one = '1';
		for (auto pos = Bits; 0 < pos;) {
			str.push_back(subscript(--pos) ? one : zero);
		}

		return str;
	}

	unsigned long long to_ullong() const    //throws std::overflow_error
	{
		if (Bits == 0) return 0;
		bool _bits_large = Bits > 64;

		if (_bits_large) {
			for (size_t indx = 1; indx < _Words; ++indx) {
				if (_Array[indx] != 0) {
					throw std::overflow_error("bitset overflow"); // fail if any high-order words are nonzero
				}
			}
		}

		return _Array[0];
	}

	unsigned long to_ulong() const {
		bool _bits_large = Bits > 64;

		if (Bits == 0)  return 0;

		if (Bits <= 32) {
			return static_cast<unsigned long>(_Array[0]);
		}

		if (_bits_large) {
			for (size_t indx = 1; indx <= _Words; ++indx) {
				if (_Array[indx] != 0) {
					throw std::overflow_error("bitset overflow"); // fail if any high-order words are nonzero
				}
			}
		}

		if (_Array[0] > ULONG_MAX) {
			throw std::overflow_error("bitset overflow");
		}

		return static_cast<unsigned long>(_Array[0]);
	}


private:
	constexpr bool subscript(size_t pos) const
	{
		return (_Array[pos / _Bitsperword] & (Type{ 1 } << pos % _Bitsperword)) != 0;
	}

	Bitset& set_unchecked(size_t pos, bool val) noexcept
	{
		auto& selected_word = _Array[pos / _Bitsperword];
		const auto bit = Type{ 1 } << pos % _Bitsperword;
		if (val) {
			selected_word |= bit;
		}
		else {
			selected_word &= ~bit;
		}

		return *this;
	}

	void trim() { // clear any trailing bits in last word
		bool work_to_do = Bits == 0 || Bits % _Bitsperword != 0;
		if (work_to_do) {
			_Array[_Words - 1] &= (Type{ 1 } << Bits % _Bitsperword) - 1;
		}
	}

	Bitset& flip_unchecked(size_t pos) noexcept
	{
		auto& selected_word = _Array[pos / _Bitsperword];
		const auto bit = Type{ 1 } << pos % _Bitsperword;
		selected_word ^= bit;

		return *this;
	}


};

template <size_t Bits>
Bitset<Bits> operator&(const Bitset<Bits>& left, const Bitset<Bits>& right) noexcept {
	Bitset<Bits> answer = left;
	answer &= right;
	return answer;
}

template <size_t Bits>
Bitset<Bits> operator|(const Bitset<Bits>& left, const Bitset<Bits>& right) noexcept {
	Bitset<Bits> answer = left;
	answer |= right;
	return answer;
}

template <size_t Bits>
Bitset<Bits> operator^(const Bitset<Bits>& left, const Bitset<Bits>& right) noexcept {
	Bitset<Bits> answer = left;
	answer ^= right;
	return answer;
}