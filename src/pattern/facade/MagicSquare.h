#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using std::vector;
using std::set;
using std::generate;

struct Generator {
    virtual vector<int> generate(const int count) const {
        vector<int> result(count);
        ::generate(result.begin(), result.end(), [&]() {return 1+ rand()%9; });
        return result;
    }
};

struct Splitter {
    vector<vector<int>> split(vector<vector<int>> array) const {
        int n = array.size();
        vector<vector<int>> result(2*n + 2, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = array[i][j];
                result[n+i][j] = array[j][i];
            }
            result[2*n][i] = array[i][i];
            result[2*n+1][i] = array[i][n-i-1];
        }
        return result;
    }
};
struct Verifier {
    bool verify(vector<vector<int>> array) const {
        if (array.empty())
            return false;
        auto expected = accumulate(array[0].begin(), array[0].end(), 0);
        return all_of(array.begin(), array.end(), [=](auto & inner) {
           return accumulate(inner.begin(), inner.end(), 0) == expected;
        });
    }
};

struct UniqueGenerator : Generator
{
    vector<int> generate(const int count) const override
    {
        vector<int> result;

        do
        {
            result = Generator::generate(count);
        } while (set<int>(result.begin(), result.end()).size()
                 != result.size());
        return result;
    }
};

template<typename G = Generator,
         typename S = Splitter,
         typename V = Verifier>
struct MagicSquareGenerator
{
    vector<vector<int>> generate(int size)
    {
        G g;
        S s;
        V v;

        vector<vector<int>> square;

        do
        {
            square.clear();
            for (int i = 0; i < size; ++i)
                square.emplace_back(g.generate(size));
        } while (!v.verify(s.split(square)));

        return square;
    }
};


