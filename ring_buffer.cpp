

RingBuffer::RingBuffer() : head_(0), tail_(0)
{
	// make all the elements 0
	for (int i = 0; i < k_max_size; i++)
		buffer_[i] = 0;	
}


RingBuffer::~RingBuffer()
{
	// do nothing 	
}


void push(T item)
{
	// check if the array is full
	assert( (tail_ + 1)  % k_max_size  != head_);
	
	buffer_[tail_] = item;	// add item
	tail_ = (tail_ + 1) % k_max_size;	// change tail
}
		
