#include "ArrayList.h"

/**
 * @brief      Default Constructor.
 *
 * @tparam     T     Typename
 */
template<class T>
ArrayList<T>::ArrayList() :
	m_size(0),
	m_capacity(SIZE_INCREMENT)
{
	pElements = new T[SIZE_INCREMENT];
}

/**
 * @brief      Clear the ArrayList
 *
 * @tparam     T     Typename
 */
template<class T>
void ArrayList<T>::clear()
{
	/** @todo Clear the list and shrink the array. **/
	m_size = 0;
	m_capacity = SIZE_INCREMENT;
}

/**
 * @brief      Adds a thing to the ArrayList
 *
 * @param[in]  toPush  The to be added.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::add(const T& toPush)
{
	/**
	 * @todo Add toPush to the end of the array,
	 * allocating resources if adding another
	 * element exceeds current capacity.
	 * 
	 * Please use "new"
	 */
	 if (m_size == m_capacity) {
	 	T * pele = new T [m_capacity];
	 	int i;
	 	for (i = 0; i < m_size; i++) {
	 		pele[i] = pElements[i];
	 	}

	 	m_capacity = m_capacity + SIZE_INCREMENT;
	 	pElements = new T [m_capacity];
	 	for (i = 0; i < m_size; i++) {
	 		pElements[i] = pele[i];
	 	}

	 }

	 pElements[m_size] = toPush;
	 m_size++;
}

/**
 * @brief      Adds a thing in a specific index.
 *
 * @param[in]  toPush  Thing to add
 * @param[in]  index   Where it is to be added.
 *
 * @tparam     T       Type of thing
 */
template<class T>
void ArrayList<T>::add(const T& toPush, int index)
{
	/**
	 * @todo Add toPush to the array in the specified index.
	 * Again, reallocate if necessary.
	 */

	 if (m_size == m_capacity) {
	 	T * pele = new T [m_capacity];
	 	int i;
	 	for (i = 0; i < m_size; i++) {
	 		pele[i] = pElements[i];
	 	}

	 	m_capacity = m_capacity + SIZE_INCREMENT;
	 	pElements = new T [m_capacity];
	 	for (i = 0; i < m_size; i++) {
	 		pElements[i] = pele[i];
	 	}

	 }

	 int i;
	 for (i = m_size - 1; i >= index; i--) {
	 	pElements[i + 1] = pElements[i];
	 }

	 pElements[index] = toPush;
	 m_size++;
}

/**
 * @brief      Pushes to the back of the list.
 *
 * @param[in]  toPush  Thing to push back.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_back(const T& toPush)
{
	/**
	 * @todo Add toPush to the back of the array.
	 */
	 add(toPush);
}

/**
 * @brief      Push a thing to the front of the list.
 *
 * @param[in]  toPush  Thing to be pushed.
 *
 * @tparam     T       Typename
 */
template<class T>
void ArrayList<T>::push_front(const T& toPush)
{
	/**
	 * @todo Add toPUsh to the front of the array.
	 */
	 add(toPush, 0);
}

/**
 * @brief      Remove the item at a specific index.
 *
 * @param[in]  index  Index of the thing to be removed.
 *
 * @tparam     T      Typename
 *
 * @return     Shallow copy of the item we removed.
 */
template<class T>
const T ArrayList<T>::remove(int index)
{
	T myT = T();
	/**
	 * @todo Remove the item in the index-th
	 * index and return it.
	 */
	int i;
	if (index >= m_size) {
		return myT;
	}
	myT = pElements[index];
	for (i = index + 1; i < m_size; i++) {
		pElements[i - 1] = pElements[i];
	}
	m_size--;
	return myT;
}

/**
 * @brief      Removes a particular item from the list.
 *
 * @param[in]  toRemove  Thing to remove.
 * @param      ok        True upon successful removal.
 *
 * @tparam     T         Typename
 */
template<class T>
void ArrayList<T>::remove(const T & toRemove, bool * ok) {
	/**
	 * @todo Find and remove toRemove within the array.
	 *  Upon successful removal, set ok to true.
	 */
	 int p = indexOf(toRemove);
	 if (p > 0) {
	 	remove(p);
	 	*ok = true;
	 } else {
	 	*ok = false;
	 }
}

/**
 * @brief      Check if an item is in the ArrayList.
 *
 * @param[in]  object The thing we want to know about.
 *
 * @tparam     T       Typename
 *
 * @return     Returns true if it's there.
 */
template<class T>
bool ArrayList<T>::contains(const T& object)
{
	/**
	 * @todo Return true if object is in the list.
	 */
	int p;
	p = indexOf(object);
	 if (p < 0) {
	 	return false;
	 } else {
	 	return true;
	 }
}

/**
 * @brief      Returns the first index of T.
 *
 * @param[in]  object  Thing.
 *
 * @tparam     T       Typename
 *
 * @return     The first index of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object)
{
	/**
	 * @todo Find the index of object in the array,
	 * or return -1 if not found.
	 */
	 int i;
	 for (i = 0; i < m_size; i++) {
	 	if (pElements[i] == object) {
	 		return i;
	 	}
	 }
	 return -1;

}

/**
 * @brief      Return the ith occurance of T.
 *
 * @param[in]  object     Thing.
 * @param[in]  occurance  Occurance of thing to find.
 *
 * @tparam     T          Type of thing.
 *
 * @return     Location of thing.
 */
template<class T>
int ArrayList<T>::indexOf(const T& object, int occurrence)
{
	/**
	 * @todo Return the index of the occurrence-th
	 * occurrence of object.
	 */
	int i;
	int j = 0;
	for (i = 0; i < m_size; i++) {
		if (pElements[i] == object) {
			j++;
		}

		if (j == occurrence) {
			return i;
		}
	}

	return -1;
}

/**
 * @brief      Check for the last index of an object.
 *
 * @param[in]  object  Thing to check
 *
 * @tparam     T       Typename
 *
 * @return     Integer location of the last location, or -1.
 */
template<class T>
int ArrayList<T>::lastIndexOf(const T& object)
{
	/**
	 * @todo Return the last index of object in the array.
	 */
	int i;
	for (i = m_size - 1; i>=0; i--) {
		if (pElements[i] == object) {
			return i;
		}
	}
	return -1;
}

/**
 * @brief      Sorts the given list in ascending order.
 * 
 * This sorts the list in ascending order. It is assumed
 * that the < operator has been overloaded.
 *
 * @tparam     T   type.  
 */
template<class T>
void ArrayList<T>::sort()
{
	/**
	 * @todo Sort the array in ascending order.
	 */
	 T temp;
	 int i = 0;
	 int j;
	 for (i = 0; i < m_size - 1; i++) {
	 	for (j = i+1; j < m_size; j++) {
	 		if (pElements[i] > pElements[j]) {
	 			temp = pElements[i];
	 			pElements[i] = pElements[j];
	 			pElements[j] = temp;
	 		}
	 	}
	 }
}
