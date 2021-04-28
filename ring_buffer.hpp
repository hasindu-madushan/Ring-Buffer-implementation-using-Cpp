// ====================================================================
// Data    : 5 Feb 2020
// Title   : Ring Buffer Header 
// Version : 0.1
// ====================================================================

#include <cassert>


// ====================================================================
template< typename T > 
class RingBuffer
{
	public:	// public functions
		
		// costructor 
		RingBuffer() : head_(0), tail_(0)
		{
			// make all the elements 0
			for (int i = 0; i < k_max_size; i++)
				buffer_[i] = 0;	
		}
		
		// destructor 
		~RingBuffer()
		{
			// do nothing 	
		}
		
		// add a new item at the end 
		void push(T item)
		{
			// check if the array is full
			assert( (tail_ + 1)  % k_max_size  != head_);
			
			buffer_[tail_] = item;	// add item
			tail_ = (tail_ + 1) % k_max_size;	// change tail
		}
		
		// remove item at the head (start of the queue)
		T pop()
		{
			// head should not be equal to tail
			assert((head_ != tail_));
			
			int  temp = head_;
			head_ = (head_ + 1) % k_max_size;	// get the new head
			
			return buffer_[temp];	// return item at the old head
		}
		
		// return the current size of the queue
		int size()
		{
			return (head_ <= tail_) ? tail_ - head_ : k_max_size - head_ - 1 + tail_ ; 
		}
		
		// return true if the queue is empty
		bool empty()
		{
			return head_ == tail_;
		}
	
	
	private:	// private functions
		// empty
		
		
	public:	// public variables
		// emtpy	
		
		
	private:	// private variables 
		
		// maximum size of the array (queue)
		static const int k_max_size = 10;	
		
		// the items array 
		T buffer_[k_max_size];
		
		// head of the ring buffer
		int head_;
		
		// tail of the ring buffer
		int tail_;
		
		
		
};
