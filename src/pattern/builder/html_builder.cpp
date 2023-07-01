#include "html_builder.h"

int main() {
    auto builder = HtmlElement::build("ul")->add_child("li", "hello").add_child("li", "world");
    cout << builder.str() << endl;
    return 0;
}