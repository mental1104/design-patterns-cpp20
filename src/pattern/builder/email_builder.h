#pragma once 

#include <string>
#include <functional>
#include <iostream>

using namespace std;

class MailService {
    class Email {
    public:
        string from, to, subject, body;
    };

public:
    class EmailBuilder {
        Email &email;
    public:
        explicit EmailBuilder(Email &email) : email{email} {};

        EmailBuilder &from(string from) {
            email.from = std::move(from);
            return *this;
        }

        EmailBuilder &to(string to) {
            email.to = std::move(to);
            return *this;
        }

        EmailBuilder &subject(string subject) {
            email.subject = std::move(subject);
            return *this;
        }

        EmailBuilder &body(string body) {
            email.body = std::move(body);
            return *this;
        }
    };

    void send_email(function<void(EmailBuilder&)> builder) {
        Email email;
        EmailBuilder b{email};
        builder(b);
        send_email_impl(email);
    }

private:
    void send_email_impl(const Email& email) {
        cout << "From " + email.from << " To " + email.to << endl;
        cout << "Subject: " + email.subject << endl;
        cout << "Content: " + email.body << endl;
    }
};