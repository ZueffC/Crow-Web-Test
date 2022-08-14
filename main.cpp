#include <iostream>
#include "sysinfo.h"
#include "parseBody.h"
#include "sqlite3.h"
#include "stdlib.h"
#include "ormlite.h"
#include "crow_all.h"

using namespace std;
using namespace BOT_ORM;
using namespace BOT_ORM::Expression;

struct BlogPost
{
    int id;
    string name;
    string author_name;
    string text;

    ORMAP ("BlogPost", id, name, author_name, text);
};


int main()
{
    crow::SimpleApp app;
    ORMapper mapper ("blog.db");

    try {
        mapper.CreateTbl(BlogPost {});
    } catch (...) {}


    CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([](){
        crow::mustache::context ctx;
        auto page = crow::mustache::load("index.html");
        auto os_name = getOsName();

        ctx["os_name"] = os_name;

        return page.render(ctx);
    });

    CROW_ROUTE(app, "/create-post").methods(crow::HTTPMethod::GET)([](){
        auto page = crow::mustache::load("create-post.html");
        return page.render();
    });

    CROW_ROUTE(app, "/create-post").methods("POST"_method)([](const crow::request& req) {
        auto page = crow::mustache::load("index.html");
        crow::mustache::context ctx;
        auto body = req.body;

        ctx["body"] = body.c_str();
        printf("%s", body.c_str());
        parseBody(body);

        return page.render(ctx);
      });


    app.port(9999).run();
}
