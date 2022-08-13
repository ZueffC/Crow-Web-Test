#include <iostream>
#include "sysinfo.h"

#include "sqlite3.h"
#include "stdlib.h"
#include "ormlite.h"
#include "crow_all.h"

using namespace std;
using namespace BOT_ORM;
using namespace BOT_ORM::Expression;

ORMapper mapper ("blog.db");

struct BlogPost
{
    string name;
    string author_name;
    string text;

    ORMAP ("BlogPost", name, author_name, text);
};

int main()
{
    crow::SimpleApp app;
    //app.loglevel(crow::LogLevel::Warning);

    CROW_ROUTE(app, "/")([](){
        crow::mustache::context ctx;
        auto page = crow::mustache::load("index.html");
        auto os_name = getOsName();

        ctx["os_name"] = os_name;

        return page.render(ctx);
    });

    app.port(9999).run();
}
