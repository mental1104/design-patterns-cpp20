#include <vector>
#include <string>
#include <iostream>

using std::ostream;
using std::string;
using std::vector;

class BetterFormattedText
{
public:
    BetterFormattedText(string s): plain_text{s} {}

    struct TextRange
    {
        int start, end;
        bool capitalize{false};

        bool covers(int position) const
        {
            return position >= start && position <= end;
        }
    };
    friend ostream& operator<<(ostream& os, const BetterFormattedText& obj);
    TextRange& get_range(int start, int end);
private:
    string plain_text;
    vector<TextRange> formatting; 
};

BetterFormattedText::TextRange& 
BetterFormattedText::get_range(int start, int end)
{
    formatting.emplace_back(TextRange{start, end});
    return *formatting.rbegin();
}

ostream& operator<<(ostream& os, const BetterFormattedText& obj)
{
    string s;
    for(size_t i = 0; i < obj.plain_text.length(); i++){
        auto c = obj.plain_text[i];
        for(const auto& rng:obj.formatting)
        {
            if(rng.covers(i) && rng.capitalize)
                c = toupper(c);
            s += c;
        }
    }
    return os << s;
}