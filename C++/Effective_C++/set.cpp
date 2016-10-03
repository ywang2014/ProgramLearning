/**
	使用list实现set
	空间优先于时间的case
*/
template<class T>
class Set{
	public:
		bool member(const T &item) const;
		void insert(const T &item);
		void remove(const T &item);
		std::size_t size() const;
	private:
		std::list<T> set;
};

template<typename T>
bool Set<T>::member(const T &item) const{
	return std::find(set.begin(), set.end(), item) != set.end();
}

template<typename T>
void Set<T>::insert(const T &item){
	if (!member(item)){
		set.puch_back(item);
	}
}

template<typename T>
void Set<T>::remove(const T &item){
	typename std::list<T>::iterator it = std::find(set.begin(), set.end(), item);
	if (it != set.end()){
		set.erase(it);
	}
}

template<typename T>
std::size_t Set<T>::size() const{
	return set.size();
}
	
	
	