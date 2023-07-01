#include "journal.h"
#include "persistence_manager.h"

int main(){
    Journal j{"Dear Diary"};
    j.add("I cried today");
    j.add("I ate a bug");

    PersistenceManager::save(j, "journal.txt");
    return 0;
}