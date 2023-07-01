#include "inherit_builder.h"

int main() {
    PersonJobBuilder<PersonBuilder> pb;
    auto person = pb.called("Dmitri")
            .works_as("Programmer")
            .build();
    cout << person << endl;

    MyBuilder mb;
    auto me = mb.called("Dmitri")
            .works_as("Programmer")
            .born_on("01/01/1980")
            .build();
    cout << me << endl;
    return 0;
}