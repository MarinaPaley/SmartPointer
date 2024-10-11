#pragma once
namespace SmartPtr
{
	template <typename T>
	class UniquePtr final
	{
	private:
		T* ptr;
	public:
		UniquePtr(const T value);
		~UniquePtr();
		UniquePtr(const UniquePtr& other) = delete;
		UniquePtr(UniquePtr&& other) noexcept;
		UniquePtr& operator=(const UniquePtr& other) = delete;
		UniquePtr& operator=(UniquePtr&& other) noexcept;
		T Get() const;
		void Swap(UniquePtr& other) noexcept;
		void Reset(UniquePtr& other) noexcept;
		T* Release();
	};

	template<typename T>
	inline UniquePtr<T>::UniquePtr(const T value)
		: ptr{ new T{value} }
	{
	}

	template<typename T>
	inline UniquePtr<T>::~UniquePtr()
	{
		delete this->ptr;
	}

	template<typename T>
	inline UniquePtr<T>::UniquePtr(UniquePtr&& other) noexcept
		: ptr {nullptr}
	{
		*this = std::move(other);
	}

	template<typename T>
	inline UniquePtr<T>& UniquePtr<T>::operator=(UniquePtr<T>&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(this->ptr, other.ptr);
		}

		return *this;
	}

	template<typename T>
	inline T UniquePtr<T>::Get() const
	{
		return *(this->ptr);
	}
	template<typename T>
	inline void UniquePtr<T>::Swap(UniquePtr& other) noexcept
	{
		std::swap(this->ptr, other.ptr);
	}

	template<typename T>
	inline void UniquePtr<T>::Reset(UniquePtr& other) noexcept
	{
		delete this->ptr;
		this->ptr = other.ptr;
		other.ptr = nullptr;
	}

	template<typename T>
	inline T* UniquePtr<T>::Release()
	{
		auto temp = this->ptr;
		this->ptr = nullptr;
		return temp;
	}
}