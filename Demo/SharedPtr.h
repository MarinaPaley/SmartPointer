#pragma once
namespace SmartPtr
{
	template <typename T>
	class SharedPtr final
	{
	private:
		T* ptr;
	public:
		static int count;
		static SharedPtr MakeShared(T value);
		SharedPtr(T value);
		SharedPtr(const SharedPtr& other);
		SharedPtr(SharedPtr&& other) noexcept = delete;
		SharedPtr& operator=(const SharedPtr& other);
		SharedPtr& operator=(SharedPtr&& other) noexcept = delete;
		~SharedPtr();
		T Get() const noexcept;
	};

	template<typename T>
	inline int SharedPtr<T>::count{ 0 };

	template<typename T>
	inline SharedPtr<T> SharedPtr<T>::MakeShared(T value)
	{
		return SharedPtr(value);
	}

	template<typename T>
	inline SharedPtr<T>::SharedPtr(T value)
		: ptr{new T{value}}
	{
		++count;
	}

	template<typename T>
	inline SharedPtr<T>::SharedPtr(const SharedPtr& other)
		: ptr{other.ptr}
	{
		++count;
	}

	template<typename T>
	inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<T>& other)
	{
		if (this != &other)
		{
			delete this->ptr;
			this->ptr = other.ptr;
		}

		return *this;
	}

	template<typename T>
	inline SharedPtr<T>::~SharedPtr()
	{
		--count;
		if (count == 0)
		{
			delete this->ptr;
		}
	}
	template<typename T>
	inline T SharedPtr<T>::Get() const noexcept
	{
		return *(this->ptr);
	}
}