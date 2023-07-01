#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "strategy.h"

using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

template<typename LS>
struct TextProcessor
{
    void append_list(const vector<string> items)
    {
        list_strategy.start(oss);
        for(auto& item : items)
            list_strategy.add_list_item(oss, item);
        list_strategy.end(oss);
    }

    string str() {  return oss.str(); }
private:
    ostringstream oss;
    LS list_strategy;
};

int main(){
    TextProcessor<MarkdownListStrategy> tpm;
    tpm.append_list({"foo", "bar", "baz"});
    cout << tpm.str() << endl;

    TextProcessor<HtmlListStrategy> tph;
    tph.append_list({"foo", "bar", "baz"});
    cout << tph.str() << endl;
}