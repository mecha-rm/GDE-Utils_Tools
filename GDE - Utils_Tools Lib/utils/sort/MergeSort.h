#pragma once

namespace util
{
	namespace sort
	{
		// TODO: complete merge sort.

		// vector version
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

	}
}