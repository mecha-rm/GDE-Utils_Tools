/*
 * Date: 05/16/2020
 * Description: merge sort
	* splits the arrays into individual pieces, then merges the pieces back together in the right order.
 * Resources:
*/
#pragma once

namespace util
{
	namespace sort
	{
		template<typename T, typename A>
		void mergeSort(std::vector<T, A>& list);

		template<typename T, typename A>
		void mergeSort(std::vector<T, A>& list, int first, int last);

		template<typename T>
		void mergeSort(T* list, const unsigned int SIZE);

		template<typename T>
		void mergeSort(T*, int, int);


		// TODO: complete merge sort.

		// merge sort (vector)
		template<typename T, typename A>
		void mergeSort(std::vector<T, A>& list)
		{
			mergeSort(list, 0, list.size() - 1);
		}


		// vector version - mergeSort(list, starting index, ending index)
		template<typename T, typename A>
		void mergeSort(std::vector<T, A>& list, int first, int last)
		{
			if (list[first] < list[last])
			{
				T mid = list[(first + last) / 2];

				mergeSort(list, first, mid);
				mergeSort(list, mid + 1, last);
				// merge(list, first, last);
			}
		}

		// array version
		template<typename T>
		void mergeSort(T* list, const unsigned int SIZE)
		{
			mergeSort(list, 0, SIZE - 1);
		}

		// array version - mergeSort(list, starting index, ending index)
		template<typename T>
		void mergeSort(T* list, int first, int last)
		{
			if (list[first] < list[last])
			{
				T mid = list[(first + last) / 2];

				mergeSort(list, first, mid);
				mergeSort(list, mid + 1, last);
				// merge(list, first, last);
			}
		}

	}
}