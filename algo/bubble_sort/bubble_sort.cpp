#include "algo/bubble_sort/bubble_sort.hpp"

#include <algorithm>

namespace mzawada::lab
{
    void bubble_sort(uint8_t *tab, size_t len)
    {
        uint8_t c;
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = 0; j < len - 1; ++j)
            {
                if (tab[j] > tab[j + 1])
                {
                    c = tab[j + 1];
                    tab[j + 1] = tab[j];
                    tab[j] = c;
                }
            }
        }
    }

    void bubble_sort_swap(uint8_t *tab, size_t len)
    {
        for (int i = 0; i < len - 1; ++i)
        {
            for (int j = 0; j < len - 1; ++j)
            {
                if (tab[j] > tab[j + 1])
                {
                    std::swap(tab[j], tab[j + 1]);
                }
            }
        }
    }

    /**
     * Last list element can be skipped after
     * each inner iteration
     */
    void bubble_sort_v2(uint8_t *tab, size_t len)
    {
        uint8_t c;
        for (int i = len - 1; i > 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (tab[j] > tab[j + 1])
                {
                    c = tab[j + 1];
                    tab[j + 1] = tab[j];
                    tab[j] = c;
                }
            }
        }
    }

    void bubble_sort_v2_with_skip(uint8_t *tab, size_t len)
    {
        uint8_t c{}, done{};
        for (int i = len - 1; i > 0; --i)
        {
            done = 1;
            for (int j = 0; j < i; ++j)
            {
                if (tab[j] > tab[j + 1])
                {
                    c = tab[j + 1];
                    tab[j + 1] = tab[j];
                    tab[j] = c;
                    done = 0;
                }
            }
            if (done) break;
        }
    }
}
