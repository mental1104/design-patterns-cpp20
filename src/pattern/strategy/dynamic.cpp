#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "strategy.h"

using std::unique_ptr;
using std::make_unique;
using std::vector;
using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

enum class OutputFormat
{
    markdown,
    html
};

struct TextProcessor
{
    TextProcessor(OutputFormat output) {
        if(output == OutputFormat::html)
            list_strategy = make_unique<HtmlListStrategy>();
        else
            list_strategy = make_unique<MarkdownListStrategy>();
    } 

    string str() {  return oss.str(); }
    void clear() { oss.str(""); }

    void append_list(const vector<string>& items)
    {
        list_strategy->start(oss);
        for(auto& item : items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }

    void set_output_format(const OutputFormat format)
    {
        switch(format)
        {
        case OutputFormat::markdown:
            list_strategy = make_unique<MarkdownListStrategy>();
            break;
        case OutputFormat::html:
            list_strategy = make_unique<HtmlListStrategy>();
            break;
        }
    }

private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};


int main(){
    TextProcessor tp{OutputFormat::markdown};
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str();

    tp.clear();
    tp.set_output_format(OutputFormat::html);
    tp.append_list({"foo", "bar", "baz"});
    cout << tp.str() << endl;
}