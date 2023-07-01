#include <sstream>
#include <string>

using std::string;
using std::ostringstream;

struct ListStrategy
{
    virtual void start(ostringstream& oss) {}
    virtual void add_list_item(ostringstream& oss, const string& item) {}
    virtual void end(ostringstream& oss) {}
};

struct HtmlListStrategy : ListStrategy
{
    void start(ostringstream& oss) override
    {
        oss << "<ul>\n";
    }

    void end(ostringstream& oss) override
    {
        oss << "</ul>\n";
    }

    void add_list_item(ostringstream& oss, const string& item) override 
    {
        oss << "  <li>" << item << "</li>\n";
    }
};

struct MarkdownListStrategy : ListStrategy
{
    void add_list_item(ostringstream& oss, const string& item) override
    {
        oss << " + " << item << "  \n";
    }
};
