#include "email_builder.h"

int main() {
    MailService ms;
    ms.send_email([&](auto & eb) {
       eb.from("foo@bar.com")
       .to("bar@baz.com")
       .subject("hello")
       .body("Hello, how are you?");
    });
    return 0;
}