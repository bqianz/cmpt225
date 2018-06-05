template <typename T>
class Deque;

template <typename T>
class Node{
	// Node(Node<T>* n = NULL,Node<T>* p = NULL, T& e = T()): next(n), prev(p), elem(e) {};
private:
	T elem;
	Node<T>* next;
	Node<T>* prev;
	friend class Deque<T>;
};

template <typename T>
class Deque{
public:
	// constructor – creates an empty deque
	Deque();

	// copy constructor – a constructor that creates a deep copy of its constant Deque reference parameter
	Deque(const Deque &);

	// destructor – deallocates dynamic memory allocated by the deque
	~Deque();

	// operator= – overloads the assignment operator for Deque – (deep) copies its constant Deque reference parameter 
	// into the calling object and returns a reference to the calling object after de-allocating any dynamic memory 
	// associated with the original contents of the calling object; if the calling object is the same as the parameter 
	// the operator should not copy it
	Deque<T>& operator= (const Deque&);

	// insertFront – inserts its parameter at the front of the deque
	void insertFront(const T&);

	// insertBack – inserts its parameter at the back of the deque
	void insertBack(const T&);

	// removeFront – removes and returns the value at the front of the deque; if the deque is empty throws a 
	// runtime_error (this error class is defined in the stdexcept library file)
	T& removeFront();

	// removeBack – removes and returns the value at the back of the deque; if the deque is empty throws a runtime_error
	T& removeBack();

	// peekFront – returns the value at the front of the deque without removing it; if the deque is empty throws
	// a runtime_error
	T& peekFront() const;

	// peekBack – returns the value at the back of the deque without removing it; if the deque is empty throws
	// a runtime_error
	T& peekBack() const;

	// empty – returns true if the deque is empty, false otherwise
	bool empty() const;

	// is_null - returns tue if header or trailer is null
	bool is_null() const;

	// size – returns the number of items stored in the deque
	int size() const;

	void print_nodes();
	void print_nodes_reverse();

private:
	Node<T>* header;
	Node<T>* trailer;
};