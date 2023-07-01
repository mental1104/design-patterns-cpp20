#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::find_if;

struct ChatRoom;

struct Person
{
    string name;
    ChatRoom* room{nullptr};
    vector<string> chat_log;

    Person(const string& name) : name{name} {}
    void receive(const string& origin, const string& message);
    void say(const string& message) const;
    void pm(const string& who, const string& message) const;
};

struct ChatRoom
{
    vector<Person*> people;

    void join(Person* p);
    void broadcast(const string& origin, const string& message);
    void message(const string& origin, const string& who, const string& message);
};

void ChatRoom::join(Person* p)
{
    string join_msg = p->name + " joins the chat";
    broadcast("room", join_msg);
    p->room = this;
    people.push_back(p);
}

void ChatRoom::broadcast(const string& origin, const string& message)
{
    for (auto p : people)
        if(p->name != origin)
            p->receive(origin, message);
}

void ChatRoom::message(const string& origin, const string& who, const string& message)
{
    auto target = find_if(begin(people), end(people),
        [&](const Person* p) { return p->name == who; });
    if(target != end(people))
    {
        (*target)->receive(origin, message);
    }
}

void Person::say(const string& message) const
{
    room->broadcast(name, message);
}

void Person::pm(const string& who, const string& message) const
{
    room->message(name, who, message);
}

void Person::receive(const string& origin, const string& message)
{
    string s{origin + ": \"" + message + "\""};
    cout << "[" << name << "'s chat session] " << s << "\n";
    chat_log.emplace_back(s);
}

