template<typename T1, typename T2>
class Pair{
public:
	Pair(T1& c, T2& d):a(c),b(d){}
	virtual void printPair{}
private:
	T1 a;
	T2 b;
}
